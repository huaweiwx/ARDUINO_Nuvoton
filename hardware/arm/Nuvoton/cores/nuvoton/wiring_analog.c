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

static int _readResolution = 10;
static int _writeResolution = 8;

void analogReadResolution(int res) {
	_readResolution = res;
}

void analogWriteResolution(int res) {
	_writeResolution = res;
}

static inline uint32_t mapResolution(uint32_t value, uint32_t from, uint32_t to) {
	if (from == to)
		return value;
	if (from > to)
		return (value >> (from-to));
	else
		return (value << (to-from));
}

eAnalogReference analog_reference = AR_DEFAULT;

void analogReference(eAnalogReference ulMode)
{
	analog_reference = ulMode;
}

uint32_t analogRead(uint8_t ucPin)
{
 /*volatile*/ uint32_t ulValue = 0;
    if(ucPin>ADC_MAX_COUNT || ADC_Desc[ucPin].A==NULL) return 0;  	  


#if defined(__M451__)||defined(M480)   

  	  	
	/* Disable the digital input path to avoid the leakage current. */
    GPIO_DISABLE_DIGITAL_PATH(GPIO_Desc[ADC_Desc[ucPin].pintype.num].P,GPIO_Desc[ADC_Desc[ucPin].pintype.num].bit);
   
    ADC_Config(ADC_Desc[ucPin]);
  
	/* Set the ADC internal sampling time, input mode as single-end and enable the A/D converter */
	EADC_Open(ADC_Desc[ucPin].A, EADC_CTL_DIFFEN_SINGLE_END);
	EADC_SetInternalSampleTime(EADC, 6);
	
	/* Configure the sample 0 module for analog input channel 0 and enable ADINT0 trigger source */
	EADC_ConfigSampleModule(EADC,ADC_Desc[ucPin].ch, EADC_ADINT0_TRIGGER, ADC_Desc[ucPin].ch);
	
	/* Clear the A/D ADINT0 interrupt flag for safe */
	EADC_CLR_INT_FLAG(EADC, 0x1);
	
	/* Enable sample module interrupt */
	EADC_ENABLE_SAMPLE_MODULE_INT(EADC, 0, (0x1 << ADC_Desc[ucPin].ch));
	
	/* Trigger sample module to start A/D conversion */
	EADC_START_CONV(EADC, (0x1 << ADC_Desc[ucPin].ch));
	
	while(!(EADC_GET_INT_FLAG(EADC,0x1)));
  
    ulValue=EADC_GET_CONV_DATA(EADC, ADC_Desc[ucPin].ch);
  
 	/* Wait conversion done */
 	while(((uint32_t)EADC_GET_DATA_VALID_FLAG(EADC, (0x1 << ADC_Desc[ucPin].ch))) != ((uint32_t)(0x1 << ADC_Desc[ucPin].ch)));
	
	/* Disable the sample module interrupt */
	EADC_DISABLE_SAMPLE_MODULE_INT(EADC, 0, (1<<ADC_Desc[ucPin].ch));
	
	ulValue=EADC_GET_CONV_DATA(EADC, ADC_Desc[ucPin].ch);
	ulValue = mapResolution(ulValue, 12, _readResolution);

	// Close ADC
	EADC_Close(ADC_Desc[ucPin].A);
#elif defined(__NANO100__) | defined(__NANO1X2__)
	ADC_Config(ADC_Desc[ucPin]);
  
  //GPIO_ENABLE_DIGITAL_PATH(GPIO_Desc[ADC_Desc[ucPin].pintype.num].P,GPIO_Desc[ADC_Desc[ucPin].pintype.num].bit);
  
  // Enable channel 
	ADC_Open(ADC_Desc[ucPin].A, ADC_INPUT_MODE_SINGLE_END, ADC_OPERATION_MODE_SINGLE, (1<<ADC_Desc[ucPin].ch));
	
	// Power on ADC
	ADC_POWER_ON(ADC_Desc[ucPin].A);

  // Wait for busy of conversion
  while(ADC_IS_BUSY(ADC_Desc[ucPin].A));	
  	
  // Start for conversion	
  ADC_START_CONV(ADC_Desc[ucPin].A);
  		
	// Wait for end of conversion
	while(!ADC_GET_INT_FLAG(ADC_Desc[ucPin].A,ADC_ADF_INT));
	
	// Clear ADC flag
	ADC_CLR_INT_FLAG(ADC_Desc[ucPin].A,ADC_ADF_INT);
	
	// Read the value
	ulValue = ADC_GET_CONVERSION_DATA(ADC_Desc[ucPin].A,ADC_Desc[ucPin].ch);	
	ulValue = mapResolution(ulValue, 12, _readResolution);
  
  //GPIO_DISABLE_DIGITAL_PATH(GPIO_Desc[ADC_Desc[ucPin-1].pintype.num].P,GPIO_Desc[ADC_Desc[ucPin].pintype.num-1].bit);
  
  // Close ADC
  ADC_Close(ADC_Desc[ucPin].A);
#elif defined(__NUC240__)
  	
	ADC_Config(ADC_Desc[ucPin]);
  
	//GPIO_ENABLE_DIGITAL_PATH(GPIO_Desc[ADC_Desc[ucPin].pintype.num].P,GPIO_Desc[ADC_Desc[ucPin].pintype.num].bit);
  
	// Enable channel 0
	ADC_Open(ADC_Desc[ucPin].A, 0, 0, (1<<ADC_Desc[ucPin].ch));
		
	// Power on ADC
	ADC_POWER_ON(ADC_Desc[ucPin].A);

	// Wait for busy of conversion
	while(ADC_IS_BUSY(ADC_Desc[ucPin].A));	
  	
	// Start for conversion	
	ADC_START_CONV(ADC_Desc[ucPin].A);
  		
	// Wait for end of conversion
	while(!ADC_GET_INT_FLAG(ADC_Desc[ucPin].A,ADC_ADF_INT));
	
	// Clear ADC flag
	ADC_CLR_INT_FLAG(ADC_Desc[ucPin].A,ADC_ADF_INT);
	
	// Read the value
	ulValue = ADC_GET_CONVERSION_DATA(ADC_Desc[ucPin].A,ADC_Desc[ucPin].ch);	
	ulValue = mapResolution(ulValue, 12, _readResolution);
  
	//GPIO_DISABLE_DIGITAL_PATH(GPIO_Desc[ADC_Desc[ucPin-1].pintype.num].P,GPIO_Desc[ADC_Desc[ucPin].pintype.num-1].bit);
  
	// Close ADC
	ADC_Close(ADC_Desc[ucPin].A);
#else //if defined(__NUC131__)||defined(Mini58Series)|| defined(Mini51Series)||defined(M051Series)||defined(M058S)

  #ifndef ADC_ADF_INT
     #define ADC_ADF_INT ADC_ADIF_INT   /*Mini58*/
  #endif
  
  ADC_Config(ADC_Desc[ucPin]);
  
  //GPIO_ENABLE_DIGITAL_PATH(GPIO_Desc[ADC_Desc[ucPin].pintype.num].P,GPIO_Desc[ADC_Desc[ucPin].pintype.num].bit);
  
  // Enable channel 0
	ADC_Open(ADC_Desc[ucPin].A, 0, 0, (1<<ADC_Desc[ucPin].ch));
		
	// Power on ADC
	ADC_POWER_ON(ADC_Desc[ucPin].A);

  // Wait for busy of conversion
  while(ADC_IS_BUSY(ADC_Desc[ucPin].A));	
  	
  // Start for conversion	
  ADC_START_CONV(ADC_Desc[ucPin].A);
  		
	// Wait for end of conversion
	while(!ADC_GET_INT_FLAG(ADC_Desc[ucPin].A,ADC_ADF_INT));
	
	// Clear ADC flag
	ADC_CLR_INT_FLAG(ADC_Desc[ucPin].A,ADC_ADF_INT);
	
	// Read the value
	ulValue = ADC_GET_CONVERSION_DATA(ADC_Desc[ucPin].A,ADC_Desc[ucPin].ch);	
	ulValue = mapResolution(ulValue, 12, _readResolution);
  
  //GPIO_DISABLE_DIGITAL_PATH(GPIO_Desc[ADC_Desc[ucPin-1].pintype.num].P,GPIO_Desc[ADC_Desc[ucPin].pintype.num-1].bit);
  
  // Close ADC
  ADC_Close(ADC_Desc[ucPin].A);
#endif
  return ulValue;	
}

// Right now, PWM output only works on the pins with
// hardware support.  These are defined in the appropriate
// pins_*.c file.  For the rest of the pins, we default
// to digital output.
//static uint8_t PWMEnabled = 0;
static uint8_t pinEnabled[PWM_MAX_COUNT]={0};
static uint32_t fixValue[PWM_MAX_COUNT]={0};
void analogWrite(uint8_t ucPin, uint32_t ulValue) {
	
#ifdef USE_BoardToPin
	if(ucPin > BoardToPin_MAX_COUNT) return;
	if(BoardToPinInfo[ucPin].type!=PWM_TYPE) return;
	ucPin=BoardToPinInfo[ucPin].num;
#else
	if(ucPin>PWM_MAX_COUNT || PWM_Desc[ucPin].P==NULL) return;
#endif
	
	ulValue = mapResolution(ulValue, _writeResolution, 8);
	
	ulValue=((ulValue+1)*100)/(1<<_writeResolution);
#if defined(__M451__)||defined(M480)   
	if(ulValue==100)
	{  
		int32_t pin=PWM_Desc[ucPin].pintype.num;
		GPIO_Config(GPIO_Desc[pin]);
		GPIO_SetMode(GPIO_Desc[pin].P, GPIO_Desc[pin].bit, GPIO_MODE_OUTPUT);
		(GPIO_Desc[pin].P)->DOUT |= GPIO_Desc[pin].bit;
		pinEnabled[ucPin]= 0;
		fixValue[ucPin]=ulValue;
		return;
	}
#elif defined(__NUC240__)
	if(ulValue==0)
	{  
		int32_t pin=PWM_Desc[ucPin].pintype.num;
		GPIO_Config(GPIO_Desc[pin]);
		GPIO_SetMode(GPIO_Desc[pin].P, GPIO_Desc[pin].bit, GPIO_PMD_OUTPUT);
		(GPIO_Desc[pin].P)->DOUT &= ~GPIO_Desc[pin].bit;
		pinEnabled[ucPin]= 0;
		fixValue[ucPin]=ulValue;
		return;
	}
#elif defined(__NANO100__) | defined(__NANO1X2__)
	if(ulValue==0)
	{  
		int32_t pin=PWM_Desc[ucPin].pintype.num;
		GPIO_Config(GPIO_Desc[pin]);
		GPIO_SetMode(GPIO_Desc[pin].P, GPIO_Desc[pin].bit, GPIO_PMD_OUTPUT);
		(GPIO_Desc[pin].P)->DOUT &= ~GPIO_Desc[pin].bit;
		pinEnabled[ucPin]= 0;
		fixValue[ucPin]=ulValue;
		return;
	}
#elif defined(__NUC131__)
	if(ulValue==0)
	{  
		int32_t pin=PWM_Desc[ucPin].pintype.num;
		GPIO_Config(GPIO_Desc[pin]);
		GPIO_SetMode(GPIO_Desc[pin].P, GPIO_Desc[pin].bit, GPIO_PMD_OUTPUT);
		(GPIO_Desc[pin].P)->DOUT &= ~GPIO_Desc[pin].bit;
		pinEnabled[ucPin]= 0;
		fixValue[ucPin]=ulValue;
		return;
	}
#endif	
			
	if (!pinEnabled[ucPin]){
		//Set Mutifunction pins
		PWM_Config(PWM_Desc[ucPin]);		
    
		//Config PWMs
		PWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,PWM_Desc[ucPin].freq,ulValue);
		
		//Enable PWM output
		PWM_EnableOutput(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
		
		//Start PWM
		PWM_Start(PWM_Desc[ucPin].P,(1<<PWM_Desc[ucPin].ch));
		
		pinEnabled[ucPin] = 1;
	}
	
	//Config PWMs		
	if(fixValue[ucPin]!=ulValue)
	{
		PWM_ConfigOutputChannel(PWM_Desc[ucPin].P,PWM_Desc[ucPin].ch,PWM_Desc[ucPin].freq,ulValue);
		fixValue[ucPin]=ulValue;
	}

	
	return;
}

#ifdef __cplusplus
}
#endif
