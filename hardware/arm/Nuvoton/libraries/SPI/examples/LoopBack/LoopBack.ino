/*
  SPI LoopBack
  
	This sample code demonstrates SPI self loop back data transfer.
	SPI configuration : Master mode; data width 8 bits.
	I/O connection    : ICSP interface MOSI <--> MISO
*/


// inslude the SPI library:
#include <SPI.h>


// set pin 10 as the slave select for the digital pot:
const int slaveSelectPin = 10;

void setup() {
  Serial.begin(115200);
  // set the slaveSelectPin as an output:
  pinMode (slaveSelectPin, OUTPUT);
  // initialize SPI:
  SPI.begin(); 
}

void loop() {
  // go through the six channels of the digital pot:
  for (int channel = 0; channel < 6; channel++) { 
    // change the resistance on this channel from min to max:
    for (int level = 0; level < 255; level++) {
      WriteReadSPI(channel, level);
      delay(10);
    }
    // wait a second at the top:
    delay(100);
    // change the resistance on this channel from max to min:
    for (int level = 0; level < 255; level++) {
      WriteReadSPI(channel, 255 - level);
      delay(10);
    }
  }

}
int reciveAddress;
int reciveValue;
int WriteReadSPI(int address, int value) {
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin,LOW);
  //  send in the address and value via SPI:
  reciveAddress=SPI.transfer(address);
  reciveValue=SPI.transfer(value);
  
  Serial.print("address=");
  Serial.print(reciveAddress);
  Serial.print("  value=");
  Serial.println(reciveValue);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin,HIGH); 
}