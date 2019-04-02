/*
  variant20.h
  
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
  MFP_NULL,       // 0
  MFP_PN(1, 2),   // 1 ADC_CH2/UART0_RXD/PWM0_CH0
  MFP_PN(1, 3),   // 2 ADC_CH3/UART0_TXD/PWM0_CH1
  MFP_PN(1, 4),   // 3 ADC_CH4/UART1_RXD/PWM0_CH4
  MFP_PN(1, 5),   // 4 ADC_CH5/UART1_TXD
  MFP_NULL,       // 5 nRESET
  MFP_PN(3, 2),   // 6 INT0/TM0_EXT/STADC
  MFP_PN(3, 4),   // 7 TM0_CNT_OUT/I2C0_SDA
  MFP_PN(3, 5),   // 8 TM1_CNT_OUT/I2C0_SCL
  MFP_PN(5, 1),   // 9 XT1_OUT/I2C1_SCL/UART0_RXD
  MFP_PN(5, 0),   //10 XT1_IN/I2C1_SDA/UART0_TXD
  MFP_NULL,       //11 VSS  
  MFP_PN(2, 4),   //12 UART1_RXD/PWM0_CH2
  MFP_PN(2, 5),   //13 UART1_TXD/PWM0_CH3
#if USE_ICE == 0
  MFP_PN(4, 6),   //14 ICE_CLK/UART1_RXD
  MFP_PN(4, 7),   //15 ICE_DAT/UART1_TXD
#else
  MFP_NULL,       //14 ICE_CLK/UART1_RXD
  MFP_NULL,       //15 ICE_DAT/UART1_TXD
#endif
  MFP_PN(0, 7),   //16 SPI0_CLK/PWM0_CH0
  MFP_PN(0, 6),   //17 SPI0_MISO/PWM0_CH1
  MFP_PN(0, 5),   //18 SPI0_MOSI/PWM0_CH4
  MFP_PN(0, 4),   //19 SPI0_SS/PWM0_CH5
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWM,PWMCH23_MODULE,PWM_IRQn,2,500,{P2_4,SYS_MFP_P24_PWM0_CH2}},  //4 	
	{PWM,PWMCH23_MODULE,PWM_IRQn,3,500,{P2_5,SYS_MFP_P25_PWM0_CH3}},  //4 	
	{PWM,PWMCH01_MODULE,PWM_IRQn,0,500,{P0_7,SYS_MFP_P07_PWM0_CH0}},  //5 
	{PWM,PWMCH01_MODULE,PWM_IRQn,1,500,{P0_6,SYS_MFP_P06_PWM0_CH1}},  //6 
	{PWM,PWMCH45_MODULE,PWM_IRQn,4,500,{P0_5,SYS_MFP_P05_PWM0_CH4}},  //7 
	{PWM,PWMCH45_MODULE,PWM_IRQn,5,500,{P0_4,SYS_MFP_P04_PWM0_CH5}},  //7 
	{PWM,PWMCH01_MODULE,PWM_IRQn,0,500,{P1_2,SYS_MFP_P12_PWM0_CH0}},  //0
	{PWM,PWMCH01_MODULE,PWM_IRQn,1,500,{P1_3,SYS_MFP_P13_PWM0_CH1}},  //1  
	{PWM,PWMCH45_MODULE,PWM_IRQn,4,500,{P1_4,SYS_MFP_P14_PWM0_CH4}},  //2  
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
	{ADC,ADC_MODULE,2,{P1_2,SYS_MFP_P12_ADC_CH2}},		//2
	{ADC,ADC_MODULE,3,{P1_3,SYS_MFP_P13_ADC_CH3}},		//3
	{ADC,ADC_MODULE,4,{P1_4,SYS_MFP_P14_ADC_CH4}},		//4
	{ADC,ADC_MODULE,5,{P1_5,SYS_MFP_P15_ADC_CH5}},		//5	
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
   {{P1_2,SYS_MFP_P12_UART0_RXD}, {P1_3,SYS_MFP_P13_UART0_TXD}},	//Loc 0
   {{P5_1,SYS_MFP_P51_UART0_RXD}, {P5_0,SYS_MFP_P50_UART0_TXD}},	//Loc 1
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
   {{P1_4,SYS_MFP_P14_UART1_RXD}, {P1_5,SYS_MFP_P15_UART1_TXD}},	//Loc 0
   {{P2_4,SYS_MFP_P24_UART1_RXD}, {P2_5,SYS_MFP_P25_UART1_TXD}},	//Loc 1
#if USE_ICE == 0
   {{P4_6,SYS_MFP_P46_UART1_RXD}, {P4_7,SYS_MFP_P47_UART1_TXD}},    //Loc 2
#endif
};
const UARTPinDescription UART_Desc[]={
   {UART0,UART0_MODULE,UART0_IRQn,UART0PinAlt},	
   {UART1,UART1_MODULE,UART1_IRQn,UART1PinAlt},	
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = { 
  {{P0_7,SYS_MFP_P07_SPI0_CLK},{P0_6,SYS_MFP_P06_SPI0_MISO},{P0_5,SYS_MFP_P05_SPI0_MOSI}, {P0_4,SYS_MFP_P04_SPI0_SS}},
};
const SPIPinDescription SPI_Desc[]={
  {SPI0,SPI0_MODULE,SPI_IRQn,CLK_CLKSEL1_SPISEL_HCLK, SPI0PinAlt},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
 {{P3_4,SYS_MFP_P34_I2C0_SDA},{P3_5, SYS_MFP_P35_I2C0_SCL}},
};
const I2CPinAlt_TypeDef I2C1PinAlt[] = {
 {{P5_0,SYS_MFP_P50_I2C1_SDA},{P5_1, SYS_MFP_P51_I2C1_SCL}},
};
const I2CPinDescription I2C_Desc[]={	
 {I2C0,I2C0_MODULE,I2C0_IRQn,I2C0PinAlt},
 {I2C1,I2C1_MODULE,I2C1_IRQn,I2C1PinAlt},
};
#endif
