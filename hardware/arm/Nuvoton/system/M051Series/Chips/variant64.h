/*
  variant64.h
  
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
  MFP_NULL   ,  /* 0                   */
  MFP_PN(1,5),  /* 1  AIN5/MOSI        */
  MFP_PN(1,6),  /* 2  AIN6/MISO        */
  MFP_PN(1,7),  /* 3  AIN7/SPICLK      */
  MFP_NULL   ,  /* 4  RST               */
  MFP_PN(3,0),  /* 5  RXD              */
  MFP_NULL   ,  /* 6  AVSS              */
  MFP_PN(5,1),  /* 7  T1EX             */
  MFP_PN(5,2),  /* 8  SDA0             */
  MFP_PN(5,3),  /* 9  SCL0             */
  MFP_PN(3,1),  /* 10 TXD              */
  MFP_PN(3,2),  /* 11 nINT0/T0EX/STADC */
  MFP_PN(3,3),  /* 12 nINT1/T1EX       */
  MFP_PN(3,4),  /* 13 T0/SDA0          */
  MFP_PN(3,5),  /* 14 T1/SCL0/CKO      */
  MFP_PN(4,3),  /* 15 PWM3             */
  MFP_PN(3,6),  /* 16 CKO              */
  MFP_PN(3,7),  /* 17                  */
  MFP_PN(7,0),  /* 18  XTAL2           */
  MFP_PN(7,1),  /* 19  XTAL1           */
  MFP_NULL   ,  /* 20  VSS             */
  MFP_NULL   ,  /* 21  VDD             */
  MFP_NULL   ,  /* 22  LDO_CAP         */
  MFP_PN(5,4),  /* 23                  */
  MFP_PN(5,5),  /* 24                  */
  MFP_PN(5,6),  /* 25                  */
  MFP_PN(5,7),  /* 26                  */
  MFP_PN(2,0),  /* 27  PWM0            */
  MFP_PN(2,1),  /* 28  PWM1            */
  MFP_PN(2,2),  /* 29  PWM2            */
  MFP_PN(2,3),  /* 30  PWM3            */
  MFP_PN(2,4),  /* 31                  */
  MFP_PN(4,0),  /* 32  PWM0/T2EX       */
  MFP_PN(2,5),  /* 33                  */
  MFP_PN(2,6),  /* 34                  */
  MFP_PN(2,7),  /* 35                  */
  MFP_PN(4,4),  /* 36  SCL1            */
  MFP_PN(4,5),  /* 37  SDA1            */
#if USE_ICE == 0
  MFP_PN(4, 6), /* 38  ICE_CLK         */
  MFP_PN(4, 7), /* 39  ICE_DAT         */
#else
  MFP_NULL,     /* 38  ICE_CLK         */ 
  MFP_NULL,     /* 39  ICE_DAT         */  
#endif
  MFP_PN(6,0),  /* 40                  */
  MFP_PN(6,1),  /* 41                  */
  MFP_PN(6,2),  /* 42                  */
  MFP_PN(6,3),  /* 43                  */
  MFP_PN(0,7),  /* 44  SPICLK          */
  MFP_PN(0,6),  /* 45  MISO            */
  MFP_PN(0,5),  /* 46  MOSI            */
  MFP_PN(0,4),  /* 47  SPISS           */
  MFP_PN(4,1),  /* 48  PWM1/T3EX       */
  MFP_PN(0,3),  /* 49  RTS0/RXD        */
  MFP_PN(0,2),  /* 50  CTS0/TXD        */
  MFP_PN(0,1),  /* 51                  */
  MFP_PN(0,0),  /* 52                  */
  MFP_NULL   ,  /* 53  VSS             */
  MFP_NULL   ,  /* 54  VDD             */
  MFP_NULL   ,  /* 55  AVDD            */
  MFP_NULL   ,  /* 56  Vref            */
  MFP_PN(6,6,)  /* 57                  */
  MFP_PN(6,7,)  /* 58                  */
  MFP_PN(1,0,)  /* 59 AIN0/T2          */
  MFP_PN(1,1,)  /* 60 AIN1/T3          */
  MFP_PN(1,2,)  /* 61 AIN2             */
  MFP_PN(1,3,)  /* 62 AIN3             */
  MFP_PN(1,4,)  /* 63 AIN4/SPISS       */
  MFP_PN(4,2,)  /* 64 PWM2             */
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
   {{P3_0,SYS_MFP_P30_RXD0}, {P3_1,SYS_MFP_P31_TXD0}},	   //Loc 0
   {{P0_3,SYS_MFP_P03_RXD0}, {P0_2,SYS_MFP_P02_TXD0}},	   //Loc 1
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
 	 {{P1_7,SYS_MFP_P17_SPICLK0},{P1_6,SYS_MFP_P16_MISO_0},{P1_5,SYS_MFP_P15_MOSI_0}, {P1_4,SYS_MFP_P14_SPISS0}}, 
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = {
	 SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL1_SPI1_S_HCLK,
 	 {{P0_7,SYS_MFP_P07_SPICLK1},{P0_6,SYS_MFP_P06_MISO_1},{P0_5,SYS_MFP_P05_MOSI_1}, {P0_4,SYS_MFP_P04_SPISS1}}, 
};
const SPIPinDescription SPI_Desc[]={
    {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL1_SPI0_S_HCLK,SPI0PinAlt},
	{SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL1_SPI1_S_HCLK,SPI1PinAlt},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
    {{P3_4,SYS_MFP_P34_SDA0},{P3_5, SYS_MFP_P35_SCL0}},
};
const I2CPinDescription I2C_Desc[]={	
    {I2C0,I2C0_MODULE, I2C0_IRQn,I2C0PinAlt},
};
#endif
