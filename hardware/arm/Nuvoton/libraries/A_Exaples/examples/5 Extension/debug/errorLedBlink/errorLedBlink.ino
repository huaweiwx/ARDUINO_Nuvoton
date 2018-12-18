/*
  errorLedBlink.ino 
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
int count = 0;
void loop() {
  digitalToggle(LED_BUILTIN);
  Serial.print("Count: ");
  Serial.println(count);
  count++;
  delay(1000);
  if(count > 10){
     _Error_Handler(__FILENAME__, __LINE__);
  }
}
