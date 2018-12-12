/*
  gpio_speedTest.ino arduino gpio speed test example for nuvoton

   mode 3:  use avr emulate;
   mode 2:  use LL_PIN class
   mode 1:  cplus mode
   mode 0:  c mode

   F_CPU at 48 mHz NANO120KD2 
    read speed:    mode3   2331khz  429us in avr emulate
                   mode1/2  904khz 1106us in cplus and  LL_PIN
                   mode0    635khz 1573us in c mode
     write speed:  mode3   2702khz  370us in avr emulate
                   mode1/2 3984khz  251us in cplus and  LL_PIN
                   mode0    362khz 2759us in c mode

  by  huawei <huaweiwx@sina.com> 2019.9.10
*/
#include <NuConsole.h>

#define GPIOMODE 1   /*please select mode 0/1/2/3 */

#if GPIOMODE == 3    /*avr emulate*/
#  define inp    (bitRead(PINA,0))
#  define ledddr  DDRD
#  define ledport PORTD
#elif GPIOMODE == 2
  GPIOPIN led(LED_BUILTIN); /*GPIOPIN is alias of LL_PIN class*/
  GPIOPIN inp(PA0);
#elif GPIOMODE == 1                        /* cplus mode*/
  ARDUINOPIN_TypeDef led = LED_BUILTIN;  /* led is __ConstPin   type var */
  ARDUINOPIN_TypeDef inp = PA_0;
#else                                      /*c mode */
  uint32_t led = LED_BUILTIN;
  uint32_t inp = PA0;
#endif

void setup() {
  // put your setup code here, to run once:

  /* setup alternate location default is 0# */
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  delay(2000);
#if  GPIOMODE == 3
  DDRD |= bit(6); //  pinMode(LED_BUILTIN,OUTPUT);
#elif   GPIOMODE == 2
  led.mode(OUTPUT);
#else
  pinMode(led, OUTPUT);
#endif

  uint32_t timers = getTimers(1000, 0);
  Serial.println("\nRead:");
  Serial.print(1000000 / timers);
  Serial.print(" khz  Timer elapsed:");
  Serial.print(timers);
  Serial.println(" us\n");

  timers = getTimers(1000, 1);
  Serial.println("Write:");
  Serial.print(1000000 / timers);
  Serial.print(" khz  Timer elapsed:");
  Serial.print(timers);
  Serial.println(" us\n");
}

//Measuring toggle frequency with an oscilloscope:
void loop() {
#if  GPIOMODE == 3
  PORTD ^= BIT6;
#elif   GPIOMODE == 2
  led.toggle();
#else
  digitalToggle(led);
#endif
  //  delay(500);
}

uint32_t getTimers(uint32_t count, uint8_t op) {
  uint32_t timeBegan, loopTimeElapsed, timeElapsed, i;
  i = 0;
  uint32_t tmp = 0;
  timeBegan = micros();
  while (i < count) {
    i++;
  }
  loopTimeElapsed = (micros() - timeBegan); // Time taken to do nothing but increment a variable
  i = 0;
  if (op) {  //write
    timeBegan = micros();
    while (i < count) {
#if  GPIOMODE == 3
      PORTD |= BIT6;
      PORTD &= ~BIT6;
#elif   GPIOMODE == 2
      led.high();
      led.low();
#else
      digitalWrite(led, HIGH);
      digitalWrite(led, LOW);
#endif
      i++;
    }
    timeElapsed = (micros() - timeBegan - loopTimeElapsed); // Time taken to read a pin
  } else { //read
    timeBegan = micros();
    while (i < count) {
#if   GPIOMODE == 4
      tmp += inp;
#elif   GPIOMODE >= 2
      tmp += inp.read();
#else
      tmp += digitalRead(inp);
#endif
      i++;
    }
    timeElapsed = (micros() - timeBegan - loopTimeElapsed); // Time taken to read a pin
  }
  return timeElapsed;
}

