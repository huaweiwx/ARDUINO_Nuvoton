
#include "Arduino.h"
extern void CLK_EnableModuleClock(uint32_t);

void Enable_All_IPs(void)
{
#if USE_ICE >0
  SYS->P4_MFP = SYS_MFP_P47_ICE_DAT | SYS_MFP_P46_ICE_CLK;
#endif

  //Enable ADC module
  CLK_EnableModuleClock(ADC_MODULE);
  
  //Enable PWM0 ~PWM7 module
  CLK_EnableModuleClock(PWM01_MODULE);
  CLK_EnableModuleClock(PWM23_MODULE);
  CLK_EnableModuleClock(PWM45_MODULE);

  CLK_SetModuleClock(PWM01_MODULE,CLK_CLKSEL1_PWM01_S_HCLK,0);
  CLK_SetModuleClock(PWM23_MODULE,CLK_CLKSEL1_PWM23_S_HCLK,0);
  CLK_SetModuleClock(PWM23_MODULE,CLK_CLKSEL2_PWM45_S_HCLK,0);

}

/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
void SystemClock_Config(void)
{
    /* Enable Internal RC 22.1184MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_HIRC_EN_Msk);

    /* Waiting for Internal RC clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_HIRC_STB_Msk);


#ifdef HXT12
    /* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_CLKSTATUS_XTL_STB_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_XTL_STB_Msk);

    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_XTAL, CLK_CLKDIV_HCLK(1));

#else
    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HIRC, CLK_CLKDIV_HCLK(1));
#endif
}
