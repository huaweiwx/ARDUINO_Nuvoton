/* demo dac output 1.0v

   DAC class func list:
     DAC<ch>dac               : creat a DAC instance default ch is 0, dac is predefined
     Init(ref) or ref(ref)    : set reference dacRef1V25/dacRef2V5/dacRefVDD  default is vRef = dacRefVDD (3.3V)
	                                arduino define INTERNAL1V25/INTERNAL2V5/INTERNAL3V3(or INTERNALVDD)
     valueCalcul(vOut)        ; calculate dac output val val = vOut * 4095 / vRef;
     write(val)               : dac out val;
     enable(bool)             : turn dac out on/off
     pause(void)              : dac out off
     resume(void)             : dac out on

   2018.8.20 huaweiwx@sina.com
*/

DAC<>myDacCh0;

void setup() {
  //  put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  /*  set ref (default VDD 3.3v)   */
  //myDacCh0.Init(dacRef2V5);
  myDacCh0.ref(INTERNAL1V25);

  uint32_t outval = myDacCh0.valueCalcul(1.0); /*calcul out 1.0v value eq 1.0*4095/1.25 */
  myDacCh0.write(outval); /*dac output*/
}

void loop() {
  digitalToggle(LED_BUILTIN);
  delay(500);
}
