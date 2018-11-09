#ifndef _VARIANT_H_
#define _VARIANT_H_

#ifndef  LED_BUILTIN
# define LED_BUILTIN  P0_4
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

/*
#define SS    P1_4
#define MOSI  P1_5
#define MISO  P1_6
#define SCK   P1_7
#define SDA   P3_4
#define SCL   P3_5
*/

#define A0    0
#define A1    1
#define A2    2
#define A3    3


#endif
