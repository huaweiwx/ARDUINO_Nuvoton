#ifndef _NUVOTON_SERIES_H_
#define _NUVOTON_SERIES_H_

#include "NuMicro.h"
#define GPIO_PIN_REGADR(port, pin) ((GPIO_PIN_DATA_BASE+(0x20*(port))) + ((pin)<<2))

#endif
