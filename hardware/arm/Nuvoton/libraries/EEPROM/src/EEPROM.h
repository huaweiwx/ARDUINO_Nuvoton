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
*/

#ifndef EEPROM_h
#define EEPROM_h

#include <inttypes.h>
#include "Wire.h"

template<class T_WIRE_METHOD> class EEPROMClass
{
  public:
  	EEPROMClass(T_WIRE_METHOD& wire): 
	        _wire(wire)
    {
	}

	void Init(void){
	   _wire.begin();
	}

    uint8_t read(int address){
	  uint8_t reading = 0;     			
  	  _wire.beginTransmission(0x50); // transmit to device #80(0x50)
      _wire.write(byte(address>>8)); // high address
      _wire.write(byte(address)); 	//low address
      _wire.endTransmission(); 		// stop transmitting
      			       
      _wire.requestFrom(80, 1);    	// request 1 bytes from slave device #80(0x50)      
      delay(2);
      // receive reading from sensor
      if( _wire.available() >=1)    	// if two bytes were received      
        reading = _wire.read();  	// receive high byte (overwrites previous reading)
		
      return reading; 
	};

    void write(int address, uint8_t value)
    {
	  _wire.beginTransmission(80); 	// transmit to device #80(0x50)
      _wire.write(address>>8); 		// high address
      _wire.write(address);  		// low address
      _wire.write(value);  			// data
      _wire.endTransmission();
    }
	
private:
    T_WIRE_METHOD& _wire;
};

#endif
