/*
  variant48.h
  
  Copyright (c) 2018 huaweiwx@sina.com 2018.11.1

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
#pragma GCC diagnostic ignored "-Wconversion-null"
#define MFP_NULL {NULL, NULL, {NULL, NULL, NULL}}
#define MFP_PN(a,b) {P##a,BIT##b,{(uint32_t)&SYS->P##a##_MFP, \
                                  SYS_MFP_P##a##b##_Msk, \
					              SYS_MFP_P##a##b##_GPIO}}

#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  MFP_NULL    , // 0
  MFP_NULL    , // 1  NC
  MFP_PN(1, 5), // 2  AIN5/ACMP0_P
  MFP_NULL    , // 3  RESET
  MFP_PN(3, 0), // 4  ACMP1_N/AIN6
  MFP_NULL    , // 5  AVSS
  MFP_PN(5, 4), // 6  
  MFP_PN(3, 1), // 7  ACMP1_P/AIN7
  MFP_PN(3, 2), // 8  INT0/T0EX/STADC/ACMP1_P
  MFP_PN(3, 4), // 9  T0/SDA/ACMP1_P
  MFP_PN(3, 5), //10  T1/SCL/ACMP1_P
  MFP_NULL    , //11  NC
  MFP_NULL    , //12  NC
  MFP_NULL 	  , //13  NC
  MFP_PN(3, 6), //14  T1EX/CKO/ACMP0_O
  MFP_PN(5, 1), //15  XTAL2
  MFP_PN(5, 0), //16  XTAL1
  MFP_NULL 	  , //17  VSS
  MFP_NULL 	  , //18  LDO_CAP
  MFP_PN(5, 5), //19  
  MFP_PN(5, 2), //20  INT1
  MFP_NULL 	  , //21  NC
  MFP_PN(2, 2), //22  PWM0
  MFP_PN(2, 3), //23  PWM1
  MFP_PN(2, 4), //24  PWM2
  MFP_PN(2, 5), //25  PWM3
  MFP_PN(2, 6), //26  PWM4/ACMP1_O
  MFP_NULL 	  , //27  NC
  MFP_NULL 	  , //28  NC
#if USE_ICE == 0
  MFP_PN(4, 6), //29  ICE_CLK
  MFP_PN(4, 7), //30  ICE_DAT
#else
  MFP_NULL    , //29  ICE_CLK
  MFP_NULL    , //30  ICE_DAT
#endif
  MFP_NULL 	  , //31  NC
  MFP_PN(0, 7), //32  SPICLK
  MFP_PN(0, 6), //33  MISO
  MFP_PN(0, 5), //34  MOSI
  MFP_PN(0, 4), //35  SPISS/PWM5
  MFP_NULL 	  , //36  NC
  MFP_PN(0, 1), //37  SPISS/RTSn/RX
  MFP_PN(0, 0), //38  CTSn/TX
  MFP_NULL 	  , //39  NC
  MFP_NULL 	  , //40  NC
  MFP_PN(5, 3), //41  AIN0
  MFP_NULL 	  , //42  VDD
  MFP_NULL 	  , //43  AVDD
  MFP_PN(1, 0), //44  AIN1/ACMP0_P
  MFP_PN(1, 2), //45  AIN2/RX/ACMP0_P
  MFP_PN(1, 3), //46  AIN3/TX/ACMP0_P
  MFP_PN(1, 4), //47  AIN4/ACMP0_N
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWM,PWM01_MODULE,PWM_IRQn,0,500,{P2_2,SYS_MFP_P22_PWM0}},  //3  
	{PWM,PWM01_MODULE,PWM_IRQn,1,500,{P2_3,SYS_MFP_P23_PWM1}},  //3  
	{PWM,PWM23_MODULE,PWM_IRQn,2,500,{P2_4,SYS_MFP_P24_PWM2}},  //4 	
	{PWM,PWM23_MODULE,PWM_IRQn,3,500,{P2_5,SYS_MFP_P25_PWM3}},  //4 	
	{PWM,PWM45_MODULE,PWM_IRQn,4,500,{P2_6,SYS_MFP_P26_PWM4}},  //4 	
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
	{ADC,ADC_MODULE,0,{P5_3,SYS_MFP_P53_AIN0}},   	//0 
	{ADC,ADC_MODULE,1,{P1_0,SYS_MFP_P10_AIN1}},   	//1 
	{ADC,ADC_MODULE,2,{P1_2,SYS_MFP_P12_AIN2}},		//2
	{ADC,ADC_MODULE,3,{P1_3,SYS_MFP_P13_AIN3}},		//3
	{ADC,ADC_MODULE,4,{P1_4,SYS_MFP_P14_AIN4}},		//4
	{ADC,ADC_MODULE,5,{P1_5,SYS_MFP_P15_AIN5}},		//5	
	{ADC,ADC_MODULE,6,{P3_0,SYS_MFP_P30_AIN6}},   	//6 
	{ADC,ADC_MODULE,7,{P3_1,SYS_MFP_P31_AIN7}},   	//7 
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
   {{P0_1,SYS_MFP_P01_RXD}, {P0_0,SYS_MFP_P00_TXD}},	//Loc 0
   {{P1_2,SYS_MFP_P12_RXD}, {P1_3,SYS_MFP_P13_TXD}},	//Loc 1
};
const UARTPinDescription UART_Desc[]={
   {UART,UART_MODULE,UART_IRQn,UART0PinAlt},	
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = { 
	  {{P0_7,SYS_MFP_P07_SPICLK},{P0_6,SYS_MFP_P06_MISO},{P0_5,SYS_MFP_P05_MOSI}, {P0_4,SYS_MFP_P04_SPISS}},
};
const SPIPinDescription SPI_Desc[]={
  {SPI,SPI_MODULE,SPI_IRQn,CLK_CLKSEL1_SPI_S_HCLK, SPI0PinAlt},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
 {{P3_4,SYS_MFP_P34_SDA},{P3_5, SYS_MFP_P35_SCL}},
};
const I2CPinDescription I2C_Desc[]={	
 {I2C,I2C_MODULE,I2C_IRQn,I2C0PinAlt},
};
#endif
