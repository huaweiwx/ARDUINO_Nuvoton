#ifndef _VARIANT_H_
#define _VARIANT_H_
#define USE_BoardToPin
/*__NUC131__*/
#if 0  /* 48pins */  
#define VARIANT_PIN_LIST \
pin(B,12,1   ), \
pin(F,5 ,2   ), \
pin(F,4 ,3   ), \
pin(A,11,4   ), \
pin(A,10,5   ), \
pin(A,9 ,6   ), \
pin(A,8 ,7   ), \
pin(B,4, 8   ), \
pin(B,5, 9   ), \
pin(B,0, 13  ), \
pin(B,1, 14  ), \
pin(B,2, 15  ), \
pin(B,3, 16	 ), \
pin(D,6, 17  ), \
pin(D,7, 18	 ), \
pin(D,14,19  ), \
pin(D,15,20	 ), \
pin(C,3, 21  ), \
pin(C,2, 22  ), \
pin(C,1, 23  ), \
pin(C,0, 24	 ), \
pin(A,15,25  ), \
pin(A,14,26  ), \
pin(A,13,27  ), \
pin(A,12,28  ), \
pin(F,7 ,29  ), \
pin(F,6 ,30  ), \
pin(A,0 ,32  ), \
pin(A,1 ,33  ), \
pin(A,2 ,34  ), \
pin(A,3 ,35  ), \
pin(A,4 ,36	 ), \
pin(A,5 ,37  ), \
pin(A,6 ,38  ), \
pin(A,7 ,39  ), \
pin(C,7, 41  ), \
pin(C,6, 42	 ), \
pin(B,15,43  ), \
pin(F,0 ,44  ), \
pin(F,1 ,45  ), \
pin(F,8 ,47  ), \
pin(B,8 ,48  )


#else  /* 64pins */
#define VARIANT_PIN_LIST \
PIN(B,14,1 ), \
PIN(B,13,2 ), \
PIN(B,12,3 ), \
PIN(F,5 ,4 ), \
PIN(F,4 ,5 ), \
PIN(A,11,6 ), \
PIN(A,10,7 ), \
PIN(A,9 ,8 ), \
PIN(A,8 ,9 ), \
PIN(B,4, 10), \
PIN(B,5, 11), \
PIN(B,6, 12), \
PIN(B,7, 13), \
PIN(B,0, 17), \
PIN(B,1, 18), \
PIN(B,2, 19), \
PIN(B,3, 20), \
PIN(D,6, 21), \
PIN(D,7, 22), \
PIN(D,14,23), \
PIN(D,15,24), \
PIN(C,3, 25), \
PIN(C,2, 26), \
PIN(C,1, 27), \
PIN(C,0, 28), \
PIN(E,5, 29), \
PIN(B,11,30), \
PIN(B,10,31), \
PIN(B,9, 32), \
PIN(C,11,33), \
PIN(C,10,34), \
PIN(C,9, 35), \
PIN(C,8, 36), \
PIN(A,15,37), \
PIN(A,14,38), \
PIN(A,13,39), \
PIN(A,12,40), \
PIN(F,7 ,41), \
PIN(F,6 ,42), \
PIN(A,0 ,44), \
PIN(A,1 ,45), \
PIN(A,2 ,46), \
PIN(A,3 ,47), \
PIN(A,4 ,48), \
PIN(A,5 ,49), \
PIN(A,6 ,50), \
PIN(A,7 ,51), \
PIN(C,7, 53), \
PIN(C,6, 54), \
PIN(C,15,55), \
PIN(C,14,56), \
PIN(B,15,57), \
PIN(F,0 ,58), \
PIN(F,1 ,59), \
PIN(F,8 ,63), \
PIN(B,8 ,64)

#endif

#ifndef  LED_BUILTIN
 #define  LED_BUILTIN  13
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
//static const uint8_t A6 = 6;
//static const uint8_t A7 = 7;
//static const uint8_t A8 = 8;
//static const uint8_t A9 = 9;

#endif