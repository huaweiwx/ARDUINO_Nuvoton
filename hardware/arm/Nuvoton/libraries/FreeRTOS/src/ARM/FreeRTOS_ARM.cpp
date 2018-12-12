
#include <Arduino.h>
#include "FreeRTOS_ARM.h"

//------------------------------------------------------------------------------
/** vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. 
*/
extern void loop();
extern "C" void errorCallback(char* file, uint32_t n);

extern "C"
void  __attribute__((weak)) vApplicationIdleHook( void ) {
  void loop();
  loop();
}
/** assertBlink
 * Blink one short pulse every two seconds if configASSERT fails.
*/

//void assertBlink() {
//  errorLedBlink(1);
//}

extern "C" void vApplicationMallocFailedHook( void )
{
    /* vApplicationMallocFailedHook() will only be called if
    configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
    function that will get called if a call to pvPortMalloc() fails.*/
    //taskDISABLE_INTERRUPTS();
	errorCallback((char*)"FreeRTOS Malloc", 22);
	for(;;);
}

extern "C" void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    ( void ) pcTaskName;
    ( void ) pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */
    //taskDISABLE_INTERRUPTS();
	errorLedBlink((char*)"FreeRTOS StackOver", 23);
	for(;;);
 }

/* show port info */
#if (portINFO >0)
	
#if portUSE_HEAP == 1
#pragma message "port heap use heap_1.c"
#elif portUSE_HEAP == 2
#pragma message "port heap use heap_2.c"
#elif portUSE_HEAP == 3
#pragma message "port heap use heap_3.c"
#elif portUSE_HEAP == 4
#pragma message "port heap use heap_4.c"
#elif portUSE_HEAP == 5
#pragma message "port heap use heap_5.c"
#else
#error !portUSE_HEAP must be defined 1~5!
#endif

#if configUSE_COUNTING_SEMAPHORES > 0
#pragma message "use counting semaphores"
#endif

#if configUSE_IDLE_HOOK > 0
#pragma message "use idle hook"
#endif

#if  configUSE_TICK_HOOK >0
#pragma message "use tick hook"
#endif

#if  INCLUDE_vTaskDelayUntil >0
#pragma message "include INCLUDE_vTaskDelayUntil"
#endif

#endif
