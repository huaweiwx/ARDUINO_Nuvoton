/**************************************************************************//**
 * @file     scuart.c
 * @version  V3.00
 * $Revision: 7 $
 * $Date: 14/08/13 10:27a $
 * @brief    NUC200 series Smartcard UART mode (SCUART) driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "NUC200Series.h"

/** @addtogroup NUC200_Device_Driver NUC200 Device Driver
  @{
*/

/** @addtogroup NUC200_SCUART_Driver SCUART Driver
  @{
*/


/** @addtogroup NUC200_SCUART_EXPORTED_FUNCTIONS SCUART Exported Functions
  @{
*/

/**
  * @brief Disable smartcard uart interface.   
  * @param sc The pointer of smartcard module.
  * @return None
  * @details The function is used to disable smartcard interface UART mode.
  */
void SCUART_Close(SC_T* sc)
{
    sc->IER = 0;
    sc->UACTL = 0;
    sc->CTL = 0;

}

/**
  * @brief Enable smartcard uart interface. 
  * @param[in] sc The pointer of smartcard module.
  * @param[in] u32baudrate Target baudrate of smartcard module.
  * @return Actual baudrate of smartcard mode.
  * @details This function use to enable smartcard module UART mode and set baudrate.
  * @note This function configures character width to 8 bits, 1 stop bit, and no parity.
  *       And can use \ref SCUART_SetLineConfig function to update these settings.
  */
uint32_t SCUART_Open(SC_T* sc, uint32_t u32baudrate)
{
    uint32_t u32ClkSrc, u32Clk, u32Div;

    if(sc == SC0)
        u32ClkSrc = (CLK->CLKSEL3 & CLK_CLKSEL3_SC0_S_Msk) >> CLK_CLKSEL3_SC0_S_Pos;
    else if(sc == SC1)
        u32ClkSrc = (CLK->CLKSEL3 & CLK_CLKSEL3_SC1_S_Msk) >> CLK_CLKSEL3_SC1_S_Pos;
    else // SC2
        u32ClkSrc = (CLK->CLKSEL3 & CLK_CLKSEL3_SC2_S_Msk) >> CLK_CLKSEL3_SC2_S_Pos;

    // Get smartcard module clock
    if(u32ClkSrc == 0)
        u32Clk = __HXT;
    else if(u32ClkSrc == 1)
        u32Clk = CLK_GetPLLClockFreq();
    else
        u32Clk = __HIRC;


    if(sc == SC0)
        u32Clk /= ((CLK->CLKDIV1 & CLK_CLKDIV1_SC0_N_Msk) + 1);
    else if(sc == SC1)
        u32Clk /= (((CLK->CLKDIV1 & CLK_CLKDIV1_SC1_N_Msk) >> CLK_CLKDIV1_SC1_N_Pos) + 1);
    else // SC2
        u32Clk /= (((CLK->CLKDIV1 & CLK_CLKDIV1_SC2_N_Msk) >> CLK_CLKDIV1_SC2_N_Pos) + 1);

    // Calculate divider for target baudrate
    u32Div = (u32Clk + (u32baudrate >> 1) - 1) / u32baudrate - 1;

    sc->CTL = SC_CTL_SC_CEN_Msk | SC_CTL_SLEN_Msk;  // Enable smartcard interface and stop bit = 1
    sc->UACTL = SCUART_CHAR_LEN_8 | SCUART_PARITY_NONE | SC_UACTL_UA_MODE_EN_Msk; // Enable UART mode, disable parity and 8 bit per character
    sc->ETUCR = u32Div;

    return(u32Clk / u32Div);
}

/**
  * @brief Read data from Sc UART interface.   
  * @param[in] sc The pointer of smartcard module.
  * @param[in] pu8RxBuf The buffer to store receive the data.
  * @param[in] u32ReadBytes Target number of characters to receive.
  * @return Actual character number reads to buffer.
  * @details The function is used to read Rx data from RX FIFO.
  * @note This function does not block and return immediately if there's no data available.
  */
uint32_t SCUART_Read(SC_T* sc, uint8_t *pu8RxBuf, uint32_t u32ReadBytes)
{
    uint32_t u32Count;

    for(u32Count = 0; u32Count < u32ReadBytes; u32Count++)
    {
        if(SCUART_GET_RX_EMPTY(sc))   // no data available
        {
            break;
        }
        pu8RxBuf[u32Count] = SCUART_READ(sc);    // get data from FIFO
    }

    return u32Count;
}

/**
  * @brief This function use to config smartcard UART mode line setting.
  * @param[in] sc The pointer of smartcard module.
  * @param[in] u32Baudrate Target baudrate of smartcard module. If this value is 0, UART baudrate will not change.
  * @param[in] u32DataWidth The data length, could be:
  *                 - \ref SCUART_CHAR_LEN_5
  *                 - \ref SCUART_CHAR_LEN_6
  *                 - \ref SCUART_CHAR_LEN_7
  *                 - \ref SCUART_CHAR_LEN_8
  * @param[in] u32Parity The parity setting, could be:
  *                 - \ref SCUART_PARITY_NONE
  *                 - \ref SCUART_PARITY_ODD
  *                 - \ref SCUART_PARITY_EVEN
  * @param[in] u32StopBits The stop bit length, could be:
  *                 - \ref SCUART_STOP_BIT_1
  *                 - \ref SCUART_STOP_BIT_2
  * @return Actual baudrate of smartcard.
  * @details Smartcard UART mode is operated in LIN data frame.
  */
uint32_t SCUART_SetLineConfig(SC_T* sc, uint32_t u32Baudrate, uint32_t u32DataWidth, uint32_t u32Parity, uint32_t  u32StopBits)
{
    uint32_t u32ClkSrc, u32Clk, u32Div;
    // Get smartcard module clock
    if(sc == SC0)
        u32ClkSrc = (CLK->CLKSEL3 & CLK_CLKSEL3_SC0_S_Msk) >> CLK_CLKSEL3_SC0_S_Pos;
    else if(sc == SC1)
        u32ClkSrc = (CLK->CLKSEL3 & CLK_CLKSEL3_SC1_S_Msk) >> CLK_CLKSEL3_SC1_S_Pos;
    else // SC2
        u32ClkSrc = (CLK->CLKSEL3 & CLK_CLKSEL3_SC2_S_Msk) >> CLK_CLKSEL3_SC2_S_Pos;

    // Get smartcard module clock
    if(u32ClkSrc == 0)
        u32Clk = __HXT;
    else if(u32ClkSrc == 1)
        u32Clk = CLK_GetPLLClockFreq();
    else
        u32Clk = __HIRC;


    if(sc == SC0)
        u32Clk /= (CLK->CLKDIV1 & CLK_CLKDIV1_SC0_N_Msk);
    else if(sc == SC1)
        u32Clk /= ((CLK->CLKDIV1 & CLK_CLKDIV1_SC1_N_Msk) >> CLK_CLKDIV1_SC1_N_Pos);
    else // SC2
        u32Clk /= ((CLK->CLKDIV1 & CLK_CLKDIV1_SC2_N_Msk) >> CLK_CLKDIV1_SC2_N_Pos);

    if(u32Baudrate == 0)    // keep original baudrate setting
    {
        u32Div = sc->ETUCR & SC_ETUCR_ETU_RDIV_Msk;
    }
    else
    {
        // Calculate divider for target baudrate
        u32Div = (u32Clk + (u32Baudrate >> 1) - 1) / u32Baudrate - 1;
        sc->ETUCR = u32Div;
    }

    sc->CTL = u32StopBits | SC_CTL_SC_CEN_Msk;  // Set stop bit
    sc->UACTL = u32Parity | u32StopBits | SC_UACTL_UA_MODE_EN_Msk;  // Set character width and parity

    return(u32Clk / u32Div);
}

/**
  * @brief This function use to set receive timeout count.
  * @param[in] sc The pointer of smartcard module.
  * @param[in] u32TOC Rx timeout counter, using baudrate as counter unit. Valid range are 0~0x1FF,
  *                   set this value to 0 will disable timeout counter.
  * @return None
  * @details The time-out counter resets and starts counting whenever the RX buffer received a
  *          new data word. Once the counter decrease to 1 and no new data is received or CPU
  *          does not read any data from FIFO, a receiver time-out interrupt will be generated.
  */
void SCUART_SetTimeoutCnt(SC_T* sc, uint32_t u32TOC)
{
    sc->RFTMR = u32TOC;
}


/**
  * @brief Write data to Sc UART interface.  
  * @param[in] sc The pointer of smartcard module.
  * @param[in] pu8TxBuf The buffer containing data to send to transmit FIFO.
  * @param[in] u32WriteBytes Number of data to send.
  * @return None
  * @details This function is to write data into transmit FIFO to send data out.
  * @note This function blocks until all data write into FIFO.
  */
void SCUART_Write(SC_T* sc, uint8_t *pu8TxBuf, uint32_t u32WriteBytes)
{
    uint32_t u32Count;

    for(u32Count = 0; u32Count != u32WriteBytes; u32Count++)
    {
        while(SCUART_GET_TX_FULL(sc));  // Wait 'til FIFO not full
        sc->THR = pu8TxBuf[u32Count];    // Write 1 byte to FIFO
    }
}


/*@}*/ /* end of group NUC200_SCUART_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC200_SCUART_Driver */

/*@}*/ /* end of group NUC200_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
