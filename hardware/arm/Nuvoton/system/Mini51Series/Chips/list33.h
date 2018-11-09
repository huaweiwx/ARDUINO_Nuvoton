#ifndef _CHIP32_PINLIST_H_
#define _CHIP32_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
  PIN(1,5,1),/*P1.5*/\
        /*2   nRESET*/\
  PIN(3,0,3),/*P3.0*/\
  PIN(5,4,4),/*P5.4*/\
  PIN(3,1,5),/*P3.1*/\
  PIN(3,2,6),/*P3.2*/\
  PIN(3,4,7),/*P3.4*/\
  PIN(3,5,8),/*P3.5*/\
  PIN(3,6,9),/*P3.6*/\
  PIN(5,1,10),/*P5.1*/\
  PIN(5,0,11),/*P5.0*/\
        /*12 , VSS*/\
  PIN(5,2,13),/*P5.2*/\
  PIN(2,2,14),/*P2.2*/\
  PIN(2,3,15),/*P2.3*/\
  PIN(2,4,16),/*P2.4*/\
  PIN(2,5,17),/*P2.5*/\
  PIN(2,6,18),/*P2.6*/\
  /*PIN(4,6,19),P4.6*/\
  /*PIN(4,7,20),P4.7*/\
  PIN(0,7,21),/*P0.7*/\
  PIN(0,6,22),/*P0.6*/\
  PIN(0,5,23),/*P0.5*/\
  PIN(0,4,24), /*P0.4*/\
  PIN(0,1,25), /*P0.1*/\
  PIN(0,0,26),/*P0.0*/\
  PIN(5,3,27),/*P5.3*/\
        /*28 , VDD*/  \
  PIN(1,0,29),/*P1.0*/\
  PIN(1,2,30),/*P1.2*/\
  PIN(1,3,31),/*P1.3*/\
  PIN(1,4,32) /*P1.4*/

#else /*used ICE*/

  #define CHIP_PIN_LIST \
  PIN(1,5,1),/*P1.5*/\
        /*2   nRESET*/\
  PIN(3,0,3),/*P3.0*/\
  PIN(5,4,4),/*P5.4*/\
  PIN(3,1,5),/*P3.1*/\
  PIN(3,2,6),/*P3.2*/\
  PIN(3,4,7),/*P3.4*/\
  PIN(3,5,8),/*P3.5*/\
  PIN(3,6,9),/*P3.6*/\
  PIN(5,1,10),/*P5.1*/\
  PIN(5,0,11),/*P5.0*/\
        /*12 , VSS*/\
  PIN(5,2,13),/*P5.2*/\
  PIN(2,2,14),/*P2.2*/\
  PIN(2,3,15),/*P2.3*/\
  PIN(2,4,16),/*P2.4*/\
  PIN(2,5,17),/*P2.5*/\
  PIN(2,6,18),/*P2.6*/\
  PIN(4,6,19),/*P4.6*/\
  PIN(4,7,20),/*P4.7*/\
  PIN(0,7,21),/*P0.7*/\
  PIN(0,6,22),/*P0.6*/\
  PIN(0,5,23),/*P0.5*/\
  PIN(0,4,24), /*P0.4*/\
  PIN(0,1,25), /*P0.1*/\
  PIN(0,0,26),/*P0.0*/\
  PIN(5,3,27),/*P5.3*/\
        /*28 , VDD*/  \
  PIN(1,0,29),/*P1.0*/\
  PIN(1,2,30),/*P1.2*/\
  PIN(1,3,31),/*P1.3*/\
  PIN(1,4,32) /*P1.4*/

#endif

#define   SS_PIN   P1_4
#define MOSI_PIN   P1_5
#define MISO_PIN   P1_6
#define  SCK_PIN   P1_7

#define  SDA_PIN  P3_4
#define  SCL_PIN  P3_5


static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;


#endif
