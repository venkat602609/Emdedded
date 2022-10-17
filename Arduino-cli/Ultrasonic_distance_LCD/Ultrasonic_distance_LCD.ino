#include <LiquidCrystal.h>
/* Create object named lcd of the class LiquidCrystal */
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);	/* For 8-bit mode */
//LiquidCrystal lcd(13, 12, 11, 6, 5, 4, 3);	/* For 4-bit mode */
//LiquidCrystal lcd(13, 12, 6, 5, 4, 3);
const int rs=13,rw=12,en=11,d0=10,d1=9,d2=8,d3=7,d4=6,d5=5,d6=4,d7=3;

#define echoPin 2
#define trigPin 1 
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
long t1,t2;

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
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Yo! Venkata");
  
}

void loop() {
    // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2000);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,HIGH);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  // Calculating the distance
  distance = duration * 0.01715; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor

  String printval = String(distance);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Yo! Venkata");
  lcd.setCursor(0, 1);
  lcd.print( printval +" cm");
  delay(1000);


}

// defines variables

