/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef _NUVOTON_H_
#define _NUVOTON_H_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#if defined(M480)
  #include "M480.h"
#elif defined(M451Series)
  #include "M451Series.h"
#elif defined(__NUC240__)
  #include "NUC200Series.h"
#elif defined(__NANO100__)
  #include "Nano100Series.h"
#elif defined(__NUC131__)
  #include "NUC131.h"
#elif defined(__NANO1X2__)
  #include "Nano1X2Series.h"
#elif defined(Mini58Series)
  #include "Mini58Series.h"
#elif defined(Mini51Series)
  #include "Mini51Series.h"
#elif defined(M051Series)
  #include "M051Series.h"
#elif defined(M058S)
  #include "M058S.h"
#endif
#pragma GCC diagnostic pop


#include "wiring_constants.h"
#include "build_defines.h"

#if defined(Mini58Series)|| defined(Mini51Series)||defined(M051Series)||defined(M058S)||defined(M480)||defined(__NUC240__)
 #if defined(CHIP128P)
  #include "Chips/list128.h"
 #elif defined(CHIP100P)
  #include "Chips/list100.h"
 #elif defined(CHIP64P)
  #include "Chips/list64.h"
 #elif defined(CHIP48P)
  #include "Chips/list48.h"
 #elif defined(CHIP33P)
  #include "Chips/list33.h"
 #elif defined(CHIP28P)
  #include "Chips/list28.h"
 #elif defined(CHIP20P)
  #include "Chips/list20.h"
 #endif
#endif

#include "variant.h"
#include "pin_list.h"

#if defined(M480)
  #include "Chips/M480_typedef.h"
#elif defined(Mini58Series)
  #include "Chips/Mini58Series_typedef.h"
#elif defined(Mini51Series)
  #include "Chips/Mini51Series_typedef.h"
#elif defined(M051Series)
  #include "Chips/M051Series_typedef.h"
#elif defined(M058S)
  #include "Chips/M058S_typedef.h"
#else
  #include "nuvoton_typedef.h"
#endif



#include "nuvoton_gpio.h"

#endif