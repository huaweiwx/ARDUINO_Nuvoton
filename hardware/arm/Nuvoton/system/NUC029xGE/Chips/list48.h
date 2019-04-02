/****************************************************************************
 * @file     MCU: NUC029LGE(LQFP48)
 * @version  V1.14
 * @Date     2019/03/29-20:37:48 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2019 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#if USE_ICE >0

#define CHIP_PIN_LIST \
PIN(B,5,1 ),   /*ADC0_CH13/SPI0_MOSI/SPI1_MOSI/ACMP0_P2/EBI_AD6/UART2_RXD                         */\
PIN(B,6,2 ),   /*ADC0_CH14/SPI0_MISO/SPI1_MISO/ACMP0_P1/EBI_AD5                                   */\
PIN(B,7,3 ),   /*ADC0_CH15/SPI0_CLK/SPI1_CLK/USCI2_CTL1/ACMP0_P0/EBI_AD4                          */\
/*    4          nRESET                                                                           */\
PIN(D,0,5 ),   /*SPI0_I2SMCLK/SPI1_I2SMCLK/UART0_RXD/USCI2_CTL0/ACMP1_N/INT3                      */\
/*    6          AVSS                                                                             */\
PIN(D,1,7 ),   /*ADC0_CH19/PWM0_SYNC_IN/UART0_TXD/USCI2_CLK/ACMP1_P2/TM0/EBI_nRD                  */\
PIN(D,2,8 ),   /*ADC0_ST/TM0_EXT/USCI2_DAT0/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                     */\
PIN(D,3,9 ),   /*TM2/SPI0_I2SMCLK/TM1_EXT/USCI2_DAT1/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1           */\
/*    10         VBAT                                                                             */\
PIN(F,0,11),   /*X32_OUT/USCI2_CTL1/INT5                                                          */\
PIN(F,1,12),   /*X32_IN/USCI2_CTL0/PWM1_BRAKE0                                                    */\
PIN(F,2,13),   /*USCI2_CLK/PWM1_BRAKE1                                                            */\
PIN(D,7,14),   /*USCI1_CTL1/SPI0_I2SMCLK/PWM0_SYNC_IN/TM1/ACMP0_O/PWM0_CH5/EBI_nRD                */\
PIN(F,3,15),   /*XT1_OUT/I2C1_SCL                                                                 */\
PIN(F,4,16),   /*XT1_IN/I2C1_SDA                                                                  */\
/*    17         VSS                                                                              */\
/*    18         VDD                                                                              */\
PIN(C,0,19),   /*SPI0_CLK/UART2_nCTS/USCI0_DAT0/ACMP0_WLAT/PWM0_CH0/EBI_AD8/INT2                  */\
PIN(C,1,20),   /*CLKO/UART2_nRTS/USCI0_DAT1/ACMP1_WLAT/PWM0_CH1/EBI_AD9                           */\
PIN(C,2,21),   /*SPI0_SS/UART2_TXD/USCI0_CTL1/ACMP1_O/PWM0_CH2/EBI_AD10                           */\
PIN(C,3,22),   /*SPI0_MOSI/UART2_RXD/USCI0_CTL0/PWM0_CH3/EBI_AD11                                 */\
PIN(C,4,23),   /*SPI0_MISO/I2C1_SCL/USCI0_CLK/PWM0_CH4/EBI_AD12                                   */\
PIN(E,0,24),   /*SPI0_CLK/I2C1_SDA/TM2_EXT/PWM0_CH0/EBI_nCS1/INT4                                 */\
/*PIN(E,6,25),   ICE_CLK/I2C0_SCL/UART0_RXD                                                       */\
/*PIN(E,7,26),   ICE_DAT/I2C0_SDA/UART0_TXD                                                       */\
PIN(E,10,27),   /*SPI1_MISO/SPI0_MISO/UART1_nCTS/SPI1_CLK/EBI_AD7/TM0_EXT                          */\
PIN(E,11,28),   /*SPI1_MOSI/SPI0_MOSI/UART1_nRTS/SPI1_MISO/EBI_AD6/TM1_EXT                         */\
PIN(E,12,29),   /*SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL/SPI1_MOSI/EBI_AD5/TM2_EXT                     */\
PIN(E,13,30),   /*SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA/SPI1_SS/EBI_AD4/TM3_EXT                     */\
/*    31          VDDIO                                                                            */\
/*    32          USB_VBUS                                                                         */\
/*    33          USB_D+                                                                           */\
/*    34          USB_D-                                                                           */\
PIN(F,7,35),   /*                                                                                 */\
/*    36          USB_VDD33_CAP                                                                    */\
PIN(A,3,37),    /*UART0_RXD/UART0_nRTS/I2C0_SCL/PWM1_CH2/EBI_AD3/USCI1_CLK                         */\
PIN(A,2,38),    /*UART0_TXD/UART0_nCTS/I2C0_SDA/PWM1_CH3/EBI_AD2/USCI1_CTL0                        */\
PIN(A,1,39),    /*UART1_nRTS/UART1_RXD/USCI1_CTL1/PWM1_CH4/EBI_AD1                                 */\
PIN(A,0,40),    /*UART1_nCTS/UART1_TXD/USCI1_CTL0/PWM1_CH5/EBI_AD0/INT0                            */\
/*    41          VDD                                                                              */\
/*    42          AVDD                                                                             */\
/*    43          VREF                                                                             */\
PIN(B,0,44),    /*ADC0_CH0/VDET_P0/UART2_RXD/TM2/USCI1_DAT0/EBI_nWRL/INT1/TM1_EXT                  */\
PIN(B,1,45),    /*ADC0_CH1/VDET_P1/UART2_TXD/TM3/PWM0_SYNC_OUT/EBI_nWRH/USCI1_DAT1                 */\
PIN(B,2,46),    /*ADC0_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/TM_BRAKE0/EBI_nCS0/USCI0_DAT0/TM2_EXT       */\
PIN(B,3,47),    /*ADC0_CH3/SPI0_MISO/SPI1_MISO/UART1_TXD/TM_BRAKE1/EBI_ALE/USCI0_DAT1/TM0_EXT      */\
PIN(B,4,48)     /*ADC0_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7/USCI0_CTL1/UART2_RXD/TM1_EXT */


#else
	
#define CHIP_PIN_LIST \
PIN(B,5,1 ),   /*ADC0_CH13/SPI0_MOSI/SPI1_MOSI/ACMP0_P2/EBI_AD6/UART2_RXD                         */\
PIN(B,6,2 ),   /*ADC0_CH14/SPI0_MISO/SPI1_MISO/ACMP0_P1/EBI_AD5                                   */\
PIN(B,7,3 ),   /*ADC0_CH15/SPI0_CLK/SPI1_CLK/USCI2_CTL1/ACMP0_P0/EBI_AD4                          */\
/*    4        nRESET                                                                           */\
PIN(D,0,5 ),   /*SPI0_I2SMCLK/SPI1_I2SMCLK/UART0_RXD/USCI2_CTL0/ACMP1_N/INT3                      */\
/*    6        AVSS                                                                             */\
PIN(D,1,7 ),   /*ADC0_CH19/PWM0_SYNC_IN/UART0_TXD/USCI2_CLK/ACMP1_P2/TM0/EBI_nRD                  */\
PIN(D,2,8 ),   /*ADC0_ST/TM0_EXT/USCI2_DAT0/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                     */\
PIN(D,3,9 ),   /*TM2/SPI0_I2SMCLK/TM1_EXT/USCI2_DAT1/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1           */\
/*    10       VBAT                                                                             */\
PIN(F,0,11),   /*X32_OUT/USCI2_CTL1/INT5                                                          */\
PIN(F,1,12),   /*X32_IN/USCI2_CTL0/PWM1_BRAKE0                                                    */\
PIN(F,2,13),   /*USCI2_CLK/PWM1_BRAKE1                                                            */\
PIN(D,7,14),   /*USCI1_CTL1/SPI0_I2SMCLK/PWM0_SYNC_IN/TM1/ACMP0_O/PWM0_CH5/EBI_nRD                */\
PIN(F,3,15),   /*XT1_OUT/I2C1_SCL                                                                 */\
PIN(F,4,16),   /*XT1_IN/I2C1_SDA                                                                  */\
/*    17       VSS                                                                              */\
/*    18       VDD                                                                              */\
PIN(C,0,19),   /*SPI0_CLK/UART2_nCTS/USCI0_DAT0/ACMP0_WLAT/PWM0_CH0/EBI_AD8/INT2                  */\
PIN(C,1,20),   /*CLKO/UART2_nRTS/USCI0_DAT1/ACMP1_WLAT/PWM0_CH1/EBI_AD9                           */\
PIN(C,2,21),   /*SPI0_SS/UART2_TXD/USCI0_CTL1/ACMP1_O/PWM0_CH2/EBI_AD10                           */\
PIN(C,3,22),   /*SPI0_MOSI/UART2_RXD/USCI0_CTL0/PWM0_CH3/EBI_AD11                                 */\
PIN(C,4,23),   /*SPI0_MISO/I2C1_SCL/USCI0_CLK/PWM0_CH4/EBI_AD12                                   */\
PIN(E,0,24),   /*SPI0_CLK/I2C1_SDA/TM2_EXT/PWM0_CH0/EBI_nCS1/INT4                                 */\
PIN(E,6,25),   /*ICE_CLK/I2C0_SCL/UART0_RXD                                                       */\
PIN(E,7,26),   /*ICE_DAT/I2C0_SDA/UART0_TXD                                                       */\
PIN(E,10,27),   /*SPI1_MISO/SPI0_MISO/UART1_nCTS/SPI1_CLK/EBI_AD7/TM0_EXT                          */\
PIN(E,11,28),   /*SPI1_MOSI/SPI0_MOSI/UART1_nRTS/SPI1_MISO/EBI_AD6/TM1_EXT                         */\
PIN(E,12,29),   /*SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL/SPI1_MOSI/EBI_AD5/TM2_EXT                     */\
PIN(E,13,30),   /*SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA/SPI1_SS/EBI_AD4/TM3_EXT                     */\
/*    31       VDDIO                                                                            */\
/*    32       USB_VBUS                                                                         */\
/*    33       USB_D+                                                                           */\
/*    34       USB_D-                                                                           */\
PIN(F,7,35),   /*                                                                                 */\
/*    36       USB_VDD33_CAP                                                                    */\
PIN(A,3,37),   /*UART0_RXD/UART0_nRTS/I2C0_SCL/PWM1_CH2/EBI_AD3/USCI1_CLK                         */\
PIN(A,2,38),   /*UART0_TXD/UART0_nCTS/I2C0_SDA/PWM1_CH3/EBI_AD2/USCI1_CTL0                        */\
PIN(A,1,39),   /*UART1_nRTS/UART1_RXD/USCI1_CTL1/PWM1_CH4/EBI_AD1                                 */\
PIN(A,0,40),   /*UART1_nCTS/UART1_TXD/USCI1_CTL0/PWM1_CH5/EBI_AD0/INT0                            */\
/*    41       VDD                                                                              */\
/*    42       AVDD                                                                             */\
/*    43       VREF                                                                             */\
PIN(B,0,44),   /*ADC0_CH0/VDET_P0/UART2_RXD/TM2/USCI1_DAT0/EBI_nWRL/INT1/TM1_EXT                  */\
PIN(B,1,45),   /*ADC0_CH1/VDET_P1/UART2_TXD/TM3/PWM0_SYNC_OUT/EBI_nWRH/USCI1_DAT1                 */\
PIN(B,2,46),   /*ADC0_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/TM_BRAKE0/EBI_nCS0/USCI0_DAT0/TM2_EXT       */\
PIN(B,3,47),   /*ADC0_CH3/SPI0_MISO/SPI1_MISO/UART1_TXD/TM_BRAKE1/EBI_ALE/USCI0_DAT1/TM0_EXT      */\
PIN(B,4,48)    /*ADC0_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7/USCI0_CTL1/UART2_RXD/TM1_EXT */

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