/*
  Copyright (c) 2018 huaweiwx@sina.com 2018.11.1

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include "Arduino.h"

static void __empty() {
	// Empty
}
void systicCallback(void) __attribute__ ((weak, alias("__empty")));

/** Tick Counter united by ms */
static volatile uint32_t _dwTickCount=0 ;

/**
 * \brief SysTick_Handler.
 */
 
void SysTick_Handler(void)
{
	/* Increment counter necessary in delay(). */
	_dwTickCount++;
	systicCallback();  /*for freeRtos*/  
}

/**
 *  \brief Get current Tick Count, in ms.
 */
uint32_t GetTickCount( void )
{
    return _dwTickCount ;
}


extern void SystemClock_Config(void);
extern void Enable_All_IPs(void);

void init(void)
{
    init_flag = 1;

    /* Unlock protected registers */
    SYS_UnlockReg();
	
/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
    SystemClock_Config(); 

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set Systick to 1ms interval */
  	if (SysTick_Config(F_CPU/1000))
  	{
    // Capture error
       _Error_Handler(__FILENAME__, __LINE__); //    	while (true);
  	}    
  	
    /* To update the variable SystemCoreClock */
    SystemCoreClockUpdate();
      
    /* Enable All of IP */
    Enable_All_IPs();
    
    /* Lock protected registers */
    SYS_LockReg();  
}

//---------------------------------------------------------------------------
