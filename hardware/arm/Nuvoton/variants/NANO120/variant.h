#ifndef _VARIANT_H_
#define _VARIANT_H_

#if defined(NuTiny_EVB)
    #define LED_BUILTIN       PE_6
    #define LED_BUILTIN_MASK  0
    #define BUTTON			  PC_12
    #define BUTTON_MASK	0b0000`001
#endif

#ifndef  LED_BUILTIN
 #ifdef CHIP128P  /*my nano120kd2*/
    #define LED_BUILTIN PE_6
    #define LED_BUILTIN_MASK 0
 #else
    #define LED_BUILTIN PB_12
    #define LED_BUILTIN_MASK  0
 #endif
#endif

#ifndef LED_BUILTIN_MASK
  #define LED_BUILTIN_MASK    0
#endif

#define SS    PC_0
#define MOSI  PC_3
#define MISO  PC_2
#define SCK   PC_1

#define SDA   PA_8
#define SCL   PA_9

#define A0    0
#define A1    1
#define A2    2
#define A3    3
#define A4    4
#define A5    5
#define A6    6
#define A7    7
#define A8    8
#define A9    9


#endif //_VARIANT_H_