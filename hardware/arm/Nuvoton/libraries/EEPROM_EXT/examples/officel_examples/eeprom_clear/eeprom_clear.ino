/*
 * EEPROM Clear
 *
 * Sets all of the bytes of the EEPROM to 0.
 * Please see eeprom_iteration for a more in depth
 * look at how to traverse the EEPROM.
 *
 * This example code is in the public domain.
 */

#include "exteeprom.h"

void setup() {
  // initialize the LED pin as an output.
  pinMode(LED_BUILIN, OUTPUT);

/* for stl c++11/14 the begin/end is keywords for iteration. 
   while set USE_ITERATOR to 1 should be use  Init/deInit instead with them.
 */
#if USE_ITERATOR >0
  EEPROM.Init(); /* Init ExtEEPROM gpio */
#else
  EEPROM.begin(); /* Init ExtEEPROM gpio */
#endif
 
  /***
    Iterate through each byte of the EEPROM storage.

    Larger AVR processors have larger EEPROM sizes, E.g:
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb EEPROM storage.
    - Arduino Mega:       4kb EEPROM storage.

    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all AVR processors.
  ***/

  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }

  // turn the LED on when we're done
  digitalToggle(LED_BUILTIN);
}

void loop() {
  /** Empty loop. **/
}
