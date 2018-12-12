/*
  74165  series input demo
  huaweiwx@sina.com 2018.9.28
*/


#define IN_PIN   PF2
#define CLK_PIN   PF3
#define nPL_PIN   PF4
//#define nOE_PIN   PF5   //connet to GND

ClockedInput<>  sinp165(IN_PIN, CLK_PIN);
OutputPin       readCLK(nPL_PIN);

#ifdef nOE_PIN
OutputPin outputEnable(nOE_PIN);
#endif

uint8_t read165(void) {
  readCLK.pulse();    //getdate
  uint8_t val = sinp165; //shiftin
}

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);

  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  
#ifdef nOE_PIN
  outputEnable = LOW;
#endif
}

void loop() {
  Serial.println(read165(),HEX);
  
  digitalToggle(LED_BUILTIN);
  delay(1000);
}
