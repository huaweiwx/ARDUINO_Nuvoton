//
//  at24cxx_rw_wire.ino
//  huawei huaweiwx@sina.com 2017.2.21
//
#include "at24cxx.h"

//my vct6 board config, check and fix me

#define EE_SDA     AT24CXX_SDA
#define EE_SCL     AT24CXX_SCL
#define EE_TYPE    AT24CXX_TYPE

#define	EE_ADR  0x50    //Address A2A1A0=000

//EXTEEPROM  myeeprom(EE_SDA, EE_SCL,EE_ADR, EE_TYPE);
EXTEEPROM  myeeprom(EE_SDA, EE_SCL,EE_ADR, EE_TYPE);

inline int EERef::read_byte(int index) {
  return myeeprom.read_byte((uint16_t)index);
}
inline void EERef::write_byte(int index, uint8_t val) {
  return myeeprom.write_byte((uint16_t)index, val);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nAT24CXX RW");
  myeeprom.Init(); //

//write test
#if 0  /* write all eeprom with page number; run one times only */
  for (uint16_t i = 0; i < 256; i++) {
    myeeprom[i] = i;
  }
#endif

//read test
  for (uint16_t i = 0; i < 16; i++) {
    for (uint16_t j = 0; j < 16; j++) {
      uint8_t ch = myeeprom[ i * 16 + j];
      if ( ch < 16) Serial << "0";
      Serial << _HEX(ch) << "  ";
    }
    Serial << "\n";
  }
  Serial << "EEPROM read ok\n\n";
}

void loop() {
  digitalToggle(LED_BUILTIN);
  delay(500);
}

