#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#include<Adafruit_NeoPixel.h>
#endif

//Light strip pin numbers on arduino board
#define RING_STRIP_PIN 6
#define BRANCH_STRIP_PIN 4

//Count of lights per over all strip
#define RING_STRIP_LED_COUNT 200
#define BRANCH_STRIP_LED_COUNT 50

//Ring startpoints and sizes
#define LARGE_RING_START 136
#define LARGE_RING_SIZE 64

#define MIDDLE_RING_START 70
#define MIDDLE_RING_SIZE 43

#define SMALL_RING_START 17
#define SMALL_RING_SIZE 29

//Overall brightness of all lights from 0 - 255
#define BRIGHTNESS 255

//light strips
Adafruit_NeoPixel ring_strip(RING_STRIP_LED_COUNT, RING_STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel branch_strip(BRANCH_STRIP_LED_COUNT, BRANCH_STRIP_PIN, NEO_GRB + NEO_KHZ800);

//Subarray's for rings on ring_strip
int large_ring[LARGE_RING_SIZE];
int middle_ring[MIDDLE_RING_SIZE];
int small_ring[SMALL_RING_SIZE];

void setup() {
  ring_strip.setBrightness(BRIGHTNESS);
  branch_strip.setBrightness(BRIGHTNESS);
  ring_strip.begin();
  branch_strip.begin();
  ring_strip.show();
  branch_strip.show();

  for (int i = 0; i <= LARGE_RING_SIZE; i++) {
    large_ring[i] = i + LARGE_RING_START;
  }

  for (int i = 0; i <= MIDDLE_RING_SIZE; i++) {
    middle_ring[i] = i + MIDDLE_RING_START;
  }

  for (int i = 0; i <= SMALL_RING_SIZE; i++) {
    small_ring[i] = i + SMALL_RING_START;
  }
}

void loop() {
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(255, 0, 255), ring_strip.Color(0, 255, 0), ring_strip.Color(0, 255, 255));
  pinMode(BRANCH_STRIP_PIN, OUTPUT);
  colorWipe(branch_strip.Color(0, 255, 0), 50, branch_strip);
  pinMode(BRANCH_STRIP_PIN, OUTPUT);
  colorWipe(branch_strip.Color(255, 0, 0), 50, branch_strip);
  pinMode(BRANCH_STRIP_PIN, OUTPUT);
  colorWipe(branch_strip.Color(0, 0, 255), 50, branch_strip);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 0, 255), ring_strip.Color(255, 255, 255), ring_strip.Color(0, 0, 255));
  pinMode(BRANCH_STRIP_PIN, OUTPUT);
  colorWipe(branch_strip.Color(0, 255, 0), 50, branch_strip);
  pinMode(BRANCH_STRIP_PIN, OUTPUT);
  colorWipe(branch_strip.Color(255, 0, 0), 50, branch_strip);
  pinMode(BRANCH_STRIP_PIN, OUTPUT);
  colorWipe(branch_strip.Color(0, 0, 255), 50, branch_strip);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(255, 255, 255), ring_strip.Color(0, 0, 255),  ring_strip.Color(0, 255, 0));
  pinMode(BRANCH_STRIP_PIN, OUTPUT);
  theaterChaseRainbow(100, branch_strip);
  branch_strip.clear();
}

void create_rings(uint32_t ring_one_color, uint32_t ring_two_color, uint32_t ring_three_color) {
  for (int i = 0; i <= LARGE_RING_SIZE; i++) {
    ring_strip.setPixelColor(large_ring[i], ring_one_color);
  }
  for (int i = 0; i <= MIDDLE_RING_SIZE; i++) {
    ring_strip.setPixelColor(middle_ring[i], ring_two_color);
  }
  for (int i = 0; i <= SMALL_RING_SIZE; i++) {
    ring_strip.setPixelColor(small_ring[i], ring_three_color);
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
