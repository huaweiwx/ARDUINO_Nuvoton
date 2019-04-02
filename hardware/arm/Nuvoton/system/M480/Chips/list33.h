/****************************************************************************
 * @file     M481/2/5ZIDAE(QFN33)
 * @version  V1.00
 * @Date     2018/10/19-20:44:58 
 * @brief    arduino pin descriptions file
 * Copyright (C) 2018 huaweiwx@sina.com.
*****************************************************************************/

#ifndef _CHIP33_PINLIST_H_
#define _CHIP33_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
  PIN(B,5 , 1), /* EADC0_CH5/ACMP1_N/SD0_DAT3/SPI1_MISO/I2C0_SCL/UART5_TXD/USCI1_CTL0/SC0_CLK/I2S0_BCLK/EPWM0_CH0/TM0/INT0                     */\
  PIN(B,4 , 2), /* EADC0_CH4/ACMP1_P1/SD0_DAT2/SPI1_MOSI/I2C0_SDA/UART5_RXD/USCI1_CTL1/SC0_DAT/I2S0_MCLK/EPWM0_CH1/TM1/INT1                    */\
  PIN(B,3 , 3), /* EADC0_CH3/ACMP0_N/SD0_DAT1/SPI1_CLK/UART1_TXD/UART5_nRTS/USCI1_DAT1/SC0_RST/I2S0_DI/EPWM0_CH2/TM2/INT2                      */\
  PIN(B,2 , 4), /* EADC0_CH2/ACMP0_P1/OPA0_O/SD0_DAT0/SPI1_SS/UART1_RXD/UART5_nCTS/USCI1_DAT0/SC0_PWR/I2S0_DO/EPWM0_CH3/TM3/INT3               */\
  PIN(B,1 , 5), /* EADC0_CH1/OPA0_N/SD0_CLK/SPI1_I2SMCLK/SPI3_I2SMCLK/UART2_TXD/USCI1_CLK/I2C1_SCL/I2S0_LRCK/EPWM0_CH4/EPWM1_CH4/EPWM0_BRAKE0  */\
  PIN(B,0 , 6), /* EADC0_CH0/OPA0_P/SD0_CMD/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/EPWM0_CH5/EPWM1_CH5/EPWM0_BRAKE1                                   */\
  PIN(F,5 , 7), /* UART2_RXD/UART2_nCTS/BPWM0_CH4/EPWM0_SYNC_OUT/X32_IN/EADC0_ST                                                               */\
  PIN(F,4 , 8), /* UART2_TXD/UART2_nRTS/BPWM0_CH5/X32_OUT                                                                                      */\
  PIN(F,3 , 9), /* UART0_TXD/I2C0_SCL/XT1_IN/BPWM1_CH0                                                                                         */\
  PIN(F,2 ,10), /* UART0_RXD/I2C0_SDA/QSPI0_CLK/XT1_OUT/BPWM1_CH1                                                                              */\
  PIN(A,3 ,11), /* SPIM_SS/QSPI0_SS/SPI0_SS/SC0_PWR/UART4_TXD/UART1_TXD/I2C1_SCL/BPWM0_CH3/EPWM0_CH2                                           */\
  PIN(A,2 ,12), /* SPIM_CLK/QSPI0_CLK/SPI0_CLK/SC0_RST/UART4_RXD/UART1_RXD/I2C1_SDA/BPWM0_CH2/EPWM0_CH3                                        */\
  PIN(A,1 ,13), /* SPIM_MISO/QSPI0_MISO0/SPI0_MISO/SC0_DAT/UART0_TXD/UART1_nCTS/I2C2_SCL/BPWM0_CH1/EPWM0_CH4/DAC1_ST                           */\
  PIN(A,0 ,14), /* SPIM_MOSI/QSPI0_MOSI0/SPI0_MOSI/SC0_CLK/UART0_RXD/UART1_nRTS/I2C2_SDA/BPWM0_CH0/EPWM0_CH5/DAC0_ST                           */\
        /* 15      VDDIO                                                                                                                       */\
        /* 16      nRESET                                                                                                                       */\
  /*PIN(F,0 ,17),  UART1_TXD/I2C1_SCL/BPWM1_CH0/ICE_DAT                                                                                        */\
  /*PIN(F,1 ,18),  UART1_RXD/I2C1_SDA/BPWM1_CH1/ICE_CLK                                                                                        */\
  PIN(C,1 ,19), /* SPIM_MISO/QSPI0_MISO0/SC1_DAT/I2S0_DO/SPI1_CLK/UART2_TXD/I2C0_SCL/EPWM1_CH4/ACMP0_O                                         */\
  PIN(C,0 ,20), /* SPIM_MOSI/QSPI0_MOSI0/SC1_CLK/I2S0_LRCK/SPI1_SS/UART2_RXD/I2C0_SDA/EPWM1_CH5/ACMP1_O                                        */\
  PIN(A,12,21), /* I2S0_BCLK/UART4_TXD/I2C1_SCL/SPI2_SS/CAN0_TXD/SC2_PWR/BPWM1_CH2/QEI1_INDEX                                                  */\
  PIN(A,13,22), /* I2S0_MCLK/UART4_RXD/I2C1_SDA/SPI2_CLK/CAN0_RXD/SC2_RST/BPWM1_CH3/QEI1_A                                                     */\
  PIN(A,14,23), /* I2S0_DI/UART0_TXD/SPI2_MISO/I2C2_SCL/SC2_DAT/BPWM1_CH4/QEI1_B                                                               */\
  PIN(A,15,24), /* I2S0_DO/UART0_RXD/SPI2_MOSI/I2C2_SDA/SC2_CLK/BPWM1_CH5/EPWM0_SYNC_IN                                                        */\
        /* 25      VSS                                                                                                                         */\
        /* 26      LDO_CAP                                                                                                                     */\
        /* 27      VDD                                                                                                                         */\
  PIN(B,15,28), /* EADC0_CH15/SC1_PWR/SPI0_SS/USCI0_CTL1/UART0_nCTS/UART3_TXD/I2C2_SMBAL/EPWM1_CH0/TM0_EXT                                    */\
  PIN(B,14,29), /* EADC0_CH14/SC1_RST/SPI0_CLK/USCI0_DAT1/UART0_nRTS/UART3_RXD/I2C2_SMBSUS/EPWM1_CH1/TM1_EXT/CLKO                             */\
  PIN(B,13,30), /* EADC0_CH13/DAC1_OUT/ACMP0_P3/ACMP1_P3/SC1_DAT/SPI0_MISO/USCI0_DAT0/UART0_TXD/UART3_nRTS/I2C2_SCL/EPWM1_CH2/TM2_EXT         */\
  PIN(B,12,31)  /* EADC0_CH12/DAC0_OUT/ACMP0_P2/ACMP1_P2/SC1_CLK/SPI0_MOSI/USCI0_CLK/UART0_RXD/UART3_nCTS/I2C2_SDA/SD0_nCD/EPWM1_CH3/TM3_EXT   */
         /*32      AVDD  */
#else /*used ICE*/
  #define CHIP_PIN_LIST \
  PIN(B,5 , 1), /* /EADC0_CH5/ACMP1_N/SD0_DAT3/SPI1_MISO/I2C0_SCL/UART5_TXD/USCI1_CTL0/SC0_CLK/I2S0_BCLK/EPWM0_CH0/TM0/INT0                     */\
  PIN(B,4 , 2), /* /EADC0_CH4/ACMP1_P1/SD0_DAT2/SPI1_MOSI/I2C0_SDA/UART5_RXD/USCI1_CTL1/SC0_DAT/I2S0_MCLK/EPWM0_CH1/TM1/INT1                    */\
  PIN(B,3 , 3), /* /EADC0_CH3/ACMP0_N/SD0_DAT1/SPI1_CLK/UART1_TXD/UART5_nRTS/USCI1_DAT1/SC0_RST/I2S0_DI/EPWM0_CH2/TM2/INT2                      */\
  PIN(B,2 , 4), /* /EADC0_CH2/ACMP0_P1/OPA0_O/SD0_DAT0/SPI1_SS/UART1_RXD/UART5_nCTS/USCI1_DAT0/SC0_PWR/I2S0_DO/EPWM0_CH3/TM3/INT3               */\
  PIN(B,1 , 5), /* /EADC0_CH1/OPA0_N/SD0_CLK/SPI1_I2SMCLK/SPI3_I2SMCLK/UART2_TXD/USCI1_CLK/I2C1_SCL/I2S0_LRCK/EPWM0_CH4/EPWM1_CH4/EPWM0_BRAKE0  */\
  PIN(B,0 , 6), /* /EADC0_CH0/OPA0_P/SD0_CMD/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/EPWM0_CH5/EPWM1_CH5/EPWM0_BRAKE1                                   */\
  PIN(F,5 , 7), /* /UART2_RXD/UART2_nCTS/BPWM0_CH4/EPWM0_SYNC_OUT/X32_IN/EADC0_ST                                                               */\
  PIN(F,4 , 8), /* /UART2_TXD/UART2_nRTS/BPWM0_CH5/X32_OUT                                                                                      */\
  PIN(F,3 , 9), /* /UART0_TXD/I2C0_SCL/XT1_IN/BPWM1_CH0                                                                                         */\
  PIN(F,2 ,10), /* /UART0_RXD/I2C0_SDA/QSPI0_CLK/XT1_OUT/BPWM1_CH1                                                                              */\
  PIN(A,3 ,11), /* /SPIM_SS/QSPI0_SS/SPI0_SS/SC0_PWR/UART4_TXD/UART1_TXD/I2C1_SCL/BPWM0_CH3/EPWM0_CH2                                           */\
  PIN(A,2 ,12), /* /SPIM_CLK/QSPI0_CLK/SPI0_CLK/SC0_RST/UART4_RXD/UART1_RXD/I2C1_SDA/BPWM0_CH2/EPWM0_CH3                                        */\
  PIN(A,1 ,13), /* /SPIM_MISO/QSPI0_MISO0/SPI0_MISO/SC0_DAT/UART0_TXD/UART1_nCTS/I2C2_SCL/BPWM0_CH1/EPWM0_CH4/DAC1_ST                           */\
  PIN(A,0 ,14), /* /SPIM_MOSI/QSPI0_MOSI0/SPI0_MOSI/SC0_CLK/UART0_RXD/UART1_nRTS/I2C2_SDA/BPWM0_CH0/EPWM0_CH5/DAC0_ST                           */\
        /* 15      VDDIO                                                                                                                       */\
        /* 16      nRESET                                                                                                                      */\
  PIN(F,0 ,17), /* /UART1_TXD/I2C1_SCL/BPWM1_CH0/ICE_DAT                                                                                        */\
  PIN(F,1 ,18), /* /UART1_RXD/I2C1_SDA/BPWM1_CH1/ICE_CLK                                                                                        */\
  PIN(C,1 ,19), /* /SPIM_MISO/QSPI0_MISO0/SC1_DAT/I2S0_DO/SPI1_CLK/UART2_TXD/I2C0_SCL/EPWM1_CH4/ACMP0_O                                         */\
  PIN(C,0 ,20), /* /SPIM_MOSI/QSPI0_MOSI0/SC1_CLK/I2S0_LRCK/SPI1_SS/UART2_RXD/I2C0_SDA/EPWM1_CH5/ACMP1_O                                        */\
  PIN(A,12,21), /* /I2S0_BCLK/UART4_TXD/I2C1_SCL/SPI2_SS/CAN0_TXD/SC2_PWR/BPWM1_CH2/QEI1_INDEX                                                  */\
  PIN(A,13,22), /* /I2S0_MCLK/UART4_RXD/I2C1_SDA/SPI2_CLK/CAN0_RXD/SC2_RST/BPWM1_CH3/QEI1_A                                                     */\
  PIN(A,14,23), /* /I2S0_DI/UART0_TXD/SPI2_MISO/I2C2_SCL/SC2_DAT/BPWM1_CH4/QEI1_B                                                               */\
  PIN(A,15,24), /* /I2S0_DO/UART0_RXD/SPI2_MOSI/I2C2_SDA/SC2_CLK/BPWM1_CH5/EPWM0_SYNC_IN                                                        */\
        /* 25      VSS                                                                                                                         */\
        /* 26      LDO_CAP                                                                                                                     */\
        /* 27      VDD                                                                                                                         */\
  PIN(B,15,28), /* /EADC0_CH15/SC1_PWR/SPI0_SS/USCI0_CTL1/UART0_nCTS/UART3_TXD/I2C2_SMBAL/EPWM1_CH0/TM0_EXT                                     */\
  PIN(B,14,29), /* /EADC0_CH14/SC1_RST/SPI0_CLK/USCI0_DAT1/UART0_nRTS/UART3_RXD/I2C2_SMBSUS/EPWM1_CH1/TM1_EXT/CLKO                              */\
  PIN(B,13,30), /* /EADC0_CH13/DAC1_OUT/ACMP0_P3/ACMP1_P3/SC1_DAT/SPI0_MISO/USCI0_DAT0/UART0_TXD/UART3_nRTS/I2C2_SCL/EPWM1_CH2/TM2_EXT          */\
  PIN(B,12,31)  /* /EADC0_CH12/DAC0_OUT/ACMP0_P2/ACMP1_P2/SC1_CLK/SPI0_MOSI/USCI0_CLK/UART0_RXD/UART3_nCTS/I2C2_SDA/SD0_nCD/EPWM1_CH3/TM3_EXT   */
         /*32       AVDD  */
#endif

#define MISO_PIN PB_5
#define MOSI_PIN PB_4
#define  SCK_PIN PB_3
#define   SS_PIN PB_2

#define  SDA_PIN PC_0
#define  SCL_PIN PC_1

#define A0  0
#define A1  1
#define A2  2
#define A3  3
#define A4  4
#define A5  5

#endif
