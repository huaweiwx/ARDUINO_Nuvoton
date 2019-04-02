
#include "Arduino.h"
extern void CLK_EnableModuleClock(uint32_t);

void Enable_All_IPs(void)
{

  //Enable ADC module
  CLK_EnableModuleClock(ADC_MODULE);
  
  //Enable PWM0 ~PWM7 module
  CLK_EnableModuleClock(PWM0_MODULE);
  CLK_EnableModuleClock(PWM1_MODULE);

  CLK_SetModuleClock(PWM0_MODULE,CLK_CLKSEL3_PWM0_S_PLL,0);
  CLK_SetModuleClock(PWM1_MODULE,CLK_CLKSEL3_PWM1_S_PLL,0);

}

/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
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

#endif
    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL, CLK_CLKDIV_HCLK(1));
	
    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(F_CPU);
	
    /* Enable UART module clock */
//    CLK_EnableModuleClock(UART0_MODULE);

    /* Select UART module clock source */
//  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_CLKDIV_UART(1));

}
