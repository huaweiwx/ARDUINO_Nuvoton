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
  
#include "nuvoton_series.h"

#pragma GCC diagnostic pop


#include "wiring_constants.h"
#include "build_defines.h"

#if defined(Mini58Series)|| defined(Mini51Series)||defined(M051Series)||defined(M058S)||defined(M480)||defined(__NUC240__)||defined(NUC029FAE)
  #include "chip.h"
#endif

#include "variant.h"
#include "pin_list.h"
#include "nuvoton_typedef.h"
#include "nuvoton_gpio.h"

#endif