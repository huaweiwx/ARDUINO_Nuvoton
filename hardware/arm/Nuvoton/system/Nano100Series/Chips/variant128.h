/*
  variant128.h
  
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
  MFP_NULL       , // 0
  MFP_PN(E, 13,H), // 1   LCD_SEG27                                    
  MFP_PN(B, 14,H), // 2   INT0/SC2_CD/SPI2_SS1/LCD_SEG26               
  MFP_PN(B, 13,H), // 3   EBI_AD1/LCD_SEG25                            
  MFP_PN(B, 12,H), // 4   EBI_AD0/FCLKO/LCD_SEG24                      
  MFP_NULL       , // 5   NC                                           
  MFP_NULL       , // 6   X32_OUT                                      
  MFP_NULL       , // 7   X32_IN                                       
  MFP_NULL       , // 8   NC                                           
  MFP_PN(A, 11,H), // 9   I2C1_SCL/EBI_nRD/SC0_RST/SPI2_MOSI0/LCD_SEG23
  MFP_PN(A, 10,H), // 10  I2C1_SDA/EBI_nWR/SC0_PWR/SPI2_MISO0/LCD_SEG22
  MFP_PN(A, 9 ,H), // 11  I2C0_SCL/SC0_DAT/SPI2_CLK/LCD_SEG21          
  MFP_PN(A, 8 ,H), // 12  I2C0_SDA/SC0_CLK/SPI2_SS0/LCD_SEG20          
  MFP_PN(D, 8 ,H), // 13  LCD_SEG19                                    
  MFP_PN(D, 9 ,H), // 14  LCD_SEG18                                    
  MFP_PN(D, 10,H), // 15  LCD_SEG17                                    
  MFP_PN(D, 11,H), // 16  LCD_SEG16                                    
  MFP_PN(D, 12,H), // 17  LCD_SEG15                                    
  MFP_PN(D, 13,H), // 18  LCD_SEG14                                    
  MFP_PN(B, 4 ,L), // 19  UART1_RXD/SC0_CD/SPI2_SS0/LCD_SEG13          
  MFP_PN(B, 5 ,L), // 20  UART1_TXD/SC0_RST/SPI2_CLK/LCD_SEG12         
  MFP_PN(B, 6 ,L), // 21  UART1_RTSn/EBI_ALE/SPI2_MISO0/LCD_SEG11      
  MFP_PN(B, 7 ,L), // 22  UART1_CTSn/EBI_nCS/SPI2_MOSI0/LCD_SEG10      
  MFP_NULL       , // 23  NC                                           
  MFP_NULL       , // 24  LDO_CAP                                      
  MFP_NULL       , // 25  NC                                           
  MFP_NULL       , // 26  NC                                           
  MFP_NULL       , // 27  VDD                                          
  MFP_NULL       , // 28  NC                                           
  MFP_NULL       , // 29  VSS                                          
  MFP_NULL       , // 30  VSS                                          
  MFP_NULL       , // 31  VSS                                          
  MFP_NULL       , // 32  VSS                                          
  MFP_PN(E, 12,H), // 33                                               
  MFP_PN(E, 11,H), // 34                                               
  MFP_PN(E, 10,H), // 35                                               
  MFP_PN(E, 9 ,H), // 36                                               
  MFP_PN(E, 8 ,H), // 37  LCD_SEG9                                     
  MFP_PN(E, 7 ,L), // 38  LCD_SEG8                                     
  MFP_NULL       , // 39  NC                                           
  MFP_NULL       , // 40  USB_VBUS                                     
  MFP_NULL       , // 41  USB_VDD33_CAP                                
  MFP_NULL       , // 42  USB_D-                                       
  MFP_NULL       , // 43  USB_D+                                       
  MFP_PN(B, 0 ,L), // 44  UART0_RXD/SPI1_MOSI0/LCD_SEG7                
  MFP_PN(B, 1 ,L), // 45  UART0_TXD/SPI1_MISO0/LCD_SEG6                
  MFP_PN(B, 2 ,L), // 46  UART0_RTSn/EBI_nWRL/SPI1_CLK/LCD_SEG5        
  MFP_PN(B, 3 ,L), // 47  UART0_CTSn/EBI_nWRH/SPI1_SS0/LCD_SEG4        
  MFP_PN(D, 6 ,L), // 48  LCD_SEG3                                     
  MFP_PN(D, 7 ,L), // 49  LCD_SEG2                                     
  MFP_PN(D, 14,H), // 50  LCD_SEG1                                     
  MFP_PN(D, 15,H), // 51  LCD_SEG0                                     
  MFP_PN(C, 5 ,L), // 52  SPI0_MOSI1/LCD_COM3
  MFP_PN(C, 4 ,L), // 53  SPI0_MISO1/LCD_COM2
  MFP_PN(C, 3 ,L), // 54  SPI0_MOSI0/I2S_DO/SC1_RST/LCD_COM1
  MFP_PN(C, 2 ,L), // 55  SPI0_MISO0/I2S_DI/SC1_PWR/LCD_COM0
  MFP_PN(C, 1 ,L), // 56  SPI0_CLK/I2S_BCLK/SC1_DAT/LCD_DH2 
  MFP_PN(C, 0 ,L), // 57  SPI0_SS0/I2S_LRCLK/SC1_CLK/LCD_DH1
  MFP_PN(E, 6 ,L), // 58
  MFP_NULL       , // 59  LCD_VLCD
  MFP_NULL       , // 60  NC      
  MFP_PN(E, 5 ,L), // 61
  MFP_PN(B, 11,H), // 62  PWM1_CH0/TM3/SC2_DAT/SPI0_MISO0/LCD_V1    
  MFP_PN(B, 10,H), // 63  SPI0_SS1/TM2/SC2_CLK/SPI0_MOSI0/LCD_V2    
  MFP_PN(B, 9 ,H), // 64  SPI1_SS1/TM1/SC2_RST/INT0/LCD_V3          
  MFP_PN(E, 4 ,L), // 65  SPI0_MOSI0                                
  MFP_PN(E, 3 ,L), // 66  SPI0_MISO0                                
  MFP_PN(E, 2 ,L), // 67  SPI0_CLK                                  
  MFP_PN(E, 1 ,L), // 68  PWM1_CH3/SPI0_SS0                         
  MFP_PN(E, 0 ,L), // 69  PWM1_CH2/I2S_MCLK                         
  MFP_PN(C, 13,H), // 70  SPI1_MOSI1/PWM1_CH1/SNOOPER/INT1/I2C0_SCL 
  MFP_PN(C, 12,H), // 71  SPI1_MISO1/PWM1_CH0/INT0/I2C0_SDA        
  MFP_PN(C, 11,H), // 72  SPI1_MOSI0/UART1_TXD                      
  MFP_PN(C, 10,H), // 73  SPI1_MISO0/UART1_RXD                      
  MFP_PN(C, 9 ,H), // 74  SPI1_CLK/I2C1_SCL                         
  MFP_PN(C, 8 ,H), // 75  SPI1_SS0/EBI_MCLK/I2C1_SDA               
  MFP_PN(A, 15,H), // 76  PWM0_CH3/I2S_MCLK/TC3/SC0_PWR/UART0_TXD   
  MFP_PN(A, 14,H), // 77  PWM0_CH2/EBI_AD15/TC2/UART0_RXD           
  MFP_PN(A, 13,H), // 78  PWM0_CH1/EBI_AD14/TC1/I2C0_SCL           
  MFP_PN(A, 12,H), // 79  PWM0_CH0/EBI_AD13/TC0/I2C0_SDA            
#if USE_ICE == 0                                  
  MFP_PN(F, 0 ,L), // 80  INT0/ICE_DAT                             
  MFP_PN(F, 1 ,L), // 81  FCLKO/INT1/ICE_CLK
#else              //     
  MFP_NULL       , // 80  INT0/ICE_DAT      
  MFP_NULL       , // 81  FCLKO/INT1/ICE_CLK
#endif                    
  MFP_NULL       , // 82  NC                                        
  MFP_NULL       , // 83  VDD                                       
  MFP_NULL       , // 84  NC                                        
  MFP_NULL       , // 85  VSS                                       
  MFP_NULL       , // 86  VSS                                       
  MFP_NULL       , // 87  AVSS                                      
  MFP_NULL       , // 88  AVSS                                      
  MFP_PN(A, 0 ,L), // 89  AD0/SC2_CD                                
  MFP_PN(A, 1 ,L), // 90  AD1/EBI_AD12                              
  MFP_PN(A, 2 ,L), // 91  AD2/EBI_AD11/UART1_RXD                    
  MFP_PN(A, 3 ,L), // 92  AD3/EBI_AD10/UART1_TXD                    
  MFP_PN(A, 4 ,L), // 93  AD4/EBI_AD9/SC2_PWR/I2C0_SDA/LCD_SEG39    
  MFP_PN(A, 5 ,L), // 94  AD5/EBI_AD8/SC2_RST/I2C0_SCL/LCD_SEG38    
  MFP_PN(A, 6 ,L), // 95  AD6/EBI_AD7/TC3/SC2_CLK/PWM0_CH3/LCD_SEG37
  MFP_PN(A, 7 ,L), // 96  AD7/EBI_AD6/TC2/SC2_DAT/PWM0_CH2/LCD_SEG36
  MFP_NULL       , // 97  VREF                                        
  MFP_NULL       , // 98  NC                                          
  MFP_NULL       , // 99  AVDD                                        
  MFP_PN(D, 0 ,L), // 100 UART1_RXD/SPI2_SS0/SC1_CLK/AD8              
  MFP_PN(D, 1 ,L), // 101 UART1_TXD/SPI2_CLK/SC1_DAT/AD9              
  MFP_PN(D, 2 ,L), // 102 UART1_RTSn/I2S_LRCLK/SPI2_MISO0/SC1_PWR/AD10
  MFP_PN(D, 3 ,L), // 103 UART1_CTSn/I2S_BCLK/SPI2_MOSI0/SC1_RST/AD11 
  MFP_NULL,        // 104 NC                                          
  MFP_PN(D, 4 ,L), // 105 I2S_DI/SPI2_MISO1/SC1_CD/LCD_SEG35          
  MFP_PN(D, 5 ,L), // 106 I2S_DO/SPI2_MOSI1/LCD_SEG34                 
  MFP_PN(C, 7 ,L), // 107 DA1_OUT/EBI_AD5/TC1/PWM0_CH1                
  MFP_PN(C, 6 ,L), // 108 DA0_OUT/EBI_AD4/TC0/SC1_CD/PWM0_CH0         
  MFP_PN(C, 15,H), // 109 EBI_AD3/TC0/PWM1_CH2/LCD_SEG33              
  MFP_PN(C, 14,H), // 110 EBI_AD2/PWM1_CH3/LCD_SEG32                  
  MFP_PN(B, 15,H), // 111 INT1/SNOOPER/SC1_CD/LCD_SEG31               
  MFP_NULL       , // 112 NC                                          
  MFP_NULL       , // 113 XT1_IN                                      
  MFP_NULL       , // 114 XT1_OUT                                     
  MFP_NULL       , // 115 NC                                          
  MFP_NULL       , // 116 nRESET                                      
  MFP_NULL       , // 117 VSS                                         
  MFP_NULL       , // 118 VSS                                         
  MFP_NULL       , // 119 NC                                          
  MFP_NULL       , // 120 VDD                                         
  MFP_NULL       , // 121 NC                                          
  MFP_PN(F, 4 ,L), // 122 I2C0_SDA                                    
  MFP_PN(F, 5 ,L), // 123 I2C0_SCL                                    
  MFP_NULL       , // 124 VSS                                         
  MFP_NULL       , // 125 PVSS                                        
  MFP_PN(B, 8 ,H), // 126 STADC/TM0/INT0/SC2_PWR/LCD_SEG30            
  MFP_PN(E, 15,H), // 127 LCD_SEG29                                   
  MFP_PN(E, 14,H), // 128 LCD_SEG28                                   
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
    {{PC_1, SYS_PC_L_MFP_PC1_MFP_SPI0_SCLK }, {PC_3, SYS_PC_L_MFP_PC3_MFP_SPI0_MOSI0},
      {PC_2, SYS_PC_L_MFP_PC2_MFP_SPI0_MISO0}, {PC_0, SYS_PC_L_MFP_PC0_MFP_SPI0_SS0}},  /*Loc 0*/
    {{PE_2, SYS_PE_L_MFP_PE2_MFP_SPI0_SCLK }, {PE_4, SYS_PE_L_MFP_PE4_MFP_SPI0_MOSI0},
      {PE_3, SYS_PE_L_MFP_PE3_MFP_SPI0_MISO0}, {PE_1, SYS_PE_L_MFP_PE1_MFP_SPI0_SS0}},  /*Loc 1*/
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
  {{PA_14,SYS_PA_H_MFP_PA14_MFP_UART0_RX}, {PA_15,SYS_PA_H_MFP_PA15_MFP_UART0_TX}},  /* Loc 0*/
  {{PB_0, SYS_PB_L_MFP_PB0_MFP_UART0_RX }, {PB_1, SYS_PB_L_MFP_PB1_MFP_UART0_TX }},  /* Loc 1*/
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
  {{PB_4, SYS_PB_L_MFP_PB4_MFP_UART1_RX }, {PB_5, SYS_PB_L_MFP_PB5_MFP_UART1_TX }},  /* Loc 0*/
  {{PA_2, SYS_PA_L_MFP_PA2_MFP_UART1_RX }, {PA_3, SYS_PA_L_MFP_PA3_MFP_UART1_TX }},  /* Loc 1*/
  {{PD_0, SYS_PD_L_MFP_PD0_MFP_UART1_RX},  {PD_1, SYS_PD_L_MFP_PD1_MFP_UART1_TX }},  /* Loc 2*/
  {{PC_10,SYS_PC_H_MFP_PC10_MFP_UART1_RX}, {PC_11,SYS_PC_H_MFP_PC11_MFP_UART1_TX}},  /* Loc 3*/
};
const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART0_IRQn, UART0PinAlt},
  {UART1, UART1_MODULE, UART1_IRQn, UART1PinAlt}, 
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
  {{PA_9, SYS_PA_H_MFP_PA9_MFP_I2C0_SCL}, {PA_8, SYS_PA_H_MFP_PA8_MFP_I2C0_SDA }},  /* Loc 0*/
  {{PA_5, SYS_PA_L_MFP_PA5_MFP_I2C0_SCL}, {PA_4, SYS_PA_L_MFP_PA4_MFP_I2C0_SDA }},  /* Loc 1*/
  {{PA_13,SYS_PA_H_MFP_PA13_MFP_I2C0_SCL},{PA_12,SYS_PA_H_MFP_PA12_MFP_I2C0_SDA}},  /* Loc 2*/
};
const I2CPinAlt_TypeDef I2C1PinAlt[] = {
  {{PA_11,SYS_PA_H_MFP_PA11_MFP_I2C1_SCL},{PA_10,SYS_PA_H_MFP_PA10_MFP_I2C1_SDA}},  /* Loc 0 */
};
const I2CPinDescription I2C_Desc[] = {
  {I2C0, I2C0_MODULE,I2C0_IRQn, I2C0PinAlt},
  {I2C1, I2C1_MODULE,I2C1_IRQn, I2C1PinAlt},
};
#endif
