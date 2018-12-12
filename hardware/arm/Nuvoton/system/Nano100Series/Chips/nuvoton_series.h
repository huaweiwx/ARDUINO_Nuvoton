
#include "Nano100Series.h"

#define GPIO_PIN_REGADR(port, pin) (GPIO_PIN_DATA_BASE+ 0x40*(port) + ((pin)<<2)) /* Pin Data Input/Output  */
