/*
  Copyright (c) 2018 huaweiwx@sina.com 2018.7.1

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


#ifndef _BUILD_DEFINES_H_
#define _BUILD_DEFINES_H_

#define  ARDUINO_EXTEND 1
#include "util/utils_all.h"

#if __has_include("HAL_Conf.h")
# include "HAL_Conf.h"
#endif

#if __has_include("configs/HAL_Conf.h")
# include "configs/HAL_Conf.h"
#endif


//default defines,  overriden by HAL_Conf.h  in path sketch or path valiants/valiant/configs/
/***************  HAL_Conf default here ******************/

//OS
#ifndef  FREERTOS
# define FREERTOS  0
#endif

#ifndef  UCOSII	/*running with ucosii*/
# define UCOSII      0
#endif

#ifndef  BOOTLOADER	/*check & go addr if avalible */
# define BOOTLOADER  0
#endif

#ifndef  USE_BITBAND
# define USE_BITBAND 1
#endif

#ifndef  USE_CORECALLBACK
# define USE_CORECALLBACK 0
#endif

#ifndef  USE_AVREMULATION
# define USE_AVREMULATION 1
#endif

#ifndef  USE_ICE
# define USE_ICE          1
#endif

#ifndef  USE_ERRORBLINK
#  ifdef DEBUG_NUVOTON_USER
    #define USE_ERRORBLINK 1
#  else
    #define USE_ERRORBLINK 0
#  endif
#endif	

#ifndef  USE_TIMER0_PWM
# define USE_TIMER0_PWM 1
#endif

#ifndef  USE_TIMER1_PWM
# define USE_TIMER1_PWM 1
#endif

#ifndef  USE_TIMER2_PWM
# define USE_TIMER2_PWM 1
#endif

#ifndef  USE_TIMER3_PWM
# define USE_TIMER3_PWM 1
#endif

//devices
//USB
#ifndef USE_USBSERIAL
# ifdef MENU_USB_SERIAL
#   define USE_USBSERIAL 1
#   define USE_USB 1
# endif
#endif

#ifndef USE_USBDMSC
# ifdef MENU_USB_MASS_STORAGE
#   define USE_USBDMSC  1
#   define USE_USB 1
# endif
#endif

#ifndef USE_USBDDFU
# ifdef MENU_USB_DFU
#   define USE_USBDDFU  1
#   define USE_USB 1
# endif
#endif

#ifndef USE_USBDCOMPOSITE
# ifdef MENU_USB_IAD
#	define USE_USBDCOMPOSITE  1
#   define USE_USB 1
# endif
#endif

#ifndef USE_USBDCONF
#  define USE_USBDCONF  1
#endif

//USART
#ifndef USE_UART0
# define USE_UART0 1
#endif
#ifndef USE_UART1
# define USE_UART1 1
#endif
#ifndef USE_UART2
# define USE_UART2 1
#endif
#ifndef USE_UART3
# define USE_UART3 1
#endif
#ifndef USE_UART4
# define USE_UART4 1
#endif
#ifndef USE_UART5
# define USE_UART5 1
#endif

//SPI
#ifndef USE_SPI0
# define USE_SPI0 1
#endif

#ifndef USE_SPI1
# define USE_SPI1 1
#endif

#ifndef USE_SPI2
# define USE_SPI2 1
#endif

#ifndef USE_SPI3
# define USE_SPI3 1
#endif

#ifndef USE_SPI4
# define USE_SPI4 1
#endif

//I2C
#ifndef USE_I2C0
# define USE_I2C0 1
#endif

#ifndef USE_I2C1
# define USE_I2C1 1
#endif

#ifndef USE_I2C2
# define USE_I2C2 1
#endif

/***************  HAL_Conf default end  ******************/

#endif /*_BUILD_DEFINES_H_*/