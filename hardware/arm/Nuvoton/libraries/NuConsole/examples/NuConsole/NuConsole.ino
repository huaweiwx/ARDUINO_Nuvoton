/*
 * NuConsole.ino use nulink console i/o demo by huaweiwx@sina.com 2018.11.25
   
   1 menu Serial communication option selected NuConsole
   2 NuConsole_InfoBlock adress search the sketch map file in the sketch path
   3 run NuConsole and modify Info Block Address as NuConsole_InfoBlock address
   4 Click the [start] in NuConsole window;   
   5 at Transmit Text input your string and click Enter
   
*/

#include <NuConsole.h>

#include "BiLED.h"
#define BILEDPIN0 PB_4
#define BILEDPIN1 PB_5
BILEDClass myLED(BILEDPIN0, BILEDPIN1);

void setup() {
  myLED.Init();
  myLED = 1;
  Serial.begin();
}

uint16_t cnt= 0;
void loop() {
  /*write test*/
  Serial.print("hello ");
  Serial.println(cnt);

 /* dump test */ 
  while (Serial.available()) {
    char ch = Serial.read();
    Serial.write(ch);
  }

  myLED.toggle();
  delay(1000);
  cnt++;
}
