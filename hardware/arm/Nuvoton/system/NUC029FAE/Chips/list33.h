/****************************************************************************
 * @file     NUC029TAN(QFN33)
 * @version  V1.13
 * @Date     2018/11/10-19:58:11 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2018 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#if USE_ICE >0

#define CHIP_PIN_LIST \
PIN(1,5,1 ),  /*AIN5/ACMP0_P     */\
	 /* 2       nRST             */\
PIN(3,0,3 ),  /*RXD/ACMP1_N      */\
	/*  4   ,   AVSS             */\
PIN(3,1,5 ),  /*TXD/ACMP1_P      */\
PIN(3,2,6 ),  /*nINT0/T0EX/STADC */\
PIN(3,4,7 ),  /*T0/SDA0          */\
PIN(3,5,8 ),  /*T1/SCL0/CKO      */\
PIN(3,6,9 ),  /*CKO/ACMP0_O      */\
	 /* 10 		XTAL2            */\
	 /* 11 		XTAL1            */\
	 /* 12 		VSS              */\
	 /* 13 		LDO_CAP          */\
PIN(2,2,14),  /*PWM2             */\
PIN(2,3,15),  /*PWM3             */\
PIN(2,4,16),  /*PWM4/SCL1        */\
PIN(2,5,17),  /*PWM5/SDA1        */\
PIN(2,6,18),  /*PWM6/ACMP1_O     */\
/* (4,6,19),  ICE_CLK            */\
/* (4,7,20),  ICE_DAT            */\
PIN(0,7,21),  /*SPICLK1          */\
PIN(0,6,22),  /*MISO_1           */\
PIN(0,5,23),  /*MOSI_1           */\
PIN(0,4,24),  /*SPISS1           */\
PIN(0,1,25),  /*RTS1/RXD1/ACMP3_N*/\
PIN(0,0,26),  /*CTS1/TXD1/ACMP3_P*/\
	/*  27      VDD              */\
	/*  28      AVDD             */\
PIN(1,0,29),  /*AIN0/T2          */\
PIN(1,2,30),  /*AIN2/RXD1        */\
PIN(1,3,31),  /*AIN3/TXD1        */\
PIN(1,4,32)   /*AIN4/ACMP0_N     */

#else
	
#define CHIP_PIN_LIST \
PIN(1,5,1 ),  /*AIN5/ACMP0_P     */\
	 /* 2       nRST             */\
PIN(3,0,3 ),  /*RXD/ACMP1_N      */\
	/*  4   ,   AVSS             */\
PIN(3,1,5 ),  /*TXD/ACMP1_P      */\
PIN(3,2,6 ),  /*nINT0/T0EX/STADC */\
PIN(3,4,7 ),  /*T0/SDA0          */\
PIN(3,5,8 ),  /*T1/SCL0/CKO      */\
PIN(3,6,9 ),  /*CKO/ACMP0_O      */\
	 /* 10 		XTAL2            */\
	 /* 11 		XTAL1            */\
	 /* 12 		VSS              */\
	 /* 13 		LDO_CAP          */\
PIN(2,2,14),  /*PWM2             */\
PIN(2,3,15),  /*PWM3             */\
PIN(2,4,16),  /*PWM4/SCL1        */\
PIN(2,5,17),  /*PWM5/SDA1        */\
PIN(2,6,18),  /*PWM6/ACMP1_O     */\
PIN(4,6,19),  /*ICE_CLK          */\
PIN(4,7,20),  /*ICE_DAT          */\
PIN(0,7,21),  /*SPICLK1          */\
PIN(0,6,22),  /*MISO_1           */\
PIN(0,5,23),  /*MOSI_1           */\
PIN(0,4,24),  /*SPISS1           */\
PIN(0,1,25),  /*RTS1/RXD1/ACMP3_N*/\
PIN(0,0,26),  /*CTS1/TXD1/ACMP3_P*/\
	/*  27      VDD              */\
	/*  28      AVDD             */\
PIN(1,0,29),  /*AIN0/T2          */\
PIN(1,2,30),  /*AIN2/RXD1        */\
PIN(1,3,31),  /*AIN3/TXD1        */\
PIN(1,4,32)   /*AIN4/ACMP0_N     */

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