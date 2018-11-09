/*
  Copyright (c) 2013 Arduino LLC. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
#include "Arduino.h"
#include <nvtServo.h>
volatile uint32_t Servo_MAX=180;
volatile uint32_t Servo_MIN=0;
volatile uint32_t Pwm2Servo_max=10; 
volatile uint32_t Pwm2Servo_min=3;
uint8_t Servo_Pin=0;
uint8_t Servo_Val=0;

// Micro servo must learn to adjust with PWM
uint32_t mul_max=9;  //For GS-9018
uint32_t mul_min=39; //For GS-9018

Servo::Servo()
{

}

uint8_t Servo::attach(uint8_t pin)
{
  return this->attach(pin, Servo_MIN, Servo_MAX);
}
static uint8_t pinEnabled[PWM_MAX_COUNT];
static uint32_t fixValue[PWM_MAX_COUNT];
uint8_t Servo::attach(uint8_t ucPin, int min, int max)
{      
	uint32_t CNR;
	uint32_t ulValue=0;
	#ifdef USE_BoardToPin
	if(ucPin > BoardToPin_MAX_COUNT) return 0;
	if(BoardToPinInfo[ucPin].type!=PWM_TYPE) return 0;
	ucPin=BoardToPinInfo[ucPin].num;
	#else
	if(ucPin>PWM_MAX_COUNT || PWM_Desc[ucPin].P==NULL) return 0;
	#endif	
#if defined(__M451__)
	if(ulValue==100)
	{  
		int32_t pin=PWM_Desc[ucPin].pintype.num;
		GPIO_Config(GPIO_Desc[pin]);
		GPIO_SetMode(GPIO_Desc[pin].P, GPIO_Desc[pin].bit, GPIO_MODE_OUTPUT);
		(GPIO_Desc[pin].P)->DOUT |= GPIO_Desc[pin].bit;
		pinEnabled[ucPin]= 0;
		fixValue[ucPin]=ulValue;
		//return 0;
	}
#elif defined(__NUC240__)
	if(ulValue==0)
	{  
		int32_t pin=PWM_Desc[ucPin].pintype.num;
		GPIO_Config(GPIO_Desc[pin]);
		GPIO_SetMode(GPIO_Desc[pin].P, GPIO_Desc[pin].bit, GPIO_PMD_OUTPUT);
		(GPIO_Desc[pin].P)->DOUT &= ~GPIO_Desc[pin].bit;
		pinEnabled[ucPin]= 0;
		fixValue[ucPin]=ulValue;
		//return 0;
	}
#elif defined(__NANO100__) | defined(__NANO1X2__)
	if(ulValue==0)
	{  
		int32_t pin=PWM_Desc[ucPin].pintype.num;
		GPIO_Config(GPIO_Desc[pin]);
		GPIO_SetMode(GPIO_Desc[pin].P, GPIO_Desc[pin].bit, GPIO_PMD_OUTPUT);
		(GPIO_Desc[pin].P)->DOUT &= ~GPIO_Desc[pin].bit;
		pinEnabled[ucPin]= 0;
		fixValue[ucPin]=ulValue;
		//return 0;
	}
#elif defined(__NUC131__)
	if(ulValue==0)
	{  
		int32_t pin=PWM_Desc[ucPin].pintype.num;
		GPIO_Config(GPIO_Desc[pin]);
		GPIO_SetMode(GPIO_Desc[pin].P, GPIO_Desc[pin].bit, GPIO_PMD_OUTPUT);
		(GPIO_Desc[pin].P)->DOUT &= ~GPIO_Desc[pin].bit;
		pinEnabled[ucPin]= 0;
		fixValue[ucPin]=ulValue;
		//return 0;
	}
#endif	

	if (!pinEnabled[ucPin]){
		//Set Mutifunction pins
		PWM_Config(PWM_Desc[ucPin]);		
    
		//Config PWMs
		PWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,50,0);
		
		//Enable PWM output
		PWM_EnableOutput(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
		
		//Start PWM
		PWM_Start(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
		
		pinEnabled[ucPin] = 1;
	}
	
	//Config PWMs		
	if(fixValue[ucPin]!=ulValue)
	{
		PWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,50,ulValue);
		fixValue[ucPin]=ulValue;
	}
	
	Servo_MAX=max;
  Servo_MIN=min;
  Servo_Pin=ucPin;
  
#if defined(__NUC131__)
	CNR=(PWM_Desc[ucPin].P)->PERIOD[(((PWM_Desc[ucPin].ch)>>1<<1))] - 1;
	Pwm2Servo_min= (CNR/mul_min);
	Pwm2Servo_max= (CNR/mul_max);  //1ms
#else

#endif
}

void Servo::detach()
{

}

void Servo::write(int value)
{
    if (value < Servo_MIN)
      value = Servo_MIN;
    else if (value > Servo_MAX)
      value = Servo_MAX;

    Servo_Val=value;
    value = map(value, Servo_MIN, Servo_MAX, Pwm2Servo_min, Pwm2Servo_max);
#if defined(__NUC131__)
	  PWM_SET_CMR(PWM_Desc[Servo_Pin].P,PWM_Desc[Servo_Pin].ch,value);
		(PWM_Desc[Servo_Pin].P)->WGCTL0 &= ~((PWM_WGCTL0_PRDPCTL0_Msk | PWM_WGCTL0_ZPCTL0_Msk) << (PWM_Desc[Servo_Pin].ch * 2));
		(PWM_Desc[Servo_Pin].P)->WGCTL0 |= (PWM_OUTPUT_LOW << (PWM_Desc[Servo_Pin].ch * 2 + PWM_WGCTL0_PRDPCTL0_Pos));
		(PWM_Desc[Servo_Pin].P)->WGCTL1 &= ~((PWM_WGCTL1_CMPDCTL0_Msk | PWM_WGCTL1_CMPUCTL0_Msk) << (PWM_Desc[Servo_Pin].ch * 2));
		(PWM_Desc[Servo_Pin].P)->WGCTL1 |= (PWM_OUTPUT_HIGH << (PWM_Desc[Servo_Pin].ch * 2 + PWM_WGCTL1_CMPDCTL0_Pos));
#else
    PWM_ConfigOutputChannel(PWM_Desc[Servo_Pin].P,PWM_Desc[Servo_Pin].ch,50,value);	 
#endif
}

int Servo::read() // return the value as degrees
{
  return Servo_Val;
}
