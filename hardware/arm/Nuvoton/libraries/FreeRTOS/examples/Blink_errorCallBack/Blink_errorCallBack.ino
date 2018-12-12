/*
  Blink.ino
  Turns LED on/off demo running in FreeRTOS V9.0/10.0.

  This example code is in the public domain.
  Nuvoton tested  by huaweiwx@sina.com , May 2 2018
*/

#include <FreeRTOS.h>

/*Check environment configuration*/
/*default*/

static void myTask1(void __attribute__ ((unused)) *argument)
{
  /*Task1 setup*/
  uint32_t i = 0;
  

  /* Infinite loop */
  for (;;)
  {
    /* USER CODE BEGIN Task1 */
    vTaskDelay(1000);
    i++;
    Serial.print("Count:");
    Serial.print(i, HEX);
    Serial.println(" in myTask1");
    /* USER CODE END Task1 */
  }
}
static void myTask2(void __attribute__ ((unused)) *argument)
{
  /*Task2 setup*/
  pinMode(LED_BUILTIN, OUTPUT);

  /* Infinite loop */
  for (;;)
  {
    /* USER CODE BEGIN Task2 */
    digitalToggle(LED_BUILTIN);
    vTaskDelay(500);
    /* USER CODE END Task2 */
  }
}

// the setup function runs once when you press reset or power the board.
void setup() {
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  xTaskCreate(myTask1,
              NULL,
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY +1,
              NULL);
  xTaskCreate(myTask2,
              NULL,
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY,
              NULL);
  vTaskStartScheduler();  //FreeRTOS start and never return!
}

void loop() {
  for (;;) {} //This example Not used.
}

extern "C" void errorCallback(char* file, uint32_t n){
  Serial.println(file);
  Serial.println(n);
  while(1);
}

