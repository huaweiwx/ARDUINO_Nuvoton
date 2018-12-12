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
//#define TEST_INPUT

#ifdef TEST_INPUT
ClockedInput<>  sinp(PA0,PA1);
#else
ClockedOutput<> sout(PA0,PA1);
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

