/*
  stm32_devices cut from stm32flash - Open Source ST STM32 flash program for *nix
  Copyright (C) 2010 Geoffrey McRae <geoff@spacevs.com>
  Copyright (C) 2014-2015 Antonio Borneo <borneo.antonio@gmail.com>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

  for appAdminister huaweiwx@sina.com 2017 2018
*/

#include <Arduino.h>
#include "dev_table.h"

#if defined(STM32F1)
#  if (FLASH_BANK1_END >  0x0801FFFFU) /*512k flash 64k ram for xC/xE*/
#    ifdef GD32F10X
        const  uint16_t appCodeSegAddr[] = {3,64,2*64,3*64};
#    else
        const  uint16_t appCodeSegAddr[] = {7,64, 2*64,3*64,4*64,5*64,6*64,7*64};
#    endif
#  else  /*128k flash 20k ram for x8/xB*/
        const uint16_t appCodeSegAddr[] =  {3,16,3*16,5*16};
#  endif
#elif defined(STM32F207ZG)
        const uint16_t appCodeSegAddr[] =  {7,128,2*128,3*128,4*128,5*128,6*128,7*128};
#elif defined(STM32F303VC)
        const uint16_t appCodeSegAddr[] =  {3,64, 2*64,3*64};
#elif defined(STM32F401CC)
        const uint16_t appCodeSegAddr[] =  {2,64,2*64};
#elif defined(STM32F303RE)||defined(STM32F303VE)||defined(STM32F401RE)||\
      defined(STM32F411RE)||defined(STM32F401ZE)||defined(STM32F407ZE)||defined(STM32F407VE)
        const uint16_t appCodeSegAddr[] =  {3,128,2*128,3*128};
#elif defined(STM32F407VG)||defined(STM32F407ZG)||(STM32F407IG)||(STM32F429IG)
        const uint16_t appCodeSegAddr[] =  {7,128,2*128,3*128,4*128,5*128,6*128,7*128};
#elif defined(STM32F746IG)
        const uint16_t appCodeSegAddr[] =  {3,256,2*256,3*256};
#elif defined(STM32F767ZI)||defined(STM32H743ZI)||defined(STM32L4R5ZI)
        const uint16_t appCodeSegAddr[] =  {7,256,2*256,3*256,4*256,5*256,6*256,7*256};
#elif defined(STM32L476RG)
        const uint16_t appCodeSegAddr[] =  {7,128,2*128,3*128,4*128,5*128,6*128,7*128};
#else /*add me*/

#warning "please add me!"

#endif
