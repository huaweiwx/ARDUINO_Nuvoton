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
#include "Arduino.h"

#pragma GCC diagnostic ignored "-Wconversion-null"

#define MFP_NULL {NULL, NULL, {NULL, NULL, NULL}}
#define MFP_PN(a,b,c) {P##a,BIT##b,{(uint32_t)&SYS->GP##a##_MFP##c, \
                                     SYS_GP##a##_MFP##c##_P##a##b##MFP_Msk, \
					                 SYS_GP##a##_MFP##c##_P##a##b##MFP_GPIO}}

#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  MFP_NULL,        //0   
  MFP_PN(B, 6, L), //1   EADC0_CH6/EBI_nWRH/EMAC_PPS/USCI1_DAT1/CAN1_RXD/UART1_RXD/SD1_CLK/EBI_nCS1/BPWM1_CH5/EPWM1_BRAKE1/EPWM1_CH5/INT4/ACMP1_O                           
  MFP_PN(B, 5, L), //2   EADC0_CH5/ACMP1_N/EBI_ADR0/SD0_DAT3/EMAC_RMII_REFCLK/SPI1_MISO/I2C0_SCL/UART5_TXD/USCI1_CTL0/SC0_CLK/I2S0_BCLK/EPWM0_CH0/TM0/INT0                  
  MFP_PN(B, 4, L), //3   EADC0_CH4/ACMP1_P1/EBI_ADR1/SD0_DAT2/EMAC_RMII_RXD0/SPI1_MOSI/I2C0_SDA/UART5_RXD/USCI1_CTL1/SC0_DAT/I2S0_MCLK/EPWM0_CH1/TM1/INT1                   
  MFP_PN(B, 3, L), //4   EADC0_CH3/ACMP0_N/EBI_ADR2/SD0_DAT1/EMAC_RMII_RXD1/SPI1_CLK/UART1_TXD/UART5_nRTS/USCI1_DAT1/SC0_RST/I2S0_DI/EPWM0_CH2/TM2/INT2                     
  MFP_PN(B, 2, L), //5   EADC0_CH2/ACMP0_P1/OPA0_O/EBI_ADR3/SD0_DAT0/EMAC_RMII_CRSDV/SPI1_SS/UART1_RXD/UART5_nCTS/USCI1_DAT0/SC0_PWR/I2S0_DO/EPWM0_CH3/TM3/INT3             
  MFP_PN(B, 1, L), //6   EADC0_CH1/OPA0_N/EBI_ADR8/SD0_CLK/EMAC_RMII_RXERR/SPI1_I2SMCLK/SPI3_I2SMCLK/UART2_TXD/USCI1_CLK/I2C1_SCL/I2S0_LRCK/EPWM0_CH4/EPWM1_CH4/EPWM0_BRAKE0
  MFP_PN(B, 0, L), //7   EADC0_CH0/OPA0_P/EBI_ADR9/SD0_CMD/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/EPWM0_CH5/EPWM1_CH5/EPWM0_BRAKE1                                                 
  MFP_PN(A, 11,H), //8   ACMP0_P0/EBI_nRD/SC2_PWR/SPI2_SS/SD1_DAT3/USCI0_CLK/I2C2_SCL/BPWM0_CH0/EPWM0_SYNC_OUT/TM0_EXT/DAC1_ST                                              
  MFP_PN(A, 10,H), //9   ACMP1_P0/OPA1_O/EBI_nWR/SC2_RST/SPI2_CLK/SD1_DAT2/USCI0_DAT0/I2C2_SDA/BPWM0_CH1/QEI1_INDEX/ECAP0_IC0/TM1_EXT/DAC0_ST                               
  MFP_PN(A, 9, H), //10  OPA1_N/EBI_MCLK/SC2_DAT/SPI2_MISO/SD1_DAT1/USCI0_DAT1/UART1_TXD/BPWM0_CH2/QEI1_A/ECAP0_IC1/TM2_EXT                                                 
  MFP_PN(A, 8, H), //11  OPA1_P/EBI_ALE/SC2_CLK/SPI2_MOSI/SD1_DAT0/USCI0_CTL1/UART1_RXD/BPWM0_CH3/QEI1_B/ECAP0_IC2/TM3_EXT/INT4                                             
  MFP_PN(F, 6, L), //12  EBI_ADR19/SC0_CLK/I2S0_LRCK/SPI0_MOSI/UART4_RXD/EBI_nCS0/TAMPER0                                                                                   
  MFP_NULL,        //13  VDD                                                                                                                                                
  MFP_PN(F, 5, L), //14  UART2_RXD/UART2_nCTS/BPWM0_CH4/EPWM0_SYNC_OUT/X32_IN/EADC0_ST                                                                                      
  MFP_PN(F, 4, L), //15  UART2_TXD/UART2_nRTS/BPWM0_CH5/X32_OUT                                                                                                             
  MFP_PN(F, 3, L), //16  EBI_nCS0/UART0_TXD/I2C0_SCL/XT1_IN/BPWM1_CH0                                                                                                       
  MFP_PN(F, 2, L), //17  EBI_nCS1/UART0_RXD/I2C0_SDA/QSPI0_CLK/XT1_OUT/BPWM1_CH1                                                                                            
  MFP_PN(C, 7, L), //18  EBI_AD9/EMAC_RMII_RXD0/SPI1_MISO/UART4_TXD/SC2_PWR/UART0_nCTS/I2C1_SMBAL/EPWM1_CH2/BPWM1_CH0/TM0/INT3                                              
  MFP_PN(C, 6, L), //19  EBI_AD8/EMAC_RMII_RXD1/SPI1_MOSI/UART4_RXD/SC2_RST/UART0_nRTS/I2C1_SMBSUS/EPWM1_CH3/BPWM1_CH1/TM1/INT2                                             
  MFP_PN(A, 7, L), //20  EBI_AD7/EMAC_RMII_CRSDV/SPI1_CLK/SC2_DAT/UART0_TXD/I2C1_SCL/EPWM1_CH4/BPWM1_CH2/ACMP0_WLAT/TM2/INT1                                                
  MFP_PN(A, 6, L), //21  EBI_AD6/EMAC_RMII_RXERR/SPI1_SS/SD1_nCD/SC2_CLK/UART0_RXD/I2C1_SDA/EPWM1_CH5/BPWM1_CH3/ACMP1_WLAT/TM3/INT0                                         
  MFP_NULL,        //22  VSS                                                                                                                                                
  MFP_NULL,        //23  VDD                                                                                                                                                
  MFP_NULL, 	   //24  LDO_CAP                                                                                                                                            
  MFP_PN(A, 5, L), //25  SPIM_D2/QSPI0_MISO1/SPI1_I2SMCLK/SD1_CMD/SC2_nCD/UART0_nCTS/UART5_TXD/I2C0_SCL/CAN0_TXD/BPWM0_CH5/EPWM0_CH0/QEI0_INDEX                             
  MFP_PN(A, 4, L), //26  SPIM_D3/QSPI0_MOSI1/SPI0_I2SMCLK/SD1_CLK/SC0_nCD/UART0_nRTS/UART5_RXD/I2C0_SDA/CAN0_RXD/BPWM0_CH4/EPWM0_CH1/QEI0_A                                 
  MFP_PN(A, 3, L), //27  SPIM_SS/QSPI0_SS/SPI0_SS/SD1_DAT3/SC0_PWR/UART4_TXD/UART1_TXD/I2C1_SCL/BPWM0_CH3/EPWM0_CH2/QEI0_B                                                  
  MFP_PN(A, 2, L), //28  SPIM_CLK/QSPI0_CLK/SPI0_CLK/SD1_DAT2/SC0_RST/UART4_RXD/UART1_RXD/I2C1_SDA/BPWM0_CH2/EPWM0_CH3                                                      
  MFP_PN(A, 1, L), //29  SPIM_MISO/QSPI0_MISO0/SPI0_MISO/SD1_DAT1/SC0_DAT/UART0_TXD/UART1_nCTS/I2C2_SCL/BPWM0_CH1/EPWM0_CH4/DAC1_ST                                         
  MFP_PN(A, 0, L), //30  SPIM_MOSI/QSPI0_MOSI0/SPI0_MOSI/SD1_DAT0/SC0_CLK/UART0_RXD/UART1_nRTS/I2C2_SDA/BPWM0_CH0/EPWM0_CH5/DAC0_ST                                         
  MFP_NULL,        //31  VDDIO                                                                                                                                              
  MFP_NULL,        //32  nRESET                                                                                                                                             
#if USE_ICE >0
  MFP_NULL,        //33  UART1_TXD/I2C1_SCL/BPWM1_CH0/ICE_DAT                                                                                                                                             
  MFP_NULL,        //34  UART1_RXD/I2C1_SDA/BPWM1_CH1/ICE_CLK                                                                                                                                             
#else
  MFP_PN(F, 0, L), //33  UART1_TXD/I2C1_SCL/BPWM1_CH0/ICE_DAT                                                                                                               
  MFP_PN(F, 1, L), //34  UART1_RXD/I2C1_SDA/BPWM1_CH1/ICE_CLK                                                                                                               
#endif
  MFP_PN(C, 5, L), //35  EBI_AD5/SPIM_D2/QSPI0_MISO1/UART2_TXD/I2C1_SCL/CAN0_TXD/UART4_TXD/EPWM1_CH0                                                                        
  MFP_PN(C, 4, L), //36  EBI_AD4/SPIM_D3/QSPI0_MOSI1/SC1_nCD/I2S0_BCLK/SPI1_I2SMCLK/UART2_RXD/I2C1_SDA/CAN0_RXD/UART4_RXD/EPWM1_CH1                                         
  MFP_PN(C, 3, L), //37  EBI_AD3/SPIM_SS/QSPI0_SS/SC1_PWR/I2S0_MCLK/SPI1_MISO/UART2_nRTS/I2C0_SMBAL/CAN1_TXD/UART3_TXD/EPWM1_CH2                                            
  MFP_PN(C, 2, L), //38  EBI_AD2/SPIM_CLK/QSPI0_CLK/SC1_RST/I2S0_DI/SPI1_MOSI/UART2_nCTS/I2C0_SMBSUS/CAN1_RXD/UART3_RXD/EPWM1_CH3                                           
  MFP_PN(C, 1, L), //39  EBI_AD1/SPIM_MISO/QSPI0_MISO0/SC1_DAT/I2S0_DO/SPI1_CLK/UART2_TXD/I2C0_SCL/EPWM1_CH4/ACMP0_O                                                        
  MFP_PN(C, 0, L), //40  EBI_AD0/SPIM_MOSI/QSPI0_MOSI0/SC1_CLK/I2S0_LRCK/SPI1_SS/UART2_RXD/I2C0_SDA/EPWM1_CH5/ACMP1_O                                                       
  MFP_PN(D, 3, L), //41  EBI_AD10/USCI0_CTL1/SPI0_SS/UART3_nRTS/USCI1_CTL0/SC2_PWR/SC1_nCD/UART0_TXD                                                                        
  MFP_PN(D, 2, L), //42  EBI_AD11/USCI0_DAT1/SPI0_CLK/UART3_nCTS/SC2_RST/UART0_RXD                                                                                          
  MFP_PN(D, 1, L), //43  EBI_AD12/USCI0_DAT0/SPI0_MISO/UART3_TXD/I2C2_SCL/SC2_DAT                                                                                           
  MFP_PN(D, 0, L), //44  EBI_AD13/USCI0_CLK/SPI0_MOSI/UART3_RXD/I2C2_SDA/SC2_CLK/TM2                                                                                        
  MFP_PN(A, 12,H), //45  I2S0_BCLK/UART4_TXD/I2C1_SCL/SPI2_SS/CAN0_TXD/SC2_PWR/BPWM1_CH2/QEI1_INDEX                                                                         
  MFP_PN(A, 13,H), //46  I2S0_MCLK/UART4_RXD/I2C1_SDA/SPI2_CLK/CAN0_RXD/SC2_RST/BPWM1_CH3/QEI1_A                                                                            
  MFP_PN(A, 14,H), //47  I2S0_DI/UART0_TXD/SPI2_MISO/I2C2_SCL/SC2_DAT/BPWM1_CH4/QEI1_B                                                                                      
  MFP_PN(A, 15,H), //48  I2S0_DO/UART0_RXD/SPI2_MOSI/I2C2_SDA/SC2_CLK/BPWM1_CH5/EPWM0_SYNC_IN                                                                               
  MFP_NULL, 	   //49  VSS                                                                                                                                                
  MFP_NULL, 	   //50  LDO_CAP                                                                                                                                            
  MFP_NULL,        //51  VDD                                                                                                                                                
  MFP_PN(C, 14,H), //52  EBI_AD11/SC1_nCD/SPI0_I2SMCLK/USCI0_CTL0/QSPI0_CLK/EPWM0_SYNC_IN/TM1                                                                               
  MFP_PN(B, 15,H), //53  EADC0_CH15/EBI_AD12/SC1_PWR/SPI0_SS/USCI0_CTL1/UART0_nCTS/UART3_TXD/I2C2_SMBAL/EPWM1_CH0/TM0_EXT                                                   
  MFP_PN(B, 14,H), //54  EADC0_CH14/EBI_AD13/SC1_RST/SPI0_CLK/USCI0_DAT1/UART0_nRTS/UART3_RXD/I2C2_SMBSUS/EPWM1_CH1/TM1_EXT/CLKO                                            
  MFP_PN(B, 13,H), //55  EADC0_CH13/DAC1_OUT/ACMP0_P3/ACMP1_P3/EBI_AD14/SC1_DAT/SPI0_MISO/USCI0_DAT0/UART0_TXD/UART3_nRTS/I2C2_SCL/EPWM1_CH2/TM2_EXT                        
  MFP_PN(B, 12,H), //56  EADC0_CH12/DAC0_OUT/ACMP0_P2/ACMP1_P2/EBI_AD15/SC1_CLK/SPI0_MOSI/USCI0_CLK/UART0_RXD/UART3_nCTS/I2C2_SDA/SD0_nCD/EPWM1_CH3/TM3_EXT                 
  MFP_NULL,        //57  AVDD                                                                                                                                               
  MFP_NULL,        //58  VREF                                                                                                                                               
  MFP_NULL,        //59  AVSS                                                                                                                                               
  MFP_PN(B, 11,H), //60  EADC0_CH11/EBI_ADR16/EMAC_RMII_MDC/UART0_nCTS/UART4_TXD/I2C1_SCL/CAN0_TXD/SPI0_I2SMCLK/BPWM1_CH0/SPI3_CLK                                          
  MFP_PN(B, 10,H), //61  EADC0_CH10/EBI_ADR17/EMAC_RMII_MDIO/USCI1_CTL0/UART0_nRTS/UART4_RXD/I2C1_SDA/CAN0_RXD/BPWM1_CH1/SPI3_SS                                            
  MFP_PN(B, 9, H), //62  EADC0_CH9/EBI_ADR18/EMAC_RMII_TXD0/USCI1_CTL1/UART0_TXD/UART1_nCTS/I2C1_SMBAL/BPWM1_CH2/SPI3_MISO/INT7                                             
  MFP_PN(B, 8, H), //63  EADC0_CH8/EBI_ADR19/EMAC_RMII_TXD1/USCI1_CLK/UART0_RXD/UART1_nRTS/I2C1_SMBSUS/BPWM1_CH3/SPI3_MOSI/INT6                                             
  MFP_PN(B, 7, L), //64  EADC0_CH7/EBI_nWRL/EMAC_RMII_TXEN/USCI1_DAT0/CAN1_TXD/UART1_TXD/SD1_CMD/EBI_nCS0/BPWM1_CH4/EPWM1_BRAKE0/EPWM1_CH4/INT5/ACMP0_O                     
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[] = { //SYS_GPA_MFPL_PA5MFP_PWM0_CH0
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 0, 500, {PB_5, SYS_GPB_MFPL_PB5MFP_EPWM0_CH0 }}, //6  PE3
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 1, 500, {PB_4, SYS_GPB_MFPL_PB4MFP_EPWM0_CH1 }}, //6  PE3
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 2, 500, {PB_3, SYS_GPB_MFPL_PB3MFP_EPWM0_CH2 }}, //6  PE3
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 3, 500, {PB_2, SYS_GPB_MFPL_PB2MFP_EPWM0_CH3 }}, //6  PE3
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 4, 500, {PB_1, SYS_GPB_MFPL_PB1MFP_EPWM0_CH4 }}, //6  PE3
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 5, 500, {PB_0, SYS_GPB_MFPL_PB0MFP_EPWM0_CH5 }}, //6  PE3
  {EPWM0, EPWM0_MODULE, EPWM0P0_IRQn, 2, 500, {PA_3, SYS_GPA_MFPL_PA3MFP_EPWM0_CH2 }}, //6  PE3
  {EPWM0, EPWM0_MODULE, EPWM0P0_IRQn, 3, 500, {PA_2, SYS_GPA_MFPL_PA2MFP_EPWM0_CH3 }}, //6  PE3
  {EPWM0, EPWM0_MODULE, EPWM0P0_IRQn, 4, 500, {PA_1, SYS_GPA_MFPL_PA1MFP_EPWM0_CH4 }}, //6  PE3
  {EPWM0, EPWM0_MODULE, EPWM0P0_IRQn, 5, 500, {PA_0, SYS_GPA_MFPL_PA0MFP_EPWM0_CH5 }}, //6  PE3

  {EPWM1, EPWM1_MODULE, EPWM1P2_IRQn, 4, 500, {PC_1, SYS_GPC_MFPL_PC1MFP_EPWM1_CH4 }},     //5  PC0
  {EPWM1, EPWM1_MODULE, EPWM1P2_IRQn, 5, 500, {PC_0, SYS_GPC_MFPL_PC0MFP_EPWM1_CH5 }},     //5  PC0
  {EPWM1, EPWM0_MODULE, EPWM1P1_IRQn, 0, 500, {PB_15,SYS_GPB_MFPH_PB15MFP_EPWM1_CH0}}, //6  PE3
  {EPWM1, EPWM0_MODULE, EPWM1P1_IRQn, 1, 500, {PB_14,SYS_GPB_MFPH_PB14MFP_EPWM1_CH1}}, //6  PE3
  {EPWM1, EPWM0_MODULE, EPWM1P1_IRQn, 2, 500, {PB_13,SYS_GPB_MFPH_PB13MFP_EPWM1_CH2}}, //6  PE3
  {EPWM1, EPWM0_MODULE, EPWM1P1_IRQn, 3, 500, {PB_12,SYS_GPB_MFPH_PB12MFP_EPWM1_CH3}}, //6  PE3

//  {BPWM0, BPWM0_MODULE,   BPWM0_IRQn, 5, 500, {PF_5, SYS_GPF_MFPL_PF5MFP_BPWM0_CH4 }}, //0  PC12
//  {BPWM0, BPWM0_MODULE,   BPWM0_IRQn, 4, 500, {PF_4, SYS_GPF_MFPL_PF4MFP_BPWM0_CH5 }}, //1  PC11
//  {BPWM1, BPWM1_MODULE,   BPWM1_IRQn, 4, 500, {PF_3, SYS_GPF_MFPL_PF3MFP_BPWM1_CH0 }}, //1  PC11
//  {BPWM1, BPWM0_MODULE,   BPWM1_IRQn, 4, 500, {PF_2, SYS_GPF_MFPL_PF2MFP_BPWM1_CH1 }}, //1  PC11
 // {EPWM1, EPWM1_MODULE, EPWM1P2_IRQn, 0, 500, {PC_12,SYS_GPC_MFPH_PC12MFP_EPWM1_CH0 }}, //0  PC12
 // {EPWM1, EPWM1_MODULE, EPWM1P2_IRQn, 1, 500, {PC_11,SYS_GPC_MFPH_PC11MFP_EPWM1_CH1 }}, //1  PC11
 // {EPWM1, EPWM1_MODULE, EPWM1P2_IRQn, 2, 500, {PC_10,SYS_GPC_MFPH_PC10MFP_EPWM1_CH2 }}, //1  PC10
 // {EPWM1, EPWM1_MODULE, EPWM1P2_IRQn, 3, 500, {PC_9, SYS_GPC_MFPH_PC9MFP_EPWM1_CH3  }}, //0  PC9
//  {EPWM1, EPWM1_MODULE, EPWM1P2_IRQn, 4, 500, {PC_13,SYS_GPC_MFPH_PC13MFP_EPWM1_CH4 }}, //4  PC13
//  {EPWM0, EPWM0_MODULE, EPWM1P3_IRQn, 5, 500, {PD_7, SYS_GPD_MFPL_PD7MFP_EPWM0_CH5  }}, //7  PD7
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[] = {
  {EADC, EADC_MODULE, 0,  {PB_0, SYS_GPB_MFPL_PB0MFP_EADC0_CH0  }},  //0
  {EADC, EADC_MODULE, 1,  {PB_1, SYS_GPB_MFPL_PB1MFP_EADC0_CH1  }},  //1
  {EADC, EADC_MODULE, 2,  {PB_2, SYS_GPB_MFPL_PB2MFP_EADC0_CH2 }},   //2
  {EADC, EADC_MODULE, 3,  {PB_3, SYS_GPB_MFPL_PB3MFP_EADC0_CH3 }},   //3
  {EADC, EADC_MODULE, 4,  {PB_4, SYS_GPB_MFPL_PB4MFP_EADC0_CH4 }},   //4
  {EADC, EADC_MODULE, 5,  {PB_5, SYS_GPB_MFPL_PB5MFP_EADC0_CH5 }},   //5
  {EADC, EADC_MODULE, 6,  {PB_6, SYS_GPB_MFPL_PB6MFP_EADC0_CH6 }},   //6
  {EADC, EADC_MODULE, 7,  {PB_7, SYS_GPB_MFPL_PB7MFP_EADC0_CH7 }},   //7
  {EADC, EADC_MODULE, 8,  {PB_8, SYS_GPB_MFPH_PB8MFP_EADC0_CH8  }},  //8
  {EADC, EADC_MODULE, 9,  {PB_9, SYS_GPB_MFPH_PB9MFP_EADC0_CH9  }},  //9
  {EADC, EADC_MODULE, 10, {PB_10,SYS_GPB_MFPH_PB10MFP_EADC0_CH10 }}, //10
  {EADC, EADC_MODULE, 11, {PB_11,SYS_GPB_MFPH_PB11MFP_EADC0_CH11 }}, //11
  {EADC, EADC_MODULE, 12, {PB_12,SYS_GPB_MFPH_PB12MFP_EADC0_CH12 }}, //12
  {EADC, EADC_MODULE, 13, {PB_13,SYS_GPB_MFPH_PB13MFP_EADC0_CH13}},  //13
  {EADC, EADC_MODULE, 14, {PB_14,SYS_GPB_MFPH_PB14MFP_EADC0_CH14}},  //14
  {EADC, EADC_MODULE, 15, {PB_15,SYS_GPB_MFPH_PB15MFP_EADC0_CH15}},  //15
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = {
  {{PA_2,SYS_GPA_MFPL_PA2MFP_SPI0_CLK} ,{PA_0,SYS_GPA_MFPL_PA0MFP_SPI0_MOSI},
   {PA_1,SYS_GPA_MFPL_PA1MFP_SPI0_MISO},{PA_3,SYS_GPA_MFPL_PA3MFP_SPI0_SS}}, //Loc 0
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = {
  {{PB_3,SYS_GPB_MFPL_PB3MFP_SPI1_CLK} ,{PB_4,SYS_GPB_MFPL_PB4MFP_SPI1_MOSI },
   {PB_5,SYS_GPB_MFPL_PB5MFP_SPI1_MISO},{PB_2,SYS_GPB_MFPL_PB2MFP_SPI1_SS}}, //Loc 0
};
const SPIPinAlt_TypeDef SPI2PinAlt[] = {
  {{PA_13,SYS_GPA_MFPH_PA13MFP_SPI2_CLK} ,{PA_15,SYS_GPA_MFPH_PA15MFP_SPI2_MOSI},
   {PA_14,SYS_GPA_MFPH_PA14MFP_SPI2_MISO},{PA_12,SYS_GPA_MFPH_PA12MFP_SPI2_SS}}, //Loc 0
};
const SPIPinDescription SPI_Desc[] = {
  {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL2_SPI0SEL_PCLK1,SPI0PinAlt},
  {SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL2_SPI2SEL_PCLK1,SPI1PinAlt},
  {SPI2,SPI2_MODULE,SPI2_IRQn,CLK_CLKSEL2_SPI2SEL_PCLK1,SPI2PinAlt},
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
  {{PB_12,SYS_GPB_MFPH_PB12MFP_UART0_RXD}, {PB_13,SYS_GPB_MFPH_PB13MFP_UART0_TXD}},  //Loc 0
  {{PA_0, SYS_GPA_MFPL_PA0MFP_UART0_RXD }, {PA_1, SYS_GPA_MFPL_PA1MFP_UART0_TXD }},  //Loc 1
  {{PA_15,SYS_GPA_MFPH_PA15MFP_UART0_RXD}, {PA_14,SYS_GPA_MFPH_PA14MFP_UART0_TXD}},  //Loc 2 
  {{PF_2, SYS_GPF_MFPL_PF2MFP_UART0_RXD }, {PF_3, SYS_GPF_MFPL_PF3MFP_UART0_TXD }},  //Loc 3
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
  {{PA_2, SYS_GPA_MFPL_PA2MFP_UART1_RXD }, {PA_3, SYS_GPA_MFPL_PA3MFP_UART1_TXD }},  //Loc 0
  {{PB_2, SYS_GPB_MFPL_PB2MFP_UART1_RXD }, {PB_3, SYS_GPB_MFPL_PB3MFP_UART1_TXD }},  //Loc 1
};
const UARTPinAlt_TypeDef UART2PinAlt[] = {
  {{PB_0, SYS_GPB_MFPL_PB0MFP_UART2_RXD }, {PB_1, SYS_GPB_MFPL_PB1MFP_UART2_TXD }},  //Loc 0
  {{PF_5, SYS_GPF_MFPL_PF5MFP_UART2_RXD }, {PF_4, SYS_GPF_MFPL_PF4MFP_UART2_TXD }},  //Loc 1
  {{PC_0, SYS_GPC_MFPL_PC0MFP_UART2_RXD }, {PC_1, SYS_GPC_MFPL_PC1MFP_UART2_TXD }},  //Loc 2
};
const UARTPinAlt_TypeDef UART3PinAlt[] = {
  {{PB_14,SYS_GPB_MFPH_PB14MFP_UART3_RXD}, {PB_15,SYS_GPB_MFPH_PB15MFP_UART3_TXD}},  //Loc 0
};
const UARTPinAlt_TypeDef UART4PinAlt[] = {
  {{PA_13,SYS_GPA_MFPH_PA13MFP_UART4_RXD}, {PA_12,SYS_GPA_MFPH_PA12MFP_UART4_TXD}},  //Loc 1
  {{PA_2, SYS_GPA_MFPL_PA2MFP_UART4_RXD }, {PA_3, SYS_GPA_MFPL_PA3MFP_UART4_TXD }},  //Loc 0
};
const UARTPinAlt_TypeDef UART5PinAlt[] = {
  {{PB_4, SYS_GPB_MFPL_PB4MFP_UART5_RXD }, {PB_5, SYS_GPB_MFPL_PB5MFP_UART5_TXD }},  //Loc 0
};

const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART0_IRQn, UART0PinAlt},  //0
  {UART1, UART1_MODULE, UART1_IRQn, UART1PinAlt},  //1
  {UART2, UART2_MODULE, UART2_IRQn, UART2PinAlt},  //2
  {UART3, UART3_MODULE, UART3_IRQn, UART3PinAlt},  //3
  {UART4, UART4_MODULE, UART4_IRQn, UART4PinAlt},  //4
  {UART5, UART5_MODULE, UART5_IRQn, UART5PinAlt},  //5
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
  {{PC_1, SYS_GPC_MFPL_PC1MFP_I2C0_SCL}, {PC_0, SYS_GPC_MFPL_PC0MFP_I2C0_SDA }},//Loc 0
  {{PB_5, SYS_GPB_MFPL_PB5MFP_I2C0_SCL}, {PB_4, SYS_GPB_MFPL_PB4MFP_I2C0_SDA }},//Loc 1
  {{PF_3, SYS_GPF_MFPL_PF3MFP_I2C0_SCL}, {PF_2, SYS_GPF_MFPL_PF2MFP_I2C0_SDA }},//Loc 2
};
const I2CPinAlt_TypeDef I2C1PinAlt[] = {
  {{PB_1, SYS_GPB_MFPL_PB1MFP_I2C1_SCL}, {PB_0, SYS_GPB_MFPL_PB0MFP_I2C1_SDA }},//Loc 0
  {{PA_3, SYS_GPA_MFPL_PA3MFP_I2C1_SCL}, {PA_2, SYS_GPA_MFPL_PA2MFP_I2C1_SDA }},//Loc 1
};
const I2CPinAlt_TypeDef I2C2PinAlt[] = {
  {{PA_1, SYS_GPA_MFPL_PA1MFP_I2C2_SCL}, {PA_0, SYS_GPA_MFPL_PA0MFP_I2C2_SDA }},//Loc 0
  {{PB_13,SYS_GPB_MFPH_PB13MFP_I2C2_SCL},{PB_12,SYS_GPB_MFPH_PB12MFP_I2C2_SDA}},//Loc 1
};
const I2CPinDescription I2C_Desc[] = {
  {I2C0, I2C0_MODULE, I2C0_IRQn,I2C0PinAlt},
  {I2C1, I2C1_MODULE, I2C1_IRQn,I2C1PinAlt},
  {I2C2, I2C2_MODULE, I2C2_IRQn,I2C2PinAlt},
};
#endif

#ifndef CAN_DESC_USERDEF
const CANPinDescription CAN_Desc[] = {
//  {CAN0, CAN0_MODULE, CAN0_IRQn, {{84, SYS_GPA_MFPH_PA13MFP_CAN0_RXD}, {83, SYS_GPA_MFPH_PA12MFP_CAN0_TXD}}},
};
#endif
