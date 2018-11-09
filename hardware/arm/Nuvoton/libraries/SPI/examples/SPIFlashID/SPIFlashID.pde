/*
  SPI Flash
  
	This sample code demonstrates how to access a Winbond 25x16 SPI flash without FIFO buffers.
	SPI configuration : Master mode; data width 8 bits.
		
*/
 
 // inslude the SPI library:
#include <SPI.h>

// set pin 10 as the slave select for the digital pot:
const int slaveSelectPin = SS;

void setup()
{
  uint32_t u32ID;
  Serial.begin(115200);
  Serial.print("\n+------------------------------------------------------------------------+\n");
  Serial.print("|               SPI Flash with FIFO mode Sample                          |\n");
  Serial.print("+------------------------------------------------------------------------+\n");  
  Serial.println("This sample code demonstrates how to access a");
  Serial.println("Winbond 25x16 SPI flash without FIFO buffers.");
  // set the slaveSelectPin as an output:
  pinMode (slaveSelectPin, OUTPUT);
  // initialize SPI:
  SPI.begin();
  
  /* Wait ready */
  SpiFlash_WaitReady();  
  if((u32ID = SpiFlash_ReadMidDid()) != 0xEF14)
  {
    Serial.print("Wrong ID, 0x");
    Serial.println(u32ID,HEX);
    return;		
  }else
    Serial.print("Flash found: W25x16 ...\n");	
}

void loop()
{

}


byte SpiFlash_ReadStatusReg()
{
  byte RxData;	  
  // /CS: active
  digitalWrite(slaveSelectPin,LOW);
  /* send Command: 0x05, Read status register */
  SPI.transfer(0x05);	
  /* Send SPI bus clock to read status register */	
  RxData=SPI.transfer(0x00);   
  digitalWrite(slaveSelectPin,HIGH);	  
  return RxData;
}

/**
  * @brief  Wait SPI flash ready.
  * @param  spi is the base address of SPI module.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void SpiFlash_WaitReady()
{
    while((SpiFlash_ReadStatusReg()) & 1); /* check the BUSY status bit */
}

/**
  * @brief  Read SPI flash manufacturer ID and device ID.
  * @param  spi is the base address of SPI module.
  * @return High byte is manufacturer ID; low byte is device ID.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
uint32_t SpiFlash_ReadMidDid()
{
  uint32_t u32MID_DID;	
  // CS: active
  digitalWrite(slaveSelectPin,LOW);	
  //Send command 0x90: Read Manufacturer/Device ID
  SPI.transfer(0x90);	
  //Send 24 '0' dummy bits 
  SPI.transfer(0x00); /* Send the first  8 dummy bits */
  SPI.transfer(0x00); /* Send the second 8 dummy bits */
  SPI.transfer(0x00); /* Send the third  8 dummy bits */
  //Send SPI bus clock to get Manufacturer ID 
  u32MID_DID = SPI.transfer(0x00)<<8;	
  //Send SPI bus clock to get Device ID
  u32MID_DID |= SPI.transfer(0x00);  
  //CS: inactive
  digitalWrite(slaveSelectPin,HIGH);	
  return u32MID_DID;
}