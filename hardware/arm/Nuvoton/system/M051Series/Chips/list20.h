/****************************************************************************
 * @file     M058SFAN(TSSOP20)
 * @version  V1.00
 * @Date     2018/10/19-12:33:59 
 * @brief    arduino pin descriptions file
 * Copyright (C) 2018 huaweiwx@sina.com.
*****************************************************************************/

#ifndef _CHIP20_PINLIST_H_
#define _CHIP20_PINLIST_H_

#if USE_ICE >0
#define CHIP_PIN_LIST \
PIN(1,0, 1), /* /AIN0/T2     */\
PIN(1,4, 2), /* /AIN4/SPISS  */\
      /* 3),  nRST           */\
PIN(3,0, 4), /* /RXD         */\
      /* 5), /* AVSS         */\
PIN(3,1, 6), /* /TXD         */\
PIN(3,4, 7), /* /T0/SDA0     */\
PIN(3,5, 8), /* /T1/SCL0/CKO */\
 /*PIN(7,0, 9), XTAL2/       */\
/*PIN(7,1,10),  XTAL1/       */\
     /* 11),  VSS            */\
     /* 12),  LDO_CAP        */\
PIN(2,3,13), /* /PWM3        */\
/*PIN(4,6,14),  /ICE_CLK     */\
/*PIN(4,7,15),  /ICE_DAT     */\
PIN(0,7,16), /*  /SPICLK      */\
PIN(0,6,17), /* /MISO        */\
PIN(0,5,18) /* /MOSI        */
     /* 19),  VDD          */
     /* 20),  AVDD         */

#else /*used ICE*/

#define CHIP_PIN_LIST \
PIN(1,0, 1), /* /AIN0/T2     */\
PIN(1,4, 2), /* /AIN4/SPISS  */\
      /* 3),  nRST           */\
PIN(3,0, 4), /* /RXD         */\
PIN( , , 5), /* AVSS         */\
PIN(3,1, 6), /* /TXD         */\
PIN(3,4, 7), /* /T0/SDA0     */\
PIN(3,5, 8), /* /T1/SCL0/CKO */\
PIN(7,0, 9), /* XTAL2/       */\
PIN(7,1,10), /* XTAL1/       */\
     /* 11),  VSS            */\
     /* 12),  LDO_CAP        */\
PIN(2,3,13), /* /PWM3        */\
PIN(4,6,14), /* /ICE_CLK     */\
PIN(4,7,15), /* /ICE_DAT     */\
PIN(0,7,16), /* /SPICLK      */\
PIN(0,6,17), /* /MISO        */\
PIN(0,5,18) /* /MOSI        */
     /* 19),  VDD          */
     /* 20),  AVDD         */

#endif

#define   SS_PIN   P1_4
#define MOSI_PIN   P1_5
#define MISO_PIN   P1_6
#define  SCK_PIN   P1_7

#define  SDA_PIN  P3_4
#define  SCL_PIN  P3_5

static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;

#endif
