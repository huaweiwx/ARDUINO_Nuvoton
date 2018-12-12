/*
  adcDiffRead.ino  efm32adc differential read demo
     ADC class func list:
         ADC adcinstence         : creat a ADC instance,  adc is predefined
         resolution(res)         :set resolution
         getResolution()         :get resolution
         reference(int ref)      :set reference
         getReference()          :get reference
         read(pin1, pin2)        ;pin2 default is NOT_A_PIN,SingleInput else deffInput mode
         readTemp()              :read internal temperature ADC value;
         temperatureCelsius()    :temperature degree celsius;
         temperatureFahrenheit() :temperature degree fahrenheit;

    This example code is in the public domain.
    huaweiwx@sina.com 2018.8
*/

void setup() {
   pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);

  adc.reference(INTERNAL2V5); /* setup ADC reference INTERNAL1V25/INTERNAL2V5/INTERNAL3V3*/
}

// the loop function runs over and over again forever
void loop() {
  digitalToggle(LED_BUILTIN);   // turn the LED on (HIGH is the voltage level)
#if defined(A4 )&& defined(A5)  /* adc channel see datasheet */
  Serial.print("ADC differential ch4 ch5 read:");
  Serial.println(adc.read(A4, A5));
#else
  Serial.print("ADC differential ch6 ch7 read:");
  Serial.println(adc.read(A6, A7));
#endif
  delay(2000);  // wait for 2 seconds
}
