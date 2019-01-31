/****************************************************************************
 * @file     NuConsole_Retarget.cpp
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
#include <reent.h>        // required for _write_r

NuConsoleCLASS   NuConsole;
static const int print_fileno = 3;

static Print *print;
static Print *stdPrint = &Serial;
static Print *errPrint = &Serial;

/**
  * @brief   C library retargetting
  * @param   ch Character to send out
  * @return  None
  */
//extern "C"
//void _ttywrch(int ch)
//{
//	NuConsole_Write((const uint8_t *)&ch, 1);
//	return;
//}

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

extern "C" int setPrintOutput(Print *p) {
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

extern "C" void setStdPrintDev(Print *p,int file) {
    if((file == STDOUT_FILENO)||(file == STDIN_FILENO)){
		stdPrint = p;
	}
#if (USE_ICEPRINTERR < 1) && (USE_SWOPRINTERR < 1)  /*NUVOTON not swo , USE_SWOPRINTERR compatible with stm32/efm32*/
	else if(file == STDERR_FILENO){
		errPrint = p;		
	}
#endif
}

extern "C" int _write(int file, char *ptr, int len ) {
	if (file == STDOUT_FILENO){
		return stdPrint->write(ptr, len);
	} 
	if (file == STDERR_FILENO) {
#if (USE_ICEPRINTERR < 1) && (USE_SWOPRINTERR < 1)  /*NUVOTON not swo , USE_SWOPRINTERR compatible with stm32/efm32*/
		errPrint->write(ptr, len);
		((Stream *)errPrint)->flush();
#else
	    NuConsole_Write(ptr,len);
#endif
		return len;
	} 
	if (file == print_fileno) {
		if (print != NULL) return print->write(ptr, len);
	}
	
	// TODO show error
	return 0;  //return no-void warning add by huaweiwx@sina.com 2017.7.21
}

struct _reent;
extern "C"  int _write_r(struct _reent *r, int file, const void *ptr, size_t len) {
  (void) r;     /* Not used, avoid warning */
  _write(file, (char *)ptr, (int)len);
  return len;
}

/*** (C) COPYRIGHT 2016 Nuvoton Technology Corp. ***/
