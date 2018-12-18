/*
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when the reed switch output HIGH. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * reed switch attached to pin 10 from DO
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 28 Oct 2010
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int switchPin = 10;     // the number of the reed switch pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int switchState = 0;         // variable for reading the reed switch status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the reed switch pin as an input:
  pinMode(switchPin, INPUT);     
}

void loop(){
  // read the state of the reed switch value:
  switchState = digitalRead(switchPin);

  // check if the reed switch is pressed.
  // if it is, the switchState is HIGH:
  if (switchState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}