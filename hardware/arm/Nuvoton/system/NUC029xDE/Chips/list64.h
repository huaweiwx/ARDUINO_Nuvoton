/****************************************************************************
 * @file     NUC029SDE.csv
 * @version  V1.13
 * @Date     2018/11/10-19:38:16 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2018 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#if USE_ICE >0

#define CHIP_PIN_LIST \
PIN(B,14,1 ), /*  INT0                                 */\
PIN(B,13,2 ), /*                                       */\
PIN(B,12,3 ), /*  CLKO/BPWM1_CH3                       */\
PIN(F, 5,4 ), /*  I2C0_SCL/PWM1_CH5                    */\
PIN(F, 4,5 ), /*  I2C0_SDA/PWM1_CH4                    */\
PIN(A,11,6 ), /*  I2C1_SCL/PWM1_CH3                    */\
PIN(A,10,7 ), /*  I2C1_SDA/PWM1_CH2                    */\
PIN(A, 9,8 ), /*  I2C0_SCL/UART1_nCTS                  */\
PIN(A, 8,9 ), /*  I2C0_SDA/UART1_nRTS                  */\
PIN(B, 4,10), /*  UART1_RXD                            */\
PIN(B, 5,11), /*  UART1_TXD                            */\
PIN(B, 6,12), /*  UART1_nRTS                           */\
PIN(B, 7,13), /*  UART1_nCTS                           */\
      /* 14       DO_CAP                               */\
      /* 15       DD                                   */\
      /* 16       SS                                   */\
PIN(B, 0,17), /*  UART0_RXD                            */\
PIN(B, 1,18), /*  UART0_TXD                            */\
PIN(B, 2,19), /*  UART0_nRTS/TM2_EXT/PWM1_BRAKE1/TM2   */\
PIN(B, 3,20), /*  UART0_nCTS/TM3_EXT/PWM1_BRAKE0/TM3   */\
PIN(D, 6,21), /*  BPWM1_CH1                            */\
PIN(D, 7,22), /*  BPWM1_CH0                            */\
PIN(D,14,23), /*  UART2_RXD/BPWM0_CH5                  */\
PIN(D,15,24), /*  UART2_TXD/BPWM0_CH4                  */\
PIN(C, 3,25), /*  SPI0_MOSI0/BPWM0_CH3                 */\
PIN(C, 2,26), /*  SPI0_MISO0/BPWM0_CH2                 */\
PIN(C, 1,27), /*  SPI0_CLK/BPWM0_CH1                   */\
PIN(C, 0,28), /*  SPI0_SS0/BPWM0_CH0                   */\
PIN(E, 5,29), /*  PWM0_CH5/TM1/TM1_EXT                 */\
PIN(B,11,30), /*  TM3/PWM0_CH4                         */\
PIN(B,10,31), /*  TM2                                  */\
PIN(B, 9,32), /*  TM1                                  */\
PIN(C,11,33), /*  PWM1_BRAKE1                          */\
PIN(C,10,34), /*  PWM1_BRAKE0                          */\
PIN(C, 9,35), /*  PWM0_BRAKE1                          */\
PIN(C, 8,36), /*  PWM0_BRAKE0                          */\
PIN(A,15,37), /*  PWM0_CH3                             */\
PIN(A,14,38), /*  PWM0_CH2                             */\
PIN(A,13,39), /*  PWM0_CH1/UART5_TXD                   */\
PIN(A,12,40), /*  PWM0_CH0/UART5_RXD                   */\
/* (F, 7,41),   ICE_DAT                                */\
/* (F, 6,42),   ICE_CLK                                */\
      /* 43       AVSS                                 */\
PIN(A, 0,44), /*  ADC_CH0/I2C1_SCL/UART5_TXD/PWM0_CH4  */\
PIN(A, 1,45), /*  ADC_CH1/I2C1_SDA/UART5_RXD/PWM0_CH5  */\
PIN(A, 2,46), /*  ADC_CH2/UART3_TXD/PWM1_CH0           */\
PIN(A, 3,47), /*  ADC_CH3/UART3_RXD/PWM1_CH1           */\
PIN(A, 4,48), /*  ADC_CH4                              */\
PIN(A, 5,49), /*  ADC_CH5/UART3_RXD                    */\
PIN(A, 6,50), /*  ADC_CH6/UART3_TXD                    */\
PIN(A, 7,51), /*  ADC_CH7/VREF                         */\
      /* 52       AVDD                                 */\
PIN(C, 7,53), /*  UART4_RXD/I2C0_SCL/PWM0_BRAKE1       */\
PIN(C, 6,54), /*  UART4_TXD/I2C0_SDA/PWM0_BRAKE0       */\
PIN(C,15,55), /*                                       */\
PIN(C,14,56), /*                                       */\
PIN(B,15,57), /*  INT1/TM0/TM0_EXT/BPWM1_CH5           */\
      /* 58       XT1_OUT/PF.0                         */\
      /* 59       XT1_IN/PF.1                          */\
      /* 60       nRESET                               */\
      /* 61       VSS                                  */\
      /* 62       VDD                                  */\
PIN(F, 8,63), /*  CLKO/BPWM1_CH4                       */\
PIN(B, 8,64)  /*  TM0/STADC/CLKO/BPWM1_CH2             */

#else /*used ICE*/

#define CHIP_PIN_LIST \
PIN(B,14,1 ), /*  INT0                                 */\
PIN(B,13,2 ), /*                                       */\
PIN(B,12,3 ), /*  CLKO/BPWM1_CH3                       */\
PIN(F, 5,4 ), /*  I2C0_SCL/PWM1_CH5                    */\
PIN(F, 4,5 ), /*  I2C0_SDA/PWM1_CH4                    */\
PIN(A,11,6 ), /*  I2C1_SCL/PWM1_CH3                    */\
PIN(A,10,7 ), /*  I2C1_SDA/PWM1_CH2                    */\
PIN(A, 9,8 ), /*  I2C0_SCL/UART1_nCTS                  */\
PIN(A, 8,9 ), /*  I2C0_SDA/UART1_nRTS                  */\
PIN(B, 4,10), /*  UART1_RXD                            */\
PIN(B, 5,11), /*  UART1_TXD                            */\
PIN(B, 6,12), /*  UART1_nRTS                           */\
PIN(B, 7,13), /*  UART1_nCTS                           */\
      /* 14       DO_CAP                               */\
      /* 15       DD                                   */\
      /* 16       SS                                   */\
PIN(B, 0,17), /*  UART0_RXD                            */\
PIN(B, 1,18), /*  UART0_TXD                            */\
PIN(B, 2,19), /*  UART0_nRTS/TM2_EXT/PWM1_BRAKE1/TM2   */\
PIN(B, 3,20), /*  UART0_nCTS/TM3_EXT/PWM1_BRAKE0/TM3   */\
PIN(D, 6,21), /*  BPWM1_CH1                            */\
PIN(D, 7,22), /*  BPWM1_CH0                            */\
PIN(D,14,23), /*  UART2_RXD/BPWM0_CH5                  */\
PIN(D,15,24), /*  UART2_TXD/BPWM0_CH4                  */\
PIN(C, 3,25), /*  SPI0_MOSI0/BPWM0_CH3                 */\
PIN(C, 2,26), /*  SPI0_MISO0/BPWM0_CH2                 */\
PIN(C, 1,27), /*  SPI0_CLK/BPWM0_CH1                   */\
PIN(C, 0,28), /*  SPI0_SS0/BPWM0_CH0                   */\
PIN(E, 5,29), /*  PWM0_CH5/TM1/TM1_EXT                 */\
PIN(B,11,30), /*  TM3/PWM0_CH4                         */\
PIN(B,10,31), /*  TM2                                  */\
PIN(B, 9,32), /*  TM1                                  */\
PIN(C,11,33), /*  PWM1_BRAKE1                          */\
PIN(C,10,34), /*  PWM1_BRAKE0                          */\
PIN(C, 9,35), /*  PWM0_BRAKE1                          */\
PIN(C, 8,36), /*  PWM0_BRAKE0                          */\
PIN(A,15,37), /*  PWM0_CH3                             */\
PIN(A,14,38), /*  PWM0_CH2                             */\
PIN(A,13,39), /*  PWM0_CH1/UART5_TXD                   */\
PIN(A,12,40), /*  PWM0_CH0/UART5_RXD                   */\
PIN(F, 7,41), /*  ICE_DAT                              */\
PIN(F, 6,42), /*  ICE_CLK                              */\
      /* 43       AVSS                                 */\
PIN(A, 0,44), /*  ADC_CH0/I2C1_SCL/UART5_TXD/PWM0_CH4  */\
PIN(A, 1,45), /*  ADC_CH1/I2C1_SDA/UART5_RXD/PWM0_CH5  */\
PIN(A, 2,46), /*  ADC_CH2/UART3_TXD/PWM1_CH0           */\
PIN(A, 3,47), /*  ADC_CH3/UART3_RXD/PWM1_CH1           */\
PIN(A, 4,48), /*  ADC_CH4                              */\
PIN(A, 5,49), /*  ADC_CH5/UART3_RXD                    */\
PIN(A, 6,50), /*  ADC_CH6/UART3_TXD                    */\
PIN(A, 7,51), /*  ADC_CH7/VREF                         */\
      /* 52       AVDD                                 */\
PIN(C, 7,53), /*  UART4_RXD/I2C0_SCL/PWM0_BRAKE1       */\
PIN(C, 6,54), /*  UART4_TXD/I2C0_SDA/PWM0_BRAKE0       */\
PIN(C,15,55), /*                                       */\
PIN(C,14,56), /*                                       */\
PIN(B,15,57), /*  INT1/TM0/TM0_EXT/BPWM1_CH5           */\
      /* 58       XT1_OUT/PF.0                         */\
      /* 59       XT1_IN/PF.1                          */\
      /* 60       nRESET                               */\
      /* 61       VSS                                  */\
      /* 62       VDD                                  */\
PIN(F, 8,63), /*  CLKO/BPWM1_CH4                       */\
PIN(B, 8,64)  /*  TM0/STADC/CLKO/BPWM1_CH2             */

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