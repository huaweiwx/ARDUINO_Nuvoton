/*
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when touch the touch sensor attached to pin 10. 
 
 
 The circuit:
 * LED attached from pin 13 to ground  
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 28 Oct 2010
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 
 *modified Oct 2018 by nuvoTon for 37 in 1 sensor kit
 
 */

// constants won't change. They're used here to 
// set pin numbers:
const int touchSensorOutputnPin = 10;     // the number of the touch sensor pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int touchState = 0;         // variable for reading the touch sensor status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the touch sensor pin as an input:
  pinMode(touchSensorOutputnPin, INPUT);     
}

void loop(){
  // read the state of the touch sensor value:
  touchState = digitalRead(touchSensorOutputnPin);

  // check if the touch sensor is pressed.
  // if it is, the touchState is HIGH:
  if (touchState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}