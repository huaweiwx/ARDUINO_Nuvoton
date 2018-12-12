/*
  errorLedBlink.ino 
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  _Error_Handler(__FILENAME__, __LINE__);
}

// the loop function runs over and over again forever
void loop() {
}
