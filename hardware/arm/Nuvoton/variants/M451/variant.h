#ifndef _VARIANT_H_
#define _VARIANT_H_

#ifndef  LED_BUILTIN
 #ifdef CHIP100P
   #define LED_BUILTIN        PC_9  /* 38 */
 #else
   #define LED_BUILTIN        PD_3  /*fixed me*/
 #endif 
   #define LED_BUILTIN_MASK  0
#endif
#ifndef LED_BUILTIN_MASK
  #define LED_BUILTIN_MASK  0
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