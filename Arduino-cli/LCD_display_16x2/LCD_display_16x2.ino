#include <LiquidCrystal.h>
/* Create object named lcd of the class LiquidCrystal */
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);	/* For 8-bit mode */
//LiquidCrystal lcd(13, 12, 11, 6, 5, 4, 3);	/* For 4-bit mode */
//LiquidCrystal lcd(13, 12, 6, 5, 4, 3);
const int rs=13,rw=12,en=11,d0=10,d1=9,d2=8,d3=7,d4=6,d5=5,d6=4,d7=3;

void setup() 
{
	// set up the LCD's number of columns and rows:
	lcd.begin(16, 2);

	// Clears the LCD screen
	lcd.clear();
  lcd.print("hello, world!");
  delay(1000);
  for(int i=0;i<2;i++){
    for(int j=0;j<16;j++){
      lcd.setCursor(j,i);
      lcd.print(j%10);
      delay(100);    }
  }
}

void loop() {
  lcd.clear();
  lcd.print("Need NTP Server!");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Yo! Venkata");
  lcd.setCursor(0, 1);
  lcd.print("Welcome Back!");
  delay(5000);

}