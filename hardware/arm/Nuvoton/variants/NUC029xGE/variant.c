
#include "Arduino.h"
extern void CLK_EnableModuleClock(uint32_t);

void Enable_All_IPs(void)
{

  //Enable ADC module
  CLK_EnableModuleClock(ADC_MODULE);
  
  //Enable PWM0 ~PWM7 module
  CLK_EnableModuleClock(PWM0_MODULE);
  CLK_EnableModuleClock(PWM1_MODULE);

  CLK_SetModuleClock(PWM0_MODULE,CLK_CLKSEL1_PWM0SEL_PLL,0);
  CLK_SetModuleClock(PWM1_MODULE,CLK_CLKSEL1_PWM1SEL_PLL,0);

}

/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
void SystemClock_Config(void)
{
 /* Enable Internal RC 22.1184MHz clock */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for Internal RC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Select HCLK clock source as HIRC and and HCLK clock divider as 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));


#ifdef HXT12
    /* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCTL_HXTEN_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_STATUS_HXTSTB_Msk);
#endif

    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(F_CPU);

/* Enable UART module clock */
//    CLK_EnableModuleClock(UART0_MODULE);

    /* Select UART module clock source */
//  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_CLKDIV_UART(1));
}
