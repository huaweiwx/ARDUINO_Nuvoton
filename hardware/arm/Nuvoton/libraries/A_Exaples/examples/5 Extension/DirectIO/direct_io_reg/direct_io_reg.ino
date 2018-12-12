/*
   direct_io_reg.ino

   attention:
      PAx...PHx or P0x...P7x is bitband registers for Nuvoton!
*/

#define ioPinNo   PA_0 /* PA_0 is arduino pin number */
#define ioPinReg  PA0  /* PA0 is  bitband register */

void setup() {
  pinMode(PA_0, OUTPUT);
}

void loop() {
  PA0 ^= 1;     // "toggle pin"
  delay(500);
}
