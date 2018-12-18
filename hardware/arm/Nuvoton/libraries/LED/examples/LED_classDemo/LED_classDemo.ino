#include <LED.h>
//example for LED lib  LEDClass application   by huawei<huaweiwx@sina.com> 2016.10.28

//LEDClass myLed;                  //init LEDClass myLed(default LED_BUILTIN)  HIGH ON;
LEDClass myLed(LED_BUILTIN, LOW);  //init LEDClass LeD(LED_BUILTIN, LOW)  LOW ON;

#ifdef LED1_BUILTIN
LEDClass myLed1(LED1_BUILTIN, LOW) ;   //init LEDClass Led2  LOW ON;
#endif

#ifdef LED2_BUILTIN
LEDClass myLed2(LED2_BUILTIN, LOW);   //init LEDClass Led3  LOW ON;
#endif


void setup() {
  //  put your setup code here, to run once:
  myLed.Init();

#ifdef LED1_BUILTIN
  myLed1.Init();
#endif

#ifdef LED2_BUILTIN
  myLed2.Init();
#endif
}

void loop() {
  // put your main code here, to run repeatedly:

  myLed.flash(10, 990, 1);

#ifdef LED1_BUILTIN
  myLed1.flash(10, 490, 2);
#endif

#ifdef LED2_BUILTIN
  myLed2.flash(10, 320, 3);
#endif
}