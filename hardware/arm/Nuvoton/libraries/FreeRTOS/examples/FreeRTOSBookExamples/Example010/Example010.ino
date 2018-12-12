/*
  Example 10. Blocking When Receiving From a Queue
			  从队列接收时阻塞

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


/* The tasks to be created.  Two instances are created of the sender task while
only a single instance is created of the receiver task. */
static void vSenderTask( void *pvParameters );
static void vReceiverTask( void *pvParameters );

/*-----------------------------------------------------------*/

/* Declare a variable of type QueueHandle_t.  This is used to store the queue
that is accessed by all three tasks. */
QueueHandle_t xQueue;


void setup( void )
{
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
    /* The queue is created to hold a maximum of 5 long values. */
    xQueue = xQueueCreate( 5, sizeof( long ) );

  if( xQueue != NULL )
  {
    /* Create two instances of the task that will write to the queue.  The
    parameter is used to pass the value that the task should write to the queue,
    so one task will continuously write 100 to the queue while the other task
    will continuously write 200 to the queue.  Both tasks are created at
    priority 1. */
    xTaskCreate( vSenderTask, "Sender1", 200, ( void * ) 100, 1, NULL );
    xTaskCreate( vSenderTask, "Sender2", 200, ( void * ) 200, 1, NULL );

    /* Create the task that will read from the queue.  The task is created with
    priority 2, so above the priority of the sender tasks. */
    xTaskCreate( vReceiverTask, "Receiver", 200, NULL, 2, NULL );

    /* Start the scheduler so the created tasks start executing. */
    vTaskStartScheduler();
  }
  else
  {
    /* The queue could not be created. */
  }

    /* If all is well we will never reach here as the scheduler will now be
    running the tasks.  If we do reach here then it is likely that there was
    insufficient heap memory available for a resource to be created. */
  for( ;; );

}
/*-----------------------------------------------------------*/

static void vSenderTask( void *pvParameters )
{
long lValueToSend;
portBASE_TYPE xStatus;

  /* Two instances are created of this task so the value that is sent to the
  queue is passed in via the task parameter rather than be hard coded.  This way
  each instance can use a different value.  Cast the parameter to the required
  type. */
  lValueToSend = ( long ) pvParameters;

  /* As per most tasks, this task is implemented within an infinite loop. */
  for( ;; )
  {
    /* The first parameter is the queue to which data is being sent.  The
    queue was created before the scheduler was started, so before this task
    started to execute.

    The second parameter is the address of the data to be sent.

    The third parameter is the Block time � the time the task should be kept
    in the Blocked state to wait for space to become available on the queue
    should the queue already be full.  In this case we don�t specify a block
    time because there should always be space in the queue. */
    xStatus = xQueueSendToBack( xQueue, &lValueToSend, 0 );

    if( xStatus != pdPASS )
    {
      /* We could not write to the queue because it was full � this must
      be an error as the queue should never contain more than one item! */
      vPrintString( "Could not send to the queue.\r\n" );
    }

    /* Allow the other sender task to execute. */
    taskYIELD();
  }
}
/*-----------------------------------------------------------*/

static void vReceiverTask( void *pvParameters )
{
/* Declare the variable that will hold the values received from the queue. */
long lReceivedValue;
portBASE_TYPE xStatus;
const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;

  /* This task is also defined within an infinite loop. */
  for( ;; )
  {
    /* As this task unblocks immediately that data is written to the queue this
    call should always find the queue empty. */
    if( uxQueueMessagesWaiting( xQueue ) != 0 )
    {
      vPrintString( "Queue should have been empty!\r\n" );
    }

    /* The first parameter is the queue from which data is to be received.  The
    queue is created before the scheduler is started, and therefore before this
    task runs for the first time.

    The second parameter is the buffer into which the received data will be
    placed.  In this case the buffer is simply the address of a variable that
    has the required size to hold the received data.

    the last parameter is the block time � the maximum amount of time that the
    task should remain in the Blocked state to wait for data to be available should
    the queue already be empty. */
    xStatus = xQueueReceive( xQueue, &lReceivedValue, xTicksToWait );

    if( xStatus == pdPASS )
    {
      /* Data was successfully received from the queue, print out the received
      value. */
      vPrintStringAndNumber( "Received = ", lReceivedValue );
    }
    else
    {
      /* We did not receive anything from the queue even after waiting for 100ms.
      This must be an error as the sending tasks are free running and will be
      continuously writing to the queue. */
      vPrintString( "Could not receive from the queue.\r\n" );
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




