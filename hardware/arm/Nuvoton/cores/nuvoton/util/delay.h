//AVR compatibility functions
#ifndef _DELAY_H_
#define _DELAY_H_

#define _delay_us(n) delayMicroseconds(n)

#define _delay_ms(n) delay(n)

/*10 cycle*/
#define _delay_loop_2(x)  do{for(uint32_t i=0;i<x;i++) {asm volatile("nop");}}while(0)

#endif

