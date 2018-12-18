/* vdos_spisdcard.ino stm32 vdisk/mcu administer
    ---------------------------------------------------------------------------------------
   from the menu
   Select Startup adr: flash(WhitRamboo xxkRAM used only)
   ---------------------------------------------------------------------------------------
   cmd usage:
   type help or h or ? for Display list of commands.

   ---------------------------------------------------------------------------------------
   tested for F103xE/F407xE  by huaweiwx@sina.com 2017.10

   ---------------------------------------------------------------------------------------
*/
#if  USE_SPISDCARD > 0
#	include <SD.h>
#	include "configs/sdCardConfig.h"
File root;
#elif  USE_SDIOSDCARD > 0
#include <STM32SD.h>
File root;
#elif  USE_SERIALFLASH >0
#include <SerialFlash.h>
#endif

#if USE_FILESYSTEM > 0

uint8_t vdos_init (void) {
  static  uint8_t  inited = 0;
  if (inited) return 0;
  Serial << "vdisk init...";

#if  USE_SERIALFLASH >0
  if (!SerialFlash.begin()) {
    Serial << "\nUnable to access SPI Flash chip\n";
    return 1;
  } else {
    inited = 1;
    Serial.println("ok");
    return 0;
  }
#elif  (USE_SPISDCARD > 0)
  if (!SD.begin(SDCARD_CS)) {
    Serial << "\nUnable to access SPI Flash chip\n";
    return 1;
  } else {
    inited = 1;
    Serial.println("ok");
    return 0;
  }
#elif  (USE_SDIOSDCARD > 0)

  for (uint8_t i = 0; i < 5; i++) {
#ifdef   SD_DETECT_PIN
    if (SD.begin(SD_DETECT_PIN) != TRUE)
#else
    if (SD.begin() != TRUE)
#endif
    {
      Led.flash(10, 190, 1);
    } else {
      inited = 1;
      Serial.println("ok");
      return 0;
    }
  }
  return 1;
#endif
}

#if  USE_SERIALFLASH >0
void spaces(int num) {
  for (int i = 0; i < num; i++) {
    Serial.print(" ");
  }
}

SerialFlashFile vdos_openfile(char* filename)
{
  SerialFlashFile f = SerialFlash.open(filename);
  return f;
}
#else
File vdos_openfile(char* filename, uint8_t oflag)
{
  File f =  SD.open(filename, oflag);
  return f;
}
#endif

#if  (USE_SPISDCARD > 0)
void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

#endif
void vdos_listFiles(void) {
  if (vdos_init ()) {
    Serial.println("vdisk init failure");
    return;
  }
  Serial << "ls files:\n";
#if USE_SERIALFLASH >0
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
  root = SD.open("/");
  printDirectory(root, 0);
#elif  (USE_SDIOSDCARD > 0)
  root = SD.openRoot();
  root.ls(LS_R | LS_DATE | LS_SIZE);
  root.close();
#endif
}


#if portINFO >0
# if  USE_SPISDCARD > 0
#   pragma message "vdos use SPI SDCARD."
# elif USE_SDIOSDCARD > 0
#   pragma message "vdos use SDIO SDCARD."
# elif USE_SPIFLASH > 0
#   pragma message "vdos use Serial flash."
# endif
#endif /* portINFO>0 */

#endif /*USE_FILESYSTEM*/

