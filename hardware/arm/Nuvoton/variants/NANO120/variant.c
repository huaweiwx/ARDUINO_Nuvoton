
#include "Arduino.h"

extern void CLK_EnableModuleClock(uint32_t);

void Enable_All_IPs(void)
{
  CLK_EnableModuleClock(ADC_MODULE);    
  
  //Enable PWM0 ~PWM7 module
  CLK_EnableModuleClock(PWM0_CH01_MODULE);
  CLK_EnableModuleClock(PWM0_CH23_MODULE);
  CLK_EnableModuleClock(PWM1_CH01_MODULE);
  CLK_EnableModuleClock(PWM1_CH23_MODULE);

  CLK_SetModuleClock(PWM0_CH01_MODULE,CLK_CLKSEL1_PWM0_CH01_S_HXT,0);
  CLK_SetModuleClock(PWM0_CH23_MODULE,CLK_CLKSEL1_PWM0_CH23_S_HXT,0);
  CLK_SetModuleClock(PWM1_CH01_MODULE,CLK_CLKSEL2_PWM1_CH01_S_HXT,0);
  CLK_SetModuleClock(PWM1_CH23_MODULE,CLK_CLKSEL2_PWM1_CH23_S_HXT,0);
}

/* Init System Clock                                                                                       */
void SystemClock_Config(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();
	
    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRC_EN_Msk |CLK_PWRCTL_HXT_EN_Msk);
    
    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_HIRC_STB_Msk | CLK_CLKSTATUS_HXT_STB_Msk);
	
    /* Disable PLL first to avoid unstable when setting PLL */
    CLK_DisablePLL();
	
#if defined(HIRC)
    /* Set PLL source HIRC frequency 84MHz*/
    CLK_EnablePLL(CLK_PLLCTL_PLL_SRC_HIRC, 84000000);
#else  // defined(HXT12)
    /* Set PLL source external HXT frequency 84MHz  */
    CLK_EnablePLL(CLK_PLLCTL_PLL_SRC_HXT, 84000000);
#endif

    /* Waiting for PLL ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);
 
#if F_CPU == 42000000
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL, CLK_HCLK_CLK_DIVIDER(2));
#elif F_CPU == 28000000
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL, CLK_HCLK_CLK_DIVIDER(3));
#else // F_CPU == 21000000
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL, CLK_HCLK_CLK_DIVIDER(4));
#endif

    SystemCoreClockUpdate();
    /* Lock protected registers */
    SYS_LockReg();
}
