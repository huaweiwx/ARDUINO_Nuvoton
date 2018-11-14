#ifndef _VARIANT_H_
#define _VARIANT_H_
//#define USE_BoardToPin

#ifndef LED_BUILTIN
#define LED_BUILTIN P2_3
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
