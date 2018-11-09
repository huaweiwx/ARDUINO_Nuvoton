/*
  EEPROM.cpp - EEPROM library
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

/******************************************************************************
 * Includes
 ******************************************************************************/
 
#include "Arduino.h"
#include "EEPROM.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * Constructors
 ******************************************************************************/

/******************************************************************************
 * User API
 ******************************************************************************/
EEPROMClass::EEPROMClass()
{
	 Wire.begin();
}

uint8_t EEPROMClass::read(int address)
{
			uint8_t reading;     			
  		Wire.beginTransmission(0x50); // transmit to device #80(0x50)
      Wire.write(byte(address>>8)); // high address
      Wire.write(byte(address)); 		//low address
      Wire.endTransmission(); 			// stop transmitting
      			       
      Wire.requestFrom(80, 1);    	// request 1 bytes from slave device #80(0x50)      
      delay(2);
      // receive reading from sensor
      if( Wire.available() >=1)    	// if two bytes were received      
        reading = Wire.read();  		// receive high byte (overwrites previous reading)                       
      return reading; 
}

void EEPROMClass::write(int address, uint8_t value)
{
		Wire.beginTransmission(80); // transmit to device #80(0x50)
    Wire.write(address>>8); 		// high address
    Wire.write(address);  			// low address
    Wire.write(value);  				// data
    Wire.endTransmission();
}

EEPROMClass EEPROM;
