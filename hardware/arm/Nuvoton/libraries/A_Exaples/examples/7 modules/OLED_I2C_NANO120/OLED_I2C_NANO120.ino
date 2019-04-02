// OLED_I2C_TinyFont_View
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// A quick demo of how to use my OLED_I2C library.
//
// To use the hardware I2C (TWI) interface of the Arduino you must connect
// the pins as follows:
//
// Arduino Uno/Leonardo/Mega/Due:
// ----------------------
// Display:  SDA pin   -> Arduino Analog 4 or the dedicated SDA pin
//           SCL pin   -> Arduino Analog 5 or the dedicated SCL pin
//
// The internal pull-up resistors will be activated when using the
// hardware I2C interfaces.
//
// You can connect the OLED display to any available pin but if you use
// any other than what is described above the library will fall back to
// a software-based, TWI-like protocol which will require exclusive access
// to the pins used, and you will also have to use appropriate, external
// pull-up resistors on the data and clock signals.
//

// add support ssd1306_12832 by huaweiwx@sina.com 2016.11.08
// class OLED_12832 128x32    OLED_12864 128x64
// OLED_128xx  myOLED(SDA, SCL);      //default unuse RST
// OLED_128xx  myOLED(SDA, SCL, RST); //use rst


/* OLED12864/32  检查你的连接接线，否则修改之
  OLED12864:        CS  RST   DC   D1(SDA)   D0(SCL)   VCC     GND
  NANO120   :      -    PC_7   -    PA_13     PA_12    33V     GND
  
  OLED12832:       SDA    SCL   RST   VCC    GND  
  NANO120    :     PC_6  PA_13 PA_12  33V    GND
*/

#include <OLED_I2C.h>

/*NANO120 define pins*/
#define  OLED  12864

#if OLED == 12832 //128x32 modules
  #define OLED_SDA PC_6
  #define OLED_SCL PA_13
  #define OLED_RES PA_12
  //#define OLED_VCC  33V
  //#define OLED_GND  GND
	OLED_12832  myOLED(OLED_SDA, OLED_SCL, OLED_RES);  //use soft i2c  12832
#else //128x64 modules
  #define OLED_RES  PC_7
  #define OLED_SDA PA_13
  #define OLED_SCL PA_12
   //#define OLED_VCC  33V
  //#define OLED_GND  GND
	OLED_12864  myOLED(OLED_SDA, OLED_SCL, OLED_RES);   //use soft i2c  12864
#endif

void setup()
{
#ifdef OLED_GND
  pinMode(OLED_GND, OUTPUT);
  digitalWriteLow(OLED_GND);
#endif
#ifdef OLED_VCC
  pinMode(OLED_VCC, OUTPUT);
  digitalWriteHigh(OLED_VCC);
#endif

  myOLED.begin();
  myOLED.setFont(SmallFont);   /* TinyFont / SmallFont /MediumNumbers / BigNumbers */

  myOLED.printxy("0123456789012345678", CENTER, 0);
  myOLED.printxy("abcdefghijklmno", CENTER,  8);
  myOLED.printxy("0123456789012345678", CENTER, 16);
  myOLED.printxy("abcdefghijklmno", CENTER,  24);
#if OLED == 12864  //128x64
  myOLED.printxy("0123456789012345678", CENTER, 32);
  myOLED.printxy("abcdefghijklmno", CENTER,  40);
  myOLED.printxy("0123456789012345678", CENTER, 48);
  myOLED.printxy("abcdefghijklmno", CENTER,  56);
#endif
  myOLED.update();
}

void loop()
{
}
