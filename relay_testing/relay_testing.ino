// all off, 1 lights up till all on.  Then chase off
// this is the one I used

int timerdown =100;
int timerup =150;
int timeron = 500;
int timeroff1 = 300;

int ledPins[] = { 
  2,3,4,5,6,7,8,9};       // an array of pin numbers to which LEDs are attached
int pinCount = 8;           // the number of pins (i.e. the length of the array)

void setup() {
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);      
  }
}

void loop() 
{
 

  // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);   
    delay(timerup);                  
    // turn the pin off:
  }
  delay(timeron);
 for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
    // turn the pin on:
    digitalWrite(ledPins[thisPin], LOW);   
    delay(timerdown);                  
    // turn the pin off:

}
  delay(timeroff1);
}
