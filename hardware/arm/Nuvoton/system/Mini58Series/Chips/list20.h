#ifndef _CHIP20_PINLIST_H_
#define _CHIP20_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
  PIN(1,2,1),/*P1.2*/\
  PIN(1,3,2),/*P1.3*/\
  PIN(1,4,3),/*P1.4*/\
  PIN(1,5,4),/*P1.5*/\
        /*5   nRESET*/\
  PIN(3,2,6),/*P32*/\
  PIN(3,4,7),/*P3.4*/\
  PIN(3,5,8),/*P3.5*/\
  PIN(5,1,9),/*P5.1*/\
  PIN(5,0,10),/*P5.0*/\
        /*11 , VSS*/\
  PIN(2,4,12),/*P2.4*/\
  PIN(2,5,13),/*P2.5*/\
  /*PIN(4,6,14),P4.6*/\
  /*PIN(4,7,15),P4.7*/\
  PIN(0,7,16),/*P0.7*/\
  PIN(0,6,17),/*P0.6*/\
  PIN(0,5,18),/*P0.5*/\
  PIN(0,4,19) /*P0.4*/
        /*20 , VDD*/
#else /*used ICE*/
  #define CHIP_PIN_LIST \
  PIN(1,2,1),/*P1.2*/\
  PIN(1,3,2),/*P1.3*/\
  PIN(1,4,3),/*P1.4*/\
  PIN(1,5,4),/*P1.5*/\
        /*5   nRESET*/\
  PIN(3,2,6),/*P32*/\
  PIN(3,4,7),/*P3.4*/\
  PIN(3,5,8),/*P3.5*/\
  PIN(5,1,9),/*P5.1*/\
  PIN(5,0,10),/*P5.0*/\
        /*11 , VSS*/\
  PIN(2,4,12),/*P2.4*/\
  PIN(2,5,13),/*P2.5*/\
  PIN(4,6,14),/*P4.6*/\
  PIN(4,7,15),/*P4.7*/\
  PIN(0,7,16),/*P0.7*/\
  PIN(0,6,17),/*P0.6*/\
  PIN(0,5,18),/*P0.5*/\
  PIN(0,4,19) /*P0.4*/
        /*20 , VDD*/
#endif

#define   SS_PIN   P1_4
#define MOSI_PIN   P1_5
#define MISO_PIN   P1_6
#define  SCK_PIN   P1_7

#define  SDA_PIN  P3_4
#define  SCL_PIN  P3_5

#define A2 P1_2  
#define A3 P1_3
#define A4 P1_4
#define A5 P1_5

#endif
