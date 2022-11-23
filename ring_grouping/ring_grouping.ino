 #ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#include<Adafruit_NeoPixel.h>
#endif

//Light strip pin numbers on arduino board
#define RING_STRIP_PIN 2
#define BRANCH_ONE_STRIP_PIN 4

//Count of lights per over all strip
#define RING_STRIP_LED_COUNT 282

#define BRANCH_STRIP_LED_COUNT 140

//Ring startpoints and sizes
#define LOWER_RING_START 0
#define LOWER_RING_SIZE 88

#define LOWER_MIDDLE_START 89
#define LOWER_MIDDLE_SIZE 70

#define MIDDLE_RING_START 158
#define MIDDLE_RING_SIZE 67

#define UPPER_MIDDLE_START 225
#define UPPER_MIDDLE_SIZE 35

#define TOP_RING_START 261
#define TOP_RING_SIZE 22

//Overall brightness of all lights from 0 - 255
#define BRIGHTNESS 150

//light strips
Adafruit_NeoPixel ring_strip(RING_STRIP_LED_COUNT, RING_STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel branch_one_strip(BRANCH_STRIP_LED_COUNT, BRANCH_ONE_STRIP_PIN, NEO_GRB + NEO_KHZ800);

//Subarray's for rings on ring_strip
int lower_ring[LOWER_RING_SIZE];
int lower_middle_ring[LOWER_MIDDLE_SIZE];
int middle_ring[MIDDLE_RING_SIZE];
int upper_middle_ring[UPPER_MIDDLE_SIZE];
int top_ring[TOP_RING_SIZE];

void setup() {
  ring_strip.setBrightness(BRIGHTNESS);
  branch_one_strip.setBrightness(BRIGHTNESS);
  ring_strip.begin();
  branch_one_strip.begin();
  ring_strip.show();
  branch_one_strip.show();

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
  winter_wonderland();
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

void five_rings_up_fill(uint32_t top_ring_color, uint32_t upper_middle_color, uint32_t middle_ring_color, uint32_t lower_middle_color, uint32_t bottom_ring_color, int delay_one, int delay_two){
  delay(delay_one);
  create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), bottom_ring_color);
  delay(delay_two);
  create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), lower_middle_color, bottom_ring_color);
  delay(delay_two);
  create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), middle_ring_color, lower_middle_color, bottom_ring_color);
  delay(delay_two);
  create_rings(ring_strip.Color(0,0,0), upper_middle_color, middle_ring_color, lower_middle_color, bottom_ring_color);
  delay(delay_two);
  create_rings(top_ring_color, upper_middle_color, middle_ring_color, lower_middle_color,bottom_ring_color);  
}

void five_rings_down_filled(uint32_t top_ring_color, uint32_t upper_middle_color, uint32_t middle_ring_color, uint32_t lower_middle_color, uint32_t bottom_ring_color, int delay_one, int delay_two){
  delay(delay_one);
  create_rings(top_ring_color, ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
  delay(delay_two);
  create_rings(top_ring_color, upper_middle_color, ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
  delay(delay_two);
  create_rings(top_ring_color, upper_middle_color, middle_ring_color, ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
  delay(delay_two);
  create_rings(top_ring_color, upper_middle_color, middle_ring_color, lower_middle_color, ring_strip.Color(0,0,0));
  delay(delay_two);
  create_rings(top_ring_color, upper_middle_color, middle_ring_color, lower_middle_color, bottom_ring_color);
}

void five_rings_down_unfill(uint32_t top_ring_color, uint32_t upper_middle_color, uint32_t middle_ring_color, uint32_t lower_middle_color, uint32_t bottom_ring_color, int delay_one, int delay_two){
  delay(delay_one);
  create_rings(top_ring_color, upper_middle_color, middle_ring_color, lower_middle_color, bottom_ring_color);
  delay(delay_two);
  create_rings(ring_strip.Color(0,0,0), upper_middle_color, middle_ring_color, lower_middle_color, bottom_ring_color);
  delay(delay_two);
  create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), middle_ring_color, lower_middle_color, bottom_ring_color);
  delay(delay_two);
  create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), lower_middle_color, bottom_ring_color);
  delay(delay_two);
  create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), bottom_ring_color);
}

void theaterChaseRainbow(int wait, Adafruit_NeoPixel lights) {
  int firstPixelHue = 0; 
  for(int a=0; a<30; a++) { 
    for(int b=0; b<3; b++) { 
      lights.clear();
      for(int c=b; c<lights.numPixels(); c += 3) {
        int      hue   = firstPixelHue + c * 65536L / lights.numPixels();
        uint32_t color = lights.gamma32(lights.ColorHSV(hue));
        lights.setPixelColor(c, color); 
      }
      lights.show();                
      delay(wait);                 
      firstPixelHue += 65536 / 90; 
    }
  }
}

void theaterChaseWhite(int wait) {
  int firstPixelHue = 0;
  for (int a = 0; a < 30; a++) {
    for (int b = 0; b < 3; b++) {
      ring_strip.clear();
      branch_one_strip.clear();
      for (int c = b; c < ring_strip.numPixels(); c += 3) {
        pinMode(RING_STRIP_PIN,OUTPUT);
        ring_strip.setPixelColor(c, ring_strip.Color(255,255,255));
        pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
        branch_one_strip.setPixelColor(c, branch_one_strip.Color(255,255,255));
      }
      ring_strip.show();
      branch_one_strip.show();
      delay(wait);
    }
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

void pulseFromNoteOn(int startNote, uint32_t color, int wait) {
  double waitAddition = wait;
  branch_one_strip.setPixelColor(startNote, color);
  branch_one_strip.show();
  branch_one_strip.setPixelColor(startNote, branch_one_strip.Color(0, 0, 0));
  branch_one_strip.show();
  for (int i = 1; i < BRANCH_STRIP_LED_COUNT; i++) {
    branch_one_strip.setPixelColor(startNote + i, color);
    branch_one_strip.setPixelColor(startNote - i, color);
    branch_one_strip.show();
    delay(waitAddition);
    waitAddition = waitAddition * .95;
  }
}

void reversePulseFromNote(uint32_t color, int wait){
  for(int i = 0; i < BRANCH_STRIP_LED_COUNT / 2; i++){
    pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
    branch_one_strip.setPixelColor(i, color);
    branch_one_strip.setPixelColor(BRANCH_STRIP_LED_COUNT - i, color);
    branch_one_strip.show();
    if(i == 31){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,255), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
    }
    delay(wait);
  }  
}

void pulseFromNoteOnWithRings(int startNote, uint32_t color, int wait) {
  double waitAddition = wait;
  branch_one_strip.setPixelColor(startNote, color);
  branch_one_strip.show();
  branch_one_strip.setPixelColor(startNote, branch_one_strip.Color(0, 0, 0));
  branch_one_strip.show();
  for (int i = 1; i < BRANCH_STRIP_LED_COUNT; i++) {
    pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
    branch_one_strip.setPixelColor(startNote + i, color);
    branch_one_strip.setPixelColor(startNote - i, color);
    branch_one_strip.show();
    if(i == 14){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,255), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
    }
    if(i == 30){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
    }
    if(i == 44){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
    }
    if(i == 60){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,0));
    }
    if(i == 76){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255));
    }
    delay(waitAddition);
    waitAddition = waitAddition * .95;
  }
}

void pulseFromNoteOffWithRings(int startNote, int wait) {
  double waitAddition = wait;
  branch_one_strip.setPixelColor(startNote, branch_one_strip.Color(0, 0, 0));
  branch_one_strip.show();
  for (int i = 1; i < BRANCH_STRIP_LED_COUNT; i++) {
    pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
    branch_one_strip.setPixelColor(startNote + i, branch_one_strip.Color(0, 0, 0));
    branch_one_strip.setPixelColor(startNote - i, branch_one_strip.Color(0, 0, 0));
    branch_one_strip.show();
    if(i == 14){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255));
    }
    if(i == 30){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255));
    }
    if(i == 44){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,255), ring_strip.Color(0,0,255));
    }
    if(i == 60){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,255));
    }
    if(i == 76){
      pinMode(RING_STRIP_PIN, OUTPUT);
      create_rings(ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
    }
    delay(waitAddition);
    waitAddition = waitAddition * .95;
  }
}

void branch_fill_color(uint32_t color){
  for(int i = 0; i < BRANCH_STRIP_LED_COUNT; i++){
    branch_one_strip.setPixelColor(i, color);
    }
}
  
void colorWipeBranch(uint32_t color, int wait) {
  for (int i = 0; i < branch_one_strip.numPixels(); i++) {
    branch_one_strip.setPixelColor(i, color);
    branch_one_strip.show();
    delay(wait);
  }
}

void wizards_of_winter(){
  theaterChaseWhite(100);
}

void jingle_bells(){
  for(int count = 0; count < 170; count++){
    if(count == 0){
      pinMode(BRANCH_ONE_STRIP_PIN,OUTPUT);
      pulseFromNoteOn(BRANCH_STRIP_LED_COUNT / 2 - 4, branch_one_strip.Color(255,255,255), 10);
    }
    pinMode(RING_STRIP_PIN, OUTPUT);
    create_rings(ring_strip.Color(150,255,0),ring_strip.Color(0,0,0),ring_strip.Color(150,255,0),ring_strip.Color(0,0,0),ring_strip.Color(150,255,0));
    delay(343);
    create_rings(ring_strip.Color(0,0,0),ring_strip.Color(150,255,0),ring_strip.Color(0,0,0),ring_strip.Color(150,255,0),ring_strip.Color(0,0,0));
    delay(343);
  }
  branch_one_strip.clear();
}

void deck_the_halls(){
  pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
  pulseFromNoteOn(BRANCH_STRIP_LED_COUNT / 2 - 4, branch_one_strip.Color(255,0,0), 8);
  pinMode(RING_STRIP_PIN, OUTPUT);
  create_rings(ring_strip.Color(0,255,0),ring_strip.Color(0,0,0),ring_strip.Color(0,0,0),ring_strip.Color(0,0,0),ring_strip.Color(0,255,0));
  delay(136);
  create_rings(ring_strip.Color(0,255,0),ring_strip.Color(0,255,0),ring_strip.Color(0,0,0),ring_strip.Color(0,255,0),ring_strip.Color(0,255,0));
  delay(136);
  create_rings(ring_strip.Color(0,255,0),ring_strip.Color(0,255,0),ring_strip.Color(0,255,0),ring_strip.Color(0,255,0),ring_strip.Color(0,255,0));
  delay(136);
  create_rings(ring_strip.Color(0,0,0),ring_strip.Color(0,0,0),ring_strip.Color(0,0,0),ring_strip.Color(0,0,0),ring_strip.Color(0,0,0));
  pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
  branch_one_strip.clear();   
}

void most_wonderful_time(){
  pulseFromNoteOnWithRings(BRANCH_STRIP_LED_COUNT / 2 - 10,branch_one_strip.Color(255,255,255),10);
  pulseFromNoteOffWithRings(BRANCH_STRIP_LED_COUNT / 2 - 10,10);  
}

void sarajevo(){
  reversePulseFromNote(branch_one_strip.Color(255,255,255), 2);
  create_rings(ring_strip.Color(0,255,0), ring_strip.Color(0,255,0), ring_strip.Color(0,0,255), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
  delay(241);
  create_rings(ring_strip.Color(0,255,0), ring_strip.Color(0,255,0), ring_strip.Color(0,0,255), ring_strip.Color(0,255,0), ring_strip.Color(0,255,0));
  delay(241);
  branch_one_strip.clear();
  ring_strip.clear();  
}

void winter_wonderland(){
  for(int count = 0; count < 170; count++){
    if(count == 0){
      pinMode(BRANCH_ONE_STRIP_PIN,OUTPUT);
      pulseFromNoteOn(BRANCH_STRIP_LED_COUNT / 2 - 4, branch_one_strip.Color(150,150,255), 10);
    }
    pinMode(RING_STRIP_PIN, OUTPUT);
    create_rings(ring_strip.Color(255,255,255),ring_strip.Color(0,0,0),ring_strip.Color(255,255,255),ring_strip.Color(0,0,0),ring_strip.Color(255,255,255));
    delay(472);
    create_rings(ring_strip.Color(0,0,0),ring_strip.Color(255,255,255),ring_strip.Color(0,0,0),ring_strip.Color(255,255,255),ring_strip.Color(0,0,0));
    delay(472);
  }
  branch_one_strip.clear();  
}
