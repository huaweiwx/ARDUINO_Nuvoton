/****************************************************************************
 * @file     MCU: NUC029FAE(TSSOP20)
 * @version  V1.00
 * @Date     2018/10/19-12:33:59 
 * @brief    arduino pin descriptions file
 * Copyright (C) 2018 huaweiwx@sina.com.
*****************************************************************************/

#ifndef _CHIP20_PINLIST_H_
#define _CHIP20_PINLIST_H_

#if USE_ICE >0
#define CHIP_PIN_LIST \
PIN(1,2,1 ),    /* /AIN2/RXD/ACMP0_P         */\
PIN(1,3,2 ),    /* /AIN3/TXD/ACMP0_P         */\
PIN(1,4,3 ),    /* /AIN4/ACMP0_N             */\
PIN(1,5,4 ),    /* /AIN5/ACMP0_P             */\
     /* 5 ,        nRST                      */\
PIN(3,2,6 ),    /* /nINT0/T0EX/STADC/ACMP1_P */\
PIN(3,4,7 ),    /* /T0/SDA0/ACMP1_P          */\
PIN(3,5,8 ),    /* /T1/SCL0/ACMP1_P          */\
PIN(5,1,9 ),    /* /XTAL2                    */\
PIN(5,0,10),    /* XTAL1                     */\
     /* 11         VSS                       */\
PIN(2,4,12),    /* PWM2                      */\
PIN(2,5,13),    /* PWM3                      */\
     /* 14         ICE_CLK                   */\
     /* 15         ICE_DAT                   */\
PIN(0,7,16),    /* SPICLK0                   */\
PIN(0,6,17),    /* MISO_0                    */\
PIN(0,5,18),    /* MOSI_0                    */\
PIN(0,4,19)     /* SPISS0/PWM5               */\
     /* 20         VDD                       */

#else /*used ICE*/

#define CHIP_PIN_LIST \
PIN(1,2,1 ),    /* /AIN2/RXD/ACMP0_P         */\
PIN(1,3,2 ),    /* /AIN3/TXD/ACMP0_P         */\
PIN(1,4,3 ),    /* /AIN4/ACMP0_N             */\
PIN(1,5,4 ),    /* /AIN5/ACMP0_P             */\
     /* 5 ,        nRST                      */\
PIN(3,2,6 ),    /* /nINT0/T0EX/STADC/ACMP1_P */\
PIN(3,4,7 ),    /* /T0/SDA0/ACMP1_P          */\
PIN(3,5,8 ),    /* /T1/SCL0/ACMP1_P          */\
PIN(5,1,9 ),    /* /XTAL2                    */\
PIN(5,0,10),    /* XTAL1                     */\
     /* 11         VSS                       */\
PIN(2,4,12),    /* PWM2                      */\
PIN(2,5,13),    /* PWM3                      */\
PIN(4,6,14),    /* ICE_CLK                   */\
PIN(4,7,15),    /* ICE_DAT                   */\
PIN(0,7,16),    /* SPICLK0                   */\
PIN(0,6,17),    /* MISO_0                    */\
PIN(0,5,18),    /* MOSI_0                    */\
PIN(0,4,19)     /* SPISS0/PWM5               */\
     /* 20         VDD                       */

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


#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5


#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5


#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5


#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5


#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5


#endif
