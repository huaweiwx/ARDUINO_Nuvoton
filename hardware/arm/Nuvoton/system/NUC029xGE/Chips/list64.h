/****************************************************************************
 * @file     NUC029SGE.csv
 * @version  V1.13
 * @Date     2019/03/22-23:33:18 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2019 Nuvoton Technology Corp. All rights reserved.
MCU: NUC029SGE(LQFP64)
*****************************************************************************/
#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#if USE_ICE >0

#define CHIP_PIN_LIST \
PIN(B,15,1 ),  /* ADC0_CH12/ACMP0_P3/EBI_nCS1                                                     */\
PIN(B,5 ,2 ),  /* ADC0_CH13/SPI0_MOSI/SPI1_MOSI/ACMP0_P2/EBI_AD6/UART2_RXD                        */\
PIN(B,6 ,3 ),  /* ADC0_CH14/SPI0_MISO/SPI1_MISO/ACMP0_P1/EBI_AD5                                  */\
PIN(B,7 ,4 ),  /* ADC0_CH15/SPI0_CLK/SPI1_CLK/USCI2_CTL1/ACMP0_P0/EBI_AD4                         */\
 /*      5        nRESET                                                                          */\
PIN(D,0 ,6 ),  /* SPI0_I2SMCLK/SPI1_I2SMCLK/UART0_RXD/USCI2_CTL0/ACMP1_N/INT3                     */\
 /*      7        AVSS                                                                            */\
PIN(D,8 ,8 ),  /* ADC0_CH17/UART0_nCTS/USCI2_CTL1/TM2/EBI_nCS0                                    */\
PIN(D,9 ,9 ),  /* ADC0_CH18/UART0_RXD/USCI2_CTL0/ACMP1_P3/TM3/EBI_ALE                             */\
PIN(D,1 ,10),  /* ADC0_CH19/PWM0_SYNC_IN/UART0_TXD/USCI2_CLK/ACMP1_P2/TM0/EBI_nRD                  */\
PIN(D,2 ,11),  /* ADC0_ST/TM0_EXT/USCI2_DAT0/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                     */\
PIN(D,3 ,12),  /* TM2/SPI0_I2SMCLK/TM1_EXT/USCI2_DAT1/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1           */\
 /*      13       VBAT                                                                               */\
PIN(F,0 ,14),  /* X32_OUT/USCI2_CTL1/INT5                                                          */\
PIN(F,1 ,15),  /* X32_IN/USCI2_CTL0/PWM1_BRAKE0                                                    */\
PIN(F,2 ,16),  /* USCI2_CLK/PWM1_BRAKE1                                                            */\
PIN(D,12,17),  /* USCI1_CTL0/SPI1_SS/UART0_TXD/PWM1_CH0/EBI_ADR16                                  */\
PIN(D,13,18),  /* USCI1_DAT1/SPI1_MOSI/UART0_RXD/PWM1_CH1/EBI_ADR17                                */\
PIN(D,14,19),  /* USCI1_DAT0/SPI1_MISO/UART0_nCTS/PWM1_CH2/EBI_ADR18                               */\
PIN(D,15,20),  /* USCI1_CLK/SPI1_CLK/UART0_nRTS/PWM1_CH3/EBI_ADR19                                 */\
PIN(D,7 ,21),  /* USCI1_CTL1/SPI0_I2SMCLK/PWM0_SYNC_IN/TM1/ACMP0_O/PWM0_CH5/EBI_nRD                */\
PIN(F,3 ,22),  /* XT1_OUT/I2C1_SCL                                                                 */\
PIN(F,4 ,23),  /* XT1_IN/I2C1_SDA                                                                  */\
 /*      24       VSS                                                                              */\
 /*      25       VDD                                                                              */\
 /*      26       VDD                                                                              */\
PIN(C,0 ,27),  /* SPI0_CLK/UART2_nCTS/USCI0_DAT0/ACMP0_WLAT/PWM0_CH0/EBI_AD8/INT2                  */\
PIN(C,1 ,28),  /* CLKO/UART2_nRTS/USCI0_DAT1/ACMP1_WLAT/PWM0_CH1/EBI_AD9                           */\
PIN(C,2 ,29),  /* SPI0_SS/UART2_TXD/USCI0_CTL1/ACMP1_O/PWM0_CH2/EBI_AD10                           */\
PIN(C,3 ,30),  /* SPI0_MOSI/UART2_RXD/USCI0_CTL0/PWM0_CH3/EBI_AD11                                 */\
PIN(C,4 ,31),  /* SPI0_MISO/I2C1_SCL/USCI0_CLK/PWM0_CH4/EBI_AD12                                   */\
PIN(C,5 ,32),  /* SPI0_I2SMCLK/I2C1_SDA/USCI0_DAT0/PWM0_CH5/EBI_AD13                               */\
PIN(C,6 ,33),  /* USCI0_DAT1/ACMP1_O/PWM1_CH0/EBI_AD14                                             */\
PIN(C,7 ,34),  /* USCI0_CTL1/PWM1_CH1/EBI_AD15                                                     */\
/* PIN(E,6 ,35),  ICE_CLK/I2C0_SCL/UART0_RXD                                                       */\
/* PIN(E,7 ,36),  ICE_DAT/I2C0_SDA/UART0_TXD                                                       */\
PIN(E,8 ,37),  /* UART1_TXD/TM0/I2C1_SCL                                                           */\
PIN(E,9 ,38),  /* UART1_RXD/TM1/I2C1_SDA                                                           */\
PIN(E,10,39),  /* SPI1_MISO/SPI0_MISO/UART1_nCTS/SPI1_CLK/EBI_AD7/TM0_EXT                          */\
PIN(E,11,40),  /* SPI1_MOSI/SPI0_MOSI/UART1_nRTS/SPI1_MISO/EBI_AD6/TM1_EXT                         */\
PIN(E,12,41),  /* SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL/SPI1_MOSI/EBI_AD5/TM2_EXT                     */\
PIN(E,13,42),  /* SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA/SPI1_SS/EBI_AD4/TM3_EXT                     */\
 /*      43       VDDIO                                                                            */\
 /*      44       USB_VBUS                                                                         */\
 /*      45       USB_D+                                                                           */\
 /*      46       USB_D-                                                                           */\
PIN(F,7,47),     /*                                                                                  */\
 /*      48       USB_VDD33_CAP                                                                    */\
PIN(A,3 ,49),  /* UART0_RXD/UART0_nRTS/I2C0_SCL/PWM1_CH2/EBI_AD3/USCI1_CLK                         */\
PIN(A,2 ,50),  /* UART0_TXD/UART0_nCTS/I2C0_SDA/PWM1_CH3/EBI_AD2/USCI1_CTL0                        */\
PIN(A,1 ,51),  /* UART1_nRTS/UART1_RXD/USCI1_CTL1/PWM1_CH4/EBI_AD1                                 */\
PIN(A,0 ,52),  /* UART1_nCTS/UART1_TXD/USCI1_CTL0/PWM1_CH5/EBI_AD0/INT0                            */\
 /*      53       VSS                                                                              */\
 /*      54       VDD                                                                              */\
 /*      55       AVDD                                                                             */\
 /*      56       VREF                                                                             */\
PIN(B,0 ,57),  /* ADC0_CH0/VDET_P0/UART2_RXD/TM2/USCI1_DAT0/EBI_nWRL/INT1/TM1_EXT                  */\
PIN(B,1 ,58),  /* ADC0_CH1/VDET_P1/UART2_TXD/TM3/PWM0_SYNC_OUT/EBI_nWRH/USCI1_DAT1                 */\
PIN(B,2 ,59),  /* ADC0_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/TM_BRAKE0/EBI_nCS0/USCI0_DAT0/TM2_EXT       */\
PIN(B,3 ,60),  /* ADC0_CH3/SPI0_MISO/SPI1_MISO/UART1_TXD/TM_BRAKE1/EBI_ALE/USCI0_DAT1/TM0_EXT      */\
PIN(B,4 ,61),  /* ADC0_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7/USCI0_CTL1/UART2_RXD/TM1_EXT */\
PIN(B,8 ,62),  /* ADC0_CH5/UART1_nRTS/TM_BRAKE2/PWM0_CH2/USCI0_CTL0                                */\
PIN(B,11,63),  /* ADC0_CH8                                                                         */\
PIN(E,2 ,64)   /* ADC0_CH9/UART1_nRTS/TM_BRAKE3/PWM0_CH2/USCI0_CTL0                                */

#else /*used ICE*/

#define CHIP_PIN_LIST \
PIN(B,15,1 ),  /* /ADC0_CH12/ACMP0_P3/EBI_nCS1                                                     */\
PIN(B,5 ,2 ),  /* /ADC0_CH13/SPI0_MOSI/SPI1_MOSI/ACMP0_P2/EBI_AD6/UART2_RXD                        */\
PIN(B,6 ,3 ),  /* /ADC0_CH14/SPI0_MISO/SPI1_MISO/ACMP0_P1/EBI_AD5                                  */\
PIN(B,7 ,4 ),  /* /ADC0_CH15/SPI0_CLK/SPI1_CLK/USCI2_CTL1/ACMP0_P0/EBI_AD4                         */\
 /*      5         nRESET                                                                          */\
PIN(D,0 ,6 ),  /* /SPI0_I2SMCLK/SPI1_I2SMCLK/UART0_RXD/USCI2_CTL0/ACMP1_N/INT3                     */\
 /*      7       AVSS                                                                              */\
PIN(D,8 ,8 ),  /* /ADC0_CH17/UART0_nCTS/USCI2_CTL1/TM2/EBI_nCS0                                    */\
PIN(D,9 ,9 ),  /* /ADC0_CH18/UART0_RXD/USCI2_CTL0/ACMP1_P3/TM3/EBI_ALE                             */\
PIN(D,1 ,10),  /* ADC0_CH19/PWM0_SYNC_IN/UART0_TXD/USCI2_CLK/ACMP1_P2/TM0/EBI_nRD                  */\
PIN(D,2 ,11),  /* ADC0_ST/TM0_EXT/USCI2_DAT0/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                     */\
PIN(D,3 ,12),  /* TM2/SPI0_I2SMCLK/TM1_EXT/USCI2_DAT1/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1           */\
 /*      13     VBAT                                                                               */\
PIN(F,0 ,14),  /* X32_OUT/USCI2_CTL1/INT5                                                          */\
PIN(F,1 ,15),  /* X32_IN/USCI2_CTL0/PWM1_BRAKE0                                                    */\
PIN(F,2 ,16),  /* USCI2_CLK/PWM1_BRAKE1                                                            */\
PIN(D,12,17),  /* USCI1_CTL0/SPI1_SS/UART0_TXD/PWM1_CH0/EBI_ADR16                                  */\
PIN(D,13,18),  /* USCI1_DAT1/SPI1_MOSI/UART0_RXD/PWM1_CH1/EBI_ADR17                                */\
PIN(D,14,19),  /* USCI1_DAT0/SPI1_MISO/UART0_nCTS/PWM1_CH2/EBI_ADR18                               */\
PIN(D,15,20),  /* USCI1_CLK/SPI1_CLK/UART0_nRTS/PWM1_CH3/EBI_ADR19                                 */\
PIN(D,7 ,21),  /* USCI1_CTL1/SPI0_I2SMCLK/PWM0_SYNC_IN/TM1/ACMP0_O/PWM0_CH5/EBI_nRD                */\
PIN(F,3 ,22),  /* XT1_OUT/I2C1_SCL                                                                 */\
PIN(F,4 ,23),  /* XT1_IN/I2C1_SDA                                                                  */\
 /*      24       VSS                                                                              */\
 /*      25       VDD                                                                              */\
 /*      26       VDD                                                                              */\
PIN(C,0 ,27),  /* SPI0_CLK/UART2_nCTS/USCI0_DAT0/ACMP0_WLAT/PWM0_CH0/EBI_AD8/INT2                  */\
PIN(C,1 ,28),  /* CLKO/UART2_nRTS/USCI0_DAT1/ACMP1_WLAT/PWM0_CH1/EBI_AD9                           */\
PIN(C,2 ,29),  /* SPI0_SS/UART2_TXD/USCI0_CTL1/ACMP1_O/PWM0_CH2/EBI_AD10                           */\
PIN(C,3 ,30),  /* SPI0_MOSI/UART2_RXD/USCI0_CTL0/PWM0_CH3/EBI_AD11                                 */\
PIN(C,4 ,31),  /* SPI0_MISO/I2C1_SCL/USCI0_CLK/PWM0_CH4/EBI_AD12                                   */\
PIN(C,5 ,32),  /* SPI0_I2SMCLK/I2C1_SDA/USCI0_DAT0/PWM0_CH5/EBI_AD13                               */\
PIN(C,6 ,33),  /* USCI0_DAT1/ACMP1_O/PWM1_CH0/EBI_AD14                                             */\
PIN(C,7 ,34),  /* USCI0_CTL1/PWM1_CH1/EBI_AD15                                                     */\
PIN(E,6 ,35),  /* ICE_CLK/I2C0_SCL/UART0_RXD                                                       */\
PIN(E,7 ,36),  /* ICE_DAT/I2C0_SDA/UART0_TXD                                                       */\
PIN(E,8 ,37),  /* UART1_TXD/TM0/I2C1_SCL                                                           */\
PIN(E,9 ,38),  /* UART1_RXD/TM1/I2C1_SDA                                                           */\
PIN(E,10,39),  /* SPI1_MISO/SPI0_MISO/UART1_nCTS/SPI1_CLK/EBI_AD7/TM0_EXT                          */\
PIN(E,11,40),  /* SPI1_MOSI/SPI0_MOSI/UART1_nRTS/SPI1_MISO/EBI_AD6/TM1_EXT                         */\
PIN(E,12,41),  /* SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL/SPI1_MOSI/EBI_AD5/TM2_EXT                     */\
PIN(E,13,42),  /* SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA/SPI1_SS/EBI_AD4/TM3_EXT                     */\
 /*      43       VDDIO                                                                            */\
 /*      44       USB_VBUS                                                                         */\
 /*      45       USB_D+                                                                           */\
 /*      46       USB_D-                                                                           */\
 /*      47       PF.7                                                                             */\
 /*      48       USB_VDD33_CAP                                                                    */\
PIN(A,3 ,49),  /* UART0_RXD/UART0_nRTS/I2C0_SCL/PWM1_CH2/EBI_AD3/USCI1_CLK                         */\
PIN(A,2 ,50),  /* UART0_TXD/UART0_nCTS/I2C0_SDA/PWM1_CH3/EBI_AD2/USCI1_CTL0                        */\
PIN(A,1 ,51),  /* UART1_nRTS/UART1_RXD/USCI1_CTL1/PWM1_CH4/EBI_AD1                                 */\
PIN(A,0 ,52),  /* UART1_nCTS/UART1_TXD/USCI1_CTL0/PWM1_CH5/EBI_AD0/INT0                            */\
 /*      53       VSS                                                                              */\
 /*      54       VDD                                                                              */\
 /*      55       AVDD                                                                             */\
 /*      56       VREF                                                                             */\
PIN(B,0 ,57),  /* ADC0_CH0/VDET_P0/UART2_RXD/TM2/USCI1_DAT0/EBI_nWRL/INT1/TM1_EXT                  */\
PIN(B,1 ,58),  /* ADC0_CH1/VDET_P1/UART2_TXD/TM3/PWM0_SYNC_OUT/EBI_nWRH/USCI1_DAT1                 */\
PIN(B,2 ,59),  /* ADC0_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/TM_BRAKE0/EBI_nCS0/USCI0_DAT0/TM2_EXT       */\
PIN(B,3 ,60),  /* ADC0_CH3/SPI0_MISO/SPI1_MISO/UART1_TXD/TM_BRAKE1/EBI_ALE/USCI0_DAT1/TM0_EXT      */\
PIN(B,4 ,61),  /* ADC0_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7/USCI0_CTL1/UART2_RXD/TM1_EXT */\
PIN(B,8 ,62),  /* ADC0_CH5/UART1_nRTS/TM_BRAKE2/PWM0_CH2/USCI0_CTL0                                */\
PIN(B,11,63),  /* ADC0_CH8                                                                         */\
PIN(E,2 ,64)   /* ADC0_CH9/UART1_nRTS/TM_BRAKE3/PWM0_CH2/USCI0_CTL0                                */

#endif


#define   SS_PIN   P0_4
#define MOSI_PIN   P0_5
#define MISO_PIN   P0_6
#define  SCK_PIN   P0_7

#define  SDA_PIN  P3_4
#define  SCL_PIN  P3_5

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5

#endif

/*** (C) COPYRIGHT 2013-2018 Nuvoton Technology Corp. ***/