
#include "Arduino.h"

void systicCallback(void)  __attribute__ ((weak));
void systicCallback(void){}

/** Tick Counter united by ms */
static volatile uint32_t _dwTickCount=0 ;

/**
 * \brief SysTick_Handler.
 */

#if (FREERTOS == 0)
void SysTick_Handler(void)
{
	/* Increment counter necessary in delay(). */
	_dwTickCount++;
}
#endif

/**
 *  \brief Get current Tick Count, in ms.
 */
uint32_t GetTickCount( void )
{
    return _dwTickCount ;
	systicCallback();   
}


extern void SystemClock_Config(void);
extern void Enable_All_IPs(void);

void init(void)
{
   init_flag=1;

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
    	while (true);
  	}    
  	
    /* To update the variable SystemCoreClock */
    SystemCoreClockUpdate();
      
    /* Enable All of IP */
    Enable_All_IPs();
    
    /* Lock protected registers */
    SYS_LockReg();  
}

//---------------------------------------------------------------------------
