/*
  Example 11. Blocking When Sending to a Queue / Sending Structures on a Queue   发送到队列的队列/发送结构时阻塞

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

#define mainSENDER_1    1
#define mainSENDER_2    2

/* The tasks to be created.  Two instances are created of the sender task while
only a single instance is created of the receiver task. */
static void vSenderTask( void *pvParameters );
static void vReceiverTask( void *pvParameters );

/*-----------------------------------------------------------*/

/* Declare a variable of type QueueHandle_t.  This is used to store the queue
that is accessed by all three tasks. */
QueueHandle_t xQueue;

/* Define the structure type that will be passed on the queue. */
typedef struct
{
  unsigned char ucValue;
  unsigned char ucSource;
} xData;

/* Declare two variables of type xData that will be passed on the queue. */
static const xData xStructsToSend[ 2 ] =
{
  { 100, mainSENDER_1 }, /* Used by Sender1. */
  { 200, mainSENDER_2 }  /* Used by Sender2. */
};

void setup( void )
{
  Serial.begin(115200);  /*set param: 115200bps 8N1 (default 115200bps 8N1) */
    /* The queue is created to hold a maximum of 3 structures of type xData. */
    xQueue = xQueueCreate( 3, sizeof( xData ) );

  if( xQueue != NULL )
  {
    /* Create two instances of the task that will write to the queue.  The
    parameter is used to pass the structure that the task should write to the
    queue, so one task will continuously send xStructsToSend[ 0 ] to the queue
    while the other task will continuously send xStructsToSend[ 1 ].  Both
    tasks are created at priority 2 which is above the priority of the receiver. */
    xTaskCreate( vSenderTask, "Sender1", 200, ( void * ) &( xStructsToSend[ 0 ] ), 2, NULL );
    xTaskCreate( vSenderTask, "Sender2", 200, ( void * ) &( xStructsToSend[ 1 ] ), 2, NULL );

    /* Create the task that will read from the queue.  The task is created with
    priority 1, so below the priority of the sender tasks. */
    xTaskCreate( vReceiverTask, "Receiver", 200, NULL, 1, NULL );

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
portBASE_TYPE xStatus;
const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;

  /* As per most tasks, this task is implemented within an infinite loop. */
  for( ;; )
  {
    /* The first parameter is the queue to which data is being sent.  The
    queue was created before the scheduler was started, so before this task
    started to execute.

    The second parameter is the address of the structure being sent.  The
    address is passed in as the task parameter.

    The third parameter is the Block time - the time the task should be kept
    in the Blocked state to wait for space to become available on the queue
    should the queue already be full.  A block time is specified as the queue
    will become full.  Items will only be removed from the queue when both
    sending tasks are in the Blocked state.. */
    xStatus = xQueueSendToBack( xQueue, pvParameters, xTicksToWait );

    if( xStatus != pdPASS )
    {
      /* We could not write to the queue because it was full - this must
      be an error as the receiving task should make space in the queue
      as soon as both sending tasks are in the Blocked state. */
      vPrintString( "Could not send to the queue.\r\n" );
    }

    /* Allow the other sender task to execute. */
    taskYIELD();
  }
}
/*-----------------------------------------------------------*/

static void vReceiverTask( void *pvParameters )
{
/* Declare the structure that will hold the values received from the queue. */
xData xReceivedStructure;
portBASE_TYPE xStatus;

  /* This task is also defined within an infinite loop. */
  for( ;; )
  {
    /* As this task only runs when the sending tasks are in the Blocked state,
    and the sending tasks only block when the queue is full, this task should
    always find the queue to be full.  3 is the queue length. */
    if( uxQueueMessagesWaiting( xQueue ) != 3 )
    {
      vPrintString( "Queue should have been full!\r\n" );
    }

    /* The first parameter is the queue from which data is to be received.  The
    queue is created before the scheduler is started, and therefore before this
    task runs for the first time.

    The second parameter is the buffer into which the received data will be
    placed.  In this case the buffer is simply the address of a variable that
    has the required size to hold the received structure.

    The last parameter is the block time - the maximum amount of time that the
    task should remain in the Blocked state to wait for data to be available
    should the queue already be empty.  A block time is not necessary as this
    task will only run when the queue is full so data will always be available. */
    xStatus = xQueueReceive( xQueue, &xReceivedStructure, 0 );

    if( xStatus == pdPASS )
    {
      /* Data was successfully received from the queue, print out the received
      value and the source of the value. */
      if( xReceivedStructure.ucSource == mainSENDER_1 )
      {
        vPrintStringAndNumber( "From Sender 1 = ", xReceivedStructure.ucValue );
      }
      else
      {
        vPrintStringAndNumber( "From Sender 2 = ", xReceivedStructure.ucValue );
      }
    }
    else
    {
      /* We did not receive anything from the queue.  This must be an error
      as this task should only run when the queue is full. */
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



