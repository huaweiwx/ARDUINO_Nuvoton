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
#define MFP_PN(a,b,c) {P##a,BIT##b,{(uint32_t)&SYS->GP##a##_MFP##c, \
                                     SYS_GP##a##_MFP##c##_P##a##b##MFP_Msk, \
					                 SYS_GP##a##_MFP##c##_P##a##b##MFP_GPIO}}
									
#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  MFP_NULL,        //0
  MFP_PN(B, 15,H), //1   ADC0_CH12/ACMP0_P3/EBI_nCS1                                           
  MFP_PN(B, 5, L), //2   ADC0_CH13/SPI0_MOSI/SPI1_MOSI/ACMP0_P2/EBI_AD6/UART2_RXD              
  MFP_PN(B, 6, L), //3   ADC0_CH14/SPI0_MISO/SPI1_MISO/ACMP0_P1/EBI_AD5                        
  MFP_PN(B, 7, L), //4   ADC0_CH15/SPI0_CLK/SPI1_CLK/USCI2_CTL1/ACMP0_P0/EBI_AD4               
  MFP_NULL,        //5   nRESET                                                                
  MFP_PN(D, 0, L), //6   SPI0_I2SMCLK/SPI1_I2SMCLK/UART0_RXD/USCI2_CTL0/ACMP1_N/INT3           
  MFP_NULL,        //7   AVSS                                                                  
  MFP_PN(D, 8, H), //8   ADC0_CH17/UART0_nCTS/USCI2_CTL1/TM2/EBI_nCS0                          
  MFP_PN(D, 9, H), //9   ADC0_CH18/UART0_RXD/USCI2_CTL0/ACMP1_P3/TM3/EBI_ALE                   
  MFP_PN(D, 1, L), //10  ADC0_CH19/PWM0_SYNC_IN/UART0_TXD/USCI2_CLK/ACMP1_P2/TM0/EBI_nRD       
  MFP_PN(D, 2, L), //11  ADC0_ST/TM0_EXT/USCI2_DAT0/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0          
  MFP_PN(D, 3, L), //12  TM2/SPI0_I2SMCLK/TM1_EXT/USCI2_DAT1/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1
  MFP_NULL,        //13  VBAT                                                                  
  MFP_PN(F, 0, L), //14  X32_OUT/USCI2_CTL1/INT5                                               
  MFP_PN(F, 1, L), //15  X32_IN/USCI2_CTL0/PWM1_BRAKE0                                         
  MFP_PN(F, 2, L), //16  USCI2_CLK/PWM1_BRAKE1                                                 
  MFP_PN(D, 12,H), //17  USCI1_CTL0/SPI1_SS/UART0_TXD/PWM1_CH0/EBI_ADR16                       
  MFP_PN(D, 13,H), //18  USCI1_DAT1/SPI1_MOSI/UART0_RXD/PWM1_CH1/EBI_ADR17                     
  MFP_PN(D, 14,H), //19  USCI1_DAT0/SPI1_MISO/UART0_nCTS/PWM1_CH2/EBI_ADR18                    
  MFP_PN(D, 15,H), //20  USCI1_CLK/SPI1_CLK/UART0_nRTS/PWM1_CH3/EBI_ADR19                      
  MFP_PN(D, 7, L), //21  USCI1_CTL1/SPI0_I2SMCLK/PWM0_SYNC_IN/TM1/ACMP0_O/PWM0_CH5/EBI_nRD     
  MFP_PN(F, 3, L), //22  XT1_OUT/I2C1_SCL                                                      
  MFP_PN(F, 4, L), //23  XT1_IN/I2C1_SDA                                                       
  MFP_NULL,        //24  VSS                                                                   
  MFP_NULL,        //25  VDD                                                                   
  MFP_NULL,        //26  VDD                                                                   
  MFP_PN(C, 0, L), //27  SPI0_CLK/UART2_nCTS/USCI0_DAT0/ACMP0_WLAT/PWM0_CH0/EBI_AD8/INT2       
  MFP_PN(C, 1, L), //28  CLKO/UART2_nRTS/USCI0_DAT1/ACMP1_WLAT/PWM0_CH1/EBI_AD9                
  MFP_PN(C, 2, L), //29  SPI0_SS/UART2_TXD/USCI0_CTL1/ACMP1_O/PWM0_CH2/EBI_AD10                
  MFP_PN(C, 3, L), //30  SPI0_MOSI/UART2_RXD/USCI0_CTL0/PWM0_CH3/EBI_AD11                      
  MFP_PN(C, 4, L), //31  SPI0_MISO/I2C1_SCL/USCI0_CLK/PWM0_CH4/EBI_AD12                        
  MFP_PN(C, 5, L), //32  SPI0_I2SMCLK/I2C1_SDA/USCI0_DAT0/PWM0_CH5/EBI_AD13                    
  MFP_PN(C, 6, L), //33  USCI0_DAT1/ACMP1_O/PWM1_CH0/EBI_AD14                                  
  MFP_PN(C, 7, L), //34  USCI0_CTL1/PWM1_CH1/EBI_AD15                                          
#if USE_ICE == 0                                                                
  MFP_PN(E, 7, L), //35  ICE_CLK/I2C0_SCL/UART0_RXD
  MFP_PN(E, 6, L), //36  ICE_DAT/I2C0_SDA/UART0_TXD
#else
  MFP_NULL,        //35  ICE_CLK/I2C0_SCL/UART0_RXD   
  MFP_NULL,        //36  ICE_DAT/I2C0_SDA/UART0_TXD 
#endif
  MFP_PN(E, 8 ,H), //37  UART1_TXD/TM0/I2C1_SCL                                                          
  MFP_PN(E, 9 ,H), //38  UART1_RXD/TM1/I2C1_SDA                                                          
  MFP_PN(E, 10,H), //39  SPI1_MISO/SPI0_MISO/UART1_nCTS/SPI1_CLK/EBI_AD7/TM0_EXT                         
  MFP_PN(E, 11,H), //40  SPI1_MOSI/SPI0_MOSI/UART1_nRTS/SPI1_MISO/EBI_AD6/TM1_EXT                        
  MFP_PN(E, 12,H), //41  SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL/SPI1_MOSI/EBI_AD5/TM2_EXT                    
  MFP_PN(E, 13,H), //42  SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA/SPI1_SS/EBI_AD4/TM3_EXT                    
  MFP_NULL,        //43  VDDIO                                                                           
  MFP_NULL,        //44  USB_VBUS                                                                        
  MFP_NULL,        //45  USB_D+                                                                          
  MFP_NULL,        //46  USB_D-                                                                          
  MFP_PN(F, 7, L), //47
  MFP_NULL,        //48  USB_VDD33_CAP                                                                   
  MFP_PN(A, 3, L), //49  UART0_RXD/UART0_nRTS/I2C0_SCL/PWM1_CH2/EBI_AD3/USCI1_CLK                        
  MFP_PN(A, 2, L), //50  UART0_TXD/UART0_nCTS/I2C0_SDA/PWM1_CH3/EBI_AD2/USCI1_CTL0                       
  MFP_PN(A, 1, L), //51  UART1_nRTS/UART1_RXD/USCI1_CTL1/PWM1_CH4/EBI_AD1                                
  MFP_PN(A, 0, L), //52  UART1_nCTS/UART1_TXD/USCI1_CTL0/PWM1_CH5/EBI_AD0/INT0                           
  MFP_NULL,        //53  VSS                                                                             
  MFP_NULL,        //54  VDD                                                                             
  MFP_NULL,        //55  AVDD                                                                            
  MFP_NULL,        //56  VREF                                                                            
  MFP_PN(B, 0, L), //57  ADC0_CH0/VDET_P0/UART2_RXD/TM2/USCI1_DAT0/EBI_nWRL/INT1/TM1_EXT                 
  MFP_PN(B, 1, L), //58  ADC0_CH1/VDET_P1/UART2_TXD/TM3/PWM0_SYNC_OUT/EBI_nWRH/USCI1_DAT1                
  MFP_PN(B, 2, L), //59  ADC0_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/TM_BRAKE0/EBI_nCS0/USCI0_DAT0/TM2_EXT      
  MFP_PN(B, 3, L), //60  ADC0_CH3/SPI0_MISO/SPI1_MISO/UART1_TXD/TM_BRAKE1/EBI_ALE/USCI0_DAT1/TM0_EXT     
  MFP_PN(B, 4, L), //61  ADC0_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7/USCI0_CTL1/UART2_RXD/TM1_EXT
  MFP_PN(B, 8, H), //62  ADC0_CH5/UART1_nRTS/TM_BRAKE2/PWM0_CH2/USCI0_CTL0                               
  MFP_PN(B, 11,H), //63  ADC0_CH8                                                                        
  MFP_PN(E, 2, L), //64  ADC0_CH9/UART1_nRTS/TM_BRAKE3/PWM0_CH2/USCI0_CTL0                               
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWM0,PWM0_MODULE,PWM0_IRQn, 1,500,{PC_0,PWM0_CH0_PC0}},
//  {PWM0,PWM0_MODULE,PWM0_IRQn, 2,500,{PE_0,PWM0_CH0_PE0}},
	{PWM0,PWM0_MODULE,PWM0_IRQn, 3,500,{PC_1,PWM0_CH1_PC1}},
//	{PWM0,PWM0_MODULE,PWM0_IRQn, 4,500,{PE_1,PWM0_CH1_PE1}},
	{PWM0,PWM0_MODULE,PWM0_IRQn, 5,500,{PE_2,PWM0_CH2_PE2}},
	{PWM0,PWM0_MODULE,PWM0_IRQn, 6,500,{PC_2,PWM0_CH2_PC2}},
	{PWM0,PWM0_MODULE,PWM0_IRQn, 7,500,{PB_8,PWM0_CH2_PB8}},
//	{PWM0,PWM0_MODULE,PWM0_IRQn, 8,500,{PE_3,PWM0_CH3_PE3}},
	{PWM0,PWM0_MODULE,PWM0_IRQn, 9,500,{PC_3,PWM0_CH3_PC3}},
	{PWM0,PWM0_MODULE,PWM0_IRQn,10,500,{PC_4,PWM0_CH4_PC4}},
	{PWM0,PWM0_MODULE,PWM0_IRQn,11,500,{PD_7,PWM0_CH5_PD7}},
	{PWM0,PWM0_MODULE,PWM0_IRQn,12,500,{PC_5,PWM0_CH5_PC5}},
//	{PWM0,PWM0_MODULE,PWM0_IRQn,13,500,{PD_6,PWM0_CH5_PD6}},
	
    {PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PD_12,PWM1_CH0_PD12}},
//	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PC_9 ,PWM1_CH0_PC9 }},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PC_6 ,PWM1_CH0_PC6 }},
//	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PC_15,PWM1_CH0_PC15}},
//	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PC_10,PWM1_CH1_PC10}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PD_13,PWM1_CH1_PD13}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PC_7 ,PWM1_CH1_PC7 }},
//	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PB_12,PWM1_CH1_PB12}},
//	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PC_11,PWM1_CH2_PC11}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PD_14,PWM1_CH2_PD14}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PA_3 ,PWM1_CH2_PA3 }},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PA_2 ,PWM1_CH3_PA2 }},
//	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PC_12,PWM1_CH3_PC12}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PD_15,PWM1_CH3_PD15}},
//	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PC_13,PWM1_CH4_PC13}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PA_1 ,PWM1_CH4_PA1 }},
//	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PC_14,PWM1_CH5_PC14}},
	{PWM1,PWM1_MODULE,PWM1_IRQn,13,500,{PA_0 ,PWM1_CH5_PA0 }},
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
    {ADC,ADC_MODULE,1,{PB_0 ,ADC0_CH0_PB0  }},
	{ADC,ADC_MODULE,2,{PB_1 ,ADC0_CH1_PB1  }},
//	{ADC,ADC_MODULE,3,{PB_13,ADC0_CH10_PB13}},
//	{ADC,ADC_MODULE,4,{PB_14,ADC0_CH11_PB14}},
	{ADC,ADC_MODULE,5,{PB_15,ADC0_CH12_PB15}},
	{ADC,ADC_MODULE,6,{PB_5 ,ADC0_CH13_PB5 }},
	{ADC,ADC_MODULE,7,{PB_6, ADC0_CH14_PB6 }},
	{ADC,ADC_MODULE,8,{PB_7, ADC0_CH15_PB7 }},
//	{ADC,ADC_MODULE,9,{PC_8, ADC0_CH16_PC8 }},
	{ADC,ADC_MODULE,10,{PD_8, ADC0_CH17_PD8}},
	{ADC,ADC_MODULE,11,{PD_9, ADC0_CH18_PD9}},
	{ADC,ADC_MODULE,12,{PD_1, ADC0_CH19_PD1}},
	{ADC,ADC_MODULE,13,{PB_2 ,ADC0_CH2_PB2 }},
	{ADC,ADC_MODULE,14,{PB_3 ,ADC0_CH3_PB3 }},
	{ADC,ADC_MODULE,15,{PB_4 ,ADC0_CH4_PB4 }},
	{ADC,ADC_MODULE,16,{PB_8 ,ADC0_CH5_PB8 }},
//	{ADC,ADC_MODULE,17,{PB_9 ,ADC0_CH6_PB9 }},
//	{ADC,ADC_MODULE,18,{PB_10,ADC0_CH7_PB10}},
	{ADC,ADC_MODULE,19,{PB_11,ADC0_CH8_PB11}},
    {ADC,ADC_MODULE,20,{PE_2 ,ADC0_CH9_PE2 }},
};  

#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
	{{PA_3 ,UART0_RXD_PA3 },{PA_2 ,UART0_TXD_PA2 }},
	{{PD_0 ,UART0_RXD_PD0 },{PD_1 ,UART0_TXD_PD1 }},
	{{PD_13,UART0_RXD_PD13},{PD_12,UART0_TXD_PD12}},
//	{{PE_6 ,UART0_RXD_PE6 },{PE_7 ,UART0_TXD_PE7 }},
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
	{{PA_1 ,UART1_RXD_PA1 },{PA_0 ,UART1_TXD_PA0 }},
//	{{PA_9 ,UART1_RXD_PA9 },{PA_8 ,UART1_TXD_PA8 }},
//	{{PA_12,UART1_RXD_PA12},{PA_13,UART1_TXD_PA13}},
	{{PB_2 ,UART1_RXD_PB2 },{PB_3 ,UART1_TXD_PB3 }},
	{{PE_9 ,UART1_RXD_PE9 },{PE_8 ,UART1_TXD_PE8 }},
	{{PE_13,UART1_RXD_PE13},{PE_12,UART1_TXD_PE12}},
};
const UARTPinAlt_TypeDef UART2PinAlt[] = {
//	{{PA_12,UART2_RXD_PA12},{PA_13,UART2_TXD_PA13}},
	{{PB_0 ,UART2_RXD_PB0 },{PB_1 ,UART2_TXD_PB1 }},
	{{PC_3 ,UART2_RXD_PC3 },{PC_2 ,UART2_TXD_PC2 }},
//	{{PE_3 ,UART2_RXD_PE3 },{PD_6 ,UART2_TXD_PD6 }},
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
//	{{PC_12,SPI0_CLK_PC12 },{PC_11SPI0_MISO_PC11},{PC_10,SPI0_MOSI_PC10},{PC_13,SPI0_SS_PC13 }},     
	{{PB_7 ,SPI0_CLK_PB7  },{PB_6 ,SPI0_MISO_PB6 },{PB_5 ,SPI0_MOSI_PB5 },{PB_4 ,SPI0_SS_PB4 }},     
	{{PE_13,SPI0_CLK_PE13 },{PE_10,SPI0_MISO_PE10},{PE_11,SPI0_MOSI_PE11},{PE_12,SPI0_SS_PE12}},
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = { 
//    {{PA_7 ,SPI1_CLK_PA7  },{PA_6 ,SPI1_MISO_PA6 },{PA_5 ,SPI1_MOSI_PA5 },{PA_4 ,SPI1_SS_PA4  }},     
    {{PB_2 ,SPI1_CLK_PB2  },{PB_3 ,SPI1_MISO_PB3 },{PB_5 ,SPI1_MOSI_PB5 },{PB_4 ,SPI1_SS_PB4  }},     
    {{PE_10,SPI1_CLK_PE10 },{PE_11,SPI1_MISO_PE11},{PE_12,SPI1_MOSI_PE12},{PE_13,SPI1_SS_PE13 }},     
    {{PD_15,SPI1_CLK_PD15 },{PD_14,SPI1_MISO_PD14},{PD_13,SPI1_MOSI_PD13},{PD_12,SPI1_SS_PD12 }},     
//  {{PD_4 ,SPI1_CLK_PD4  },{PE_11,SPI1_MOSI_PE11},{PE_13,SPI1_CLK_PE13 },{PD_5 ,SPI1_MISO_PD5}},  
//  {PE_10,SPI1_MISO_PE10},{PE_3 ,SPI1_MOSI_PE3 },
//  {PE_12,SPI1_SS_PE12  },{PD_6 ,SPI1_SS_PD6   },
//  {PB_7 ,SPI1_CLK_PB7  },{PB_6 ,SPI1_MISO_PB6 },
};
const SPIPinDescription SPI_Desc[]={
  {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL2_SPI0SEL_PCLK0, SPI0PinAlt},
  {SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL2_SPI1SEL_PCLK0, SPI1PinAlt},
};  
#endif
    
#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
	{{PA_2 ,I2C0_SDA_PA2 },{PA_3 ,I2C0_SCL_PA3 }},
//	{{PD_4 ,I2C0_SDA_PD4 },{PD_5 ,I2C0_SCL_PD5 }},
//	{{PE_5 ,I2C0_SDA_PE5 },{PE_4 ,I2C0_SCL_PE4 }},
//	{{PE_7 ,I2C0_SDA_PE7 },{PE_6 ,I2C0_SCL_PE6 }},
	{{PE_13,I2C0_SDA_PE13},{PE_12,I2C0_SCL_PE12}},
};
const I2CPinAlt_TypeDef I2C1PinAlt[] = {
//	{{PA_9 ,I2C1_SDA_PA9 },{PA_8 ,I2C1_SCL_PA8 }},
	{{PC_5 ,I2C1_SDA_PC5 },{PC_4 ,I2C1_SCL_PC4 }},
//	{{PC_10,I2C1_SDA_PC10},{PC_9 ,I2C1_SCL_PC9 }},
//	{{PE_5 ,I2C1_SDA_PE5 },{PE_4 ,I2C1_SCL_PE4 }},
	{{PE_9 ,I2C1_SDA_PE9 },{PE_8 ,I2C1_SCL_PE8 }},
	{{PF_4 ,I2C1_SDA_PF4 },{PF_3 ,I2C1_SCL_PF3 }},
//{PE_0 ,I2C1_SDA_PE0 },
};
const I2CPinDescription I2C_Desc[]={	
 {I2C0,I2C0_MODULE,I2C0_IRQn,I2C0PinAlt},
 {I2C1,I2C1_MODULE,I2C1_IRQn,I2C1PinAlt},
};
#endif
    
    