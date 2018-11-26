/****************************************************************************
 * @file     NuConsole_Config.h
 * @version  V1.00
 * $Revision: 0 $
 * $Date: 16/07/06 0:00p $
 * @brief    
 *
 * @note
 * Copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#ifndef __NUCONSOLE_CONFIG_H__
#define __NUCONSOLE_CONFIG_H__

#ifndef NUCOSOLE_TX_BUFFER_SIZE
#define NUCOSOLE_TX_BUFFER_SIZE    1024
#endif
#ifndef NUCOSOLE_RX_BUFFER_SIZE    
#define NUCOSOLE_RX_BUFFER_SIZE    32
#endif

#define NUCONSOLE_FIFO_DEFAULT_MODE    NUCONSOLE_FIFO_MODE_BLOCKING //or NUCONSOLE_FIFO_MODE_NON_BLOCKING

#endif
