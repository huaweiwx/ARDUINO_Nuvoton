/****************************************************************************
 * @file     NANO120LE3BN(LQFP48)
 * @version  V1.00
 * @Date     2018/10/19-20:44:46 
 * @brief    arduino pin descriptions file
 * Copyright (C) 2018 huaweiwx@sina.com.
*****************************************************************************/

#ifndef _CHIP48_PINLIST_H_
#define _CHIP48_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
    PIN(B,12,1 ), /* EBI_AD0/FCLKO                          */\
         /*  2       X32_OUT                                */\
         /*  3       X32_IN                                 */\
    PIN(A,11,4 ), /* I2C1_SCL/EBI_nRD/SC0_RST/SPI2_MOSI0    */\
    PIN(A,10,5 ), /* I2C1_SDA/EBI_nWR/SC0_PWR/SPI2_MISO0    */\
    PIN(A,9 ,6 ), /* I2C0_SCL/SC0_DAT/SPI2_CLK              */\
    PIN(A,8 ,7 ), /* I2C0_SDA/SC0_CLK/SPI2_SS0              */\
    PIN(B,4 ,8 ), /* UART1_RXD/SC0_CD/SPI2_SS0              */\
    PIN(B,5 ,9 ), /* UART1_TXD/SC0_RST/SPI2_CLK             */\
         /*  10      LDO_CAP                                */\
         /*  11      VDD                                    */\
         /*  12      VSS                                    */\
         /*  13      USB_VBUS                               */\
         /*  14      USB_VDD33_CAP                          */\
         /*  15      USB_D-                                 */\
         /*  16      USB_D+                                 */\
    PIN(B,0 ,17), /* UART0_RXD/SPI1_MOSI0                   */\
    PIN(B,1 ,18), /* UART0_TXD/SPI1_MISO0                   */\
    PIN(B,2 ,19), /* UART0_RTSn/EBI_nWRL/SPI1_CLK           */\
    PIN(B,3 ,20), /* UART0_CTSn/EBI_nWRH/SPI1_SS0           */\
    PIN(C,3 ,21), /* SPI0_MOSI0/I2S_DO/SC1_RST              */\
    PIN(C,2 ,22), /* SPI0_MISO0/I2S_DI/SC1_PWR              */\
    PIN(C,1 ,23), /* SPI0_CLK/I2S_BCLK/SC1_DAT              */\
    PIN(C,0 ,24), /* SPI0_SS0/I2S_LRCLK/SC1_CLK             */\
    PIN(A,15,25), /* PWM0_CH3/I2S_MCLK/TC3/SC0_PWR/UART0_TXD*/\
    PIN(A,14,26), /* PWM0_CH2/EBI_AD15/TC2/UART0_RXD        */\
    PIN(A,13,27), /* PWM0_CH1/EBI_AD14/TC1/I2C0_SCL         */\
    PIN(A,12,28), /* PWM0_CH0/EBI_AD13/TC0/I2C0_SDA         */\
 /* PIN(F,0 ,29),    INT0/ICE_DAT                           */\
 /* PIN(F,1 ,30),    FCLKO/INT1/ICE_CLK                     */\
         /*  31      AVSS                                   */\
    PIN(A,0 ,32), /* AD0/SC2_CD                             */\
    PIN(A,1 ,33), /* AD1/EBI_AD12                           */\
    PIN(A,2 ,34), /* AD2/EBI_AD11/UART1_RXD                 */\
    PIN(A,3 ,35), /* AD3/EBI_AD10/UART1_TXD                 */\
    PIN(A,4 ,36), /* AD4/EBI_AD9/SC2_PWR/I2C0_SDA           */\
    PIN(A,5 ,37), /* AD5/EBI_AD8/SC2_RST/I2C0_SCL           */\
    PIN(A,6 ,38), /* AD6/EBI_AD7/TC3/SC2_CLK/PWM0_CH3       */\
          /* 39      VREF                                   */\
          /* 40      AVDD                                   */\
    PIN(C,7 ,41), /* DA1_OUT/EBI_AD5/TC1/PWM0_CH1           */\
    PIN(C,6 ,42), /* DA0_OUT/EBI_AD4/TC0/SC1_CD/PWM0_CH0    */\
    PIN(B,15,43), /* INT1/SNOOPER/SC1_CD                    */\
          /* 44      XT1_IN                                 */\
          /* 45      XT1_OUT                                */\
          /* 46      nRESET                                 */\
          /* 47      PVSS                                   */\
    PIN(B,8 ,48)  /* STADC/TM0/INT0/SC2_PWR                 */

#else

  #define CHIP_PIN_LIST \
    PIN(B,12,1 ), /* EBI_AD0/FCLKO                          */\
         /*  2       X32_OUT                                */\
         /*  3       X32_IN                                 */\
    PIN(A,11,4 ), /* I2C1_SCL/EBI_nRD/SC0_RST/SPI2_MOSI0    */\
    PIN(A,10,5 ), /* I2C1_SDA/EBI_nWR/SC0_PWR/SPI2_MISO0    */\
    PIN(A,9 ,6 ), /* I2C0_SCL/SC0_DAT/SPI2_CLK              */\
    PIN(A,8 ,7 ), /* I2C0_SDA/SC0_CLK/SPI2_SS0              */\
    PIN(B,4 ,8 ), /* UART1_RXD/SC0_CD/SPI2_SS0              */\
    PIN(B,5 ,9 ), /* UART1_TXD/SC0_RST/SPI2_CLK             */\
         /*  10      LDO_CAP                                */\
         /*  11      VDD                                    */\
         /*  12      VSS                                    */\
         /*  13      USB_VBUS                               */\
         /*  14      USB_VDD33_CAP                          */\
         /*  15      USB_D-                                 */\
         /*  16      USB_D+                                 */\
    PIN(B,0 ,17),  /* UART0_RXD/SPI1_MOSI0                   */\
    PIN(B,1 ,18), /* UART0_TXD/SPI1_MISO0                   */\
    PIN(B,2 ,19), /* UART0_RTSn/EBI_nWRL/SPI1_CLK           */\
    PIN(B,3 ,20), /* UART0_CTSn/EBI_nWRH/SPI1_SS0           */\
    PIN(C,3 ,21), /* SPI0_MOSI0/I2S_DO/SC1_RST              */\
    PIN(C,2 ,22), /* SPI0_MISO0/I2S_DI/SC1_PWR              */\
    PIN(C,1 ,23), /* SPI0_CLK/I2S_BCLK/SC1_DAT              */\
    PIN(C,0 ,24), /* SPI0_SS0/I2S_LRCLK/SC1_CLK             */\
    PIN(A,15,25), /* PWM0_CH3/I2S_MCLK/TC3/SC0_PWR/UART0_TXD*/\
    PIN(A,14,26), /* PWM0_CH2/EBI_AD15/TC2/UART0_RXD        */\
    PIN(A,13,27), /* PWM0_CH1/EBI_AD14/TC1/I2C0_SCL         */\
    PIN(A,12,28), /* PWM0_CH0/EBI_AD13/TC0/I2C0_SDA         */\
    PIN(F,0 ,29), /* INT0/ICE_DAT                           */\
    PIN(F,1 ,30), /* FCLKO/INT1/ICE_CLK                     */\
         /*  31      AVSS                                   */\
    PIN(A,0 ,32), /* AD0/SC2_CD                             */\
    PIN(A,1 ,33), /* AD1/EBI_AD12                           */\
    PIN(A,2 ,34), /* AD2/EBI_AD11/UART1_RXD                 */\
    PIN(A,3 ,35), /* AD3/EBI_AD10/UART1_TXD                 */\
    PIN(A,4 ,36), /* AD4/EBI_AD9/SC2_PWR/I2C0_SDA           */\
    PIN(A,5 ,37), /* AD5/EBI_AD8/SC2_RST/I2C0_SCL           */\
    PIN(A,6 ,38), /* AD6/EBI_AD7/TC3/SC2_CLK/PWM0_CH3       */\
          /* 39      VREF                                   */\
          /* 40      AVDD                                   */\
    PIN(C,7 ,41), /* DA1_OUT/EBI_AD5/TC1/PWM0_CH1           */\
    PIN(C,6 ,42), /* DA0_OUT/EBI_AD4/TC0/SC1_CD/PWM0_CH0    */\
    PIN(B,15,43), /* INT1/SNOOPER/SC1_CD                    */\
          /* 44      XT1_IN                                 */\
          /* 45      XT1_OUT                                */\
          /* 46      nRESET                                 */\
          /* 47      PVSS                                   */\
    PIN(B,8 ,48)  /* STADC/TM0/INT0/SC2_PWR                 */

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

