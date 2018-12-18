/*
  Calibration
 
 Demonstrates one technique for calibrating sensor input.  The
 sensor readings during the first five seconds of the sketch
 execution define the minimum and maximum of expected values
 attached to the sensor pin.
 
 The sensor minimum and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything 
 lower, saving it as the new minimum. Likewise, you set the
 maximum low and listen for anything higher as the new maximum.
 
 The circuit:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 9 to ground
 
 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/Calibration
 
 This example code is in the public domain.
 
 */

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
int rgbLed[]={ 2, 3, 4 };    // R, G, B pin that the LED is attached to

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 0;           // minimum sensor value
int sensorMax = 1023;        // maximum sensor value


void setup() {
  pinMode(rgbLed[0], OUTPUT);
  pinMode(rgbLed[1], OUTPUT);
  pinMode(rgbLed[2], OUTPUT);  
}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);
  
  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);
  
  //remove interference
  if(sensorValue>253) sensorValue=255; 
 
  // fade the LED using the calibrated value:
  analogWrite(rgbLed[0], sensorValue);
  analogWrite(rgbLed[1], sensorValue);
  analogWrite(rgbLed[2], sensorValue);
}