#include <LED.h>

//Led is predefined in LED.h

void setup() {
  //  put your setup code here, to run once:
  Led.Init();
}

void loop() {
  Led.on();
  delay(500);
  Led.off();
  delay(500); 
}
