/*
  temperatureSensor.ino   read chip temperature Sensor value
  use extension temperatureFahrenheit and temperatureCelsius get the temperature and prints it to the Serial Monitor or plotter
  This example code is in the public domain.
  huaweiwx@sina.com 2018.9.18
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  //  adc.reference(INTERNAL2V5); /* setup ADC reference INTERNAL1V25/INTERNAL2V5/INTERNAL3V3*/
}

// the loop function runs over and over again forever
void loop() {
  digitalToggle(LED_BUILTIN);   // turn the LED on (HIGH is the voltage level)
  // int tempval = adc.readTemp();
#if 1  /*set 0  use plotter */
/* serial output temperature */
  Serial.print("Read internal temperature :");
  float temp = adc.temperatureFahrenheit();
  Serial.print(temp);
  Serial.print("F (");
  temp = adc.temperatureCelsius();
  Serial.print(temp);
  Serial.println("C)");
  delay(2000);                  // wait for 2 seconds
 #else
 /*plotter temperature curver*/
   Serial.println(adc.temperatureCelsius());
   delay(100);
 #endif
}
