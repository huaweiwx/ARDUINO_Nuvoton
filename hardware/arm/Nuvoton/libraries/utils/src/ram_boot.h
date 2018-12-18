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

#ifndef _RAM_BOOT_H_
#define _RAM_BOOT_H_
#include "Bootloader.h"


__attribute__(( constructor (101))) void premain(){ 
#ifdef SERIAL_LOAD_RAM
  if (UTIL_checkUserCode(SERIAL_LOAD_RAM))
  {
    UTIL_jumpToUser(SERIAL_LOAD_RAM);
  } 
  else 
#elif defined(STM32H743ZI)
  if (UTIL_checkUserCode(0x24000000))
     UTIL_jumpToUser(0x24000000);
#else
  if (UTIL_checkUserCode(0x20000000))
     UTIL_jumpToUser(0x20000000);
#endif

}
#endif