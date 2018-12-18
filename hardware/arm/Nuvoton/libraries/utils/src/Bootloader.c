/*
  Copyright (c) 2017 huaweiwx@sina.com

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
#include "Bootloader.h"

#if !(defined(STM32F0)||defined(STM32L0))

static void powerdown_nvic(void);
static void powerdown_scb(uint32_t vtor);
static void start_new_application(void *sp, void *pc);

void start_application(uintptr_t address)
{
    void *sp;
    void *pc;

    // Interrupts are re-enabled in start_new_application
    __disable_irq();

    SysTick->CTRL = 0x00000000;
    powerdown_nvic();
    powerdown_scb(address);

    sp = *((void**)address + 0);
    pc = *((void**)address + 1);
    start_new_application(sp, pc);
}

static void powerdown_nvic()
{
    int isr_groups_32;
    int i;
    int j;

    isr_groups_32 = ((SCnSCB->ICTR & SCnSCB_ICTR_INTLINESNUM_Msk) >> SCnSCB_ICTR_INTLINESNUM_Pos) + 1;
    for (i = 0; i < isr_groups_32; i++) {
        NVIC->ICER[i] = 0xFFFFFFFF;
        NVIC->ICPR[i] = 0xFFFFFFFF;
        for (j = 0; j < 8; j++) {
            NVIC->IP[i * 8 + j] = 0x00000000;
        }
    }
}

static void powerdown_scb(uint32_t vtor)
{
    int i;

    // SCB->CPUID   - Read only CPU ID register
    SCB->ICSR = SCB_ICSR_PENDSVCLR_Msk | SCB_ICSR_PENDSTCLR_Msk;
    SCB->VTOR = vtor;
    SCB->AIRCR = 0x05FA | 0x0000;
    SCB->SCR = 0x00000000;
    // SCB->CCR     - Implementation defined value
    for (i = 0; i < 12; i++) {
#if defined(STM32F7)||defined(STM32H7)
        SCB->SHPR[i] = 0x00;
#else
        SCB->SHP[i] = 0x00;
#endif
    }
    SCB->SHCSR = 0x00000000;
    SCB->CFSR = 0xFFFFFFFF;
    SCB->HFSR = SCB_HFSR_DEBUGEVT_Msk | SCB_HFSR_FORCED_Msk | SCB_HFSR_VECTTBL_Msk;
    SCB->DFSR = SCB_DFSR_EXTERNAL_Msk | SCB_DFSR_VCATCH_Msk |
                SCB_DFSR_DWTTRAP_Msk | SCB_DFSR_BKPT_Msk | SCB_DFSR_HALTED_Msk;
    // SCB->MMFAR   - Implementation defined value
    // SCB->BFAR    - Implementation defined value
    // SCB->AFSR    - Implementation defined value
    // SCB->PFR     - Read only processor feature register
    // SCB->DFR     - Read only debug feature registers
    // SCB->ADR     - Read only auxiliary feature registers
    // SCB->MMFR    - Read only memory model feature registers
    // SCB->ISAR    - Read only instruction set attribute registers
    // SCB->CPACR   - Implementation defined value
}

static void start_new_application(void *sp, void *pc)
{
    __asm volatile (
        "mov    r2, #0      \n"
        "msr    control, r2 \n" // Switch to main stack
        "mov    sp, %0      \n"
        "msr    primask, r2 \n" // Enable interrupts
        "bx     %1          \n"
        :
        : "l" (sp), "l" (pc)
        : "r2", "cc", "memory"
    );
}

//for m3/m4/m7 only
int UTIL_checkUserCode(uint32_t usrAddr) {
    uint32_t sp = *(volatile uint32_t *) usrAddr;
#if defined(STM32F0)||defined(STM32F1)||defined(STM32F3)||defined(STM32L1)
    return ((sp & 0xFFFE0000) == 0x20000000)?1:0;  /*1xxxx*/
#elif defined(STM32F2)
    return ((sp & 0xFFFC0000) == 0x20000000)?1:0;  /*3xxxx*/
#elif defined(STM32L4R5ZI)
    return ((sp & 0xFFF00000) == 0x20000000)?1:0;
#elif defined(STM32F4)||defined(STM32L4)
    return ((sp & 0xFFF80000) == 0x20000000)?1:0;
#elif defined(STM32F7)||defined(STM32H7)
    return ((sp & 0xFFF00000) == 0x20000000)?1:0;
#else
#error  !!for m3/m4/m7 only!!
#endif
}

/*bootloader use*/
void UTIL_jumpToUser(uint32_t usrAddr) {
  // Dedicated function with no call to any function (appart the last call)
  // This way, there is no manipulation of the stack here, ensuring that GGC
  // didn't insert any pop from the SP after having set the MSP.
  
  typedef void (*funcPtr)(void);

  uint32_t jumpAddr = *(volatile uint32_t *)(usrAddr + 0x04); /* reset ptr in vector table */

  funcPtr usrMain = (funcPtr) jumpAddr;

  asm volatile("msr msp, %0"::"g"
               (*(volatile uint32_t *)usrAddr));
  *(uint32_t *) 0xE000ED08 = usrAddr;   /* 设置中断向量表地址 */
  usrMain();                            /* go! */
}

#ifdef CHK_JUMP_TO_SRAM    /*for develop ram debug only*/
//reset boot to ram if available
# include "ram_boot.h"

#endif

#endif