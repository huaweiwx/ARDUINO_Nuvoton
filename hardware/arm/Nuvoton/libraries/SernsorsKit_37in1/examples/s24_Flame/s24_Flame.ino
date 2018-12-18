/*
 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when the flame sensor output HIGH.


 The circuit:
 * LED attached from pin 13 to ground
 * flame sensor attached to pin 2 from +5V
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
const int flameSensorPin = 10;     // the number of the flame sensor pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int flameSensorState = 0;         // variable for reading the flame sensor status

void setup()
{
    // initialize the LED pin as an output:
    pinMode(ledPin, OUTPUT);
    // initialize the flame sensor pin as an input:
    pinMode(flameSensorPin, INPUT);
}

void loop()
{
    // read the state of the flame sensor value:
    flameSensorState = digitalRead(flameSensorPin);

    // check if the flame sensor is pressed.
    // if it is, the flameSensorState is HIGH:
    if (flameSensorState == HIGH)
    {
        // turn LED on:
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        // turn LED off:
        digitalWrite(ledPin, LOW);
    }
}