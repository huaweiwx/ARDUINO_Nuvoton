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

#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 0
  {P1, BIT2, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P12_Msk, SYS_MFP_P12_GPIO}},    // 1
  {P1, BIT3, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P13_Msk, SYS_MFP_P13_GPIO}},    // 2
  {P1, BIT4, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P14_Msk, SYS_MFP_P14_GPIO}},    // 3
  {P1, BIT5, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P15_Msk, SYS_MFP_P15_GPIO }},   // 4
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 5
  {P3, BIT2, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P32_Msk, SYS_MFP_P32_GPIO }},   // 6
  {P3, BIT4, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P34_Msk, SYS_MFP_P34_GPIO }},   // 7
  {P3, BIT5, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P35_Msk, SYS_MFP_P35_GPIO }},   // 8
  {P5, BIT1, {(uint32_t)&SYS->P5_MFP, SYS_MFP_P51_Msk, SYS_MFP_P51_GPIO }},   // 9
  {P5, BIT0, {(uint32_t)&SYS->P5_MFP, SYS_MFP_P50_Msk, SYS_MFP_P50_GPIO }},   //10
  {NULL, NULL, {NULL, NULL, NULL}},                                           //11
  {P2, BIT4, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P24_Msk, SYS_MFP_P24_GPIO }},   //12
  {P2, BIT5, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P25_Msk, SYS_MFP_P25_GPIO }},   //13
#if USE_ICE == 0
  {P4, BIT6, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P46_Msk, SYS_MFP_P46_GPIO }},   //14
  {P4, BIT7, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P47_Msk, SYS_MFP_P47_GPIO }},   //15
#else
  {NULL, NULL, {NULL, NULL, NULL}},   //14
  {NULL, NULL, {NULL, NULL, NULL}},   //15
#endif
  {P0, BIT7, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P07_Msk, SYS_MFP_P07_GPIO }},   //16
  {P0, BIT6, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P06_Msk, SYS_MFP_P06_GPIO }},   //17
  {P0, BIT5, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P05_Msk, SYS_MFP_P05_GPIO }},   //18
  {P0, BIT4, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P04_Msk, SYS_MFP_P04_GPIO }},   //19
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
