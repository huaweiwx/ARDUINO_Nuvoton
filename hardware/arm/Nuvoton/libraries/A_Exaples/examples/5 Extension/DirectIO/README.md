# EFM32 ARDUINO  ARM EXTENSION
  arduino arm extension.

## DIRECTIO
   efm32/stm32  class LL_PIN is built in and GPIOPIN is it's an alias.
   OutputPin and  InputPin is a derived class of LL_PIN.
### LL_PIN class
  creat example:
    LL_PIN  myLed(PA5); 
    or GPIOPIN  myLed(PA5); 
  
api:

* **`void high()`**: pin out high.
* **`void low()`** : pin out low.
* **`void write(bool b)`**: pin out high or low.
* **`bool read(void)`**: read pin.

