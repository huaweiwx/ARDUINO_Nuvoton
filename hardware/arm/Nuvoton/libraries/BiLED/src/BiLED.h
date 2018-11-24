#include "Arduino.h"

#ifndef ARDUINOPIN_TypeDef
#define ARDUINOPIN_TypeDef  uint8_t
#endif

class BILEDClass
{
  public:
    BILEDClass(ARDUINOPIN_TypeDef bPin0, ARDUINOPIN_TypeDef bPin1)
	                      : bPin0(bPin0),             bPin1(bPin1) {}

    ARDUINOPIN_TypeDef bPin0;
    ARDUINOPIN_TypeDef bPin1;

    ~BILEDClass() {
      deInit();
    }

    inline void Init(void) {
      pinMode(bPin0.ucPin, OUTPUT);
      pinMode(bPin1.ucPin, OUTPUT);
    }

    inline void deInit(void) {
      pinMode(bPin0, INPUT);
      pinMode(bPin1, INPUT);
    }

    uint8_t read(void) {
      uint8_t rtn = 0;
      if (digitalRead(bPin0)) rtn |=  bit(0);
      if (digitalRead(bPin1)) rtn |=  bit(1);
      return rtn;
    }

    inline void write(uint8_t val) {
      digitalWrite(bPin0, bitRead(val, 0));
      digitalWrite(bPin1, bitRead(val, 1));
    }

    inline void toggle(void) {
      digitalToggle(bPin0);
      digitalToggle(bPin1);
    }

    inline void off() {
      digitalWrite(bPin0, LOW);
      digitalWrite(bPin1, LOW);
    }

    inline void on(uint8_t val = 1) {
      write(val);
    }

    inline operator uint8_t () {
      return read();
    }

    template<typename T>
    inline BILEDClass & operator = (T value) {
      write(value);
      return *this;
    }

};
