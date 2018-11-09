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
#ifndef _NUVOTON_TYPEDEF_H_
#define _NUVOTON_TYPEDEF_H_

//#define USE_BoardToPin

/* Types used for the tables below */
typedef struct _PinType
{
  uint32_t num;
  uint32_t type;
} PinType;

typedef struct _PinDescription
{
  uint32_t MFP;
  uint32_t Mask;
#if defined(__NUC240__)
  uint32_t ALTMsk;
  uint32_t ALT1Msk;
  uint32_t ALT2Msk;
#elif defined(__NUC131__)
  uint32_t ALTMsk;
  uint32_t ALT2Msk;
  uint32_t ALT3Msk;
  uint32_t ALT4Msk;
#endif
  uint32_t Type;
} PinDescription;

typedef struct _GPIOPinDescription
{
  GPIO_T *P;
  uint32_t bit;
  PinDescription Pin;
} GPIOPinDescription;

typedef struct _GPIOPortDescription
{
  GPIO_T *P;
  uint32_t Pins;
  uint32_t MFP;  
  uint32_t Mask;
  uint32_t Type;
//  PinDescription Pin;
} GPIOPortDescription;

typedef struct _ADCPinDescription
{
#if defined(EADC /*__M451__*/)
  EADC_T *A;
#else // defined (__NUC131__) | defined(__NUC240__) | defined(__NANO100__) | defined(__NANO1X2__)
  ADC_T *A;
#endif
  uint32_t module;
  uint32_t ch;
  PinType pintype;
} ADCPinDescription;

typedef struct _PWMPinDescription
{
  PWM_T *P;
  uint32_t module;
  IRQn_Type irq;
  uint32_t ch;
  uint32_t freq;
  PinType pintype;
} PWMPinDescription;

typedef struct _SPIPinDescription
{
  SPI_T *S;
  uint32_t module;
  IRQn_Type irq;
  uint32_t clksel;
  PinType pintype[4];
} SPIPinDescription;

typedef struct _UARTPinDescription
{
  UART_T *U;
  uint32_t module;
  IRQn_Type irq;
  PinType pintype[2];
} UARTPinDescription;

#if defined(CAN0) /* M451/NUC240*/
typedef struct _CANPinDescription
{
  CAN_T *C;
  uint32_t module;
  IRQn_Type irq;
  PinType pintype[2];
} CANPinDescription;
#endif

typedef struct _I2CPinDescription
{
  I2C_T *I;
  uint32_t module;
  PinType pintype[2];
} I2CPinDescription;


typedef struct _BoardToPin
{
  int32_t pin;
  uint8_t type;
  uint8_t num;
} BoardToPin;

#define BoardToPin_MAX_COUNT 81
extern BoardToPin BoardToPinInfo[];



#define GPIO_TYPE   0
#define UART_TYPE  	1
#define I2C_TYPE   	2
#define SPI_TYPE	3
#define ADC_TYPE	4
#define PWM_TYPE	5
#define CAN_TYPE	6
#define BoardToPin_MAX_COUNT 0x54

//extern BoardToPin BoardToPinInfo[];


extern const GPIOPinDescription GPIO_Desc[];
#define GPIO_Config(Desc)   /*outp32(Desc.MFP,(inp32(Desc.MFP) & ~Desc.Mask) | Desc.Type)*/


#define PWM_MAX_COUNT 8
extern const PWMPinDescription PWM_Desc[];
#define PWM_Config(Desc) 

#define ADC_MAX_COUNT 6
extern const ADCPinDescription ADC_Desc[];

#define SPI_MAX_COUNT 1
#define SPI_CHANNELS_NUM 1
extern const SPIPinDescription SPI_Desc[];
#define SPI_SCK   0
#define SPI_MOSI  1
#define SPI_MISO  2
#define SPI_SS    3
#define SPI_Config(Desc) 

#define UART_MAX_COUNT 1
extern const UARTPinDescription UART_Desc[];
#define UART_RX 0
#define UART_TX 1
#define UART_Config(Desc) 


#define I2C_MAX_COUNT 1

extern const I2CPinDescription I2C_Desc[];


#endif /*_NUVOTON_TYPEDEF_H_*/