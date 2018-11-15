#ifndef _CHIP100_PINLIST_H_
#define _CHIP100_PINLIST_H_

#define CHIP_PIN_LIST \
PIN(E,15, 1  ), \
PIN(E,14, 2  ), \
PIN(E,13, 3  ), \
PIN(B,14, 4  ), /*INT0/SPI3_SS1/AD0 */\
PIN(B,13, 5  ), /*ACMP1_O/AD1       */\
       /* 6   ,   VBAT              */\
       /* 7   ,   X32_OUT           */\
       /* 8   ,   X32_IN            */\
PIN(A,11, 9  ), /*I2C1_SCL/CAN1_RXD/nRD*/\
PIN(A,10, 10 ), /*I2C1_SDA/CAN1_TXD/nWR*/\
PIN(A,9,  11 ), /*I2C0_SCL             */\
PIN(A,8,  12 ), /*I2C0_SDA             */\
PIN(D,8,  13 ), /*SPI3_SS0             */\
PIN(D,9,  14 ), /*SPI3_CLK             */\
PIN(D,10, 15 ), /*SPI3_MISO0           */\
PIN(D,11, 16 ), /*SPI3_MOSI0           */\
PIN(D,12, 17 ), /*SPI3_MISO1           */\
PIN(D,13, 18) , /*SPI3_MOSI1           */\
PIN(B,4,  19 ), /*UART1_RXD            */\
PIN(B,5,  20 ), /*UART1_TXD            */\
PIN(B,6,  21 ), /*UART1_nRTS/ALE       */\
PIN(B,7,  22 ), /*UART1_nCTS/nCS       */\
       /* 23  ,LDO_CAP                 */\
       /* 24  ,VDD                     */\
       /* 25  ,VSS                     */\
PIN(E,7,  26 ), \
PIN(E,8,  27 ), \
       /* 28,USB_VBUS            */\
       /* 29,USB_VDD33_CAP       */\
       /* 30,USB_D-              */\
       /* 31,USB_D+              */\
PIN(B,0,  32 ), /* UART0_RXD                           */\
PIN(B,1,  33 ), /* UART0_TXD                           */\
PIN(B,2,  34 ), /* UART0_nRTS/TM2_EXT/ACMP0_O/TM2/nWRL */\
PIN(B,3,  35 ), /* UART0_nCTS/TM3_EXT/SC2_CD/TM3/nWRH  */\
PIN(D,6,  36 ), /* CAN0_RXD                            */\
PIN(D,7,  37 ), /* CAN0_TXD                            */\
PIN(D,14, 38 ), /* UART2_RXD/CAN1_RXD                  */\
PIN(D,15, 39 ), /* UART2_TXD/CAN1_TXD                  */\
PIN(C,5,  40 ), /* SPI0_MOSI1                          */\
PIN(C,4,  41 ), /* SPI0_MISO1                          */\
PIN(C,3,  42 ), /* SPI0_MOSI0/I2S_DO                   */\
PIN(C,2,  43 ), /* SPI0_MISO0/I2S_DI                   */\
PIN(C,1,  44 ), /* SPI0_CLK/I2S_BCLK                   */\
PIN(C,0,  45 ), /* SPI0_SS0/I2S_LRCLK                  */\
PIN(E,6,  46 ), \
PIN(E,5,  47 ), /* PWM5/TM1/TM1_EXT					*/\
PIN(B,11, 48 ), /* TM3/PWM4        					*/\
PIN(B,10, 49 ), /* TM2/SPI0_SS1    					*/\
PIN(B,9,  50 ), /* TM1/SPI1_SS1    					*/\
PIN(E,4,  51 ), \
PIN(E,3,  52 ), \
PIN(E,2,  53 ), \
PIN(E,1,  54 ), /* PWM7                            */\
PIN(E,0,  55 ), /* PWM6\                           */\
PIN(C,13, 56 ), /* SPI1_MOSI1                      */\
PIN(C,12, 57 ), /* SPI1_MISO1                      */\
PIN(C,11, 58 ), /* SPI1_MOSI0                      */\
PIN(C,10, 59 ), /* SPI1_MISO0                      */\
PIN(C,9,  60 ), /* SPI1_CLK                        */\
PIN(C,8,  61 ), /* SPI1_SS0/MCLK                   */\
PIN(A,15, 62 ), /* PWM3/I2S_MCLK/SC2_PWR           */\
PIN(A,14, 63 ), /* PWM2/SC2_RST/AD15               */\
PIN(A,13, 64 ), /* PWM1/SC2_CLK/UART5_TXD/AD14     */\
PIN(A,12, 65 ), /* PWM0/SC2_DAT/UART5_RXD/AD13     */\
       /* 66  ,    ICE_DAT                         */\
       /* 67  ,    ICE_CLK                         */\
       /* 68  ,    VDD                             */\
       /* 69  ,    VSS                             */\
       /* 70  ,    AVSS                            */\
PIN(A,0,  71 ), /* ADC0/SC0_PWR                        */\
PIN(A,1,  72 ), /* ADC1/SC0_RST/AD12                   */\
PIN(A,2,  73 ), /* ADC2/SC0_CLK/UART3_TXD/AD11         */\
PIN(A,3,  74 ), /* ADC3/SC0_DAT/UART3_RXD/AD10         */\
PIN(A,4,  75 ), /* ADC4/SC1_PWR/AD9                    */\
PIN(A,5,  76 ), /* ADC5/SC1_RST/AD8                    */\
PIN(A,6,  77 ), /* ADC6/SC1_CLK/UART4_TXD/AD7          */\
PIN(A,7,  78 ), /* ADC7/SPI2_SS1/SC1_DAT/UART4_RXD/AD6 */\
       /* 79,Vref                                      */\
       /* 80,AVDD                                      */\
PIN(D,0,  81 ), /* SPI2_SS0                             */\
PIN(D,1,  82 ), /* SPI2_CLK                             */\
PIN(D,2,  83 ), /* SPI2_MISO0                           */\
PIN(D,3,  84 ), /* SPI2_MOSI0                           */\
PIN(D,4,  85 ), /* SPI2_MISO1                           */\
PIN(D,5,  86 ), /* SPI2_MOSI1                           */\
PIN(C,7,  87 ), /* ACMP0_N/SC1_CD/AD5                   */\
PIN(C,6,  88 ), /* ACMP0_P/SC0_CD/AD4                   */\
PIN(C,15, 89 ), /* ACMP1_N/AD3                          */\
PIN(C,14, 90 ), /* ACMP1_P/AD2                          */\
PIN(B,15, 91 ), /* INT1/TM0/TM0_EXT/AD6                 */\
PIN(F,0,  92 ), /* XT1_OUT     */\
PIN(F,1,  93 ), /* XT1_IN      */\
       /* 94  ,nRESET          */\
       /* 95  ,VSS             */\
       /* 96  ,VDD             */\
PIN(F,2,  97 ), \
PIN(F,3,  98 ), \
       /* 99  , PVSS  */\
PIN(B,8,  100)  /* TM0/STADC/CLKO */

#define MOSI_PIN  PC_3
#define MISO_PIN  PC_2
#define SCK_PIN   PC_1
#define SS_PIN    PC_0

#define SDA_PIN  PA_8
#define SCL_PIN  PA_9


#define A0_PIN  0
#define A1_PIN  1
#define A2_PIN  2
#define A3_PIN  3
#define A4_PIN  4
#define A5_PIN  5
#define A6_PIN  6
#define A7_PIN  7

#endif

