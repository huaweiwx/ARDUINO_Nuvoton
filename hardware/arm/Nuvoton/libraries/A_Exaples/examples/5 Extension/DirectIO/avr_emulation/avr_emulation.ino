/*
  avr_emulation.ino: avr registers PORTx PINx DDRx emulation demo
  NANO120KD2 board LED_BUILTIN is PE_6
  EFM32/STM32/Nuvoton  avr emulation is build in; huaweiwx@sina.com 2018.8.10
*/

#define LED_DDR   DDRE
#define LED_PORT  PORTE
#define pinMask   bit(6)

void setup() {
  LED_DDR |= pinMask; // set PE_6  OUTPUT,  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
#if 1
  LED_PORT ^=  pinMask;   /* PE_6 toggle */
  delay(1000);
#else
  LED_PORT |=  pinMask;   /* PE_6 set   */
  delay(500);
  LED_PORT &= ~pinMask;   /* PE_6 clear */
  delay(500);
#endif
}

