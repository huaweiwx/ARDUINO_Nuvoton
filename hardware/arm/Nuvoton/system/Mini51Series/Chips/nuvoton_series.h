
#include "Mini51Series.h"

#define GPIO_PIN_REGADR(port, pin) ((GPIO_PIN_DATA_BASE+(0x20*(port))) + ((pin)<<2))