/****************************************************************************
 * @file     M0516LDE.csv
 * @version  V1.13
 * @Date     2018/10/19-12:10:43 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2018 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef _CHIP48_PINLIST_H_
#define _CHIP48_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
  PIN(1,5,1 ), /* /AIN5/MOSI_0/ACMP0_P    */\
  PIN(1,6,2 ), /* /AIN6/MISO_0/ACMP2_N    */\
  PIN(1,7,3 ), /* /AIN7/SPICLK0/ACMP2_P   */\
       /* 4      nRST                     */\
  PIN(3,0,5 ), /* /RXD/ACMP1_N            */\
       /* 6 ),     AVSS                   */\
  PIN(3,1,7 ), /* /TXD/ACMP1_P            */\
  PIN(3,2,8 ), /* /nINT0/T0EX/STADC       */\
  PIN(3,3,9 ), /* /nINT1/MCLK/T1EX        */\
  PIN(3,4,10), /* /T0/SDA0                */\
  PIN(3,5,11), /* /T1/SCL0/CKO            */\
  PIN(4,3,12), /* /PWM3                   */\
  PIN(3,6,13), /* /nWR/CKO/ACMP0_O        */\
  PIN(3,7,14), /* /nRD                    */\
       /* 15      XTAL2                   */\
       /* 16      XTAL1                   */\
       /* 17      VSS                     */\
       /* 18      LDO_CAP                 */\
  PIN(2,0,19), /* /AD8/PWM0               */\
  PIN(2,1,20), /* /AD9/PWM1               */\
  PIN(2,2,21), /* /AD10/PWM2              */\
  PIN(2,3,22), /* /AD11/PWM3              */\
  PIN(2,4,23), /* /AD12/SCL1              */\
  PIN(4,0,24), /* /PWM0/T2EX              */\
  PIN(2,5,25), /* /AD13/PWM5/SDA1         */\
  PIN(2,6,26), /* /AD14/PWM6/ACMP1_O      */\
  PIN(2,7,27), /* /AD15/PWM7              */\
  PIN(4,4,28), /* /nCS/SCL1               */\
  PIN(4,5,29), /* /ALE/SDA1               */\
  /*PIN(4,6,30),  /ICE_CLK                */\
  /*PIN(4,7,31),  /ICE_DAT                */\
  PIN(0,7,32), /* /AD7/SPICLK1            */\
  PIN(0,6,33), /* /AD6/MISO_1             */\
  PIN(0,5,34), /* /AD5/MOSI_1             */\
  PIN(0,4,35), /* /AD4/SPISS1             */\
  PIN(4,1,36), /* /PWM1/T3EX              */\
  PIN(0,3,37), /* /AD3/RTS0/RXD           */\
  PIN(0,2,38), /* /AD2/CTS0/TXD           */\
  PIN(0,1,39), /* /AD1/RTS1/RXD1/ACMP3_N  */\
  PIN(0,0,40), /* /AD0/CTS1/TXD1/ACMP3_P  */\
       /* 41      VDD                     */\
       /* 42      AVDD                    */\
  PIN(1,0,43), /* /AIN0/T2/nWRL           */\
  PIN(1,1,44), /* /AIN1/T3/nWRH           */\
  PIN(1,2,45), /* /AIN2/RXD1              */\
  PIN(1,3,46), /* /AIN3/TXD1              */\
  PIN(1,4,47), /* /AIN4/SPISS0/ACMP0_N    */\
  PIN(4,2,48)  /* /PWM2                   */

#else /*used ICE*/
  #define CHIP_PIN_LIST \
  PIN(1,5,1 ), /* /AIN5/MOSI_0/ACMP0_P    */\
  PIN(1,6,2 ), /* /AIN6/MISO_0/ACMP2_N    */\
  PIN(1,7,3 ), /* /AIN7/SPICLK0/ACMP2_P   */\
       /* 4      nRST                     */\
  PIN(3,0,5 ), /* /RXD/ACMP1_N            */\
       /* 6 ),     AVSS                   */\
  PIN(3,1,7 ), /* /TXD/ACMP1_P            */\
  PIN(3,2,8 ), /* /nINT0/T0EX/STADC       */\
  PIN(3,3,9 ), /* /nINT1/MCLK/T1EX        */\
  PIN(3,4,10), /* /T0/SDA0                */\
  PIN(3,5,11), /* /T1/SCL0/CKO            */\
  PIN(4,3,12), /* /PWM3                   */\
  PIN(3,6,13), /* /nWR/CKO/ACMP0_O        */\
  PIN(3,7,14), /* /nRD                    */\
       /* 15      XTAL2                   */\
       /* 16      XTAL1                   */\
       /* 17      VSS                     */\
       /* 18      LDO_CAP                 */\
  PIN(2,0,19), /* /AD8/PWM0               */\
  PIN(2,1,20), /* /AD9/PWM1               */\
  PIN(2,2,21), /* /AD10/PWM2              */\
  PIN(2,3,22), /* /AD11/PWM3              */\
  PIN(2,4,23), /* /AD12/PWM4/SCL1         */\
  PIN(4,0,24), /* /PWM0/T2EX              */\
  PIN(2,5,25), /* /AD13/PWM5/SDA1         */\
  PIN(2,6,26), /* /AD14/PWM6/ACMP1_O      */\
  PIN(2,7,27), /* /AD15/PWM7              */\
  PIN(4,4,28), /* /nCS/SCL1               */\
  PIN(4,5,29), /* /ALE/SDA1               */\
  PIN(4,6,30), /* /ICE_CLK                */\
  PIN(4,7,31), /* /ICE_DAT                */\
  PIN(0,7,32), /* /AD7/SPICLK1            */\
  PIN(0,6,33), /* /AD6/MISO_1             */\
  PIN(0,5,34), /* /AD5/MOSI_1             */\
  PIN(0,4,35), /* /AD4/SPISS1             */\
  PIN(4,1,36), /* /PWM1/T3EX              */\
  PIN(0,3,37), /* /AD3/RTS0/RXD           */\
  PIN(0,2,38), /* /AD2/CTS0/TXD           */\
  PIN(0,1,39), /* /AD1/RTS1/RXD1/ACMP3_N  */\
  PIN(0,0,40), /* /AD0/CTS1/TXD1/ACMP3_P  */\
       /* 41      VDD                     */\
       /* 42      AVDD                    */\
  PIN(1,0,43), /* /AIN0/T2/nWRL           */\
  PIN(1,1,44), /* /AIN1/T3/nWRH           */\
  PIN(1,2,45), /* /AIN2/RXD1              */\
  PIN(1,3,46), /* /AIN3/TXD1              */\
  PIN(1,4,47), /* /AIN4/SPISS0/ACMP0_N    */\
  PIN(4,2,48)  /* /PWM2                   */

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

