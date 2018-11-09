/**************************************************************************//**
 * @file     retarget.c
 * @version  V1.00
 * $Revision: 7 $
 * $Date: 13/10/07 3:50p $ 
 * @brief    Mini51 series retarget source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/ 
#include <stdio.h>
#include "Mini51Series.h"

#if defined ( __CC_ARM   )
#if (__ARMCC_VERSION < 400000)
#else
/* Insist on keeping widthprec, to avoid X propagation by benign code in C-lib */
#pragma import _printf_widthprec
#endif
#endif

/* Un-comment this line to disable all printf and getchar. getchar() will always return 0x00*/
//#define DISABLE_UART

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

#if !(defined(__ICCARM__) && (__VER__ >= 6010000))
struct __FILE { int handle; /* Add whatever you need here */ };
#endif
FILE __stdout;
FILE __stdin;

#if defined(DEBUG_ENABLE_SEMIHOST)
/* The static buffer is used to speed up the semihost */
static char g_buf[16];
static char g_buf_len = 0;

/* The function to process semihosted command */

extern int SH_DoCommand(int n32In_R0, int n32In_R1, int *pn32Out_R0);
#endif


/**
  * @brief  Write a char to UART.
  * @param  ch The character sent to UART.
  * @return None
  */

void SendChar_ToUART(int ch)
{
#ifndef DISABLE_UART
        while(UART->FSR & UART_FSR_TX_FULL_Msk);
        UART->THR = ch;
        if(ch == '\n'){
            while(UART->FSR & UART_FSR_TX_FULL_Msk);
            UART->THR = '\r';
        }
#endif
}


/**
  * @brief  Write a char to debug console.
  * @param  ch The character sent to debug console
  * @return None
  */

void SendChar(int ch)
{
#if defined(DEBUG_ENABLE_SEMIHOST)
    g_buf[g_buf_len++] = ch;
    g_buf[g_buf_len] = '\0';
    if(g_buf_len + 1 >= sizeof(g_buf) || ch == '\n' || ch == '\0')
    {

        /* Send the char */

        if(SH_DoCommand(0x04, (int)g_buf, NULL) != 0)
        {
            g_buf_len = 0;
            return;
        }
        else
        {
            int i;

            for(i=0;i<g_buf_len;i++)
                SendChar_ToUART(g_buf[i]);
            g_buf_len = 0;
        }
    }
#else
    SendChar_ToUART(ch);
#endif
}


/**
  * @brief  Read a char from debug console.
  * @param  None
  * @return Received character from debug console
  * @note   This API waits until UART debug port or semihost input a character
  */

char GetChar(void)
{
#if defined(DEBUG_ENABLE_SEMIHOST)
# if defined ( __CC_ARM   )
    int nRet;
    while(SH_DoCommand(0x101, 0, &nRet) != 0)
    {
        if(nRet != 0)
        {
            SH_DoCommand(0x07, 0, &nRet);
            return (char)nRet;
        }
    }
# else
    int nRet;
    while(SH_DoCommand(0x7, 0, &nRet) != 0)  
    {
        if(nRet != 0)
            return (char)nRet;
    }
# endif    
#endif
#ifndef DISABLE_UART
        while (1){
            if(!(UART->FSR & UART_FSR_RX_EMPTY_Msk))
            {
                return (UART->RBR);
                
            }
        }
#else
    return(0);
#endif        
}


/**
  * @brief  Check whether UART receive FIFO is empty or not.
  * @param  None
  * @return UART Rx FIFO empty status
  * @retval 1 Indicates at least one character is available in UART Rx FIFO
  * @retval 0 UART Rx FIFO is empty
  */
int kbhit(void)
{
#ifndef DISABLE_UART
    return !(UART->FSR & UART_FSR_RX_EMPTY_Msk);
#else
    return(0);
#endif
}

/**
  * @brief  Check whether UART transmit FIFO is empty or not.
  * @param  None
  * @return UART Tx FIFO empty status
  * @retval 1 UART Tx FIFO is empty
  * @retval 0 UART Tx FIFO is not empty
  */
int IsDebugFifoEmpty(void)
{
#ifndef DISABLE_UART
    return (UART->FSR & UART_FSR_TE_FLAG_Msk) ? 1 : 0;
#else
    return(1);
#endif    

}

/*---------------------------------------------------------------------------------------------------------*/
/* C library retargetting                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
void _ttywrch(int ch)
{
  SendChar(ch);
  return;
}

int fputc(int ch, FILE *f)
{
  SendChar(ch);
  return ch;
}

int fgetc(FILE *f) {
   return (GetChar());
}


int ferror(FILE *f) {
  return EOF;
}

#ifdef DEBUG_ENABLE_SEMIHOST 
# ifdef __ICCARM__
void __exit(int return_code) {

    /* Check if link with ICE */

    if(SH_DoCommand(0x18, 0x20026, NULL) == 0)
    {
        /* Make sure all message is print out */

        while(IsDebugFifoEmpty() == 0);
    }
label:  goto label;  /* endless loop */
}
# else
void _sys_exit(int return_code) {

    /* Check if link with ICE */
    if(SH_DoCommand(0x18, 0x20026, NULL) == 0)
    {
        /* Make sure all message is print out */
        while(IsDebugFifoEmpty() == 0);
    }
label:  goto label;  /* endless loop */
}
# endif
#endif
/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/

