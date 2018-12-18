/*
  Copyright (c) 2017 huawei

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
#include <Arduino.h>
//#include "USBDevice.h"

#ifndef _BOOTLOADER_H_
#define _BOOTLOADER_H_
#define USER_CODE_RAM   0x20000000U

//for run in sram by app manager
#ifdef STM32F1  //F0/L0/F1/L1/F3

# if (FLASH_BANK1_END >  0x0801FFFFU) /*512k flash 64k ram for xC/xE*/
#  define MAX_PROG_RAM (44*1024)      /*use 0x20000000~0x2000BFFF*/
# else  /*128k flash 20k ram for x8/xB*/
#  define MAX_PROG_RAM (16*1024)      /*use 0x20000000~0x20003FFF*/
# endif

#elif defined(STM32F207ZG)
#  define MAX_PROG_RAM (96*1024)

#elif defined(STM32F303VC)
#  define MAX_PROG_RAM (40*1024)

#elif defined(STM32F401CC)
#  define MAX_PROG_RAM (44*1024)      /*use 0x20000000~0x2000BFFF*/

#elif defined(STM32F401RE)
#  define MAX_PROG_RAM (64*1024)

#elif defined(STM32F407VE)||defined(STM32F407VG)||defined(STM32F407ZE)||\
      defined(STM32F407ZG)||defined(STM32F407IG)||defined(STM32F411RE)||defined(STM32F429ZI)||defined(STM32F429IG)
#  define MAX_PROG_RAM (96*1024)

#elif defined(STM32F746IG)
#  define MAX_PROG_RAM (196*1024)

#elif defined(STM32F767ZI)
#  define MAX_PROG_RAM (256*1024)

#elif defined(STM32L152RE)||defined(STM32L476RG)
#  define MAX_PROG_RAM (64*1024)

#else
//# error "please add me!"
#endif

extern const uint16_t appCodeSegAddr[];

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

int  UTIL_checkUserCode(uint32_t usrAddr);
void UTIL_jumpToUser(uint32_t usrAddr);
void start_application(uintptr_t address);


#ifdef __cplusplus
 } //  extern "C"
#endif /* __cplusplus */

#endif

