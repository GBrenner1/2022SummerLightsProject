#include <MIDI.h>  // Add Midi Library
#include<Adafruit_NeoPixel.h>
#include "FastLED.h"

#define LED 6  // Arduino Board LED is on Pin 13
#define LED_COUNT 200
#define LENGTH_OF_TAIL 20

CRGB leds[LED_COUNT];

//Adafruit_NeoPixel strip(LED_COUNT, LED, NEO_GRB + NEO_KHZ800);

// Below is my function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  int light = pitch - 36;
  for(int i = 0; i < 250; i++){
    cd_sinelon_oneway(25, CRGB::Green, 10);
  }
  if (velocity == 0) { //A NOTE ON message with a velocity = Zero is actualy a NOTE OFF
//    strip.setPixelColor(light, strip.Color(0, 0, 0));
//    strip.show();
  }
}

void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
  int light = pitch - 36;
//  strip.setPixelColor(light, strip.Color(0, 0, 0));
//  strip.show();
}

void setup() {
//  strip.setBrightness(100);
//  strip.begin();
//  strip.clear();
  FastLED.addLeds<NEOPIXEL, LED>(leds, LED_COUNT).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(150);
  pinMode (LED, OUTPUT); 
  Serial.begin(115200); 
  MIDI.setHandleNoteOn(MyHandleNoteOn);
  MIDI.setHandleNoteOff(MyHandleNoteOff);

}

void loop() { 
  MIDI.read();
}

//void setGroup(uint8_t g, uint32_t c, int groupSize) {
//  int firstPixel = g * groupSize;
//  for (uint8_t i = 0; i < groupSize; i++) {
//    strip.setPixelColor(firstPixel + i, c);
//  }
//  strip.show();
//}

//void pulseFromNote(int startNote, uint32_t color, int wait) {
//  strip.setPixelColor(startNote, color);
//  strip.show();
//  strip.setPixelColor(startNote, strip.Color(0, 0, 0));
//  strip.show();
//  for (int i = 1; i < LED_COUNT; i++) {
//    strip.setPixelColor(startNote + i, color);
//    strip.setPixelColor(startNote - i, color);
//    strip.show();
//    strip.setPixelColor(startNote + i, strip.Color(0, 0, 0));
//    strip.setPixelColor(startNote - i, strip.Color(0, 0, 0));
//    strip.show();
//  }
//}

void cd_sinelon_oneway(uint8_t BPM, CRGB color, uint8_t fadeby){
  fadeToBlackBy(leds, LED_COUNT, LENGTH_OF_TAIL);
  uint8_t u = beat8(BPM,0);
  uint16_t pos = map(u,0,255,0,LED_COUNT);
  leds[pos] = color;
  FastLED.show();
  }
