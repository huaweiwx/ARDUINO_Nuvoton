/*
  variant33.h
  
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
  MFP_NULL    ,   // 0
  MFP_PN(1, 5),   // 1 AIN5/ACMP0_P    
  MFP_NULL    ,   // 2 nRST            
  MFP_PN(3, 0),   // 3 RXD/ACMP1_N     
  MFP_NULL    ,   // 4 AVSS            
  MFP_PN(3, 1),   // 5 TXD/ACMP1_P     
  MFP_PN(3, 2),   // 6 nINT0/T0EX/STADC
  MFP_PN(3, 4),   // 7 T0/SDA0         
  MFP_PN(3, 5),   // 8 T1/SCL0/CKO     
  MFP_PN(3, 6),   // 9 CKO/ACMP0_O     
  MFP_NULL    ,   //10 XTAL2           
  MFP_NULL    ,   //11 XTAL1           
  MFP_NULL    ,   //12 VSS             
  MFP_NULL    ,   //13 LDO_CAP         
  MFP_PN(2, 2),   //14 PWM2            
  MFP_PN(2, 3),   //15 PWM3            
  MFP_PN(2, 4),   //16 PWM4/SCL1       
  MFP_PN(2, 5),   //17 PWM5/SDA1       
  MFP_PN(2, 6),   //18 PWM6/ACMP1_O    
#if USE_ICE == 0                
  MFP_PN(4, 6),   //19 ICE_CLK
  MFP_PN(4, 7),   //20 ICE_DAT
#else
  MFP_NULL    ,   //19 ICE_CLK
  MFP_NULL    ,   //20 ICE_DAT
#endif
  MFP_PN(0, 7),   //21 SPICLK1          
  MFP_PN(0, 6),   //22 MISO_1           
  MFP_PN(0, 5),   //23 MOSI_1           
  MFP_PN(0, 4),   //24 SPISS1           
  MFP_PN(0, 1),   //25 RTS1/RXD1/ACMP3_N
  MFP_PN(0, 0),   //26 CTS1/TXD1/ACMP3_P
  MFP_NULL    ,   //41 VDD              
  MFP_NULL    ,   //42 AVDD             
  MFP_PN(1, 0),   //29 AIN0/T2          
  MFP_PN(1, 2),   //30 AIN2/RXD1        
  MFP_PN(1, 3),   //31 AIN3/TXD1        
  MFP_PN(1, 4),   //32 AIN4/ACMP0_N     
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWMA,PWM23_MODULE,PWMA_IRQn,2,500,{P2_2,SYS_MFP_P22_PWM2}},  //2  
	{PWMA,PWM23_MODULE,PWMA_IRQn,3,500,{P2_3,SYS_MFP_P23_PWM3}},  //3  
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
	{ADC,ADC_MODULE,0,{P1_0,SYS_MFP_P10_AIN0}},   	//0 
	{ADC,ADC_MODULE,2,{P1_2,SYS_MFP_P12_AIN2}},		//2
	{ADC,ADC_MODULE,3,{P1_3,SYS_MFP_P13_AIN3}},		//3
	{ADC,ADC_MODULE,4,{P1_4,SYS_MFP_P14_AIN4}},		//4
	{ADC,ADC_MODULE,5,{P1_5,SYS_MFP_P15_AIN5}},		//5	
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
   {{P3_0,SYS_MFP_P30_RXD}, {P3_1,SYS_MFP_P31_TXD}},	
};
const UARTPinDescription UART_Desc[]={
   {UART0,UART0_MODULE,UART0_IRQn,UART0PinAlt},	
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = {
   {{P0_7,SYS_MFP_P07_SPICLK},{P0_6,SYS_MFP_P06_MISO},{P0_5,SYS_MFP_P05_MOSI}, {P1_4,SYS_MFP_P14_SPISS}},
};
const SPIPinDescription SPI_Desc[]={
  {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL1_SPI0_S_HCLK,SPI0PinAlt},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
  {{P3_4,SYS_MFP_P34_SDA0},{P3_5, SYS_MFP_P35_SCL0}}
};
const I2CPinDescription I2C_Desc[]={	
  {I2C0,I2C0_MODULE,I2C0_IRQn,I2C0PinAlt},
};
#endif
