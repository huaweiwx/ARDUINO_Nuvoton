/*
   direct_io.ino
   efm32/stm32  class LL_PIN is built in and GPIOPIN is it's an alias.
   OutputPin and  InputPin is a derived class of LL_PIN.
   avr series included in the DirectIO lib

   class func list:
     void high()       output high
     void low()        output low
     void toggle()     output toggle
     void write(boll)  output h/l
     bool read()       intput pin
     void pulse()      output a pulse
     uint8_t pulseIn() Get the pulse width
     operate =         output h/l
     operate ()        input bool
*/


//Check the Environment
#if ARDUINO_EXTEND > 0
OutputPin pin(LED_BUILTIN);

#elif defined(__AVR__)
#include <DirectIO.h>
Output<13> pin;

#else
#error "un supported"
#endif

void setup() {}

void loop() {
#if 1
  pin = HIGH;
  delay(500);
  pin = LOW;
  delay(500);
#else
  pin.toggle();
  delay(500);
#endif
}

