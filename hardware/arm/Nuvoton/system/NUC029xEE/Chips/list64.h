/****************************************************************************
 * @file     NUC029SEE.csv
 * @version  V1.14
 * @Date     2019/03/24-12:10:13 
 * @brief    NuMicro pin descriptions file
 * Copyright (C) 2013-2019 Nuvoton Technology Corp. All rights reserved.
 * MCU: NUC029SEE(LQFP64)
*****************************************************************************/

#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#define CHIP_PIN_LIST \
PIN(B,14,1 ),  /* INT0/AD0                    */\
PIN(B,13,2 ),  /* AD1                         */\
/*       3        VBAT                        */\
/*       4        X32_OUT                     */\
/*       5        X32_IN                      */\
PIN(A,11,6 ),  /* I2C1_SCL/nRD                */\
PIN(A,10,7 ),  /* I2C1_SDA/nWR                */\
PIN(A,9 ,8 ),  /* I2C0_SCL                    */\
PIN(A,8 ,9 ),  /* I2C0_SDA                    */\
PIN(B,4 ,10),  /* UART1_RXD                   */\
PIN(B,5 ,11),  /* UART1_TXD                   */\
PIN(B,6 ,12),  /* UART1_nRTS/ALE              */\
PIN(B,7 ,13),  /* UART1_nCTS/nCS              */\
/*       14       LDO_CAP                     */\
/*       15       VDD                         */\
/*       16       VSS                         */\
/*       17       USB_VBUS                    */\
/*       18       USB_VDD33_CAP               */\
/*       19       USB_D-                      */\
/*       20       USB_D+                      */\
PIN(B,0 ,21),  /* UART0_RXD                   */\
PIN(B,1 ,22),  /* UART0_TXD                   */\
PIN(B,2 ,23),  /* UART0_nRTS/TM2_EXT/TM2/nWRL */\
PIN(B,3 ,24),  /* UART0_nCTS/TM3_EXT/TM3/nWRH */\
PIN(C,3 ,25),  /* SPI0_MOSI0                  */\
PIN(C,2 ,26),  /* SPI0_MISO0                  */\
PIN(C,1 ,27),  /* SPI0_CLK                    */\
PIN(C,0 ,28),  /* SPI0_SS0                    */\
PIN(E,5 ,29),  /* PWM5/TM1/TM1_EXT            */\
PIN(B,11,30),  /* TM3/PWM4                    */\
PIN(B,10,31),  /* TM2/UART2_RXD               */\
PIN(B,9 ,32),  /* TM1/UART2_TXD               */\
PIN(C,11,33),  /* SPI1_MOSI0                  */\
PIN(C,10,34),  /* SPI1_MISO0                  */\
PIN(C,9 ,35),  /* SPI1_CLK                    */\
PIN(C,8 ,36),  /* SPI1_SS0/MCLK               */\
PIN(A,15,37),  /* PWM3                        */\
PIN(A,14,38),  /* PWM2/AD15                   */\
PIN(A,13,39),  /* PWM1/AD14                   */\
PIN(A,12,40),  /* PWM0/AD13                   */\
/*       41       ICE_DAT                     */\
/*       42       ICE_CLK                     */\
/*       43       AVSS                        */\
PIN(A,0 ,44),  /* ADC0                        */\
PIN(A,1 ,45),  /* ADC1/AD12                   */\
PIN(A,2 ,46),  /* ADC2/AD11                   */\
PIN(A,3 ,47),  /* ADC3/AD10                   */\
PIN(A,4 ,48),  /* ADC4/AD9                    */\
PIN(A,5 ,49),  /* ADC5/AD8                    */\
PIN(A,6 ,50),  /* ADC6/AD7                    */\
/*       51       VREF                        */\
/*       52       AVDD                        */\
PIN(C,7 ,53),  /* ADC7/AD5                    */\
PIN(C,6 ,54),  /* ADC8/AD4                    */\
PIN(C,15,55),  /* ADC9/AD3                    */\
PIN(C,14,56),  /* ADC10/AD2                   */\
PIN(B,15,57),  /* INT1/TM0/ADC11/TM0_EXT/AD6  */\
PIN(F,0 ,58),  /* XT1_OUT                     */\
PIN(F,1 ,59),  /* XT1_IN                      */\
/*       60       nRESET                      */\
/*       61       VSS                         */\
/*       62       VDD                         */\
/*       63       VSS                         */\
PIN(B,8 ,64)   /* TM0/STADC/CLKO              */ 


#define   SS_PIN  PA_4
#define MOSI_PIN  PA_5
#define MISO_PIN  PA_6
#define  SCK_PIN  PA_7

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