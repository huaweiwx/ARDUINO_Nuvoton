/*
  mcp_can_dfs.h
*/
#ifndef _NUVOTON_CAN_DFS_H_
#define _NUVOTON_CAN_DFS_H_

#include <Arduino.h>
#include <CAN.h>
#include <inttypes.h>

#ifndef INT32U
#define INT32U unsigned long
#endif

#ifndef INT8U
#define INT8U byte
#endif

// if print debug information
#define DEBUG_MODE 1




#define CANDEBUG   1

#define CANUSELOOP 0

#define CANSENDTIMEOUT (200)                                            /* milliseconds                 */

/*
 *   initial value of gCANAutoProcess
 */
#define CANAUTOPROCESS (1)
#define CANAUTOON  (1)
#define CANAUTOOFF (0)

#define CAN_STDID (0)
#define CAN_EXTID (1)

#define CANDEFAULTIDENT    (0x55CC)
#define CANDEFAULTIDENTEXT (CAN_EXTID)

#define CAN_5KBPS    1
#define CAN_10KBPS   2
#define CAN_20KBPS   3
#define CAN_31K25BPS 4
#define CAN_40KBPS   5
#define CAN_50KBPS   6
#define CAN_80KBPS   7
#define CAN_100KBPS  8
#define CAN_125KBPS  9
#define CAN_200KBPS  10
#define CAN_250KBPS  11
#define CAN_500KBPS  12
#define CAN_1000KBPS 13

#define CAN_OK                  (0)
#define CAN_FAILINIT            (1)
#define CAN_FAILTX              (2)
#define CAN_MSGAVAIL            (3)
#define CAN_NOMSG               (4)
#define CAN_CTRLERROR           (5)
#define CAN_GETTXBFTIMEOUT      (6)
#define CAN_SENDMSGTIMEOUT      (7)
#define CAN_FAIL                (0xff)

#define CAN_MAX_CHAR_IN_MESSAGE (8)

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
