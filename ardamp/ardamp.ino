#include <LiquidCrystal.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define BTN_RIGHT 0
#define BTN_UP     1
#define BTN_DOWN   2
#define BTN_LEFT   3
#define BTN_SELECT 4
#define BTN_NONE   5

/**
 * read buttons from ADC pin 0
 */
int read_LCD_buttons() {
	int keyIn = analogRead(0); 
	if (keyIn > 1000) return BTN_NONE;
	if (keyIn < 50)   return BTN_RIGHT;  
	if (keyIn < 250)  return BTN_UP; 
	if (keyIn < 450)  return BTN_DOWN; 
	if (keyIn < 650)  return BTN_LEFT; 
	if (keyIn < 850)  return BTN_SELECT;  
	return BTN_NONE;
}

void serviceButtons() {
	lcd.setCursor(9,1); 
	lcd.print(millis()/1000);
	lcd.setCursor(0,1);
	int lcdKey = read_LCD_buttons();

	switch (lcdKey) {
		case BTN_RIGHT:
		{
		    lcd.print("RIGHT ");
		    break;
		}
		case BTN_LEFT:
		{
		    lcd.print("LEFT   ");
		    break;
		}
		case BTN_UP:
		{
		    lcd.print("UP    ");
		    break;
		}
		case BTN_DOWN:
		{
		    lcd.print("DOWN  ");
		    break;
		}
		case BTN_SELECT:
		{
		    lcd.print("SELECT");
		    break;
		}
		case BTN_NONE:
		{
		    lcd.print("NONE  ");
		    break;
		}
	}
}


void setup() {
	lcd.begin(16, 2); 
	lcd.setCursor(0,0);
	lcd.print("Bob gets bananas");
}



/**
 * The main processing loop
 */
void loop() {
    serviceButtons();
}
