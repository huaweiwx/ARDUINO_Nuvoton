/*
  variant48.h
  
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
  MFP_NULL,           // 0 
  MFP_PN(B, 12,H),    // 1  EBI_AD0/FCLKO                          
  MFP_NULL,           // 2  X32_OUT                                
  MFP_NULL,           // 3  X32_IN                                 
  MFP_PN(A, 11,H),    // 4  I2C1_SCL/EBI_nRD/SC0_RST/SPI2_MOSI0    
  MFP_PN(A, 10,H),    // 5  I2C1_SDA/EBI_nWR/SC0_PWR/SPI2_MISO0    
  MFP_PN(A, 9, H),    // 6  I2C0_SCL/SC0_DAT/SPI2_CLK              
  MFP_PN(A, 8, H),    // 7  I2C0_SDA/SC0_CLK/SPI2_SS0              
  MFP_PN(B, 4, L),    // 8  UART1_RXD/SC0_CD/SPI2_SS0              
  MFP_PN(B, 5, L),    // 9  UART1_TXD/SC0_RST/SPI2_CLK             
  MFP_NULL,           // 10 LDO_CAP                                
  MFP_NULL,           // 11 VDD                                    
  MFP_NULL,           // 12 VSS                                    
  MFP_NULL,           // 13 USB_VBUS                               
  MFP_NULL,           // 14 USB_VDD33_CAP                          
  MFP_NULL,           // 15 USB_D-                                 
  MFP_NULL,           // 16 USB_D+                                 
  MFP_PN(B, 0, L),    // 17 UART0_RXD/SPI1_MOSI0                   
  MFP_PN(B, 1, L),    // 18 UART0_TXD/SPI1_MISO0                   
  MFP_PN(B, 2, L),    // 19 UART0_RTSn/EBI_nWRL/SPI1_CLK           
  MFP_PN(B, 3, L),    // 20 UART0_CTSn/EBI_nWRH/SPI1_SS0           
  MFP_PN(C, 3, L),    // 21 SPI0_MOSI0/I2S_DO/SC1_RST              
  MFP_PN(C, 2, L),    // 22 SPI0_MISO0/I2S_DI/SC1_PWR              
  MFP_PN(C, 1, L),    // 23 SPI0_CLK/I2S_BCLK/SC1_DAT              
  MFP_PN(C, 0, L),    // 24 SPI0_SS0/I2S_LRCLK/SC1_CLK             
  MFP_PN(A, 15,H),    // 25 PWM0_CH3/I2S_MCLK/TC3/SC0_PWR/UART0_TXD
  MFP_PN(A, 14,H),    // 26 PWM0_CH2/EBI_AD15/TC2/UART0_RXD        
  MFP_PN(A, 13,H),    // 27 PWM0_CH1/EBI_AD14/TC1/I2C0_SCL         
  MFP_PN(A, 12,H),    // 28 PWM0_CH0/EBI_AD13/TC0/I2C0_SDA         
#if USE_ICE == 0
  MFP_PN(F, 0, L),    // 29 INT0/ICE_DAT                          
  MFP_PN(F, 1, L),    // 30 FCLKO/INT1/ICE_CLK
#else
  MFP_NULL,           // 29 INT0/ICE_DAT      
  MFP_NULL,           // 30 FCLKO/INT1/ICE_CLK
#endif
  MFP_NULL,           // 31 AVSS                               
  MFP_PN(A, 0, L),    // 32 AD0/SC2_CD                         
  MFP_PN(A, 1, L),    // 33 AD1/EBI_AD12                       
  MFP_PN(A, 2, L),    // 34 AD2/EBI_AD11/UART1_RXD             
  MFP_PN(A, 3, L),    // 35 AD3/EBI_AD10/UART1_TXD             
  MFP_PN(A, 4, L),    // 36 AD4/EBI_AD9/SC2_PWR/I2C0_SDA       
  MFP_PN(A, 5, L),    // 37 AD5/EBI_AD8/SC2_RST/I2C0_SCL       
  MFP_PN(A, 6, L),    // 38 AD6/EBI_AD7/TC3/SC2_CLK/PWM0_CH3   
  MFP_NULL,           // 39 VREF                               
  MFP_NULL,           // 40 AVDD                               
  MFP_PN(C, 7, L),    // 41 DA1_OUT/EBI_AD5/TC1/PWM0_CH1       
  MFP_PN(C, 6, L),    // 42 DA0_OUT/EBI_AD4/TC0/SC1_CD/PWM0_CH0
  MFP_PN(B, 15,H),    // 43 INT1/SNOOPER/SC1_CD                
  MFP_NULL,           // 44 XT1_IN                             
  MFP_NULL,           // 45 XT1_OUT                            
  MFP_NULL,           // 46 nRESET                             
  MFP_NULL,           // 47 PVSS                               
  MFP_PN(B, 8, H),    // 48 STADC/TM0/INT0/SC2_PWR             
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[] = {
  {PWM0, PWM0_CH01_MODULE, PWM0_IRQn, 0, 500, {PA_12, SYS_PA_H_MFP_PA12_MFP_PWM0_CH0}}, //0
  {PWM0, PWM0_CH01_MODULE, PWM0_IRQn, 1, 500, {PA_13, SYS_PA_H_MFP_PA13_MFP_PWM0_CH1}}, //1
  {PWM0, PWM0_CH23_MODULE, PWM0_IRQn, 2, 500, {PA_14, SYS_PA_H_MFP_PA14_MFP_PWM0_CH2}}, //2
  {PWM0, PWM0_CH23_MODULE, PWM0_IRQn, 3, 500, {PA_15, SYS_PA_H_MFP_PA15_MFP_PWM0_CH3}}, //3
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
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = {
    {{PC_1, SYS_PC_L_MFP_PC1_MFP_SPI0_SCLK }, {PC_3, SYS_PC_L_MFP_PC3_MFP_SPI0_MOSI0}, /* Loc 0 */
      {PC_2, SYS_PC_L_MFP_PC2_MFP_SPI0_MISO0}, {PC_0, SYS_PC_L_MFP_PC0_MFP_SPI0_SS0}}
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = {
    {{PB_2, SYS_PB_L_MFP_PB2_MFP_SPI1_SCLK }, {PB_0, SYS_PB_L_MFP_PB0_MFP_SPI1_MOSI0}, /* Loc 0 */
      {PB_1, SYS_PB_L_MFP_PB1_MFP_SPI1_MISO0}, {PB_3, SYS_PB_L_MFP_PB3_MFP_SPI1_SS0}}
};
const SPIPinAlt_TypeDef SPI2PinAlt[] = { 
    {{PA_9, SYS_PA_H_MFP_PA9_MFP_SPI2_SCLK }, {PA_11, SYS_PA_H_MFP_PA11_MFP_SPI2_MOSI0}, /* Loc 0 */
      {PA_10, SYS_PA_H_MFP_PA10_MFP_SPI2_MISO0}, {PA_8, SYS_PA_H_MFP_PA8_MFP_SPI2_SS0}},
    {{PB_5, SYS_PB_L_MFP_PB5_MFP_SPI2_SCLK }, {PA_11, SYS_PA_H_MFP_PA11_MFP_SPI2_MOSI0}, /* Loc 1 */
      {PA_10, SYS_PA_H_MFP_PA10_MFP_SPI2_MISO0}, {PB_4, SYS_PB_L_MFP_PB4_MFP_SPI2_SS0}},
};
const SPIPinDescription SPI_Desc[] = {
  { SPI0, SPI0_MODULE, SPI0_IRQn, CLK_CLKSEL2_SPI0_S_HCLK, SPI0PinAlt},
  { SPI1, SPI1_MODULE, SPI1_IRQn, CLK_CLKSEL2_SPI1_S_HCLK, SPI1PinAlt},
  { SPI2, SPI2_MODULE, SPI2_IRQn, CLK_CLKSEL2_SPI2_S_HCLK, SPI2PinAlt},
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
  {{PA_14,SYS_PA_H_MFP_PA14_MFP_UART0_RX}, {PA_15,SYS_PA_H_MFP_PA15_MFP_UART0_TX}}, /* Loc 0 */
  {{PB_0, SYS_PB_L_MFP_PB0_MFP_UART0_RX }, {PB_1, SYS_PB_L_MFP_PB1_MFP_UART0_TX }}, /* Loc 1 */
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
  {{PB_4, SYS_PB_L_MFP_PB4_MFP_UART1_RX }, {PB_5, SYS_PB_L_MFP_PB5_MFP_UART1_TX}},  /* Loc 0 */
  {{PA_2, SYS_PA_L_MFP_PA2_MFP_UART1_RX }, {PA_3, SYS_PA_L_MFP_PA3_MFP_UART1_TX}},  /* Loc 1 */
};
const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART0_IRQn, UART0PinAlt},
  {UART1, UART1_MODULE, UART1_IRQn, UART1PinAlt}, 
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
  {{PA_9,  SYS_PA_H_MFP_PA9_MFP_I2C0_SCL },{PA_8, SYS_PA_H_MFP_PA8_MFP_I2C0_SDA }},   /* Loc 0 */
  {{PA_5,  SYS_PA_L_MFP_PA5_MFP_I2C0_SCL },{PA_4, SYS_PA_L_MFP_PA4_MFP_I2C0_SDA }},   /* Loc 1 */
  {{PA_13, SYS_PA_H_MFP_PA13_MFP_I2C0_SCL},{PA_12,SYS_PA_H_MFP_PA12_MFP_I2C0_SDA}},   /* Loc 2 */
};
const I2CPinAlt_TypeDef I2C1PinAlt[] = {
  {{PA_11, SYS_PA_H_MFP_PA11_MFP_I2C1_SCL},{PA_10, SYS_PA_H_MFP_PA10_MFP_I2C1_SDA}},  /* Loc 0 */
};
const I2CPinDescription I2C_Desc[] = {
  {I2C0, I2C0_MODULE,I2C0_IRQn, I2C0PinAlt},
  {I2C1, I2C1_MODULE,I2C1_IRQn, I2C1PinAlt},
};
#endif
