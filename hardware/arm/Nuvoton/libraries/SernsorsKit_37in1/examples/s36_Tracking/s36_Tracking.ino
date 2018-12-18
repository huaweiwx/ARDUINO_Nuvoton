/*
 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when tracking sensor sense the obstacle.


 The circuit:
 * LED attached from pin 13 to ground
 * tracking sensor output(DO) attached to pin 10

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
const int sensorPin = 10;     // the number of the tracking sensor pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int sensorState = 0;         // variable for reading the tracking sensor status

void setup()
{
    // initialize the LED pin as an output:
    pinMode(ledPin, OUTPUT);
    // initialize the tracking sensor pin as an input:
    pinMode(sensorPin, INPUT);
}

void loop()
{
    // read the state of the tracking sensor value:
    sensorState = digitalRead(sensorPin);

    // check if the tracking sensor is pressed.
    // if it is, the sensorState is HIGH:
    if (sensorState == HIGH)
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