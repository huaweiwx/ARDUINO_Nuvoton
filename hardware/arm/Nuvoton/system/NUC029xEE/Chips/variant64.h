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

#define MFP_NULL {NULL, NULL, {NULL, NULL, NULL, NULL, NULL}} 
#define MFP_PN(a, b) {P##a,BIT##b,{(uint32_t)&SYS->GP##a##_MFP, \
                                    SYS_GP##a##_MFP_P##a##b##_Msk, \
						            SYS_ALT_MFP_P##a##b##_GPIO,\
						            SYS_ALT_MFP2_P##a##b##_GPIO,\
						            SYS_GP##a##_MFP_P##a##b##_GPIO}}

#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  MFP_NULL,        //0
  MFP_PN(B, 14),   //1   INT0/AD0                   
  MFP_PN(B, 13),   //2   AD1                        
  MFP_NULL,        //3   VBAT                       
  MFP_NULL,        //4   X32_OUT                    
  MFP_NULL,        //5   X32_IN                     
  MFP_PN(A, 11),   //6   I2C1_SCL/nRD               
  MFP_PN(A, 10),   //7   I2C1_SDA/nWR               
  MFP_PN(A, 9 ),   //8   I2C0_SCL                   
  MFP_PN(A, 8 ),   //9   I2C0_SDA                   
  MFP_PN(B, 4 ),   //10  UART1_RXD                  
  MFP_PN(B, 5 ),   //11  UART1_TXD                  
  MFP_PN(B, 6 ),   //12  UART1_nRTS/ALE             
  MFP_PN(B, 7 ),   //13  UART1_nCTS/nCS             
  MFP_NULL,        //14  LDO_CAP                    
  MFP_NULL,        //15  VDD                        
  MFP_NULL,        //16  VSS                        
  MFP_NULL,        //17  USB_VBUS                   
  MFP_NULL,        //18  USB_VDD33_CAP              
  MFP_NULL,        //19  USB_D-                     
  MFP_NULL,        //20  USB_D+                     
  MFP_PN(B, 0 ),   //21  UART0_RXD                  
  MFP_PN(B, 1 ),   //22  UART0_TXD                  
  MFP_PN(B, 2 ),   //23  UART0_nRTS/TM2_EXT/TM2/nWRL
  MFP_PN(B, 3 ),   //24  UART0_nCTS/TM3_EXT/TM3/nWRH
  MFP_PN(C, 3 ),   //25  SPI0_MOSI0                 
  MFP_PN(C, 2 ),   //26  SPI0_MISO0                 
  MFP_PN(C, 1 ),   //27  SPI0_CLK                   
  MFP_PN(C, 0 ),   //28  SPI0_SS0                   
  MFP_PN(E, 5 ),   //29  PWM5/TM1/TM1_EXT           
  MFP_PN(B, 11),   //30  TM3/PWM4                   
  MFP_PN(B, 10),   //31  TM2/UART2_RXD              
  MFP_PN(B, 9 ),   //32  TM1/UART2_TXD              
  MFP_PN(C, 11),   //33  SPI1_MOSI0                 
  MFP_PN(C, 10),   //34  SPI1_MISO0                 
  MFP_PN(C, 9 ),   //35  SPI1_CLK                   
  MFP_PN(C, 8 ),   //36  SPI1_SS0/MCLK              
  MFP_PN(A, 15),   //37  PWM3                       
  MFP_PN(A, 14),   //38  PWM2/AD15                  
  MFP_PN(A, 13),   //39  PWM1/AD14                  
  MFP_PN(A, 12),   //40  PWM0/AD13                  
  MFP_NULL,        //41  ICE_DAT                    
  MFP_NULL,        //42  ICE_CLK                    
  MFP_NULL,        //43  AVSS                       
  MFP_PN(A, 0 ),   //44  ADC0                       
  MFP_PN(A, 1 ),   //45  ADC1/AD12                  
  MFP_PN(A, 2 ),   //46  ADC2/AD11                  
  MFP_PN(A, 3 ),   //47  ADC3/AD10                  
  MFP_PN(A, 4 ),   //48  ADC4/AD9                   
  MFP_PN(A, 5 ),   //49  ADC5/AD8                   
  MFP_PN(A, 6 ),   //50  ADC6/AD7                   
  MFP_NULL,        //51  VREF                       
  MFP_NULL,        //52  AVDD                       
  MFP_PN(C, 7 ),   //53  ADC7/AD5                   
  MFP_PN(C, 6 ),   //54  ADC8/AD4                   
  MFP_PN(C, 15),   //55  ADC9/AD3                   
  MFP_PN(C, 14),   //56  ADC10/AD2                  
  MFP_PN(B, 15),   //57  INT1/TM0/ADC11/TM0_EXT/AD6 
  MFP_PN(F, 0 ),   //58  XT1_OUT                    
  MFP_PN(F, 1 ),   //59  XT1_IN                     
  MFP_NULL,        //60  nRESET                     
  MFP_NULL,        //61  VSS                        
  MFP_NULL,        //62  VDD                        
  MFP_NULL,        //63  VSS                        
  MFP_PN(B, 8 ),   //64  TM0/STADC/CLKO                                                                        
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWMA,PWM01_MODULE,PWMA_IRQn,1,500,{PA_12,SYS_GPA_MFP_PA12_PWM0,SYS_ALT_MFP_PA12_PWM0,SYS_ALT_MFP2_PA12_PWM0}},
	{PWMA,PWM01_MODULE,PWMA_IRQn,2,500,{PA_13,SYS_GPA_MFP_PA13_PWM1,SYS_ALT_MFP_PA13_PWM1,SYS_ALT_MFP2_PA13_PWM1}},
	{PWMA,PWM01_MODULE,PWMA_IRQn,3,500,{PA_14,SYS_GPA_MFP_PA14_PWM2,SYS_ALT_MFP_PA14_PWM2,SYS_ALT_MFP2_PA14_PWM2}},
	{PWMB,PWM01_MODULE,PWMB_IRQn,4,500,{PA_15,SYS_GPA_MFP_PA15_PWM3,SYS_ALT_MFP_PA15_PWM3,SYS_ALT_MFP2_PA15_PWM3}},
	{PWMB,PWM01_MODULE,PWMB_IRQn,5,500,{PB_11,SYS_GPB_MFP_PB11_PWM4,SYS_ALT_MFP_PB11_PWM4,SYS_ALT_MFP2_PB11_PWM4}},
	{PWMB,PWM01_MODULE,PWMB_IRQn,6,500,{PE_5 ,SYS_GPE_MFP_PE5_PWM5 ,SYS_ALT_MFP_PE5_PWM5 ,SYS_ALT_MFP2_PE5_PWM5 }},	
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
     {ADC,ADC_MODULE,0 ,{PA_0 ,SYS_GPA_MFP_PA0_ADC0  ,SYS_ALT_MFP_PA0_ADC0  ,SYS_ALT_MFP2_PA0_ADC0  }}, //0 
	 {ADC,ADC_MODULE,1 ,{PA_1 ,SYS_GPA_MFP_PA1_ADC1  ,SYS_ALT_MFP_PA1_ADC1  ,SYS_ALT_MFP2_PA1_ADC1  }}, //1 
	 {ADC,ADC_MODULE,2 ,{PA_2 ,SYS_GPA_MFP_PA2_ADC2  ,SYS_ALT_MFP_PA2_ADC2  ,SYS_ALT_MFP2_PA2_ADC2  }}, //2 
	 {ADC,ADC_MODULE,3 ,{PA_3 ,SYS_GPA_MFP_PA3_ADC3  ,SYS_ALT_MFP_PA3_ADC3  ,SYS_ALT_MFP2_PA3_ADC3  }}, //3 
	 {ADC,ADC_MODULE,4 ,{PA_4 ,SYS_GPA_MFP_PA4_ADC4  ,SYS_ALT_MFP_PA4_ADC4  ,SYS_ALT_MFP2_PA4_ADC4  }}, //4 
	 {ADC,ADC_MODULE,5 ,{PA_5 ,SYS_GPA_MFP_PA5_ADC5  ,SYS_ALT_MFP_PA5_ADC5  ,SYS_ALT_MFP2_PA5_ADC5  }}, //5 
	 {ADC,ADC_MODULE,6 ,{PA_6 ,SYS_GPA_MFP_PA6_ADC6  ,SYS_ALT_MFP_PA6_ADC6  ,SYS_ALT_MFP2_PA6_ADC6  }}, //6 
	 {ADC,ADC_MODULE,7 ,{PC_7 ,SYS_GPC_MFP_PC7_ADC7  ,SYS_ALT_MFP_PC7_ADC7  ,SYS_ALT_MFP2_PC7_ADC7  }}, //7 
	 {ADC,ADC_MODULE,6 ,{PC_6 ,SYS_GPC_MFP_PC6_ADC8  ,SYS_ALT_MFP_PC6_ADC8  ,SYS_ALT_MFP2_PC6_ADC8  }}, //6 
	 {ADC,ADC_MODULE,15,{PC_15,SYS_GPC_MFP_PC15_ADC9 ,SYS_ALT_MFP_PC15_ADC9 ,SYS_ALT_MFP2_PC15_ADC9 }}, //15
	 {ADC,ADC_MODULE,14,{PC_14,SYS_GPC_MFP_PC14_ADC10,SYS_ALT_MFP_PC14_ADC10,SYS_ALT_MFP2_PC14_ADC10}}, //14
	 {ADC,ADC_MODULE,15,{PB_15,SYS_GPB_MFP_PB15_ADC11,SYS_ALT_MFP_PB15_ADC11,SYS_ALT_MFP2_PB15_ADC11}}, //15
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
   {{PB_0,SYS_GPB_MFP_PB0_UART0_RXD,SYS_ALT_MFP_PB0_UART0_RXD,SYS_ALT_MFP2_PB0_UART0_RXD},
    {PB_1,SYS_GPB_MFP_PB1_UART0_TXD,SYS_ALT_MFP_PB1_UART0_TXD,SYS_ALT_MFP2_PB1_UART0_TXD}
   },
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
   {{PB_4,SYS_GPB_MFP_PB4_UART1_RXD,SYS_ALT_MFP_PB4_UART1_RXD,SYS_ALT_MFP2_PB4_UART1_RXD},
    {PB_5 ,SYS_GPB_MFP_PB5_UART1_TXD,SYS_ALT_MFP_PB5_UART1_TXD,SYS_ALT_MFP2_PB5_UART1_TXD}},
};
const UARTPinAlt_TypeDef UART2PinAlt[] = {
   {{PB_10,SYS_GPB_MFP_PB10_UART2_RXD,SYS_ALT_MFP_PB10_UART2_RXD,SYS_ALT_MFP2_PB10_UART2_RXD},
    {PB_9  ,SYS_GPB_MFP_PB9_UART2_TXD, SYS_ALT_MFP_PB9_UART2_TXD, SYS_ALT_MFP2_PB9_UART2_TXD}},
};
const UARTPinDescription UART_Desc[]={
   {UART0,UART0_MODULE,UART02_IRQn,UART0PinAlt},	
   {UART1,UART1_MODULE,UART1_IRQn ,UART1PinAlt},
   {UART2,UART2_MODULE,UART02_IRQn,UART2PinAlt},
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = { 
	{{PC_1,SYS_GPC_MFP_PC1_SPI0_CLK  ,SYS_ALT_MFP_PC1_SPI0_CLK  ,SYS_ALT_MFP2_PC1_SPI0_CLK  },
	 {PC_2,SYS_GPC_MFP_PC2_SPI0_MISO0,SYS_ALT_MFP_PC2_SPI0_MISO0,SYS_ALT_MFP2_PC2_SPI0_MISO0},
	 {PC_3,SYS_GPC_MFP_PC3_SPI0_MOSI0,SYS_ALT_MFP_PC3_SPI0_MOSI0,SYS_ALT_MFP2_PC3_SPI0_MOSI0},
	 {PC_0,SYS_GPC_MFP_PC0_SPI0_SS0  ,SYS_ALT_MFP_PC0_SPI0_SS0  ,SYS_ALT_MFP2_PC0_SPI0_SS0  }},
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = { 
	{{PC_9, SYS_GPC_MFP_PC9_SPI1_CLK   ,SYS_ALT_MFP_PC9_SPI1_CLK   ,SYS_ALT_MFP2_PC9_SPI1_CLK   },
	 {PC_10,SYS_GPC_MFP_PC10_SPI1_MISO0,SYS_ALT_MFP_PC10_SPI1_MISO0,SYS_ALT_MFP2_PC10_SPI1_MISO0},
	 {PC_11,SYS_GPC_MFP_PC11_SPI1_MOSI0,SYS_ALT_MFP_PC11_SPI1_MOSI0,SYS_ALT_MFP2_PC11_SPI1_MOSI0},
	 {PC_8, SYS_GPC_MFP_PC8_SPI1_SS0   ,SYS_ALT_MFP_PC8_SPI1_SS0   ,SYS_ALT_MFP2_PC8_SPI1_SS0   }},
};
const SPIPinDescription SPI_Desc[]={
  {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL1_SPI0_S_HCLK, SPI0PinAlt},
  {SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL1_SPI1_S_HCLK, SPI1PinAlt},
};  
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
	{{PA_8,SYS_GPA_MFP_PA8_I2C0_SDA,SYS_ALT_MFP_PA8_I2C0_SDA,SYS_ALT_MFP2_PA8_I2C0_SDA},
	 {PA_9,SYS_GPA_MFP_PA9_I2C0_SCL,SYS_ALT_MFP_PA9_I2C0_SCL,SYS_ALT_MFP2_PA9_I2C0_SCL}},
};

const I2CPinAlt_TypeDef I2C1PinAlt[] = {
	{{PA_10,SYS_GPA_MFP_PA10_I2C1_SDA,SYS_ALT_MFP_PA10_I2C1_SDA,SYS_ALT_MFP2_PA10_I2C1_SDA},
	 {PA_11,SYS_GPA_MFP_PA11_I2C1_SCL,SYS_ALT_MFP_PA11_I2C1_SCL,SYS_ALT_MFP2_PA11_I2C1_SCL}},
};

const I2CPinDescription I2C_Desc[]={	
 {I2C0,I2C0_MODULE,I2C0_IRQn,I2C0PinAlt},
 {I2C1,I2C1_MODULE,I2C1_IRQn,I2C1PinAlt},
};




#endif
