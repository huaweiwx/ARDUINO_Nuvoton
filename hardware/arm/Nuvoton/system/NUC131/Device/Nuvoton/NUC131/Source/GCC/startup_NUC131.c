/* ----------------------------------------------------------------------------
 *         Nuvoton Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
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

#include "NUC131.h"

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

/* Memory mapping defintions for nuc400series */
#define IROM_ADDR       (0x00100000u) /**< Internal ROM base address */
#define IRAM0_ADDR      (0x20000000u) /**< Internal RAM 0 base address */
#define IRAM1_ADDR      (0x20080000u) /**< Internal RAM 1 base address */
#define NFC_RAM_ADDR    (0x20100000u) /**< NAND Flash Controller RAM base address */

/** \cond DOXYGEN_SHOULD_SKIP_THIS */
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
void WDT_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void EINT0_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void EINT1_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void GPAB_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void GPCDEF_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void TMR0_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void TMR1_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void TMR2_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void TMR3_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void UART02_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void UART1_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void SPI0_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));           
void UART3_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART4_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART5_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void I2C0_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void I2C1_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void CAN0_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void CAN1_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void PWM0_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void PWM1_IRQHandler       ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void BPWM0_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void BPWM1_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void BRAKE0_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void BRAKE1_IRQHandler     ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 
void PWRWU_IRQHandler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTC_IRQHandler        ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); 

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
	(void*) (0UL),           /* Reserved */
	(void*) (0UL),           /* Reserved */
	(void*) (0UL),           /* Reserved */
	(void*) (0UL),           /* Reserved */
	(void*) SVC_Handler,
	(void*) DebugMon_Handler,
	(void*) (0UL),           /* Reserved */
	(void*) PendSV_Handler,
	(void*) SysTick_Handler,

	/* Configurable interrupts */
	(void *)BOD_IRQHandler,    /*  0  BOD_IRQHandler */
	(void *)WDT_IRQHandler,
  (void *)EINT0_IRQHandler,
  (void *)EINT1_IRQHandler,
  (void *)GPAB_IRQHandler , 
  (void *)GPCDEF_IRQHandler,
  (void *)(0UL), 
  (void *)(0UL), 
  (void *)TMR0_IRQHandler,
  (void *)TMR1_IRQHandler,
  (void *)TMR2_IRQHandler,
  (void *)TMR3_IRQHandler,
  (void *)UART02_IRQHandler,
  (void *)UART1_IRQHandler,
  (void *)SPI0_IRQHandler,            
  (void *)UART3_IRQHandler,
  (void *)UART4_IRQHandler ,
  (void *)UART5_IRQHandler ,
  (void *)I2C0_IRQHandler,
  (void *)I2C1_IRQHandler,
  (void *)CAN0_IRQHandler ,
  (void *)CAN1_IRQHandler,
  (void *)PWM0_IRQHandler,
  (void *)PWM1_IRQHandler,
  (void *)BPWM0_IRQHandler,
  (void *)BPWM1_IRQHandler,
  (void *)BRAKE0_IRQHandler,
  (void *)BRAKE1_IRQHandler,  
  (void *)PWRWU_IRQHandler,
  (void *)ADC_IRQHandler, 
  (void *)(0UL),
  (void *)RTC_IRQHandler,
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
