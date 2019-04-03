/*
  variant100.h
  
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

#define MFP_NULL {NULL, NULL, {NULL, NULL, NULL}}  
#define MFP_PN(a, b,c) {P##a,BIT##b,{(uint32_t)&SYS->P##a##_##c##_MFP, \
                         SYS_P##a##_##c##_MFP_P##a##b##_MFP_Msk, \
						 SYS_P##a##_##c##_MFP_P##a##b##_MFP_GP##a##b}}

#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  MFP_NULL,       //0
  MFP_PN(E,15,H), //1                                      
  MFP_PN(E,14,H), //2                                      
  MFP_PN(E,13,H), //3                                      
  MFP_PN(B,14,H), //4  nINT0/SPISS21                       
  MFP_PN(B,13,H), //5  AD1                                 
  MFP_PN(B,12,H), //6  AD0/CLKO                            
  MFP_NULL,       //7  X32_OUT                             
  MFP_NULL,       //8  X32_IN                              
  MFP_PN(A,11,H), //9  I2C1SCK/nRD/SC0RST/MOSI20           
  MFP_PN(A,10,H), //10 I2C1SDA/nWR/SC0PWR/MISO20           
  MFP_PN(A,9, H), //11 I2C0SCL/SC0DAT/SPICLK2              
  MFP_PN(A,8, H), //12 I2C0SDA/SC0CLK/SPISS20              
  MFP_PN(D,8, H), //13                                     
  MFP_PN(D,9, H), //14                                     
  MFP_PN(D,10,H), //15                                     
  MFP_PN(D,11,H), //16                                     
  MFP_PN(D,12,H), //17                                     
  MFP_PN(D,13,H), //18                                     
  MFP_PN(B,4, L), //19 RX1/SC0CD/SPISS20                   
  MFP_PN(B,5, L), //20 TX1/SPICLK2                         
  MFP_PN(B,6, L), //21 RTSn1/ALE/MISO20                    
  MFP_PN(B,7, L), //22 CTSn1/nCS/MOSI20                    
  MFP_NULL,       //23 LDO_CAP                             
  MFP_NULL,       //24 VDD                                 
  MFP_NULL,       //25 VSS                                 
  MFP_PN(E,8, H), //26                                     
  MFP_PN(E,7, L), //27                                     
  MFP_NULL,       //28 USB_VBUS                                                       
  MFP_NULL,       //29 USB_VDD33_CAP                       
  MFP_NULL,       //30 USB_D-                              
  MFP_NULL,       //31 USB_D+                              
  MFP_PN(B,0, L), //32 RX0/MOSI10                          
  MFP_PN(B,1, L), //33 TX0/MISO10                          
  MFP_PN(B,2, L), //34 RTSn0/nWRL/SPICLK1                  
  MFP_PN(B,3, L), //35 CTSn0/nWRH/SPISS10                  
  MFP_PN(D,6, L), //36                                     
  MFP_PN(D,7, L), //37                                     
  MFP_PN(D,14,H), //38                                     
  MFP_PN(D,15,H), //39                                     
  MFP_PN(C,5, L), //40 MOSI01                              
  MFP_PN(C,4, L), //41 MISO01                              
  MFP_PN(C,3, L), //42 MOSI00/I2SDO/SC1RST                 
  MFP_PN(C,2, L), //43 MISO00/I2SDI/SC1PWR                 
  MFP_PN(C,1, L), //44 SPICLK0/I2SBCLK/SC1DAT              
  MFP_PN(C,0, L), //45 SPISS00/I2SLRCLK/SC1CLK             
  MFP_PN(E,6, L), //46                                     
  MFP_PN(E,5, L), //47 PWM1CH1                             
  MFP_PN(B,11,H), //48 TMR3/PWM1CH0/MISO00                 
  MFP_PN(B,10,H), //49 SPISS01/TMR2/MOSI00                 
  MFP_PN(B,9, H), //50 SPISS11/TMR1/nINT0                  
  MFP_PN(E,4, L), //51 MOSI00                              
  MFP_PN(E,3, L), //52 MISO00                              
  MFP_PN(E,2, L), //53 SPICLK0                             
  MFP_PN(E,1, L), //54 PWM1CH3/SPISS00                     
  MFP_PN(E,0, L), //55 PWM1CH2/I2SMCLK                     
  MFP_PN(C,13,H), //56 MOSI11/PWM1CH1/SNOOPER/nINT1/I2C0SCK
  MFP_PN(C,12,H), //57 MISO11/PWM1CH0/nINT0/I2C0SDA        
  MFP_PN(C,11,H), //58 MOSI10/TX1                          
  MFP_PN(C,10,H), //59 MISO10/RX1                          
  MFP_PN(C,9, H), //60 SPICLK1/I2C1SCK                     
  MFP_PN(C,8, H), //61 SPISS10/MCLK/I2C1SDA                
  MFP_PN(A,15,H), //62 PWM0CH3/I2SMCLK/TC3/TX0             
  MFP_PN(A,14,H), //63 PWM0CH2/AD15/TC2/RX0                
  MFP_PN(A,13,H), //64 PWM0CH1/AD14/TC1/I2C0SCK            
  MFP_PN(A,12,H), //65 PWM0CH0/AD13/TC0/I2C0SDA            
#if USE_ICE == 0   
  MFP_PN(F,0, L), //66  nINT0/ICE_DAT    
  MFP_PN(F,1, L), //67  CLKO/nINT1/ICE_CK
#else
  MFP_NULL,       //66  nINT0/ICE_DAT    
  MFP_NULL,       //67  CLKO/nINT1/ICE_CK
#endif
  MFP_NULL,       //68  VDD  
  MFP_NULL,       //69  VSS  
  MFP_NULL,       //70  AVSS 
  MFP_PN(A,0, L), //71  ADC0                        
  MFP_PN(A,1, L), //72  ADC1/AD12                   
  MFP_PN(A,2, L), //73  ADC2/AD11/RX1               
  MFP_PN(A,3, L), //74  ADC3/AD10/TX1               
  MFP_PN(A,4, L), //75  ADC4/AD9/I2C0SDA            
  MFP_PN(A,5, L), //76  ADC5/AD8/I2C0SCK            
  MFP_PN(A,6, L), //77  ADC6/AD7/TC3/PWM0CH3        
  MFP_PN(A,7, L), //78  ADC7/AD6/TC2/PWM0CH2        
  MFP_NULL,       //79  VREF                        
  MFP_NULL,       //80  AVDD                        
  MFP_PN(D,0, L), //81  RX1/SPISS20/SC1CLK          
  MFP_PN(D,1, L), //82  TX1/SPICLK2/SC1DAT          
  MFP_PN(D,2, L), //83  RTSn1/I2SLRCLK/MISO20/SC1PWR
  MFP_PN(D,3, L), //84  CTSn1/I2SBCLK/MOSI20/SC1RST 
  MFP_PN(D,4, L), //85  I2SDI/MISO21/SC1CD          
  MFP_PN(D,5, L), //86  I2SDO/MOSI21                
  MFP_PN(C,7, L), //87  AD5/TC1/PWM0CH1             
  MFP_PN(C,6, L), //88  AD4/TC0/SC1CD/PWM0CH0       
  MFP_PN(C,15,H), //89  AD3/TC0/PWM1CH2             
  MFP_PN(C,14,H), //90  AD2/PWM1CH3                 
  MFP_PN(B,15,H), //91  nINT1/SNOOPER               
  MFP_NULL,       //92  XT1_OUT                     
  MFP_NULL,       //93  XT1_IN                      
  MFP_NULL,       //94  nRESET                      
  MFP_NULL,       //95  VSS                         
  MFP_NULL,       //96  VDD                         
  MFP_PN(F,4, L), //97  I2C0SDA                     
  MFP_PN(F,5, L), //98  I2C0SCK                     
  MFP_NULL,       //99  PVSS                        
  MFP_PN(B,8, H), //100 ADCTRG/TMR0/nINT0  
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[] = {
  {PWM0, PWM0_CH01_MODULE, PWM0_IRQn, 0, 500, {PA_12, SYS_PA_H_MFP_PA12_MFP_PWM0_CH0}}, //0
  {PWM0, PWM0_CH01_MODULE, PWM0_IRQn, 1, 500, {PA_13, SYS_PA_H_MFP_PA13_MFP_PWM0_CH1}}, //1
  {PWM0, PWM0_CH23_MODULE, PWM0_IRQn, 2, 500, {PA_14, SYS_PA_H_MFP_PA14_MFP_PWM0_CH2}}, //2
  {PWM0, PWM0_CH23_MODULE, PWM0_IRQn, 3, 500, {PA_15, SYS_PA_H_MFP_PA15_MFP_PWM0_CH3}}, //3
  {PWM1, PWM1_CH01_MODULE, PWM1_IRQn, 0, 500, {PC_12, SYS_PC_H_MFP_PC12_MFP_PWM1_CH0}}, //4
  {PWM1, PWM1_CH01_MODULE, PWM1_IRQn, 1, 500, {PC_13, SYS_PC_H_MFP_PC13_MFP_PWM1_CH1}}, //5
  {PWM1, PWM1_CH23_MODULE, PWM1_IRQn, 2, 500, {PC_15, SYS_PC_H_MFP_PC15_MFP_PWM1_CH2}}, //6
  {PWM1, PWM1_CH23_MODULE, PWM1_IRQn, 3, 500, {PC_14, SYS_PC_H_MFP_PC14_MFP_PWM1_CH3}}, //7
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[] = {
  {ADC, ADC_MODULE, 0, {PA_0, SYS_PA_L_MFP_PA0_MFP_ADC_CH0}}, //0
  {ADC, ADC_MODULE, 1, {PA_1, SYS_PA_L_MFP_PA1_MFP_ADC_CH1}}, //1
  {ADC, ADC_MODULE, 2, {PA_2, SYS_PA_L_MFP_PA2_MFP_ADC_CH2}}, //2
  {ADC, ADC_MODULE, 3, {PA_3, SYS_PA_L_MFP_PA3_MFP_ADC_CH3}}, //3
  {ADC, ADC_MODULE, 4, {PA_4, SYS_PA_L_MFP_PA4_MFP_ADC_CH4}}, //4
  {ADC, ADC_MODULE, 5, {PA_5, SYS_PA_L_MFP_PA5_MFP_ADC_CH5}}, //5
  {ADC, ADC_MODULE, 6, {PA_6, SYS_PA_L_MFP_PA6_MFP_ADC_CH6}}, //6
  {ADC, ADC_MODULE, 7, {PA_7, SYS_PA_L_MFP_PA7_MFP_ADC_CH7}}, //7
  {ADC, ADC_MODULE, 8, {PD_0, SYS_PD_L_MFP_PD0_MFP_ADC_CH8}}, //8
  {ADC, ADC_MODULE, 9, {PD_1, SYS_PD_L_MFP_PD1_MFP_ADC_CH9}}, //9
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = {
    {{PC_1, SYS_PC_L_MFP_PC1_MFP_SPI0_SCLK },
  	 {PC_3, SYS_PC_L_MFP_PC3_MFP_SPI0_MOSI0},
     {PC_2, SYS_PC_L_MFP_PC2_MFP_SPI0_MISO0},
     {PC_0, SYS_PC_L_MFP_PC0_MFP_SPI0_SS0}},  /*Loc 0*/
    {{PE_2, SYS_PE_L_MFP_PE2_MFP_SPI0_SCLK },
 	 {PE_4, SYS_PE_L_MFP_PE4_MFP_SPI0_MOSI0},
     {PE_3, SYS_PE_L_MFP_PE3_MFP_SPI0_MISO0},
	 {PE_1, SYS_PE_L_MFP_PE1_MFP_SPI0_SS0}},  /*Loc 1*/
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = {
    {{PB_2, SYS_PB_L_MFP_PB2_MFP_SPI1_SCLK }, {PB_0, SYS_PB_L_MFP_PB0_MFP_SPI1_MOSI0},
      {PB_1, SYS_PB_L_MFP_PB1_MFP_SPI1_MISO0}, {PB_3, SYS_PB_L_MFP_PB3_MFP_SPI1_SS0}},   /*Loc 0*/
    {{PC_9, SYS_PC_H_MFP_PC9_MFP_SPI1_SCLK }, {PC_11, SYS_PC_H_MFP_PC11_MFP_SPI1_MOSI0},
      {PC_10, SYS_PC_H_MFP_PC10_MFP_SPI1_MISO0}, {PC_8, SYS_PC_H_MFP_PC8_MFP_SPI1_SS0}}, /*Loc 1*/
};
const SPIPinAlt_TypeDef SPI2PinAlt[] = { 
    {{PA_9, SYS_PA_H_MFP_PA9_MFP_SPI2_SCLK }, {PA_11, SYS_PA_H_MFP_PA11_MFP_SPI2_MOSI0},
      {PA_10, SYS_PA_H_MFP_PA10_MFP_SPI2_MISO0}, {PA_8, SYS_PA_H_MFP_PA8_MFP_SPI2_SS0}}, /*Loc 0*/
    {{PB_5, SYS_PB_L_MFP_PB5_MFP_SPI2_SCLK }, {PB_7, SYS_PB_L_MFP_PB7_MFP_SPI2_MOSI0},
      {PB_6, SYS_PB_L_MFP_PB6_MFP_SPI2_MISO0}, {PB_4, SYS_PB_L_MFP_PB4_MFP_SPI2_SS0}},   /*Loc 1*/
};
const SPIPinDescription SPI_Desc[] = {
  { SPI0, SPI0_MODULE, SPI0_IRQn, CLK_CLKSEL2_SPI0_S_HCLK, SPI0PinAlt},
  { SPI1, SPI1_MODULE, SPI1_IRQn, CLK_CLKSEL2_SPI1_S_HCLK, SPI1PinAlt},
  { SPI2, SPI2_MODULE, SPI2_IRQn, CLK_CLKSEL2_SPI2_S_HCLK, SPI2PinAlt},
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
  {{PA_14,SYS_PA_H_MFP_PA14_MFP_UART0_RX}, 
   {PA_15,SYS_PA_H_MFP_PA15_MFP_UART0_TX}},  /* Loc 0*/
  {{PB_0, SYS_PB_L_MFP_PB0_MFP_UART0_RX }, 
   {PB_1, SYS_PB_L_MFP_PB1_MFP_UART0_TX }},  /* Loc 1*/
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
  {{PB_4, SYS_PB_L_MFP_PB4_MFP_UART1_RX},
   {PB_5, SYS_PB_L_MFP_PB5_MFP_UART1_TX }},  /* Loc 0*/
  {{PA_2, SYS_PA_L_MFP_PA2_MFP_UART1_RX},
   {PA_3, SYS_PA_L_MFP_PA3_MFP_UART1_TX }},  /* Loc 1*/
  {{PD_0, SYS_PD_L_MFP_PD0_MFP_UART1_RX},
   {PD_1, SYS_PD_L_MFP_PD1_MFP_UART1_TX }},  /* Loc 2*/
  {{PC_10,SYS_PC_H_MFP_PC10_MFP_UART1_RX},
   {PC_11,SYS_PC_H_MFP_PC11_MFP_UART1_TX}},  /* Loc 3*/
};
const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART0_IRQn, UART0PinAlt},
  {UART1, UART1_MODULE, UART1_IRQn, UART1PinAlt}, 
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
  {{PA_9, SYS_PA_H_MFP_PA9_MFP_I2C0_SCL},
   {PA_8, SYS_PA_H_MFP_PA8_MFP_I2C0_SDA }},  /* Loc 0*/
  {{PA_5, SYS_PA_L_MFP_PA5_MFP_I2C0_SCL},
   {PA_4, SYS_PA_L_MFP_PA4_MFP_I2C0_SDA }},  /* Loc 1*/
  {{PA_13,SYS_PA_H_MFP_PA13_MFP_I2C0_SCL},
   {PA_12,SYS_PA_H_MFP_PA12_MFP_I2C0_SDA}},  /* Loc 2*/
};
const I2CPinAlt_TypeDef I2C1PinAlt[] = {
  {{PA_11,SYS_PA_H_MFP_PA11_MFP_I2C1_SCL},
   {PA_10,SYS_PA_H_MFP_PA10_MFP_I2C1_SDA}},  /* Loc 0 */
};
const I2CPinDescription I2C_Desc[] = {
  {I2C0, I2C0_MODULE,I2C0_IRQn, I2C0PinAlt},
  {I2C1, I2C1_MODULE,I2C1_IRQn, I2C1PinAlt},
};
#endif
