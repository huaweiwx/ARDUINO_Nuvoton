/******************************************************************************
   The MIT License

   Copyright (c) 2010 Perry Hung.

   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without
   restriction, including without limitation the rights to use, copy,
   modify, merge, publish, distribute, sublicense, and/or sell copies
   of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 *****************************************************************************/

/**
   @file HardwareSerial.cpp
   @brief Wirish serial port implementation.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

/*default*/
#ifndef UART0_ROUTELOC
#define UART0_ROUTELOC 0
#endif
#ifndef UART1_ROUTELOC
#define UART1_ROUTELOC 0
#endif
#ifndef UART2_ROUTELOC
#define UART2_ROUTELOC 0
#endif
#ifndef UART3_ROUTELOC
#define UART3_ROUTELOC 0
#endif
#ifndef UART4_ROUTELOC
#define UART4_ROUTELOC 0
#endif
#ifndef UART5_ROUTELOC
#define UART5_ROUTELOC 0
#endif

#if  defined(M480)
  #if(UART_MAX_COUNT>0)
  ring_buffer rx_buffer0 = { { 0 }, 0, 0};
  HardwareSerial Serial0(UART_Desc[0].U,0, UART0_ROUTELOC, CLK_CLKSEL1_UART0SEL_PLL, 1, UART_Desc[0].irq, &rx_buffer0);
  #endif
  
  #if(UART_MAX_COUNT>1)
  ring_buffer rx_buffer1 = { { 0 }, 0, 0};
  HardwareSerial Serial1(UART_Desc[1].U,1, UART1_ROUTELOC, CLK_CLKSEL1_UART1SEL_PLL, 1, UART_Desc[1].irq, &rx_buffer1);
  #endif
  
  #if(UART_MAX_COUNT>2)
  ring_buffer rx_buffer2 = { { 0 }, 0, 0};
  HardwareSerial Serial2(UART_Desc[2].U,2, UART2_ROUTELOC, CLK_CLKSEL3_UART2SEL_PLL, 1, UART_Desc[2].irq, &rx_buffer2);
  #endif

  #if(UART_MAX_COUNT>3)
  ring_buffer rx_buffer3 = { { 0 }, 0, 0};
  HardwareSerial Serial3(UART_Desc[3].U,3, UART3_ROUTELOC, CLK_CLKSEL3_UART3SEL_PLL, 1, UART_Desc[3].irq, &rx_buffer3);
  #endif
  
  #if(UART_MAX_COUNT>4)
  ring_buffer rx_buffer4 = { { 0 }, 0, 0};
  HardwareSerial Serial4(UART_Desc[4].U,4, UART4_ROUTELOC, CLK_CLKSEL3_UART4SEL_PLL, 1, UART_Desc[4].irq, &rx_buffer4);
  #endif
  
  #if(UART_MAX_COUNT>5)
  ring_buffer rx_buffer5 = { { 0 }, 0, 0};
  HardwareSerial Serial5(UART_Desc[5].U,5, UART5_ROUTELOC, CLK_CLKSEL3_UART5SEL_PLL, 1, UART_Desc[5].irq, &rx_buffer5);
  #endif
  
  #if(UART_MAX_COUNT>0)
  extern "C"
  void UART0_IRQHandler(void) {
    while (UART_GET_INT_FLAG(UART0, UART_IER_RDA_IEN_Msk))
    {
      unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer0.tail) {
        rx_buffer0.buffer[rx_buffer0.head] = UART_READ(UART0);
        rx_buffer0.head = i;
      }
    }
  }
  #endif
  
  #if(UART_MAX_COUNT>1)
  extern "C"
  void UART1_IRQHandler(void) {
    while (UART_GET_INT_FLAG(UART1, UART_IER_RDA_IEN_Msk)) {
      unsigned int i = (rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer1.tail) {
        rx_buffer1.buffer[rx_buffer1.head] = UART_READ(UART1);
        rx_buffer1.head = i;
      }
    }
  }
  #endif
  #if(UART_MAX_COUNT>2)
  extern "C"
  void UART2_IRQHandler(void) {
    while (UART_GET_INT_FLAG(UART2, UART_IER_RDA_IEN_Msk)) {
      unsigned int i = (rx_buffer2.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer2.tail) {
        rx_buffer2.buffer[rx_buffer2.head] = UART_READ(UART2);
        rx_buffer2.head = i;
      }
    }
  }
  #endif
  #if(UART_MAX_COUNT>3)
  extern "C"
  void UART3_IRQHandler(void) {
    while (UART_GET_INT_FLAG(UART3, UART_IER_RDA_IEN_Msk)) {
      unsigned int i = (rx_buffer3.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer3.tail) {
        rx_buffer3.buffer[rx_buffer3.head] = UART_READ(UART3);
        rx_buffer3.head = i;
      }
    }
  }
  #endif
  #if(UART_MAX_COUNT>4)
  extern "C"
  void UART4_IRQHandler(void) {
    while (UART_GET_INT_FLAG(UART4, UART_IER_RDA_IEN_Msk)) {
      unsigned int i = (rx_buffer4.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer4.tail) {
        rx_buffer4.buffer[rx_buffer4.head] = UART_READ(UART4);
        rx_buffer4.head = i;
      }
    }
  }
  #endif
  #if(UART_MAX_COUNT>5)
  extern "C" void UART5_IRQHandler(void) {
    while (UART_GET_INT_FLAG(UART5, UART_IER_RDA_IEN_Msk)) {
      unsigned int i = (rx_buffer5.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer5.tail) {
        rx_buffer5.buffer[rx_buffer5.head] = UART_READ(UART5);
        rx_buffer5.head = i;
      }
    }
  }
  #endif

#elif defined(M031Series)|| defined(NUC029xDE)|| defined(NUC029xEE)|| defined(NUC029xGE)||defined(__NUC131__)||defined(NUC200Series)
//uart02
  #ifndef CLK_CLKSEL1_UART0SEL_PLL
      #ifdef  CLK_CLKSEL1_UART_S_PLL
        #define CLK_CLKSEL1_UART0SEL_PLL CLK_CLKSEL1_UART_S_PLL
      #elif defined(CLK_CLKSEL1_UARTSEL_PLL)  	  
        #define CLK_CLKSEL1_UART0SEL_PLL CLK_CLKSEL1_UARTSEL_PLL
	  #endif
  #endif
  #ifndef CLK_CLKSEL3_UART2SEL_PLL
      #ifdef  CLK_CLKSEL1_UART_S_PLL
        #define CLK_CLKSEL3_UART2SEL_PLL CLK_CLKSEL1_UART_S_PLL
      #elif defined(CLK_CLKSEL1_UARTSEL_PLL)  	  
        #define CLK_CLKSEL3_UART2SEL_PLL CLK_CLKSEL1_UARTSEL_PLL
	  #endif
  #endif
  ring_buffer rx_buffer0 = { { 0 }, 0, 0};
  HardwareSerial Serial0(UART_Desc[0].U, 0,UART0_ROUTELOC, CLK_CLKSEL1_UART0SEL_PLL, 1, UART_Desc[0].irq, &rx_buffer0);
  
  ring_buffer rx_buffer2 = { { 0 }, 0, 0};
  HardwareSerial Serial2(UART_Desc[2].U, 2,UART2_ROUTELOC, CLK_CLKSEL3_UART2SEL_PLL, 1, UART_Desc[2].irq,  &rx_buffer2);
 
  extern "C"
  void UART02_IRQHandler(void){
    while (UART_GET_INT_FLAG(UART0, UART_IER_RDA_IEN_Msk)){
      unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer0.tail) {
        rx_buffer0.buffer[rx_buffer0.head] = UART_READ(UART0);
        rx_buffer0.head = i;
      }
    }
    while (UART_GET_INT_FLAG(UART2, UART_IER_RDA_IEN_Msk)){
     unsigned int i = (rx_buffer2.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer2.tail) {
        rx_buffer2.buffer[rx_buffer2.head] = UART_READ(UART2);
        rx_buffer2.head = i;
      }
    }
  }
  
  #if(UART_MAX_COUNT>1)
    #ifndef CLK_CLKSEL1_UART1SEL_PLL 
      #ifdef  CLK_CLKSEL1_UART_S_PLL
        #define CLK_CLKSEL1_UART1SEL_PLL CLK_CLKSEL1_UART_S_PLL
	  #else	
        #define CLK_CLKSEL1_UART1SEL_PLL CLK_CLKSEL1_UARTSEL_PLL
	  #endif
    #endif
  ring_buffer rx_buffer1 = { { 0 }, 0, 0};
  HardwareSerial Serial1(UART_Desc[1].U, 1,UART1_ROUTELOC, CLK_CLKSEL1_UART1SEL_PLL, 1, UART_Desc[1].irq, &rx_buffer1);
  
  extern "C"
  void UART1_IRQHandler(void){
    while (UART_GET_INT_FLAG(UART1, UART_IER_RDA_IEN_Msk)){
      unsigned int i = (rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer1.tail) {
        rx_buffer1.buffer[rx_buffer1.head] = UART_READ(UART1);
        rx_buffer1.head = i;
      }
    }
  }
  #endif
  
  #if(UART_MAX_COUNT>3)
    #ifndef CLK_CLKSEL1_UART3SEL_PLL 
      #ifdef  CLK_CLKSEL1_UART_S_PLL
        #define CLK_CLKSEL1_UART3SEL_PLL CLK_CLKSEL1_UART_S_PLL
	  #else	
        #define CLK_CLKSEL1_UART3SEL_PLL CLK_CLKSEL4_UARTSEL_PLL
	  #endif
    #endif
  ring_buffer rx_buffer3 = { { 0 }, 0, 0};
  HardwareSerial Serial3(UART_Desc[3].U, 3,UART3_ROUTELOC, CLK_CLKSEL1_UART3SEL_PLL, 1, UART_Desc[3].irq, &rx_buffer1);
  
  extern "C"
  void UART3_IRQHandler(void){
    while (UART_GET_INT_FLAG(UART3, UART_IER_RDA_IEN_Msk)){
      unsigned int i = (rx_buffer3.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer3.tail) {
        rx_buffer3.buffer[rx_buffer3.head] = UART_READ(UART3);
        rx_buffer3.head = i;
      }
    }
  }
  #endif
  
  #if(UART_MAX_COUNT>4)   /*NUC029xDE*/
    #ifndef CLK_CLKSEL1_UART4SEL_PLL 
      #ifdef  CLK_CLKSEL1_UART_S_PLL
        #define CLK_CLKSEL1_UART4SEL_PLL CLK_CLKSEL1_UART_S_PLL
	  #else	
        #define CLK_CLKSEL1_UART4SEL_PLL CLK_CLKSEL4_UARTSEL_PLL
	  #endif
    #endif
  ring_buffer rx_buffer4 = { { 0 }, 0, 0};
  HardwareSerial Serial3(UART_Desc[4].U, 4,UART4_ROUTELOC, CLK_CLKSEL1_UART4SEL_PLL, 1, UART_Desc[4].irq, &rx_buffer1);
  
  extern "C"
  void UART4_IRQHandler(void){
    while (UART_GET_INT_FLAG(UART4, UART_IER_RDA_IEN_Msk)){
      unsigned int i = (rx_buffer4.head + 1) % SERIAL_BUFFER_SIZE;
      if (i != rx_buffer4.tail) {
        rx_buffer4.buffer[rx_buffer4.head] = UART_READ(UART4);
        rx_buffer4.head = i;
      }
    }
  }
  #endif

#else
  #ifndef CLK_CLKSEL1_UART_S_PLL
    #ifdef  CLK_CLKSEL1_UARTSEL_PLL
    #  define CLK_CLKSEL1_UART_S_PLL CLK_CLKSEL1_UARTSEL_PLL  //mini58
    #endif
  #endif
  #if(UART_MAX_COUNT>0)
    ring_buffer rx_buffer0 = { { 0 }, 0, 0};  /* for UAR0 */
    HardwareSerial Serial0(UART_Desc[0].U, 0,UART0_ROUTELOC, CLK_CLKSEL1_UART_S_PLL, 1, UART_Desc[0].irq, &rx_buffer0);
  #endif
  
  #if(UART_MAX_COUNT>1)
    ring_buffer rx_buffer1 = { { 0 }, 0, 0}; /* for UAR1 */
    HardwareSerial Serial1(UART_Desc[1].U, 1,UART1_ROUTELOC, CLK_CLKSEL1_UART_S_PLL, 1, UART_Desc[1].irq, &rx_buffer1);
  #endif
  
  #if defined(UART0)
    #if(UART_MAX_COUNT>0)
    extern "C"
    void UART0_IRQHandler(void) {
      while (UART_GET_INT_FLAG(UART0, UART_IER_RDA_IEN_Msk))  {
        unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
        if (i != rx_buffer0.tail) {
          rx_buffer0.buffer[rx_buffer0.head] = UART_READ(UART0);
          rx_buffer0.head = i;
        }
      }
    }
    #endif
    
    #if(UART_MAX_COUNT>1)
    extern "C"
    void UART1_IRQHandler(void){
      while (UART_GET_INT_FLAG(UART1, UART_IER_RDA_IEN_Msk)){
        unsigned int i = (rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
        if (i != rx_buffer1.tail) {
          rx_buffer1.buffer[rx_buffer1.head] = UART_READ(UART1);
          rx_buffer1.head = i;
        }
      }
    }
    #endif
  #else
    extern "C"
    void UART_IRQHandler(void){   /*for mini51/nuc029FAE/NUC029xAN*/
      while (UART_GET_INT_FLAG(UART, UART_IER_RDA_IEN_Msk)){
        unsigned int i = (rx_buffer0.head + 1) % SERIAL_BUFFER_SIZE;
        if (i != rx_buffer0.tail) {
          rx_buffer0.buffer[rx_buffer0.head] = UART_READ(UART);
          rx_buffer0.head = i;
        }
      }
    }
  #endif
  
#endif

#if 0
#if(UART_MAX_COUNT>0)
void serialEvent() __attribute__((weak));
#endif

void serialEventRun(void)
{
#if(UART_MAX_COUNT>0)
  if (Serial.available()) serialEvent();
#endif
}
#endif

HardwareSerial::HardwareSerial(UART_T *uart_device,
                               uint8_t ucIdx,
                               uint8_t ucLoc,
                               uint32_t u32ClkSrc,
                               uint32_t u32ClkDiv,
                               IRQn_Type u32IrqId,
                               ring_buffer *rx_buffer) {
  this->uart_device = uart_device;
  this->ucIdx = ucIdx;
  this->ucLoc = ucLoc;
  this->u32ClkSrc = u32ClkSrc;
  this->u32ClkDiv = u32ClkDiv;
  this->u32IrqId = u32IrqId;
  this->_rx_buffer = rx_buffer;
}

/*
   Set up/tear down
*/

void HardwareSerial::begin(uint32_t baud) {
  UART_Config(UART_Desc[this->ucIdx].pinAlt[this->ucLoc]);
  /* Enable IP clock */
  CLK_EnableModuleClock(UART_Desc[ucIdx].module);

#if defined(M480)|| defined(M031Series)
  /* Select IP clock source and clock divider */
  if (uart_device == UART0)
    CLK_SetModuleClock(UART_Desc[ucIdx].module, u32ClkSrc, CLK_CLKDIV0_UART0(u32ClkDiv));
  #if(UART_MAX_COUNT>1)
  else if (uart_device == UART1)
    CLK_SetModuleClock(UART_Desc[ucIdx].module, u32ClkSrc, CLK_CLKDIV0_UART1(u32ClkDiv));
  #endif
  #if(UART_MAX_COUNT>2)
  else if (uart_device == UART2)
    CLK_SetModuleClock(UART_Desc[ucIdx].module, u32ClkSrc, CLK_CLKDIV4_UART2(u32ClkDiv));
  #endif
  #if(UART_MAX_COUNT>3)
  else if (uart_device == UART3)
    CLK_SetModuleClock(UART_Desc[ucIdx].module, u32ClkSrc, CLK_CLKDIV4_UART3(u32ClkDiv));
  #endif
  #if(UART_MAX_COUNT>4)
  else if (uart_device == UART4)
    CLK_SetModuleClock(UART_Desc[ucIdx].module, u32ClkSrc, CLK_CLKDIV4_UART4(u32ClkDiv));
  #endif
  #if(UART_MAX_COUNT>5)
  else if (uart_device == UART5)
    CLK_SetModuleClock(UART_Desc[ucIdx].module, u32ClkSrc, CLK_CLKDIV4_UART5(u32ClkDiv));
  #endif


#else
  /* Select IP clock source and clock divider */
  CLK_SetModuleClock(UART_Desc[ucIdx].module, u32ClkSrc, CLK_CLKDIV_UART(u32ClkDiv));

#endif

  /* Reset IP */
  //SYS_ResetModule(UART_Desc[ucIdx].module);
  /* Enable Interrupt */
  UART_ENABLE_INT(uart_device, UART_IER_RDA_IEN_Msk);

  NVIC_EnableIRQ(u32IrqId);
  /* Configure UART and set UART Baudrate */
  UART_Open(uart_device, baud);
}

void HardwareSerial::end(void) {
  UART_Close(uart_device);
}

/*
   I/O
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

int HardwareSerial::availableForWrite(void){
  /* For NUC131 */
#if defined(__NUC131__)
  if (UART_IS_TX_FULL(uart_device)) {
    return 0;
  } else {
    return (int)(UART0_FIFO_SIZE - ((uart_device->FSR & UART_FSR_TX_POINTER_Msk) >> UART_FSR_TX_POINTER_Pos));
  }
#else
  return 1;
#endif
}

int HardwareSerial::available(void) {
  return (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % SERIAL_BUFFER_SIZE;
}

size_t HardwareSerial::write(const uint8_t ch) {
  while (UART_IS_TX_FULL(uart_device));
  UART_WRITE(uart_device, ch); 
  return 1;
}

void HardwareSerial::flush(void) {
#if UART_FIFOSTS_TXEMPTY_Msk
  while ( !(uart_device->FIFOSTS & UART_FIFOSTS_TXEMPTY_Msk) );
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
