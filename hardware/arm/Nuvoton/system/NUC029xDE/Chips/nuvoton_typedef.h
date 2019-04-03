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
/* Types used for the tables below */
typedef struct _PinType
{
   uint32_t num;
   uint32_t type;
   uint32_t AMsk;
// uint32_t AMsk1;
   uint32_t AMsk2;
   uint32_t AMsk3;
   uint32_t AMsk4;
} PinType;

typedef struct _PinDescription
{
   uint32_t MFP;
   uint32_t Mask;
   uint32_t ALTMsk;
// uint32_t ALT1Msk;
   uint32_t ALT2Msk;
   uint32_t ALT3Msk;
   uint32_t ALT4Msk;
   uint32_t Type;
} PinDescription;

typedef struct _GPIOPinDescription
{
   GPIO_T *P;
   uint32_t bit;
   PinDescription Pin;
} GPIOPinDescription;

typedef struct _ADCPinDescription
{
	ADC_T *A;
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

typedef struct _SPIPinAlt
{
	PinType clk;
	PinType mosi;
	PinType miso;
	PinType ss;
} SPIPinAlt_TypeDef;
typedef struct _SPIPinDescription
{
	SPI_T *S;
	uint32_t module;
	IRQn_Type irq;
	uint32_t clksel;
	const SPIPinAlt_TypeDef* pinAlt;
} SPIPinDescription;

typedef struct _UARTPinAlt
{
	PinType rxd;
	PinType txd;
} UARTPinAlt_TypeDef;
typedef struct _UARTPinDescription
{
	UART_T *U;
	uint32_t module;
	IRQn_Type irq;
	const UARTPinAlt_TypeDef* pinAlt;
} UARTPinDescription;

typedef struct _I2CPinAlt
{
	PinType scl;
	PinType sda;
} I2CPinAlt_TypeDef;
typedef struct _I2CPinDescription
{
	I2C_T *I;
	uint32_t module;
	IRQn_Type irq;
	const I2CPinAlt_TypeDef* pinAlt;
} I2CPinDescription;


#ifdef USE_BoardToPin
typedef struct _BoardToPin
{
    int32_t pin;
    uint8_t type;
    uint8_t num;
} BoardToPin;
  
  #define GPIO_TYPE   0
  #define UART_TYPE   1
  #define I2C_TYPE    2
  #define SPI_TYPE	  3
  #define ADC_TYPE	  4
  #define PWM_TYPE	  5
  #define CAN_TYPE	  6
  
#define BoardToPin_MAX_COUNT 81
extern BoardToPin BoardToPinInfo[];
#endif 

extern const GPIOPinDescription GPIO_Desc[];
#define GPIO_Config(Desc) \
  do { \
    outp32(Desc.Pin.MFP,(inp32(Desc.Pin.MFP) & ~Desc.Pin.Mask) | Desc.Pin.Type); \
    outp32(&SYS->ALT_MFP, (inp32(&SYS->ALT_MFP)  & ~Desc.Pin.ALTMsk));  \
    if(Desc.Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~Desc.Pin.ALT2Msk)); \
    if(Desc.Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~Desc.Pin.ALT3Msk)); \
    if(Desc.Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~Desc.Pin.ALT4Msk)); \
  }while(0)


#define PWM_MAX_COUNT 8
extern const PWMPinDescription PWM_Desc[];
#define PWM_Config(Desc) \
  do{ \
    outp32(GPIO_Desc[Desc.pintype.num].Pin.MFP,(inp32(GPIO_Desc[Desc.pintype.num].Pin.MFP) & ~GPIO_Desc[Desc.pintype.num].Pin.Mask) | Desc.pintype.type); \
    if(GPIO_Desc[Desc.pintype.num].Pin.ALTMsk != NULL) outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP) & ~GPIO_Desc[Desc.pintype.num].Pin.ALTMsk) | Desc.pintype.AMsk); \
    if(GPIO_Desc[Desc.pintype.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.pintype.num].Pin.ALT2Msk) | Desc.pintype.AMsk2); \
    if(GPIO_Desc[Desc.pintype.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.pintype.num].Pin.ALT3Msk) | Desc.pintype.AMsk3); \
    if(GPIO_Desc[Desc.pintype.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.pintype.num].Pin.ALT4Msk) | Desc.pintype.AMsk4); \
  }while(0)

#define ADC_MAX_COUNT 6
extern const ADCPinDescription ADC_Desc[];
#define ADC_Config(Desc) \
  do { \
    outp32(GPIO_Desc[Desc.pintype.num].Pin.MFP,(inp32(GPIO_Desc[Desc.pintype.num].Pin.MFP) & ~GPIO_Desc[Desc.pintype.num].Pin.Mask) | Desc.pintype.type); \
    if(GPIO_Desc[Desc.pintype.num].Pin.ALTMsk != NULL) outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP) & ~GPIO_Desc[Desc.pintype.num].Pin.ALTMsk) | Desc.pintype.AMsk); \
    if(GPIO_Desc[Desc.pintype.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.pintype.num].Pin.ALT2Msk) | Desc.pintype.AMsk2); \
    if(GPIO_Desc[Desc.pintype.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.pintype.num].Pin.ALT3Msk) | Desc.pintype.AMsk3); \
    if(GPIO_Desc[Desc.pintype.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.pintype.num].Pin.ALT4Msk) | Desc.pintype.AMsk4); \
  }while(0)

#define SPI_MAX_COUNT 2
extern const SPIPinDescription SPI_Desc[];
#define SPI_Config(Desc) \
  do { \
    outp32(GPIO_Desc[Desc.clk.num].Pin.MFP, (inp32(GPIO_Desc[Desc.clk.num].Pin.MFP) & ~GPIO_Desc[Desc.clk.num].Pin.Mask) | Desc.clk.type); \
    if(GPIO_Desc[Desc.clk.num].Pin.ALTMsk  != NULL)outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP)   & ~GPIO_Desc[Desc.clk.num].Pin.ALTMsk) | Desc.clk.AMsk); \
    if(GPIO_Desc[Desc.clk.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.clk.num].Pin.ALT2Msk) | Desc.clk.AMsk2); \
    if(GPIO_Desc[Desc.clk.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.clk.num].Pin.ALT3Msk) | Desc.clk.AMsk3); \
    if(GPIO_Desc[Desc.clk.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.clk.num].Pin.ALT4Msk) | Desc.clk.AMsk4); \
    outp32(GPIO_Desc[Desc.mosi.num].Pin.MFP,(inp32(GPIO_Desc[Desc.mosi.num].Pin.MFP) & ~GPIO_Desc[Desc.mosi.num].Pin.Mask) | Desc.mosi.type); \
    if(GPIO_Desc[Desc.mosi.num].Pin.ALTMsk  != NULL)outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP)   & ~GPIO_Desc[Desc.mosi.num].Pin.ALTMsk) | Desc.mosi.AMsk); \
    if(GPIO_Desc[Desc.mosi.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.mosi.num].Pin.ALT2Msk) | Desc.mosi.AMsk2); \
    if(GPIO_Desc[Desc.mosi.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.mosi.num].Pin.ALT3Msk) | Desc.mosi.AMsk3); \
    if(GPIO_Desc[Desc.mosi.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.mosi.num].Pin.ALT4Msk) | Desc.mosi.AMsk4); \
    outp32(GPIO_Desc[Desc.miso.num].Pin.MFP,(inp32(GPIO_Desc[Desc.miso.num].Pin.MFP) & ~GPIO_Desc[Desc.miso.num].Pin.Mask) | Desc.miso.type); \
    if(GPIO_Desc[Desc.miso.num].Pin.ALTMsk  != NULL)outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP)   & ~GPIO_Desc[Desc.miso.num].Pin.ALTMsk) | Desc.miso.AMsk); \
    if(GPIO_Desc[Desc.miso.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.miso.num].Pin.ALT2Msk) | Desc.miso.AMsk2); \
    if(GPIO_Desc[Desc.miso.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.miso.num].Pin.ALT3Msk) | Desc.miso.AMsk3); \
    if(GPIO_Desc[Desc.miso.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.miso.num].Pin.ALT4Msk) | Desc.miso.AMsk4); \
    out32(GPIO_Desc[Desc.ss.num].Pin.MFP,  (inp32(GPIO_Desc[Desc.ss.num].Pin.MFP) & ~GPIO_Desc[Desc.ss.num].Pin.Mask) | Desc.ss.type); \
    if(GPIO_Desc[Desc.ss.num].Pin.ALTMsk  != NULL)outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP)   & ~GPIO_Desc[Desc.ss.num].Pin.ALTMsk) | Desc.ss.AMsk); \
    if(GPIO_Desc[Desc.ss.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.ss.num].Pin.ALT2Msk) | Desc.ss.AMsk2); \
    if(GPIO_Desc[Desc.ss.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.ss.num].Pin.ALT3Msk) | Desc.ss.AMsk3); \
    if(GPIO_Desc[Desc.ss.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.ss.num].Pin.ALT4Msk) | Desc.ss.AMsk4); \
  }while(0)

#define UART_MAX_COUNT 4
extern const UARTPinDescription UART_Desc[];
#define UART_RX 0
#define UART_TX 1
#define UART_Config(Desc) \
  do { \
    outp32(GPIO_Desc[Desc.rxd.num].Pin.MFP,(inp32(GPIO_Desc[Desc.rxd.num].Pin.MFP) & ~GPIO_Desc[Desc.rxd.num].Pin.Mask) | Desc.rxd.type); \
    if(GPIO_Desc[Desc.rxd.num].Pin.ALTMsk  != NULL)outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP)   & ~GPIO_Desc[Desc.rxd.num].Pin.ALTMsk) | Desc.rxd.AMsk); \
    if(GPIO_Desc[Desc.rxd.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.rxd.num].Pin.ALT2Msk) | Desc.rxd.AMsk2); \
    if(GPIO_Desc[Desc.rxd.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.rxd.num].Pin.ALT3Msk) | Desc.rxd.AMsk3); \
    if(GPIO_Desc[Desc.rxd.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.rxd.num].Pin.ALT4Msk) | Desc.rxd.AMsk4); \
    outp32(GPIO_Desc[Desc.txd.num].Pin.MFP,(inp32(GPIO_Desc[Desc.txd.num].Pin.MFP) & ~GPIO_Desc[Desc.txd.num].Pin.Mask) | Desc.txd.type); \
    if(GPIO_Desc[Desc.txd.num].Pin.ALTMsk  != NULL)outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP)   & ~GPIO_Desc[Desc.txd.num].Pin.ALTMsk) | Desc.txd.AMsk); \
    if(GPIO_Desc[Desc.txd.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.txd.num].Pin.ALT2Msk) | Desc.txd.AMsk2); \
    if(GPIO_Desc[Desc.txd.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.txd.num].Pin.ALT3Msk) | Desc.txd.AMsk3); \
    if(GPIO_Desc[Desc.txd.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.txd.num].Pin.ALT4Msk) | Desc.txd.AMsk4); \
  }while(0)


#define I2C_MAX_COUNT 2

extern const I2CPinDescription I2C_Desc[];
#define I2C_Config(Desc) \
  do { \
      outp32(GPIO_Desc[Desc.sda.num].Pin.MFP,(inp32(GPIO_Desc[Desc.sda.num].Pin.MFP) & ~GPIO_Desc[Desc.sda.num].Pin.Mask) | Desc.sda.type); \
      if(GPIO_Desc[Desc.sda.num].Pin.ALTMsk  != NULL)outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP)   & ~GPIO_Desc[Desc.sda.num].Pin.ALTMsk) | Desc.sda.AMsk); \
      if(GPIO_Desc[Desc.sda.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.sda.num].Pin.ALT2Msk) | Desc.sda.AMsk2); \
      if(GPIO_Desc[Desc.sda.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.sda.num].Pin.ALT3Msk) | Desc.sda.AMsk3); \
      if(GPIO_Desc[Desc.sda.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.sda.num].Pin.ALT4Msk) | Desc.sda.AMsk4); \
      outp32(GPIO_Desc[Desc.scl.num].Pin.MFP,(inp32(GPIO_Desc[Desc.scl.num].Pin.MFP) & ~GPIO_Desc[Desc.scl.num].Pin.Mask) | Desc.scl.type); \
      if(GPIO_Desc[Desc.scl.num].Pin.ALTMsk  != NULL)outp32(&SYS->ALT_MFP,(inp32(&SYS->ALT_MFP)   & ~GPIO_Desc[Desc.scl.num].Pin.ALTMsk) | Desc.scl.AMsk); \
      if(GPIO_Desc[Desc.scl.num].Pin.ALT2Msk != NULL)outp32(&SYS->ALT_MFP2,(inp32(&SYS->ALT_MFP2) & ~GPIO_Desc[Desc.scl.num].Pin.ALT2Msk) | Desc.scl.AMsk2); \
      if(GPIO_Desc[Desc.scl.num].Pin.ALT3Msk != NULL)outp32(&SYS->ALT_MFP3,(inp32(&SYS->ALT_MFP3) & ~GPIO_Desc[Desc.scl.num].Pin.ALT3Msk) | Desc.scl.AMsk3); \
      if(GPIO_Desc[Desc.scl.num].Pin.ALT4Msk != NULL)outp32(&SYS->ALT_MFP4,(inp32(&SYS->ALT_MFP4) & ~GPIO_Desc[Desc.scl.num].Pin.ALT4Msk) | Desc.scl.AMsk4); \
  }while(0)


#endif /*_NUVOTON_TYPEDEF_H_*/