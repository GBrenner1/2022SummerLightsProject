 #ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#include<Adafruit_NeoPixel.h>
#endif

//Light strip pin numbers on arduino board
#define RING_STRIP_PIN 2
#define BRANCH_ONE_STRIP_PIN 4
#define BRANCH_TWO_STRIP_PIN 6
#define BRANCH_THREE_STRIP_PIN 8

//Count of lights per over all strip
#define RING_STRIP_LED_COUNT 282

#define BRANCH_STRIP_LED_COUNT 175

//Ring startpoints and sizes
#define LOWER_RING_START 0
#define LOWER_RING_SIZE 88

#define LOWER_MIDDLE_START 89
#define LOWER_MIDDLE_SIZE 70

#define MIDDLE_RING_START 158
#define MIDDLE_RING_SIZE 67

#define UPPER_MIDDLE_START 225
#define UPPER_MIDDLE_SIZE 35

#define TOP_RING_START 260
#define TOP_RING_SIZE 22

//Overall brightness of all lights from 0 - 255
#define BRIGHTNESS 255

//light strips
Adafruit_NeoPixel ring_strip(RING_STRIP_LED_COUNT, RING_STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel branch_one_strip(BRANCH_STRIP_LED_COUNT, BRANCH_ONE_STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel branch_two_strip(BRANCH_STRIP_LED_COUNT, BRANCH_TWO_STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel branch_three_strip(BRANCH_STRIP_LED_COUNT, BRANCH_THREE_STRIP_PIN, NEO_GRB + NEO_KHZ800);

//Subarray's for rings on ring_strip
int lower_ring[LOWER_RING_SIZE];
int lower_middle_ring[LOWER_MIDDLE_SIZE];
int middle_ring[MIDDLE_RING_SIZE];
int upper_middle_ring[UPPER_MIDDLE_SIZE];
int top_ring[TOP_RING_SIZE];

void setup() {
  ring_strip.setBrightness(BRIGHTNESS);
  branch_one_strip.setBrightness(BRIGHTNESS);
  branch_two_strip.setBrightness(BRIGHTNESS);
  branch_three_strip.setBrightness(BRIGHTNESS);
  ring_strip.begin();
  branch_one_strip.begin();
  branch_two_strip.begin();
  branch_three_strip.begin();
  ring_strip.show();
  branch_one_strip.show();
  branch_two_strip.show();
  branch_three_strip.show();


  for (int i = 0; i <= LOWER_RING_SIZE; i++) {
    lower_ring[i] = i + LOWER_RING_START;
  }

  for(int i = 0; i <= LOWER_MIDDLE_SIZE; i++){
    lower_middle_ring[i] = i + LOWER_MIDDLE_START;  
  }

  for (int i = 0; i <= MIDDLE_RING_SIZE; i++) {
    middle_ring[i] = i + MIDDLE_RING_START;
  }

  for(int i = 0; i <= UPPER_MIDDLE_SIZE; i++){
    upper_middle_ring[i] = i + UPPER_MIDDLE_START;  
  }
  
  for (int i = 0; i <= TOP_RING_SIZE; i++) {
    top_ring[i] = i + TOP_RING_START;
  }
}

void loop() {
  colorWipeThreeBranch(branch_one_strip.Color(0 ,255, 0), 50);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 255, 0), ring_strip.Color(0, 255, 0), ring_strip.Color(0, 255, 0), ring_strip.Color(0, 255, 0), ring_strip.Color(0, 255, 0));
}

void create_rings(uint32_t top_ring_color, uint32_t upper_middle_color, uint32_t middle_ring_color, uint32_t lower_middle_color, uint32_t bottom_ring_color) {
  for (int i = 0; i <= LOWER_RING_SIZE; i++) {
    ring_strip.setPixelColor(lower_ring[i], bottom_ring_color);
  }
  
  for (int i = 0; i <= LOWER_MIDDLE_SIZE; i++) {
    ring_strip.setPixelColor(lower_middle_ring[i], lower_middle_color);
  }
  
  for (int i = 0; i <= MIDDLE_RING_SIZE; i++) {
    ring_strip.setPixelColor(middle_ring[i], middle_ring_color);
  }

  for (int i = 0; i <= UPPER_MIDDLE_SIZE; i++) {
    ring_strip.setPixelColor(upper_middle_ring[i], upper_middle_color);
  }
  
  for (int i = 0; i <= TOP_RING_SIZE; i++) {
    ring_strip.setPixelColor(top_ring[i], top_ring_color);
  }
  ring_strip.show();
}

void theaterChaseRainbow(int wait, Adafruit_NeoPixel lights) {
  int firstPixelHue = 0;
  for (int a = 0; a < 30; a++) {
    for (int b = 0; b < 3; b++) {
      lights.clear();
      for (int c = b; c < lights.numPixels(); c += 3) {
        int hue = firstPixelHue + c * 65536L / lights.numPixels();
        uint32_t color = lights.gamma32(lights.ColorHSV(hue));
        lights.setPixelColor(c, color);
      }
      lights.show();
      delay(wait);
      firstPixelHue += 65536 / 90;
    }
  }
}
  
void colorWipe(uint32_t color, int wait, Adafruit_NeoPixel lights) {
  for (int i = 0; i < lights.numPixels(); i++) {
    lights.setPixelColor(i, color);
    lights.show();
    delay(wait);
  }
}
void blinkingStartLight() {
  branch_one_strip.setPixelColor(0, branch_one_strip.Color(255, 0, 0));
  branch_one_strip.show();
  delay(1000);
  branch_one_strip.setPixelColor(0, branch_one_strip.Color(255, 255, 0));
  branch_one_strip.show();
  delay(1000);
  branch_one_strip.setPixelColor(0, branch_one_strip.Color(0, 255, 0));
  branch_one_strip.show();
  delay(1000);
}

void colorWipeThreeBranch(uint32_t color, int wait) {
  for (int i = 0; i < branch_one_strip.numPixels(); i++) {
    pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
    branch_one_strip.setPixelColor(i, color);
    pinMode(BRANCH_TWO_STRIP_PIN, OUTPUT);
    branch_two_strip.setPixelColor(i, color);
    pinMode(BRANCH_THREE_STRIP_PIN, OUTPUT);
    branch_three_strip.setPixelColor(i, color);
    branch_one_strip.show();
    branch_two_strip.show();
    branch_three_strip.show();
    delay(wait);
  }
}
