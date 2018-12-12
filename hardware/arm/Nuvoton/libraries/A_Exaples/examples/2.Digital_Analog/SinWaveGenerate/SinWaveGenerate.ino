/*
  sineGeneriate.ino EFM32DAC demo
  
  DAC class func list:
     DAC<ch>dac               : creat a DAC instance default ch is 0, dac is predefined
     Init(ref) or ref(ref)    : set reference dacRef1V25/dacRef2V5/dacRefVDD  default is vRef = dacRefVDD(3.3v)
     valueCalcul(vOut)        ; calculate dac output val val = vOut * 4095 / vRef;
     write(val)               : dac out val;
     enable(bool)             : turn dac out on/off
     pause(void)              : dac out off
     resume(void)             : dac out on

   2018.8.20 huaweiwx@sina.com
*/

#define NUMS    72
static uint16_t wavedatas [NUMS];

static uint16_t myfunc(int i) {
  int mul = 10000;
  int res = sin(2 * PI / NUMS * i) * mul; /* res: -10000~10000 */
  return (uint16_t) map(res, -mul, mul,  0, 0xfff); /* map to 0 ~ 4095 */
}

// the setup routine runs once when you press reset:
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  
  delay(2000);
  
  Serial.println("sine wave generate demo...");
  for (int i = 0; i < NUMS; i++) wavedatas[i] = myfunc(i);
  
  /*  set reference (default VDD 3.3v)  */
  // dac.Init(dacRefVDD);
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i = 1; i <NUMS ; i++) {
    dac.write(wavedatas[i]);
  }
}

