/*
  This sketch fades LEDs up and down one at a time on digital pins 2 through 4.  
 	
  The circuit:
  * LEDs attached from pins 2 through 4 to ground.

  This example code is in the public domain.
  
*/
// These constants won't change.  They're used to give names
// to the pins used:
const int lowestPin = 0;
const int highestPin = 2;

int rgbLed[]={ 2, 3, 4 };  /* R, G, B LED */

void setup() {
  // set pins 2 through 4 as outputs:
  for (int thisPin =lowestPin; thisPin <= highestPin; thisPin++) { 
    pinMode(rgbLed[thisPin], OUTPUT); 
  }
}

void loop() {
  // iterate over the pins:
  for (int thisPin =lowestPin; thisPin <= highestPin; thisPin++) { 
    // fade the LED on thisPin from off to brightest:
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(rgbLed[thisPin], brightness);
      delay(2);
    } 
    // fade the LED on thisPin from brithstest to off:
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(rgbLed[thisPin], brightness);
      delay(2);
    } 
    // pause between LEDs:
    delay(100);
  }
}