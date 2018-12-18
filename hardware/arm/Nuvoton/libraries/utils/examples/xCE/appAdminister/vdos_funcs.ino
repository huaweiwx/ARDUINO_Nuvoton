/* vdos_funcs.ino stm32 vdisk/mcu vdos functions
   by huaweiwx@sina.com  2018.8.28
   ---------------------------------------------------------------------------------------
*/
#if  USE_SPISDCARD > 0
#	include <SPI.h>
#	include <SD.h>
#	include "configs/sdCardConfig.h"
SdFile root;
#elif  USE_SDIOSDCARD > 0
#   include <STM32SD.h>
File root;
#elif  USE_SPIFLASH > 0
#    include <SerialFlash.h>
static void spaces(int num) {
  for (int i = 0; i < num; i++) {
    Serial.print(" ");
  }
}
#endif

#if USE_FILESYSTEM > 0
void vdos_listFiles(void) {
#if  USE_SPIFLASH > 0
  SerialFlash.opendir();
  uint8_t count = 0;
  while (1) {
    char filename[64];
    uint32_t filesize;
    if (SerialFlash.readdir(filename, sizeof(filename), filesize)) {
      count++;
      Serial.print("  ");
      Serial.print(filename);
      spaces(20 - strlen(filename));
      Serial.print("  ");
      Serial.print(filesize);
      Serial.print(" bytes");
      Serial.println();
    } else {
      break; // no more files
    }
  }
  Serial.print("fond ");
  Serial.print(count);
  Serial.println(" files");
#elif  (USE_SPISDCARD > 0)
  root.ls(LS_R | LS_DATE | LS_SIZE);
  root.close();
#elif  (USE_SDIOSDCARD > 0)
  root = SD.openRoot();
  root.ls(LS_R | LS_DATE | LS_SIZE);
  root.close();
#endif
}

#if  USE_SPIFLASH > 0
SerialFlashFile vdos_openfile(char* filename, uint8_t oflag) {
  return SerialFlash.open(filename);
}
#else
File vdos_openfile(char* filename, uint8_t oflag)
{
  File f;
  f = SD.open(filename, oflag);
  return f;
}
#endif //USE_SPIFLASH > 0

#if portINFO >0
# if  USE_SPISDCARD > 0
#   pragma message "vdos use SPI SDCARD."
# elif USE_SDIOSDCARD > 0
#   pragma message "vdos use SDIO SDCARD."
# elif USE_SPIFLASH > 0
#   pragma message "vdos use Serial flash."
# endif
#endif /* portINFO>0 */

#endif /* USE_FILESYSTEM>0 */
