/*
  Example  1. Creating Tasks  创建任务
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
*/

#include "FreeRTOS.h"

/* Used as a loop counter to create a very crude delay. */
#define mainDELAY_LOOP_COUNT   ( 0xfffff )

/* The task functions. */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

/*-----------------------------------------------------------*/

void setup( void )
{
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  /* Create one of the two tasks. */
  xTaskCreate(  vTask1,   /* Pointer to the function that implements the task. */
    "Task 1", /* Text name for the task.  This is to facilitate debugging only. */
    200,    /* Stack depth - most small microcontrollers will use much less stack than this. */
    NULL,   /* We are not using the task parameter. */
    1,      /* This task will run at priority 1. */
    NULL );   /* We are not using the task handle. */

  /* Create the other task in exactly the same way. */
  xTaskCreate( vTask2, "Task 2", 200, NULL, 1, NULL );

  /* Start the scheduler so our tasks start executing. */
  vTaskStartScheduler();

  /* If all is well we will never reach here as the scheduler will now be
     running.  If we do reach here then it is likely that there was insufficient
     heap available for the idle task to be created. 
  */
  for( ;; );

}
/*-----------------------------------------------------------*/

void vTask1( void *pvParameters )
{
const char *pcTaskName = "Task 1 is running\r\n";
volatile unsigned long ul;

  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( pcTaskName );

    /* Delay for a period. */
    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
    {
      /* This loop is just a very crude delay implementation.  There is
      nothing to do in here.  Later exercises will replace this crude
      loop with a proper delay/sleep function. */
    }
  }
}
/*-----------------------------------------------------------*/

void vTask2( void *pvParameters )
{
const char *pcTaskName = "Task 2 is running\r\n";
volatile unsigned long ul;

  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( pcTaskName );

    /* Delay for a period. */
    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
    {
      /* This loop is just a very crude delay implementation.  There is
      nothing to do in here.  Later exercises will replace this crude
      loop with a proper delay/sleep function. */
    }
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