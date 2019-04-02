// An example of the SdFatSoftSpi template class.
// This example is for an Adafruit Data Logging Shield on a Mega.
// Software SPI is required on Mega since this shield connects to pins 10-13.
// This example will also run on an Uno and other boards using software SPI.
//
#include <SPI.h>
#include "SdFat.h"

#if ENABLE_SOFTWARE_SPI_CLASS  // Must be set in SdFat/SdFatConfig.h or HAL_Conf.h
  // Chip select may be constant or RAM variable.
  // Pin numbers in templates must be constants.
#define  SOFT_MISO_PIN       PC_7
#define  SOFT_SCK_PIN        PC_6
#define  SOFT_MOSI_PIN       PA_13
#define  SD_CHIP_SELECT_PIN  PA_12
//#define  VCC_PIN PA_0
//#define  GND_PIN PA_1
  
  // SdFat software SPI template
  SdFatSoftSpi<SOFT_MISO_PIN, SOFT_MOSI_PIN, SOFT_SCK_PIN> sd;

#else  // ENABLE_SOFTWARE_SPI_CLASS
# error ENABLE_SOFTWARE_SPI_CLASS must be set non-zero in SdFat/SdFatConfig.h
#endif  //ENABLE_SOFTWARE_SPI_CLASS//

// Test file.
SdFile file;

void setup() {
#ifdef    GND_PIN
  pinMode(GND_PIN, OUTPUT);
  digitalWrite(GND_PIN, LOW);
#endif
#ifdef    VCC_PIN
  pinMode(VCC_PIN, OUTPUT);
  digitalWrite(VCC_PIN, HIGH);
#endif

  Serial.begin(115200);
  // Wait for USB Serial 
  while (!Serial) {
    SysCall::yield();
  }
  delay(1000);

  Serial.println("Type any character to start");
  while (!Serial.available()) {
    SysCall::yield();
  }

  if (!sd.begin(SD_CHIP_SELECT_PIN)) {
    sd.initErrorHalt();
  }

  if (!file.open("SoftSPI.txt", O_CREAT | O_RDWR)) {
    sd.errorHalt(F("open failed"));
  }
  file.println(F("This line was printed using software SPI."));

  file.rewind();
  
  while (file.available()) {
    Serial.write(file.read());
  }

  file.close();

  Serial.println(F("Done."));
}
//------------------------------------------------------------------------------
void loop() {}
