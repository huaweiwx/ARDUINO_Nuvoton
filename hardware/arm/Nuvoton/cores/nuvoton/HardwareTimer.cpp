/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Bryan Newbold.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

#include "HardwareTimer.h"
#if defined(__M451__)||defined(M480)
	#if(NR_TIMERS>0)
		HardwareTimer Timer1(0,TMR0_MODULE,CLK_CLKSEL1_TMR0SEL_HXT);
	#endif
	#if(NR_TIMERS>1)
		HardwareTimer Timer2(1,TMR1_MODULE,CLK_CLKSEL1_TMR1SEL_HXT);
	#endif
	#if(NR_TIMERS>2)
		HardwareTimer Timer3(2,TMR2_MODULE,CLK_CLKSEL1_TMR2SEL_HXT);
	#endif
	#if(NR_TIMERS>3)
		HardwareTimer Timer4(3,TMR3_MODULE,CLK_CLKSEL1_TMR3SEL_HXT);
	#endif
#elif defined(__NUC240__)
	#if(NR_TIMERS>0)
		HardwareTimer Timer1(0,TMR0_MODULE,CLK_CLKSEL1_TMR0_S_HXT);
	#endif
	#if(NR_TIMERS>1)
		HardwareTimer Timer2(1,TMR1_MODULE,CLK_CLKSEL1_TMR1_S_HXT);
	#endif
	#if(NR_TIMERS>2)
		HardwareTimer Timer3(2,TMR2_MODULE,CLK_CLKSEL1_TMR2_S_HXT);
	#endif
	#if(NR_TIMERS>3)
		HardwareTimer Timer4(3,TMR3_MODULE,CLK_CLKSEL1_TMR3_S_HXT);
	#endif
#elif defined(__NANO100__) | defined(__NANO1X2__) 
	#if(NR_TIMERS>0)
		HardwareTimer Timer1(0,TMR0_MODULE,CLK_CLKSEL1_TMR0_S_HXT);
	#endif
	#if(NR_TIMERS>1)
		HardwareTimer Timer2(1,TMR1_MODULE,CLK_CLKSEL1_TMR1_S_HXT);
	#endif
	#if(NR_TIMERS>2)
		HardwareTimer Timer3(2,TMR2_MODULE,CLK_CLKSEL2_TMR2_S_HXT);
	#endif
	#if(NR_TIMERS>3)
		HardwareTimer Timer4(3,TMR3_MODULE,CLK_CLKSEL2_TMR3_S_HXT);
	#endif
#elif defined(__NUC131__)
  #if(NR_TIMERS>0)
		HardwareTimer Timer1(0,TMR0_MODULE,CLK_CLKSEL1_TMR0_S_HXT);
  #endif
  #if(NR_TIMERS>1)
		HardwareTimer Timer2(1,TMR1_MODULE,CLK_CLKSEL1_TMR1_S_HXT);
  #endif
  #if(NR_TIMERS>2)
		HardwareTimer Timer3(2,TMR2_MODULE,CLK_CLKSEL1_TMR2_S_HXT);
  #endif
  #if(NR_TIMERS>3)
		HardwareTimer Timer4(3,TMR3_MODULE,CLK_CLKSEL1_TMR3_S_HXT);
  #endif
#elif defined(Mini58Series)
  #if(NR_TIMERS>0)
		HardwareTimer Timer1(0,TMR0_MODULE,CLK_CLKSEL1_TMR0SEL_HCLK);
  #endif
  #if(NR_TIMERS>1)
		HardwareTimer Timer2(1,TMR1_MODULE,CLK_CLKSEL1_TMR1SEL_HCLK);
  #endif
#elif  defined(Mini51Series)
  #if(NR_TIMERS>0)
		HardwareTimer Timer1(0,TMR0_MODULE,CLK_CLKSEL1_TMR0_S_HCLK);
  #endif
  #if(NR_TIMERS>1)
		HardwareTimer Timer2(1,TMR1_MODULE,CLK_CLKSEL1_TMR1_S_HCLK);
  #endif
#endif

HardwareTimer* Timer[NR_TIMERS]={
	#if(NR_TIMERS>0)
		&Timer1,
  #endif
  #if(NR_TIMERS>1)		
		&Timer2,
	#endif
	#if(NR_TIMERS>2)
		&Timer3,
	#endif
	#if(NR_TIMERS>3)
		&Timer4
	#endif
};

/** Timer channel numbers */
static voidFuncPtr TimerFuncPtr[NR_TIMERS];

#ifdef __cplusplus
extern "C"
{
#endif
	#if(NR_TIMERS>0)
	void TMR0_IRQHandler(void) { 
		if(TimerFuncPtr[0])	TimerFuncPtr[0](0); 
		TIMER_ClearIntFlag(TIMER0);
	}
	#endif
	
	#if(NR_TIMERS>1)
	void TMR1_IRQHandler(void) { 
		if(TimerFuncPtr[1])	TimerFuncPtr[1](1); 
		TIMER_ClearIntFlag(TIMER1);
	}
	#endif
	
	#if(NR_TIMERS>2)
	void TMR2_IRQHandler(void) { 
		if(TimerFuncPtr[2])	TimerFuncPtr[2](2); 
		TIMER_ClearIntFlag(TIMER2);
	}	
	#endif
	
	#if(NR_TIMERS>3)
	void TMR3_IRQHandler(void) { 
		if(TimerFuncPtr[3])	TimerFuncPtr[3](3); 
		TIMER_ClearIntFlag(TIMER3);
	}	
	#endif
#ifdef __cplusplus
}
#endif

HardwareTimer::HardwareTimer(uint8_t timerNum,uint32_t moduleIdx,uint32_t clksel) {
    if (timerNum >= NR_TIMERS) return;            
    TIMER_T * devs[] = {
#if(NR_TIMERS>0)
    	TIMER0,
#endif
#if(NR_TIMERS>1)
    	TIMER1,
#endif
#if(NR_TIMERS>2)
    	TIMER2,
#endif
#if(NR_TIMERS>3)
    	TIMER3,
#endif
    };
    dev = devs[timerNum];
    channel=timerNum;      
    TimerFuncPtr[0]=NULL; 
    CLK_EnableModuleClock(moduleIdx);
 		CLK_SetModuleClock(moduleIdx,clksel,0); 
}

void HardwareTimer::open(uint32_t mode,uint32_t freq) { 
    TIMER_Open(dev,mode,freq);		
}

void HardwareTimer::close() { 
    TIMER_Close(dev);		
}

void HardwareTimer::start() {
		TIMER_Start(dev);
}

void HardwareTimer::setPrescaleFactor(uint32_t factor) {    
    TIMER_SET_PRESCALE_VALUE(dev , factor);
}

void HardwareTimer::setCompare(uint32_t val) {
     TIMER_SET_CMP_VALUE(dev, val);
}

void HardwareTimer::attachInterrupt(void (*callback)(uint8_t)) {
   TimerFuncPtr[channel]=callback;
   TIMER_EnableInt(dev);
   NVIC_EnableIRQ((IRQn_Type)((int)TMR0_IRQn+channel));
}

void HardwareTimer::detachInterrupt() {
   TimerFuncPtr[channel]=NULL;
   TIMER_DisableInt(dev);
   NVIC_DisableIRQ((IRQn_Type)((int)TMR0_IRQn+channel));
}

uint32_t HardwareTimer::getModuleClock(){
	return TIMER_GetModuleClock(dev);
}

void HardwareTimer::clearIntFlag(){
	TIMER_ClearIntFlag(dev);
}

/* -- Deprecated predefined instances -------------------------------------- */
uint8_t TimerEnabled[NR_TIMERS]={0};

#if 0
HardwareTimer* GetHardwareTimer(void)
{
	uint8_t i;
	for(i=0;i<NR_TIMERS;i++)
	{
	  if(TimerEnabled[i]==0)
	  {
	  	TimerEnabled[i]=1;
	  	return Timer[i];
	  }
	}	
	return NULL;	  	
}

void ReleaseHardwareTimer(HardwareTimer* timer)
{
	uint8_t i;
	for(i=0;i<NR_TIMERS;i++)
	{
		if(&Timer[i]==&timer)
		{
			timer->close();
			TimerEnabled[i]=0;			
		}
	}
}
#endif
