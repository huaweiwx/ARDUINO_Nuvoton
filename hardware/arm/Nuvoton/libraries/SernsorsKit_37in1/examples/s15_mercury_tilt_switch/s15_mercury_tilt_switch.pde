/*
 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when mercury tilt switch is on.


 The circuit:
 * LED attached from pin 13 to ground
 * mercury tilt switch attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 *modified Oct 2018 by nuvoTon for 37 in 1 sensor kit
 
 */

// constants won't change. They're used here to
// set pin numbers:
const int mercurySwitchPin = 10; // the number of the mercury tilt switch pin
const int ledPin =  13;          // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the mercury tilt switch pin status

void setup()
{
    Serial.begin(115200);
    // initialize the LED pin as an output:
    pinMode(ledPin, OUTPUT);
    // initialize the mercury tilt switch pin as an input:
    pinMode(mercurySwitchPin, INPUT);
}

void loop()
{
    // read the state of the mercury tilt switch pin value:
    buttonState = digitalRead(mercurySwitchPin);
    Serial.println(buttonState);
    // check if the mercury tilt switch pin is on.
    // if it is, the mercury tilt switch is HIGH:
    if (buttonState == HIGH)
    {
        // turn LED off:
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        // turn LED on:
        digitalWrite(ledPin, LOW);
    }
}