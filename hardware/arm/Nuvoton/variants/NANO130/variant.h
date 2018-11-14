#ifndef _VARIANT_H_
#define _VARIANT_H_
//#define USE_BoardToPin

#define VARIANT_PIN_LIST \
PIN(E,13,1  ),      /* LCD_SEG27                     */\
PIN(B,14,2  ),      /* INT0/SC2_CD/SPI2_SS1/LCD_SEG26*/\
PIN(B,13,3  ),      /* EBI_AD1/LCD_SEG25             */\
PIN(B,12,4	),      /* EBI_AD0/FCLKO/LCD_SEG24       */\
      /* 5,NC                                        */\
      /* 6,X32_OUT                                   */\
      /* 7,X32_IN                                    */\
      /* 8,NC                                        */\
PIN(A,11,9  ), /* I2C1_SCL/EBI_nRD/SC0_RST/SPI2_MOSI0/LCD_SEG23 */\
PIN(A,10,10 ), /* I2C1_SDA/EBI_nWR/SC0_PWR/SPI2_MISO0/LCD_SEG22 */\
PIN(A,9, 11 ), /* I2C0_SCL/SC0_DAT/SPI2_CLK/LCD_SEG21 */\
PIN(A,8, 12 ), /* I2C0_SDA/SC0_CLK/SPI2_SS0/LCD_SEG20 */\
PIN(D,8, 13 ), /* LCD_SEG19 */\
PIN(D,9, 14 ), /* LCD_SEG18 */\
PIN(D,10,15 ), /* LCD_SEG17 */\
PIN(D,11,16 ), /* LCD_SEG16 */\
PIN(D,12,17 ), /* LCD_SEG15 */\
PIN(D,13,18 ), /* LCD_SEG14 */\
PIN(B,4 ,19 ), /* UART1_RXD/SC0_CD/SPI2_SS0/LCD_SEG13 */\
PIN(B,5 ,20 ), /* UART1_TXD/SC0_RST/SPI2_CLK/LCD_SEG12 */\
PIN(B,6 ,21 ), /* UART1_RTSn/EBI_ALE/SPI2_MISO0/LCD_SEG11 */\
PIN(B,7 ,22 ), /* UART1_CTSn/EBI_nCS/SPI2_MOSI0/LCD_SEG10 */\
      /* 23,NC                                            */\
      /* 24,LDO_CAP                                       */\
      /* 25,NC                                            */\
      /* 26,NC                                            */\
      /* 27,VDD                                           */\
      /* 28,NC                                            */\
      /* 29,VSS                                           */\
      /* 30,VSS                                           */\
      /* 31,VSS                                           */\
      /* 32,VSS                                           */\
PIN(E,12,33 ), /*  */\
PIN(E,11,34 ), /*  */\
PIN(E,10,35 ), /*  */\
PIN(E,9 ,36 ), /*  */\
PIN(E,8 ,37 ), /* LCD_SEG9 */\
PIN(E,7 ,38 ), /* LCD_SEG8 */\
      /* 39,NC             */\
      /* 40,USB_VBUS       */\
      /* 41,USB_VDD33_CAP  */\
      /* 42,USB_D-         */\
      /* 43,USB_D+         */\
PIN(B,0 ,44 ), /* UART0_RXD/SPI1_MOSI0/LCD_SEG7 */\
PIN(B,1 ,45 ), /* UART0_TXD/SPI1_MISO0/LCD_SEG6 */\
PIN(B,2 ,46 ), /* UART0_RTSn/EBI_nWRL/SPI1_CLK/LCD_SEG5 */\
PIN(B,3 ,47 ), /* UART0_CTSn/EBI_nWRH/SPI1_SS0/LCD_SEG4 */\
PIN(D,6 ,48 ), /* LCD_SEG3 */\
PIN(D,7 ,49 ), /* LCD_SEG2 */\
PIN(D,14,50 ), /* LCD_SEG1 */\
PIN(D,15,51 ), /* LCD_SEG0 */\
PIN(C,5 ,52 ), /* SPI0_MOSI1/LCD_COM3 */\
PIN(C,4 ,53 ), /* SPI0_MISO1/LCD_COM2 */\
PIN(C,3 ,54 ), /* SPI0_MOSI0/I2S_DO/SC1_RST/LCD_COM1 */\
PIN(C,2 ,55 ), /* SPI0_MISO0/I2S_DI/SC1_PWR/LCD_COM0 */\
PIN(C,1 ,56 ), /* SPI0_CLK/I2S_BCLK/SC1_DAT/LCD_DH2 */\
PIN(C,0 ,57 ), /* SPI0_SS0/I2S_LRCLK/SC1_CLK/LCD_DH1 */\
PIN(E,6 ,58 ), /*  */\
      /* 59,LCD_VLCD  */\
      /* 60,NC        */\
PIN(E,5 ,61 ), /*  */\
PIN(B,11,62 ), /* PWM1_CH0/TM3/SC2_DAT/SPI0_MISO0/LCD_V1 */\
PIN(B,10,63 ), /* SPI0_SS1/TM2/SC2_CLK/SPI0_MOSI0/LCD_V2 */\
PIN(B,9 ,64	), /* SPI1_SS1/TM1/SC2_RST/INT0/LCD_V3 */\
PIN(E,4 ,65 ), /* SPI0_MOSI0 */\
PIN(E,3 ,66 ), /* SPI0_MISO0 */\
PIN(E,2 ,67 ), /* SPI0_CLK */\
PIN(E,1 ,68 ), /* PWM1_CH3/SPI0_SS0 */\
PIN(E,0 ,69 ), /* PWM1_CH2/I2S_MCLK */\
PIN(C,13,70 ), /* SPI1_MOSI1/PWM1_CH1/SNOOPER/INT1/I2C0_SCL */\
PIN(C,12,71	), /* SPI1_MISO1/PWM1_CH0/INT0/I2C0_SDA */\
PIN(C,11,72 ), /* SPI1_MOSI0/UART1_TXD */\
PIN(C,10,73 ), /* SPI1_MISO0/UART1_RXD */\
PIN(C,9 ,74 ), /* SPI1_CLK/I2C1_SCL */\
PIN(C,8 ,75	), /* SPI1_SS0/EBI_MCLK/I2C1_SDA */\
PIN(A,15,76 ), /* PWM0_CH3/I2S_MCLK/TC3/SC0_PWR/UART0_TXD */\
PIN(A,14,77 ), /* PWM0_CH2/EBI_AD15/TC2/UART0_RXD */\
PIN(A,13,78	), /* PWM0_CH1/EBI_AD14/TC1/I2C0_SCL */\
PIN(A,12,79 ), /* PWM0_CH0/EBI_AD13/TC0/I2C0_SDA */\
PIN(F,0 ,80 ), /* INT0/ICE_DAT */\
PIN(F,1 ,81	), /* FCLKO/INT1/ICE_CLK */\
      /* 82,NC   */\
      /* 83,VDD  */\
      /* 84,NC   */\
      /* 85,VSS  */\
      /* 86,VSS  */\
      /* 87,AVSS */\
      /* 88,AVSS */\
PIN(A,0 ,89 ), /* AD0/SC2_CD */\
PIN(A,1 ,90 ), /* AD1/EBI_AD12 */\
PIN(A,2 ,91 ), /* AD2/EBI_AD11/UART1_RXD */\
PIN(A,3 ,92	), /* AD3/EBI_AD10/UART1_TXD */\
PIN(A,4 ,93 ), /* AD4/EBI_AD9/SC2_PWR/I2C0_SDA/LCD_SEG39 */\
PIN(A,5 ,94 ), /* AD5/EBI_AD8/SC2_RST/I2C0_SCL/LCD_SEG38 */\
PIN(A,6 ,95 ), /* AD6/EBI_AD7/TC3/SC2_CLK/PWM0_CH3/LCD_SEG37 */\
PIN(A,7 ,96 ), /* AD7/EBI_AD6/TC2/SC2_DAT/PWM0_CH2/LCD_SEG36 */\
      /* 97,VREF */\
      /* 98,NC   */\
      /* 99,AVDD */\
PIN(D,0 ,100), /* UART1_RXD/SPI2_SS0/SC1_CLK/AD8 */\
PIN(D,1 ,101), /* UART1_TXD/SPI2_CLK/SC1_DAT/AD9 */\
PIN(D,2 ,102), /* UART1_RTSn/I2S_LRCLK/SPI2_MISO0/SC1_PWR/AD10 */\
PIN(D,3 ,103), /* UART1_CTSn/I2S_BCLK/SPI2_MOSI0/SC1_RST/AD11 */\
PIN(D,4 ,105), /* I2S_DI/SPI2_MISO1/SC1_CD/LCD_SEG35 */\
PIN(D,5 ,106), /* I2S_DO/SPI2_MOSI1/LCD_SEG34 */\
PIN(C,7 ,107), /* DA1_OUT/EBI_AD5/TC1/PWM0_CH1 */\
PIN(C,6 ,108), /* DA0_OUT/EBI_AD4/TC0/SC1_CD/PWM0_CH0 */\
PIN(C,15,109), /* EBI_AD3/TC0/PWM1_CH2/LCD_SEG33 */\
PIN(C,14,110), /* EBI_AD2/PWM1_CH3/LCD_SEG32 */\
PIN(B,15,111), /* INT1/SNOOPER/SC1_CD/LCD_SEG31 */\
      /* 112,NC      */\
      /* 113,XT1_IN  */\
      /* 114,XT1_OUT */\
      /* 115,NC      */\
      /* 116,nRESET  */\
      /* 117,VSS     */\
      /* 118,VSS     */\
      /* 119,NC      */\
      /* 120,VDD     */\
      /* 121,NC      */\
PIN(F,4 ,122), /* I2C0_SDA */\
PIN(F,5 ,123), /* I2C0_SCL */\
      /* 124,VSS   */\
      /* 125,PVSS  */\
PIN(B,8 ,126), /* STADC/TM0/INT0/SC2_PWR/LCD_SEG30 */\
PIN(E,15,127), /* LCD_SEG29 */\
PIN(E,14,128)  /* LCD_SEG28 */

#if    defined(ARDUINO_NuEdu_NANO130)
  #define  LED_BUILTIN  PF_5
#elif  defined(ARDUINO_NuTiny_NANO130)
  #define  LED_BUILTIN  PE_6
#else
  #error "board not define! Please add me"
#endif

#define SS    PE_1
#define MOSI  PE_4
#define MISO  PE_3
#define SCK   PE_2

#define SDA   PA_10
#define SCL   PA_11

static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
static const uint8_t A6 = 6;
static const uint8_t A7 = 7;
static const uint8_t A8 = 8;
static const uint8_t A9 = 9;

#endif