#ifndef _CHIP64_PINLIST_H_
#define _CHIP64_PINLIST_H_

#define VARIANT_PIN_LIST \
PIN(B,14, 1  ), /*INT0/SPI3_SS1/AD0 */\
PIN(B,13, 2  ), /*ACMP1_O/AD1       */\
       /* 3   ,   VBAT              */\
       /* 4   ,   X32_OUT           */\
       /* 5   ,   X32_IN            */\
PIN(A,11, 6 ), /*I2C1_SCL/CAN1_RXD/nRD*/\
PIN(A,10, 7 ), /*I2C1_SDA/CAN1_TXD/nWR*/\
PIN(A,9,  8 ), /*I2C0_SCL             */\
PIN(A,8,  9 ), /*I2C0_SDA             */\
PIN(B,4,  10 ), /*UART1_RXD            */\
PIN(B,5,  11 ), /*UART1_TXD            */\
PIN(B,6,  12 ), /*UART1_nRTS/ALE       */\
PIN(B,7,  13 ), /*UART1_nCTS/nCS       */\
       /* 14  ,LDO_CAP                 */\
       /* 15  ,VDD                     */\
       /* 16  ,VSS                     */\
       /* 17,USB_VBUS            */\
       /* 18,USB_VDD33_CAP       */\
       /* 19,USB_D-              */\
       /* 20,USB_D+              */\
PIN(B,0,  21 ), /* UART0_RXD                           */\
PIN(B,1,  22 ), /* UART0_TXD                           */\
PIN(B,2,  23 ), /* UART0_nRTS/TM2_EXT/ACMP0_O/TM2/nWRL */\
PIN(B,3,  24 ), /* UART0_nCTS/TM3_EXT/SC2_CD/TM3/nWRH  */\
PIN(D,6,  25 ), /* CAN0_RXD                            */\
PIN(D,7,  26 ), /* CAN0_TXD                            */\
PIN(D,14, 27 ), /* UART2_RXD/CAN1_RXD                  */\
PIN(D,15, 28 ), /* UART2_TXD/CAN1_TXD                  */\
PIN(C,3,  29 ), /* SPI0_MOSI0/I2S_DO                   */\
PIN(C,2,  30 ), /* SPI0_MISO0/I2S_DI                   */\
PIN(C,1,  31 ), /* SPI0_CLK/I2S_BCLK                   */\
PIN(C,0,  32 ), /* SPI0_SS0/I2S_LRCLK                  */\
PIN(C,11, 33 ), /* SPI1_MOSI0                      */\
PIN(C,10, 34 ), /* SPI1_MISO0                      */\
PIN(C,9,  35 ), /* SPI1_CLK                        */\
PIN(C,8,  36 ), /* SPI1_SS0/MCLK                   */\
PIN(A,15, 37 ), /* PWM3/I2S_MCLK/SC2_PWR           */\
PIN(A,14, 38 ), /* PWM2/SC2_RST/AD15               */\
PIN(A,13, 39 ), /* PWM1/SC2_CLK/UART5_TXD/AD14     */\
PIN(A,12, 40 ), /* PWM0/SC2_DAT/UART5_RXD/AD13     */\
       /* 41  ,    ICE_DAT                         */\
       /* 42  ,    ICE_CLK                         */\
       /* 43  ,    AVSS                            */\
PIN(A,0,  44 ), /* ADC0/SC0_PWR                        */\
PIN(A,1,  45 ), /* ADC1/SC0_RST/AD12                   */\
PIN(A,2,  46 ), /* ADC2/SC0_CLK/UART3_TXD/AD11         */\
PIN(A,3,  47 ), /* ADC3/SC0_DAT/UART3_RXD/AD10         */\
PIN(A,4,  48 ), /* ADC4/SC1_PWR/AD9                    */\
PIN(A,5,  49 ), /* ADC5/SC1_RST/AD8                    */\
PIN(A,6,  50 ), /* ADC6/SC1_CLK/UART4_TXD/AD7          */\
       /* 51,Vref                                      */\
       /* 52,AVDD                                      */\
PIN(C,7,  53 ), /* ACMP0_N/SC1_CD/AD5                   */\
PIN(C,6,  54 ), /* ACMP0_P/SC0_CD/AD4                   */\
PIN(C,15, 55 ), /* ACMP1_N/AD3                          */\
PIN(C,14, 56 ), /* ACMP1_P/AD2                          */\
PIN(B,15, 57 ), /* INT1/TM0/TM0_EXT/AD6                 */\
PIN(F,0,  58 ), /* XT1_OUT     */\
PIN(F,1,  59 ), /* XT1_IN      */\
       /* 60  ,nRESET          */\
       /* 61  ,VSS             */\
       /* 62  ,VDD             */\
       /* 63 , PVSS  */\
PIN(B,8,  64)  /* TM0/STADC/CLKO */

#define MOSI_PIN  PC_3
#define MISO_PIN  PC_2
#define SCK_PIN   PC_1
#define SS_PIN    PC_0

#define SDA_PIN   PA_8
#define SCL_PIN   PA_9


#define A0  0
#define A1  1
#define A2  2
#define A3  3
#define A4  4
#define A5  5
#define A6  6
#define A7  7

#endif

