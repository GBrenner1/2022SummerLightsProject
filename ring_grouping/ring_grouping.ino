 #ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#include<Adafruit_NeoPixel.h>
#endif

//Light strip pin numbers on arduino board
#define RING_STRIP_PIN 6
#define BRANCH_ONE_STRIP_PIN 4
#define BRANCH_TWO_STRIP_PIN 2
#define BRANCH_THREE_STRIP_PIN 8

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
Adafruit_NeoPixel branch_one_strip(BRANCH_STRIP_LED_COUNT, BRANCH_ONE_STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel branch_two_strip(BRANCH_STRIP_LED_COUNT, BRANCH_TWO_STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel branch_three_strip(BRANCH_STRIP_LED_COUNT, BRANCH_THREE_STRIP_PIN, NEO_GRB + NEO_KHZ800);

//Subarray's for rings on ring_strip
int large_ring[LARGE_RING_SIZE];
int middle_ring[MIDDLE_RING_SIZE];
int small_ring[SMALL_RING_SIZE];

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
  blinkingStartLight();
  christmasMedley();
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


void christmasMedley(){
  colorWipeThreeBranch(branch_one_strip.Color(255,255,255),10);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 0, 0), ring_strip.Color(0, 0, 0), ring_strip.Color(0, 255, 0));
  delay(900);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 0, 0), ring_strip.Color(0, 255, 0), ring_strip.Color(0, 0, 0));
  delay(50);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 255, 0), ring_strip.Color(0, 0, 0), ring_strip.Color(0, 0, 0));
  delay(700);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 0, 0), ring_strip.Color(0, 255, 0), ring_strip.Color(0, 0, 0));
  delay(700);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 255, 0), ring_strip.Color(0, 0, 0), ring_strip.Color(0, 255, 0));
  delay(500);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 0, 0), ring_strip.Color(0, 0, 0), ring_strip.Color(0, 0, 255));
  delay(500);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 0, 0), ring_strip.Color(0, 255, 0), ring_strip.Color(0, 0, 255));
  delay(500);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(255, 255, 255), ring_strip.Color(0, 255, 0), ring_strip.Color(0, 0, 255));
  delay(2500);
  pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
  colorWipe(branch_one_strip.Color(0,255,0), 5, branch_one_strip);
  delay(10);
  pinMode(BRANCH_TWO_STRIP_PIN, OUTPUT);
  colorWipe(branch_two_strip.Color(255,0,0), 5, branch_two_strip);
  delay(10);
  pinMode(BRANCH_THREE_STRIP_PIN, OUTPUT);
  colorWipe(branch_three_strip.Color(0,0,255), 5, branch_three_strip);
  delay(10);
  pinMode(BRANCH_TWO_STRIP_PIN, OUTPUT);
  colorWipe(branch_two_strip.Color(0,255,0), 5, branch_two_strip);
  delay(10);
  pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
  colorWipe(branch_one_strip.Color(255,0,0), 5, branch_one_strip);
  delay(275);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 0, 0), ring_strip.Color(0, 0, 0), ring_strip.Color(255, 0, 0));
  delay(500);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0, 0, 0), ring_strip.Color(255, 0, 0), ring_strip.Color(255, 0, 0));
  delay(500);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(255, 0, 0), ring_strip.Color(255, 0, 0), ring_strip.Color(255, 0, 0));
  delay(300);
  colorWipeThreeBranch(ring_strip.Color(255, 255, 255), 10);
  }
