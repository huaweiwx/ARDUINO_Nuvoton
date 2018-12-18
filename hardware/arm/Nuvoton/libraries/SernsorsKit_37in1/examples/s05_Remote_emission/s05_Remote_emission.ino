#include <nvtIRremote.h> 
IRsend irsend;  //pin 8 is the output pin
void setup() 
{ 
  Serial.begin(115200); 
} 
void loop() 
{ 
  for (int i = 0; i < 50; i++) 
  { 
		irsend.sendSony(0xa90, 12); // Sony TV power code
		delay(500);
	}
}