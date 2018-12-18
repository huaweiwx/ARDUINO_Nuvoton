#include <LED.h>

//Led is predefined in LED.h

void setup() {
  //  put your setup code here, to run once:
  Led.Init();
}

void loop() {
  Led = 1;
  delay(500);
  Led = 0;
  delay(500); 
}
