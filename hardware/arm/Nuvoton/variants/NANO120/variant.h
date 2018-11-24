#ifndef _VARIANT_H_
#define _VARIANT_H_

#define VARIANT_PIN_LIST \
PIN(E,13,1  ), \
PIN(B,14,2  ), \
PIN(B,13,3  ), \
PIN(B,12,4	), \
PIN(A,11,9  ), \
PIN(A,10,10 ), \
PIN(A,9, 11 ), \
PIN(A,8, 12 ), \
PIN(D,8, 13 ), \
PIN(D,9, 14 ), \
PIN(D,10,15 ), \
PIN(D,11,16 ), \
PIN(D,12,17 ), \
PIN(D,13,18 ), \
PIN(B,4 ,19 ), \
PIN(B,5 ,20 ), \
PIN(B,6 ,21 ), \
PIN(B,7 ,22 ), \
PIN(E,12,33 ), \
PIN(E,11,34 ), \
PIN(E,10,35 ), \
PIN(E,9 ,36 ), \
PIN(E,8 ,37 ), \
PIN(E,7 ,38 ), \
PIN(B,0 ,44 ), \
PIN(B,1 ,45 ), \
PIN(B,2 ,46 ), \
PIN(B,3 ,47 ), \
PIN(D,6 ,48 ), \
PIN(D,7 ,49 ), \
PIN(D,14,50 ), \
PIN(D,15,51 ), \
PIN(C,5 ,52 ), \
PIN(C,4 ,53 ), \
PIN(C,3 ,54 ), \
PIN(C,2 ,55 ), \
PIN(C,1 ,56 ), \
PIN(C,0 ,57 ), \
PIN(E,6 ,58 ), \
PIN(E,5 ,61 ), \
PIN(B,11,62 ), \
PIN(B,10,63 ), \
PIN(B,9 ,64	), \
PIN(E,4 ,65 ), \
PIN(E,3 ,66 ), \
PIN(E,2 ,67 ), \
PIN(E,1 ,68 ), \
PIN(E,0 ,69 ), \
PIN(C,13,70 ), \
PIN(C,12,71	), \
PIN(C,11,72 ), \
PIN(C,10,73 ), \
PIN(C,9 ,74 ), \
PIN(C,8 ,75	), \
PIN(A,15,76 ), \
PIN(A,14,77 ), \
PIN(A,13,78	), \
PIN(A,12,79 ), \
PIN(F,0 ,80 ), \
PIN(F,1 ,81	), \
PIN(A,0 ,89 ), \
PIN(A,1 ,90 ), \
PIN(A,2 ,91 ), \
PIN(A,3 ,92	), \
PIN(A,4 ,93 ), \
PIN(A,5 ,94 ), \
PIN(A,6 ,95 ), \
PIN(A,7 ,96 ), \
PIN(D,0 ,100), \
PIN(D,1 ,101), \
PIN(D,2 ,102), \
PIN(D,3 ,103), \
PIN(D,4 ,105), \
PIN(D,5 ,106), \
PIN(C,7 ,107), \
PIN(C,6 ,108), \
PIN(C,15,109), \
PIN(C,14,110), \
PIN(B,15,111), \
PIN(F,4 ,122), \
PIN(F,5 ,123), \
PIN(B,8 ,126), \
PIN(E,15,127), \
PIN(E,14,128)

#ifndef  LED_BUILTIN
 #define LED_BUILTIN PE_6
#endif

static const uint8_t SS   = 43;
static const uint8_t MOSI = 42;
static const uint8_t MISO = 40;
static const uint8_t SCK  = 41;

static const uint8_t SDA = 14;
static const uint8_t SCL = 15;

static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
static const uint8_t A6 = 6;
static const uint8_t A7 = 7;
static const uint8_t A8 = 8;
static const uint8_t A9 = 9;
#endif