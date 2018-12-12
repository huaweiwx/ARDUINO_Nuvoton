/*
  Example  7. Defining an Idle Task Hook Function   定义空闲任务挂钩函数

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
   To use idle hook, Must set  configUSE_IDLE_HOOK to 1 in file HAL_Conf.h or FreeRTOSConfig.h
   该例程使用 idle, 因此在文件HAL_Conf.h 或 FreeRTOSConfig.h 中需要设置 宏定义 configUSE_IDLE_HOOK 为 1
*/

#include "FreeRTOS.h"

/* The task function. */
void vTaskFunction( void *pvParameters );

/* A variable that is incremented by the idle task hook function. */
volatile unsigned long ulIdleCycleCount = 0UL;

/* Define the strings that will be passed in as the task parameters.  These are
  defined const and off the stack to ensure they remain valid when the tasks are
  executing.
*/
const char *pcTextForTask1 = "Task 1 is running\r\n";
const char *pcTextForTask2 = "Task 2 is running\t\n";

/*-----------------------------------------------------------*/

void setup( void )
{
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  /* Create the first task at priority 1... */
  xTaskCreate( vTaskFunction, "Task 1", 200, (void*)pcTextForTask1, 1, NULL );

  /* ... and the second task at priority 2.  The priority is the second to
    last parameter. */
  xTaskCreate( vTaskFunction, "Task 2", 200, (void*)pcTextForTask2, 2, NULL );

  /* Start the scheduler so our tasks start executing. */
  vTaskStartScheduler();

  for ( ;; );

}
/*-----------------------------------------------------------*/

void vTaskFunction( void *pvParameters )
{
  char *pcTaskName;

  /* The string to print out is passed in via the parameter.  Cast this to a
    character pointer. */
  pcTaskName = ( char * ) pvParameters;

  /* As per most tasks, this task is implemented in an infinite loop. */
  for ( ;; )
  {
    /* Print out the name of this task AND the number of times ulIdleCycleCount
        has been incremented. */
    vPrintStringAndNumber( pcTaskName, ulIdleCycleCount );

    /* Delay for a period.  This time we use a call to vTaskDelay() which
      puts the task into the Blocked state until the delay period has expired.
      The delay period is specified in 'ticks'. */
    vTaskDelay( 250 / portTICK_PERIOD_MS );
  }
}
/*-----------------------------------------------------------*/

//------------------  vApplicationIdleHook: default idle hook ----------------
//
void vApplicationIdleHook( void ) // FreeRTOS expects C linkage
{
  /* This hook function does nothing but increment a counter. */
  ulIdleCycleCount++;
}


/****************  default idle hook callback if configUSE_IDLE_HOOK ***************************
 * 1  Arduono loop() is default idle hook if enable(set configUSE_IDLE_HOOK to 1)			   *
   2  Idle loop has a very small stack (check or set configMINIMAL_STACK_SIZE)
   3  Loop must never block.
   4  This default idle hook can be overload by vApplicationIdleHook()
 ***********************************************************************************************/
void loop() {
  for (;;) {} //This example Not used.
}
