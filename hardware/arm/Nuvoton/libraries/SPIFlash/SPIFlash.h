/*
 * Copyright (c) 2014 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */
 
#ifndef _SPIFLASH_H_INCLUDED
#define _SPIFLASH_H_INCLUDED

#include "Arduino.h"


class SPIFlashClass {
	
public :	
/**
  * This needs to be called to set up the connection to the SPI Flash
  * before other methods are used.
**/  
	boolean begin(uint8_t csPin = SS);	
/**
  * @brief  Read SPI flash manufacturer ID and device ID.
  * @param  None.
  * @return High byte is manufacturer ID; low byte is device ID.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */	
uint32_t ReadMidDid(void);
	
/**
  * @brief  Erase whole SPI flash memory.
  * @param  None.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void ChipErase(void);	

/**
  * @brief  Read SPI flash status register.
  * @param  None.
  * @return Status register value.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
byte ReadStatusReg(void);

/**
  * @brief  Write SPI flash status register.
  * @param  u32Value is the value attempt to write to status register.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void WriteStatusReg(uint32_t u32Value);

/**
  * @brief  Wait SPI flash ready.
  * @param  None.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void WaitReady();

/**
  * @brief  Perform SPI flash page program.
  * @param  u32StartAddress is the start address.
  * @param  au8DataBuffer is the pointer of source data.
  * @param  u32ByteCount is the total data count. The maximum number is 256.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void PageProgram(uint32_t u32StartAddress, uint8_t *au8DataBuffer, uint32_t u32ByteCount);

/**
  * @brief  Read SPI flash memory.
  * @param  u32StartAddress is the start address.
  * @param  au8DataBuffer is the pointer of destination buffer.
  * @param  u32ByteCount is the total data count.
  * @return None.
  * @note   Before calling this function, the transaction length (data width) must be configured as 8 bits.
  */
void ReadData(uint32_t u32StartAddress, uint8_t *au8DataBuffer, uint32_t u32ByteCount);

protected:
	int slaveSelectPin;

};

extern SPIFlashClass SPIFlash;

#endif