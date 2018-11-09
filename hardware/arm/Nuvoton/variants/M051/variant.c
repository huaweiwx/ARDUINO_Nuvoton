
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
  CLK_EnableModuleClock(PWM67_MODULE);

  CLK_SetModuleClock(PWM01_MODULE,CLK_CLKSEL1_PWM01_S_HXT,0);
  CLK_SetModuleClock(PWM23_MODULE,CLK_CLKSEL1_PWM23_S_HXT,0);
  CLK_SetModuleClock(PWM45_MODULE,CLK_CLKSEL2_PWM45_S_HXT,0);
  CLK_SetModuleClock(PWM67_MODULE,CLK_CLKSEL2_PWM67_S_HXT,0);

}

/* Init System Clock                                                                                       */
void SystemClock_Config(void)
{
    /* Enable Internal RC 22.1184MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_OSC22M_EN_Msk);

    /* Waiting for Internal RC clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_OSC22M_STB_Msk);


#ifdef HXT12
    /* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_XTL12M_EN_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Set core clock as PLL_CLOCK from PLL */
#if F_CPU == 48000000L	
    CLK_SetCoreClock(48000000);
#else
    CLK_SetCoreClock(24000000);
#endif

#else
    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HIRC, CLK_CLKDIV_HCLK(1));
#endif
    /* Enable UART module clock */
//    CLK_EnableModuleClock(UART0_MODULE);

    /* Select UART module clock source */
//  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_CLKDIV_UART(1));
}
