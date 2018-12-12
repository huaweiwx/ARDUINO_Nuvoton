/****************************************************************************
 * @file     NANO130SE3BN(LQFP64)
 * @version  V1.00
 * @Date     2018/10/19-20:44:46 
 * @brief    arduino pin descriptions file
 * Copyright (C) 2018 huaweiwx@sina.com.
*****************************************************************************/

#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
  PIN(B,14,1 ), /* INT0/SC2_CD/SPI2_SS1                    */\
  PIN(B,13,2 ), /* EBI_AD1                                 */\
  PIN(B,12,3 ), /* EBI_AD0/FCLKO                           */\
       /*  4 )     X32_OUT                                 */\
       /*  5 )     X32_IN                                  */\
  PIN(A,11,6 ), /* I2C1_SCL/EBI_nRD/SC0_RST/SPI2_MOSI0     */\
  PIN(A,10,7 ), /* I2C1_SDA/EBI_nWR/SC0_PWR/SPI2_MISO0     */\
  PIN(A,9 ,8 ), /* I2C0_SCL/SC0_DAT/SPI2_CLK               */\
  PIN(A,8 ,9 ), /* I2C0_SDA/SC0_CLK/SPI2_SS0               */\
  PIN(B,4 ,10), /* UART1_RXD/SC0_CD/SPI2_SS0               */\
  PIN(B,5 ,11), /* UART1_TXD/SC0_RST/SPI2_CLK              */\
  PIN(B,6 ,12), /* UART1_RTSn/EBI_ALE/SPI2_MISO0           */\
  PIN(B,7 ,13), /* UART1_CTSn/EBI_nCS/SPI2_MOSI0           */\
        /* 14      LDO_CAP                                 */\
        /* 15      VDD                                     */\
        /* 16      VSS                                     */\
        /* 17      USB_VBUS                                */\
        /* 18      USB_VDD33_CAP                           */\
        /* 19      USB_D-                                  */\
        /* 20      USB_D+                                  */\
  PIN(B,0 ,21), /* UART0_RXD/SPI1_MOSI0                    */\
  PIN(B,1 ,22), /* UART0_TXD/SPI1_MISO0                    */\
  PIN(B,2 ,23), /* UART0_RTSn/EBI_nWRL/SPI1_CLK            */\
  PIN(B,3 ,24), /* UART0_CTSn/EBI_nWRH/SPI1_SS0            */\
  PIN(C,3 ,25), /* SPI0_MOSI0/I2S_DO/SC1_RST               */\
  PIN(C,2 ,26), /* SPI0_MISO0/I2S_DI/SC1_PWR               */\
  PIN(C,1 ,27), /* SPI0_CLK/I2S_BCLK/SC1_DAT               */\
  PIN(C,0 ,28), /* SPI0_SS0/I2S_LRCLK/SC1_CLK              */\
  PIN(E,5 ,29), /* PWM1_CH1                                */\
  PIN(B,11,30), /* PWM1_CH0/TM3/SC2_DAT/SPI0_MISO0         */\
  PIN(B,10,31), /* SPI0_SS1/TM2/SC2_CLK/SPI0_MOSI0         */\
  PIN(B,9 ,32), /* SPI1_SS1/TM1/SC2_RST/INT0               */\
  PIN(C,11,33), /* SPI1_MOSI0/UART1_TXD                    */\
  PIN(C,10,34), /* SPI1_MISO0/UART1_RXD                    */\
  PIN(C,9 ,35), /* SPI1_CLK/I2C1_SCL                       */\
  PIN(C,8 ,36), /* SPI1_SS0/EBI_MCLK/I2C1_SDA              */\
  PIN(A,15,37), /* PWM0_CH3/I2S_MCLK/TC3/SC0_PWR/UART0_TXD */\
  PIN(A,14,38), /* PWM0_CH2/EBI_AD15/TC2/UART0_RXD         */\
  PIN(A,13,39), /* PWM0_CH1/EBI_AD14/TC1/I2C0_SCL          */\
  PIN(A,12,40), /* PWM0_CH0/EBI_AD13/TC0/I2C0_SDA          */\
/*PIN(F,0 ,41),    INT0/ICE_DAT                            */\
/*PIN(F,1 ,42),    FCLKO/INT1/ICE_CLK                      */\
        /* 43      AVSS                                    */\
  PIN(A,0 ,44), /* AD0/SC2_CD                              */\
  PIN(A,1 ,45), /* AD1/EBI_AD12                            */\
  PIN(A,2 ,46), /* AD2/EBI_AD11/UART1_RXD                  */\
  PIN(A,3 ,47), /* AD3/EBI_AD10/UART1_TXD                  */\
  PIN(A,4 ,48), /* AD4/EBI_AD9/SC2_PWR/I2C0_SDA            */\
  PIN(A,5 ,49), /* AD5/EBI_AD8/SC2_RST/I2C0_SCL            */\
  PIN(A,6 ,50), /* AD6/EBI_AD7/TC3/SC2_CLK/PWM0_CH3        */\
      /*   51      VREF                                    */\
      /*   52      AVDD                                    */\
  PIN(C,7 ,53), /* DA1_OUT/EBI_AD5/TC1/PWM0_CH1            */\
  PIN(C,6 ,54), /* DA0_OUT/EBI_AD4/TC0/SC1_CD/PWM0_CH0     */\
  PIN(C,15,55), /* EBI_AD3/TC0/PWM1_CH2                    */\
  PIN(C,14,56), /* EBI_AD2/PWM1_CH3                        */\
  PIN(B,15,57), /* INT1/SNOOPER/SC1_CD                     */\
       /*  58      XT1_IN                                  */\
       /*  59      XT1_OUT                                 */\
       /*  60      nRESET                                  */\
       /*  61      VSS                                     */\
       /*  62      VDD                                     */\
       /*  63      PVSS                                    */\
  PIN(B,8 ,64)  /* STADC/TM0/INT0/SC2_PWR                  */

#else
  #define CHIP_PIN_LIST \
  PIN(B,14,1 ), /* INT0/SC2_CD/SPI2_SS1                    */\
  PIN(B,13,2 ), /* EBI_AD1                                 */\
  PIN(B,12,3 ), /* EBI_AD0/FCLKO                           */\
       /*  4 )     X32_OUT                                 */\
       /*  5 )     X32_IN                                  */\
  PIN(A,11,6 ), /* I2C1_SCL/EBI_nRD/SC0_RST/SPI2_MOSI0     */\
  PIN(A,10,7 ), /* I2C1_SDA/EBI_nWR/SC0_PWR/SPI2_MISO0     */\
  PIN(A,9 ,8 ), /* I2C0_SCL/SC0_DAT/SPI2_CLK               */\
  PIN(A,8 ,9 ), /* I2C0_SDA/SC0_CLK/SPI2_SS0               */\
  PIN(B,4 ,10), /* UART1_RXD/SC0_CD/SPI2_SS0               */\
  PIN(B,5 ,11), /* UART1_TXD/SC0_RST/SPI2_CLK              */\
  PIN(B,6 ,12), /* UART1_RTSn/EBI_ALE/SPI2_MISO0           */\
  PIN(B,7 ,13), /* UART1_CTSn/EBI_nCS/SPI2_MOSI0           */\
        /* 14      LDO_CAP                                 */\
        /* 15      VDD                                     */\
        /* 16      VSS                                     */\
        /* 17      USB_VBUS                                */\
        /* 18      USB_VDD33_CAP                           */\
        /* 19      USB_D-                                  */\
        /* 20      USB_D+                                  */\
  PIN(B,0 ,21), /* UART0_RXD/SPI1_MOSI0                    */\
  PIN(B,1 ,22), /* UART0_TXD/SPI1_MISO0                    */\
  PIN(B,2 ,23), /* UART0_RTSn/EBI_nWRL/SPI1_CLK            */\
  PIN(B,3 ,24), /* UART0_CTSn/EBI_nWRH/SPI1_SS0            */\
  PIN(C,3 ,25), /* SPI0_MOSI0/I2S_DO/SC1_RST               */\
  PIN(C,2 ,26), /* SPI0_MISO0/I2S_DI/SC1_PWR               */\
  PIN(C,1 ,27), /* SPI0_CLK/I2S_BCLK/SC1_DAT               */\
  PIN(C,0 ,28), /* SPI0_SS0/I2S_LRCLK/SC1_CLK              */\
  PIN(E,5 ,29), /* PWM1_CH1                                */\
  PIN(B,11,30), /* PWM1_CH0/TM3/SC2_DAT/SPI0_MISO0         */\
  PIN(B,10,31), /* SPI0_SS1/TM2/SC2_CLK/SPI0_MOSI0         */\
  PIN(B,9 ,32), /* SPI1_SS1/TM1/SC2_RST/INT0               */\
  PIN(C,11,33), /* SPI1_MOSI0/UART1_TXD                    */\
  PIN(C,10,34), /* SPI1_MISO0/UART1_RXD                    */\
  PIN(C,9 ,35), /* SPI1_CLK/I2C1_SCL                       */\
  PIN(C,8 ,36), /* SPI1_SS0/EBI_MCLK/I2C1_SDA              */\
  PIN(A,15,37), /* PWM0_CH3/I2S_MCLK/TC3/SC0_PWR/UART0_TXD */\
  PIN(A,14,38), /* PWM0_CH2/EBI_AD15/TC2/UART0_RXD         */\
  PIN(A,13,39), /* PWM0_CH1/EBI_AD14/TC1/I2C0_SCL          */\
  PIN(A,12,40), /* PWM0_CH0/EBI_AD13/TC0/I2C0_SDA          */\
  PIN(F,0 ,41), /* INT0/ICE_DAT                            */\
  PIN(F,1 ,42), /* FCLKO/INT1/ICE_CLK                      */\
        /* 43      AVSS                                    */\
  PIN(A,0 ,44), /* AD0/SC2_CD                              */\
  PIN(A,1 ,45), /* AD1/EBI_AD12                            */\
  PIN(A,2 ,46), /* AD2/EBI_AD11/UART1_RXD                  */\
  PIN(A,3 ,47), /* AD3/EBI_AD10/UART1_TXD                  */\
  PIN(A,4 ,48), /* AD4/EBI_AD9/SC2_PWR/I2C0_SDA            */\
  PIN(A,5 ,49), /* AD5/EBI_AD8/SC2_RST/I2C0_SCL            */\
  PIN(A,6 ,50), /* AD6/EBI_AD7/TC3/SC2_CLK/PWM0_CH3        */\
      /*   51      VREF                                    */\
      /*   52      AVDD                                    */\
  PIN(C,7 ,53), /* DA1_OUT/EBI_AD5/TC1/PWM0_CH1            */\
  PIN(C,6 ,54), /* DA0_OUT/EBI_AD4/TC0/SC1_CD/PWM0_CH0     */\
  PIN(C,15,55), /* EBI_AD3/TC0/PWM1_CH2                    */\
  PIN(C,14,56), /* EBI_AD2/PWM1_CH3                        */\
  PIN(B,15,57), /* INT1/SNOOPER/SC1_CD                     */\
       /*  58      XT1_IN                                  */\
       /*  59      XT1_OUT                                 */\
       /*  60      nRESET                                  */\
       /*  61      VSS                                     */\
       /*  62      VDD                                     */\
       /*  63      PVSS                                    */\
  PIN(B,8 ,64)  /* STADC/TM0/INT0/SC2_PWR                  */
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

