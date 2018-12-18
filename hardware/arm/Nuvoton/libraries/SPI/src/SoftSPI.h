/* Arduino DigitalIO Library
 * Copyright (C) 2013 by William Greiman
 *
 * This file is part of the Arduino DigitalIO Library
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Arduino DigitalIO Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
/**
 * @file 
 * @brief  Software SPI.
 *
 * @defgroup softSPI Software SPI
 * @details  Software SPI Template Class.
 * @{
 */

#ifndef __SOFTSPI_H__
#define __SOFTSPI_H__

//------------------------------------------------------------------------------
#define nop asm volatile ("nop\n\t")

#define SOFTSPI_DELAY(x) do{for(uint32_t i=0;i<x;i++) {asm volatile("nop");}}while(0)

//------------------------------------------------------------------------------
/** Pin Mode for MISO is input.*/
#define MISO_MODE  INPUT_PULLDOWN
/** Pullups disabled for MISO are disabled. */
#define MISO_LEVEL LOW
/** Pin Mode for MOSI is output.*/
#define MOSI_MODE  OUTPUT
/** Pin Mode for SCK is output. */
#define SCK_MODE   OUTPUT
//------------------------------------------------------------------------------
/**
 * @class SoftSPI
 * @brief Fast software SPI.
 */
class SoftSPI {
 public:
    SoftSPI(ARDUINOPIN_TypeDef MosiPin, ARDUINOPIN_TypeDef MisoPin, ARDUINOPIN_TypeDef SckPin)
          : MosiPin(MosiPin),MisoPin(MisoPin),SckPin(SckPin){}
		 
		  ARDUINOPIN_TypeDef MosiPin;
		  ARDUINOPIN_TypeDef MisoPin;
		  ARDUINOPIN_TypeDef SckPin;
		 
  //----------------------------------------------------------------------------
  /** Initialize SoftSPI pins. */
#if USE_ITERATOR == 0
  void begin(){Init();}	
  void end()  {deInit();}
#endif

  void Init()
  {
    pinMode(MisoPin,MISO_MODE);
//	digitalWrite(MisoPin, MISO_LEVEL);
    pinMode(MosiPin,MOSI_MODE);
	digitalWrite(MosiPin, !MODE_CPHA(settings.dataMode));
	
    pinMode(SckPin,SCK_MODE);
	digitalWrite(SckPin,MODE_CPOL(settings.dataMode));
  }
  
  void deInit(){}

  void setBitOrder(uint8_t bitOrder) {
	this->settings.bitOrder = bitOrder;
  }
  
  void setDataMode(uint8_t dataMode) {
	this->settings.dataMode = dataMode;	  
  }
  
  void setClock(uint32_t clock) {
	this->settings.clock  = F_CPU/7/clock;
  }

  void beginTransaction(SPISettings settings){
	this->settings.clock    = F_CPU/7/settings.clock;
	this->settings.bitOrder = settings.bitOrder;
	this->settings.dataMode = settings.dataMode;
  }
  void endTransaction() {}
  
  //----------------------------------------------------------------------------
  /** Soft SPI receive byte.
   * @return Data byte received.
   */
  inline __attribute__((always_inline))
  uint8_t receive() {
    uint8_t data = 0;
    receiveBit(7, &data);
    receiveBit(6, &data);
    receiveBit(5, &data);
    receiveBit(4, &data);
    receiveBit(3, &data);
    receiveBit(2, &data);
    receiveBit(1, &data);
    receiveBit(0, &data);
    return data;
  }
  //----------------------------------------------------------------------------
  /** Soft SPI send byte.
   * @param[in] data Data byte to send.
   */
  inline __attribute__((always_inline))
  void send(uint8_t data) {
    sendBit(7, data);
    sendBit(6, data);
    sendBit(5, data);
    sendBit(4, data);
    sendBit(3, data);
    sendBit(2, data);
    sendBit(1, data);
    sendBit(0, data);
  }
  //----------------------------------------------------------------------------
  /** Soft SPI transfer byte.
   * @param[in] txData Data byte to send.
   * @return Data byte received.
   */
  inline __attribute__((always_inline))
  uint8_t transfer(uint8_t txData) {
	uint8_t rxData = 0;
    transferBit(7, &rxData, txData);
    transferBit(6, &rxData, txData);
    transferBit(5, &rxData, txData);
    transferBit(4, &rxData, txData);
    transferBit(3, &rxData, txData);
    transferBit(2, &rxData, txData);
    transferBit(1, &rxData, txData);
    transferBit(0, &rxData, txData);
    return rxData;
  }

  void transfer(uint8_t *buf, size_t count){  /*reseive*/
	  uint8_t *ptr = buf;
	  for(size_t i = 0;i<count;i++,ptr++){
		  *ptr = receive();
      }		  
  }
  
   uint16_t transfer16(uint16_t data) {
	 if(settings.bitOrder == MSBFIRST) {
	   uint16_t ret =  transfer(data>>8);
	   return (ret<<8) + transfer(data &0xff);
	 }else{
	   uint16_t ret =  transfer(data &0xff);
	   return (ret + (transfer(data>>8) <<8));
	 }
   }
   
 private:
  //----------------------------------------------------------------------------
  inline __attribute__((always_inline))
  bool MODE_CPHA(uint8_t mode) {return ((mode & 1) != 0);}
  inline __attribute__((always_inline))
  bool MODE_CPOL(uint8_t mode) {return ((mode & 2) != 0);}
  
  inline __attribute__((always_inline))
  void receiveBit(uint8_t bit, uint8_t* data) {
    if (MODE_CPHA(settings.dataMode)) {
      setClockPin(!MODE_CPOL(settings.dataMode));
    }
    nop;
    nop;
    setClockPin((MODE_CPHA(settings.dataMode) ? MODE_CPOL(settings.dataMode) : !MODE_CPOL(settings.dataMode)));
    if (digitalRead(MisoPin)) *data |= 1 << bit;
    if (!MODE_CPHA(settings.dataMode)) {
      setClockPin(MODE_CPOL(settings.dataMode));
    }
  }
  //----------------------------------------------------------------------------
 
  inline __attribute__((always_inline))
  void sendBit(uint8_t bit, uint8_t data) {
    if (MODE_CPHA(settings.dataMode)) {
      setClockPin(!MODE_CPOL(settings.dataMode));
    }
    digitalWrite(MosiPin, data & (1 << bit));
    setClockPin(MODE_CPHA(settings.dataMode) ? MODE_CPOL(settings.dataMode) : !MODE_CPOL(settings.dataMode));
    nop;
    nop;
    if (!MODE_CPHA(settings.dataMode)) {
      setClockPin(MODE_CPOL(settings.dataMode));
    }
  }
  //----------------------------------------------------------------------------
  inline __attribute__((always_inline))
  void transferBit(uint8_t bit, uint8_t* rxData, uint8_t txData) {
    if (MODE_CPHA(settings.dataMode)) {
      setClockPin(!MODE_CPOL(settings.dataMode));
    }
    digitalWrite(MosiPin, txData & (1 << bit));
    setClockPin(MODE_CPHA(settings.dataMode) ? MODE_CPOL(settings.dataMode) : !MODE_CPOL(settings.dataMode));
    if (digitalRead(MisoPin)) *rxData |= 1 << bit;
    if (!MODE_CPHA(settings.dataMode)) {
      setClockPin(MODE_CPOL(settings.dataMode));
    }
  }
  //----------------------------------------------------------------------------
  inline __attribute__((always_inline))
  void setClockPin(bool state) {
      SOFTSPI_DELAY(settings.clock);
	  if(state) digitalWriteHigh(SckPin);
      else 	 digitalWriteLow(SckPin);  
//      SOFTSPI_DELAY(settings.clock);
   //Allow for clock stretching - dangerous currently
//      while (digitalRead(this->SckPin) != state);
  }
  private:
    SPISettings settings = {(F_CPU)/4000000/7, MSBFIRST, SPI_MODE0};
};

#endif  // SoftSPI_h
/** @} */
