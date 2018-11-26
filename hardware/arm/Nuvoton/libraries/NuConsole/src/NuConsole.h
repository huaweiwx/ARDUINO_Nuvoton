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

#ifndef __NUCONSOLE_H__
#define __NUCONSOLE_H__

#include "Arduino.h"
#include <inttypes.h>

#include "NuConsole_Config.h"
#include "NuConsole.h"

#define NUCONSOLE_MAGIC_ID "NuConsole"

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

void NuConsole_Init(void);
void NuConsole_ConfigBuffer(uint32_t uTxFIFO_Mode);

uint32_t NuConsole_availableForWrite(void);
uint32_t NuConsole_Write(const uint8_t *pucBuffer, uint32_t uNumBytes);

uint32_t NuConsole_available(void);
uint32_t NuConsole_Read(uint8_t *pucBuffer, uint32_t uNumBytes);

#ifdef __cplusplus
}

#include "Stream.h"
class NuConsoleCLASS : public Stream {

  public:
    NuConsoleClass() {};

    /* Set up/tear down */
    void begin(uint32_t baud = 115200) {
      UNUSED(baud);
      NuConsole_Init();
    }
	
    void end(void) {}

    /* I/O */
    int available( void ) {
      return NuConsole_available();
    }
    //    int peek( void ) ;
    int read( void ) {
      char c;
      NuConsole_Read(&c, 1);
      return c;
    }

    int availableForWrite(void) {
      return NuConsole_availableForWrite();
    }
	
    int peek( void ){
		return -1;
	}

    void flush( void ) {} ;

    size_t write( const uint8_t ch ) {
      return NuConsole_Write(&ch, 1);
    }

    using Print::write; // pull in write(str) and write(buf, size) from Print
	
    operator bool() {
      return true;
    }; // UART always active
};

extern  NuConsoleCLASS NuConsole;
#endif

#endif
