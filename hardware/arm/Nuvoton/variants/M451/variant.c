
#include "Arduino.h"

extern void CLK_EnableModuleClock(uint32_t);

void Enable_All_IPs(void)
{
   //Enable ADC module
  CLK_EnableModuleClock(EADC_MODULE);  
  /* EADC clock source is 72MHz, set divider to 8, ADC clock is 72/8 MHz */
  CLK_SetModuleClock(EADC_MODULE, 0, CLK_CLKDIV0_EADC(8));
      
  //Enable PWM0 ~PWM1 module
  CLK_EnableModuleClock(PWM0_MODULE);
  CLK_EnableModuleClock(PWM1_MODULE);  
																 
  CLK_SetModuleClock(PWM0_MODULE,CLK_CLKSEL2_PWM0SEL_PCLK0,0);
  CLK_SetModuleClock(PWM1_MODULE,CLK_CLKSEL2_PWM1SEL_PCLK1,0);    
}


/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
void SystemClock_Config(void)
{
		/* Enable HIRC clock (Internal RC 22.1184MHz) */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Wait for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);
    
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
  
    /* STCLK to HXT */    
    //CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLKSEL_HCLK_DIV2);    
}
