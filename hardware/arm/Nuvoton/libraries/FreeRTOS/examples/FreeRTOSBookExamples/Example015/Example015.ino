/*
  Example 15. Rewriting vPrintString() to Use a Semaphore
              重写 vPrintString ()以使用信号量

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

/* The task to be created.  Two instances of this task are created. */
static void prvPrintTask( void *pvParameters );

/* The function that uses a mutex to control access to standard out. */
static void prvNewPrintString( const char *pcString );

/*-----------------------------------------------------------*/

/* Declare a variable of type SemaphoreHandle_t.  This is used to reference the
  mutex type semaphore that is used to ensure mutual exclusive access to stdout. */
SemaphoreHandle_t xMutex;


void setup( void )
{
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
  /* Before a semaphore is used it must be explicitly created.  In this example
    a mutex type semaphore is created. */
  xMutex = xSemaphoreCreateMutex();

  /* The tasks are going to use a pseudo random delay, seed the random number
    generator. */
#ifndef STM32H7  
 // GCC 5.4.2-2016q2 srand(x) and rand() have a bug for STM32H7 into HardFault_Handler
 // but GCC 7.3.1-2018q2 ok
    randomSeed( 567 ); 
#endif
  /* Check the semaphore was created successfully. */
  if ( xMutex != NULL )
  {
    /* Create two instances of the tasks that attempt to write stdout.  The
      string they attempt to write is passed in as the task parameter.  The tasks
      are created at different priorities so some pre-emption will occur. */
    xTaskCreate( prvPrintTask, "Print1", 200, (void*)"Task 1 ******************************************\r\n", 1, NULL );
    xTaskCreate( prvPrintTask, "Print2", 200, (void*)"Task 2 ------------------------------------------\r\n", 2, NULL );

    /* Start the scheduler so the created tasks start executing. */
    vTaskStartScheduler();
  }

  /* If all is well we will never reach here as the scheduler will now be
    running the tasks.  If we do reach here then it is likely that there was
    insufficient heap memory available for a resource to be created. */
  for ( ;; );

}

/*-----------------------------------------------------------*/

static void prvNewPrintString( const char *pcString )
{
  /* The semaphore is created before the scheduler is started so already
    exists by the time this task executes.

    Attempt to take the semaphore, blocking indefinitely if the mutex is not
    available immediately.  The call to xSemaphoreTake() will only return when
    the semaphore has been successfully obtained so there is no need to check the
    return value.  If any other delay period was used then the code must check
    that xSemaphoreTake() returns pdTRUE before accessing the resource (in this
    case standard out. */
  xSemaphoreTake( xMutex, portMAX_DELAY );
  {
    /* The following line will only execute once the semaphore has been
      successfully obtained - so standard out can be accessed freely. */
    Serial.print(pcString);
    Serial.flush();
  }
  xSemaphoreGive( xMutex );

  /* Allow any key to stop the application running.  A real application that
    actually used the key value should protect access to the keyboard too.  A
    real application is very unlikely to have more than one task processing
    key presses though! */
  if ( Serial.available() )
  {
    vTaskEndScheduler();
  }
}

/*-----------------------------------------------------------*/

static void prvPrintTask( void *pvParameters )
{
  char *pcStringToPrint;

  /* Two instances of this task are created so the string the task will send
    to prvNewPrintString() is passed in the task parameter.  Cast this to the
    required type. */
  pcStringToPrint = ( char * ) pvParameters;

  for ( ;; )
  {
    /* Print out the string using the newly defined function. */
    prvNewPrintString( pcStringToPrint );

    /* Wait a pseudo random time.  Note that rand() is not necessarily
      re-entrant, but in this case it does not really matter as the code does
      not care what value is returned.  In a more secure application a version
      of rand() that is known to be re-entrant should be used - or calls to
      rand() should be protected using a critical section. */
#ifndef STM32H7  
 // GCC 5.4.2-2016q2  srand(x) and rand() have a bug for STM32H7 into HardFault_Handler
 // but GCC 7.3.1-2018q2 ok
    vTaskDelay(random(0x200));
#else 
     vTaskDelay(0x100);
#endif
  }
}


/****************  default idle hook callback if configUSE_IDLE_HOOK ***************************
   1  Arduono loop() is default idle hook if enable(set configUSE_IDLE_HOOK to 1)
   2  Idle loop has a very small stack (check or set configMINIMAL_STACK_SIZE)
   3  Loop must never block.
   4  This default idle hook can be overload by vApplicationIdleHook()
 ***********************************************************************************************/
void loop() {
  for (;;) {} //This example Not used.
}
