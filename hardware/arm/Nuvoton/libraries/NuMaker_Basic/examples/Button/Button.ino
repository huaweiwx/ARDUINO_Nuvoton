/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 LED1 is light, when pressing a pushbutton attached to SW1. It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
 LED3 is light, when pressing a pushbutton attached to SW2. It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
 LED5 is light, when pressing a pushbutton attached to SW3. It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
 LED7 is light, when pressing a pushbutton attached to SW4. It work for NuEdu-NUC240, NuEdu-NANO130 and NuEdu-M451.
 
 Note: This sample does not support NuEdu-NUC131.
 
 This example code is in the public domain.
 
 */

// constants won't change. They're used here to 
// set pin numbers:
#define NUM 4
const int buttonPin[NUM] = {44, 39, 24, 25 };     // the number of the pushbutton pin,  SW1, SW2, SW3, SW4
const int ledPin[NUM]    = {34, 36, 38, 27 };     // the number of the LED pin, LED1, LED3, LED5, LED7

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  for(int i=0;i<NUM;i++)
   pinMode(ledPin[i], OUTPUT);      
  // initialize the pushbutton pin as an input:
  for(int i=0;i<NUM;i++)
    pinMode(buttonPin[i], INPUT);     
}

void loop(){
  // read the state of the pushbutton value:
   for(int i=0;i<NUM;i++)
   {
      buttonState = digitalRead(buttonPin[i]);
    
      // check if the pushbutton is pressed.
      // if it is, the buttonState is HIGH:
      if (buttonState == HIGH) {     
        // turn LED on:    
        digitalWrite(ledPin[i], HIGH);  
      } 
      else {
        // turn LED off:
        digitalWrite(ledPin[i], LOW); 
      }
  }
}