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
  {P1, BIT0, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P10_Msk, SYS_MFP_P10_GPIO }},   // 1
  {P1, BIT4, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P14_Msk, SYS_MFP_P14_GPIO}},    // 2
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 3
  {P3, BIT0, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P30_Msk, SYS_MFP_P30_GPIO }},   // 4
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 5
  {P3, BIT1, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P31_Msk, SYS_MFP_P31_GPIO }},   // 6
  {P3, BIT4, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P34_Msk, SYS_MFP_P34_GPIO }},   // 7
  {P3, BIT5, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P35_Msk, SYS_MFP_P35_GPIO }},   // 8
  {P7, BIT0, {(uint32_t)&SYS->P7_MFP, SYS_MFP_P70_Msk, SYS_MFP_P70_GPIO }},   // 9
  {P7, BIT1, {(uint32_t)&SYS->P7_MFP, SYS_MFP_P71_Msk, SYS_MFP_P71_GPIO }},   //10
  {NULL, NULL, {NULL, NULL, NULL}},                                           //11                               //15
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //12	     	 	    //17
  {P2, BIT3, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P23_Msk, SYS_MFP_P23_GPIO }},   //13
#if USE_ICE == 0
  {P4, BIT6, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P46_Msk, SYS_MFP_P46_GPIO }},   //14
  {P4, BIT7, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P47_Msk, SYS_MFP_P47_GPIO }},   //15
#else
  {NULL, NULL, {NULL, NULL, NULL}},   //14													//30
  {NULL, NULL, {NULL, NULL, NULL}},   //15
#endif
  {P0, BIT7, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P07_Msk, SYS_MFP_P07_GPIO }},   //16
  {P0, BIT6, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P06_Msk, SYS_MFP_P06_GPIO }},   //17
  {P0, BIT5, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P05_Msk, SYS_MFP_P05_GPIO }},   //18
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWMA,PWM01_MODULE,PWMA_IRQn,0,500,{P2_0,SYS_MFP_P20_PWM0}},  //0
	{PWMA,PWM01_MODULE,PWMA_IRQn,1,500,{P2_1,SYS_MFP_P21_PWM1}},  //1  
	{PWMA,PWM23_MODULE,PWMA_IRQn,2,500,{P2_2,SYS_MFP_P22_PWM2}},  //2  
	{PWMA,PWM23_MODULE,PWMA_IRQn,3,500,{P2_3,SYS_MFP_P23_PWM3}},  //3  
	{PWMA,PWM45_MODULE,PWMA_IRQn,4,500,{P2_4,SYS_MFP_P24_PWM4}},  //4 	
	{PWMA,PWM45_MODULE,PWMA_IRQn,5,500,{P2_5,SYS_MFP_P25_PWM5}},  //5 
	{PWMA,PWM67_MODULE,PWMA_IRQn,6,500,{P2_6,SYS_MFP_P26_PWM6}},  //6 
	{PWMA,PWM67_MODULE,PWMA_IRQn,7,500,{P2_7,SYS_MFP_P27_PWM7}},  //7 
	{PWMB,PWM01_MODULE,PWMB_IRQn,0,500,{P4_0,SYS_MFP_P40_PWM0}},  //8	 
	{PWMB,PWM01_MODULE,PWMB_IRQn,1,500,{P4_1,SYS_MFP_P41_PWM1}},  //9 
	{PWMB,PWM23_MODULE,PWMB_IRQn,2,500,{P4_2,SYS_MFP_P42_PWM2}},  //10
	{PWMB,PWM23_MODULE,PWMB_IRQn,3,500,{P4_3,SYS_MFP_P43_PWM3}},  //11
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
	{ADC,ADC_MODULE,0,{P1_0,SYS_MFP_P10_AIN0}},   	//0 
	{ADC,ADC_MODULE,1,{P1_1,SYS_MFP_P11_AIN1}},		//1
	{ADC,ADC_MODULE,2,{P1_2,SYS_MFP_P12_AIN2}},		//2
	{ADC,ADC_MODULE,3,{P1_3,SYS_MFP_P13_AIN3}},		//3
	{ADC,ADC_MODULE,4,{P1_4,SYS_MFP_P14_AIN4}},		//4
	{ADC,ADC_MODULE,5,{P1_5,SYS_MFP_P15_AIN5}},		//5	
	{ADC,ADC_MODULE,6,{P1_6,SYS_MFP_P16_AIN6}},		//6
	{ADC,ADC_MODULE,7,{P1_7,SYS_MFP_P17_AIN7}},		//7	
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
   {{P3_0,SYS_MFP_P30_RXD0}, {P3_1,SYS_MFP_P31_TXD0}},	//Loc 0
   {{P0_3,SYS_MFP_P03_RXD0}, {P0_2,SYS_MFP_P02_TXD0}},	//Loc 1
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
   {{P0_1,SYS_MFP_P01_RXD1}, {P0_0,SYS_MFP_P00_TXD1}},	
};
const UARTPinDescription UART_Desc[]={
   {UART0,UART0_MODULE,UART0_IRQn,UART0PinAlt},	
   {UART1,UART1_MODULE,UART1_IRQn,UART1PinAlt},	
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = {
 	 {{P1_7,SYS_MFP_P17_SPICLK0},{P1_6,SYS_MFP_P16_MISO_0},{P1_5,SYS_MFP_P15_MOSI_0}, {P1_4,SYS_MFP_P14_SPISS0}}
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = {
 	 {{P0_7,SYS_MFP_P07_SPICLK1},{P0_6,SYS_MFP_P06_MISO_1},{P0_5,SYS_MFP_P05_MOSI_1}, {P0_4,SYS_MFP_P04_SPISS1}},
};
const SPIPinDescription SPI_Desc[]={
	 {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL1_SPI0_S_HCLK, SPI0PinAlt},
	 {SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL1_SPI1_S_HCLK, SPI1PinAlt},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
   {{P3_4,SYS_MFP_P34_SDA0},{P3_5, SYS_MFP_P35_SCL0}},
};
const I2CPinDescription I2C_Desc[]={	
  {I2C0,I2C0_MODULE,I2C0_IRQn,I2C0PinAlt},
};
#endif
