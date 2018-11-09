
#include "Arduino.h"

extern void CLK_EnableModuleClock(uint32_t);

void Enable_All_IPs(void)
{
  //Enable ADC module
  CLK_EnableModuleClock(ADC_MODULE);
  
  //Enable PWM0 ~PWM7 module
  CLK_EnableModuleClock(PWM01_MODULE);
  CLK_EnableModuleClock(PWM23_MODULE);
  CLK_EnableModuleClock(PWM45_MODULE);
  CLK_EnableModuleClock(PWM67_MODULE);

  CLK_SetModuleClock(PWM01_MODULE,CLK_CLKSEL2_PWM45_S_HXT,0);
  CLK_SetModuleClock(PWM23_MODULE,CLK_CLKSEL2_PWM45_S_HXT,0);
  CLK_SetModuleClock(PWM45_MODULE,CLK_CLKSEL2_PWM45_S_HXT,0);
  CLK_SetModuleClock(PWM67_MODULE,CLK_CLKSEL2_PWM45_S_HXT,0);
}

/* Init System Clock                                                                                       */
void SystemClock_Config(void)
{
    /* Enable Internal RC 22.1184MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_OSC22M_EN_Msk);
    
    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_OSC22M_STB_Msk);

    /* Switch HCLK clock source to HIRC */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HIRC,CLK_CLKDIV_HCLK(1));

		/* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_XTL12M_EN_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(F_CPU);
  
    /* STCLK to HXT */    
    //CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLK_S_HXT);    

}
