/*
  High sensitive voice
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when the voice sensor attached to pin 10 sense the output. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * voice sensor output(DO) attached to pin 10
 
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
const int voiceSensorDO_Pin = 10;     // the number of the voice sensor pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int voiceSensorState = 0;         // variable for reading the voice sensor status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the voice sensor pin as an input:
  pinMode(voiceSensorDO_Pin, INPUT);     
}

void loop(){
  // read the state of the voice sensor value:
  voiceSensorState = digitalRead(voiceSensorDO_Pin);

  // check if the voice sensor is pressed.
  // if it is, the voiceSensorState is HIGH:
  if (voiceSensorState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}