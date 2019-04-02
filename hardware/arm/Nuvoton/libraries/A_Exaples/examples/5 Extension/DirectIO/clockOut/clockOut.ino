/*
  clockOut.ino  shiftin/shiftout examples
  example:
    ClockedInput<bits,bit_order>  sinp(datapin,clockpin,pullup)	  
    ClockedOutput<bits,bit_order> sout(datapin,clockpin);
      bits: 0~32,default is 8
      bit_order: LSBFIRST/MSBFIRST default is MSBFIRST
      pullup:false/true default is true
	function:
      read()
      write(val)
      operate ()
      operate =	  
*/

#define DAT_PIN PA_0
#define CLK_PIN PA_1

//#define TEST_INPUT

#ifdef TEST_INPUT
ClockedInput<>  sinp(DAT_PIN,CLK_PIN);
#else
ClockedOutput<> sout(DAT_PIN,CLK_PIN);
#endif

void setup() {
   pinMode(LED_BUILTIN,OUTPUT);

#ifdef TEST_INPUT
   Serial.begin(115200);
#endif
}

void loop() {
#ifdef TEST_INPUT
  uint8_t indate = sinp;  /*use operate ()*/
  Serial.print("input is: ");
  Serial.println(indate,HEX);
#else  
  sout = 0x55;   /*use operate =*/
#endif
  delay(1000);
  digitalToggle(LED_BUILTIN);
}

