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

#ifndef _NUVOTON_PIN_LIST_H_
#define _NUVOTON_PIN_LIST_H_

#ifdef VARIANT_PIN_LIST
  #define PIN_LIST VARIANT_PIN_LIST
  #ifndef GPIO_DESC_USERDEF
  #   define GPIO_DESC_USERDEF 1
  #endif
#else
  #define PIN_LIST CHIP_PIN_LIST
#endif

#ifdef __cplusplus
	class __ConstPin {
	public:
		constexpr __ConstPin(const uint32_t ulPortBase, const  uint32_t pinMask, const  uint32_t ioReg, const uint8_t ucPin)
		: ulPortBase(ulPortBase), pinMask(pinMask), ioReg(ioReg), ucPin(ucPin) {};
		constexpr operator uint8_t() const {return ucPin;}
		const uint32_t  ulPortBase;
		const uint32_t  pinMask;
        const uint32_t  ioReg;
		const uint8_t   ucPin;
	};
	
	#define PIN(a, b, c) _P##a##b = c
	enum {
		PIN_LIST,
		NUM_DIGITAL_PINS,
	};
	#undef PIN

    #ifdef GPIOA_BASE
	  #define PIN(a, b, c) P##a##_##b(GPIO##a##_BASE,bit(b),GPIO_PIN_REGADR((GPIO##a##_BASE-GPIOA_BASE)/(GPIOB_BASE-GPIOA_BASE),b),c)
	#elif defined(PA_BASE)  
	  #define PIN(a, b, c) P##a##_##b(P##a##_BASE,bit(b),GPIO_PIN_REGADR((P##a##_BASE-PA_BASE)/(PB_BASE-PA_BASE),b),c)
    #else
	  #define PIN(a, b, c) P##a##_##b(P##a##_BASE,bit(b),GPIO_PIN_REGADR(a,b),c)
    #endif	
	constexpr __ConstPin PIN_LIST;
	#undef PIN
	
	#define ARDUINOPIN_TypeDef  __ConstPin
	
#else  /*c mode*/

	#define ARDUINOPIN_TypeDef  uint8_t
	
	#define PIN(a, b, c) P##a##_##b = c
	enum {
		PIN_LIST,
		NUM_DIGITAL_PINS,
	};
	#undef PIN
#endif /*__cplusplus*/

#endif
