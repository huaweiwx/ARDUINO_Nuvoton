/*
  For Arduino read/write fastest use in cplus code
  
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

#ifndef __NUNOTON_GPIO_H__
#define __NUNOTON_GPIO_H__

#include "util/base.h"

#ifdef __cplusplus

//inline void pinMode(__ConstPin CPin, uint32_t mode) {
//  pinMode(CPin.ucPin,mode);	
//  GPIO_SetMode((GPIO_T*)CPin.ulPortBase, CPin.pinMask, mode);
//}

inline void digitalWriteHigh(__ConstPin CPin) {
  ((GPIO_T*)CPin.ulPortBase)->DOUT |= CPin.pinMask;	
}

inline void digitalWriteLow(__ConstPin CPin) {
  ((GPIO_T*)CPin.ulPortBase)->DOUT &= ~CPin.pinMask;	
}

template<typename T=bool>
inline void digitalWrite(__ConstPin CPin, T val )
{
  if (val) {
    digitalWriteHigh(CPin);
  } else {
    digitalWriteLow(CPin);
  }
}

template<typename T>
inline T digitalRead(__ConstPin CPin)
{
  /* can add a section here to see if pin is readable */
  return bitRead(((GPIO_T*)CPin.ulPortBase)->PIN, CPin.pinMask);
}

inline void digitalToggle(__ConstPin CPin)
{
   ((GPIO_T*)CPin.ulPortBase)->DOUT ^= CPin.pinMask;
}

/*gpio low layer interface class*/
class LL_PIN {
  public:
    __ConstPin CPin;
    const uint8_t pos = (((CPin.pinMask)==BIT0)?0: 
						(((CPin.pinMask)==BIT1)?1: 
						(((CPin.pinMask)==BIT2)?2: 
						(((CPin.pinMask)==BIT3)?3: 
						(((CPin.pinMask)==BIT4)?4: 
						(((CPin.pinMask)==BIT5)?5: 
						(((CPin.pinMask)==BIT6)?6: 
						(((CPin.pinMask)==BIT7)?7: 
						(((CPin.pinMask)==BIT8)?8: 
						(((CPin.pinMask)==BIT9)?9: 
						(((CPin.pinMask)==BIT10)?10: 
						(((CPin.pinMask)==BIT11)?11: 
						(((CPin.pinMask)==BIT12)?12: 
						(((CPin.pinMask)==BIT13)?13: 
						(((CPin.pinMask)==BIT14)?14: 
						(((CPin.pinMask)==BIT15)?15:16))))))))))))))));

#if defined(P0)
	const uint32_t ioReg = GPIO_PIN_DATA_BASE + 0x20 * (((GPIO_T*)CPin.ulPortBase)-P0)/(P1-P0) + (pos<<2);
#else
	const uint32_t ioReg = GPIO_PIN_DATA_BASE + 0x40 *  (((GPIO_T*)CPin.ulPortBase)-PA)/(PB-PA)+(pos<<2);
#endif
    constexpr LL_PIN(__ConstPin CPin): CPin(CPin) {};
    
    template<typename T = bool>
    inline  T read() {
      return inp32(ioReg);
    }

    template<typename T>
    inline void write(T value) {
      outp32(ioReg, value);
    }

    template<typename T>
    inline LL_PIN & operator = (T value) {
      this->write(value);
      return *this;
    }
    template<typename T>
    inline LL_PIN & operator ^= (T value) {
      if(value) this->toggle();
      return *this;
    }

    LL_PIN& operator = (LL_PIN& rhs) {
      this->write(rhs.read());
      return *this;
    }

    inline __attribute__((always_inline))
    void high() {
      outp32(ioReg, 1);
    }

    inline __attribute__((always_inline))
    void low() {
      outp32(ioReg, 0);
    }

    template<typename T>
    inline operator T () {
      return read();
    }

    inline void operator  !() __attribute__((always_inline)) {
      toggle();
    }

    /*----- comptabled with DigitalPin ----------*/
    inline __attribute__((always_inline))
    void toggle() {
         M32(ioReg) ^= (uint32_t)1;
    }

    inline __attribute__((always_inline))
    void config(uint32_t mode, bool value) {  /*compatale with digitalPin*/
      this->mode(mode);
      this->write(value);
    }

    inline __attribute__((always_inline))
    void mode(uint32_t mode) {
      pinMode(CPin, mode);
    }

    inline __attribute__((always_inline))
    void attach(void (*callback)(void), uint32_t mode) {
      attachInterrupt(CPin.ucPin, callback, mode);
    }

    inline __attribute__((always_inline))
    void detach(void) {
      detachInterrupt(CPin.ucPin);
    }
};

class InputPin : public LL_PIN {
  public:
    uint32_t ulDelayCnt = F_CPU / 10'000'000;  
    constexpr InputPin(__ConstPin CPin, bool initial_value = 1): LL_PIN(CPin) {
      config(INPUT, initial_value);
    }

    inline void setWaitTime(uint32_t time){
		ulDelayCnt = time;
	}

    template<typename T = bool>
    inline operator T () {
      /*Waiting for stability*/
      if (ulDelayCnt) {                           
        for (volatile uint32_t i = ulDelayCnt; i > 0; i--);
      }
      return read();
    }

    uint32_t pulseIn(bool state = false, uint32_t timeout = 1'000'000L )
    {
      // Cache the port and bit of the pin in order to speed up the
      // pulse width measuring loop and achieve finer resolution.
      // Calling digitalRead() instead yields much coarser resolution.
      uint32_t startMicros = micros();

      // wait for any previous pulse to end
      while (read() == state) {
        if (micros() - startMicros > timeout)
          return 0;
      }

      // wait for the pulse to start
      while (read() != state) {
        if (micros() - startMicros > timeout)
          return 0;
      }

      uint32_t start = micros();
      // wait for the pulse to stop
      while (read() == state) {
        if (micros() - startMicros > timeout)
          return 0;
      }
      return (micros() - start);
    }
};

class OutputPin : public LL_PIN {
  public:
    uint32_t ulDelayCnt = F_CPU / 10'000'000; /* pulse_widch*/
    constexpr OutputPin(__ConstPin CPin, bool initial_value = 0): LL_PIN(CPin) {
      config(OUTPUT, initial_value);
    }

    inline void setWaitTime(uint32_t time){
		ulDelayCnt = time;
	}

    void pulse( bool value = true) {
      if (ulDelayCnt) {
        for (volatile uint32_t i = ulDelayCnt; i > 0; i--);
      }
      this->write(value);
      if (ulDelayCnt) {
        for (volatile uint32_t i = ulDelayCnt; i > 0; i--);
      }
      this->toggle();
    }

    template<typename T = bool>
    inline operator T () {
      return read();
    }

    inline void operator  !() __attribute__((always_inline)) {
      toggle();
    }

    template<typename T>
    inline OutputPin & operator = (T value) {
      write(value);
      return *this;
    }
    template<typename T>
    inline OutputPin & operator ^= (T value) {
      if(value) toggle(value);
      return *this;
    }
};

template < uint8_t nbits = 8, uint8_t bit_order = MSBFIRST>
class ClockedInput {
    // A DirectIO implementation of shiftIn. Also supports
    // a variable number of bits (1-32); shiftIn is always 8 bits.
  public:
    // Define a type large enough to hold nbits bits (see base.h)
    typedef bits_type(nbits) bits_t;
	
    uint32_t ulDelayCnt = F_CPU / 10'000'000;

    constexpr ClockedInput(__ConstPin data_pin, __ConstPin clock_pin , bool pullup = true) : data(data_pin, pullup), clock(clock_pin) {}
    InputPin data;
    OutputPin clock;

    inline void setWaitTime(uint32_t time){
		ulDelayCnt = time;
	}

    bits_t read() {
      // read nbits bits from the input pin and pack them
      // into a value of type bits_t.

      bits_t value = 0;
      bits_t mask = (bit_order == LSBFIRST) ? 1 : (bits_t(1) << (nbits - 1));

      data.setWaitTime(0);  /*use this ulDelayCnt*/

      for (uint8_t i = 0; i < nbits; i++) {
        clock = HIGH;
        if (ulDelayCnt) {
          for (volatile uint32_t i = ulDelayCnt; i > 0; i--);
        }

        if (data) {
          value |= mask;
        }
        clock = LOW;

        if (bit_order == LSBFIRST) {
          mask <<= 1;
        }
        else {
          mask >>= 1;
        }
        if (ulDelayCnt) {
          for (volatile uint32_t i = ulDelayCnt; i > 0; i--);
        }
      }
      return value;
    }

    operator bits_t() {
      return read();
    }
};

template < uint8_t nbits = 8, uint8_t bit_order = MSBFIRST>
class ClockedOutput {
    // A DirectIO implementation of shiftOut. Also supports
    // a variable number of bits (1-32); shiftOut is always 8 bits.
  public:
    // Define a type large enough to hold nbits bits (see base.h)
    typedef bits_type(nbits) bits_t;

    uint32_t ulDelayCnt = F_CPU / 10'000'000;
	
    constexpr ClockedOutput(__ConstPin data_pin, __ConstPin clock_pin): data(data_pin), clock(clock_pin) {};
    OutputPin data;
    OutputPin clock;

    inline void setWaitTime(uint32_t time){
		ulDelayCnt = time;
	}

    void write(bits_t val, bool level = HIGH) {
      // write nbits bits to the output pin
      bits_t mask = (bit_order == LSBFIRST) ? 1 : (bits_t(1) << (nbits - 1));

      clock.setWaitTime(ulDelayCnt);  /*setup clock.pulse width*/

      for (uint8_t i = 0; i < nbits; i++) {
        data = (val & mask);
        clock.pulse(level);

        if (bit_order == LSBFIRST) {
          mask <<= 1;
        }
        else {
          mask >>= 1;
        }
      }
    }

    ClockedOutput& operator = (bits_t val) {
      write(val);
      return *this;
    }
};

// This macro lets you temporarily set an output to a value, 
// and toggling back at the end of the code block. For example:
// 
// Output<2> cs;
// Output<3> data;
// with(cs, LOW) {
//     data = HIGH;
// }
// 
// is equivalent to:
// cs = LOW;
// data = HIGH;
// cs = HIGH;

#define with(pin, val) for(boolean _loop_##pin=((pin=val),true);_loop_##pin; _loop_##pin=((pin=!val), false))

#define GPIOPIN LL_PIN
#define BB_PIN LL_PIN   /* LL_PIN use bitband operation */

#endif /*__cplusplus*/
#include "avr_emulation.h"
#endif /*__NUNOTON_GPIO_H__*/
