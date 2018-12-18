#include <LED.h>

//Led is predefined in LED.h

void setup() {
  //  put your setup code here, to run once:
  Led.Init();
}

void loop() {
  Led.toggle();
  delay(500);
}
