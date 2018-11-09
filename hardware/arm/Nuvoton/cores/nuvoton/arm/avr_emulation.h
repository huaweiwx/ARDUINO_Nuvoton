/*
  EMF32 ARDUINO  avr_emulation.h
  
  Copyright (c) 2018 huaweiwx@sina.com 2018.9.1

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef __AVREMULATION_H__
#define __AVREMULATION_H__

#ifdef __cplusplus

class DDRemulation
{
  public:
    DDRemulation(const GPIO_T* port, uint16_t mask = 0xffff): port(port),mask(mask){}
	const GPIO_T* port;
	uint16_t mask;

	inline void setMask(uint16_t val){
		mask = val;
	}

	inline uint16_t getMask(void){
		return mask;
	}

	inline void lock(uint16_t pinMask){
		this->mask &= ~pinMask;
	}

	inline void unLock(uint16_t pinMask){
		this->mask |= pinMask;
	}

    void mode(unsigned int pinMask, const uint32_t mode, unsigned int out = 0) {
        GPIO_SetMode((GPIO_T*)port, pinMask, mode);
		if(out) ((GPIO_T*)port)->DOUT |= pinMask;
    }

    inline operator int () __attribute__((always_inline)) {
		return this->save_ddr;
    }

    DDRemulation& operator = (uint16_t val){
      this->save_ddr = val & mask;
	  for(uint8_t i = 0;i<16;i++){
		  if(bitRead(mask,i)){
			GPIO_SetMode((GPIO_T*)port, (1<<i), bitRead(val,i)?OUTPUT:INPUT);
 	      }
	  }
      return *this;
    }

    inline DDRemulation& operator |= (uint16_t val) __attribute__((always_inline)) {
	  for(uint8_t i = 0;i<16;i++){
		  if((bitRead(mask,i))&(~save_ddr)){
			 if(bitRead(val,i)){
			    GPIO_SetMode((GPIO_T*)port,(1<<i),OUTPUT);
				bitSet(save_ddr,i);
 	         }			 
		  }
	  }
      return *this;
    }
	
    inline DDRemulation& operator &= (uint16_t val) __attribute__((always_inline)) {
	  for(uint8_t i = 0;i<16;i++){
		  if(bitRead((save_ddr & mask),i)){
			 if(!bitRead(val,i)){
			    GPIO_SetMode((GPIO_T*)port,(1<<i),INPUT);
				bitClear(save_ddr,i);
 	         }
		  }
	  }
      return *this;
    }
  private:
    uint16_t save_ddr = 0;	
};

#if  defined(PA)
extern	DDRemulation	DDRA;
#endif
#if  defined(PB)
extern	DDRemulation	DDRB;
#endif
#if  defined(PC)
extern  DDRemulation	DDRC;
#endif
#if   defined(PD)
extern  DDRemulation	DDRD;
#endif
#if   defined(PE)
extern  DDRemulation	DDRE;
#endif
#if   defined(PF)
extern  DDRemulation	DDRF;
#endif
#if   defined(PG)
extern  DDRemulation	DDRG;
#endif
#if   defined(PH)
extern  DDRemulation	DDRH;
#endif
#if   defined(PJ)
extern  DDRemulation	DDRJ;
#endif
#if   defined(PK)
extern  DDRemulation	DDRK;
#endif

#endif //__cplusplus

#if  defined(PA)
#define PORTA   PA->DOUT
#define  PINA   PA->PIN
#endif
#if  defined(PB)
#define PORTB   PB->DOUT
#define  PINB   PB->PIN
#endif
#if  defined(PC)
#define PORTC   PC->DOUT
#define  PINC   PC->PIN
#endif
#if  defined(PD)
#define PORTD   PD->DOUT
#define  PIND   PD->PIN
#endif
#if  defined(PE)
#define PORTE  PE->DOUT
#define  PINE  PE->PIN
#endif
#if  defined(PF)
#define PORTF  PF->DOUT
#define  PINF  PF->PIN
#endif
#if  defined(PG)
#define PORTG  PG->DOUT
#define  PING  PG->PIN
#endif
#if  defined(PH)
#define PORTH  PH->DOUT
#define  PINH  PH->PIN
#endif
#if  defined(PJ)
#define PORTJ  PJ->DOUT
#define  PINJ  PJ->PIN
#endif
#if  defined(PK)
#define PORTK  PK->DOUT
#define  PINK  PK->PIN
#endif

#include "avr_pin_legacy.h"

#endif //__AVREMULATION_H__
