/*
 * Copyright (c) 2014 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */
#include "SPIFlash.h"
#include <SPI.h>
/**
  * This needs to be called to set up the connection to the SPI Flash
  * before other methods are used.
**/  
boolean SPIFlashClass::begin(uint8_t csPin)
{
	slaveSelectPin=csPin;
	pinMode(csPin,OUTPUT);
	SPI.begin();	
	return TRUE;
}
	
/**
  * @brief  Read SPI flash manufacturer ID and device ID.
  * @param  None.
  * @return High byte is manufacturer ID; low byte is device ID.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */	
uint32_t SPIFlashClass::ReadMidDid(void)
{
	uint32_t u32MID_DID;
	
	/* CS: active */
	digitalWrite(slaveSelectPin,LOW);
	
	/* Send command 0x90: Read Manufacturer/Device ID */
	SPI.transfer(0x90);
	
	/* Send 24 '0' dummy bits */
	SPI.transfer(0x00);
	SPI.transfer(0x00);
	SPI.transfer(0x00);
	
	/* Send SPI bus clock to get Manufacturer ID */
	u32MID_DID=SPI.transfer(0x00)<<8;
	
	/* Send SPI bus clock to get Device ID */
	u32MID_DID|=SPI.transfer(0x00);
	
	/* CS: inactive */
	digitalWrite(slaveSelectPin,HIGH);
	
	return u32MID_DID;	
}
	
	
/**
  * @brief  Erase whole SPI flash memory.
  * @param  None.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void SPIFlashClass::ChipErase(void)
{
	/* CS: active */
	digitalWrite(slaveSelectPin,LOW);
	/* Send command 0x06: Write enable */
	SPI.transfer(0x06);	
	/* CS: inactive */
	digitalWrite(slaveSelectPin,HIGH);
	
	delay(10);
	
	/* CS: active */
	digitalWrite(slaveSelectPin,LOW);
	/* Send command 0xC7: Chip erase */	
	SPI.transfer(0xC7);
	/* CS: inactive */
	digitalWrite(slaveSelectPin,HIGH);
}

/**
  * @brief  Read SPI flash status register.
  * @param  None.
  * @return Status register value.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
byte SPIFlashClass::ReadStatusReg(void)
{
	byte RxData;
	
	// /CS: active
	digitalWrite(slaveSelectPin,LOW);
	
	// send Command: 0x05, Read status register
	SPI.transfer(0x05);
	
	// read status
	RxData=SPI.transfer(0x00);
	
	// /CS: inactive
	digitalWrite(slaveSelectPin,HIGH);
	
	return RxData;	
}

/**
  * @brief  Write SPI flash status register.
  * @param  u32Value is the value attempt to write to status register.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void SPIFlashClass::WriteStatusReg(uint32_t u32Value)
{
	/* CS: active */
	digitalWrite(slaveSelectPin,LOW);
	/* Send command 0x06: Write enable */
	SPI.transfer(0x06);	
	/* CS: inactive */
	digitalWrite(slaveSelectPin,HIGH);
	
	delay(10);
		
	/* CS: active */
	digitalWrite(slaveSelectPin,LOW);
	/* Send command 0x01: Write status register */
	SPI.transfer(0x01);		
	/* write to status register 1 */
	SPI.transfer(u32Value&0xFF);		
	/* write to status register 2 */
	SPI.transfer((u32Value >> 8) & 0xFF);
	/* CS: inactive */
	digitalWrite(slaveSelectPin,HIGH);
}

/**
  * @brief  Wait SPI flash ready.
  * @param  None.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void SPIFlashClass::WaitReady(void)
{
	 while((ReadStatusReg()) & 1); /* check the BUSY status bit */		
}

/**
  * @brief  Perform SPI flash page program.
  * @param  u32StartAddress is the start address.
  * @param  au8DataBuffer is the pointer of source data.
  * @param  u32ByteCount is the total data count. The maximum number is 256.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void SPIFlashClass::PageProgram(uint32_t u32StartAddress, uint8_t *au8DataBuffer, uint32_t u32ByteCount)
{
	uint32_t u32Counter;
	/* CS: active */
	digitalWrite(slaveSelectPin,LOW);	
	/* Send command 0x06: Write enable */
	SPI.transfer(0x06);	
	/* CS: inactive */
	digitalWrite(slaveSelectPin,HIGH);	
	
	delay(10);
	
	/* CS: active */
	digitalWrite(slaveSelectPin,LOW);	
	/* Send command 0x02: Page program */
	SPI.transfer(0x02);	
	/* Send 24-bit start address */
  SPI.transfer((u32StartAddress >> 16) & 0xFF);  /* Send the first  8 address bits */
  SPI.transfer((u32StartAddress >>  8) & 0xFF);  /* Send the second 8 address bits */ 
  SPI.transfer((u32StartAddress >>  0) & 0xFF);  /* Send the third  8 address bits */
  
  /* Reset TX data counter */
	u32Counter = 0;
	while(u32Counter < u32ByteCount) 
	{
		/* Write one byte to SPI flash */
		SPI.transfer(au8DataBuffer[u32Counter++]);	
	} 	
	/* CS: inactive */
	digitalWrite(slaveSelectPin,HIGH);	
}

/**
  * @brief  Read SPI flash memory.
  * @param  u32StartAddress is the start address.
  * @param  au8DataBuffer is the pointer of destination buffer.
  * @param  u32ByteCount is the total data count.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void SPIFlashClass::ReadData(uint32_t u32StartAddress, uint8_t *au8DataBuffer, uint32_t u32ByteCount)
{
	uint32_t u32RxCounter;
	/* CS: active */
	digitalWrite(slaveSelectPin,LOW);	
	/* Send command 0x03: Read data */
	SPI.transfer(0x03);
	/* Send 24-bit start address */    
  SPI.transfer((u32StartAddress >> 16) & 0xFF);  /* Send the first  8 address bits */
  SPI.transfer((u32StartAddress >>  8) & 0xFF);  /* Send the second 8 address bits */ 
  SPI.transfer((u32StartAddress >>  0) & 0xFF);  /* Send the third  8 address bits */
  
  /* Reset RX data counter */
  u32RxCounter = 0;
	while(u32RxCounter < u32ByteCount)
	{
		/* Send SPI bus clock to get data from SPI flash */
		au8DataBuffer[u32RxCounter++]=SPI.transfer(0x00);
  }
	// /CS: inactive
	digitalWrite(slaveSelectPin,HIGH);
}

SPIFlashClass SPIFlash;