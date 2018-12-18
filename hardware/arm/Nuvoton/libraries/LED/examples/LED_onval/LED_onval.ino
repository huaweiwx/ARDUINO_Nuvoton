/*
 Led_onval.ino
   The on(val) function example shows how to  analogWrite val to LED pin

 This example code is in the public domain.
 */
 
#include <LED.h>

//Led is predefined in LED.h

void setup() {
  //  put your setup code here, to run once:
  Led.Init();
}

void loop() {  
  for(int i=0;i<256;i+=5){
    Led.on(i);                
    delay(100);
  }
  for(int i=255;i>=0;i-=5){
    Led.on(i);
    delay(100);
  }
}
