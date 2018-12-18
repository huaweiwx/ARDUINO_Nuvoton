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


void pinMode(uint8_t ucPin, uint32_t ulMode)
{
#ifdef USE_BoardToPin
	assert_param(!(ucPin > BoardToPin_MAX_COUNT));   //if(ucPin > BoardToPin_MAX_COUNT) return;
	assert_param(!(BoardToPinInfo[ucPin].pin == -1));//if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else	
	assert_param(!(ucPin>=NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL));//if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL) return;
#endif

    GPIO_Config(GPIO_Desc[ucPin]); 
	GPIO_SetMode(GPIO_Desc[ucPin].P, GPIO_Desc[ucPin].bit, ulMode & 0b11); 

#ifdef GPIO_PUSEL_PULL_UP  //M480
	if(ulMode == INPUT_PULLUP){
		GPIO_SetPullCtl(GPIO_Desc[ucPin].P, GPIO_Desc[ucPin].bit,GPIO_PUSEL_PULL_UP); 
    } else if(ulMode == INPUT_PULLDOWN){
		GPIO_SetPullCtl(GPIO_Desc[ucPin].P, GPIO_Desc[ucPin].bit,GPIO_PUSEL_PULL_DOWN); 
    } else if(ulMode == INPUT){
		GPIO_SetPullCtl(GPIO_Desc[ucPin].P, GPIO_Desc[ucPin].bit,GPIO_PUSEL_DISABLE); 
    }
#elif defined(GPIO_ENABLE_PULL_UP)  /*NANO*/
	if(ulMode == INPUT_PULLUP){
		GPIO_ENABLE_PULL_UP(GPIO_Desc[ucPin].P, GPIO_Desc[ucPin].bit); 
    } else if(ulMode == INPUT){
		GPIO_DISABLE_PULL_UP(GPIO_Desc[ucPin].P, GPIO_Desc[ucPin].bit);
	}
#endif
}

void digitalWriteHigh(uint8_t ucPin)
{
#ifdef USE_BoardToPin
	assert_param(!(ucPin > BoardToPin_MAX_COUNT));   //if(ucPin > BoardToPin_MAX_COUNT) return;
	assert_param(!(BoardToPinInfo[ucPin].pin == -1));//if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else	
	assert_param(!(ucPin>=NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL));//if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL) return;
#endif
	(GPIO_Desc[ucPin].P)->DOUT |= GPIO_Desc[ucPin].bit;	
}

void digitalWriteLow(uint8_t ucPin)
{
#ifdef USE_BoardToPin
	assert_param(!(ucPin > BoardToPin_MAX_COUNT));   //if(ucPin > BoardToPin_MAX_COUNT) return;
	assert_param(!(BoardToPinInfo[ucPin].pin == -1));//if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else	
	assert_param(!(ucPin>=NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL));//if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL) return;
#endif
		
	(GPIO_Desc[ucPin].P)->DOUT &= ~GPIO_Desc[ucPin].bit;
}

void digitalWrite(uint8_t ucPin, uint8_t ucVal)
{
	if(ucVal)
		digitalWriteHigh(ucPin);	
	else
		digitalWriteLow(ucPin);
}

int digitalRead(uint8_t ucPin)
{
#ifdef USE_BoardToPin
	assert_param(!(ucPin > BoardToPin_MAX_COUNT));   //if(ucPin > BoardToPin_MAX_COUNT) return;
	assert_param(!(BoardToPinInfo[ucPin].pin == -1));//if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else	
	assert_param(!(ucPin>=NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL));//if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL) return;
#endif
	return ((GPIO_Desc[ucPin].P)->PIN & GPIO_Desc[ucPin].bit)?HIGH:LOW;
}


void digitalToggle(uint8_t ucPin)  //add 2015.6 by huawei
{
#ifdef USE_BoardToPin
	assert_param(!(ucPin > BoardToPin_MAX_COUNT));   //if(ucPin > BoardToPin_MAX_COUNT) return;
	assert_param(!(BoardToPinInfo[ucPin].pin == -1));//if(BoardToPinInfo[ucPin].pin == -1) return;
	ucPin=BoardToPinInfo[ucPin].pin;
#else	
	assert_param(!(ucPin>=NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL));//if(ucPin>NUM_DIGITAL_PINS || GPIO_Desc[ucPin].P==NULL) return;
#endif
	((GPIO_T *)(GPIO_Desc[ucPin].P))->DOUT ^= GPIO_Desc[ucPin].bit;	
}

