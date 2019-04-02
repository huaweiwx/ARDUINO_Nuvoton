/*
		This sample code sets I2C bus clock to 100kHz. Then, accesses EEPROM 24C32 with Byte Write
		and Byte Read operations, and check if the read data is equal to the programmed data.

		This example code is in the public domain.
*/
#include <EEPROM.h>

#define  USE_WARESOFT  0
#define AT24CXX_TYPE   AT24C32
#define AT24CXX_A2A1A0 0

//#define VCC_PIN      PA_10
//#define GND_PIN      PA_11

#if USE_WARESOFT >     0                   /*use soft wire test*/
  #include <WireSoft.h>
  #define AT24CXX_SDA    PA_12
  #define AT24CXX_SCL    PA_13
  TwoWireSoft WARE(AT24CXX_SDA, AT24CXX_SCL) ;
  EEPROMClass<TwoWireSoft> EEPROM(WARE);
#else                                       /* use hard wire test*/
  #include <Wire.h>
  #define I2C_ROUTELOC  2
  EEPROMClass<TwoWire>EEPROM(Wire);
  //EEPROMClass<TwoWire>EEPROM(&Wire1);
#endif

void setup(){
#ifdef GND_PIN
  pinMode(GND_PIN, OUTPUT);
  digitalWrite(GND_PIN, LOW);  /*GND*/
#endif
#ifdef VCC_PIN
  pinMode(VCC_PIN, OUTPUT);
  digitalWrite(VCC_PIN, HIGH); /*VCC*/
  delay(1000);     /*wait for eeprom power ready*/
#endif

  Serial.begin(115200);

#if I2C_ROUTELOC >0
  Wire.setRouteLoc(I2C_ROUTELOC);
#endif
  EEPROM.Init();

  /* Programming EEPROM */
  int reading;
  for (int i = 0; i < 256; i++)  {
    //    EEPROM.write(i,i);  /* Write EEPROM */
  }

  for (int i = 0; i < 256; i++) {
    reading = EEPROM.read(i);  /* Read EEPROM */
    Serial.print(reading);   /* print the reading */
    Serial.print("\t");
  }
}

void loop(){
}
