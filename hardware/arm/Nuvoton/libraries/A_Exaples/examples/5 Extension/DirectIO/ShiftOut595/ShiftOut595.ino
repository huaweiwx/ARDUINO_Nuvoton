/*
  74595/74164 series output demo
  huaweiwx@sina.com 2018.9.28
*/


#define DS_PIN   PF2
#define SHCP_PIN PF3
#define STCP_PIN PF4
//#define nOE_PIN   PF5   //connet to GND
//#define nMR_PIN   PF6   //connet to VCC 

ClockedOutput<> sout595(DS_PIN, SHCP_PIN);
OutputPin       storageCLK(STCP_PIN);

#ifdef nOE_PIN
OutputPin outputEnable(nOE_PIN);
#endif

void write595(uint8_t val) {
  sout595.write(val);
  storageCLK.pulse();
}

void setup() {
#ifdef nOE_PIN
  outputEnable = LOW;
#endif
}

void loop() {
  static uint8_t i = 0;
  write595(i);
  i++;
  delay(100);
}
