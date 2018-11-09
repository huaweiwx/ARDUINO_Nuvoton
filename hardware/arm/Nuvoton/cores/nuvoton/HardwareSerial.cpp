/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Perry Hung.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file HardwareSerial.cpp
 * @brief Wirish serial port implementation.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#if  defined(M480)   
  #if(UART_MAX_COUNT>0)
  ring_buffer rx_buffer0 = { { 0 }, 0, 0};
  HardwareSerial Serial0(UART_Desc[0].U,0,CLK_CLKSEL1_UART0SEL_PLL,1,UART_Desc[0].irq,&rx_buffer0);
  #endif

  #if(UART_MAX_COUNT>1)
  ring_buffer rx_buffer1 = { { 0 }, 0, 0};
  HardwareSerial Serial1(UART_Desc[1].U,1,CLK_CLKSEL1_UART1SEL_PLL,1,UART_Desc[1].irq,&rx_buffer1);
  #endif

#ifdef __cplusplus
extern "C" {
#endif

#if(UART_MAX_COUNT>0)
void UART0_IRQHandler(void)
{
	while(UART_GET_INT_FLAG(UART0,UART_INTEN_RDAIEN_Msk))
	{
	   unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
  	   if (i != rx_buffer0.tail) {
    	  rx_buffer0.buffer[rx_buffer0.head] = UART0->DAT;
    	  rx_buffer0.head = i;
  	   }
	}
		
}
#endif

#if(UART_MAX_COUNT>1)
void UART1_IRQHandler(void)
{
	while(UART_GET_INT_FLAG(UART1,UART_INTEN_RDAIEN_Msk))
	{
		unsigned int i = (rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
		if (i != rx_buffer1.tail) {
			rx_buffer1.buffer[rx_buffer1.head] = UART1->DAT;
			rx_buffer1.head = i;
		}
	}
		
}
#endif

#ifdef __cplusplus
}
#endif

#elif defined(__M451__) 
  #if(UART_MAX_COUNT>0)
  ring_buffer rx_buffer0 = { { 0 }, 0, 0};
  HardwareSerial Serial0(UART_Desc[0].U,0,CLK_CLKSEL1_UARTSEL_HXT,1,UART_Desc[0].irq,&rx_buffer0);
  #endif

  #if(UART_MAX_COUNT>1)
  ring_buffer rx_buffer1 = { { 0 }, 0, 0};
  HardwareSerial Serial1(UART_Desc[1].U,1,CLK_CLKSEL1_UARTSEL_HXT,1,UART_Desc[1].irq,&rx_buffer1);
  #endif

#ifdef __cplusplus
extern "C" {
#endif

#if(UART_MAX_COUNT>0)
void UART0_IRQHandler(void)
{
	while(UART_GET_INT_FLAG(UART0,UART_INTEN_RDAIEN_Msk))
	{
	   unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
  	   if (i != rx_buffer0.tail) {
    	  rx_buffer0.buffer[rx_buffer0.head] = UART0->DAT;
    	  rx_buffer0.head = i;
  	   }
	}
		
}
#endif

#if(UART_MAX_COUNT>1)
void UART1_IRQHandler(void)
{
	while(UART_GET_INT_FLAG(UART1,UART_INTEN_RDAIEN_Msk))
	{
		unsigned int i = (rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
		if (i != rx_buffer1.tail) {
			rx_buffer1.buffer[rx_buffer1.head] = UART1->DAT;
			rx_buffer1.head = i;
		}
	}
		
}
#endif

#ifdef __cplusplus
}
#endif

#elif defined(__NUC240__)
  #if(UART_MAX_COUNT>0)
  ring_buffer rx_buffer0 = { { 0 }, 0, 0};
  HardwareSerial Serial0(UART_Desc[0].U,0,CLK_CLKSEL1_UART_S_HXT,1,UART_Desc[0].irq,&rx_buffer0);
  #endif

  #if(UART_MAX_COUNT>1)
  ring_buffer rx_buffer1 = { { 0 }, 0, 0};
  HardwareSerial Serial1(UART_Desc[1].U,1,CLK_CLKSEL1_UART_S_HXT,1,UART_Desc[1].irq,&rx_buffer1);
  #endif

#ifdef __cplusplus
extern "C" {
#endif

#if(UART_MAX_COUNT>0)
void UART02_IRQHandler(void)
{	 
	while(UART_GET_INT_FLAG(UART0,UART_IER_RDA_IEN_Msk))
	{
		unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
		if (i != rx_buffer0.tail) {
			rx_buffer0.buffer[rx_buffer0.head] = UART0->RBR;
			rx_buffer0.head = i;
		}
	}
		
}
#endif

#if(UART_MAX_COUNT>1)
void UART1_IRQHandler(void)
{
	while(UART_GET_INT_FLAG(UART1,UART_IER_RDA_IEN_Msk))
	{
		unsigned int i = (rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
		if (i != rx_buffer1.tail) {
			rx_buffer1.buffer[rx_buffer1.head] = UART1->RBR;
			rx_buffer1.head = i;
		}
	}
		
}
#endif

#ifdef __cplusplus
}
#endif

#elif defined(__NANO100__)
 #if(UART_MAX_COUNT>0)
  ring_buffer rx_buffer0 = { { 0 }, 0, 0};  /* for UAR0_IRQ */
  HardwareSerial Serial0(UART_Desc[0].U,0,CLK_CLKSEL1_UART_S_HXT,1,UART_Desc[0].irq,&rx_buffer0);
 #endif

 #if(UART_MAX_COUNT>1)
  ring_buffer rx_buffer1 = { { 0 }, 0, 0}; /* for UAR1_IRQ */
  HardwareSerial Serial1(UART_Desc[1].U,1,CLK_CLKSEL1_UART_S_HXT,1,UART_Desc[1].irq,&rx_buffer1);
 #endif

#ifdef __cplusplus
extern "C" {
#endif

#if(UART_MAX_COUNT>1)
void UART0_IRQHandler(void)
{        	                   
	while(UART_GET_INT_FLAG(UART0,UART_IER_RDA_IE_Msk))
	{
		unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
  	    if (i != rx_buffer0.tail) {
    	  rx_buffer0.buffer[rx_buffer0.head] = UART0->RBR;
    	  rx_buffer0.head = i;
		}
	}
		
}
#endif

#if(UART_MAX_COUNT>0)
void UART1_IRQHandler(void)
{		 
	while(UART_GET_INT_FLAG(UART1,UART_IER_RDA_IE_Msk))
	{
		unsigned int i = (rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
		if (i != rx_buffer1.tail) {
			rx_buffer1.buffer[rx_buffer1.head] = UART1->RBR;
			rx_buffer1.head = i;
		}
	}
		
}
#endif

#ifdef __cplusplus
}
#endif

#elif defined(__NUC131__)

#if(UART_MAX_COUNT>0)
ring_buffer rx_buffer0 = { { 0 }, 0, 0};
HardwareSerial Serial0(UART_Desc[0].U,0,CLK_CLKSEL1_UART_S_HXT,1,UART_Desc[0].irq,&rx_buffer0);
#endif

#if(UART_MAX_COUNT>1)
ring_buffer rx_buffer1 = { { 0 }, 0, 0};
HardwareSerial Serial1(UART_Desc[1].U,1,CLK_CLKSEL1_UART_S_HXT,1,UART_Desc[1].irq,&rx_buffer1);
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if(UART_MAX_COUNT>0)
void UART02_IRQHandler(void)
{	 
	while(UART_GET_INT_FLAG(UART0,UART_IER_RDA_IEN_Msk))
	{
		unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
		if (i != rx_buffer0.tail) {
			rx_buffer0.buffer[rx_buffer0.head] = UART0->RBR;
			rx_buffer0.head = i;
		}
	}
}
#endif

#if(UART_MAX_COUNT>1)
void UART1_IRQHandler(void)
{
	while(UART_GET_INT_FLAG(UART1,UART_IER_RDA_IEN_Msk))
	{
		unsigned int i = (rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
		if (i != rx_buffer1.tail) {
			rx_buffer1.buffer[rx_buffer1.head] = UART1->RBR;
			rx_buffer1.head = i;
		}
	}		
}
#endif

#ifdef __cplusplus
}
#endif

#elif defined(__NANO1X2__)

#if(UART_MAX_COUNT>0)
ring_buffer rx_buffer0 = { { 0 }, 0, 0};  /* for UART0_IRQ */
HardwareSerial Serial0(UART_Desc[0].U,0,CLK_CLKSEL1_UART_S_HIRC,1,UART_Desc[0].irq,&rx_buffer0);
#endif

#if(UART_MAX_COUNT>1)
ring_buffer rx_buffer1 = { { 0 }, 0, 0}; /* for UART1_IRQ */
HardwareSerial Serial1(UART_Desc[1].U,1,CLK_CLKSEL1_UART_S_HIRC,1,UART_Desc[1].irq,&rx_buffer1);
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if(UART_MAX_COUNT>0)
void UART0_IRQHandler(void)
{        	                   
	while(UART_GET_INT_FLAG(UART0,UART_IER_RDA_IE_Msk))
	{
		unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
		if (i != rx_buffer0.tail) {
			rx_buffer0.buffer[rx_buffer0.head] = UART0->RBR;
			rx_buffer0.head = i;
		}
	}
}
#endif

#if(UART_MAX_COUNT>1)
void UART1_IRQHandler(void)
{		 
	while(UART_GET_INT_FLAG(UART1,UART_IER_RDA_IE_Msk))
	{
		unsigned int i = (rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
		if (i != rx_buffer1.tail) {
			rx_buffer1.buffer[rx_buffer1.head] = UART1->RBR;
			rx_buffer1.head = i;
		}
	}
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#if(UART_MAX_COUNT>0)
void serialEvent() __attribute__((weak));
#endif

#if(UART_MAX_COUNT>1)
void serial1Event() __attribute__((weak));
#endif

void serialEventRun(void)
{
#if(UART_MAX_COUNT>0)
    if (Serial.available()) serialEvent();
#endif
    	
#if(UART_MAX_COUNT>1)
    if (Serial1.available()) serial1Event();
#endif	
}

HardwareSerial::HardwareSerial(UART_T *uart_device,
							 uint32_t u32Idx,															                              
                             uint32_t u32ClkSrc,
                             uint32_t u32ClkDiv,
                             IRQn_Type u32IrqId,
                             ring_buffer *rx_buffer) {
    this->uart_device = uart_device;
    this->u32Idx = u32Idx;
    this->u32ClkSrc = u32ClkSrc;
    this->u32ClkDiv = u32ClkDiv;
    this->u32IrqId = u32IrqId;
    this->_rx_buffer = rx_buffer;
}

/*
 * Set up/tear down
 */

void HardwareSerial::begin(uint32_t baud) {
    
    UART_Config(UART_Desc[u32Idx]);
    /* Enable IP clock */       
    CLK_EnableModuleClock(UART_Desc[u32Idx].module);

#if defined(M480)     
    /* Select IP clock source and clock divider */
	if(uart_device == UART0)
       CLK_SetModuleClock(UART_Desc[u32Idx].module,u32ClkSrc,CLK_CLKDIV0_UART0(u32ClkDiv));
#if(UART_MAX_COUNT>1)
    else if(uart_device == UART1)
       CLK_SetModuleClock(UART_Desc[u32Idx].module,u32ClkSrc,CLK_CLKDIV0_UART1(u32ClkDiv));
#endif
#if(UART_MAX_COUNT>2)
    else if(uart_device == UART2)
       CLK_SetModuleClock(UART_Desc[u32Idx].module,u32ClkSrc,CLK_CLKDIV4_UART2(u32ClkDiv));
#endif
#if(UART_MAX_COUNT>3)
    else if(uart_device == UART3)
       CLK_SetModuleClock(UART_Desc[u32Idx].module,u32ClkSrc,CLK_CLKDIV4_UART3(u32ClkDiv));
#endif
#if(UART_MAX_COUNT>4)
    else if(uart_device == UART4)
       CLK_SetModuleClock(UART_Desc[u32Idx].module,u32ClkSrc,CLK_CLKDIV4_UART4(u32ClkDiv));
#endif
#if(UART_MAX_COUNT>5)
    else if(uart_device == UART5)
       CLK_SetModuleClock(UART_Desc[u32Idx].module,u32ClkSrc,CLK_CLKDIV4_UART5(u32ClkDiv));
#endif

    /* Reset IP */
    //SYS_ResetModule(UART_Desc[u32Idx].module);
    /* Enable Interrupt */
    UART_ENABLE_INT(uart_device,UART_INTEN_RDAIEN_Msk);
#elif defined(__M451__)     
    /* Select IP clock source and clock divider */
    CLK_SetModuleClock(UART_Desc[u32Idx].module,u32ClkSrc,CLK_CLKDIV0_UART(u32ClkDiv));
    /* Reset IP */
    //SYS_ResetModule(UART_Desc[u32Idx].module);
    /* Enable Interrupt */
    UART_ENABLE_INT(uart_device,UART_INTEN_RDAIEN_Msk);
#elif defined(__NUC240__) | defined(__NUC131__)
   	/* Select IP clock source and clock divider */
	CLK_SetModuleClock(UART_Desc[u32Idx].module,u32ClkSrc,CLK_CLKDIV_UART(u32ClkDiv));
    /* Reset IP */
    //SYS_ResetModule(UART_Desc[u32Idx].module);
    /* Enable Interrupt */
    UART_ENABLE_INT(uart_device,UART_IER_RDA_IEN_Msk);
#elif defined(__NANO100__) | defined(__NANO1X2__)
   	/* Select IP clock source and clock divider */
	CLK_SetModuleClock(UART_Desc[u32Idx].module,u32ClkSrc,CLK_UART_CLK_DIVIDER(u32ClkDiv));
    /* Reset IP */
    //SYS_ResetModule(UART_Desc[u32Idx].module);
    /* Enable Interrupt */
    UART_ENABLE_INT(uart_device,UART_IER_RDA_IE_Msk);
#endif

    NVIC_EnableIRQ(u32IrqId);
    /* Configure UART and set UART Baudrate */
    UART_Open(uart_device, baud);
}

void HardwareSerial::end(void) {
    UART_Close(uart_device);
}

/*
 * I/O
 */

int HardwareSerial::read(void) {        
  // if the head isn't ahead of the tail, we don't have any characters
  if (_rx_buffer->head == _rx_buffer->tail) {
    return -1;
  } else {
    unsigned char c = _rx_buffer->buffer[_rx_buffer->tail];
    _rx_buffer->tail = (unsigned int)(_rx_buffer->tail + 1) % SERIAL_BUFFER_SIZE;
    return c;
  }
}

int HardwareSerial::availableForWrite(void)
{
/* For NUC131 */
#if defined(__NUC131__)
  if(UART_IS_TX_FULL(uart_device)) {
	  return 0;
  } else {
	  return (int)(UART0_FIFO_SIZE - ((uart_device->FSR & UART_FSR_TX_POINTER_Msk)>>UART_FSR_TX_POINTER_Pos));
  }
#else
  return 1;	
#endif
}

int HardwareSerial::available(void) {    
   return (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % SERIAL_BUFFER_SIZE;
}

size_t HardwareSerial::write(const uint8_t ch) {
	while(UART_IS_TX_FULL(uart_device));
#if defined(__M451__)  
	uart_device->DAT = ch;
	return 1;
#elif defined(__NUC240__)||defined(__NUC131__)||defined(__NANO100__)
	uart_device->THR = ch;
	return 1;
#elif defined(__NANO1X2__)||defined(M480) 
	UART_WRITE(uart_device,ch);
#else
	UART_WRITE(uart_device,ch);  /*default*/
#endif
	return 1;
}

void HardwareSerial::flush(void) {
#if defined(__M451__)||defined(M480)   
  while( !(uart_device->FIFOSTS & UART_FIFOSTS_TXEMPTY_Msk) );
#endif
  /* No need to implement because we use hardware UART and it is with hardware FIFO*/
}


int HardwareSerial::peek( void ) {	
  if (_rx_buffer->head == _rx_buffer->tail) {
    return -1;
  } else {
    return _rx_buffer->buffer[_rx_buffer->tail];
  }
}
