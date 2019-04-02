#ifndef _NUVOTON_SERIES_H_
#define _NUVOTON_SERIES_H_

#include "NuMicro.h"
#define GPIO_PIN_REGADR(port, pin)  (((port)< 5)?((GPIO_PIN_DATA_BASE+(0x20*(port))) + ((pin)<<2)):\
                                                 ((GPIO_PIN_DATA_BASE2+(0x20*((port)-5))) + ((pin)<<2)))
#endif