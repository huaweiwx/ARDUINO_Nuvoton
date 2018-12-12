
#ifndef _NUVOTON_SERIES_H_
#define _NUVOTON_SERIES_H_

#include "M480.h"
#define GPIO_PIN_REGADR(port, pin) ((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2)) /* Pin Data Input/Output  */

#endif //_NUVOTON_SERIES_H_