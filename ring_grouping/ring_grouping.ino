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

#define LOWER_MIDDLE_START 88
#define LOWER_MIDDLE_SIZE 71

#define MIDDLE_RING_START 158
#define MIDDLE_RING_SIZE 67

#define UPPER_MIDDLE_START 225
#define UPPER_MIDDLE_SIZE 35

#define TOP_RING_START 260
#define TOP_RING_SIZE 23

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
   wizards_of_winter();
   delay(100);
   jingle_bells();
   delay(100);
   deck_the_halls();
   delay(1000);
   most_wonderful_time();
   delay(1000);
   sarajevo();
   delay(100);
   winter_wonderland();
   delay(1000);
   frosty_the_snowman();
   delay(100);
   let_it_snow();
   delay(100);
   placeholder();
   delay(202000);
   
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

void theaterChase(int wait, Adafruit_NeoPixel lights) {
  int firstPixelHue = 0; 
  for(int a=0; a<100; a++) { 
    for(int b=0; b<3; b++) { 
      lights.clear();
      for(int c=b; c<lights.numPixels(); c += 3) {
        lights.setPixelColor(c, lights.Color(255,255,255)); 
      }
      lights.show();                
      delay(wait);                 
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

void pulse_from_note(int startNote, uint32_t color, int wait){
  branch_one_strip.setPixelColor(startNote, color);
  branch_one_strip.show();
  branch_one_strip.setPixelColor(startNote, branch_one_strip.Color(0, 0, 0));
  branch_one_strip.show();
  for (int i = 1; i < BRANCH_STRIP_LED_COUNT/2 + 10; i++) {
    pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
    branch_one_strip.setPixelColor(startNote + i, color);
    branch_one_strip.setPixelColor(startNote - i, color);
    branch_one_strip.show();
    delay(wait);
    branch_one_strip.setPixelColor(startNote + i, branch_one_strip.Color(0, 0, 0));
    branch_one_strip.setPixelColor(startNote - i, branch_one_strip.Color(0, 0, 0));
    branch_one_strip.show();
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
  
void colorWipeBranch(uint32_t color, int wait) {
  for (int i = 0; i < branch_one_strip.numPixels(); i++) {
    branch_one_strip.setPixelColor(i, color);
    branch_one_strip.show();
    delay(wait);
  }
}

void wizards_of_winter(){
  for(int i = 0; i < 18; i++){
    theaterChaseWhite(100); 
  }
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
  for(int i = 0; i < 144; i++){
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
}

void most_wonderful_time(){
  for(int i = 0; i < 90; i++){
    pulseFromNoteOnWithRings(BRANCH_STRIP_LED_COUNT / 2 - 10,branch_one_strip.Color(255,255,255),10);
    pulseFromNoteOffWithRings(BRANCH_STRIP_LED_COUNT / 2 - 10,10);  
  }
}

void sarajevo(){
  for(int i = 0; i < 234; i++){
  reversePulseFromNote(branch_one_strip.Color(255,255,255), 2);
  create_rings(ring_strip.Color(0,255,0), ring_strip.Color(0,255,0), ring_strip.Color(0,0,255), ring_strip.Color(0,0,0), ring_strip.Color(0,0,0));
  delay(241);
  create_rings(ring_strip.Color(0,255,0), ring_strip.Color(0,255,0), ring_strip.Color(0,0,255), ring_strip.Color(0,255,0), ring_strip.Color(0,255,0));
  delay(241);
  branch_one_strip.clear();
  ring_strip.clear();  
  }
}

void winter_wonderland(){
  for(int count = 0; count < 160; count++){
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

void frosty_the_snowman(){
  for(int i = 0; i < 2; i++){
  pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
  pulseFromNoteOn(BRANCH_STRIP_LED_COUNT / 2 - 4, branch_one_strip.Color(150,255,0), 10);
  pinMode(RING_STRIP_PIN, OUTPUT);
  theaterChase(195, ring_strip);
  }
}

void let_it_snow(){
  for(int i = 0; i < 15; i ++){
  pinMode(RING_STRIP_PIN,OUTPUT);
   create_rings(ring_strip.Color(255,255,255),ring_strip.Color(255,255,255),ring_strip.Color(255,255,255),ring_strip.Color(255,255,255),ring_strip.Color(255,255,255));
   pinMode(BRANCH_ONE_STRIP_PIN, OUTPUT);
   branch_one_strip.setBrightness(BRIGHTNESS / 2);
   pulse_from_note(BRANCH_STRIP_LED_COUNT / 2 - 10, branch_one_strip.Color(255,255,255), 75);  
  }
}

void placeholder(){
   pulseFromNoteOn(BRANCH_STRIP_LED_COUNT / 2 - 4, branch_one_strip.Color(255,255,255), 10);
 }
