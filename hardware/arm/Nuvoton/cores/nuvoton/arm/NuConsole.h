/****************************************************************************
 * @file     NuConsole.h
 * @version  V1.01
 * $Revision: 0 $
 * $Date: 17/02/23 0:00p $
 * @brief    
 *
 * @note
 * Copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/


/* add by huaweiwx@sina.com 2018.11.20 for arduino
// uint32_t NuConsole_availableForWrite(void);
// int NuConsole_peek(void);
// uint32_t NuConsole_available(void);
// uint32_t NuConsole_Read(uint8_t *pucBuffer, uint32_t uNumBytes);
// class NuConsoleCLASS
*/

#ifndef __NUCONSOLE_H__
#define __NUCONSOLE_H__

#include "Arduino.h"
#include <stdbool.h>

// Returns if we are in an interrupt
inline bool isInterrupt() {
    return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}


#ifndef NUCOSOLE_TX_BUFFER_SIZE
#define NUCOSOLE_TX_BUFFER_SIZE           1024
#endif
#ifndef NUCOSOLE_RX_BUFFER_SIZE    
#define NUCOSOLE_RX_BUFFER_SIZE           32
#endif
#define NUCONSOLE_FIFO_DEFAULT_MODE       NUCONSOLE_FIFO_MODE_BLOCKING //or NUCONSOLE_FIFO_MODE_NON_BLOCKING

#define NUCONSOLE_MAGIC_ID                "NuConsole"

#define NUCONSOLE_FIFO_MODE_BLOCKING     (0x0)
#define NUCONSOLE_FIFO_MODE_NON_BLOCKING (0x1)
#define NUCONSOLE_FIFO_MODE_MASK         (0x1)

typedef struct
{
	uint8_t *pucBuffer;
	uint32_t uSize;
	volatile uint32_t uHead;
	volatile uint32_t uTail;
	uint32_t uMode;
} NUCOSOLE_FIFO;

typedef struct
{
	uint8_t aucMagicID[12];
	NUCOSOLE_FIFO aTxFIFO;
	NUCOSOLE_FIFO aRxFIFO; 
} NUCONSOLE_INFOBLOCK;

#ifdef __cplusplus
extern "C"
{
#endif
// Internal: what will be the

void     NuConsole_Init(void);
void     NuConsole_ConfigBuffer(uint32_t uTxFIFO_Mode);

uint32_t NuConsole_availableForWrite(void);
uint32_t NuConsole_Write(const uint8_t *pucBuffer, uint32_t uNumBytes);

int      NuConsole_peek(void);
uint32_t NuConsole_available(void);
uint32_t NuConsole_Read(uint8_t *pucBuffer, uint32_t uNumBytes);

#ifdef __cplusplus
}

extern "C" int setPrintOutput(Print *p);

#include "Stream.h"
class NuConsoleCLASS : public Stream {

  public:
//    NuConsoleClass() {};

    /* Set up/tear down */
    void begin(uint32_t baud = 115200) {
      UNUSED(baud);
      NuConsole_Init();
    }

#if __LOG_LEVEL  /*__LOG_LEVEL > 0*/
    __deprecated("setRouteLoc only supports real serial port, NuConsoleClass is virtual serial port and it's ignored here. (huaweiwx)")
#endif
    void setRouteLoc(uint8_t loc){
		UNUSED(loc);
	}
    /* I/O */
    int available( void ) {
      return NuConsole_available();
    }
    int read( void ) {
      uint8_t c;
      NuConsole_Read(&c, 1);
      return c;
    }

    int availableForWrite(void) {
      return NuConsole_availableForWrite();
    }

    int peek(void ){
		return NuConsole_peek();
	}

    void flush( void ) {} ;

    size_t write( const uint8_t ch ) {
      return NuConsole_Write(&ch, 1);
    }

    using Print::write; // pull in write(str) and write(buf, size) from Print
	
    void end(void) {}

    operator bool() {
      return true;
    }; // UART always active
};

extern  NuConsoleCLASS NuConsole;
#endif  //__cplusplus

#endif  //__NUCONSOLE_H__
