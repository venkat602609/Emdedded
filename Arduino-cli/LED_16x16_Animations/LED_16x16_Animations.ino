#include <FastLED.h>


#define LED_COUNT 256
#define DATA 13
#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define BRIGHTNESS 100
#define VOLTS 5
#define MAX_AMPS 200

CRGB leds[LED_COUNT];
int randLEDNumber, randRed, randGreen, randBlue;

void setup() {
  // put your setup code here, to run once:
FastLED.addLeds<CHIPSET,DATA,COLOR_ORDER>(leds,LED_COUNT);
FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
FastLED.setBrightness(BRIGHTNESS);
FastLED.clear();
FastLED.show();

}

void loop() {

  // put your main code here, to run repeatedly:
randLEDNumber = random(256);
randRed = random(255);
randGreen = random(255);
randBlue = random(255);
fill_solid(leds, LED_COUNT, CRGB(randRed,randGreen,randBlue));
delay(5000);
FastLED.show();


}
