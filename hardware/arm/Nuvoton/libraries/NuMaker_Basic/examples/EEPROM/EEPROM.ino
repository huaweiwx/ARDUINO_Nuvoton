/*
		This sample code sets I2C bus clock to 100kHz. Then, accesses EEPROM 24LC64 with Byte Write
		and Byte Read operations, and check if the read data is equal to the programmed data.

		This example code is in the public domain.
*/

#include <EEPROM.h>

#define  USE_WARESOFT  0
#define AT24CXX_TYPE   AT24C02
#define AT24CXX_A2A1A0 0
//#define VCC_PIN    PA_8
//#define GND_PIN    PB_10

#if USE_WARESOFT >      0  /*use soft wire */
#include <WireSoft.h>
#define AT24CXX_SDA    PA_12
#define AT24CXX_SCL    PA_13
TwoWireSoft WARE(AT24CXX_SDA, AT24CXX_SCL) ;
EEPROMClass<TwoWireSoft> EEPROM(WARE);
#else /* use hard wire */
#include <Wire.h>
#define I2C_ROUTELOC  2
EEPROMClass<TwoWire>EEPROM(Wire);
//EEPROMClass<TwoWire>EEPROM(Wire1);
#endif


void setup()
{
#ifdef GND_PIN
  pinMode(GND_PIN, OUTPUT);
  digitalWrite(GND_PIN, LOW); /*GND*/
#endif
#ifdef VCC_PIN
  pinMode(VCC_PIN, OUTPUT);
  digitalWrite(VCC_PIN, HIGH); /*VCC.*/
  delay(1000);     /*wait for eeprom power ready*/
#endif

  Serial.begin(115200);

#if I2C_ROUTELOC >0
  Wire.setRouteLoc(I2C_ROUTELOC);
#endif
  EEPROM.Init();

  /* Programming EEPROM */
  for (int i = 0; i < 256; i++) {
    //    EEPROM.write(i,i);  /* Write EEPROM */
  }

  for (int i = 0; i < 256; i++) {
    int  rd = EEPROM.read(i);  /* Read EEPROM */
    Serial.print(rd);   /* print the reading */
    Serial.print("\t");
  }
}

void loop()
{
}
