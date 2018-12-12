/* blink.ino arduino example for nuvoton  
  by  huawei <huaweiwx@sina.com> 2016.9.20
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
}


void loop() {
	// put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN,LOW);
  delay(500);
}
