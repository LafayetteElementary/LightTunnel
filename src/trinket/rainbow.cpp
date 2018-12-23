#include <FastLED.h>

#define NUM_LEDS    150
#define BRIGHTNESS  127
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_ROWS 3

#define UPDATES_PER_SECOND 10

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

typedef struct Row { 
   uint8_t row;
   uint8_t colorIndex;
   CRGB leds[NUM_LEDS];

   void init(uint8_t row) {
      this->row = row;
      this->colorIndex = (row * NUM_LEDS) / NUM_ROWS;
   };

   void advance() { 
      uint8_t brightness = BRIGHTNESS;
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 2;
      }
   }
    
} Row;

Row rows[NUM_ROWS];

void initRows() {
  
  for(int i = 0; i < NUM_ROWS; i++) {
    rows[i].init(i+1);
  }
  
  FastLED.addLeds<LED_TYPE, 3, COLOR_ORDER>(rows[0].leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(rows[1].leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(rows[2].leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
// Not working when I go more than 3 pins / rows
//  FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(rows[3].leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<LED_TYPE, 8, COLOR_ORDER>(rows[3].leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<LED_TYPE, 9, COLOR_ORDER>(rows[5].leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}

void setup() {
    delay( 3000 ); // power-up safety delay
    
    FastLED.setBrightness(BRIGHTNESS);

    // Apply the rainbow palette
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;

    // But, now we set the last 2 entries as Black
    // to give the fade out effect
    currentPalette[12] = CRGB::Black;
    currentPalette[13] = CRGB::Black;
    currentPalette[14] = CRGB::Black;
    currentPalette[15] = CRGB::Black;
    
    initRows();
}

void loop()
{   
    for(int i = 0; i < NUM_ROWS; i++) {
      rows[i].advance();
    }
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}

