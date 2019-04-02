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
#include "Arduino.h"

#pragma GCC diagnostic ignored "-Wconversion-null"

#define MFP_NULL {NULL, NULL, {NULL, NULL, NULL}}
#define MFP_PN(a,b,c) {P##a,BIT##b,{(uint32_t)&SYS->GP##a##_MFP##c, \
                                     SYS_GP##a##_MFP##c##_P##a##b##MFP_Msk, \
					                 SYS_GP##a##_MFP##c##_P##a##b##MFP_GPIO}}

#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  MFP_NULL       ,  //0
  MFP_PN(B, 5, L),  //1     EADC0_CH5/ACMP1_N/EBI_ADR0/SD0_DAT3/EMAC_RMII_REFCLK/SPI1_MISO/I2C0_SCL/UART5_TXD/USCI1_CTL0/SC0_CLK/I2S0_BCLK/EPWM0_CH0/TM0/INT0                  
  MFP_PN(B, 4, L),  //2     EADC0_CH4/ACMP1_P1/EBI_ADR1/SD0_DAT2/EMAC_RMII_RXD0/SPI1_MOSI/I2C0_SDA/UART5_RXD/USCI1_CTL1/SC0_DAT/I2S0_MCLK/EPWM0_CH1/TM1/INT1                   
  MFP_PN(B, 3, L),  //3     EADC0_CH3/ACMP0_N/EBI_ADR2/SD0_DAT1/EMAC_RMII_RXD1/SPI1_CLK/UART1_TXD/UART5_nRTS/USCI1_DAT1/SC0_RST/I2S0_DI/EPWM0_CH2/TM2/INT2                     
  MFP_PN(B, 2, L),  //4     EADC0_CH2/ACMP0_P1/OPA0_O/EBI_ADR3/SD0_DAT0/EMAC_RMII_CRSDV/SPI1_SS/UART1_RXD/UART5_nCTS/USCI1_DAT0/SC0_PWR/I2S0_DO/EPWM0_CH3/TM3/INT3             
  MFP_PN(C, 12,H),  //5     EBI_ADR4/UART0_TXD/I2C0_SCL/SPI3_MISO/SC0_nCD/ECAP1_IC2/EPWM1_CH0/ACMP0_O                                                                          
  MFP_PN(C, 11,H),  //6     EBI_ADR5/UART0_RXD/I2C0_SDA/SPI3_MOSI/ECAP1_IC1/EPWM1_CH1/ACMP1_O                                                                                  
  MFP_PN(C, 10,H),  //7     EBI_ADR6/SPI3_CLK/UART3_TXD/CAN1_TXD/ECAP1_IC0/EPWM1_CH2                                                                                           
  MFP_PN(C, 9, H),  //8     EBI_ADR7/SPI3_SS/UART3_RXD/CAN1_RXD/EPWM1_CH3                                                                                                      
  MFP_PN(B, 1, L),  //9     EADC0_CH1/OPA0_N/EBI_ADR8/SD0_CLK/EMAC_RMII_RXERR/SPI1_I2SMCLK/SPI3_I2SMCLK/UART2_TXD/USCI1_CLK/I2C1_SCL/I2S0_LRCK/EPWM0_CH4/EPWM1_CH4/EPWM0_BRAKE0
  MFP_PN(B, 0, L),  //10    EADC0_CH0/OPA0_P/EBI_ADR9/SD0_CMD/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/EPWM0_CH5/EPWM1_CH5/EPWM0_BRAKE1                                                 
  MFP_NULL       ,  //11    VSS                                                                                                                                                
  MFP_NULL       ,  //12    VDD                                                                                                                                                
  MFP_PN(A, 11,H),  //13    ACMP0_P0/EBI_nRD/SC2_PWR/SPI2_SS/SD1_DAT3/USCI0_CLK/I2C2_SCL/BPWM0_CH0/EPWM0_SYNC_OUT/TM0_EXT/DAC1_ST                                              
  MFP_PN(A, 10,H),  //14    ACMP1_P0/OPA1_O/EBI_nWR/SC2_RST/SPI2_CLK/SD1_DAT2/USCI0_DAT0/I2C2_SDA/BPWM0_CH1/QEI1_INDEX/ECAP0_IC0/TM1_EXT/DAC0_ST                               
  MFP_PN(A, 9, H),  //15    OPA1_N/EBI_MCLK/SC2_DAT/SPI2_MISO/SD1_DAT1/USCI0_DAT1/UART1_TXD/BPWM0_CH2/QEI1_A/ECAP0_IC1/TM2_EXT                                                 
  MFP_PN(A, 8, H),  //16    OPA1_P/EBI_ALE/SC2_CLK/SPI2_MOSI/SD1_DAT0/USCI0_CTL1/UART1_RXD/BPWM0_CH3/QEI1_B/ECAP0_IC2/TM3_EXT/INT4                                             
  MFP_PN(C, 13,H),  //17    EBI_ADR10/SC2_nCD/SPI2_I2SMCLK/CAN1_TXD/USCI0_CTL0/UART2_TXD/BPWM0_CH4/CLKO/EADC0_ST                                                               
  MFP_PN(D, 12,H),  //18    OPA2_O/EBI_nCS0/CAN1_RXD/UART2_RXD/BPWM0_CH5/QEI0_INDEX/CLKO/EADC0_ST/INT5                                                                         
  MFP_PN(D, 11,H),  //19    OPA2_N/EBI_nCS1/UART1_TXD/CAN0_TXD/QEI0_A/INT6                                                                                                     
  MFP_PN(D, 10,H),  //20    OPA2_P/EBI_nCS2/UART1_RXD/CAN0_RXD/QEI0_B/INT7                                                                                                     
  MFP_PN(G, 2, L),  //21    EBI_ADR11/SPI2_SS/I2C0_SMBAL/I2C1_SCL/TM0                                                                                                          
  MFP_PN(G, 3, L),  //22    EBI_ADR12/SPI2_CLK/I2C0_SMBSUS/I2C1_SDA/TM1                                                                                                        
  MFP_PN(G, 4, L),  //23    EBI_ADR13/SPI2_MISO/TM2                                                                                                                            
  MFP_PN(F, 11,H),  //24    EBI_ADR14/SPI2_MOSI/TAMPER5/TM3                                                                                                                    
  MFP_PN(F, 10,H),  //25    EBI_ADR15/SC0_nCD/I2S0_BCLK/SPI0_I2SMCLK/TAMPER4                                                                                                   
  MFP_PN(F, 9, H),  //26    EBI_ADR16/SC0_PWR/I2S0_MCLK/SPI0_SS/TAMPER3                                                                                                        
  MFP_PN(F, 8, H),  //27    EBI_ADR17/SC0_RST/I2S0_DI/SPI0_CLK/TAMPER2                                                                                                         
  MFP_PN(F, 7, L),  //28    EBI_ADR18/SC0_DAT/I2S0_DO/SPI0_MISO/UART4_TXD/TAMPER1                                                                                              
  MFP_PN(F, 6, L),  //29    EBI_ADR19/SC0_CLK/I2S0_LRCK/SPI0_MOSI/UART4_RXD/EBI_nCS0/TAMPER0                                                                                   
  MFP_NULL       ,  //30    VDD                                                                                                                                                
  MFP_PN(F, 5, L),  //31    UART2_RXD/UART2_nCTS/BPWM0_CH4/EPWM0_SYNC_OUT/X32_IN/EADC0_ST                                                                                      
  MFP_PN(F, 4, L),  //32    UART2_TXD/UART2_nRTS/BPWM0_CH5/X32_OUT                                                                                                             
  MFP_PN(H, 4, L),  //33    EBI_ADR3/SPI1_MISO                                                                                                                                 
  MFP_PN(H, 5, L),  //34    EBI_ADR2/SPI1_MOSI                                                                                                                                 
  MFP_PN(H, 6, L),  //35    EBI_ADR1/SPI1_CLK                                                                                                                                  
  MFP_PN(H, 7, L),  //36    EBI_ADR0/SPI1_SS                                                                                                                                   
  MFP_PN(F, 3, L),  //37    EBI_nCS0/UART0_TXD/I2C0_SCL/XT1_IN/BPWM1_CH0                                                                                                       
  MFP_PN(F, 2, L),  //38    EBI_nCS1/UART0_RXD/I2C0_SDA/QSPI0_CLK/XT1_OUT/BPWM1_CH1                                                                                            
  MFP_NULL       ,  //39    VSS
  MFP_NULL       ,  //40    VDD
  MFP_PN(E, 8, H),  //41    EBI_ADR10/EMAC_RMII_MDC/I2S0_BCLK/SPI2_CLK/USCI1_CTL1/UART2_TXD/EPWM0_CH0/EPWM0_BRAKE0/ECAP0_IC0/TRACE_DATA3                                       
  MFP_PN(E, 9, H),  //42    EBI_ADR11/EMAC_RMII_MDIO/I2S0_MCLK/SPI2_MISO/USCI1_CTL0/UART2_RXD/EPWM0_CH1/EPWM0_BRAKE1/ECAP0_IC1/TRACE_DATA2                                     
  MFP_PN(E, 10,H),  //43    EBI_ADR12/EMAC_RMII_TXD0/I2S0_DI/SPI2_MOSI/USCI1_DAT0/UART3_TXD/EPWM0_CH2/EPWM1_BRAKE0/ECAP0_IC2/TRACE_DATA1                                       
  MFP_PN(E, 11,H),  //44    EBI_ADR13/EMAC_RMII_TXD1/I2S0_DO/SPI2_SS/USCI1_DAT1/UART3_RXD/UART1_nCTS/EPWM0_CH3/EPWM1_BRAKE1/ECAP1_IC2/TRACE_DATA0                              
  MFP_PN(E, 12,H),  //45    EBI_ADR14/EMAC_RMII_TXEN/I2S0_LRCK/SPI2_I2SMCLK/USCI1_CLK/UART1_nRTS/EPWM0_CH4/ECAP1_IC1/TRACE_CLK                                                 
  MFP_PN(E, 13,H),  //46    EBI_ADR15/EMAC_PPS/I2C0_SCL/UART4_nRTS/UART1_TXD/EPWM0_CH5/EPWM1_CH0/BPWM1_CH5/ECAP1_IC0                                                           
  MFP_PN(C, 8, H),  //47    EBI_ADR16/EMAC_RMII_REFCLK/I2C0_SDA/UART4_nCTS/UART1_RXD/EPWM1_CH1/BPWM1_CH4                                                                       
  MFP_PN(C, 7, L),  //48    EBI_AD9/EMAC_RMII_RXD0/SPI1_MISO/UART4_TXD/SC2_PWR/UART0_nCTS/I2C1_SMBAL/EPWM1_CH2/BPWM1_CH0/TM0/INT3                                              
  MFP_PN(C, 6, L),  //49    EBI_AD8/EMAC_RMII_RXD1/SPI1_MOSI/UART4_RXD/SC2_RST/UART0_nRTS/I2C1_SMBSUS/EPWM1_CH3/BPWM1_CH1/TM1/INT2                                             
  MFP_PN(A, 7, L),  //50    EBI_AD7/EMAC_RMII_CRSDV/SPI1_CLK/SC2_DAT/UART0_TXD/I2C1_SCL/EPWM1_CH4/BPWM1_CH2/ACMP0_WLAT/TM2/INT1                                                
  MFP_PN(A, 6, L),  //51    EBI_AD6/EMAC_RMII_RXERR/SPI1_SS/SD1_nCD/SC2_CLK/UART0_RXD/I2C1_SDA/EPWM1_CH5/BPWM1_CH3/ACMP1_WLAT/TM3/INT0                                         
  MFP_NULL       ,  //52    VSS                                                                                                                                                
  MFP_NULL       ,  //53    VDD                                                                                                                                                
  MFP_NULL       ,  //54    LDO_CAP                                                                                                                                            
  MFP_PN(A, 5, L),  //55    SPIM_D2/QSPI0_MISO1/SPI1_I2SMCLK/SD1_CMD/SC2_nCD/UART0_nCTS/UART5_TXD/I2C0_SCL/CAN0_TXD/BPWM0_CH5/EPWM0_CH0/QEI0_INDEX                             
  MFP_PN(A, 4, L),  //56    SPIM_D3/QSPI0_MOSI1/SPI0_I2SMCLK/SD1_CLK/SC0_nCD/UART0_nRTS/UART5_RXD/I2C0_SDA/CAN0_RXD/BPWM0_CH4/EPWM0_CH1/QEI0_A                                 
  MFP_PN(A, 3, L),  //57    SPIM_SS/QSPI0_SS/SPI0_SS/SD1_DAT3/SC0_PWR/UART4_TXD/UART1_TXD/I2C1_SCL/BPWM0_CH3/EPWM0_CH2/QEI0_B                                                  
  MFP_PN(A, 2, L),  //58    SPIM_CLK/QSPI0_CLK/SPI0_CLK/SD1_DAT2/SC0_RST/UART4_RXD/UART1_RXD/I2C1_SDA/BPWM0_CH2/EPWM0_CH3                                                      
  MFP_PN(A, 1, L),  //59    SPIM_MISO/QSPI0_MISO0/SPI0_MISO/SD1_DAT1/SC0_DAT/UART0_TXD/UART1_nCTS/I2C2_SCL/BPWM0_CH1/EPWM0_CH4/DAC1_ST                                         
  MFP_PN(A, 0, L),  //60    SPIM_MOSI/QSPI0_MOSI0/SPI0_MOSI/SD1_DAT0/SC0_CLK/UART0_RXD/UART1_nRTS/I2C2_SDA/BPWM0_CH0/EPWM0_CH5/DAC0_ST                                         
  MFP_NULL       ,  //61    VDDIO                                                                                                                                              
  MFP_PN(E, 14,H),  //62    EBI_AD8/UART2_TXD/CAN0_TXD/SD1_nCD                                                                                                                 
  MFP_PN(E, 15,H),  //63    EBI_AD9/UART2_RXD/CAN0_RXD                                                                                                                         
  MFP_NULL, //64            nRESET                                                                                                                                             
#if USE_ICE == 0
  MFP_PN(F, 0, L),  //65    UART1_TXD/I2C1_SCL/BPWM1_CH0/ICE_DAT
  MFP_PN(F, 1, L),  //66    UART1_RXD/I2C1_SDA/BPWM1_CH1/ICE_CLK
#else
  MFP_NULL       ,  //65    UART1_TXD/I2C1_SCL/BPWM1_CH0/ICE_DAT
  MFP_NULL       ,  //66    UART1_RXD/I2C1_SDA/BPWM1_CH1/ICE_CLK
#endif
  MFP_PN(D, 9, H),  //67    EBI_AD7/I2C2_SCL/UART2_nCTS                                                                                                               
  MFP_PN(D, 8, H),  //68    EBI_AD6/I2C2_SDA/UART2_nRTS                                                                                                               
  MFP_PN(C, 5, L),  //69    EBI_AD5/SPIM_D2/QSPI0_MISO1/UART2_TXD/I2C1_SCL/CAN0_TXD/UART4_TXD/EPWM1_CH0                                                               
  MFP_PN(C, 4, L),  //70    EBI_AD4/SPIM_D3/QSPI0_MOSI1/SC1_nCD/I2S0_BCLK/SPI1_I2SMCLK/UART2_RXD/I2C1_SDA/CAN0_RXD/UART4_RXD/EPWM1_CH1                                
  MFP_PN(C, 3, L),  //71    EBI_AD3/SPIM_SS/QSPI0_SS/SC1_PWR/I2S0_MCLK/SPI1_MISO/UART2_nRTS/I2C0_SMBAL/CAN1_TXD/UART3_TXD/EPWM1_CH2                                   
  MFP_PN(C, 2, L),  //72    EBI_AD2/SPIM_CLK/QSPI0_CLK/SC1_RST/I2S0_DI/SPI1_MOSI/UART2_nCTS/I2C0_SMBSUS/CAN1_RXD/UART3_RXD/EPWM1_CH3                                  
  MFP_PN(C, 1, L),  //73    EBI_AD1/SPIM_MISO/QSPI0_MISO0/SC1_DAT/I2S0_DO/SPI1_CLK/UART2_TXD/I2C0_SCL/EPWM1_CH4/ACMP0_O                                               
  MFP_PN(C, 0, L),  //74    EBI_AD0/SPIM_MOSI/QSPI0_MOSI0/SC1_CLK/I2S0_LRCK/SPI1_SS/UART2_RXD/I2C0_SDA/EPWM1_CH5/ACMP1_O                                              
  MFP_NULL       ,  //75    VSS                                                                                                                                       
  MFP_NULL       ,  //76    VDD                                                                                                                                       
  MFP_PN(G, 9, H),  //77    EBI_AD0/SD1_DAT3/SPIM_D2/BPWM0_CH5                                                                                                        
  MFP_PN(G, 10,H),  //78    EBI_AD1/SD1_DAT2/SPIM_D3/BPWM0_CH4                                                                                                        
  MFP_PN(G, 11,H),  //79    EBI_AD2/SD1_DAT1/SPIM_SS/BPWM0_CH3                                                                                                        
  MFP_PN(G, 12,H),  //80    EBI_AD3/SD1_DAT0/SPIM_CLK/BPWM0_CH2                                                                                                       
  MFP_PN(G, 13,H),  //81    EBI_AD4/SD1_CMD/SPIM_MISO/BPWM0_CH1                                                                                                       
  MFP_PN(G, 14,H),  //82    EBI_AD5/SD1_CLK/SPIM_MOSI/BPWM0_CH0                                                                                                       
  MFP_PN(G, 15,H),  //83    SD1_nCD/CLKO/EADC0_ST                                                                                                                     
  MFP_PN(D, 13,H),  //84    EBI_AD10/SD0_nCD/SPI0_I2SMCLK/SPI1_I2SMCLK/SC2_nCD                                                                                        
  MFP_PN(A, 12,H),  //85    I2S0_BCLK/UART4_TXD/I2C1_SCL/SPI2_SS/CAN0_TXD/SC2_PWR/BPWM1_CH2/QEI1_INDEX/USB_VBUS                                                       
  MFP_PN(A, 13,H),  //86    I2S0_MCLK/UART4_RXD/I2C1_SDA/SPI2_CLK/CAN0_RXD/SC2_RST/BPWM1_CH3/QEI1_A/USB_D-                                                            
  MFP_PN(A, 14,H),  //87    I2S0_DI/UART0_TXD/SPI2_MISO/I2C2_SCL/SC2_DAT/BPWM1_CH4/QEI1_B/USB_D+                                                                      
  MFP_PN(A, 15,H),  //88    I2S0_DO/UART0_RXD/SPI2_MOSI/I2C2_SDA/SC2_CLK/BPWM1_CH5/EPWM0_SYNC_IN/USB_OTG_ID                                                           
  MFP_NULL       ,  //89    HSUSB_VRES                                                                                                                                
  MFP_NULL       ,  //90    HSUSB_VDD33                                                                                                                               
  MFP_NULL       ,  //91    HSUSB_VBUS                                                                                                                                
  MFP_NULL       ,  //92    HSUSB_D-                                                                                                                                  
  MFP_NULL       ,  //93    HSUSB_VSS                                                                                                                                 
  MFP_NULL       ,  //94    HSUSB_D+                                                                                                                                  
  MFP_NULL       ,  //95    HSUSB_VDD12_CAP                                                                                                                           
  MFP_NULL       ,  //96    HSUSB_ID                                                                                                                                  
  MFP_PN(E, 7,L),  //97     SD0_CMD/SPIM_D2/UART5_TXD/CAN1_TXD/QEI1_INDEX/EPWM0_CH0/BPWM0_CH5                                                                         
  MFP_PN(E, 6,L),  //98     SD0_CLK/SPIM_D3/SPI3_I2SMCLK/SC0_nCD/USCI0_CTL0/UART5_RXD/CAN1_RXD/QEI1_A/EPWM0_CH1/BPWM0_CH4                                             
  MFP_PN(E, 5,L),  //99     EBI_nRD/SD0_DAT3/SPIM_SS/SPI3_SS/SC0_PWR/USCI0_CTL1/QEI1_B/EPWM0_CH2/BPWM0_CH3                                                            
  MFP_PN(E, 4,L),  //100    EBI_nWR/SD0_DAT2/SPIM_CLK/SPI3_CLK/SC0_RST/USCI0_DAT1/QEI0_INDEX/EPWM0_CH3/BPWM0_CH2                                                      
  MFP_PN(E, 3,L),  //101    EBI_MCLK/SD0_DAT1/SPIM_MISO/SPI3_MISO/SC0_DAT/USCI0_DAT0/QEI0_A/EPWM0_CH4/BPWM0_CH1                                                       
  MFP_PN(E, 2,L),  //102    EBI_ALE/SD0_DAT0/SPIM_MOSI/SPI3_MOSI/SC0_CLK/USCI0_CLK/QEI0_B/EPWM0_CH5/BPWM0_CH0                                                         
  MFP_NULL      ,  //103    VSS                                                                                                                                       
  MFP_NULL      ,  //104    VDD                                                                                                                                       
  MFP_PN(E, 1, L), //105    EBI_AD10/QSPI0_MISO0/SC2_DAT/I2S0_BCLK/SPI1_MISO/UART3_TXD/I2C1_SCL/UART4_nCTS                                                            
  MFP_PN(E, 0, L), //106    EBI_AD11/QSPI0_MOSI0/SC2_CLK/I2S0_MCLK/SPI1_MOSI/UART3_RXD/I2C1_SDA/UART4_nRTS                                                            
  MFP_PN(H, 8, H), //107    EBI_AD12/QSPI0_CLK/SC2_PWR/I2S0_DI/SPI1_CLK/UART3_nRTS/I2C1_SMBAL/I2C2_SCL/UART1_TXD                                                      
  MFP_PN(H, 9, H), //108    EBI_AD13/QSPI0_SS/SC2_RST/I2S0_DO/SPI1_SS/UART3_nCTS/I2C1_SMBSUS/I2C2_SDA/UART1_RXD                                                       
  MFP_PN(H, 10,H), //109    EBI_AD14/QSPI0_MISO1/SC2_nCD/I2S0_LRCK/SPI1_I2SMCLK/UART4_TXD/UART0_TXD                                                                   
  MFP_PN(H, 11,H), //110    EBI_AD15/QSPI0_MOSI1/UART4_RXD/UART0_RXD/EPWM0_CH5                                                                                        
  MFP_PN(D, 14,H), //111    EBI_nCS0/SPI3_I2SMCLK/SC1_nCD/EPWM0_CH4                                                                                                   
  MFP_NULL       , //112    VSS                                                                                                                                       
  MFP_NULL       , //113    LDO_CAP                                                                                                                                   
  MFP_NULL       , //114    VDD                                                                                                                                       
  MFP_PN(C, 14,H), //115    EBI_AD11/SC1_nCD/SPI0_I2SMCLK/USCI0_CTL0/QSPI0_CLK/EPWM0_SYNC_IN/TM1/USB_VBUS_ST/HSUSB_VBUS_ST                                            
  MFP_PN(B, 15,H), //116    EADC0_CH15/EBI_AD12/SC1_PWR/SPI0_SS/USCI0_CTL1/UART0_nCTS/UART3_TXD/I2C2_SMBAL/EPWM1_CH0/TM0_EXT/USB_VBUS_EN/HSUSB_VBUS_EN                
  MFP_PN(B, 14,H), //117    EADC0_CH14/EBI_AD13/SC1_RST/SPI0_CLK/USCI0_DAT1/UART0_nRTS/UART3_RXD/I2C2_SMBSUS/EPWM1_CH1/TM1_EXT/CLKO                                   
  MFP_PN(B, 13,H), //118    EADC0_CH13/DAC1_OUT/ACMP0_P3/ACMP1_P3/EBI_AD14/SC1_DAT/SPI0_MISO/USCI0_DAT0/UART0_TXD/UART3_nRTS/I2C2_SCL/EPWM1_CH2/TM2_EXT               
  MFP_PN(B, 12,H), //119    EADC0_CH12/DAC0_OUT/ACMP0_P2/ACMP1_P2/EBI_AD15/SC1_CLK/SPI0_MOSI/USCI0_CLK/UART0_RXD/UART3_nCTS/I2C2_SDA/SD0_nCD/EPWM1_CH3/TM3_EXT        
  MFP_NULL       , //120    AVDD                                                                                                                                      
  MFP_NULL       , //121    VREF                                                                                                                                      
  MFP_NULL       , //122    AVSS                                                                                                                                      
  MFP_PN(B, 11,H), //123    EADC0_CH11/EBI_ADR16/EMAC_RMII_MDC/UART0_nCTS/UART4_TXD/I2C1_SCL/CAN0_TXD/SPI0_I2SMCLK/BPWM1_CH0/SPI3_CLK/HSUSB_VBUS_ST                   
  MFP_PN(B, 10,H), //124    EADC0_CH10/EBI_ADR17/EMAC_RMII_MDIO/USCI1_CTL0/UART0_nRTS/UART4_RXD/I2C1_SDA/CAN0_RXD/BPWM1_CH1/SPI3_SS/HSUSB_VBUS_EN                     
  MFP_PN(B, 9, H), //125    EADC0_CH9/EBI_ADR18/EMAC_RMII_TXD0/USCI1_CTL1/UART0_TXD/UART1_nCTS/I2C1_SMBAL/BPWM1_CH2/SPI3_MISO/INT7                                    
  MFP_PN(B, 8, H), //126    EADC0_CH8/EBI_ADR19/EMAC_RMII_TXD1/USCI1_CLK/UART0_RXD/UART1_nRTS/I2C1_SMBSUS/BPWM1_CH3/SPI3_MOSI/INT6                                    
  MFP_PN(B, 7, L), //127    EADC0_CH7/EBI_nWRL/EMAC_RMII_TXEN/USCI1_DAT0/CAN1_TXD/UART1_TXD/SD1_CMD/EBI_nCS0/BPWM1_CH4/EPWM1_BRAKE0/EPWM1_CH4/INT5/USB_VBUS_ST/ACMP0_O
  MFP_PN(B, 6, L), //128    EADC0_CH6/EBI_nWRH/EMAC_PPS/USCI1_DAT1/CAN1_RXD/UART1_RXD/SD1_CLK/EBI_nCS1/BPWM1_CH5/EPWM1_BRAKE1/EPWM1_CH5/INT4/USB_VBUS_EN/ACMP1_O      
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[] = { //SYS_GPA_MFPL_PA5MFP_PWM0_CH0
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 0, 500, {PB_5, SYS_GPB_MFPL_PB5MFP_EPWM0_CH0 }}, //0  PB5
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 1, 500, {PB_4, SYS_GPB_MFPL_PB4MFP_EPWM0_CH1 }}, //1  PB4
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 2, 500, {PB_3, SYS_GPB_MFPL_PB3MFP_EPWM0_CH2 }}, //2  PB3
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 3, 500, {PB_2, SYS_GPB_MFPL_PB2MFP_EPWM0_CH3 }}, //3  PB2
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 4, 500, {PB_1, SYS_GPB_MFPL_PB1MFP_EPWM0_CH4 }}, //4  PB1
  {EPWM0, EPWM0_MODULE, EPWM0P1_IRQn, 5, 500, {PB_0, SYS_GPB_MFPL_PB0MFP_EPWM0_CH5 }}, //5  PB0
  {EPWM0, EPWM0_MODULE, EPWM0P0_IRQn, 2, 500, {PA_3, SYS_GPA_MFPL_PA3MFP_EPWM0_CH2 }}, //6  PA3
  {EPWM0, EPWM0_MODULE, EPWM0P0_IRQn, 3, 500, {PA_2, SYS_GPA_MFPL_PA2MFP_EPWM0_CH3 }}, //7  PA2
  {EPWM0, EPWM0_MODULE, EPWM0P0_IRQn, 4, 500, {PA_1, SYS_GPA_MFPL_PA1MFP_EPWM0_CH4 }}, //8  PA1
  {EPWM0, EPWM0_MODULE, EPWM0P0_IRQn, 5, 500, {PA_0, SYS_GPA_MFPL_PA0MFP_EPWM0_CH5 }}, //9  PA0

  {EPWM1, EPWM1_MODULE, EPWM1P2_IRQn, 4, 500, {PC_1, SYS_GPC_MFPL_PC1MFP_EPWM1_CH4 }}, //1  PC1
  {EPWM1, EPWM1_MODULE, EPWM1P2_IRQn, 5, 500, {PC_0, SYS_GPC_MFPL_PC0MFP_EPWM1_CH5 }}, //5  PC0
  {EPWM1, EPWM0_MODULE, EPWM1P1_IRQn, 0, 500, {PB_15,SYS_GPB_MFPH_PB15MFP_EPWM1_CH0}}, //6  PB15
  {EPWM1, EPWM0_MODULE, EPWM1P1_IRQn, 1, 500, {PB_14,SYS_GPB_MFPH_PB14MFP_EPWM1_CH1}}, //6  PB14
  {EPWM1, EPWM0_MODULE, EPWM1P1_IRQn, 2, 500, {PB_13,SYS_GPB_MFPH_PB13MFP_EPWM1_CH2}}, //6  PB13
  {EPWM1, EPWM0_MODULE, EPWM1P1_IRQn, 3, 500, {PB_12,SYS_GPB_MFPH_PB12MFP_EPWM1_CH3}}, //6  PB12

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
   {PA_1,SYS_GPA_MFPL_PA1MFP_SPI0_MISO},{PA_3,SYS_GPA_MFPL_PA3MFP_SPI0_SS}},      /* Loc 0 */
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = {
  {{PB_3,SYS_GPB_MFPL_PB3MFP_SPI1_CLK} ,{PB_4,SYS_GPB_MFPL_PB4MFP_SPI1_MOSI },
   {PB_5,SYS_GPB_MFPL_PB5MFP_SPI1_MISO},{PB_2,SYS_GPB_MFPL_PB2MFP_SPI1_SS}},      /* Loc 0 */
};
const SPIPinAlt_TypeDef SPI2PinAlt[] = {
  {{PA_13,SYS_GPA_MFPH_PA13MFP_SPI2_CLK} ,{PA_15,SYS_GPA_MFPH_PA15MFP_SPI2_MOSI},
   {PA_14,SYS_GPA_MFPH_PA14MFP_SPI2_MISO},{PA_12,SYS_GPA_MFPH_PA12MFP_SPI2_SS}},  /* Loc 0 */
};
const SPIPinDescription SPI_Desc[] = {
  {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL2_SPI0SEL_PCLK1,SPI0PinAlt},
  {SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL2_SPI2SEL_PCLK1,SPI1PinAlt},
  {SPI2,SPI2_MODULE,SPI2_IRQn,CLK_CLKSEL2_SPI2SEL_PCLK1,SPI2PinAlt},
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
  {{PB_12,SYS_GPB_MFPH_PB12MFP_UART0_RXD}, {PB_13,SYS_GPB_MFPH_PB13MFP_UART0_TXD}},  //Loc 3
  {{PF_2, SYS_GPF_MFPL_PF2MFP_UART0_RXD }, {PF_3, SYS_GPF_MFPL_PF3MFP_UART0_TXD }},  //Loc 0
  {{PA_0, SYS_GPA_MFPL_PA0MFP_UART0_RXD }, {PA_1, SYS_GPA_MFPL_PA1MFP_UART0_TXD }},  //Loc 1
  {{PA_15,SYS_GPA_MFPH_PA15MFP_UART0_RXD}, {PA_14,SYS_GPA_MFPH_PA14MFP_UART0_TXD}},  //Loc 2 
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
  {{PB_2, SYS_GPB_MFPL_PB2MFP_UART1_RXD }, {PB_3, SYS_GPB_MFPL_PB3MFP_UART1_TXD }},  //Loc 0
  {{PA_2, SYS_GPA_MFPL_PA2MFP_UART1_RXD }, {PA_3, SYS_GPA_MFPL_PA3MFP_UART1_TXD }},  //Loc 1
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
  {{PA_2, SYS_GPA_MFPL_PA2MFP_UART4_RXD }, {PA_3, SYS_GPA_MFPL_PA3MFP_UART4_TXD }},  //Loc 0
  {{PA_13,SYS_GPA_MFPH_PA13MFP_UART4_RXD}, {PA_12,SYS_GPA_MFPH_PA12MFP_UART4_TXD}},  //Loc 1
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
  {I2C0, I2C0_MODULE,I2C0_IRQn, I2C0PinAlt},
  {I2C1, I2C1_MODULE,I2C1_IRQn, I2C1PinAlt},
  {I2C2, I2C2_MODULE,I2C2_IRQn, I2C2PinAlt},
};
#endif

#ifndef CAN_DESC_USERDEF
const CANPinDescription CAN_Desc[] = {
//  {CAN0, CAN0_MODULE, CAN0_IRQn, {{84, SYS_GPA_MFPH_PA13MFP_CAN0_RXD}, {83, SYS_GPA_MFPH_PA12MFP_CAN0_TXD}}},
};
#endif


