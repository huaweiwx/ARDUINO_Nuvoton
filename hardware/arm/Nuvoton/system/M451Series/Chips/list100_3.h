/****************************************************************************
 * @file     M453(LQFP100)
 * @version  V1.13
 * @Date     2018/10/19-12:23:34 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2018 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef _CHIP100_PINLIST_H_
#define _CHIP100_PINLIST_H_

#if USE_ICE >0
#define CHIP_PIN_LIST \
PIN(B,13,1  ), /* EADC_CH10                                                          */\
PIN(B,14,2  ), /* EADC_CH11                                                          */\
PIN(B,15,3  ), /* EADC_CH12/ACMP0_P3/EBI_nCS1                                        */\
PIN(B,5 ,4  ), /* EADC_CH13/SPI0_MOSI0/SPI1_MOSI/ACMP0_P2/EBI_AD6                    */\
PIN(B,6 ,5  ), /* EADC_CH14/SPI0_MISO0/SPI1_MISO/ACMP0_P1/EBI_AD5                    */\
PIN(B,7 ,6  ), /* EADC_CH15/SPI0_CLK/SPI1_CLK/ACMP0_P0/EBI_AD4                       */\
    /*  ,7  ),  nRESET                                                             */\
PIN(D,0 ,8  ), /* SPI1_I2SMCLK/UART0_RXD/ACMP1_N/INT3                                */\
/*PIN( ,  ,9  ),  AVSS                                                               */\
/*PIN( ,  ,10 ),  VDD                                                                */\
/*PIN( ,  ,11 ),  VSS                                                                */\
PIN(C,8 ,12 ), /*                                                                    */\
PIN(D,8 ,13 ), /* /EBI_nCS0                                                          */\
PIN(D,9 ,14 ), /* /ACMP1_P3/EBI_ALE                                                  */\
PIN(D,1 ,15 ), /* /PWM0_SYNC_IN/UART0_TXD/ACMP1_P2/T0/EBI_nRD                        */\
PIN(D,2 ,16 ), /* /STADC/T0_EXT/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                    */\
PIN(D,3 ,17 ), /* /T2/T1_EXT/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1                      */\
PIN(D,4 ,18 ), /* /SPI1_CLK/I2C0_SDA/PWM0_BRAKE0/T0                                  */\
PIN(D,5 ,19 ), /* /CLKO/SPI1_MISO/I2C0_SCL/PWM0_BRAKE1/T1                            */\
PIN(E,3 ,20 ), /* /SPI1_MOSI/PWM0_CH3                                                */\
PIN(D,6 ,21 ), /* /CLKO/SPI1_SS/UART0_RXD/ACMP0_O/PWM0_CH5/EBI_nWR                   */\
/*PIN( ,  ,22 ),    VBAT                                                             */\
PIN(F,0 ,23 ), /* 32_OUT/INT5                                                        */\
PIN(F,1 ,24 ), /* 32_IN                                                              */\
PIN(F,2 ,25 ), /* AMPER                                                              */\
PIN(D,10,26 ), /* T2                                                                 */\
PIN(D,11,27 ), /* T3                                                                 */\
PIN(D,12,28 ), /* SPI2_SS/UART3_TXD/PWM1_CH0/EBI_ADR16                               */\
PIN(D,13,29 ), /* SPI2_MOSI/UART3_RXD/PWM1_CH1/EBI_ADR17                             */\
PIN(D,14,30 ), /* SPI2_MISO/UART3_nCTS/PWM1_CH2/EBI_ADR18                            */\
PIN(D,15,31 ), /* SPI2_CLK/UART3_nRTS/PWM1_CH3/EBI_ADR19                             */\
PIN(D,7 ,32 ), /* WM0_SYNC_IN/T1/ACMP0_O/PWM0_CH5/EBI_nRD                            */\
PIN(F,3 ,33 ), /* T1_OUT/I2C1_SCL                                                    */\
PIN(F,4 ,34 ), /* T1_IN/I2C1_SDA                                                     */\
/*PIN( ,  ,35 ),  SS                                                                 */\
/*PIN( ,  ,36 ),  DD                                                                 */\
/*PIN( ,  ,37 ),  DO_CAP                                                             */\
PIN(C,9 ,38 ), /* PI2_I2SMCLK/PWM1_CH0                                               */\
PIN(C,10,39 ), /* SPI2_MOSI/PWM1_CH1                                                 */\
PIN(C,11,40 ), /* SPI2_MISO/PWM1_CH2                                                 */\
PIN(C,12,41 ), /* SPI2_CLK/PWM1_CH3                                                  */\
PIN(C,13,42 ), /* SPI2_SS/PWM1_CH4                                                   */\
PIN(C,14,43 ), /* PWM1_CH5                                                           */\
PIN(C,0 ,44 ), /* SPI2_CLK/UART2_nCTS/CAN0_TXD/PWM0_CH0/EBI_AD8/INT2                 */\
PIN(C,1 ,45 ), /* CLKO/STDAC/UART2_nRTS/CAN0_RXD/PWM0_CH1/EBI_AD9                    */\
PIN(C,2 ,46 ), /* SPI2_SS/UART2_TXD/ACMP1_O/PWM0_CH2/EBI_AD10                        */\
PIN(C,3 ,47 ), /* SPI2_MOSI/UART2_RXD/USB_VBUS_ST/PWM0_CH3/EBI_AD11                  */\
PIN(C,4 ,48 ), /* SPI2_MISO/I2C1_SCL/USB_VBUS_EN/PWM0_CH4/EBI_AD12                   */\
PIN(E,0 ,49 ), /* SPI2_CLK/I2C1_SDA/T2_EXT/SC0_CD/PWM0_CH0/EBI_nCS1/INT4             */\
PIN(C,5 ,50 ), /* SPI2_I2SMCLK/PWM0_CH5/EBI_AD13                                     */\
PIN(C,6 ,51 ), /* I2C1_SMBAL/ACMP1_O/PWM1_CH0/EBI_AD14                               */\
PIN(C,7 ,52 ), /* I2C1_SMBSUS/PWM1_CH1/EBI_AD15                                      */\
PIN(E,4 ,53 ), /* I2C1_SCL/SC0_PWR/PWM1_BRAKE0/EBI_nCS0/INT0                         */\
PIN(E,5 ,54 ), /* I2C1_SDA/SC0_RST/PWM1_BRAKE1/EBI_ALE/INT1                          */\
/*PIN(F,5 ,55 ),  ICE_CLK                                                            */\
/*PIN(F,6 ,56 ),  ICE_DAT                                                            */\
PIN(A,8 ,57 ), /* UART3_TXD                                                          */\
PIN(A,9 ,58 ), /* UART3_RXD                                                          */\
PIN(A,7 ,59 ), /* SPI1_CLK/T0_EXT/EBI_AD7                                            */\
PIN(A,6 ,60 ), /* SPI1_MISO/T1_EXT/EBI_AD6                                           */\
PIN(A,5 ,61 ), /* SPI1_MOSI/T2_EXT/EBI_AD5                                           */\
PIN(A,4 ,62 ), /* SPI1_SS/EBI_AD4                                                    */\
/*PIN( ,  ,63 ),  VSS                                                                */\
/*PIN( ,  ,64 ),  VDD                                                                */\
PIN(E,1 ,65 ), /* T3_EXT/SC0_CD/PWM0_CH1                                             */\
PIN(E,8 ,66 ), /* UART1_TXD/SPI0_MISO1/I2C1_SCL/SC0_PWR                              */\
PIN(E,9 ,67 ), /* UART1_RXD/SPI0_MOSI1/I2C1_SDA/SC0_RST                              */\
PIN(E,10,68 ), /* SPI1_MISO/SPI0_MISO0/UART1_nCTS/I2C0_SMBAL/SC0_DAT                 */\
PIN(E,11,69 ), /* SPI1_MOSI/SPI0_MOSI0/UART1_nRTS/I2C0_SMBSUS/SC0_CLK                */\
PIN(E,12,70 ), /* SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL                                 */\
PIN(E,13,71 ), /* SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA                               */\
/*PIN( ,  ,72 ),  VDDIO                                                              */\
/*PIN( ,  ,73 ),  USB_VBUS                                                           */\
/*PIN( ,  ,74 ),  USB_D-                                                             */\
/*PIN( ,  ,75 ),  USB_D+                                                             */\
/*PIN( ,  ,76 ),  USB_ID                                                             */\
/*PIN( ,  ,77 ),  USB_VDD33_CAP                                                      */\
PIN(E,2 ,78 ), /* PWM1_CH1                                                           */\
PIN(A,3 ,79 ), /* USB_VBUS_ST/UART0_RXD/UART0_nRTS/I2C0_SCL/SC0_PWR/PWM1_CH2/EBI_AD3 */\
PIN(A,2 ,80 ), /* USB_VBUS_EN/UART0_TXD/UART0_nCTS/I2C0_SDA/SC0_RST/PWM1_CH3/EBI_AD2 */\
PIN(A,1 ,81 ), /* UART1_nRTS/UART1_RXD/CAN0_TXD/SC0_DAT/PWM1_CH4/EBI_AD1             */\
PIN(A,0 ,82 ), /* UART1_nCTS/UART1_TXD/CAN0_RXD/SC0_CLK/PWM1_CH5/EBI_AD0/INT0        */\
PIN(A,12,83 ), /* SPI1_I2SMCLK/CAN0_TXD                                              */\
PIN(A,13,84 ), /* CAN0_RXD                                                           */\
PIN(A,14,85 ), /* UART2_nCTS/I2C0_SMBAL                                              */\
PIN(A,15,86 ), /* UART2_nRTS/I2C0_SMBSUS                                             */\
/*PIN( ,  ,87 ),  VSS                                                                */\
/*PIN( ,  ,88 ),  VDD                                                                */\
/*PIN( ,  ,89 ),  AVDD                                                               */\
/*PIN( ,  ,90 ),  VREF                                                               */\
PIN(B,0 ,91 ), /* EADC_CH0/SPI0_MOSI1/UART2_RXD/T2/DAC/EBI_nWRL/INT1                 */\
PIN(B,1 ,92 ), /* EADC_CH1/SPI0_MISO1/UART2_TXD/T3/SC0_RST/PWM0_SYNC_OUT/EBI_nWRH    */\
PIN(B,2 ,93 ), /* EADC_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/SC0_CD                        */\
PIN(B,3 ,94 ), /* EADC_CH3/SPI0_MISO0/SPI1_MISO/UART1_TXD                            */\
PIN(B,4 ,95 ), /* EADC_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7                */\
PIN(B,8 ,96 ), /* EADC_CH5/UART1_nRTS/PWM0_CH2                                       */\
PIN(B,9 ,97 ), /* EADC_CH6                                                           */\
PIN(B,10,98 ), /* EADC_CH7                                                           */\
PIN(B,11,99 ), /* EADC_CH8                                                           */\
PIN(B,12,100)  /* EADC_CH9*/

#else
#define CHIP_PIN_LIST \
PIN(B,13,1  ), /* EADC_CH10                                                          */\
PIN(B,14,2  ), /* EADC_CH11                                                          */\
PIN(B,15,3  ), /* EADC_CH12/ACMP0_P3/EBI_nCS1                                        */\
PIN(B,5 ,4  ), /* EADC_CH13/SPI0_MOSI0/SPI1_MOSI/ACMP0_P2/EBI_AD6                    */\
PIN(B,6 ,5  ), /* EADC_CH14/SPI0_MISO0/SPI1_MISO/ACMP0_P1/EBI_AD5                    */\
PIN(B,7 ,6  ), /* EADC_CH15/SPI0_CLK/SPI1_CLK/ACMP0_P0/EBI_AD4                       */\
    /*  ,7  ),  nRESET                                                             */\
PIN(D,0 ,8  ), /* SPI1_I2SMCLK/UART0_RXD/ACMP1_N/INT3                                */\
/*PIN( ,  ,9  ),  AVSS                                                               */\
/*PIN( ,  ,10 ),  VDD                                                                */\
/*PIN( ,  ,11 ),  VSS                                                                */\
PIN(C,8 ,12 ), /*                                                                    */\
PIN(D,8 ,13 ), /* /EBI_nCS0                                                          */\
PIN(D,9 ,14 ), /* /ACMP1_P3/EBI_ALE                                                  */\
PIN(D,1 ,15 ), /* /PWM0_SYNC_IN/UART0_TXD/ACMP1_P2/T0/EBI_nRD                        */\
PIN(D,2 ,16 ), /* /STADC/T0_EXT/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                    */\
PIN(D,3 ,17 ), /* /T2/T1_EXT/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1                      */\
PIN(D,4 ,18 ), /* /SPI1_CLK/I2C0_SDA/PWM0_BRAKE0/T0                                  */\
PIN(D,5 ,19 ), /* /CLKO/SPI1_MISO/I2C0_SCL/PWM0_BRAKE1/T1                            */\
PIN(E,3 ,20 ), /* /SPI1_MOSI/PWM0_CH3                                                */\
PIN(D,6 ,21 ), /* /CLKO/SPI1_SS/UART0_RXD/ACMP0_O/PWM0_CH5/EBI_nWR                   */\
/*PIN( ,  ,22 ),    VBAT                                                             */\
PIN(F,0 ,23 ), /* 32_OUT/INT5                                                        */\
PIN(F,1 ,24 ), /* 32_IN                                                              */\
PIN(F,2 ,25 ), /* AMPER                                                              */\
PIN(D,10,26 ), /* T2                                                                 */\
PIN(D,11,27 ), /* T3                                                                 */\
PIN(D,12,28 ), /* SPI2_SS/UART3_TXD/PWM1_CH0/EBI_ADR16                               */\
PIN(D,13,29 ), /* SPI2_MOSI/UART3_RXD/PWM1_CH1/EBI_ADR17                             */\
PIN(D,14,30 ), /* SPI2_MISO/UART3_nCTS/PWM1_CH2/EBI_ADR18                            */\
PIN(D,15,31 ), /* SPI2_CLK/UART3_nRTS/PWM1_CH3/EBI_ADR19                             */\
PIN(D,7 ,32 ), /* WM0_SYNC_IN/T1/ACMP0_O/PWM0_CH5/EBI_nRD                            */\
PIN(F,3 ,33 ), /* T1_OUT/I2C1_SCL                                                    */\
PIN(F,4 ,34 ), /* T1_IN/I2C1_SDA                                                     */\
/*PIN( ,  ,35 ),  SS                                                                 */\
/*PIN( ,  ,36 ),  DD                                                                 */\
/*PIN( ,  ,37 ),  DO_CAP                                                             */\
PIN(C,9 ,38 ), /* PI2_I2SMCLK/PWM1_CH0                                               */\
PIN(C,10,39 ), /* SPI2_MOSI/PWM1_CH1                                                 */\
PIN(C,11,40 ), /* SPI2_MISO/PWM1_CH2                                                 */\
PIN(C,12,41 ), /* SPI2_CLK/PWM1_CH3                                                  */\
PIN(C,13,42 ), /* SPI2_SS/PWM1_CH4                                                   */\
PIN(C,14,43 ), /* PWM1_CH5                                                           */\
PIN(C,0 ,44 ), /* SPI2_CLK/UART2_nCTS/CAN0_TXD/PWM0_CH0/EBI_AD8/INT2                 */\
PIN(C,1 ,45 ), /* CLKO/STDAC/UART2_nRTS/CAN0_RXD/PWM0_CH1/EBI_AD9                    */\
PIN(C,2 ,46 ), /* SPI2_SS/UART2_TXD/ACMP1_O/PWM0_CH2/EBI_AD10                        */\
PIN(C,3 ,47 ), /* SPI2_MOSI/UART2_RXD/USB_VBUS_ST/PWM0_CH3/EBI_AD11                  */\
PIN(C,4 ,48 ), /* SPI2_MISO/I2C1_SCL/USB_VBUS_EN/PWM0_CH4/EBI_AD12                   */\
PIN(E,0 ,49 ), /* SPI2_CLK/I2C1_SDA/T2_EXT/SC0_CD/PWM0_CH0/EBI_nCS1/INT4             */\
PIN(C,5 ,50 ), /* SPI2_I2SMCLK/PWM0_CH5/EBI_AD13                                     */\
PIN(C,6 ,51 ), /* I2C1_SMBAL/ACMP1_O/PWM1_CH0/EBI_AD14                               */\
PIN(C,7 ,52 ), /* I2C1_SMBSUS/PWM1_CH1/EBI_AD15                                      */\
PIN(E,4 ,53 ), /* I2C1_SCL/SC0_PWR/PWM1_BRAKE0/EBI_nCS0/INT0                         */\
PIN(E,5 ,54 ), /* I2C1_SDA/SC0_RST/PWM1_BRAKE1/EBI_ALE/INT1                          */\
PIN(F,5 ,55 ), /* ICE_CLK                                                            */\
PIN(F,6 ,56 ), /* ICE_DAT                                                            */\
PIN(A,8 ,57 ), /* UART3_TXD                                                          */\
PIN(A,9 ,58 ), /* UART3_RXD                                                          */\
PIN(A,7 ,59 ), /* SPI1_CLK/T0_EXT/EBI_AD7                                            */\
PIN(A,6 ,60 ), /* SPI1_MISO/T1_EXT/EBI_AD6                                           */\
PIN(A,5 ,61 ), /* SPI1_MOSI/T2_EXT/EBI_AD5                                           */\
PIN(A,4 ,62 ), /* SPI1_SS/EBI_AD4                                                    */\
/*PIN( ,  ,63 ),  VSS                                                                */\
/*PIN( ,  ,64 ),  VDD                                                                */\
PIN(E,1 ,65 ), /* T3_EXT/SC0_CD/PWM0_CH1                                             */\
PIN(E,8 ,66 ), /* UART1_TXD/SPI0_MISO1/I2C1_SCL/SC0_PWR                              */\
PIN(E,9 ,67 ), /* UART1_RXD/SPI0_MOSI1/I2C1_SDA/SC0_RST                              */\
PIN(E,10,68 ), /* SPI1_MISO/SPI0_MISO0/UART1_nCTS/I2C0_SMBAL/SC0_DAT                 */\
PIN(E,11,69 ), /* SPI1_MOSI/SPI0_MOSI0/UART1_nRTS/I2C0_SMBSUS/SC0_CLK                */\
PIN(E,12,70 ), /* SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL                                 */\
PIN(E,13,71 ), /* SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA                               */\
/*PIN( ,  ,72 ),  VDDIO                                                              */\
/*PIN( ,  ,73 ),  USB_VBUS                                                           */\
/*PIN( ,  ,74 ),  USB_D-                                                             */\
/*PIN( ,  ,75 ),  USB_D+                                                             */\
/*PIN( ,  ,76 ),  USB_ID                                                             */\
/*PIN( ,  ,77 ),  USB_VDD33_CAP                                                      */\
PIN(E,2 ,78 ), /* PWM1_CH1                                                           */\
PIN(A,3 ,79 ), /* USB_VBUS_ST/UART0_RXD/UART0_nRTS/I2C0_SCL/SC0_PWR/PWM1_CH2/EBI_AD3 */\
PIN(A,2 ,80 ), /* USB_VBUS_EN/UART0_TXD/UART0_nCTS/I2C0_SDA/SC0_RST/PWM1_CH3/EBI_AD2 */\
PIN(A,1 ,81 ), /* UART1_nRTS/UART1_RXD/CAN0_TXD/SC0_DAT/PWM1_CH4/EBI_AD1             */\
PIN(A,0 ,82 ), /* UART1_nCTS/UART1_TXD/CAN0_RXD/SC0_CLK/PWM1_CH5/EBI_AD0/INT0        */\
PIN(A,12,83 ), /* SPI1_I2SMCLK/CAN0_TXD                                              */\
PIN(A,13,84 ), /* CAN0_RXD                                                           */\
PIN(A,14,85 ), /* UART2_nCTS/I2C0_SMBAL                                              */\
PIN(A,15,86 ), /* UART2_nRTS/I2C0_SMBSUS                                             */\
/*PIN( ,  ,87 ),  VSS                                                                */\
/*PIN( ,  ,88 ),  VDD                                                                */\
/*PIN( ,  ,89 ),  AVDD                                                               */\
/*PIN( ,  ,90 ),  VREF                                                               */\
PIN(B,0 ,91 ), /* EADC_CH0/SPI0_MOSI1/UART2_RXD/T2/DAC/EBI_nWRL/INT1                 */\
PIN(B,1 ,92 ), /* EADC_CH1/SPI0_MISO1/UART2_TXD/T3/SC0_RST/PWM0_SYNC_OUT/EBI_nWRH    */\
PIN(B,2 ,93 ), /* EADC_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/SC0_CD                        */\
PIN(B,3 ,94 ), /* EADC_CH3/SPI0_MISO0/SPI1_MISO/UART1_TXD                            */\
PIN(B,4 ,95 ), /* EADC_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7                */\
PIN(B,8 ,96 ), /* EADC_CH5/UART1_nRTS/PWM0_CH2                                       */\
PIN(B,9 ,97 ), /* EADC_CH6                                                           */\
PIN(B,10,98 ), /* EADC_CH7                                                           */\
PIN(B,11,99 ), /* EADC_CH8                                                           */\
PIN(B,12,100)  /* EADC_CH9*/

#endif

#define SS_PIN   PD_12
#define MOSI_PIN PD_13
#define MISO_PIN PD_14
#define SCK_PIN  PD_15

#define SDA_PIN  PD_4
#define SCL_PIN  PD_5


#define A0   0
#define A1   1
#define A2   2
#define A3   3
#define A4   4
#define A5   5

#endif

