/****************************************************************************
 * @file     M451(LQFP48)
 * @version  V1.13
 * @Date     2018/10/19-12:23:34 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2018 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef _CHIP48_PINLIST_H_
#define _CHIP48_PINLIST_H_

#if USE_ICE >0
#define CHIP_PIN_LIST \
  PIN(B,5 ,1 ),  /* EADC_CH13/SPI0_MOSI0/SPI1_MOSI/ACMP0_P2/EBI_AD6                 */\
  PIN(B,6 ,2 ),  /* EADC_CH14/SPI0_MISO0/SPI1_MISO/ACMP0_P1/EBI_AD5                 */\
  PIN(B,7 ,3 ),  /* EADC_CH15/SPI0_CLK/SPI1_CLK/ACMP0_P0/EBI_AD4                    */\
  /* IN(   4 ),   nRESET                                                          */\
  PIN(D,0 ,5 ),  /* SPI1_I2SMCLK/UART0_RXD/ACMP1_N/INT3                             */\
  /* IN(   6 ),   AVSS                                                            */\
  PIN(D,1 ,7 ),  /* PWM0_SYNC_IN/UART0_TXD/ACMP1_P2/T0/EBI_nRD                      */\
  PIN(D,2 ,8 ),  /* STADC/T0_EXT/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                  */\
  PIN(D,3 ,9 ),  /* T2/T1_EXT/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1                    */\
  /* IN(   10),   VBAT                                                            */\
  PIN(F,0 ,11),  /* X32_OUT/INT5                                                    */\
  PIN(F,1 ,12),  /* X32_IN                                                          */\
  PIN(F,2 ,13),  /* TAMPER                                                          */\
  PIN(D,7 ,14),  /* PWM0_SYNC_IN/T1/ACMP0_O/PWM0_CH5/EBI_nRD                        */\
  PIN(F,3 ,15),  /* XT1_OUT/I2C1_SCL                                                */\
  PIN(F,4 ,16),  /* XT1_IN/I2C1_SDA                                                 */\
  /* IN(   17),   VSS                                                             */\
  /* IN(   18),   LDO_CAP                                                         */\
  PIN(C,0 ,19),  /* SPI2_CLK/UART2_nCTS/PWM0_CH0/EBI_AD8/INT2                       */\
  PIN(C,1 ,20),  /* CLKO/STDAC/UART2_nRTS/PWM0_CH1/EBI_AD9                          */\
  PIN(C,2 ,21),  /* SPI2_SS/UART2_TXD/ACMP1_O/PWM0_CH2/EBI_AD10                     */\
  PIN(C,3 ,22),  /* SPI2_MOSI/UART2_RXD/PWM0_CH3/EBI_AD11                           */\
  PIN(C,4 ,23),  /* SPI2_MISO/I2C1_SCL/PWM0_CH4/EBI_AD12                            */\
  PIN(E,0 ,24),  /* SPI2_CLK/I2C1_SDA/T2_EXT/SC0_CD/PWM0_CH0/EBI_nCS1/INT4          */\
  PIN(C,5 ,25),  /* SPI2_I2SMCLK/PWM0_CH5/EBI_AD13                                  */\
  PIN(C,6 ,26),  /* I2C1_SMBAL/ACMP1_O/PWM1_CH0/EBI_AD14                            */\
  PIN(C,7 ,27),  /* I2C1_SMBSUS/PWM1_CH1/EBI_AD15                                   */\
/*PIN(F,5 ,28),     ICE_CLK                                                         */\
/*PIN(F,6 ,29),     ICE_DAT                                                         */\
  PIN(E,8 ,30),  /* UART1_TXD/SPI0_MISO1/I2C1_SCL/SC0_PWR                           */\
  PIN(E,9 ,31),  /* UART1_RXD/SPI0_MOSI1/I2C1_SDA/SC0_RST                           */\
  PIN(E,10,32),  /* SPI1_MISO/SPI0_MISO0/UART1_nCTS/I2C0_SMBAL/SC0_DAT              */\
  PIN(E,11,33),  /* SPI1_MOSI/SPI0_MOSI0/UART1_nRTS/I2C0_SMBSUS/SC0_CLK             */\
  PIN(E,12,34),  /* SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL                              */\
  PIN(E,13,35),  /* SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA                            */\
  /* IN(   36),   VDDIO                                                           */\
  PIN(A,3 ,37),  /* UART0_RXD/UART0_nRTS/I2C0_SCL/SC0_PWR/PWM1_CH2/EBI_AD3          */\
  PIN(A,2 ,38),  /* UART0_TXD/UART0_nCTS/I2C0_SDA/SC0_RST/PWM1_CH3/EBI_AD2          */\
  PIN(A,1 ,39),  /* UART1_nRTS/UART1_RXD/SC0_DAT/PWM1_CH4/EBI_AD1                   */\
  PIN(A,0 ,40),  /* UART1_nCTS/UART1_TXD/SC0_CLK/PWM1_CH5/EBI_AD0/INT0              */\
  /* IN(   41),   VDD                                                             */\
  /* IN(   42),   AVDD                                                            */\
  /* IN(   43),   VREF                                                            */\
  PIN(B,0 ,44),  /* EADC_CH0/SPI0_MOSI1/UART2_RXD/T2/DAC/EBI_nWRL/INT1              */\
  PIN(B,1 ,45),  /* EADC_CH1/SPI0_MISO1/UART2_TXD/T3/SC0_RST/PWM0_SYNC_OUT/EBI_nWRH */\
  PIN(B,2 ,46),  /* EADC_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/SC0_CD                     */\
  PIN(B,3 ,47),  /* EADC_CH3/SPI0_MISO0/SPI1_MISO/UART1_TXD                         */\
  PIN(B,4 ,48)   /* EADC_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7             */
  
#else
  #define CHIP_PIN_LIST \
  PIN(B,5 ,1 ),  /* EADC_CH13/SPI0_MOSI0/SPI1_MOSI/ACMP0_P2/EBI_AD6                 */\
  PIN(B,6 ,2 ),  /* EADC_CH14/SPI0_MISO0/SPI1_MISO/ACMP0_P1/EBI_AD5                 */\
  PIN(B,7 ,3 ),  /* EADC_CH15/SPI0_CLK/SPI1_CLK/ACMP0_P0/EBI_AD4                    */\
  /* IN( ,  ,4 ),   nRESET                                                          */\
  PIN(D,0 ,5 ),  /* SPI1_I2SMCLK/UART0_RXD/ACMP1_N/INT3                             */\
  /* IN( ,  ,6 ),   AVSS                                                            */\
  PIN(D,1 ,7 ),  /* PWM0_SYNC_IN/UART0_TXD/ACMP1_P2/T0/EBI_nRD                      */\
  PIN(D,2 ,8 ),  /* STADC/T0_EXT/ACMP1_P1/PWM0_BRAKE0/EBI_nWR/INT0                  */\
  PIN(D,3 ,9 ),  /* T2/T1_EXT/ACMP1_P0/PWM0_BRAKE1/EBI_MCLK/INT1                    */\
  /* IN( ,  ,10),   VBAT                                                            */\
  PIN(F,0 ,11),  /* X32_OUT/INT5                                                    */\
  PIN(F,1 ,12),  /* X32_IN                                                          */\
  PIN(F,2 ,13),  /* TAMPER                                                          */\
  PIN(D,7 ,14),  /* PWM0_SYNC_IN/T1/ACMP0_O/PWM0_CH5/EBI_nRD                        */\
  PIN(F,3 ,15),  /* XT1_OUT/I2C1_SCL                                                */\
  PIN(F,4 ,16),  /* XT1_IN/I2C1_SDA                                                 */\
  /* IN( ,  ,17),   VSS                                                             */\
  /* IN( ,  ,18),   LDO_CAP                                                         */\
  PIN(C,0 ,19),  /* SPI2_CLK/UART2_nCTS/PWM0_CH0/EBI_AD8/INT2                       */\
  PIN(C,1 ,20),  /* CLKO/STDAC/UART2_nRTS/PWM0_CH1/EBI_AD9                          */\
  PIN(C,2 ,21),  /* SPI2_SS/UART2_TXD/ACMP1_O/PWM0_CH2/EBI_AD10                     */\
  PIN(C,3 ,22),  /* SPI2_MOSI/UART2_RXD/PWM0_CH3/EBI_AD11                           */\
  PIN(C,4 ,23),  /* SPI2_MISO/I2C1_SCL/PWM0_CH4/EBI_AD12                            */\
  PIN(E,0 ,24),  /* SPI2_CLK/I2C1_SDA/T2_EXT/SC0_CD/PWM0_CH0/EBI_nCS1/INT4          */\
  PIN(C,5 ,25),  /* SPI2_I2SMCLK/PWM0_CH5/EBI_AD13                                  */\
  PIN(C,6 ,26),  /* I2C1_SMBAL/ACMP1_O/PWM1_CH0/EBI_AD14                            */\
  PIN(C,7 ,27),  /* I2C1_SMBSUS/PWM1_CH1/EBI_AD15                                   */\
  PIN(F,5 ,28),  /* ICE_CLK                                                         */\
  PIN(F,6 ,29),  /* ICE_DAT                                                         */\
  PIN(E,8 ,30),  /* UART1_TXD/SPI0_MISO1/I2C1_SCL/SC0_PWR                           */\
  PIN(E,9 ,31),  /* UART1_RXD/SPI0_MOSI1/I2C1_SDA/SC0_RST                           */\
  PIN(E,10,32),  /* SPI1_MISO/SPI0_MISO0/UART1_nCTS/I2C0_SMBAL/SC0_DAT              */\
  PIN(E,11,33),  /* SPI1_MOSI/SPI0_MOSI0/UART1_nRTS/I2C0_SMBSUS/SC0_CLK             */\
  PIN(E,12,34),  /* SPI1_SS/SPI0_SS/UART1_TXD/I2C0_SCL                              */\
  PIN(E,13,35),  /* SPI1_CLK/SPI0_CLK/UART1_RXD/I2C0_SDA                            */\
  /* IN( ,  ,36),   VDDIO                                                           */\
  PIN(A,3 ,37),  /* UART0_RXD/UART0_nRTS/I2C0_SCL/SC0_PWR/PWM1_CH2/EBI_AD3          */\
  PIN(A,2 ,38),  /* UART0_TXD/UART0_nCTS/I2C0_SDA/SC0_RST/PWM1_CH3/EBI_AD2          */\
  PIN(A,1 ,39),  /* UART1_nRTS/UART1_RXD/SC0_DAT/PWM1_CH4/EBI_AD1                   */\
  PIN(A,0 ,40),  /* UART1_nCTS/UART1_TXD/SC0_CLK/PWM1_CH5/EBI_AD0/INT0              */\
  /* IN( ,  ,41),   VDD                                                             */\
  /* IN( ,  ,42),   AVDD                                                            */\
  /* IN( ,  ,43),   VREF                                                            */\
  PIN(B,0 ,44),  /* EADC_CH0/SPI0_MOSI1/UART2_RXD/T2/DAC/EBI_nWRL/INT1              */\
  PIN(B,1 ,45),  /* EADC_CH1/SPI0_MISO1/UART2_TXD/T3/SC0_RST/PWM0_SYNC_OUT/EBI_nWRH */\
  PIN(B,2 ,46),  /* EADC_CH2/SPI0_CLK/SPI1_CLK/UART1_RXD/SC0_CD                     */\
  PIN(B,3 ,47),  /* EADC_CH3/SPI0_MISO0/SPI1_MISO/UART1_TXD                         */\
  PIN(B,4 ,48)   /* EADC_CH4/SPI0_SS/SPI1_SS/UART1_nCTS/ACMP0_N/EBI_AD7             */
#endif

#define SS_PIN   PD_12
#define MOSI_PIN PD_13
#define MISO_PIN PD_14
#define SCK_PIN  PD_15

#define SDA_PIN  PD_4
#define SCL_PIN  PD_5


#define A0   0
#define A1   1
#define A2   2
#define A3   3
#define A4   4
#define A5   5

#endif

