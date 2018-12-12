/*
  Example  6. Combining blocking and non-blocking tasks
              组合阻止和非阻塞任务

  FreeRTOS.org V9.0.0 - Copyright (C) 2003-2017 Richard Barry.

  This file is part of the FreeRTOS.org distribution.

  FreeRTOS.org is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  FreeRTOS.org is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with FreeRTOS.org; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  A special exception to the GPL can be applied should you wish to distribute
  a combined work that includes FreeRTOS.org, without being obliged to provide
  the source code for any proprietary components.  See the licensing section
  of http://www.FreeRTOS.org for full details of how and when the exception
  can be applied.
  
   Attention(注意):
    To use vTaskDelayUntil() function, Must set  INCLUDE_vTaskDelayUntil to 1 in file HAL_Conf.h or FreeRTOSConfig.h
    该例程使用 vTaskDelayUntil(), 因此在文件HAL_Conf.h 或 FreeRTOSConfig.h 中需要设置 宏定义 INCLUDE_vTaskDelayUntil 为 1
*/


#include "FreeRTOS.h"

/* The task functions. */
void vContinuousProcessingTask( void *pvParameters );
void vPeriodicTask( void *pvParameters );

/* Define the strings that will be passed in as the task parameters.  These are
defined const and off the stack to ensure they remain valid when the tasks are
executing. */
const char *pcTextForTask1 = "Continuous task 1 running\r\n";
const char *pcTextForTask2 = "Continuous task 2 running\r\n";
const char *pcTextForPeriodicTask = "Periodic task is running\r\n";

/*-----------------------------------------------------------*/

void setup( void )
{
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  /* Create two instances of the continuous processing task, both at priority 1. */
  xTaskCreate( vContinuousProcessingTask, "Task 1", 200, (void*)pcTextForTask1, 1, NULL );
  xTaskCreate( vContinuousProcessingTask, "Task 2", 200, (void*)pcTextForTask2, 1, NULL );

  /* Create one instance of the periodic task at priority 2. */
  xTaskCreate( vPeriodicTask, "Task 3", 200, (void*)pcTextForPeriodicTask, 2, NULL );

  /* Start the scheduler so our tasks start executing. */
  vTaskStartScheduler();

  for( ;; );

}
/*-----------------------------------------------------------*/

void vContinuousProcessingTask( void *pvParameters )
{
char *pcTaskName;

  /* The string to print out is passed in via the parameter.  Cast this to a
  character pointer. */
  pcTaskName = ( char * ) pvParameters;

  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task.  This task just does this repeatedly
    without ever blocking or delaying. */
    delay(100);  // Arduino delay, burn 100 ms cpu time to slow print.
    vPrintString( pcTaskName );
  }
}
/*-----------------------------------------------------------*/

void vPeriodicTask( void *pvParameters )
{
TickType_t xLastWakeTime;

  /* The xLastWakeTime variable needs to be initialized with the current tick
  count.  Note that this is the only time we access this variable.  From this
  point on xLastWakeTime is managed automatically by the vTaskDelayUntil()
  API function. */
  xLastWakeTime = xTaskGetTickCount();

  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( "Periodic task is running\r\n" );

    /* We want this task to execute exactly every 500 milliseconds. */
    vTaskDelayUntil( &xLastWakeTime, ( 500 / portTICK_PERIOD_MS ) );
  }
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
