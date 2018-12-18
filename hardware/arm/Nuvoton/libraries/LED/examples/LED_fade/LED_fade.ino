/*
 LED_fade.ino
 This example shows how to fade an LED
 using the analogWrite() function.

 This example code is in the public domain.
 */
#include <LED.h>   /*LEDClass: Led Led1/2/3/4/5/6/7 has be predefiend */

// the setup routine runs once when you press reset:
void setup() {
  //  put your setup code here, to run once:
  Serial.begin(115200);
  Led.Init();
  delay(2000); /*wait for serial ready*/
  Serial.println("I'm going to sleep.......");
}

void loop() {
  // put your main code here, to run repeatedly:
  Led.fade(1000);
}
