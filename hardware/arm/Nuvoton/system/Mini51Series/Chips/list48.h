#ifndef _CHIP48_PINLIST_H_
#define _CHIP48_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
        /*1    NC  */\
  PIN(1,5,2),/*P1.5*/\
        /*3   nRESET*/\
  PIN(3,0,4),/*P3.0*/\
        /*5   AVCC */\
  PIN(5,4,6),/*P5.4*/\
  PIN(3,1,7),/*P3.1*/\
  PIN(3,2,8),/*P3.2*/\
  PIN(3,4,9),/*P3.4*/\
  PIN(3,5,10),/*P3.5*/\
        /*11   NC  */\
        /*12   NC  */\
        /*13   NC  */\
  PIN(3,6,14),/*P3.6*/\
  PIN(5,1,15),/*P5.1*/\
  PIN(5,0,16),/*P5.0*/\
        /*17 , VSS*/\
        /*18 , LDOCAP*/\
  PIN(5,5,19),/*P5.5*/\
  PIN(5,2,20),/*P5.2*/\
        /*21   NC  */\
  PIN(2,2,22),/*P2.2*/\
  PIN(2,3,23),/*P2.3*/\
  PIN(2,4,24),/*P2.4*/\
  PIN(2,5,25),/*P2.5*/\
  PIN(2,6,26),/*P2.6*/\
        /*27   NC  */\
        /*28   NC  */\
  PIN(4,6,29),/*P4.6*/\
  PIN(4,7,30),/*P4.7*/\
        /*31   NC  */\
  PIN(0,7,32),/*P0.7*/\
  PIN(0,6,33),/*P0.6*/\
  PIN(0,5,34),/*P0.5*/\
  PIN(0,4,35), /*P0.4*/\
        /*36    NC  */\
  PIN(0,1,37),  /*P0.1*/\
  PIN(0,0,38),/*P0.0*/\
        /*39    NC  */\
        /*40    NC  */\
  PIN(5,3,41),/*P5.3*/\
        /*42 ,  VDD*/ \
        /*43 ,  AVDD*/ \
  PIN(1,0,44),/*P1.0*/\
  PIN(1,2,45),/*P1.2*/\
  PIN(1,3,46),/*P1.3*/\
  PIN(1,4,47) /*P1.4*/
        /*48    NC  */

#else /*used ICE*/

  #define CHIP_PIN_LIST \
        /*1    NC  */\
  PIN(1,5,2),/*P1.5*/\
        /*3   nRESET*/\
  PIN(3,0,4),/*P3.0*/\
        /*5   AVCC */\
  PIN(5,4,6),/*P5.4*/\
  PIN(3,1,7),/*P3.1*/\
  PIN(3,2,8),/*P3.2*/\
  PIN(3,4,9),/*P3.4*/\
  PIN(3,5,10),/*P3.5*/\
        /*11   NC  */\
        /*12   NC  */\
        /*13   NC  */\
  PIN(3,6,14),/*P3.6*/\
  PIN(5,1,15),/*P5.1*/\
  PIN(5,0,16),/*P5.0*/\
        /*17 , VSS*/\
        /*18 , LDOCAP*/\
  PIN(5,5,19),/*P5.5*/\
  PIN(5,2,20),/*P5.2*/\
        /*21   NC  */\
  PIN(2,2,22),/*P2.2*/\
  PIN(2,3,23),/*P2.3*/\
  PIN(2,4,24),/*P2.4*/\
  PIN(2,5,25),/*P2.5*/\
  PIN(2,6,26),/*P2.6*/\
        /*27   NC  */\
        /*28   NC  */\
  /*PIN(4,6,29),P4.6*/\
  /*PIN(4,7,30),P4.7*/\
        /*31   NC  */\
  PIN(0,7,32),/*P0.7*/\
  PIN(0,6,33),/*P0.6*/\
  PIN(0,5,34),/*P0.5*/\
  PIN(0,4,35), /*P0.4*/\
        /*36    NC  */\
  PIN(0,1,37),  /*P0.1*/\
  PIN(0,0,38),/*P0.0*/\
        /*39    NC  */\
        /*40    NC  */\
  PIN(5,3,41),/*P5.3*/\
        /*42 ,  VDD*/ \
        /*43 ,  AVDD*/ \
  PIN(1,0,44),/*P1.0*/\
  PIN(1,2,45),/*P1.2*/\
  PIN(1,3,46),/*P1.3*/\
  PIN(1,4,47) /*P1.4*/
        /*48    NC  */

#endif

#define   SS_PIN   P1_4
#define MOSI_PIN   P1_5
#define MISO_PIN   P1_6
#define  SCK_PIN   P1_7

#define  SDA_PIN  P3_4
#define  SCL_PIN  P3_5
#endif


static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;

#endif