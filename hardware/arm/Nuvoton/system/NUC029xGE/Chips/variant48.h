/*
  variant48.h  NUC029LGE
  
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
#define MFP_PN(a,b,c) {P##a,BIT##b,{(uint32_t)&SYS->GP##a##_MFP##c, \
                                     SYS_GP##a##_MFP##c##_P##a##b##MFP_Msk, \
					                 SYS_GP##a##_MFP##c##_P##a##b##MFP_GPIO}}
#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  MFP_NULL,        //0
  MFP_PN(B, 5,L),  //1   ADC0_CH13/SPI0_MOSI/SPI1_MOSI/ACMP0_P2/EBI_AD6/UART2_RXD              
  MFP_PN(B, 6,L),  //2   ADC0_CH14/SPI0_MISO/SPI1_MISO/ACMP0_P1/EBI_AD5                        
  MFP_PN(B, 7,L),  //3   ADC0_CH15/SPI0_CLK/SPI1_CLK/USCI2_CTL1/ACMP0_P0/EBI_AD4               
  MFP_NULL,        //4   nRESET                                                                
  MFP_PN(D, 0,L),  //5   SPI0_I2SMCLK/SPI1_I2SMCLK/UART0_RXD/USCI2_CTL0/ACMP1_N/INT3           
  MFP_NULL,        //6   AVSS                                                                  
  MFP_PN(D, 1,L),  //7   ADC0_CH19/PWM0_SYNC_IN/UART0_TXD/USCI2_CLK/ACMP1_P2/TM0/EBI_nRD       
  MFP_PN(D, 2,L),  //8   ADC0_ST/TM0_EXT/USCI2_DAT0/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0          
  MFP_PN(D, 3,L),  //9   TM2/SPI0_I2SMCLK/TM1_EXT/USCI2_DAT1/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1
  MFP_NULL,        //10  VBAT                                                                  
  MFP_PN(F, 0,L),  //11  X32_OUT/USCI2_CTL1/INT5                                               
  MFP_PN(F, 1,L),  //12  X32_IN/USCI2_CTL0/PWM1_BRAKE0                                         
  MFP_PN(F, 2,L),  //13  USCI2_CLK/PWM1_BRAKE1                                                 
  MFP_PN(D, 7,L),  //14  USCI1_CTL1/SPI0_I2SMCLK/PWM0_SYNC_IN/TM1/ACMP0_O/PWM0_CH5/EBI_nRD     
  MFP_PN(F, 3,L),  //15  XT1_OUT/I2C1_SCL                                                      
  MFP_PN(F, 4,L),  //16  XT1_IN/I2C1_SDA                                                       
  MFP_NULL,        //17  VSS                                                                   
  MFP_NULL,        //18  VDD                                                                   
  MFP_PN(C, 0,L),  //19  SPI0_CLK/UART2_nCTS/USCI0_DAT0/ACMP0_WLAT/PWM0_CH0/EBI_AD8/INT2       
  MFP_PN(C, 1,L),  //20  CLKO/UART2_nRTS/USCI0_DAT1/ACMP1_WLAT/PWM0_CH1/EBI_AD9                
  MFP_PN(C, 2,L),  //21  SPI0_SS/UART2_TXD/USCI0_CTL1/ACMP1_O/PWM0_CH2/EBI_AD10                
  MFP_PN(C, 3,L),  //22  SPI0_MOSI/UART2_RXD/USCI0_CTL0/PWM0_CH3/EBI_AD11                      
  MFP_PN(C, 4,L),  //23  SPI0_MISO/I2C1_SCL/USCI0_CLK/PWM0_CH4/EBI_AD12                        
  MFP_PN(E, 0,L),  //24  SPI0_CLK/I2C1_SDA/TM2_EXT/PWM0_CH0/EBI_nCS1/INT4                      
#if USE_ICE == 0                                                                                                            
  MFP_PN(E, 7,L),  //25  ICE_CLK/I2C0_SCL/UART0_RXD                                            
  MFP_PN(E, 6,L),  //26  ICE_DAT/I2C0_SDA/UART0_TXD
#else
  MFP_NULL,        //25  ICE_CLK/I2C0_SCL/UART0_RXD  
  MFP_NULL,        //26  ICE_DAT/I2C0_SDA/UART0_TXD
#endif
  MFP_PN(E, 10,H), //27  SPI1_MISO/SPI0_MISO/UART1_nCTS/SPI1_CLK/EBI_AD7/TM0_EXT                         
  MFP_PN(E, 11,H), //28  SPI1_MOSI/SPI0_MOSI/UART1_nRTS/SPI1_MISO/EBI_AD6/TM1_EXT                        
  MFP_PN(E, 12,H), //29  SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL/SPI1_MOSI/EBI_AD5/TM2_EXT                    
  MFP_PN(E, 13,H), //30  SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA/SPI1_SS/EBI_AD4/TM3_EXT                    
  MFP_NULL,        //31  VDDIO                                                                           
  MFP_NULL,        //32  USB_VBUS                                                                        
  MFP_NULL,        //33  USB_D+                                                                          
  MFP_NULL,        //34  USB_D-                                                                          
  MFP_PN(F, 7, L), //35                                                                                  
  MFP_NULL,        //36  USB_VDD33_CAP                                                                   
  MFP_PN(A, 3, L), //37  UART0_RXD/UART0_nRTS/I2C0_SCL/PWM1_CH2/EBI_AD3/USCI1_CLK                        
  MFP_PN(A, 2, L), //38  UART0_TXD/UART0_nCTS/I2C0_SDA/PWM1_CH3/EBI_AD2/USCI1_CTL0                       
  MFP_PN(A, 1, L), //39  UART1_nRTS/UART1_RXD/USCI1_CTL1/PWM1_CH4/EBI_AD1                                
  MFP_PN(A, 0, L), //40  UART1_nCTS/UART1_TXD/USCI1_CTL0/PWM1_CH5/EBI_AD0/INT0                           
  MFP_NULL,        //41  VDD                                                                             
  MFP_NULL,        //42  AVDD                                                                            
  MFP_NULL,        //43  VREF                                                                            
  MFP_PN(B, 0, L), //44  ADC0_CH0/VDET_P0/UART2_RXD/TM2/USCI1_DAT0/EBI_nWRL/INT1/TM1_EXT                 
  MFP_PN(B, 1, L), //45  ADC0_CH1/VDET_P1/UART2_TXD/TM3/PWM0_SYNC_OUT/EBI_nWRH/USCI1_DAT1                
  MFP_PN(B, 2, L), //46  ADC0_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/TM_BRAKE0/EBI_nCS0/USCI0_DAT0/TM2_EXT      
  MFP_PN(B, 3, L), //47  ADC0_CH3/SPI0_MISO/SPI1_MISO/UART1_TXD/TM_BRAKE1/EBI_ALE/USCI0_DAT1/TM0_EXT     
  MFP_PN(B, 4, L), //48  ADC0_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7/USCI0_CTL1/UART2_RXD/TM1_EXT
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWM0,PWM0_MODULE,PWM0_IRQn, 1,500,{PC_0,PWM0_CH0_PC0}},
	{PWM0,PWM0_MODULE,PWM0_IRQn, 3,500,{PC_1,PWM0_CH1_PC1}},
	{PWM0,PWM0_MODULE,PWM0_IRQn, 6,500,{PC_2,PWM0_CH2_PC2}},
	{PWM0,PWM0_MODULE,PWM0_IRQn, 9,500,{PC_3,PWM0_CH3_PC3}},
	{PWM0,PWM0_MODULE,PWM0_IRQn,10,500,{PC_4,PWM0_CH4_PC4}},
	{PWM0,PWM0_MODULE,PWM0_IRQn,11,500,{PD_7,PWM0_CH5_PD7}},
	
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PA_3,PWM1_CH2_PA3}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PA_2,PWM1_CH3_PA2}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PA_1,PWM1_CH4_PA1}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PA_0,PWM1_CH5_PA0}},
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
    {ADC,ADC_MODULE,1, {PB_0,ADC0_CH0_PB0 }},
	{ADC,ADC_MODULE,2, {PB_1,ADC0_CH1_PB1 }},
	{ADC,ADC_MODULE,6, {PB_5,ADC0_CH13_PB5}},
	{ADC,ADC_MODULE,7, {PB_6,ADC0_CH14_PB6}},
	{ADC,ADC_MODULE,8, {PB_7,ADC0_CH15_PB7}},
	{ADC,ADC_MODULE,12,{PD_1,ADC0_CH19_PD1}},
	{ADC,ADC_MODULE,13,{PB_2,ADC0_CH2_PB2 }},
	{ADC,ADC_MODULE,14,{PB_3,ADC0_CH3_PB3 }},
	{ADC,ADC_MODULE,15,{PB_4,ADC0_CH4_PB4 }},
};  

#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
	{{PA_3 ,UART0_RXD_PA3 },{PA_2 ,UART0_TXD_PA2 }},
	{{PD_0 ,UART0_RXD_PD0 },{PD_1 ,UART0_TXD_PD1 }},
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
	{{PA_1 ,UART1_RXD_PA1 },{PA_0 ,UART1_TXD_PA0 }},
	{{PB_2 ,UART1_RXD_PB2 },{PB_3 ,UART1_TXD_PB3 }},
	{{PE_13,UART1_RXD_PE13},{PE_12,UART1_TXD_PE12}},
};
const UARTPinAlt_TypeDef UART2PinAlt[] = {
	{{PB_0 ,UART2_RXD_PB0 },{PB_1 ,UART2_TXD_PB1 }},
	{{PC_3 ,UART2_RXD_PC3 },{PC_2 ,UART2_TXD_PC2 }},
	{{PB_5 ,UART2_RXD_PB5 },{PB_4 ,UART2_RXD_PB4 }},
};

const UARTPinDescription UART_Desc[]={
   {UART0,UART0_MODULE,UART02_IRQn,UART0PinAlt},
   {UART1,UART1_MODULE,UART1_IRQn, UART1PinAlt},
   {UART2,UART2_MODULE,UART02_IRQn,UART2PinAlt},
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = { 
	{{PC_0 ,SPI0_CLK_PC0  },{PC_4 ,SPI0_MISO_PC4 },{PC_3 ,SPI0_MOSI_PC3 },{PC_2 ,SPI0_SS_PC2 }},     
	{{PB_7 ,SPI0_CLK_PB7  },{PB_6 ,SPI0_MISO_PB6 },{PB_5 ,SPI0_MOSI_PB5 },{PB_4 ,SPI0_SS_PB4 }},     
	{{PE_13,SPI0_CLK_PE13 },{PE_10,SPI0_MISO_PE10},{PE_11,SPI0_MOSI_PE11},{PE_12,SPI0_SS_PE12}},
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = { 
    {{PB_2 ,SPI1_CLK_PB2  },{PB_3 ,SPI1_MISO_PB3 },{PB_5 ,SPI1_MOSI_PB5 },{PB_4 ,SPI1_SS_PB4  }},     
    {{PE_10,SPI1_CLK_PE10 },{PE_11,SPI1_MISO_PE11},{PE_12,SPI1_MOSI_PE12},{PE_13,SPI1_SS_PE13 }},     
};
const SPIPinDescription SPI_Desc[]={
  {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL2_SPI0SEL_PCLK0, SPI0PinAlt},
  {SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL2_SPI1SEL_PCLK0, SPI1PinAlt},
};  
#endif
    
#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
	{{PA_2 ,I2C0_SDA_PA2 },{PA_3 ,I2C0_SCL_PA3 }},
	{{PE_13,I2C0_SDA_PE13},{PE_12,I2C0_SCL_PE12}},
};
const I2CPinAlt_TypeDef I2C1PinAlt[] = {
	{{PF_4 ,I2C1_SDA_PF4 },{PF_3 ,I2C1_SCL_PF3 }},
};
const I2CPinDescription I2C_Desc[]={	
 {I2C0,I2C0_MODULE,I2C0_IRQn,I2C0PinAlt},
 {I2C1,I2C1_MODULE,I2C1_IRQn,I2C1PinAlt},
};
#endif
    
    