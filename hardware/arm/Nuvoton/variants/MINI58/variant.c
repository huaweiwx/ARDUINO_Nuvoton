
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
  CLK_EnableModuleClock(PWMCH01_MODULE);
  CLK_EnableModuleClock(PWMCH23_MODULE);
  CLK_EnableModuleClock(PWMCH45_MODULE);

  CLK_SetModuleClock(PWMCH01_MODULE,CLK_CLKSEL1_PWMCH01SEL_HCLK,0);
  CLK_SetModuleClock(PWMCH23_MODULE,CLK_CLKSEL1_PWMCH23SEL_HCLK,0);
  CLK_SetModuleClock(PWMCH45_MODULE,CLK_CLKSEL2_PWMCH45SEL_HCLK,0);
}

/* Init System Clock                                                                                       */
void SystemClock_Config(void)
{
    /* Enable Internal RC 22.1184MHz clock */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for Internal RC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV_HCLK(1));

#ifdef HXT12
    /* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCTL_XTLEN_HXT);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_STATUS_XTLSTB_Msk);

    /* Set core clock as PLL_CLOCK from PLL */
#if F_CPU == 100000000L	
    CLK_SetCoreClock(FREQ_100MHZ);
#else
    CLK_SetCoreClock(FREQ_50MHZ);
#endif
#endif
    /* Enable UART module clock */
//    CLK_EnableModuleClock(UART0_MODULE);

    /* Select UART module clock source */
//  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_CLKDIV_UART(1));

}
