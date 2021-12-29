#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN     4
#define NUM_LEDS    24
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 10

//LED config variables
CRGB leds[NUM_LEDS];
CRGB colors[16];
int b;
int SATURATION = 255;
//CHSV start = CHSV( HUE_AQUA, 255, BRIGHTNESS);
//CHSV end = CHSV( HUE_AQUA, 255, BRIGHTNESS);

void setup() {
  // put your setup code here, to run once:
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.print(".");
  b = 150;
  
  //Adding Leds
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( b );
  
  //Setup LED Colors
  //Ice Barrage
  leds[0] = CRGB::Cyan;
  leds[1] = CRGB::Cyan;
  leds[2] = CRGB::Cyan;
  leds[3] = CRGB::Cyan; 
  //Varrock TP
  leds[4] = CRGB::Fuchsia;
  leds[5] = CRGB::Fuchsia;
  leds[6] = CRGB::Fuchsia;
  leds[7] = CRGB::Fuchsia;
  //Ice Blitz
  leds[8] = CRGB::Fuchsia;
  leds[9] = CRGB::Fuchsia;
  leds[10] = CRGB::Fuchsia;
  leds[11] = CRGB::Fuchsia;
  // Lassar TP
  leds[12] = CRGB::Cyan;
  leds[13] = CRGB::Cyan;
  leds[14] = CRGB::Cyan;
  leds[15] = CRGB::Cyan;
  //Spine
  leds[16] = CRGB::Fuchsia;
  leds[17] = CRGB::Fuchsia;
  leds[18] = CRGB::Fuchsia;
  leds[19] = CRGB::Fuchsia;
  leds[20] = CRGB::Cyan;
  leds[21] = CRGB::Cyan;
  leds[22] = CRGB::Cyan;
  leds[23] = CRGB::Cyan;
}

void loop() {
    Serial.print(b);
    // put your main code here, to run repeatedly:
    FastLED.show(b);
    while (b > 2)
    {
      FastLED.delay(1000 / UPDATES_PER_SECOND);
      Serial.print("Sub Brightness");
      b -= 1;
      Serial.print(b);
      FastLED.setBrightness( b );  
      FastLED.show(b);
    }
    while (b < 120)
    {
      FastLED.delay(1000 / UPDATES_PER_SECOND);
      b +=  1; 
      FastLED.setBrightness( b );
      FastLED.show(b); 
    }
}
