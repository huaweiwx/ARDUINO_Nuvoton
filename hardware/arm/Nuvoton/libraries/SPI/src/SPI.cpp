/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#include "SPI.h"

#if defined(__NUC240__) | defined(__NANO100__)
#define SPI_WRITE_TX(spi, u32TxData) 	SPI_WRITE_TX0(spi, u32TxData);
#define SPI_READ_RX(spi)                SPI_READ_RX0(spi)
#endif		
					
#define SPI_ID0 0

SPIClass::SPIClass(SPI_T *_spi, uint8_t ucLoc) :
	  spi(_spi), ucLoc(ucLoc)
{
	  this->spi=_spi;
	  this->ucLoc=ucLoc;
	  if(spi = SPI0) this->idx = 0;
#ifdef SPI1
      else 	if(spi = SPI1) this->idx = 1;
#elif defined(SPI2)
      else 	if(spi = SPI2) this->idx = 2;
#elif defined(SPI3)
      else 	if(spi = SPI3) this->idx = 3;
#elif defined(SPI4)
      else 	if(spi = SPI4) this->idx = 4;
#elif defined(SPI5)
      else 	if(spi = SPI5) this->idx = 5;
#endif  
	  this->module = SPI_Desc[idx].module;
      this->clksel = SPI_Desc[idx].clksel;
	  this->id     =SPI_Desc[idx].irq;
}

SPIClass::SPIClass(uint8_t idx,uint8_t ucLoc) :
	  idx(idx), ucLoc(ucLoc)
{
	  this->idx = idx;
	  this->spi=SPI_Desc[idx].S;
	  this->ucLoc = ucLoc;
	  this->module = SPI_Desc[idx].module;
      this->clksel = SPI_Desc[idx].clksel;
	  this->id=SPI_Desc[idx].irq;
}

void SPIClass::Init() {
	 SPI_Config(SPI_Desc[idx].pinAlt[loc]);	
	 this->init_flag = 1;
}

void SPIClass::begin() {		
	
	if(init_flag==0) Init();
	
	 /* Unlock protected registers */
	SYS_UnlockReg();	

	/* Enable IP clock */       
	CLK_EnableModuleClock(module);    	
   	
  /* Select IP clock source and clock divider */
	CLK_SetModuleClock(module,clksel,0);
	
	/* Lock protected registers */
	SYS_LockReg();
			  
	/* Configure as a master, clock idle low, falling clock edge Tx, rising edge Rx and 8-bit transaction */
  /* Set IP clock divider. SPI clock rate = 4MHz */  
  SPI_Open(spi, SPI_MASTER, SPI_MODE_0, 8, 4000000); 
#if defined(__NUC240__)	| defined(__NANO100__) | defined(__NUC131__)
  SPI_EnableFIFO(spi,12,12);
#endif
  setBitOrder(SS, MSBFIRST);  

#if defined(__M451__) 
  SPI_ClearRxFIFO(spi);
  SPI_TRIGGER(spi);
#endif

}

void SPIClass::begin(uint8_t _pin) {
if(init_flag==0) Init();
#if defined(__M451__)	
	/* Enable IP clock */       
	CLK_EnableModuleClock(module);    	
   	
  /* Select IP clock source and clock divider */
   CLK_SetModuleClock(module,clksel,0);

	/* Configure as a master, clock idle low, falling clock edge Tx, rising edge Rx and 8-bit transaction */
	/* Set IP clock divider. SPI clock rate = 4MHz */  	
	SPI_Open(spi, SPI_MASTER, SPI_MODE_0, 8, 4000000);	
	//SPI_EnableFIFO(spi,12,12);	
	setBitOrder(SS, MSBFIRST);
	
	SPI_ClearRxFIFO(spi);
	SPI_TRIGGER(spi);
#elif defined(__NUC240__) | defined(__NUC131__)
	/* Enable IP clock */       
	CLK_EnableModuleClock(module);    	
   	
    /* Select IP clock source and clock divider */
    CLK_SetModuleClock(module,clksel,0);

	/* Configure as a master, clock idle low, falling clock edge Tx, rising edge Rx and 8-bit transaction */
	/* Set IP clock divider. SPI clock rate = 4MHz */  	
	SPI_Open(spi, SPI_MASTER, SPI_MODE_0, 8, 4000000);	
	SPI_EnableFIFO(spi,12,12);	
	setBitOrder(SS, MSBFIRST);
#elif defined(__NANO100__)
	/* Enable IP clock */       
	CLK_EnableModuleClock(module);    	
   	
    /* Select IP clock source and clock divider */
    CLK_SetModuleClock(module,clksel,0);

	/* Configure as a master, clock idle low, falling clock edge Tx, rising edge Rx and 8-bit transaction */
	/* Set IP clock divider. SPI clock rate = 4MHz */  	
	SPI_Open(spi, SPI_MASTER, SPI_MODE_0, 8, 4000000);
        setBitOrder(SS, MSBFIRST);
        SPI_EnableFIFO(spi,12,12); 
#endif
}

void SPIClass::end(uint8_t _pin) {
		SPI_Close(spi);
}

void SPIClass::end() {
	SPI_Close(spi);
}

void SPIClass::usingInterrupt(uint8_t interruptNumber)
{
}

void SPIClass::beginTransaction(uint8_t pin, SPISettings settings)
{
        if(init_flag==0) init();
	/* Configure as a master, clock idle low, falling clock edge Tx, rising edge Rx and 8-bit transaction */
	/* Set IP clock divider. SPI clock rate = 4MHz */  	
	SPI_Open(spi, SPI_MASTER, settings.datmode, 8, settings.clock);	
	//SPI_EnableFIFO(spi,12,12);	
	setBitOrder(SS, settings.border);

#if defined(__M451__) | defined(__NANO100__)	
	SPI_ClearRxFIFO(spi);
	SPI_TRIGGER(spi);
#endif
}

void SPIClass::endTransaction(void)
{
	
}

void SPIClass::setBitOrder(uint8_t _pin, BitOrder _bitOrder) {	
	if(_bitOrder==LSBFIRST)
		SPI_SET_LSB_FIRST(spi);
	else
		SPI_SET_MSB_FIRST(spi);
}

void SPIClass::setDataMode(uint8_t _pin, uint8_t _mode) {	
#if defined(__M451__)
	spi->CTL = (spi->CTL & ~SPI_MODE_Msk) | _mode;
#elif defined(__NUC240__) | defined(__NUC131__)
    spi->CNTRL = (spi->CNTRL & ~SPI_MODE_Msk) | _mode;
#elif defined(__NANO100__)
    spi->CTL = (spi->CTL & ~SPI_MODE_Msk) | _mode;
#endif
}

void SPIClass::setClockDivider(uint8_t _pin, uint8_t _divider) {	
	spi->DIVIDER = (spi->DIVIDER & ~0xffff) | _divider;
}

byte SPIClass::transfer(byte _pin, uint8_t _data, SPITransferMode _mode) {	
	uint32_t rdata;
	SPI_WRITE_TX(spi, _data);
	SPI_TRIGGER(spi);
	while(SPI_IS_BUSY(spi));
	return (SPI_READ_RX(spi) & 0xff);
}			

uint16_t SPIClass::transfer16(byte _pin, uint16_t _data, SPITransferMode _mode) {
	uint32_t rdata;
	SPI_WRITE_TX(spi, _data&0xff);
	SPI_TRIGGER(spi);
	while(SPI_IS_BUSY(spi));
	rdata=(SPI_READ_RX(spi) & 0xff);
	SPI_WRITE_TX(spi, _data>>8);
	SPI_TRIGGER(spi);
	while(SPI_IS_BUSY(spi));
	rdata=rdata | ((SPI_READ_RX(spi) & 0xff)<<8);

	return rdata;
}

void SPIClass::transfer(byte _pin, void *_buf, size_t _count, SPITransferMode _mode) {
	uint32_t i;
	uint8_t *buf;
	buf=(uint8_t *)_buf;
	for(i=0;i<_count;i++)
	{	
		SPI_WRITE_TX(spi, buf[i]);
		SPI_TRIGGER(spi);
		while(SPI_IS_BUSY(spi));
	}
}

void SPIClass::attachInterrupt(void) {
	// Should be enableInterrupt()
}

void SPIClass::detachInterrupt(void) {
	// Should be disableInterrupt()
}

#if SPI_MAX_COUNT > 0

#ifndef SPI_ID0
#define SPI_ID0 0
#endif

SPIClass SPI(0,0);
#endif
