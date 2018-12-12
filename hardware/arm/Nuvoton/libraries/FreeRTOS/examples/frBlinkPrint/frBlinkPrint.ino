/*
    Simple demo of three threads/ 三个线程的简单演示
    LED blink thread, print thread, and idle loop

    Attention(注意):
	  To use idle hook, Must set  configUSE_IDLE_HOOK to 1 in file HAL_Conf.h or FreeRTOSConfig.h
	  该例程使用 idle hook, 因此在文件HAL_Conf.h 或 FreeRTOSConfig.h 中需要设置宏定义 configUSE_IDLE_HOOK 为 1
*/
#include <FreeRTOS.h>

/*Check environment configuration*/
#if configUSE_IDLE_HOOK == 0
# error	"!Use idel hook,The macro variable configUSE_IDLE_HOOK must be set to 1 in file HAL_Conf.h!"
#endif

// The LED is attached to pin 13 on Arduino.
# define LED_PIN     LED_BUILTIN
# define LED_LEVELON (LED_BUILTIN_MASK & 0x01) /*LOW or HIGH*/

volatile uint32_t count = 0;

// handle for blink task
TaskHandle_t blink;

//------------------------------------------------------------------------------
// high priority for blinking LED
static void vLEDFlashTask(void *pvParameters) {
  UNUSED(pvParameters);
  pinMode(LED_PIN, OUTPUT);

  // Flash led every 200 ms.
  for (;;) {
    // Turn LED on.
    digitalWrite(LED_PIN, LED_LEVELON);

    // Sleep for 20 milliseconds.
    vTaskDelay((20L * configTICK_RATE_HZ) / 1000L);

    // Turn LED off.
    digitalToggle(LED_PIN);

    // Sleep for 230 milliseconds.
    vTaskDelay((230L * configTICK_RATE_HZ) / 1000L);
  }
}

//------------------------------------------------------------------------------
static void vPrintTask(void *pvParameters) {
  UNUSED(pvParameters);
  while (1) {
    // Sleep for one second.
    vTaskDelay(configTICK_RATE_HZ);
    if (count) {
      // Print count for previous second.
      Serial.print(F("Count per second: "));
      Serial.println(count);
      // Zero count.
      count = 0;
    } else {
      Serial.println(" idle hook is not runed. Please set configUSE_IDLE_HOOK to 1");
    }
  }
}

//------------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  
  // wait for usbSerial(exp. Leonardo)
  while (!Serial) {}

  // create blink task
  xTaskCreate(vLEDFlashTask,
              "Task1",
              configMINIMAL_STACK_SIZE + 50,
              NULL,
              tskIDLE_PRIORITY + 2,
              &blink);

  // create print task
  xTaskCreate(vPrintTask,
              "Task2",
              configMINIMAL_STACK_SIZE + 100,
              NULL,
              tskIDLE_PRIORITY + 1,
              NULL);

  //start FreeRTOS
  vTaskStartScheduler();

  // should never return
  Serial.println(F("Die"));
  while (1);
}

/************************  default idle hook  if configUSE_IDLE_HOOK *******************
   1  Arduono loop() is default idle hook if enable(set configUSE_IDLE_HOOK to 1)
   2  idle loop has a very small stack (check or set configMINIMAL_STACK_SIZE)
   3  loop must never block.
   4  This default idle hook can be overload by vApplicationIdleHook()
 ***************************************************************************************/
void loop()
{
  while (1) {
    // must insure increment is atomic
    // in case of context switch for print
    noInterrupts();
    count++;
    interrupts();
  }
}

/*The end*/

