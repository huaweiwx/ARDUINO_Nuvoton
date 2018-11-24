#ifndef _VARIANT_H_
#define _VARIANT_H_

#ifndef  LED_BUILTIN
 #define LED_BUILTIN     PA_0
#endif


/*if undef use default*/
#ifndef UART0_LOC
#define UART0_LOC 0
#endif
#ifndef UART1_LOC
#define UART1_LOC 1
#endif
#ifndef UART2_LOC
#define UART2_LOC 2
#endif
#ifndef UART3_LOC
#define UART3_LOC 3
#endif
#ifndef UART4_LOC
#define UART4_LOC 4
#endif
#ifndef UART5_LOC
#define UART5_LOC 5
#endif

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

#ifndef SPI0_LOC
#define SPI0_LOC 0
#endif
#ifndef SPI1_LOC
#define SPI1_LOC 1
#endif
#ifndef SPI2_LOC
#define SPI2_LOC 2
#endif


#ifndef SDA
#define SDA  SDA_PIN
#endif

#ifndef SCL
#define SCL  SCL_PIN
#endif

#ifndef I2C0_LOC
#define I2C0_LOC 0
#endif
#ifndef I2C1_LOC
#define I2C1_LOC 1
#endif
#ifndef I2C2_LOC
#define I2C2_LOC 2
#endif

#endif