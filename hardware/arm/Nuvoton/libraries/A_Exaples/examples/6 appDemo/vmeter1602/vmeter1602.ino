/*
  vmeter1602.ino LiquidCrystal Library demo

  This sketch prints ADC to the LCD

  7/28/2018 by huaweiwx@sina.com
*/

#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = PC13,
          //          rw = PC14,
          en = PC15,
          d4 = PF2,
          d5 = PF3,
          d6 = PF4,
          d7 = PF5;

// OutputPin lcd_bkPin(PF6);

#define ADC_RENFERENCE  INTERNAL1V25  /* INTERNAL1V25/INTERNAL2V5/INTERNALVDD use 1.25V/2.5V/VDD3.3V  internal renference*/

typedef struct {
  uint8_t c;
  uint8_t l;
} pos_t;

#define CHS 4
uint8_t AIN[CHS] = {PC0, PC1, PC2, PC3}; /*ADC0/3/6/7*/
uint16_t Ax_MIN[CHS] = {0u, 0u, 0u, 0u};

#if ADC_RENFERENCE ==  INTERNAL1V25
uint16_t Ax_MAX[CHS] = {12500u, 12500u, 12500u, 12500u};  /*1.25v*/
#elif   ADC_RENFERENCE ==  INTERNAL2V5
uint16_t Ax_MAX[CHS] = {2500u, 2500u, 2500u, 2500u};      /*2.5v mage8*/
#else
uint16_t Ax_MAX[CHS] = {3300u, 3300u, 3300u, 3300u};     /*3.3v vcc*/
#endif

pos_t pos[CHS] = {
  {0, 0},
  {8, 0},
  {0, 1},
  {8, 1},
};

LiquidCrystal lcd(rs,   en, d4, d5, d6, d7);                   //4 bit mode,unused rwPin
//LiquidCrystal lcd(rs,rw,en, d4, d5, d6, d7);                   //4 bit mode
//LiquidCrystal lcd(rs,   en, d0, d1, d2, d3, d4, d5, d6, d7);   //8 bit mode, unused rwPin
//LiquidCrystal lcd(rs, rw, en, d0, d1, d2, d3, d4, d5, d6, d7); //8 bit mode

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  //  lcd_bkPin = HIGH; /*BK ON*/

  // Print a message to the LCD.
  // lcd.setCursor(2, 0);
  lcd.print("Vmeter 4CHs demo");
  lcd.setCursor(1, 1);
  lcd.print("Renference:");

#if  ADC_RENFERENCE ==  INTERNAL1V25
  lcd.print("1.25V");
#elif ADC_RENFERENCE ==  INTERNAL2V5
  lcd.print("2.5V");
#else
  lcd.print(" VDD");
#endif

  delay(2000);
  lcd.clear();
  analogReference(ADC_RENFERENCE);
}

void loop() {
  uint16_t V[CHS];

  for (int8_t j = 0; j < CHS; j++) {
    V[j] = analogRead(AIN[j]);
    V[j] = 0;

    for (uint8_t i = 0; i < 16; i++) {
      V[j]  += analogRead(AIN[j]);
    }

    V[j] = map( V[j], Ax_MIN[j], (uint32_t)4095 * 16, 0, Ax_MAX[j]);

    lcd.setCursor(pos[j].c, pos[j].l);
    lcd.print(j); lcd.print(": ");
    if (V[j] > (Ax_MAX[j] - 3))
      lcd.print(" OVL");
    else {
      if (V[j] < 1000) lcd.print(" ");
      if (V[j] < 100)  lcd.print(" ");
      if (V[j] < 10)   lcd.print(" ");
      lcd.print(V[j]);
    }
  }
  delay(500);
}
