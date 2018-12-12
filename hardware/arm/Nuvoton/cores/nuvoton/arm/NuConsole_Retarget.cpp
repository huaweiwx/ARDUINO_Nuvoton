/****************************************************************************
 * @file     NuConsole_Retarget.c
 * @version  V1.01
 * $Revision: 0 $
 * $Date: 17/02/23 0:00p $
 * @brief    Low-level functions for using printf()/getchar() via NuConsole
 *
 * @note
 * Copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "NuConsole.h"
#include <stdio.h>
#include "systemDrivers.h"

#include "unistd.h"
#include "cmsis_gcc.h"

NuConsoleCLASS NuConsole;
static const int print_fileno = 3;

/**
  * @brief   C library retargetting
  * @param   ch Character to send out
  * @return  None
  */
extern "C"
void _ttywrch(int ch)
{
	NuConsole_Write((const uint8_t *)&ch, 1);
	return;
}

/**
  * @brief      Write character to stream
  * @param[in]  ch       Character to be written. The character is passed as its int promotion.
  * @param[in]  stream   Pointer to a FILE object that identifies the stream where the character is to be written.
  * @return     If there are no errors, the same character that has been written is returned.
  *             If an error occurs, EOF is returned and the error indicator is set (see ferror).
  * @note       The above descriptions are copied from http://www.cplusplus.com/reference/clibrary/cstdio/fputc/.
  *
  */
//extern "C"
//int fputc(int ch, FILE *stream)
//{
//	NuConsole_Write((const uint8_t *)&ch, 1);
//	return ch;
//}

/**
  * @brief      Get character from NuConsole RX FIFO
  * @param[in]  stream   Pointer to a FILE object that identifies the stream on which the operation is to be performed.
  * @return     The character read from NuConsole RX FIFO
  *
  */
//extern "C"
//int fgetc(FILE *stream)
//{
//	int ch;
//	NuConsole_Read((uint8_t *)&ch, 1);
//	return ch;
//}

static Print *print;

int setPrintOutput(Print *p) {
    if (p == NULL) {
        print = NULL;
        return 0;
    }

    if (isInterrupt() && print != NULL) {
        return 0;
    }

    while(print != NULL);
    print = p;

    return print_fileno;
}

extern "C" int _write(int file, char *ptr, int len ) {
	if (file == STDOUT_FILENO){
		return Serial.write(ptr, len);
	} 
	if (file == STDERR_FILENO) {
		Serial.write(ptr, len);
		Serial.flush();
		return len;
	} 
	if (file == print_fileno) {
		if (print != NULL) return print->write(ptr, len);
	}
	
	// TODO show error
	return 0;  //return no-void warning add by huaweiwx@sina.com 2017.7.21
}

/*** (C) COPYRIGHT 2016 Nuvoton Technology Corp. ***/
