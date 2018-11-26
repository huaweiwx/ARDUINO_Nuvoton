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
#include <stdio.h>
#include "NuConsole.h"

/**
  * @brief   C library retargetting
  * @param   ch Character to send out
  * @return  None
  */
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
int fputc(int ch, FILE *stream)
{
	NuConsole_Write((const uint8_t *)&ch, 1);
	return ch;
}

/**
  * @brief      Get character from NuConsole RX FIFO
  * @param[in]  stream   Pointer to a FILE object that identifies the stream on which the operation is to be performed.
  * @return     The character read from NuConsole RX FIFO
  *
  */
int fgetc(FILE *stream)
{
	int ch;
	NuConsole_Read((uint8_t *)&ch, 1);
	return ch;
}

/*** (C) COPYRIGHT 2016 Nuvoton Technology Corp. ***/
