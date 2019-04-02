/****************************************************************************
 * @file     NANO120VD3AN(LQFP1100)
 * @version  V1.00
 * @Date     2018/10/19-20:44:46 
 * @brief    arduino pin descriptions file
 * Copyright (C) 2018 huaweiwx@sina.com.
*****************************************************************************/

#ifndef _CHIP100_PINLIST_H_
#define _CHIP100_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
      PIN(E,15  ,1  ), /*                                     */\
      PIN(E,14  ,2  ), /*                                     */\
      PIN(E,13  ,3  ), /*                                     */\
      PIN(B,14  ,4  ), /*nINT0/SPISS21                        */\
      PIN(B,13  ,5  ), /*AD1                                  */\
      PIN(B,12  ,6  ), /*AD0/CLKO                             */\
      /*         7        X32_OUT                             */\
      /*         8        X32_IN                              */\
      PIN(A,11  ,9  ), /*I2C1SCK/nRD/SC0RST/MOSI20            */\
      PIN(A,10  ,10 ), /*I2C1SDA/nWR/SC0PWR/MISO20            */\
      PIN(A,9   ,11 ), /*I2C0SCL/SC0DAT/SPICLK2               */\
      PIN(A,8   ,12 ), /*I2C0SDA/SC0CLK/SPISS20               */\
      PIN(D,8   ,13 ), /*                                     */\
      PIN(D,9   ,14 ), /*                                     */\
      PIN(D,10  ,15 ), /*                                     */\
      PIN(D,11  ,16 ), /*                                     */\
      PIN(D,12  ,17 ), /*                                     */\
      PIN(D,13  ,18 ), /*                                     */\
      PIN(B,4   ,19 ), /*RX1/SC0CD/SPISS20                    */\
      PIN(B,5   ,20 ), /*TX1/SPICLK2                          */\
      PIN(B,6   ,21 ), /*RTSn1/ALE/MISO20                     */\
      PIN(B,7   ,22 ), /*CTSn1/nCS/MOSI20                     */\
      /* 		 23      LDO_CAP                              */\
      /* 		 24      VDD                                  */\
      /* 		 25      VSS                                  */\
      PIN(E,8   ,26 ), /*                                     */\
      PIN(E,7   ,27 ), /*                                     */\
      /*         28      SB_VBUS                              */\
      /*         29      SB_VDD33_CAP                         */\
      /*         30      SB_D-                                */\
      /*         31      SB_D+                                */\
      PIN(B,0   ,32 ), /*RX0/MOSI10                           */\
      PIN(B,1   ,33 ), /*TX0/MISO10                           */\
      PIN(B,2   ,34 ), /*RTSn0/nWRL/SPICLK1                   */\
      PIN(B,3   ,35 ), /*CTSn0/nWRH/SPISS10                   */\
      PIN(D,6   ,36 ), /*                                     */\
      PIN(D,7   ,37 ), /*                                     */\
      PIN(D,14  ,38 ), /*                                     */\
      PIN(D,15  ,39 ), /*                                     */\
      PIN(C,5   ,40 ), /*MOSI01                               */\
      PIN(C,4   ,41 ), /*MISO01                               */\
      PIN(C,3   ,42 ), /*MOSI00/I2SDO/SC1RST                  */\
      PIN(C,2   ,43 ), /*MISO00/I2SDI/SC1PWR                  */\
      PIN(C,1   ,44 ), /*SPICLK0/I2SBCLK/SC1DAT               */\
      PIN(C,0   ,45 ), /*SPISS00/I2SLRCLK/SC1CLK              */\
      PIN(E,6   ,46 ), /*                                     */\
      PIN(E,5   ,47 ), /*PWM1CH1                              */\
      PIN(B,11  ,48 ), /*TMR3/PWM1CH0/MISO00                  */\
      PIN(B,10  ,49 ), /*SPISS01/TMR2/MOSI00                  */\
      PIN(B,9   ,50 ), /*SPISS11/TMR1/nINT0                   */\
      PIN(E,4   ,51 ), /*MOSI00                               */\
      PIN(E,3   ,52 ), /*MISO00                               */\
      PIN(E,2   ,53 ), /*SPICLK0                              */\
      PIN(E,1   ,54 ), /*PWM1CH3/SPISS00                      */\
      PIN(E,0   ,55 ), /*PWM1CH2/I2SMCLK                      */\
      PIN(C,13  ,56 ), /*MOSI11/PWM1CH1/SNOOPER/nINT1/I2C0SCK */\
      PIN(C,12  ,57 ), /*MISO11/PWM1CH0/nINT0/I2C0SDA         */\
      PIN(C,11  ,58 ), /*MOSI10/TX1                           */\
      PIN(C,10  ,59 ), /*MISO10/RX1                           */\
      PIN(C,9   ,60 ), /*SPICLK1/I2C1SCK                      */\
      PIN(C,8   ,61 ), /*SPISS10/MCLK/I2C1SDA                 */\
      PIN(A,15  ,62 ), /*PWM0CH3/I2SMCLK/TC3/TX0              */\
      PIN(A,14  ,63 ), /*PWM0CH2/AD15/TC2/RX0                 */\
      PIN(A,13  ,64 ), /*PWM0CH1/AD14/TC1/I2C0SCK             */\
      PIN(A,12  ,65 ), /*PWM0CH0/AD13/TC0/I2C0SDA             */\
      /*PIN(F,0 ,66 ),   nINT0/ICE_DAT                        */\
      /*PIN(F,1 ,67 ),   CLKO/nINT1/ICE_CK                    */\
      /*         68      VDD                                  */\
      /*         69      VSS                                  */\
      /*         70      AVSS                                 */\
      PIN(A,0   ,71 ), /*ADC0                                 */\
      PIN(A,1   ,72 ), /*ADC1/AD12                            */\
      PIN(A,2   ,73 ), /*ADC2/AD11/RX1                        */\
      PIN(A,3   ,74 ), /*ADC3/AD10/TX1                        */\
      PIN(A,4   ,75 ), /*ADC4/AD9/I2C0SDA                     */\
      PIN(A,5   ,76 ), /*ADC5/AD8/I2C0SCK                     */\
      PIN(A,6   ,77 ), /*ADC6/AD7/TC3/PWM0CH3                 */\
      PIN(A,7   ,78 ), /*ADC7/AD6/TC2/PWM0CH2                 */\
      /*        ,79      VREF                                 */\
      /*        ,80      AVDD                                 */\
      PIN(D,0   ,81 ), /*RX1/SPISS20/SC1CLK                   */\
      PIN(D,1   ,82 ), /*TX1/SPICLK2/SC1DAT                   */\
      PIN(D,2   ,83 ), /*RTSn1/I2SLRCLK/MISO20/SC1PWR         */\
      PIN(D,3   ,84 ), /*CTSn1/I2SBCLK/MOSI20/SC1RST          */\
      PIN(D,4   ,85 ), /*I2SDI/MISO21/SC1CD                   */\
      PIN(D,5   ,86 ), /*I2SDO/MOSI21                         */\
      PIN(C,7   ,87 ), /*AD5/TC1/PWM0CH1                      */\
      PIN(C,6   ,88 ), /*AD4/TC0/SC1CD/PWM0CH0                */\
      PIN(C,15  ,89 ), /*AD3/TC0/PWM1CH2                      */\
      PIN(C,14  ,90 ), /*AD2/PWM1CH3                          */\
      PIN(B,15  ,91 ), /*nINT1/SNOOPER                        */\
      /*         92      XT1_OUT                              */\
      /*         93      XT1_IN                               */\
      /*         94      nRESET                               */\
      /*         95      VSS                                  */\
      /*         96      VDD                                  */\
      PIN(F,4   ,97 ), /*I2C0SDA                              */\
      PIN(F,5   ,98 ), /*I2C0SCK                              */\
      /*         99      PVSS                                 */\
      PIN(B,8   ,100)  /*ADCTRG/TMR0/nINT0                    */

#else /*used ICE*/
  #define CHIP_PIN_LIST \
      PIN(E,15  ,1  ), /*                                     */\
      PIN(E,14  ,2  ), /*                                     */\
      PIN(E,13  ,3  ), /*                                     */\
      PIN(B,14  ,4  ), /*nINT0/SPISS21                        */\
      PIN(B,13  ,5  ), /*AD1                                  */\
      PIN(B,12  ,6  ), /*AD0/CLKO                             */\
      /*         7        X32_OUT                             */\
      /*         8        X32_IN                              */\
      PIN(A,11  ,9  ), /*I2C1SCK/nRD/SC0RST/MOSI20            */\
      PIN(A,10  ,10 ), /*I2C1SDA/nWR/SC0PWR/MISO20            */\
      PIN(A,9   ,11 ), /*I2C0SCL/SC0DAT/SPICLK2               */\
      PIN(A,8   ,12 ), /*I2C0SDA/SC0CLK/SPISS20               */\
      PIN(D,8   ,13 ), /*                                     */\
      PIN(D,9   ,14 ), /*                                     */\
      PIN(D,10  ,15 ), /*                                     */\
      PIN(D,11  ,16 ), /*                                     */\
      PIN(D,12  ,17 ), /*                                     */\
      PIN(D,13  ,18 ), /*                                     */\
      PIN(B,4   ,19 ), /*RX1/SC0CD/SPISS20                    */\
      PIN(B,5   ,20 ), /*TX1/SPICLK2                          */\
      PIN(B,6   ,21 ), /*RTSn1/ALE/MISO20                     */\
      PIN(B,7   ,22 ), /*CTSn1/nCS/MOSI20                     */\
      /* 		 23      LDO_CAP                              */\
      /* 		 24      VDD                                  */\
      /* 		 25      VSS                                  */\
      PIN(E,8   ,26 ), /*                                     */\
      PIN(E,7   ,27 ), /*                                     */\
      /*         28      SB_VBUS                              */\
      /*         29      SB_VDD33_CAP                         */\
      /*         30      SB_D-                                */\
      /*         31      SB_D+                                */\
      PIN(B,0   ,32 ), /*RX0/MOSI10                           */\
      PIN(B,1   ,33 ), /*TX0/MISO10                           */\
      PIN(B,2   ,34 ), /*RTSn0/nWRL/SPICLK1                   */\
      PIN(B,3   ,35 ), /*CTSn0/nWRH/SPISS10                   */\
      PIN(D,6   ,36 ), /*                                     */\
      PIN(D,7   ,37 ), /*                                     */\
      PIN(D,14  ,38 ), /*                                     */\
      PIN(D,15  ,39 ), /*                                     */\
      PIN(C,5   ,40 ), /*MOSI01                               */\
      PIN(C,4   ,41 ), /*MISO01                               */\
      PIN(C,3   ,42 ), /*MOSI00/I2SDO/SC1RST                  */\
      PIN(C,2   ,43 ), /*MISO00/I2SDI/SC1PWR                  */\
      PIN(C,1   ,44 ), /*SPICLK0/I2SBCLK/SC1DAT               */\
      PIN(C,0   ,45 ), /*SPISS00/I2SLRCLK/SC1CLK              */\
      PIN(E,6   ,46 ), /*                                     */\
      PIN(E,5   ,47 ), /*PWM1CH1                              */\
      PIN(B,11  ,48 ), /*TMR3/PWM1CH0/MISO00                  */\
      PIN(B,10  ,49 ), /*SPISS01/TMR2/MOSI00                  */\
      PIN(B,9   ,50 ), /*SPISS11/TMR1/nINT0                   */\
      PIN(E,4   ,51 ), /*MOSI00                               */\
      PIN(E,3   ,52 ), /*MISO00                               */\
      PIN(E,2   ,53 ), /*SPICLK0                              */\
      PIN(E,1   ,54 ), /*PWM1CH3/SPISS00                      */\
      PIN(E,0   ,55 ), /*PWM1CH2/I2SMCLK                      */\
      PIN(C,13  ,56 ), /*MOSI11/PWM1CH1/SNOOPER/nINT1/I2C0SCK */\
      PIN(C,12  ,57 ), /*MISO11/PWM1CH0/nINT0/I2C0SDA         */\
      PIN(C,11  ,58 ), /*MOSI10/TX1                           */\
      PIN(C,10  ,59 ), /*MISO10/RX1                           */\
      PIN(C,9   ,60 ), /*SPICLK1/I2C1SCK                      */\
      PIN(C,8   ,61 ), /*SPISS10/MCLK/I2C1SDA                 */\
      PIN(A,15  ,62 ), /*PWM0CH3/I2SMCLK/TC3/TX0              */\
      PIN(A,14  ,63 ), /*PWM0CH2/AD15/TC2/RX0                 */\
      PIN(A,13  ,64 ), /*PWM0CH1/AD14/TC1/I2C0SCK             */\
      PIN(A,12  ,65 ), /*PWM0CH0/AD13/TC0/I2C0SDA             */\
      PIN(F,0   ,66 ), /*nINT0/ICE_DAT                        */\
      PIN(F,1   ,67 ), /*CLKO/nINT1/ICE_CK                    */\
      /*         68      VDD                                  */\
      /*         69      VSS                                  */\
      /*         70      AVSS                                 */\
      PIN(A,0   ,71 ), /*ADC0                                 */\
      PIN(A,1   ,72 ), /*ADC1/AD12                            */\
      PIN(A,2   ,73 ), /*ADC2/AD11/RX1                        */\
      PIN(A,3   ,74 ), /*ADC3/AD10/TX1                        */\
      PIN(A,4   ,75 ), /*ADC4/AD9/I2C0SDA                     */\
      PIN(A,5   ,76 ), /*ADC5/AD8/I2C0SCK                     */\
      PIN(A,6   ,77 ), /*ADC6/AD7/TC3/PWM0CH3                 */\
      PIN(A,7   ,78 ), /*ADC7/AD6/TC2/PWM0CH2                 */\
      /*        ,79      VREF                                 */\
      /*        ,80      AVDD                                 */\
      PIN(D,0   ,81 ), /*RX1/SPISS20/SC1CLK                   */\
      PIN(D,1   ,82 ), /*TX1/SPICLK2/SC1DAT                   */\
      PIN(D,2   ,83 ), /*RTSn1/I2SLRCLK/MISO20/SC1PWR         */\
      PIN(D,3   ,84 ), /*CTSn1/I2SBCLK/MOSI20/SC1RST          */\
      PIN(D,4   ,85 ), /*I2SDI/MISO21/SC1CD                   */\
      PIN(D,5   ,86 ), /*I2SDO/MOSI21                         */\
      PIN(C,7   ,87 ), /*AD5/TC1/PWM0CH1                      */\
      PIN(C,6   ,88 ), /*AD4/TC0/SC1CD/PWM0CH0                */\
      PIN(C,15  ,89 ), /*AD3/TC0/PWM1CH2                      */\
      PIN(C,14  ,90 ), /*AD2/PWM1CH3                          */\
      PIN(B,15  ,91 ), /*nINT1/SNOOPER                        */\
      /*         92      XT1_OUT                              */\
      /*         93      XT1_IN                               */\
      /*         94      nRESET                               */\
      /*         95      VSS                                  */\
      /*         96      VDD                                  */\
      PIN(F,4   ,97 ), /*I2C0SDA                              */\
      PIN(F,5   ,98 ), /*I2C0SCK                              */\
      /*         99      PVSS                                 */\
      PIN(B,8   ,100)  /*ADCTRG/TMR0/nINT0                    */
#endif

#define MISO_PIN  PE_3
#define MOSI_PIN  PE_4
#define  SCK_PIN  PE_2
#define   SS_PIN  PE_1

#define SDA_PIN   PA_10
#define SCL_PIN   PA_11

#define A0_PIN  0
#define A1_PIN  1
#define A2_PIN  2
#define A3_PIN  3
#define A4_PIN  4
#define A5_PIN  5
#define A6_PIN  6
#define A7_PIN  7
#define A8_PIN  8
#define A9_PIN  9

#endif

