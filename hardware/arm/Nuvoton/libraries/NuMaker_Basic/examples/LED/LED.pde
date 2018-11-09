/*
  Dancing LED
  Turns on an LED1,LED2...LED8 on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
  LED1(34), It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
  LED2(35), It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
  LED3(36), It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
  LED4(37), It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
  LED5(38), It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
  LED6(26), It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
  LED7(27), It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
  LED8(29), It work for NuEdu-NUC240 and NuEdu-NANO130.
  
  Note: This sample does not support NuEdu-NUC131.
 */



#define lenPin 8
int led[]={34,35,36,37,38,26,27,29};  /* LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8 */

void setup() {
  int thisPin;
  for (thisPin =0; thisPin < lenPin; thisPin++) { 
    pinMode(led[thisPin], OUTPUT); 
  }
}

void loop() {
  // iterate over the pins:
  for (int thisPin =0; thisPin < lenPin; thisPin++) { 
    //The LEDs on thisPin from off to on:  
    digitalWrite(led[thisPin], HIGH);
    delay(100);
  }
  
  // iterate over the pins:
  for (int thisPin =0; thisPin < lenPin; thisPin++) { 
    //The LEDs on thisPin from on to off:
    digitalWrite(led[thisPin], LOW);
    delay(100);
  }  
}