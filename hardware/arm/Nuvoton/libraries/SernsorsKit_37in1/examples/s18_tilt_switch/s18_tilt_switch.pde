/*

 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when the tilt switch closed. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * tilt switch attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
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
const int tiltSwitchPin = 10;     // the number of the tilt switch pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the tilt switch status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the tilt switch pin as an input:
  pinMode(tiltSwitchPin, INPUT);     
}

void loop(){
  // read the state of the tilt switch value:
  buttonState = digitalRead(tiltSwitchPin);

  // check if the tilt switch is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, LOW);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, HIGH); 
  }
}