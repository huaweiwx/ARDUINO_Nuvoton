/*
  avr_emulation.ino: avr registers PORTx PINx DDRx emulation demo
  efm32g222f128 LED_BUILTIN is PD6
  EFM32/STM32/Nuvoton  avr emulation is build in; huaweiwx@sina.com 2018.8.10
*/

#define LED_DDR   DDRD
#define LED_PORT  PORTD
#define pinMask   bit(6)

void setup() {
  LED_DDR |= pinMask; // set PD6  OUTPUT,  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
#if 1
  LED_PORT ^=  pinMask;   /* PD6 toggle */
  delay(1000);
#else
  LED_PORT |=  pinMask;   /* PD6 set   */
  delay(500);
  LED_PORT &= ~pinMask;   /* PD6 clear */
  delay(500);
#endif
}

