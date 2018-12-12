#ifndef _VARIANT_H_
#define _VARIANT_H_

#define VARIANT_PIN_LIST \
PIN(B,13,1  ),\
PIN(B,14,2	),\
PIN(B,15,3  ),\
PIN(B,5, 4  ),\
PIN(B,6, 5  ),\
PIN(B,7, 6  ),\
PIN(D,0, 8  ),\
PIN(C,8, 12 ),\
PIN(D,8, 13 ),\
PIN(D,9, 14 ),\
PIN(D,1, 15	),\
PIN(D,2, 16 ),\
PIN(D,3, 17 ),\
PIN(D,4, 18 ),\
PIN(D,5, 19 ),\
PIN(E,3, 20 ),\
PIN(D,6, 21 ),\
PIN(F,0, 23 ),\
PIN(F,1, 24 ),\
PIN(F,2, 25	),\
PIN(D,10,26 ),\
PIN(D,11,27 ),\
PIN(D,12,28 ),\
PIN(D,13,29 ),\
PIN(D,14,30 ),\
PIN(D,15,31 ),\
PIN(D,7, 32	),\
PIN(F,3, 33 ),\
PIN(F,4, 34 ),\
PIN(C,9, 38 ),\
PIN(C,10,39	),\
PIN(C,11,40 ),\
PIN(C,12,41 ),\
PIN(C,13,42 ),\
PIN(C,14,43	),\
PIN(C,0, 44 ),\
PIN(C,1, 45 ),\
PIN(C,2, 46 ),\
PIN(C,3, 47 ),\
PIN(C,4, 48 ),\
PIN(E,0, 49 ),\
PIN(C,5, 50	),\
PIN(C,6, 51 ),\
PIN(C,7, 52	),\
PIN(E,4, 53 ),\
PIN(E,5, 54	),\
PIN(F,5, 55 ),\
PIN(F,6, 56	),\
PIN(A,8, 57 ),\
PIN(A,9, 58 ),\
PIN(A,10,59 ),\
PIN(A,11,60	),\
PIN(E,6, 61	),\
PIN(A,7, 62	),\
PIN(A,6, 63	),\
PIN(A,5, 64	),\
PIN(A,4, 65	),\
PIN(E,1, 68	),\
PIN(E,8, 69 ),\
PIN(E,9, 70 ),\
PIN(E,10,71 ),\
PIN(E,11,72 ),\
PIN(E,12,73 ),\
PIN(E,13,74 ),\
PIN(E,7, 76	),\
PIN(C,15,77 ),\
PIN(E,2, 78	),\
PIN(A,3, 79 ),\
PIN(A,2, 80 ),\
PIN(A,1, 81 ),\
PIN(A,0, 82	),\
PIN(A,12,83 ),\
PIN(A,13,84 ),\
PIN(A,14,85 ),\
PIN(A,15,86 ),\
PIN(B,0, 91 ),\
PIN(B,1, 92 ),\
PIN(B,2, 93 ),\
PIN(B,3, 94 ),\
PIN(B,4, 95	),\
PIN(B,8, 96 ),\
PIN(B,9, 97 ),\
PIN(B,10,98	),\
PIN(B,11,99 ),\
PIN(B,12,100)

#ifndef  LED_BUILTIN
 #define LED_BUILTIN      PC_9 /*38*/
  #define LED_BUILTIN_MASK 0
#endif
#ifndef LED_BUILTIN_MASK
  #define LED_BUILTIN_MASK 0
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

/*
#ifndef SDA
#define SDA  SDA_PIN
#endif

#ifndef SCL
#define SCL  SCL_PIN
#endif

#define SS   PC_10
#define MOSI PC_13
#define MISO PC_11
#define SCK  PC_12

#define SDA PD_9
#define SCL PD_1
*/

static const uint8_t A0  = 0;
static const uint8_t A1  = 1;
static const uint8_t A2  = 2;
static const uint8_t A3  = 3;
static const uint8_t A4  = 4;
static const uint8_t A5  = 5;
static const uint8_t A6  = 6;
static const uint8_t A7  = 7;
static const uint8_t A8  = 8;
static const uint8_t A9  = 9;
//static const uint8_t A10 = 10;
//static const uint8_t A11 = 11;

#endif