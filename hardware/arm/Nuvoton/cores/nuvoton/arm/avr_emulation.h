/*
  NUVOTON ARDUINO  avr_emulation.h
  
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

#if  defined(PA)|| defined(P0)
	extern	DDRemulation	DDRA;
#endif
#if  defined(PB)|| defined(P1)
	extern	DDRemulation	DDRB;
#endif
#if  defined(PC)|| defined(P2)
	extern  DDRemulation	DDRC;
#endif
#if   defined(PD)|| defined(P3)
	extern  DDRemulation	DDRD;
#endif
#if   defined(PE)|| defined(P4)
	extern  DDRemulation	DDRE;
#endif
#if   defined(PF)|| defined(P5)
	extern  DDRemulation	DDRF;
#endif
#if   defined(PG)|| defined(P6)
	extern  DDRemulation	DDRG;
#endif
#if   defined(PH)|| defined(P7)
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
#elif defined(P0)
  #define PORTA   P0->DOUT
  #define  PINA   P0->PIN
#endif
#if  defined(PB)
  #define PORTB   PB->DOUT
  #define  PINB   PB->PIN
#elif defined(P1)
  #define PORTB   P1->DOUT
  #define  PINB   P1->PIN
#endif
#if  defined(PC)
  #define PORTC   PC->DOUT
  #define  PINC   PC->PIN
#elif defined(P2)
  #define PORTC   P2->DOUT
  #define  PINC   P2->PIN
#endif
#if  defined(PD)
  #define PORTD   PD->DOUT
  #define  PIND   PD->PIN
#elif defined(P3)
  #define PORTD   P3->DOUT
  #define  PIND   P3->PIN
#endif
#if  defined(PE)
  #define PORTE   PE->DOUT
  #define  PINE   PE->PIN
#elif defined(P4)
  #define PORTE   P4->DOUT
  #define  PINE   P4->PIN
#endif
#if  defined(PF)
  #define PORTF   PF->DOUT
  #define  PINF   PF->PIN
#elif defined(P5)
  #define PORTF   P5->DOUT
  #define  PINF   P5->PIN
#endif
#if  defined(PG)
  #define PORTG   PG->DOUT
  #define  PING   PG->PIN
#elif defined(P6)
  #define PORTG   P6->DOUT
  #define  PING   P6->PIN
#endif
#if  defined(PH)
  #define PORTH   PH->DOUT
  #define  PINH   PH->PIN
#elif defined(P7)
  #define PORTH   P7->DOUT
  #define  PINH   P7->PIN
#endif
#if  defined(PJ)
  #define PORTJ   PJ->DOUT
  #define  PINJ   PJ->PIN
#endif
#if  defined(PK)
  #define PORTK   PK->DOUT
  #define  PINK   PK->PIN
#endif

#include "avr_pin_legacy.h"

#endif //__AVREMULATION_H__
