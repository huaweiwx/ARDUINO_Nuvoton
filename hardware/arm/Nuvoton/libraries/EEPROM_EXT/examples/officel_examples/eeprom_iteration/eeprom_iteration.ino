/***
    eeprom_iteration example.

  for stl begin/end is keywords for iteration
  this demo use begin() and end(), must be set the  USE_ITERATOR to  1
  lib WARE/SOFTWARE use Init/deInit instead of begin/end

  #define  USE_ITERATOR  1

    A set of example snippets highlighting the
    simplest methods for traversing the EEPROM.

    Running this sketch is not necessary, this is
    simply highlighting certain programming methods.

    Written by Christopher Andrews 2015
    Released under MIT licence.
***/
#include "exteeprom.h"

/* check config */
#if USE_ITERATOR == 0
#error "! must set USE_ITERATOR to 1, enable EEPROM use iteration ! "
#endif

void setup() {

  /***
    Iterate the EEPROM using a for loop.
  ***/
  /*
    for stl begin/end is keywords for iteration
    if set USE_ITERATOR, arduino lib SPI/SOFTSPI/WARE/SOFTWARE use Init/deInit instead of begin/end
  */
#define  USE_ITERATOR  1
  EEPROM.Init(); /* Init ExtEEPROM gpio */

  for (auto index = EEPROM.begin() ; index < EEPROM.end() ; index++) {
    //Add one to each cell in the EEPROM
    EEPROM[ index ] += 1;
  }

  /***
    Iterate the EEPROM using a while loop.
  ***/

  int index = 0;

  while (index < EEPROM.end()) {

    //Add one to each cell in the EEPROM
    EEPROM[ index ] += 1;
    index++;
  }

  /***
    Iterate the EEPROM using a do-while loop.
  ***/

  int idx = 0;  //Used 'idx' to avoid name conflict with 'index' above.

  do {
    //Add one to each cell in the EEPROM
    EEPROM[ idx ] += 1;
    idx++;
  } while (idx < EEPROM.end());


} //End of setup function.

void loop() {}
