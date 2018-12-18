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

#if USE_WARESOFT > 0
#include "WireSoft.h"
# define  WARE  TwoWireSoft
#elif  AT24CXX_DEV >0
#include "Wire.h"
# define  WARE  TwoWire
#else
#error "support hardware iic port?  undefined  exteeprom iic device, check file variat/config/i2cEepromConfig.h"
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

template<const uint8_t devAdr = 0x50, const uint16_t devType = AT24C02>
class EXTEEPROM : public WARE {
  public:
    //    uint8_t     devAdr;
    //    uint16_t    devType;
#if USE_WARESOFT>0
   EXTEEPROM(__ConstPin sda = AT24CXX_SDA, __ConstPin scl = AT24CXX_SCL, uint8_t delay = SOFT_STANDARD): WARE(sda, scl, delay) {}
#else
   EXTEEPROM(__ConstPin sda = AT24CXX_SDA, __ConstPin scl = AT24CXX_SCL): WARE(sda, scl) {}
#endif
    uint8_t read(uint16_t address)
    {
      WARE::beginTransmission(devAdr);    // transmit to device #80(0x50)

      if (devType > AT24C16)	             //for 16bit address
        WARE::write(byte(address >> 8));   // high address

      WARE::write(byte(address & 0xff));   //low address
      WARE::endTransmission(); 			// stop transmitting
      WARE::requestFrom(byte(devAdr),byte(1));    	// request 1 bytes from slave device #80(0x50)
      delay(2);
      return  WARE::read();  		// receive high byte (overwrites previous reading)
    }

    size_t write(uint16_t address, uint8_t value)
    {
      WARE::beginTransmission(devAdr); // transmit to device #80(0x50)
      if (devType > AT24C16)
        WARE::write(address >> 8); 		// high address
      WARE::write(address & 0xff);  			// low address
      WARE::write(value);  				// data
      WARE::endTransmission();
      delay(2);
      return 1;
    }

    ~EXTEEPROM() {};
};

//extern EEPROMClass EXTEEPROM;

#endif

