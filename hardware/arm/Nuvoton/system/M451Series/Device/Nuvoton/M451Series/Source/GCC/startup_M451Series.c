/* ----------------------------------------------------------------------------
 *         Nuvoton Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Nuvoton Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

#include "M451Series.h"

/* Initialize segments */
extern uint32_t _sfixed;
extern uint32_t _efixed;
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _szero;
extern uint32_t _ezero;
extern uint32_t _sstack;
extern uint32_t _estack;

/** \cond DOXYGEN_SHOULD_SKIP_THIS */
void SystemInit(void);
int main(void);
/** \endcond */

// Arduino: we must setup hardware before doing this
void __libc_init_array(void);

/* Default empty handler */
void Dummy_Handler(void);

// Arduino: handlers weak symbols moved into main
/* Cortex-M4 core handlers */
void Reset_Handler      ( void );
void NMI_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void HardFault_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void MemManage_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void BusFault_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UsageFault_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SVC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DebugMon_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PendSV_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SysTick_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

/* Peripherals handlers */
void BOD_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void IRC_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void PWRWU_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void RAMPE_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void CLKFAIL_IRQHandler    ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void RTC_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void TAMPER_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void WDT_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void WWDT_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void EINT0_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void EINT1_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void EINT2_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void EINT3_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void EINT4_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void EINT5_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void GPA_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPB_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPC_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPD_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void GPE_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void GPF_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void SPI0_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void SPI1_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void BRAKE0_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM0P0_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM0P1_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM0P2_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void BRAKE1_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM1P0_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM1P1_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM1P2_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TMR0_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TMR1_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TMR2_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TMR3_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART0_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void UART1_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void I2C0_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void I2C1_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDMA_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DAC_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void ADC00_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void ADC01_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void ACMP01_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void ADC02_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void ADC03_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void UART2_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void UART3_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI2_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void USBD_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void USBH_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void USBOTG_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void CAN0_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void SC0_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void TK_IRQHandler         ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
 
/* Exception Table */
__attribute__ ((section(".vectors")))
const void * exception_table[] = {

 /* Configure Initial Stack Pointer, using linker-generated symbols */
 (void*) (&_estack),
 (void*) Reset_Handler,
 
 (void*) NMI_Handler,
 (void*) HardFault_Handler,
 (void*) MemManage_Handler,
 (void*) BusFault_Handler,
 (void*) UsageFault_Handler,
 (void*) (0UL),           		   /* Reserved */
 (void*) (0UL),                    /* Reserved */
 (void*) (0UL),                    /* Reserved */
 (void*) (0UL),                    /* Reserved */
 (void*) SVC_Handler,
 (void*) DebugMon_Handler,
 (void*) (0UL),                    /* Reserved */
 (void*) PendSV_Handler,
 (void*) SysTick_Handler,
 
	/* Configurable interrupts */
 (void*) BOD_IRQHandler,           //; 0: Brown Out detection
 (void*) IRC_IRQHandler,           //; 1: Internal RC
 (void*) PWRWU_IRQHandler,         //; 2: Power down wake up 
 (void*) RAMPE_IRQHandler,         //; 3: RAM parity error
 (void*) CLKFAIL_IRQHandler,       //; 4: Clock detection fail
 (void*) (0UL),                    //; 5: Reserved
 (void*) RTC_IRQHandler,           //; 6: Real Time Clock 
 (void*) TAMPER_IRQHandler,        //; 7: Tamper detection
 (void*) WDT_IRQHandler,           //; 8: Watchdog timer
 (void*) WWDT_IRQHandler,          //; 9: Window watchdog timer
 (void*) EINT0_IRQHandler,         //; 10: External Input 0
 (void*) EINT1_IRQHandler,         //; 11: External Input 1
 (void*) EINT2_IRQHandler,         //; 12: External Input 2
 (void*) EINT3_IRQHandler,         //; 13: External Input 3
 (void*) EINT4_IRQHandler,         //; 14: External Input 4
 (void*) EINT5_IRQHandler,         //; 15: External Input 5
 (void*) GPA_IRQHandler,           //; 16: GPIO Port A
 (void*) GPB_IRQHandler,           //; 17: GPIO Port B
 (void*) GPC_IRQHandler,           //; 18: GPIO Port C
 (void*) GPD_IRQHandler,           //; 19: GPIO Port D
 (void*) GPE_IRQHandler,           //; 20: GPIO Port E
 (void*) GPF_IRQHandler,           //; 21: GPIO Port F
 (void*) SPI0_IRQHandler,          //; 22: SPI0
 (void*) SPI1_IRQHandler,          //; 23: SPI1
 (void*) BRAKE0_IRQHandler,        //; 24: 
 (void*) PWM0P0_IRQHandler,        //; 25: 
 (void*) PWM0P1_IRQHandler,        //; 26: 
 (void*) PWM0P2_IRQHandler,        //; 27: 
 (void*) BRAKE1_IRQHandler,        //; 28: 
 (void*) PWM1P0_IRQHandler,        //; 29: 
 (void*) PWM1P1_IRQHandler,        //; 30: 
 (void*) PWM1P2_IRQHandler,        //; 31: 
 (void*) TMR0_IRQHandler,          //; 32: Timer 0
 (void*) TMR1_IRQHandler,          //; 33: Timer 1
 (void*) TMR2_IRQHandler,          //; 34: Timer 2
 (void*) TMR3_IRQHandler,          //; 35: Timer 3
 (void*) UART0_IRQHandler,         //; 36: UART0
 (void*) UART1_IRQHandler,         //; 37: UART1
 (void*) I2C0_IRQHandler,          //; 38: I2C0
 (void*) I2C1_IRQHandler,          //; 39: I2C1
 (void*) PDMA_IRQHandler,          //; 40: Peripheral DMA
 (void*) DAC_IRQHandler,           //; 41: DAC
 (void*) ADC00_IRQHandler,         //; 42: ADC0 interrupt source 0
 (void*) ADC01_IRQHandler,         //; 43: ADC0 interrupt source 1
 (void*) ACMP01_IRQHandler,        //; 44: ACMP0 and ACMP1
 (void*) (0UL),                    //; 45: Reserved
 (void*) ADC02_IRQHandler,         //; 46: ADC0 interrupt source 2
 (void*) ADC03_IRQHandler,         //; 47: ADC0 interrupt source 3
 (void*) UART2_IRQHandler,         //; 48: UART2
 (void*) UART3_IRQHandler,         //; 49: UART3
 (void*) (0UL),                    //; 50: Reserved
 (void*) SPI2_IRQHandler,          //; 51: SPI2
 (void*) (0UL),                    //; 52: Reserved
 (void*) USBD_IRQHandler ,         //; 53: USB device
 (void*) USBH_IRQHandler,          //; 54: USB host
 (void*) USBOTG_IRQHandler,        //; 55: USB OTG
 (void*) CAN0_IRQHandler,          //; 56: CAN0
 (void*) (0UL),          		   //; 57: Reserved
 (void*) SC0_IRQHandler,           //; 58: 
 (void*) (0UL),          		   //; 59: Reserved.
 (void*) (0UL),          		   //; 60: 
 (void*) (0UL) ,         		   //; 61: 
 (void*) (0UL),          		   //; 62:
 (void*) TK_IRQHandler,            //; 63:	
};

/**
 * \brief This is the code that gets called on processor reset.
 * To initialize the device, and call the main() routine.
 */
void Reset_Handler(void)
{
	uint32_t *pSrc, *pDest;

	/* Initialize the relocate segment */
	pSrc = &_etext;
	pDest = &_srelocate;

	if (pSrc != pDest) {
		for (; pDest < &_erelocate;) {
			*pDest++ = *pSrc++;
		}
	}

	/* Clear the zero segment */
	for (pDest = &_szero; pDest < &_ezero;) {
		*pDest++ = 0;
	}

#ifndef __NO_SYSTEM_INIT
	SystemInit();
#endif
	/* Initialize the C library */
	// Arduino: we must setup hardware before doing this
	__libc_init_array();

	/* Branch to main function */
	main();

	/* Infinite loop */
	while (1);
}

/**
 * \brief Default interrupt handler for unused IRQs.
 */
void Dummy_Handler(void)
{
	while (1) {
	}
}
