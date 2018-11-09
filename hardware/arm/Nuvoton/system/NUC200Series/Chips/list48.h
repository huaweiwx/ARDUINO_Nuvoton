#ifndef _CHIP48_PINLIST_H_
#define _CHIP48_PINLIST_H_

#define VARIANT_PIN_LIST \
       /* 1   ,   VBAT              */\
       /* 2   ,   X32_OUT           */\
       /* 3   ,   X32_IN            */\
PIN(A,11, 4 ), /*I2C1_SCL/CAN1_RXD/nRD*/\
PIN(A,10, 5 ), /*I2C1_SDA/CAN1_TXD/nWR*/\
PIN(A,9,  6 ), /*I2C0_SCL             */\
PIN(A,8,  7 ), /*I2C0_SDA             */\
PIN(B,4,  8  ), /*UART1_RXD            */\
PIN(B,5,  9  ), /*UART1_TXD            */\
       /* 10  ,LDO_CAP                 */\
       /* 11  ,VDD                     */\
       /* 12  ,VSS                     */\
       /* 13,USB_VBUS            */\
       /* 14,USB_VDD33_CAP       */\
       /* 15,USB_D-              */\
       /* 16,USB_D+              */\
PIN(B,0,  17 ), /* UART0_RXD                           */\
PIN(B,1,  18 ), /* UART0_TXD                           */\
PIN(D,6,  19 ), /* CAN0_RXD                            */\
PIN(D,7,  20 ), /* CAN0_TXD                            */\
PIN(C,3,  21 ), /* SPI0_MOSI0/I2S_DO                   */\
PIN(C,2,  22 ), /* SPI0_MISO0/I2S_DI                   */\
PIN(C,1,  23 ), /* SPI0_CLK/I2S_BCLK                   */\
PIN(C,0,  24 ), /* SPI0_SS0/I2S_LRCLK                  */\
PIN(A,15, 25 ), /* PWM3/I2S_MCLK/SC2_PWR           */\
PIN(A,14, 26 ), /* PWM2/SC2_RST/AD15               */\
PIN(A,13, 27 ), /* PWM1/SC2_CLK/UART5_TXD/AD14     */\
PIN(A,12, 28 ), /* PWM0/SC2_DAT/UART5_RXD/AD13     */\
       /* 29  ,    ICE_DAT                         */\
       /* 30  ,    ICE_CLK                         */\
       /* 31  ,    AVSS                            */\
PIN(A,0,  32 ), /* ADC0/SC0_PWR                        */\
PIN(A,1,  33 ), /* ADC1/SC0_RST/AD12                   */\
PIN(A,2,  34 ), /* ADC2/SC0_CLK/UART3_TXD/AD11         */\
PIN(A,3,  35 ), /* ADC3/SC0_DAT/UART3_RXD/AD10         */\
PIN(A,4,  36 ), /* ADC4/SC1_PWR/AD9                    */\
PIN(A,5,  37 ), /* ADC5/SC1_RST/AD8                    */\
PIN(A,6,  38 ), /* ADC6/SC1_CLK/UART4_TXD/AD7          */\
       /* 39,Vref                                      */\
       /* 40,AVDD                                      */\
PIN(C,7,  41 ), /* ACMP0_N/SC1_CD/AD5                   */\
PIN(C,6,  42 ), /* ACMP0_P/SC0_CD/AD4                   */\
PIN(B,15, 43 ), /* INT1/TM0/TM0_EXT/AD6                 */\
       /* 44  ,nRESET          */\
       /* 45  ,VSS             */\
       /* 46  ,VDD             */\
       /* 47 , PVSS  */\
PIN(B,8,  48)  /* TM0/STADC/CLKO */

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

