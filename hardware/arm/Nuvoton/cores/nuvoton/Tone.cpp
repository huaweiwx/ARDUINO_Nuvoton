/* Tone.cpp

  A Tone Generator Library

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


#include "Arduino.h"

HardwareTimer *ToneTimer=Timer[1];

typedef struct {
  HardwareTimer* timer;
  uint8_t pin;  
  uint8_t enabled;  
  volatile uint8_t waitISR;
} tone_t;

tone_t Tone ={0,0,0,0};

void tone_ISR(uint8_t num)
{	
    unused(num);

	Tone.waitISR=0;	
#if defined(__NANO100__) | defined(__NANO1X2__)
	Tone.timer->clearIntFlag();
#else
	Tone.timer->close();
#ifdef M480
	EPWM_DisableOutput(PWM_Desc[Tone.pin].P,(1<<PWM_Desc[Tone.pin].ch));
#else
	PWM_DisableOutput(PWM_Desc[Tone.pin].P,(1<<PWM_Desc[Tone.pin].ch));
#endif
#endif 
}

static uint8_t pinEnabled[PWM_MAX_COUNT]={0};
// frequency (in hertz) and duration (in milliseconds).
void tone(uint8_t ucPin, unsigned int frequency, unsigned long duration)
{	
	tone_t *tone;
#ifdef USE_BoardToPin
	if(ucPin > BoardToPin_MAX_COUNT) return;
	if(BoardToPinInfo[ucPin].type!=PWM_TYPE) return;
	ucPin=BoardToPinInfo[ucPin].num;
#else
	if(ucPin>PWM_MAX_COUNT || PWM_Desc[ucPin].P==NULL) return;
#endif
	
	
	if (!pinEnabled[ucPin] && frequency!=0){
		//Set Mutifunction pins
		PWM_Config(PWM_Desc[ucPin]);		
    
		
		//Enable PWM output
#ifdef M480
		//Config PWMs
		EPWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,frequency,50);
		EPWM_EnableOutput(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
		//Start PWM
		EPWM_Start(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
#else		
		//Config PWMs
		PWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,frequency,50);
		PWM_EnableOutput(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
		//Start PWM
		PWM_Start(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
#endif
		
		pinEnabled[ucPin] = 1;
	}
	
		tone=&Tone;		
		tone->pin=ucPin;
		tone->timer=ToneTimer;		
		tone->enabled=1;	
		if(duration==0){
			if(frequency!=0)
			{
#ifdef M480
				EPWM_EnableOutput(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
				EPWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,frequency,50);
				//PWM_Start(PWM_Desc[tone->pin].P,(1<<PWM_Desc[tone->pin].ch));	
#else
				PWM_EnableOutput(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
				PWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,frequency,50);
				//PWM_Start(PWM_Desc[tone->pin].P,(1<<PWM_Desc[tone->pin].ch));	
#endif
				}
		}else{  			
			while(tone->waitISR);			
			//Config PWMs	
			if(frequency!=0)
			{
#ifdef M480
				EPWM_EnableOutput(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
				EPWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,frequency,50);	
#else
				PWM_EnableOutput(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
				PWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,frequency,50);	
#endif	
			}
			//PWM_Start(PWM_Desc[tone->pin].P,(1<<PWM_Desc[tone->pin].ch));	
			tone->waitISR=1;
			
			//Config Timer			
			tone->timer->open(ONESHOT,tone->timer->getModuleClock());
			tone->timer->setPrescaleFactor(0);
			tone->timer->setCompare(tone->timer->getModuleClock()/1000*duration);  /* milliseconds */ 
			tone->timer->attachInterrupt(tone_ISR);
			tone->timer->start();			
		}		
}

void noTone(uint8_t ucPin)
{
  tone_t *tone;
#ifdef USE_BoardToPin
	if(ucPin > BoardToPin_MAX_COUNT) return;
	if(BoardToPinInfo[ucPin].type!=PWM_TYPE) return;
	ucPin=BoardToPinInfo[ucPin].num;
#else
	if(ucPin>PWM_MAX_COUNT || PWM_Desc[ucPin].P==NULL) return;
#endif	
	//close tone		
	tone=&Tone;
	if(tone->pin==ucPin)
	{	 									
		while(tone->waitISR);		
#ifdef M480
		EPWM_DisableOutput(PWM_Desc[tone->pin].P,(1<<PWM_Desc[tone->pin].ch));
		//EPWM_Stop(PWM_Desc[tone->pin].P,(1<<PWM_Desc[tone->pin].ch));		
#else
		PWM_DisableOutput(PWM_Desc[tone->pin].P,(1<<PWM_Desc[tone->pin].ch));
		//PWM_Stop(PWM_Desc[tone->pin].P,(1<<PWM_Desc[tone->pin].ch));		
#endif	
		tone->pin = 0;
		tone->enabled=0;
		tone->timer->close();		
	}
}
