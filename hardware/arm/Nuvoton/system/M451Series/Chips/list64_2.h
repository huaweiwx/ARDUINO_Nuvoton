/****************************************************************************
 * @file     M452(LQFP64)
 * @version  V1.13
 * @Date     2018/10/19-12:23:34 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2018 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#if USE_ICE >0
#define CHIP_PIN_LIST \
PIN(B,15,1 ),  /* EADC_CH12/ACMP0_P3/EBI_nCS1                                        */\
PIN(B,5 ,2 ),  /* EADC_CH13/SPI0_MOSI0/SPI1_MOSI/ACMP0_P2/EBI_AD6                    */\
PIN(B,6 ,3 ),  /* EADC_CH14/SPI0_MISO0/SPI1_MISO/ACMP0_P1/EBI_AD5                    */\
PIN(B,7 ,4 ),  /* EADC_CH15/SPI0_CLK/SPI1_CLK/ACMP0_P0/EBI_AD4                       */\
/* IN( ,  ,5 ),   nRESET                                                             */\
PIN(D,0 ,6 ),  /* SPI1_I2SMCLK/UART0_RXD/ACMP1_N/INT3                                */\
/* IN( ,  ,7 ),   AVSS                                                               */\
PIN(D,8 ,8 ),  /* EBI_nCS0                                                           */\
PIN(D,9 ,9 ),  /* ACMP1_P3/EBI_ALE                                                   */\
PIN(D,1 ,10),  /* PWM0_SYNC_IN/UART0_TXD/ACMP1_P2/T0/EBI_nRD                         */\
PIN(D,2 ,11),  /* STADC/T0_EXT/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                     */\
PIN(D,3 ,12),  /* T2/T1_EXT/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1                       */\
/* IN( ,  ,13),   VBAT                                                               */\
PIN(F,0 ,14),  /* X32_OUT/INT5                                                       */\
PIN(F,1 ,15),  /* X32_IN                                                             */\
PIN(F,2 ,16),  /* TAMPER                                                             */\
PIN(D,12,17),  /* /SPI2_SS/UART3_TXD/PWM1_CH0/EBI_ADR16                              */\
PIN(D,13,18),  /* /SPI2_MOSI/UART3_RXD/PWM1_CH1/EBI_ADR17                            */\
PIN(D,14,19),  /* /SPI2_MISO/UART3_nCTS/PWM1_CH2/EBI_ADR18                           */\
PIN(D,15,20),  /* /SPI2_CLK/UART3_nRTS/PWM1_CH3/EBI_ADR19                            */\
PIN(D,7 ,21),  /* PWM0_SYNC_IN/T1/ACMP0_O/PWM0_CH5/EBI_nRD                           */\
PIN(F,3 ,22),  /* XT1_OUT/I2C1_SCL                                                   */\
PIN(F,4 ,23),  /* XT1_IN/I2C1_SDA                                                    */\
/* IN( ,  ,24),   VSS                                                                */\
/* IN( ,  ,25),   VDD                                                                */\
/* IN( ,  ,26),   LDO_CAP                                                            */\
PIN(C,0 ,27),  /* SPI2_CLK/UART2_nCTS/PWM0_CH0/EBI_AD8/INT2                          */\
PIN(C,1 ,28),  /* CLKO/STDAC/UART2_nRTS/PWM0_CH1/EBI_AD9                             */\
PIN(C,2 ,29),  /* SPI2_SS/UART2_TXD/ACMP1_O/PWM0_CH2/EBI_AD10                        */\
PIN(C,3 ,30),  /* SPI2_MOSI/UART2_RXD/USB_VBUS_ST/PWM0_CH3/EBI_AD11                  */\
PIN(C,4 ,31),  /* SPI2_MISO/I2C1_SCL/USB_VBUS_EN/PWM0_CH4/EBI_AD12                   */\
PIN(C,5 ,32),  /* SPI2_I2SMCLK/PWM0_CH5/EBI_AD13                                     */\
PIN(C,6 ,33),  /* I2C1_SMBAL/ACMP1_O/PWM1_CH0/EBI_AD14                               */\
PIN(C,7 ,34),  /* I2C1_SMBSUS/PWM1_CH1/EBI_AD15                                      */\
/*PIN(F,5 ,35),   ICE_CLK                                                            */\
/*PIN(F,6 ,36),   ICE_DAT                                                            */\
PIN(E,8 ,37),  /* UART1_TXD/SPI0_MISO1/I2C1_SCL/SC0_PWR                              */\
PIN(E,9 ,38),  /* UART1_RXD/SPI0_MOSI1/I2C1_SDA/SC0_RST                              */\
PIN(E,10,39),  /* SPI1_MISO/SPI0_MISO0/UART1_nCTS/I2C0_SMBAL/SC0_DAT                 */\
PIN(E,11,40),  /* SPI1_MOSI/SPI0_MOSI0/UART1_nRTS/I2C0_SMBSUS/SC0_CLK                */\
PIN(E,12,41),  /* SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL                                 */\
PIN(E,13,42),  /* SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA                               */\
/* IN( ,  ,43),   VDDIO                                                              */\
/* IN( ,  ,44),   USB_VBUS                                                           */\
/* IN( ,  ,45),   USB_D-                                                             */\
/* IN( ,  ,46),   USB_D+                                                             */\
/* IN( ,  ,47),   USB_ID                                                             */\
/* IN( ,  ,48),   USB_VDD33_CAP                                                      */\
PIN(A,3 ,49),  /* USB_VBUS_ST/UART0_RXD/UART0_nRTS/I2C0_SCL/SC0_PWR/PWM1_CH2/EBI_AD3 */\
PIN(A,2 ,50),  /* USB_VBUS_EN/UART0_TXD/UART0_nCTS/I2C0_SDA/SC0_RST/PWM1_CH3/EBI_AD2 */\
PIN(A,1 ,51),  /* UART1_nRTS/UART1_RXD/SC0_DAT/PWM1_CH4/EBI_AD1                      */\
PIN(A,0 ,52),  /* UART1_nCTS/UART1_TXD/SC0_CLK/PWM1_CH5/EBI_AD0/INT0                 */\
/* IN( ,  ,53),   VSS                                                                */\
/* IN( ,  ,54),   VDD                                                                */\
/* IN( ,  ,55),   AVDD                                                               */\
/* IN( ,  ,56),   VREF                                                               */\
PIN(B,0 ,57),  /* EADC_CH0/SPI0_MOSI1/UART2_RXD/T2/DAC/EBI_nWRL/INT1                 */\
PIN(B,1 ,58),  /* EADC_CH1/SPI0_MISO1/UART2_TXD/T3/SC0_RST/PWM0_SYNC_OUT/EBI_nWRH    */\
PIN(B,2 ,59),  /* EADC_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/SC0_CD                        */\
PIN(B,3 ,60),  /* EADC_CH3/SPI0_MISO0/SPI1_MISO/UART1_TXD                            */\
PIN(B,4 ,61),  /* EADC_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7                */\
PIN(B,8 ,62),  /* EADC_CH5/UART1_nRTS/PWM0_CH2                                       */\
PIN(B,11,63),  /* EADC_CH8                                                           */\
PIN(B,12,64)   /* EADC_CH9                                                           */

#else
#define CHIP_PIN_LIST \
PIN(B,15,1 ),  /* EADC_CH12/ACMP0_P3/EBI_nCS1                                        */\
PIN(B,5 ,2 ),  /* EADC_CH13/SPI0_MOSI0/SPI1_MOSI/ACMP0_P2/EBI_AD6                    */\
PIN(B,6 ,3 ),  /* EADC_CH14/SPI0_MISO0/SPI1_MISO/ACMP0_P1/EBI_AD5                    */\
PIN(B,7 ,4 ),  /* EADC_CH15/SPI0_CLK/SPI1_CLK/ACMP0_P0/EBI_AD4                       */\
/* IN( ,  ,5 ),   nRESET                                                             */\
PIN(D,0 ,6 ),  /* SPI1_I2SMCLK/UART0_RXD/ACMP1_N/INT3                                */\
/* IN( ,  ,7 ),   AVSS                                                               */\
PIN(D,8 ,8 ),  /* EBI_nCS0                                                           */\
PIN(D,9 ,9 ),  /* ACMP1_P3/EBI_ALE                                                   */\
PIN(D,1 ,10),  /* PWM0_SYNC_IN/UART0_TXD/ACMP1_P2/T0/EBI_nRD                         */\
PIN(D,2 ,11),  /* STADC/T0_EXT/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                     */\
PIN(D,3 ,12),  /* T2/T1_EXT/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1                       */\
/* IN( ,  ,13),   VBAT                                                               */\
PIN(F,0 ,14),  /* X32_OUT/INT5                                                       */\
PIN(F,1 ,15),  /* X32_IN                                                             */\
PIN(F,2 ,16),  /* TAMPER                                                             */\
PIN(D,1 ,17),  /* /SPI2_SS/UART3_TXD/PWM1_CH0/EBI_ADR16                              */\
PIN(D,1 ,18),  /* /SPI2_MOSI/UART3_RXD/PWM1_CH1/EBI_ADR17                            */\
PIN(D,1 ,19),  /* /SPI2_MISO/UART3_nCTS/PWM1_CH2/EBI_ADR18                           */\
PIN(D,1 ,20),  /* /SPI2_CLK/UART3_nRTS/PWM1_CH3/EBI_ADR19                            */\
PIN(D,7 ,21),  /* PWM0_SYNC_IN/T1/ACMP0_O/PWM0_CH5/EBI_nRD                           */\
PIN(F,3 ,22),  /* XT1_OUT/I2C1_SCL                                                   */\
PIN(F,4 ,23),  /* XT1_IN/I2C1_SDA                                                    */\
/* IN( ,  ,24),   VSS                                                                */\
/* IN( ,  ,25),   VDD                                                                */\
/* IN( ,  ,26),   LDO_CAP                                                            */\
PIN(C,0 ,27),  /* SPI2_CLK/UART2_nCTS/PWM0_CH0/EBI_AD8/INT2                          */\
PIN(C,1 ,28),  /* CLKO/STDAC/UART2_nRTS/PWM0_CH1/EBI_AD9                             */\
PIN(C,2 ,29),  /* SPI2_SS/UART2_TXD/ACMP1_O/PWM0_CH2/EBI_AD10                        */\
PIN(C,3 ,30),  /* SPI2_MOSI/UART2_RXD/USB_VBUS_ST/PWM0_CH3/EBI_AD11                  */\
PIN(C,4 ,31),  /* SPI2_MISO/I2C1_SCL/USB_VBUS_EN/PWM0_CH4/EBI_AD12                   */\
PIN(C,5 ,32),  /* SPI2_I2SMCLK/PWM0_CH5/EBI_AD13                                     */\
PIN(C,6 ,33),  /* I2C1_SMBAL/ACMP1_O/PWM1_CH0/EBI_AD14                               */\
PIN(C,7 ,34),  /* I2C1_SMBSUS/PWM1_CH1/EBI_AD15                                      */\
PIN(F,5 ,35),  /* ICE_CLK                                                            */\
PIN(F,6 ,36),  /* ICE_DAT                                                            */\
PIN(E,8 ,37),  /* UART1_TXD/SPI0_MISO1/I2C1_SCL/SC0_PWR                              */\
PIN(E,9 ,38),  /* UART1_RXD/SPI0_MOSI1/I2C1_SDA/SC0_RST                              */\
PIN(E,10,39),  /* SPI1_MISO/SPI0_MISO0/UART1_nCTS/I2C0_SMBAL/SC0_DAT                 */\
PIN(E,11,40),  /* SPI1_MOSI/SPI0_MOSI0/UART1_nRTS/I2C0_SMBSUS/SC0_CLK                */\
PIN(E,12,41),  /* SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL                                 */\
PIN(E,13,42),  /* SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA                               */\
/* IN( ,  ,43),   VDDIO                                                              */\
/* IN( ,  ,44),   USB_VBUS                                                           */\
/* IN( ,  ,45),   USB_D-                                                             */\
/* IN( ,  ,46),   USB_D+                                                             */\
/* IN( ,  ,47),   USB_ID                                                             */\
/* IN( ,  ,48),   USB_VDD33_CAP                                                      */\
PIN(A,3 ,49),  /* USB_VBUS_ST/UART0_RXD/UART0_nRTS/I2C0_SCL/SC0_PWR/PWM1_CH2/EBI_AD3 */\
PIN(A,2 ,50),  /* USB_VBUS_EN/UART0_TXD/UART0_nCTS/I2C0_SDA/SC0_RST/PWM1_CH3/EBI_AD2 */\
PIN(A,1 ,51),  /* UART1_nRTS/UART1_RXD/SC0_DAT/PWM1_CH4/EBI_AD1                      */\
PIN(A,0 ,52),  /* UART1_nCTS/UART1_TXD/SC0_CLK/PWM1_CH5/EBI_AD0/INT0                 */\
/* IN( ,  ,53),   VSS                                                                */\
/* IN( ,  ,54),   VDD                                                                */\
/* IN( ,  ,55),   AVDD                                                               */\
/* IN( ,  ,56),   VREF                                                               */\
PIN(B,0 ,57),  /* EADC_CH0/SPI0_MOSI1/UART2_RXD/T2/DAC/EBI_nWRL/INT1                 */\
PIN(B,1 ,58),  /* EADC_CH1/SPI0_MISO1/UART2_TXD/T3/SC0_RST/PWM0_SYNC_OUT/EBI_nWRH    */\
PIN(B,2 ,59),  /* EADC_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/SC0_CD                        */\
PIN(B,3 ,60),  /* EADC_CH3/SPI0_MISO0/SPI1_MISO/UART1_TXD                            */\
PIN(B,4 ,61),  /* EADC_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7                */\
PIN(B,8 ,62),  /* EADC_CH5/UART1_nRTS/PWM0_CH2                                       */\
PIN(B,11,63),  /* EADC_CH8                                                           */\
PIN(B,12,64)   /* EADC_CH9                                                           */

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

