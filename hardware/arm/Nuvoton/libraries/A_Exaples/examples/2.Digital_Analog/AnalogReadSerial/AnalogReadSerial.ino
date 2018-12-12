/*
  analogReadSerial.ino
  This example code is in the public domain.
  huaweiwx@sina.com 2018.8
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  digitalToggle(LED_BUILTIN);   // turn the LED on (HIGH is the voltage level)
  
  Serial.println(analogRead(PB_0)); /*output analogRead val*/
  delay(1000);                  // wait for a second
}
