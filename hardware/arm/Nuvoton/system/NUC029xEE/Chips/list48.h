/****************************************************************************
 * @file     MCU: NUC029LEE(LQFP48)
 * @version  V1.14
 * @Date     2019/03/29-18:13:38 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2019 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#define CHIP_PIN_LIST \
       /* 1     VBAT                       */\
       /* 2     X32_OUT                    */\
       /* 3     X32_IN                     */\
PIN(A,11, 4), /*I2C1_SCL/nRD               */\
PIN(A,10, 5), /*I2C1_SDA/nWR               */\
PIN(A,9 , 6), /*I2C0_SCL                   */\
PIN(A,8 , 7), /*I2C0_SDA                   */\
PIN(B,4 , 8), /*UART1_RXD                  */\
PIN(B,5 , 9), /*UART1_TXD                  */\
     /*  10      LDO_CAP                   */\
     /*  11      VDD                       */\
     /*  12      VSS                       */\
     /*  13      USB_VBUS                  */\
     /*  14      USB_VDD33_CAP             */\
     /*  15      USB_D-                    */\
     /*  16      USB_D+                    */\
PIN(B,0 ,17), /*UART0_RXD                  */\
PIN(B,1 ,18), /*UART0_TXD                  */\
PIN(B,2 ,19), /*UART0_nRTS/TM2_EXT/TM2/nWRL*/\
PIN(B,3 ,20), /*UART0_nCTS/TM3_EXT/TM3/nWRH*/\
PIN(C,3 ,21), /*SPI0_MOSI0                 */\
PIN(C,2 ,22), /*SPI0_MISO0                 */\
PIN(C,1 ,23), /*SPI0_CLK                   */\
PIN(C,0 ,24), /*SPI0_SS0                   */\
PIN(A,15,25), /*PWM3                       */\
PIN(A,14,26), /*PWM2/AD15                  */\
PIN(A,13,27), /*PWM1/AD14                  */\
PIN(A,12,28), /*PWM0/AD13                  */\
    /*   29     ICE_DAT                    */\
    /*   30     ICE_CLK                    */\
    /*   31     AVSS                       */\
PIN(A,0 ,32), /*ADC0                       */\
PIN(A,1 ,33), /*ADC1/AD12                  */\
PIN(A,2 ,34), /*ADC2/AD11                  */\
PIN(A,3 ,35), /*ADC3/AD10                  */\
PIN(A,4 ,36), /*ADC4/AD9                   */\
PIN(A,5 ,37), /*ADC5/AD8                   */\
PIN(A,6 ,38), /*ADC6/AD7                   */\
   /*    39     VREF                       */\
   /*    40     AVDD                       */\
PIN(C,7 ,41), /*ADC7/AD5                   */\
PIN(C,6 ,42), /*ADC8/AD4                   */\
PIN(B,15,43), /*INT1/TM0/ADC11/TM0_EXT/AD6 */\
PIN(F,0 ,44), /*XT1_OUT                    */\
PIN(F,1 ,45), /*XT1_IN                     */\
  /*     46     nRESET                     */\
  /*     47     VSS                        */\
PIN(B,8 ,48)  /*TM0/STADC/CLKO             */


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