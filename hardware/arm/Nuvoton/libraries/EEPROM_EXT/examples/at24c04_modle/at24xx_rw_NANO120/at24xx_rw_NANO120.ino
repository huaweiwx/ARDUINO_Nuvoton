/*   at24cxx_rw_wire.ino  config and demo
     EEPROM is predefine instance of  EXTEEPROM class;
     1 check at24cxx chip connected info defined in file i2cEepromConfig.h. or redefined it in file HAL_Conf.h
     2 check and config in HAL_Conf.h
         use arduino streaming, set USE_ARDUINOSTREAMING to 1
         some external eeprom are not connected to any i2c port. we can  using a software emulate i2c port by set USE_WARESOFT to 1
         wire and wireSoft because EEPROM_EXT lib support stl and c++11/14 iteration, use Init/deInit instead of begin/end by set USE_ITERATOR to 1
     3 if not connected to any i2c port, set USE_WARESOFT to 1 using a software emulate i2c port.
  huawei huaweiwx@sina.com 2017.2.21
*/

#include "exteeprom.h"

void setup() {
#ifdef GND_PIN
  pinMode(GND_PIN, OUTPUT);
  digitalWrite(GND_PIN, LOW); /*GND*/
#endif
#ifdef VCC_PIN
  pinMode(VCC_PIN, OUTPUT);
  digitalWrite(VCC_PIN, HIGH); /*VCC.*/
  delay(1000);     /*wait for eeprom power ready*/
#endif

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  delay(1000);
#if  USE_WARESOFT
  Serial << "\nAT24CXX software I2C EEPROM RW DEM\n";
#else
  Serial << "\nAT24CXX hardware I2C EEPROM RW DEM\n";
  Wire.setRouteLoc(2);
#endif

  Serial << "Length = " << EEPROM.length() << " bytes\n";

  /*--------------------------------------------------------------------------
      for stl c++11/14 the begin/end is keywords for iteration.
      while set USE_ITERATOR to 1 should be use  Init/deInit instead with them.
    ----------------------------------------------------------------------------*/
  EEPROM.Init(); /* Init ExtEEPROM gpio */

  if ((EEPROM[0] != 0x55) || (EEPROM[1] != 0xaa)) {//write all eeprom with page number; run one times only
    EEPROM[0] = 0x55;
    EEPROM[1] = 0xaa;
    EEPROM[2] = AT24CXX_TYPE & 0xff;
    EEPROM[3] = AT24CXX_TYPE >> 8;      
    for (uint16_t i = 4; i < EEPROM.length(); i++) {
      EEPROM.write_byte(i, (uint8_t) i);   /*use write function*/
    }
  }
  char s[17] = {0};
  for (uint32_t  page = 0; page < EEPROM.length() / 256; page++) {
    Serial << "page: " << page + 1  <<  "/" <<  EEPROM.length() / 256 << " \n";
    for (auto i = 0; i < 16; i++) {
      uint16_t addr = page * 256 + i * 16;
      Serial << "addr(";
      if (page == 0 )   Serial  << "0";
      if (page < 0x10 ) Serial  << "0";
      if (addr == 0)    Serial  << "0";
      Serial << _HEX(addr) << ") ";
      for (auto j = 0; j < 16; j++) {

        //      uint8_t ch = EEPROM.read( i * 16 + j); /*use read function*/
        uint8_t ch = EEPROM[addr + j];             /*use iteration*/
        if ( ch < 16) Serial << "0";
        Serial << _HEX(ch) << "  ";

        if (isPrintable(ch)) s[j] = ch; /* ascii char  */
        else s[j] = '.';
      }
      Serial << s << "\n";
    }
    Serial << "\n";
  }
  Serial << "Dump complated!";
}

void loop() {
  digitalToggle(LED_BUILTIN);
  delay(500);           // wait 0.5 seconds for next toggle
}

