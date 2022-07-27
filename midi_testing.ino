#include <MIDI.h>  // Add Midi Library
#include <Adafruit_NeoPixel.h>

#define LED 6  // Arduino Board LED is on Pin 13
#define LED_COUNT 80

Adafruit_NeoPixel strip(LED_COUNT, LED, NEO_GRB + NEO_KHZ800);

// Below is my function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  int light = pitch - 20;
  strip.setPixelColor(light, strip.Color(0, 0, 255));
  //setGroup(light, strip.Color(0,0,255), 5);
  strip.show();
  //digitalWrite(LED,HIGH);  //Turn LED on
  if (velocity == 0) {//A NOTE ON message with a velocity = Zero is actualy a NOTE OFF
    strip.setPixelColor(light, strip.Color(0, 0, 0));
    //setGroup(light, strip.Color(0,0,0), 5);
    strip.show();
    //digitalWrite(LED,LOW);//Turn LED off
  }
}

void setup() {
  strip.setBrightness(50);
  strip.begin();
  strip.clear();
  pinMode (LED, OUTPUT); // Set Arduino board pin 13 to output
  Serial.begin(115200); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to channel 2 notes only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function I want called when a Note ON command
  // is received. in this case it's "MyHandleNoteOn".
}

void loop() { // Main loop
  MIDI.read(); // Continually check what Midi Commands have been received.
}

void setGroup(uint8_t g, uint32_t c, int groupSize) {
  int firstPixel = g * groupSize;
  for (uint8_t i = 0; i < groupSize; i++) {
    strip.setPixelColor(firstPixel + i, c);
  }
  strip.show();
}
