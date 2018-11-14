
#include "Arduino.h"

extern void CLK_EnableModuleClock(uint32_t);

void Enable_All_IPs(void)
{
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
#if defined(__M451__)    
/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
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
#elif defined(__NUC240__)
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
#elif defined(__NANO100__)
/* Enable Internal RC 22.1184MHz clock */
    //CLK_EnableXtalRC(CLK_PWRCTL_HIRC_EN_Msk);
    
    /* Waiting for clock ready */
    //CLK_WaitClockReady(CLK_CLKSTATUS_HIRC_STB_Msk);

    /* Switch HCLK clock source to HIRC */
    //CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HIRC,CLK_HCLK_CLK_DIVIDER(1));

		/* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCTL_HXT_EN_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_HXT_STB_Msk);

    #if 0
    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(F_CPU);
    #else
    /* Enable external 12MHz HXT */
    CLK_EnableXtalRC(CLK_PWRCTL_HXT_EN_Msk);
    CLK_EnablePLL(CLK_PLLCTL_PLL_SRC_HXT, F_CPU*3);
    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_HXT_STB_Msk | CLK_CLKSTATUS_PLL_STB_Msk);
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL, CLK_HCLK_CLK_DIVIDER(3));
    #endif
    
  
    /* STCLK to HXT */    
    //CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLK_S_HXT);    
#elif defined(__NUC131__) 

    /* Enable Internal RC 22.1184MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_OSC22M_EN_Msk);
    
    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_OSC22M_STB_Msk);

    /* Switch HCLK clock source to HIRC */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HIRC,CLK_CLKDIV_HCLK(1));

		/* Enable external 12MHz XTAL, internal 22.1184MHz */
    CLK_EnableXtalRC(CLK_PWRCON_XTL12M_EN_Msk | CLK_PWRCON_OSC22M_EN_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(F_CPU);
  
    /* STCLK to HXT */    
    //CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLK_S_HXT);    
#elif defined(__NANO1X2__)     
    /* Set HCLK source form HXT and HCLK source divide 1  */
    //CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HXT,CLK_HCLK_CLK_DIVIDER(1));

    /* Enable 32KHz LXT and HIRC */
    CLK_EnableXtalRC(CLK_PWRCTL_LXT_EN_Msk | CLK_PWRCTL_HIRC_EN_Msk);

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_LXT_STB_Msk | CLK_CLKSTATUS_HIRC_STB_Msk);

    /*  Set HCLK frequency 32MHz */
    CLK_SetCoreClock(F_CPU);

    /* Enable IP clock */
    //CLK_EnableModuleClock(UART0_MODULE);

    /* Select IP clock source */
    //CLK_SetModuleClock(UART0_MODULE,CLK_CLKSEL1_UART_S_HIRC,CLK_UART_CLK_DIVIDER(1));  
#endif
}
