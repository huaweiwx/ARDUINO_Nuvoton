/****************************************************************************
 * @file     M058(LQFP64)
 * @version  V1.13
 * @Date     2018/10/19-12:33:47 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2018 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#if USE_ICE >0
#define CHIP_PIN_LIST \
PIN(1,5,1 ), /* /AIN5/MOSI        */\
PIN(1,6,2 ), /* /AIN6/MISO        */\
PIN(1,7,3 ), /* /AIN7/SPICLK      */\
     /* 4       nRST              */\
PIN(3,0,5 ), /* /RXD              */\
      /*6 ),    AVSS              */\
PIN(5,1,7 ), /* /T1EX             */\
PIN(5,2,8 ), /* /SDA0             */\
PIN(5,3,9 ), /* /SCL0             */\
PIN(3,1,10), /* /TXD              */\
PIN(3,2,11), /* /nINT0/T0EX/STADC */\
PIN(3,3,12), /* /nINT1/T1EX       */\
PIN(3,4,13), /* /T0/SDA0          */\
PIN(3,5,14), /* /T1/SCL0/CKO      */\
PIN(4,3,15), /* /PWM3             */\
PIN(3,6,16), /* /CKO              */\
PIN(3,7,17), /*                   */\
PIN(7,0,18), /* /XTAL2            */\
PIN(7,1,19), /* /XTAL1            */\
      /*20       VSS              */\
      /*21       VDD              */\
      /*22       LDO_CAP          */\
PIN(5,4,23), /*                   */\
PIN(5,5,24), /*                   */\
PIN(5,6,25), /*                   */\
PIN(5,7,26), /*                   */\
PIN(2,0,27), /* /PWM0             */\
PIN(2,1,28), /* /PWM1             */\
PIN(2,2,29), /* /PWM2             */\
PIN(2,3,30), /* /PWM3             */\
PIN(2,4,31), /*                   */\
PIN(4,0,32), /* /PWM0/T2EX        */\
PIN(2,5,33), /*                   */\
PIN(2,6,34), /*                   */\
PIN(2,7,35), /*                   */\
PIN(4,4,36), /* /SCL1             */\
PIN(4,5,37), /* /SDA1             */\
/* PIN(4,6,38), /ICE_CLK          */\
/* PIN(4,7,39), /ICE_DAT          */\
PIN(6,0,40), /*                   */\
PIN(6,1,41), /*                   */\
PIN(6,2,42), /*                   */\
PIN(6,3,43), /*                   */\
PIN(0,7,44), /* /SPICLK           */\
PIN(0,6,45), /* /MISO             */\
PIN(0,5,46), /* /MOSI             */\
PIN(0,4,47), /* /SPISS            */\
PIN(4,1,48), /* /PWM1/T3EX        */\
PIN(0,3,49), /* /RTS0/RXD         */\
PIN(0,2,50), /* /CTS0/TXD         */\
PIN(0,1,51), /*                   */\
PIN(0,0,52), /*                   */\
      /*53       VSS              */\
      /*54       VDD              */\
      /*55       AVDD             */\
      /*56       Vref             */\
PIN(6,6,57), /*                   */\
PIN(6,7,58), /*                   */\
PIN(1,0,59), /* /AIN0/T2          */\
PIN(1,1,60), /* /AIN1/T3          */\
PIN(1,2,61), /* /AIN2             */\
PIN(1,3,62), /* /AIN3             */\
PIN(1,4,63), /* /AIN4/SPISS       */\
PIN(4,2,64)  /* /PWM2             */

#else
#define CHIP_PIN_LIST \
PIN(1,5,1 ), /* /AIN5/MOSI        */\
PIN(1,6,2 ), /* /AIN6/MISO        */\
PIN(1,7,3 ), /* /AIN7/SPICLK      */\
     /* 4       nRST              */\
PIN(3,0,5 ), /* /RXD              */\
      /*6       AVSS              */\
PIN(5,1,7 ), /* /T1EX             */\
PIN(5,2,8 ), /* /SDA0             */\
PIN(5,3,9 ), /* /SCL0             */\
PIN(3,1,10), /* /TXD              */\
PIN(3,2,11), /* /nINT0/T0EX/STADC */\
PIN(3,3,12), /* /nINT1/T1EX       */\
PIN(3,4,13), /* /T0/SDA0          */\
PIN(3,5,14), /* /T1/SCL0/CKO      */\
PIN(4,3,15), /* /PWM3             */\
PIN(3,6,16), /* /CKO              */\
PIN(3,7,17), /*                   */\
PIN(7,0,18), /* /XTAL2            */\
PIN(7,1,19), /* /XTAL1            */\
      /*20       VSS              */\
      /*21       VDD              */\
      /*22       LDO_CAP          */\
PIN(5,4,23), /*                   */\
PIN(5,5,24), /*                   */\
PIN(5,6,25), /*                   */\
PIN(5,7,26), /*                   */\
PIN(2,0,27), /* /PWM0             */\
PIN(2,1,28), /* /PWM1             */\
PIN(2,2,29), /* /PWM2             */\
PIN(2,3,30), /* /PWM3             */\
PIN(2,4,31), /*                   */\
PIN(4,0,32), /* /PWM0/T2EX        */\
PIN(2,5,33), /*                   */\
PIN(2,6,34), /*                   */\
PIN(2,7,35), /*                   */\
PIN(4,4,36), /* /SCL1             */\
PIN(4,5,37), /* /SDA1             */\
PIN(4,6,38), /* /ICE_CLK          */\
PIN(4,7,39), /* /ICE_DAT          */\
PIN(6,0,40), /*                   */\
PIN(6,1,41), /*                   */\
PIN(6,2,42), /*                   */\
PIN(6,3,43), /*                   */\
PIN(0,7,44), /* /SPICLK           */\
PIN(0,6,45), /* /MISO             */\
PIN(0,5,46), /* /MOSI             */\
PIN(0,4,47), /* /SPISS            */\
PIN(4,1,48), /* /PWM1/T3EX        */\
PIN(0,3,49), /* /RTS0/RXD         */\
PIN(0,2,50), /* /CTS0/TXD         */\
PIN(0,1,51), /*                   */\
PIN(0,0,52), /*                   */\
      /*53       VSS              */\
      /*54       VDD              */\
      /*55       AVDD             */\
      /*56       Vref             */\
PIN(6,6,57), /*                   */\
PIN(6,7,58), /*                   */\
PIN(1,0,59), /* /AIN0/T2          */\
PIN(1,1,60), /* /AIN1/T3          */\
PIN(1,2,61), /* /AIN2             */\
PIN(1,3,62), /* /AIN3             */\
PIN(1,4,63), /* /AIN4/SPISS       */\
PIN(4,2,64)  /* /PWM2             */

#endif


#define   SS_PIN   P1_4
#define MOSI_PIN   P1_5
#define MISO_PIN   P1_6
#define  SCK_PIN   P1_7

#define  SDA_PIN   P3_4
#define  SCL_PIN   P3_5


static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;

/*** (C) COPYRIGHT 2013-2018 Nuvoton Technology Corp. ***/