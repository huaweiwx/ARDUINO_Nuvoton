/****************************************************************************
 * @file     M031TB0AE.csv
 * @version  V1.14
 * @Date     2019/03/24-10:32:48 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2019 Nuvoton Technology Corp. All rights reserved.
MCU: M031TB0AE(QFN33)
*****************************************************************************/

#ifndef _CHIP33_PINLIST_H_
#define _CHIP33_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
      PIN(B, 5,1 ),   /* ADC0_CH5/I2C0_SCL/PWM0_CH0/UART2_TXD/TM0/INT0                 */\
      PIN(B, 4,2 ),   /* ADC0_CH4/I2C0_SDA/PWM0_CH1/UART2_RXD/TM1/INT1                 */\
      PIN(B, 3,3 ),   /* ADC0_CH3/I2C1_SCL/UART1_TXD/PWM0_CH2/PWM0_BRAKE0/INT2         */\
      PIN(B, 2,4 ),   /* ADC0_CH2/I2C1_SDA/UART1_RXD/PWM0_CH3/INT3                     */\
      PIN(B, 1,5 ),   /* ADC0_CH1/UART2_TXD/I2C1_SCL/PWM0_CH4/PWM0_BRAKE0              */\
      PIN(B, 0,6 ),   /* ADC0_CH0/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/PWM0_CH5/PWM0_BRAKE1 */\
      PIN(F, 5,7 ),   /* UART2_RXD/UART2_nCTS/PWM0_CH0/ADC0_ST                         */\
      PIN(F, 4,8 ),   /* UART2_TXD/UART2_nRTS/PWM0_CH1                                 */\
      PIN(F, 3,9 ),   /* UART0_TXD/I2C0_SCL/XT1_IN                                     */\
      PIN(F, 2,10),   /* UART0_RXD/I2C0_SDA/XT1_OUT                                    */\
      PIN(A, 3,11),   /* SPI0_SS/UART1_TXD/I2C1_SCL/PWM0_CH2/CLKO                      */\
      PIN(A, 2,12),   /* SPI0_CLK/UART1_RXD/I2C1_SDA/PWM0_CH3                          */\
      PIN(A, 1,13),   /* SPI0_MISO/UART0_TXD/UART1_nCTS/PWM0_CH4                       */\
      PIN(A, 0,14),   /* SPI0_MOSI/UART0_RXD/UART1_nRTS/PWM0_CH5                       */\
      PIN(F,15,15),   /* PWM0_BRAKE0/PWM0_CH1/CLKO/INT4                                */\
      /*       16        nRESET                                                        */\
/*    PIN(F, 0,17),      UART1_TXD/I2C1_SCL/UART0_TXD/ICE_DAT                          */\
/*    PIN(F, 1,18),      UART1_RXD/I2C1_SDA/UART0_RXD/ICE_CLK                          */\
      PIN(C, 1,19),   /* UART2_TXD/I2C0_SCL                                            */\
      PIN(C, 0,20),   /* UART2_RXD/I2C0_SDA                                            */\
      PIN(A,12,21),   /* I2C1_SCL                                                      */\
      PIN(A,13,22),   /* I2C1_SDA                                                      */\
      PIN(A,14,23),   /* UART0_TXD                                                     */\
      PIN(A,15,24),   /* UART0_RXD                                                     */\
      /*       25        VSS                                                           */\
      /*       26        LDO_CAP                                                       */\
      /*       27        VDD                                                           */\
      PIN(B,15,28),   /* ADC0_CH15/SPI0_SS/UART0_nCTS/TM0_EXT/PWM0_BRAKE1              */\
      PIN(B,14,29),   /* ADC0_CH14/SPI0_CLK/UART0_nRTS/TM1_EXT/CLKO                    */\
      PIN(B,13,30),   /* ADC0_CH13/SPI0_MISO/UART0_TXD                                 */\
      PIN(B,12,31)    /* ADC0_CH12/SPI0_MOSI/UART0_RXD                                 */
      /*       32        AVDD                                                          */
#else /*used ICE*/
  #define CHIP_PIN_LIST \
      PIN(B, 5,1 ),   /* ADC0_CH5/I2C0_SCL/PWM0_CH0/UART2_TXD/TM0/INT0                 */\
      PIN(B, 4,2 ),   /* ADC0_CH4/I2C0_SDA/PWM0_CH1/UART2_RXD/TM1/INT1                 */\
      PIN(B, 3,3 ),   /* ADC0_CH3/I2C1_SCL/UART1_TXD/PWM0_CH2/PWM0_BRAKE0/INT2         */\
      PIN(B, 2,4 ),   /* ADC0_CH2/I2C1_SDA/UART1_RXD/PWM0_CH3/INT3                     */\
      PIN(B, 1,5 ),   /* ADC0_CH1/UART2_TXD/I2C1_SCL/PWM0_CH4/PWM0_BRAKE0              */\
      PIN(B, 0,6 ),   /* ADC0_CH0/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/PWM0_CH5/PWM0_BRAKE1 */\
      PIN(F, 5,7 ),   /* UART2_RXD/UART2_nCTS/PWM0_CH0/ADC0_ST                         */\
      PIN(F, 4,8 ),   /* UART2_TXD/UART2_nRTS/PWM0_CH1                                 */\
      PIN(F, 3,9 ),   /* UART0_TXD/I2C0_SCL/XT1_IN                                     */\
      PIN(F, 2,10),   /* UART0_RXD/I2C0_SDA/XT1_OUT                                    */\
      PIN(A, 3,11),   /* SPI0_SS/UART1_TXD/I2C1_SCL/PWM0_CH2/CLKO                      */\
      PIN(A, 2,12),   /* SPI0_CLK/UART1_RXD/I2C1_SDA/PWM0_CH3                          */\
      PIN(A, 1,13),   /* SPI0_MISO/UART0_TXD/UART1_nCTS/PWM0_CH4                       */\
      PIN(A, 0,14),   /* SPI0_MOSI/UART0_RXD/UART1_nRTS/PWM0_CH5                       */\
      PIN(F,15,15),   /* PWM0_BRAKE0/PWM0_CH1/CLKO/INT4                                */\
      /*       16        nRESET                                                        */\
      PIN(F, 0,17),   /* UART1_TXD/I2C1_SCL/UART0_TXD/ICE_DAT                          */\
      PIN(F, 1,18),   /* UART1_RXD/I2C1_SDA/UART0_RXD/ICE_CLK                          */\
      PIN(C, 1,19),   /* UART2_TXD/I2C0_SCL                                            */\
      PIN(C, 0,20),   /* UART2_RXD/I2C0_SDA                                            */\
      PIN(A,12,21),   /* I2C1_SCL                                                      */\
      PIN(A,13,22),   /* I2C1_SDA                                                      */\
      PIN(A,14,23),   /* UART0_TXD                                                     */\
      PIN(A,15,24),   /* UART0_RXD                                                     */\
      /*       25        VSS                                                           */\
      /*       26        LDO_CAP                                                       */\
      /*       27        VDD                                                           */\
      PIN(B,15,28),   /* ADC0_CH15/SPI0_SS/UART0_nCTS/TM0_EXT/PWM0_BRAKE1              */\
      PIN(B,14,29),   /* ADC0_CH14/SPI0_CLK/UART0_nRTS/TM1_EXT/CLKO                    */\
      PIN(B,13,30),   /* ADC0_CH13/SPI0_MISO/UART0_TXD                                 */\
      PIN(B,12,31)    /* ADC0_CH12/SPI0_MOSI/UART0_RXD                                 */
      /*       32        AVDD                                                          */
#endif

#define MISO_PIN PB_5
#define MOSI_PIN PB_4
#define  SCK_PIN PB_3
#define   SS_PIN PB_2

#define  SDA_PIN PC_0
#define  SCL_PIN PC_1

#define A0  0
#define A1  1
#define A2  2
#define A3  3
#define A4  4
#define A5  5

#endif
