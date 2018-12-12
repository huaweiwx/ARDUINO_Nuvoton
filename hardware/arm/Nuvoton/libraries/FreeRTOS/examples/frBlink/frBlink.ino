/*
 *  Example to demonstrate thread definition, semaphores, and thread sleep.
 *  演示线程定义、信号量和线程休眠
 *
 *  Attention(注意):
 *     check and set configUSE_COUNTING_SEMAPHORES in FreeRTOSConfig.h or HAL_Conf.h
 *     检查文件 FreeRTOSConfig.h 或 HAL_Conf.h 并设置宏定义 configUSE_COUNTING_SEMAPHORES 为 1    
 */
#include <FreeRTOS.h>

/*Check environment configuration*/
#if configUSE_COUNTING_SEMAPHORES == 1
// Declare a semaphore handle.
SemaphoreHandle_t sem;
#else
# error	"!The macro variable configUSE_COUNTING_SEMAPHORES must be set to 1 in file HAL_Conf.h!"
#endif

// The LED is attached to pin 13 on Arduino.
#ifdef  LED_BUILTIN
# define LED_PIN    LED_BUILTIN
# define LED_ON bitRead(LED_BUILTIN_MASK,0)
#else
# define LED_PIN  13    //fixd me
# define LED_ON 1   //fixd me
#endif
//------------------------------------------------------------------------------
/*
   Thread 1, turn the LED off when signalled by thread 2.
*/
// Declare the thread function for thread 1.
static void Thread1(void* arg) {
  UNUSED(arg);
  while (1) {

    // Wait for signal from thread 2.
    xSemaphoreTake(sem, portMAX_DELAY);

    // Turn LED off.
    digitalWrite(LED_PIN, LOW);
  }
}
//------------------------------------------------------------------------------
/*
   Thread 2, turn the LED on and signal thread 1 to turn the LED off.
*/
// Declare the thread function for thread 2.
static void Thread2(void* arg) {
  UNUSED(arg);

  pinMode(LED_PIN, OUTPUT);

  while (1) {
    // Turn LED on.
    digitalWrite(LED_PIN, HIGH);

    // Sleep for 200 milliseconds.
    vTaskDelay((200L * configTICK_RATE_HZ) / 1000L);

    // Signal thread 1 to turn LED off.
    xSemaphoreGive(sem);

    // Sleep for 200 milliseconds.
    vTaskDelay((200L * configTICK_RATE_HZ) / 1000L);
  }
}
//------------------------------------------------------------------------------
void setup() {
  portBASE_TYPE s1, s2;

  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  delay(1000);
  
  // initialize semaphore
  sem = xSemaphoreCreateCounting(1, 0);

  // create task at priority two
  s1 = xTaskCreate(Thread1, NULL, configMINIMAL_STACK_SIZE, NULL,tskIDLE_PRIORITY + 2,NULL);

  // create task at priority one
  s2 = xTaskCreate(Thread2, NULL, configMINIMAL_STACK_SIZE, NULL,tskIDLE_PRIORITY + 1,NULL);

  // check for creation errors
  if (sem == NULL || s1 != pdPASS || s2 != pdPASS ) {
    Serial.println(F("Creation problem"));
    while (1);
  } else {
    Serial.println(F("Creation ok"));
  }
  // start scheduler
  vTaskStartScheduler();
  Serial.println("Insufficient RAM");
  while (1);
}

/********************  default idle hook  if configUSE_IDLE_HOOK ***********************
 * 1  Arduono loop() is default idle hook if enable(set configUSE_IDLE_HOOK to 1)      *
 * 2  idle loop has a very small stack (check or set configMINIMAL_STACK_SIZE)         * 
 * 3  loop must never block.                                                           *
 * 4  This default idle hook can be overload by vApplicationIdleHook()                 * 
 ***************************************************************************************/
void loop() {}
