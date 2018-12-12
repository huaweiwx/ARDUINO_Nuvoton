/*
  Example  9. Deleting tasks  删除任务

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


/* The two task functions. */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

/* Used to hold the handle of Task2. */
TaskHandle_t xTask2Handle;

/*-----------------------------------------------------------*/

void setup( void )
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  /* Create the first task at priority 1.  This time the task parameter is
  not used and is set to NULL.  The task handle is also not used so likewise
  is also set to NULL. */
  xTaskCreate( vTask1, "Task 1", 200, NULL, 1, NULL );
          /* The task is created at priority 1 ^. */

  /* Start the scheduler so our tasks start executing. */
  vTaskStartScheduler();

  for( ;; );

}
/*-----------------------------------------------------------*/

void vTask1( void *pvParameters )
{
const TickType_t xDelay100ms = 100 / portTICK_PERIOD_MS;

  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( "Task1 is running\r\n" );

    /* Create task 2 at a higher priority.  Again the task parameter is not
    used so is set to NULL - BUT this time we want to obtain a handle to the
    task so pass in the address of the xTask2Handle variable. */
    xTaskCreate( vTask2, "Task 2", 200, NULL, 2, &xTask2Handle );
       /* The task handle is the last parameter ^^^^^^^^^^^^^ */

    /* Task2 has/had the higher priority, so for Task1 to reach here Task2
    must have already executed and deleted itself.  Delay for 100
    milliseconds. */
    vTaskDelay( xDelay100ms );
  }
}

/*-----------------------------------------------------------*/

void vTask2( void *pvParameters )
{
  /* Task2 does nothing but delete itself.  To do this it could call vTaskDelete()
  using a NULL parameter, but instead and purely for demonstration purposes it
  instead calls vTaskDelete() with its own task handle. */
  vPrintString( "Task2 is running and about to delete itself\r\n" );
  vTaskDelete( xTask2Handle );
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

