/* 
   test of jitter in sleep for one tick　
   测试睡眠状态下一个滴答误差

   idle loop prints min and max time between sleep calls
   空闲循环打印睡眠呼叫（唤醒）之间的最小和最大时间

   Note: access to shared variables tmin and tmax is not atomic. so glitches are possible
         if context switch happens during idle loop access to these variables.
   注意: 对共享变量 tmin 和 tmax 的访问不是自动进行的，因此, 对这些变量的访问，
         如果恰好在空闲循环中并发生线程切换, 则结果可能出现差错。
 */ 

#include <FreeRTOS.h>

volatile  uint16_t tmax = 0;
volatile  uint16_t tmin = 0XFFFF;

//------------------------------------------------------------------------------
static void vJitter(void *pvParameters) {
  UNUSED(pvParameters);
  // initialize tlast
  vTaskDelay(1);
  uint32_t tlast = micros();
  while (true) {
    vTaskDelay(1);
    // get wake time
    uint32_t tmp = micros();
    uint16_t diff = tmp - tlast;
    if (diff < tmin) tmin = diff;
    if (diff > tmax) tmax = diff;
    tlast = tmp;
  }
}
//------------------------------------------------------------------------------
uint8_t np = 10;
static void vPrintTask(void *pvParameters) {
  UNUSED(pvParameters);
  for (;;) {
    // delay one second
    vTaskDelay(configTICK_RATE_HZ);
    Serial.print(tmin);
    Serial.write(',');
    Serial.println(tmax);
    if (np++ >= 10) {
      np = 0;
      tmin = 0XFFFF;
      tmax = 0;
      Serial.write("clear\r\n");
    }
  }
}
//------------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  while (!Serial);
  delay(1000);

  // create high priority thread
  xTaskCreate(vJitter,
              "Task1",
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY + 2,
              NULL);

  // create print task
  xTaskCreate(vPrintTask,
              "Task2",
              configMINIMAL_STACK_SIZE + 100,
              NULL,
              tskIDLE_PRIORITY + 1,
              NULL);

  // start FreeRTOS
  vTaskStartScheduler();

  // should never return
  Serial.println("Die");
  while (1);
}

/****************  default idle hook callback if configUSE_IDLE_HOOK ***************************
 * 1  Arduono loop() is default idle hook if enable(set configUSE_IDLE_HOOK to 1)			   *
 * 2  Idle loop has a very small stack (check or set configMINIMAL_STACK_SIZE)                 * 
 * 3  Loop must never block.                                                                   * 
 * 4  This default idle hook can be overload by vApplicationIdleHook()                         * 
 ***********************************************************************************************/
void loop() {
  for(;;){} //This example Not used.
}