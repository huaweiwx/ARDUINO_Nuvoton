#include <LED.h>
#include <utils.h>
#include <Streaming.h>
//Led Led1 Led2 is predefined in LED.h

void setup() {
  //  put your setup code here, to run once:
  Serial.begin(115200);
  Led.Init();
  delay(1000);
  Serial << "chip info:\n";
  if (pChipInfo) {
    Serial  << " chip id: 0x" << _HEX(CHIP_ID) << "\n";
    Serial  << "  ramEnd: 0x" << _HEX(pChipInfo->ramEnd) << "\n";
    Serial  << "flashEnd: 0x" << _HEX(pChipInfo->flashEnd) << "\n";
    Serial  << "flashPPS: 0x" << _HEX(pChipInfo->flashPPS) << "\n";
    Serial  << "flashPS0: 0x" << _HEX(pChipInfo->flashPS[0]) << "\n";
  }
  Serial << "\nRST Source:\n";
  uint8_t rstsource = getRstSource();
  Serial <<  rstsource << "\n";
}

void loop() {
  // put your main code here, to run repeatedly:
    Led.fade();
}
