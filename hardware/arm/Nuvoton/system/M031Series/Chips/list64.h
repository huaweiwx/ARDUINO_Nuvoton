/****************************************************************************
 * @file     M031SE3AE.csv
 * @version  V1.13
 * @Date     2019/03/22-15:27:48 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2019 Nuvoton Technology Corp. All rights reserved.
   MCU: M031SE3AE(LQFP64)
*****************************************************************************/

#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
    PIN(B,6 ,1 ),  /* ADC0_CH6/EBI_nWRH/UART1_RXD/EBI_nCS1/PWM1_BRAKE1/PWM1_CH5/INT4/ACMP1_O               */\
    PIN(B,5 ,2 ),  /* ADC0_CH5/ACMP1_N/I2C0_SCL/PWM0_CH0/UART2_TXD/TM0/INT0                                */\
    PIN(B,4 ,3 ),  /* ADC0_CH4/ACMP1_P1/I2C0_SDA/PWM0_CH1/UART2_RXD/TM1/INT1                               */\
    PIN(B,3 ,4 ),  /* ADC0_CH3/ACMP0_N/I2C1_SCL/UART1_TXD/PWM0_CH2/PWM0_BRAKE0/TM2/INT2                    */\
    PIN(B,2 ,5 ),  /* ADC0_CH2/ACMP0_P1/I2C1_SDA/UART1_RXD/PWM0_CH3/TM3/INT3                               */\
    PIN(B,1 ,6 ),  /* ADC0_CH1/UART2_TXD/I2C1_SCL/PWM0_CH4/PWM1_CH4/PWM0_BRAKE0                            */\
    PIN(B,0 ,7 ),  /* ADC0_CH0/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/PWM0_CH5/PWM1_CH5/PWM0_BRAKE1               */\
    PIN(A,11,8 ),  /* ACMP0_P0/EBI_nRD/USCI0_CLK/TM0_EXT                                                   */\
    PIN(A,10,9 ),  /* ACMP1_P0/EBI_nWR/USCI0_DAT0/TM1_EXT                                                  */\
    PIN(A,9 ,10),  /* EBI_MCLK/USCI0_DAT1/UART1_TXD/TM2_EXT                                                */\
    PIN(A,8 ,11),  /* EBI_ALE/USCI0_CTL1/UART1_RXD/TM3_EXT/INT4                                            */\
    PIN(F,6 ,12),  /* EBI_ADR19/SPI0_MOSI/EBI_nCS0                                                         */\
    PIN(F,14,13),  /* PWM1_BRAKE0/PWM0_BRAKE0/PWM0_CH4/CLKO/TM3/INT5                                       */\
    PIN(F,5 ,14),  /* UART2_RXD/UART2_nCTS/PWM0_CH0/X32_IN/ADC0_ST                                         */\
    PIN(F,4 ,15),  /* UART2_TXD/UART2_nRTS/PWM0_CH1/X32_OUT                                                */\
    PIN(F,3 ,16),  /* EBI_nCS0/UART0_TXD/I2C0_SCL/XT1_IN                                                   */\
    PIN(F,2 ,17),  /* EBI_nCS1/UART0_RXD/I2C0_SDA/XT1_OUT                                                  */\
    PIN(C,7 ,18),  /* EBI_AD9/UART0_nCTS/PWM1_CH2/TM0/INT3                                                 */\
    PIN(C,6 ,19),  /* EBI_AD8/UART0_nRTS/PWM1_CH3/TM1/INT2                                                 */\
    PIN(A,7 ,20),  /* EBI_AD7/UART0_TXD/I2C1_SCL/PWM1_CH4/ACMP0_WLAT/TM2/INT1                              */\
    PIN(A,6 ,21),  /* EBI_AD6/UART0_RXD/I2C1_SDA/PWM1_CH5/ACMP1_WLAT/TM3/INT0                              */\
                   /* VSS                                                                                  */\
                   /* VDD                                                                                  */\
    PIN(D,15,24),  /* PWM0_CH5/TM3/INT1                                                                    */\
    PIN(A,5 ,25),  /* UART0_nCTS/UART0_TXD/I2C0_SCL/PWM0_CH0                                               */\
    PIN(A,4 ,26),  /* SPI0_I2SMCLK/UART0_nRTS/UART0_RXD/I2C0_SDA/PWM0_CH1                                  */\
    PIN(A,3 ,27),  /* SPI0_SS/UART1_TXD/I2C1_SCL/PWM0_CH2/CLKO/PWM1_BRAKE1                                 */\
    PIN(A,2 ,28),  /* SPI0_CLK/UART1_RXD/I2C1_SDA/PWM0_CH3                                                 */\
    PIN(A,1 ,29),  /* SPI0_MISO/UART0_TXD/UART1_nCTS/PWM0_CH4                                              */\
    PIN(A,0 ,30),  /* SPI0_MOSI/UART0_RXD/UART1_nRTS/PWM0_CH5                                              */\
    PIN(F,15,31),  /* PWM0_BRAKE0/PWM0_CH1/TM2/CLKO/INT4                                                   */\
                   /* nRESET                                                                               */\
/*  PIN(F,0 ,33),     UART1_TXD/I2C1_SCL/UART0_TXD/ICE_DAT                                                 */\
/*  PIN(F,1 ,34),     UART1_RXD/I2C1_SDA/UART0_RXD/ICE_CLK                                                 */\
    PIN(C,5 ,35),  /* EBI_AD5/UART2_TXD/I2C1_SCL/PWM1_CH0                                                  */\
    PIN(C,4 ,36),  /* EBI_AD4/UART2_RXD/I2C1_SDA/PWM1_CH1                                                  */\
    PIN(C,3 ,37),  /* EBI_AD3/UART2_nRTS/PWM1_CH2                                                          */\
    PIN(C,2 ,38),  /* EBI_AD2/UART2_nCTS/PWM1_CH3                                                          */\
    PIN(C,1 ,39),  /* EBI_AD1/UART2_TXD/I2C0_SCL/PWM1_CH4/ACMP0_O                                          */\
    PIN(C,0 ,40),  /* EBI_AD0/UART2_RXD/I2C0_SDA/PWM1_CH5/ACMP1_O                                          */\
    PIN(D,3 ,41),  /* EBI_AD10/USCI0_CTL1/SPI0_SS/UART0_TXD                                                */\
    PIN(D,2 ,42),  /* EBI_AD11/USCI0_DAT1/SPI0_CLK/UART0_RXD                                               */\
    PIN(D,1 ,43),  /* EBI_AD12/USCI0_DAT0/SPI0_MISO                                                        */\
    PIN(D,0 ,44),  /* EBI_AD13/USCI0_CLK/SPI0_MOSI/TM2                                                     */\
    PIN(A,12,45),  /* I2C1_SCL                                                                             */\
    PIN(A,13,46),  /* I2C1_SDA                                                                             */\
    PIN(A,14,47),  /* UART0_TXD                                                                            */\
    PIN(A,15,48),  /* UART0_RXD                                                                            */\
                   /* VSS                                                                                  */\
                   /* LDO_CAP                                                                              */\
                   /* VDD                                                                                  */\
    PIN(C,14,52),  /* EBI_AD11/SPI0_I2SMCLK/USCI0_CTL0/TM1                                                 */\
    PIN(B,15,53),  /* ADC0_CH15/EBI_AD12/SPI0_SS/USCI0_CTL1/UART0_nCTS/PWM1_CH0/TM0_EXT/PWM0_BRAKE1        */\
    PIN(B,14,54),  /* ADC0_CH14/EBI_AD13/SPI0_CLK/USCI0_DAT1/UART0_nRTS/PWM1_CH1/TM1_EXT/CLKO              */\
    PIN(B,13,55),  /* ADC0_CH13/ACMP0_P3/ACMP1_P3/EBI_AD14/SPI0_MISO/USCI0_DAT0/UART0_TXD/PWM1_CH2/TM2_EXT */\
    PIN(B,12,56),  /* ADC0_CH12/ACMP0_P2/ACMP1_P2/EBI_AD15/SPI0_MOSI/USCI0_CLK/UART0_RXD/PWM1_CH3/TM3_EXT  */\
                   /* AVDD                                                                                 */\
                   /* VREF                                                                                 */\
                   /* AVSS                                                                                 */\
    PIN(B,11,60),  /* ADC0_CH11/EBI_ADR16/UART0_nCTS/I2C1_SCL/SPI0_I2SMCLK                                 */\
    PIN(B,10,61),  /* ADC0_CH10/EBI_ADR17/UART0_nRTS/I2C1_SDA                                              */\
    PIN(B,9 ,62),  /* ADC0_CH9/EBI_ADR18/UART0_TXD/UART1_nCTS                                              */\
    PIN(B,8 ,63),  /* ADC0_CH8/EBI_ADR19/UART0_RXD/UART1_nRTS                                              */\
    PIN(B,7 ,64)   /* ADC0_CH7/EBI_nWRL/UART1_TXD/EBI_nCS0/PWM1_BRAKE0/PWM1_CH4/INT5/ACMP0_O               */

#else /*used ICE*/
  #define CHIP_PIN_LIST \
     PIN(B,6 ,1 ),  /* ADC0_CH6/EBI_nWRH/UART1_RXD/EBI_nCS1/PWM1_BRAKE1/PWM1_CH5/INT4/ACMP1_O               */\
     PIN(B,5 ,2 ),  /* ADC0_CH5/ACMP1_N/I2C0_SCL/PWM0_CH0/UART2_TXD/TM0/INT0                                */\
     PIN(B,4 ,3 ),  /* ADC0_CH4/ACMP1_P1/I2C0_SDA/PWM0_CH1/UART2_RXD/TM1/INT1                               */\
     PIN(B,3 ,4 ),  /* ADC0_CH3/ACMP0_N/I2C1_SCL/UART1_TXD/PWM0_CH2/PWM0_BRAKE0/TM2/INT2                    */\
     PIN(B,2 ,5 ),  /* ADC0_CH2/ACMP0_P1/I2C1_SDA/UART1_RXD/PWM0_CH3/TM3/INT3                               */\
     PIN(B,1 ,6 ),  /* ADC0_CH1/UART2_TXD/I2C1_SCL/PWM0_CH4/PWM1_CH4/PWM0_BRAKE0                            */\
     PIN(B,0 ,7 ),  /* ADC0_CH0/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/PWM0_CH5/PWM1_CH5/PWM0_BRAKE1               */\
     PIN(A,11,8 ),  /* ACMP0_P0/EBI_nRD/USCI0_CLK/TM0_EXT                                                   */\
     PIN(A,10,9 ),  /* ACMP1_P0/EBI_nWR/USCI0_DAT0/TM1_EXT                                                  */\
     PIN(A,9 ,10),  /* EBI_MCLK/USCI0_DAT1/UART1_TXD/TM2_EXT                                                */\
     PIN(A,8 ,11),  /* EBI_ALE/USCI0_CTL1/UART1_RXD/TM3_EXT/INT4                                            */\
     PIN(F,6 ,12),  /* EBI_ADR19/SPI0_MOSI/EBI_nCS0                                                         */\
     PIN(F,14,13),  /* PWM1_BRAKE0/PWM0_BRAKE0/PWM0_CH4/CLKO/TM3/INT5                                       */\
     PIN(F,5 ,14),  /* UART2_RXD/UART2_nCTS/PWM0_CH0/X32_IN/ADC0_ST                                         */\
     PIN(F,4 ,15),  /* UART2_TXD/UART2_nRTS/PWM0_CH1/X32_OUT                                                */\
     PIN(F,3 ,16),  /* EBI_nCS0/UART0_TXD/I2C0_SCL/XT1_IN                                                   */\
     PIN(F,2 ,17),  /* EBI_nCS1/UART0_RXD/I2C0_SDA/XT1_OUT                                                  */\
     PIN(C,7 ,18),  /* EBI_AD9/UART0_nCTS/PWM1_CH2/TM0/INT3                                                 */\
     PIN(C,6 ,19),  /* EBI_AD8/UART0_nRTS/PWM1_CH3/TM1/INT2                                                 */\
     PIN(A,7 ,20),  /* EBI_AD7/UART0_TXD/I2C1_SCL/PWM1_CH4/ACMP0_WLAT/TM2/INT1                              */\
     PIN(A,6 ,21),  /* EBI_AD6/UART0_RXD/I2C1_SDA/PWM1_CH5/ACMP1_WLAT/TM3/INT0                              */\
                    /* VSS                                                                                  */\
                    /* VDD                                                                                  */\
     PIN(D,15,24),  /* PWM0_CH5/TM3/INT1                                                                    */\
     PIN(A,5 ,25),  /* UART0_nCTS/UART0_TXD/I2C0_SCL/PWM0_CH0                                               */\
     PIN(A,4 ,26),  /* SPI0_I2SMCLK/UART0_nRTS/UART0_RXD/I2C0_SDA/PWM0_CH1                                  */\
     PIN(A,3 ,27),  /* SPI0_SS/UART1_TXD/I2C1_SCL/PWM0_CH2/CLKO/PWM1_BRAKE1                                 */\
     PIN(A,2 ,28),  /* SPI0_CLK/UART1_RXD/I2C1_SDA/PWM0_CH3                                                 */\
     PIN(A,1 ,29),  /* SPI0_MISO/UART0_TXD/UART1_nCTS/PWM0_CH4                                              */\
     PIN(A,0 ,30),  /* SPI0_MOSI/UART0_RXD/UART1_nRTS/PWM0_CH5                                              */\
     PIN(F,15,31),  /* PWM0_BRAKE0/PWM0_CH1/TM2/CLKO/INT4                                                   */\
                    /* nRESET                                                                               */\
     PIN(F,0 ,33),  /* UART1_TXD/I2C1_SCL/UART0_TXD/ICE_DAT                                                 */\
     PIN(F,1 ,34),  /* UART1_RXD/I2C1_SDA/UART0_RXD/ICE_CLK                                                 */\
     PIN(C,5 ,35),  /* EBI_AD5/UART2_TXD/I2C1_SCL/PWM1_CH0                                                  */\
     PIN(C,4 ,36),  /* EBI_AD4/UART2_RXD/I2C1_SDA/PWM1_CH1                                                  */\
     PIN(C,3 ,37),  /* EBI_AD3/UART2_nRTS/PWM1_CH2                                                          */\
     PIN(C,2 ,38),  /* EBI_AD2/UART2_nCTS/PWM1_CH3                                                          */\
     PIN(C,1 ,39),  /* EBI_AD1/UART2_TXD/I2C0_SCL/PWM1_CH4/ACMP0_O                                          */\
     PIN(C,0 ,40),  /* EBI_AD0/UART2_RXD/I2C0_SDA/PWM1_CH5/ACMP1_O                                          */\
     PIN(D,3 ,41),  /* EBI_AD10/USCI0_CTL1/SPI0_SS/UART0_TXD                                                */\
     PIN(D,2 ,42),  /* EBI_AD11/USCI0_DAT1/SPI0_CLK/UART0_RXD                                               */\
     PIN(D,1 ,43),  /* EBI_AD12/USCI0_DAT0/SPI0_MISO                                                        */\
     PIN(D,0 ,44),  /* EBI_AD13/USCI0_CLK/SPI0_MOSI/TM2                                                     */\
     PIN(A,12,45),  /* I2C1_SCL                                                                             */\
     PIN(A,13,46),  /* I2C1_SDA                                                                             */\
     PIN(A,14,47),  /* UART0_TXD                                                                            */\
     PIN(A,15,48),  /* UART0_RXD                                                                            */\
                    /* VSS                                                                                  */\
                    /* LDO_CAP                                                                              */\
                    /* VDD                                                                                  */\
     PIN(C,14,52),  /* EBI_AD11/SPI0_I2SMCLK/USCI0_CTL0/TM1                                                 */\
     PIN(B,15,53),  /* ADC0_CH15/EBI_AD12/SPI0_SS/USCI0_CTL1/UART0_nCTS/PWM1_CH0/TM0_EXT/PWM0_BRAKE1        */\
     PIN(B,14,54),  /* ADC0_CH14/EBI_AD13/SPI0_CLK/USCI0_DAT1/UART0_nRTS/PWM1_CH1/TM1_EXT/CLKO              */\
     PIN(B,13,55),  /* ADC0_CH13/ACMP0_P3/ACMP1_P3/EBI_AD14/SPI0_MISO/USCI0_DAT0/UART0_TXD/PWM1_CH2/TM2_EXT */\
     PIN(B,12,56),  /* ADC0_CH12/ACMP0_P2/ACMP1_P2/EBI_AD15/SPI0_MOSI/USCI0_CLK/UART0_RXD/PWM1_CH3/TM3_EXT  */\
                    /* AVDD                                                                                 */\
                    /* VREF                                                                                 */\
                    /* AVSS                                                                                 */\
     PIN(B,11,60),  /* ADC0_CH11/EBI_ADR16/UART0_nCTS/I2C1_SCL/SPI0_I2SMCLK                                 */\
     PIN(B,10,61),  /* ADC0_CH10/EBI_ADR17/UART0_nRTS/I2C1_SDA                                              */\
     PIN(B,9 ,62),  /* ADC0_CH9/EBI_ADR18/UART0_TXD/UART1_nCTS                                              */\
     PIN(B,8 ,63),  /* ADC0_CH8/EBI_ADR19/UART0_RXD/UART1_nRTS                                              */\
     PIN(B,7 ,64)   /* ADC0_CH7/EBI_nWRL/UART1_TXD/EBI_nCS0/PWM1_BRAKE0/PWM1_CH4/INT5/ACMP0_O               */
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

