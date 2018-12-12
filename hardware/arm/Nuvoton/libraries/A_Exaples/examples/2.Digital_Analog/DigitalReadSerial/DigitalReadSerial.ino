/*
  digital read  pin PA0 and print it on uart1
  demo by huaweiwx<huaweiwx@sina.com> 2016.9.18
 */

void setup() {
	pinMode(LED_BUILTIN,OUTPUT);
	pinMode(PA0,INPUT);

  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
}

void loop() {
	int sensorValue = digitalRead(PA0);
	Serial1.println(sensorValue, DEC);
	
	digitalToggle(LED_BUILTIN);
	delay(1000);
}
