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
#include "Arduino.h"

#ifdef __cplusplus
 extern "C" {
#endif


extern void pinMode(uint8_t ucPin, uint32_t ulMode )
{
#ifdef USE_BoardToPin
	if(ucPin > BoardToPin_MAX_COUNT) return;
	if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else
    if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL) return;
#endif  
    GPIO_Config(GPIO_Desc[ucPin]); 
	GPIO_SetMode(GPIO_Desc[ucPin].P, GPIO_Desc[ucPin].bit, ulMode); 
}

extern void digitalWriteHigh(uint8_t ucPin)
{
#ifdef USE_BoardToPin
	if(ucPin > BoardToPin_MAX_COUNT) return;
	if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else	
	if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL) return;
#endif

	(GPIO_Desc[ucPin].P)->DOUT |= GPIO_Desc[ucPin].bit;	
}

extern void digitalWriteLow(uint8_t ucPin)
{
#ifdef USE_BoardToPin
	if(ucPin > BoardToPin_MAX_COUNT) return;
	if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else	
	if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL) return;
#endif
		
	(GPIO_Desc[ucPin].P)->DOUT &= ~GPIO_Desc[ucPin].bit;
}

extern void digitalWrite(uint8_t ucPin, uint8_t ucVal )
{
	if(ucVal)
		digitalWriteHigh(ucPin);	
	else
		digitalWriteLow(ucPin);;
}

extern int digitalRead(uint8_t ucPin )
{
#ifdef USE_BoardToPin
	if(ucPin > BoardToPin_MAX_COUNT) return;     
	if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else	
	if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL) return LOW;
#endif
	return ((GPIO_Desc[ucPin].P)->PIN & GPIO_Desc[ucPin].bit)?HIGH:LOW;
}


extern void digitalToggle(uint8_t ucPin)  //add 2015.6 by huawei
{
#ifdef USE_BoardToPin
	if(ucPin > BoardToPin_MAX_COUNT) return;
	if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else	
	if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P == NULL) return;
#endif
	((GPIO_T *)(GPIO_Desc[ucPin].P))->DOUT ^= GPIO_Desc[ucPin].bit;	
}

#ifdef __cplusplus
}
#endif

