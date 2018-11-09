
#include "Arduino.h"

extern void CLK_EnableModuleClock(uint32_t);

void Enable_All_IPs(void)
{

#if USE_ICE >0
//  SYS->GPF_MFPL = SYS_GPF_MFPL_PF1MFP_ICE_CLK | SYS_GPF_MFPL_PF0MFP_ICE_DAT;
#endif

#if defined(__M451__)
   //Enable ADC module
  CLK_EnableModuleClock(EADC_MODULE);  
  /* EADC clock source is 72MHz, set divider to 8, ADC clock is 72/8 MHz */
  CLK_SetModuleClock(EADC_MODULE, 0, CLK_CLKDIV0_EADC(8));
      
  //Enable PWM0 ~PWM1 module
  CLK_EnableModuleClock(PWM0_MODULE);
  CLK_EnableModuleClock(PWM1_MODULE);  
																 
  CLK_SetModuleClock(PWM0_MODULE,CLK_CLKSEL2_PWM0SEL_PCLK0,0);
  CLK_SetModuleClock(PWM1_MODULE,CLK_CLKSEL2_PWM1SEL_PCLK1,0);    
#elif defined(__NUC240__)
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
#elif defined(__NANO100__)
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
#elif defined(__NUC131__)
  //Enable ADC module
  CLK_EnableModuleClock(ADC_MODULE);
  
  //Enable PWM0 ~PWM7 module
  CLK_EnableModuleClock(PWM0_MODULE);
  CLK_EnableModuleClock(PWM1_MODULE);  

  CLK_SetModuleClock(PWM0_MODULE, CLK_CLKSEL3_PWM0_S_PLL, 0);
  CLK_SetModuleClock(PWM1_MODULE, CLK_CLKSEL3_PWM0_S_PLL, 0);
#elif defined(__NANO1X2__)
   //Enable ADC module
  CLK_EnableModuleClock(ADC_MODULE);
  
  //Enable PWM0 ~PWM3 module
  CLK_EnableModuleClock(PWM0_CH01_MODULE);
  CLK_EnableModuleClock(PWM0_CH23_MODULE);  
  
  CLK_SetModuleClock(PWM0_CH01_MODULE, CLK_CLKSEL1_PWM0_CH01_S_HCLK, 0);
  CLK_SetModuleClock(PWM0_CH23_MODULE, CLK_CLKSEL1_PWM0_CH23_S_HCLK, 0);
#endif
}

/* Init System Clock                                                                                       */
void SystemClock_Config(void)
{
/* Enable Internal RC 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRC_EN_Msk);
    
    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_HIRC_STB_Msk);

#if defined(HIRC)
    CLK_EnablePLL(CLK_CLKSEL0_HCLK_S_HIRC, 96000000);
    /* Switch HCLK clock source to HIRC */
    CLK_WaitClockReady(CLK_CLKSTATUS_HIRC_STB_Msk | CLK_CLKSTATUS_PLL_STB_Msk);

#else  // defined(HXT12)
	/* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCTL_HXT_EN_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_HXT_STB_Msk);

    /* Enable external 12MHz HXT */
    CLK_EnableXtalRC(CLK_PWRCTL_HXT_EN_Msk);
	
    CLK_EnablePLL(CLK_PLLCTL_PLL_SRC_HXT, 96000000);
    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_HXT_STB_Msk | CLK_CLKSTATUS_PLL_STB_Msk);

#endif   
 
#if F_CPU == 48000000
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL, CLK_HCLK_CLK_DIVIDER(2));
#elif F_CPU == 32000000
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL, CLK_HCLK_CLK_DIVIDER(3));
#else // F_CPU == 24000000
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL, CLK_HCLK_CLK_DIVIDER(4));
#endif
    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(F_CPU);
  
    /* STCLK to HXT */    
    //CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLK_S_HXT);    
}
