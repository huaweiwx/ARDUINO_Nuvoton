#ifndef _VARIANT_H_
#define _VARIANT_H_

#if  defined(ARDUINO_NuEdu_NUC240)
#define VARIANT_PIN_LIST \
PIN(B,0,   0), /* UART0_RXD                       */\
PIN(B,1,   1), /* UART0_TXD                       */\
PIN(A,12,  2), /* PWM0/SC2_DAT/UART5_RXD/AD13     */\
PIN(A,13,  3), /* PWM1/SC2_CLK/UART5_TXD/AD14     */\
PIN(A,14,  4), /* PWM2/SC2_RST/AD15               */\
PIN(A,15,  5), /* PWM3/I2S_MCLK/SC2_PWR           */\
PIN(B,11,  6), /* TM3/PWM4        			      */\
PIN(E,5,   7), /* PWM5/TM1/TM1_EXT				  */\
PIN(E,0,   8), /* PWM6\                           */\
PIN(E,1,   9), /* PWM7                            */\
PIN(C,4,  10), /* SPI0_MISO1                      */\
PIN(B,9,  11), /* TM1/SPI1_SS1    				  */\
PIN(C,5,  12), /* SPI0_MOSI1                      */\
PIN(E,6,  13), \
PIN(A,10, 14), /*I2C1_SDA/CAN1_TXD/nWR*/\
PIN(A,11, 15), /*I2C1_SCL/CAN1_RXD/nRD*/\
PIN(A,0,  16), /* ADC0/SC0_PWR                        */\
PIN(A,1,  17), /* ADC1/SC0_RST/AD12                   */\
PIN(A,2,  18), /* ADC2/SC0_CLK/UART3_TXD/AD11         */\
PIN(A,3,  19), /* ADC3/SC0_DAT/UART3_RXD/AD10         */\
PIN(A,4,  20), /* ADC4/SC1_PWR/AD9                    */\
PIN(A,5,  21), /* ADC5/SC1_RST/AD8                    */\
PIN(A,6,  22), /* ADC6/SC1_CLK/UART4_TXD/AD7          */\
PIN(A,7,  23), /* ADC7/SPI2_SS1/SC1_DAT/UART4_RXD/AD6 */\
PIN(C,15, 24), /* ACMP1_N/AD3                         */\
PIN(C,14, 25), /* ACMP1_P/AD2                         */\
PIN(E,15, 26), \
PIN(E,14, 27), \
PIN(D,4,  28), /* SPI2_MISO1                          */\
PIN(D,5,  29), /* SPI2_MOSI1                          */\
PIN(D,6,  30), /* CAN0_RXD                            */\
PIN(D,7,  31), /* CAN0_TXD                            */\
PIN(A,9,  32), /*I2C0_SCL             */\
PIN(A,8,  33), /*I2C0_SDA             */\
PIN(B,4,  34), /*UART1_RXD            */\
PIN(B,5,  35), /*UART1_TXD            */\
PIN(D,14, 36), /* UART2_RXD/CAN1_RXD                  */\
PIN(D,15, 37), /* UART2_TXD/CAN1_TXD                  */\
PIN(E,7,  38), \
PIN(E,8,  39), \
PIN(D,2,  40), /* SPI2_MISO0                           */\
PIN(D,1,  41), /* SPI2_CLK                             */\
PIN(D,3,  42), /* SPI2_MOSI0                           */\
/* (D,4,  43), /* SPI2_MISO1                           */\
PIN(C,13, 44), /* SPI1_MOSI1                      */\
PIN(D,8,  45), /*SPI3_SS0                         */\
PIN(B,8,  46), /* TM0/STADC/CLKO                  */\
PIN(D,9,  47), /*SPI3_CLK                         */\
/* (A,15, 48), /* PWM3/I2S_MCLK/SC2_PWR           */\
PIN(D,10, 49), /*SPI3_MISO0                       */\
PIN(C,0,  50), /* SPI0_SS0/I2S_LRCLK              */\
PIN(D,11, 51), /*SPI3_MOSI0                       */\
PIN(C,1,  52), /* SPI0_CLK/I2S_BCLK               */\
PIN(D,12, 53), /*SPI3_MISO1                       */\
PIN(C,2,  54), /* SPI0_MISO0/I2S_DI               */\
PIN(D,13, 55), /*SPI3_MOSI1                       */\
PIN(C,3,  56), /* SPI0_MOSI0/I2S_DO               */\
PIN(C,12, 57), /* SPI1_MISO1                      */\
PIN(B,10, 58), /* TM2/SPI0_SS1    				  */\
/*        59      X                               */\
PIN(B,3,  60), /* UART0_nCTS/TM3_EXT/SC2_CD/TM3/nWRH  */\
/*        61     X                               */\
PIN(C,7,  62), /* ACMP0_N/SC1_CD/AD5             */\
/*        63     X                               */\
PIN(C,6,  64), /* ACMP0_P/SC0_CD/AD4             */\
/*        65     X                               */\
PIN(B,2,  66), /* UART0_nRTS/TM2_EXT/ACMP0_O/TM2/nWRL */\
/*        67     X                               */\
PIN(C,8,  68), /* SPI1_SS0/MCLK                  */\
PIN(B,7,  69), /*UART1_nCTS/nCS                  */\
PIN(C,9,  70), /* SPI1_CLK                       */\
PIN(B,6,  71), /*UART1_nRTS/ALE                  */\
PIN(C,10, 72), /* SPI1_MISO0                     */\
PIN(F,2,  73), \
PIN(C,11, 74), /* SPI1_MOSI0                     */\
PIN(F,3,  75), \
PIN(E,2,  76), \
PIN(B,14, 77), /*INT0/SPI3_SS1/AD0               */\
PIN(E,3,  78), \
PIN(B,15, 79), /* INT1/TM0/TM0_EXT/AD6           */\
PIN(E,4,  80), \
PIN(E,13, 81), \
PIN(B,13, 82), /*ACMP1_O/AD1                     */\
PIN(D,0,  83)  /* SPI2_SS0                       */\
/* PIN(F,0,  84), /* XT1_OUT     */
/* PIN(F,1,  85), /* XT1_IN      */

#endif

#ifndef  LED_BUILTIN
 #define LED_BUILTIN      PA_12  /*PA12*/
#endif

/*if undef use default*/
#ifndef MISO
#define MISO MISO_PIN 
#endif
#ifndef MOSI
#define MOSI MOSI_PIN
#endif
#ifndef SCK
#define SCK  SCK_PIN
#endif
#ifndef SS
#define SS   SS_PIN
#endif

#ifndef SDA
#define SDA  SDA_PIN
#endif

#ifndef SCL
#define SCL  SCL_PIN
#endif

#endif