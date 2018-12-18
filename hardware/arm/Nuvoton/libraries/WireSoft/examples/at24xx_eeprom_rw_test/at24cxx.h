/*
  EEPROM.h - EEPROM library
  Copyright (c) 2006 David A. Mellis.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  modify by huawewi huaweiwx@sina.com 2017.2.18
*/

#ifndef _AT24CXX_h
#define _AT24CXX_h
#include "Arduino.h"
#if __has_include("configs/i2cEepromConfig.h")
#  include "configs/i2cEepromConfig.h"
#endif

#if (USE_WARESOFT >0)||(AT24CXX_DEV == 0)
# include "WireSoft.h"
# define  WARE  TwoWireSoft
#elif  AT24CXX_DEV >0
# include "Wire.h"
# define  WARE  TwoWire
#else
# error "support hardware iic port?  undefined  exteeprom iic device, check file variat/config/i2cEepromConfig.h"
#endif


#define AT24C01		0x7f
#define AT24C02		0xff
#define AT24C04		0x1ff
#define AT24C08		0x3ff
#define AT24C16		0x7ff
#define AT24C32		0xfff
#define AT24C64	  0x1fff
#define AT24C128	0x3fff
#define AT24C256	0x7fff
#define AT24C512	0xffff

class EERef {
  protected:
    virtual int    read_byte(int index);
    virtual void  write_byte(int index, uint8_t val);

  public:
    EERef( const int index ): index( index ) {}

    //Access/read members.
    uint8_t operator*() const {
      return read_byte(index);
    }
    operator const uint8_t() const {
      return **this;
    }

    //Assignment/write members.
    EERef &operator=(const EERef &ref ) {
      return *this = *ref;
    }
    EERef &operator = (uint8_t in) {
      return  write_byte(index, in ), *this;
    }
    EERef &operator +=(uint8_t in) {
      return *this = **this + in;
    }
    EERef &operator -=(uint8_t in) {
      return *this = **this - in;
    }
    EERef &operator *=(uint8_t in) {
      return *this = **this * in;
    }
    EERef &operator /=(uint8_t in) {
      return *this = **this / in;
    }
    EERef &operator ^=(uint8_t in) {
      return *this = **this ^ in;
    }
    EERef &operator %=(uint8_t in) {
      return *this = **this % in;
    }
    EERef &operator &=(uint8_t in) {
      return *this = **this & in;
    }
    EERef &operator |=(uint8_t in) {
      return *this = **this | in;
    }
    EERef &operator <<=(uint8_t in) {
      return *this = **this << in;
    }
    EERef &operator >>=(uint8_t in) {
      return *this = **this >> in;
    }

    EERef &update( uint8_t in ) {
      return  in != *this ? *this = in : *this;
    }

    /** Prefix increment/decrement **/
    EERef& operator++() {
      return *this += 1;
    }
    EERef& operator--() {
      return *this -= 1;
    }

    /** Postfix increment/decrement **/
    uint8_t operator++ (int) {
      uint8_t ret = **this;
      return ++(*this), ret;
    }
    uint8_t operator-- (int) {
      uint8_t ret = **this;
      return --(*this), ret;
    }
    int index; //Index of current EEPROM cell.
};

class EEPtr {
  public:
    EEPtr( const int index ): index( index ) {}

    operator const int() const {
      return index;
    }
    EEPtr &operator=(int in) {
      return index = in, *this;
    }

    //Iterator functionality.
    bool operator!=( const EEPtr &ptr ) {
      return index != ptr.index;
    }
    EERef operator* () {
      return index;
    }

    /** Prefix & Postfix increment/decrement **/
    EEPtr& operator++() {
      return ++index, *this;
    }
    EEPtr& operator--() {
      return --index, *this;
    }
    EEPtr operator++ (int) {
      return index++;
    }
    EEPtr operator-- (int) {
      return index--;
    }
    int index; //Index of current EEPROM cell.
};

class EXTEEPROM : public WARE {
  public:
    uint8_t devAdr;
    uint16_t devType;

    EXTEEPROM(ARDUINOPIN_TypeDef sda = AT24CXX_SDA, ARDUINOPIN_TypeDef scl = AT24CXX_SCL, uint8_t devAdr = 0x50, uint16_t devType = AT24C02)
      : WARE(sda, scl), devAdr(devAdr), devType(devType) {}
    ~EXTEEPROM() {}

    uint8_t read_byte(uint16_t address)
    {
      WARE::beginTransmission(devAdr);    // transmit to device #80(0x50)

      if (devType > AT24C16)	             //for 16bit address
        WARE::write(byte(address >> 8));   // high address

      WARE::write(byte(address & 0xff));   //low address
      WARE::endTransmission(); 			// stop transmitting
      WARE::requestFrom(byte(devAdr), byte(1));    	// request 1 bytes from slave device #80(0x50)
      delay(2);
      return  WARE::read();  		// receive high byte (overwrites previous reading)
    }
    inline uint8_t read(uint16_t address) {
      return read_byte(address);
    }
    void write_byte(uint16_t address, uint8_t val)
    {
      WARE::beginTransmission(devAdr); // transmit to device #80(0x50)
      if (devType > AT24C16)
        WARE::write(address >> 8); 		// high address
      WARE::write(address & 0xff);  			// low address
      WARE::write(val);  				// data
      WARE::endTransmission();
      delay(2);
    }
    size_t  write(uint16_t address, uint8_t val) {
      write_byte(address, val); return 1;
    };

    EERef operator[](const int idx) {
      return idx;
    }
    uint32_t length() {
      return devType + 1;
    }

#if 0
    uint8_t read(int idx ) {
      return EERef(idx);
    }
    void write(int idx, uint8_t val) {
      (EERef(idx)) = val;
    }
    void update( int idx, uint8_t val) {
      EERef( idx ).update( val );
    }

    //STL and C++11 iteration capability.
    EEPtr begin() {
      return 0x00;
    }
    EEPtr end() {
      return length(); //Standards requires this to be the item after the last valid entry. The returned pointer is invalid.
    }
    //Functionality to 'get' and 'put' objects to and from EEPROM.
    template< typename T > T &get( int idx, T & t ) {
      EEPtr e = idx;
      uint8_t *ptr = (uint8_t*) &t;
      for ( int count = sizeof(T) ; count ; --count, ++e )  *ptr++ = *e;
      return t;
    }
    template< typename T > const T &put( int idx, const T & t ) {
      EEPtr e = idx;
      const uint8_t *ptr = (const uint8_t*) &t;
      for ( int count = sizeof(T) ; count ; --count, ++e )  (*e).update( *ptr++ );
      return t;
    }
#endif
};

#endif

