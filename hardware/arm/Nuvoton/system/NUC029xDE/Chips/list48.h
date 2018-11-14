/****************************************************************************
 * @file     NUC029LDE(LQFP48)
 * @version  V1.13
 * @Date     2018/11/10-19:48:47 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2018 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#if USE_ICE >0

#define CHIP_PIN_LIST \
PIN(B,12,1 ), /* CLKO/BPWM1_CH3                      */\
PIN(F, 5,2 ), /* I2C0_SCL/PWM1_CH5                   */\
PIN(F, 4,3 ), /* I2C0_SDA/PWM1_CH4                   */\
PIN(A,11,4 ), /* I2C1_SCL/PWM1_CH3                   */\
PIN(A,10,5 ), /* I2C1_SDA/PWM1_CH2                   */\
PIN(A, 9,6 ), /* I2C0_SCL/UART1_nCTS                 */\
PIN(A, 8,7 ), /* I2C0_SDA/UART1_nRTS                 */\
PIN(B, 4,8 ), /* UART1_RXD                           */\
PIN(B, 5,9 ), /* UART1_TXD                           */\
      /* 10      LDO_CAP                             */\
      /* 11      VDD                                 */\
      /* 12      VSS                                 */\
PIN(B, 0,13), /* UART0_RXD                           */\
PIN(B, 1,14), /* UART0_TXD                           */\
PIN(B, 2,15), /* UART0_nRTS/TM2_EXT/PWM1_BRAKE1/TM2  */\
PIN(B, 3,16), /* UART0_nCTS/TM3_EXT/PWM1_BRAKE0/TM3  */\
PIN(D, 6,17), /* BPWM1_CH1                           */\
PIN(D, 7,18), /* BPWM1_CH0                           */\
PIN(D,14,19), /* UART2_RXD/BPWM0_CH5                 */\
PIN(D,15,20), /* UART2_TXD/BPWM0_CH4                 */\
PIN(C, 3,21), /* SPI0_MOSI0/BPWM0_CH3                */\
PIN(C, 2,22), /* SPI0_MISO0/BPWM0_CH2                */\
PIN(C, 1,23), /* SPI0_CLK/BPWM0_CH1                  */\
PIN(C, 0,24), /* SPI0_SS0/BPWM0_CH0                  */\
PIN(A,15,25), /* PWM0_CH3                            */\
PIN(A,14,26), /* PWM0_CH2                            */\
PIN(A,13,27), /* PWM0_CH1/UART5_TXD                  */\
PIN(A,12,28), /* PWM0_CH0/UART5_RXD                  */\
/* (F, 7,29),    ICE_DAT                             */\
/* (F, 6,30),    ICE_CLK                             */\
      /* 31       AVSS                               */\
PIN(A, 0,32), /* ADC_CH0/I2C1_SCL/UART5_TXD/PWM0_CH4 */\
PIN(A, 1,33), /* ADC_CH1/I2C1_SDA/UART5_RXD/PWM0_CH5 */\
PIN(A, 2,34), /* ADC_CH2/UART3_TXD/PWM1_CH0          */\
PIN(A, 3,35), /* ADC_CH3/UART3_RXD/PWM1_CH1          */\
PIN(A, 4,36), /* ADC_CH4                             */\
PIN(A, 5,37), /* ADC_CH5/UART3_RXD                   */\
PIN(A, 6,38), /* ADC_CH6/UART3_TXD                   */\
PIN(A, 7,39), /* ADC_CH7/VREF                        */\
      /* 40      AVDD                                */\
PIN(C, 7,41), /* UART4_RXD/I2C0_SCL/PWM0_BRAKE1      */\
PIN(C, 6,42), /* UART4_TXD/I2C0_SDA/PWM0_BRAKE0      */\
PIN(B,15,43), /* INT1/TM0/TM0_EXT/BPWM1_CH5          */\
      /* 44      XT1_OUT/PF.0                        */\
      /* 45      XT1_IN/PF.1                         */\
      /* 46      nRESET                              */\
PIN(F,8 ,47), /* CLKO/BPWM1_CH4                      */\
PIN(B,8 ,48)  /* TM0/STADC/CLKO/BPWM1_CH2            */

#else
	
#define CHIP_PIN_LIST \
PIN(B,12,1 ), /* CLKO/BPWM1_CH3                      */\
PIN(F, 5,2 ), /* I2C0_SCL/PWM1_CH5                   */\
PIN(F, 4,3 ), /* I2C0_SDA/PWM1_CH4                   */\
PIN(A,11,4 ), /* I2C1_SCL/PWM1_CH3                   */\
PIN(A,10,5 ), /* I2C1_SDA/PWM1_CH2                   */\
PIN(A, 9,6 ), /* I2C0_SCL/UART1_nCTS                 */\
PIN(A, 8,7 ), /* I2C0_SDA/UART1_nRTS                 */\
PIN(B, 4,8 ), /* UART1_RXD                           */\
PIN(B, 5,9 ), /* UART1_TXD                           */\
      /* 10      LDO_CAP                             */\
      /* 11      VDD                                 */\
      /* 12      VSS                                 */\
PIN(B, 0,13), /* UART0_RXD                           */\
PIN(B, 1,14), /* UART0_TXD                           */\
PIN(B, 2,15), /* UART0_nRTS/TM2_EXT/PWM1_BRAKE1/TM2  */\
PIN(B, 3,16), /* UART0_nCTS/TM3_EXT/PWM1_BRAKE0/TM3  */\
PIN(D, 6,17), /* BPWM1_CH1                           */\
PIN(D, 7,18), /* BPWM1_CH0                           */\
PIN(D,14,19), /* UART2_RXD/BPWM0_CH5                 */\
PIN(D,15,20), /* UART2_TXD/BPWM0_CH4                 */\
PIN(C, 3,21), /* SPI0_MOSI0/BPWM0_CH3                */\
PIN(C, 2,22), /* SPI0_MISO0/BPWM0_CH2                */\
PIN(C, 1,23), /* SPI0_CLK/BPWM0_CH1                  */\
PIN(C, 0,24), /* SPI0_SS0/BPWM0_CH0                  */\
PIN(A,15,25), /* PWM0_CH3                            */\
PIN(A,14,26), /* PWM0_CH2                            */\
PIN(A,13,27), /* PWM0_CH1/UART5_TXD                  */\
PIN(A,12,28), /* PWM0_CH0/UART5_RXD                  */\
PIN(F, 7,29), /* ICE_DAT                             */\
PIN(F, 6,30), /* ICE_CLK                             */\
      /* 31       AVSS                               */\
PIN(A, 0,32), /* ADC_CH0/I2C1_SCL/UART5_TXD/PWM0_CH4 */\
PIN(A, 1,33), /* ADC_CH1/I2C1_SDA/UART5_RXD/PWM0_CH5 */\
PIN(A, 2,34), /* ADC_CH2/UART3_TXD/PWM1_CH0          */\
PIN(A, 3,35), /* ADC_CH3/UART3_RXD/PWM1_CH1          */\
PIN(A, 4,36), /* ADC_CH4                             */\
PIN(A, 5,37), /* ADC_CH5/UART3_RXD                   */\
PIN(A, 6,38), /* ADC_CH6/UART3_TXD                   */\
PIN(A, 7,39), /* ADC_CH7/VREF                        */\
      /* 40      AVDD                                */\
PIN(C, 7,41), /* UART4_RXD/I2C0_SCL/PWM0_BRAKE1      */\
PIN(C, 6,42), /* UART4_TXD/I2C0_SDA/PWM0_BRAKE0      */\
PIN(B,15,43), /* INT1/TM0/TM0_EXT/BPWM1_CH5          */\
      /* 44      XT1_OUT/PF.0                        */\
      /* 45      XT1_IN/PF.1                         */\
      /* 46      nRESET                              */\
PIN(F,8 ,47), /* CLKO/BPWM1_CH4                      */\
PIN(B,8 ,48)  /* TM0/STADC/CLKO/BPWM1_CH2            */

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