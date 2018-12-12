/* blink_toggle.ino arduino extantion example for efm32g222fx  
  by  huawei <huaweiwx@sina.com> 2016.9.20
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
}


void loop() {
	// put your main code here, to run repeatedly:
  digitalToggle(LED_BUILTIN,LOW);
  delay(500);
}
