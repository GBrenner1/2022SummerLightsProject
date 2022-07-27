#include<Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define LED_PIN 6
#define LED_COUNT 80

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(50);
}

void loop() {
  blinkingStartLight();

  masterOfPuppets();

  //wizardsInWinter();









  // Fill along the length of the strip in various colors...
  //  colorWipe(strip.Color(255,   0,   0), 50); // Red
  //  colorWipe(strip.Color(  0, 255,   0), 50); // Green
  //  colorWipe(strip.Color(  0,   0, 255), 50); // Blue

  //  singingGroup(strip.Color(0, 255, 0), 0, 500, 12); //we
  //  singingGroup(strip.Color(255, 0, 0), 3, 500, 12); //wish
  //  singingGroup(strip.Color(0, 0, 255), 4, 500, 12); //you;
  //  singingGroup(strip.Color(255, 255, 0), 4, 500, 12); //a
  //  singingGroup(strip.Color(255, 0, 255), 3, 250, 12); //mer-
  //  singingGroup(strip.Color(0, 255, 0), 2, 250, 12); //-ry
  //  singingGroup(strip.Color(255, 0, 0), 1, 250, 12); //Crist-
  //  singingGroup(strip.Color(0, 0, 255), 1, 250, 12); //-mas
  //  singingGroup(strip.Color(0, 255, 0), 1, 500, 12); //we
  //  singingGroup(strip.Color(255, 0, 0), 4, 500, 12); //wish
  //  singingGroup(strip.Color(0, 0, 255), 4, 250, 12); //you
  //  singingGroup(strip.Color(255, 255, 0), 5, 500, 12); //a
  //  singingGroup(strip.Color(255, 0, 255), 4, 250, 12); //mer-
  //  singingGroup(strip.Color(0, 255, 0), 3, 250, 12); //-ry
  //  singingGroup(strip.Color(0, 255, 255), 2, 250, 12); //christ-
  //  singingGroup(strip.Color(255, 255, 0), 0, 250, 12); //-mas

  //trailGroups(15, 500, 6, strip.Color(255, 255, 0), strip.Color(0, 255, 0));

  //onOff(strip.Color(50, 0, 255), 250);


}

void blinkingStartLight() {
  strip.setPixelColor(0, strip.Color(255, 0, 0));
  strip.show();
  delay(1000);
  strip.setPixelColor(0, strip.Color(255, 255, 0));
  strip.show();
  delay(1000);
  strip.setPixelColor(0, strip.Color(0, 255, 0));
  strip.show();
  delay(1000);
}

void masterOfPuppets() {
  colorWipe(strip.Color(255,   0,   0), 1);
  delay(950);
  strip.clear();
  setGroup(0, strip.Color(255, 0, 0), 30);
  delay(250);
  strip.clear();
  setGroup(1, strip.Color(255, 0, 0), 30);
  delay(250);
  strip.clear();
  setGroup(2, strip.Color(255, 0, 0), 30);
  delay(1550);
  strip.clear();
  setGroup(0, strip.Color(255, 0, 0), 100);
  delay(100);
  strip.clear();
  onOff(strip.Color(255, 0, 0), 50, 40);
  strip.clear();
  setGroup(0, strip.Color(255, 0, 0), 40);
  delay(250);
  strip.clear();
  setGroup(1, strip.Color(255, 0, 0), 40);
  delay(250);
  strip.clear();
  onOff(strip.Color(255, 0, 0), 50, 10);
  strip.clear();
  setGroup(0, strip.Color(255, 0, 0), 30);
  delay(250);
  strip.clear();
  setGroup(1, strip.Color(255, 0, 0), 30);
  delay(250);
  strip.clear();
  setGroup(2, strip.Color(255, 0, 0), 30);
  delay(250);
  strip.clear();
  onOff(strip.Color(255, 0, 0), 50, 20);
  strip.clear();
  setGroup(0, strip.Color(255, 0, 0), 40);
  delay(250);
  strip.clear();
  setGroup(1, strip.Color(255, 0, 0), 40);
  delay(250);
  strip.clear();
}

void wizardsInWinter() {
  trailGroups(4, 190, 20, strip.Color(255, 255, 255), strip.Color(10 , 10, 255));
  delay(100);
  strip.clear();
  trailGroups(4, 190, 20, strip.Color(10 , 10, 255), strip.Color(255, 255, 255));
  delay(100);
  strip.clear();
  trailGroups(4, 190, 20, strip.Color(255, 255, 255), strip.Color(10 , 10, 255));
  delay(100);
  strip.clear();
  trailGroups(4, 190, 20, strip.Color(10 , 10, 255), strip.Color(255, 255, 255));
  delay(100);
  strip.clear();
  trailGroups(4, 190, 20, strip.Color(255, 255, 255), strip.Color(10 , 10, 255));
  delay(100);
  strip.clear();
  trailGroups(5, 175, 16, strip.Color(255, 0, 0), strip.Color(0, 255, 0));
  delay(100);
  strip.clear();
  trailGroups(6, 170, 14, strip.Color(0, 255, 0), strip.Color(255, 0, 0));
  delay(100);
  trailGroups(4, 190, 20, strip.Color(255, 255, 255), strip.Color(10 , 10, 255));
  delay(100);
  strip.clear();
  trailGroups(4, 190, 20, strip.Color(10 , 10, 255), strip.Color(255, 255, 255));
  delay(100);
  strip.clear();
  trailGroups(4, 190, 20, strip.Color(255, 255, 255), strip.Color(10 , 10, 255));
  delay(100);
  strip.clear();
  trailGroups(4, 190, 20, strip.Color(10 , 10, 255), strip.Color(255, 255, 255));
  delay(100);
  strip.clear();
  trailGroups(4, 190, 20, strip.Color(255, 255, 255), strip.Color(10 , 10, 255));
  delay(100);
  strip.clear();
  trailGroups(5, 175, 16, strip.Color(255, 0, 0), strip.Color(0, 255, 0));
  delay(100);
  strip.clear();
  trailGroups(6, 170, 14, strip.Color(0, 255, 0), strip.Color(255, 0, 0));

}

void singingGroup(uint32_t c, uint8_t g, int wait, int groupSize) {
  int firstPixel = g * groupSize;
  for (uint8_t i = 0; i < groupSize; i++) {
    strip.setPixelColor(firstPixel + i, c);
  }
  strip.show();
  delay(wait);
  strip.clear();
}

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void singleLightTest(uint32_t color, int wait, int lightNumberInArray) {
  strip.clear();
  strip.setPixelColor(lightNumberInArray, color);
  strip.show();
  delay(wait);
}

void onOff(uint32_t color, int wait, int cycles) {
  for (int i = 0; i < cycles; i++) {
    for (int j = 0; j < 2; j++) {
      strip.clear();
      for (int k = j; k < strip.numPixels(); k += 2) {
        strip.setPixelColor(k, color);
      }
      strip.show();
      delay(wait);
    }
  }
}

void trailGroups(int cycles, int wait, int groupSize, uint32_t colorOne, uint32_t colorTwo) {
  for (int i = 0; i < cycles; i++) {
    if (i % 2 == 0) {
      setGroup(i, colorOne, groupSize);
      //setGroup(i + 1, strip.Color(255, 0, 0), groupSize);
      //setGroup(i + 2, strip.Color(0, 255, 0), groupSize);
      delay(wait);
      //strip.clear();
    } else {
      setGroup(i, colorTwo, groupSize);
      //setGroup(i + 1, strip.Color(0, 255, 0), groupSize);
      //setGroup(i + 2, strip.Color(255, 0, 0), groupSize);
      delay(wait);
      //strip.clear();
    }
  }
  strip.clear();
}

void setGroup(uint8_t g, uint32_t c, int groupSize) {
  //  for(){
  int firstPixel = g * groupSize;
  for (uint8_t i = 0; i < groupSize; i++) {
    strip.setPixelColor(firstPixel + i, c);
  }
  strip.show();
}
//}
