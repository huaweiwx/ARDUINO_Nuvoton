
#include "Arduino.h"

extern void CLK_EnableModuleClock(uint32_t);

//for m3/m4/m7 only
int UTIL_checkUserCode(uint32_t usrAddr) {
    uint32_t sp = *(volatile uint32_t *) usrAddr;
    extern char __StackTop; /* Defined in the linker script */
    return (sp == (uint32_t)&__StackTop)?1:0;
}

/*bootloader use*/
void UTIL_jumpToUser(uint32_t usrAddr) {
  // Dedicated function with no call to any function (appart the last call)
  // This way, there is no manipulation of the stack here, ensuring that GGC
  // didn't insert any pop from the SP after having set the MSP.
  
  typedef void (*funcPtr)(void);

  uint32_t jumpAddr = *(volatile uint32_t *)(usrAddr + 0x04); /* reset ptr in vector table */

  funcPtr usrMain = (funcPtr) jumpAddr;

  asm volatile("msr msp, %0"::"g"
               (*(volatile uint32_t *)usrAddr));
  *(uint32_t *) 0xE000ED08 = usrAddr;   /* 设置中断向量表地址 */
  usrMain();                            /* go! */
}


void Enable_All_IPs(void)
{
   //Enable ADC module
  CLK_EnableModuleClock(EADC_MODULE);  
  /* EADC clock source is 72MHz, set divider to 8, ADC clock is 72/8 MHz */
  CLK_SetModuleClock(EADC_MODULE, 0, CLK_CLKDIV0_EADC(8));
      
  //Enable PWM0 ~PWM1 module
  CLK_EnableModuleClock(EPWM0_MODULE);
  CLK_EnableModuleClock(EPWM1_MODULE);
  
  CLK_EnableModuleClock(BPWM0_MODULE);
  CLK_EnableModuleClock(BPWM1_MODULE);  
																 
  CLK_SetModuleClock(EPWM0_MODULE,CLK_CLKSEL2_EPWM0SEL_PCLK0,0);
  CLK_SetModuleClock(EPWM1_MODULE,CLK_CLKSEL2_EPWM1SEL_PCLK1,0);
  
  CLK_SetModuleClock(BPWM0_MODULE,CLK_CLKSEL2_BPWM0SEL_PCLK0,0);
  CLK_SetModuleClock(BPWM1_MODULE,CLK_CLKSEL2_BPWM1SEL_PCLK1,0);    
}

//F_CPU
void SystemClock_Config(void)
{
#ifdef CHK_JUMP_TO_SRAM    /*for develop ram debug only*/
    UTIL_jumpToUser(0x20000000);
#endif
#if 1

/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
#ifdef HIRC
		/* Enable HIRC clock (Internal RC 22.1184MHz) */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Wait for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);
	
    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC,CLK_CLKDIV0_HCLK(1));
		/* Set PLL to power down mode and PLLSTB bit in CLKSTATUS register will be cleared by hardware.*/

	CLK->PLLCTL|= CLK_PLLCTL_PD_Msk;   
    
    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(F_CPU);
#else
    /* Enable External XTAL (4~24 MHz) */
    CLK_EnableXtalRC(CLK_PWRCTL_HXTEN_Msk);
    
    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady( CLK_STATUS_HXTSTB_Msk);
    /* Switch HCLK clock source to HXT */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HXT,CLK_CLKDIV0_HCLK(1));

		/* Set PLL to power down mode and PLLSTB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCTL|= CLK_PLLCTL_PD_Msk;   
    
    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(F_CPU);
#endif
  	
#else

    /* Set XT1_OUT(PF.2) and XT1_IN(PF.3) to input mode */
    PF->MODE &= ~(GPIO_MODE_MODE2_Msk | GPIO_MODE_MODE3_Msk);

    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Disable PLL first to avoid unstable when setting PLL */
//    CLK_DisablePLL();
    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(F_CPU);
	
    /* Set PCLK-related clock */
    CLK->PCLKDIV = (CLK_PCLKDIV_PCLK0DIV1 | CLK_PCLKDIV_PCLK1DIV1);
	
#endif	
}
