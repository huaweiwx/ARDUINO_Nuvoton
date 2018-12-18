/*
   Hello World! arduino Serial.println it on USART0/1/LEUART
   demo by huawei<huaweiwx@sina.com> 2016.9.18
 */

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
//  Serial.setRouteLoc(1); /*default Loc 0*/
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) Loc 0*/
}

void loop() {
  digitalToggle(LED_BUILTIN);
  Serial.println(PORTD,HEX);
  delay(1000);
}
