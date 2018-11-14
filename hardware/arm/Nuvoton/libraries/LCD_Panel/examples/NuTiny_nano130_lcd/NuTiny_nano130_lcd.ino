/*
  NuTiny_nano130_lcd.ino:  LCD_Panel lib  template
  for NuTiny-EVB-Nano130-LQFQ128 board and LCD Panel uints
  LCDClass API:
     Init(): init lcd;
	   print(uint32_t  u32Zone, char *string) // Zone:0/1
	   putChar(uint32_t u32Zone, uint32_t u32Index, uint8_t u8Ch);
	   setSymbol(uint32_t u32Zone, uint32_t u32Index, uint32_t u32OnOff);
	   printNumber(uint32_t  u32Zone, long long value);

   huaweiwx@sina.com 2018.11..14
*/

#include "LCD_Panel.h"
LCDClass lcd;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.Init();
  lcd.print(0, "NUVOTON");
  lcd.print(1, "1234");
}

void loop() {
  digitalToggle(LED_BUILTIN);
  delay(500);
}
