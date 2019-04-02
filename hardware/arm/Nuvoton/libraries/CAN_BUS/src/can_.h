/*
  mcp_can.h
*/
#ifndef _NUVOTON_CAN_H_
#define _NUVOTON_CAN_H_
#include "Arduino.h"
#include <inttypes.h>
#include "can_dfs.h"

#define MAX_CHAR_IN_MESSAGE 8
typedef void (*interruptCAN)(void);

#if defined(__NUC131__)
    #error "This board does not support this sample..."
#endif


class CAN
{
    private:
    CAN_T *can_device;
  	INT32U u32Idx;    
  	INT32U u32module;  
  	IRQn_Type u32IrqId;    
    
    
    INT8U   m_nExtFlg;                                                  /* identifier xxxID             */
                                                                        /* either extended (the 29 LSB) */
                                                                        /* or standard (the 11 LSB)     */
    INT32U  m_nID;                                                      /* can id                       */
    INT8U   m_nDlc;                                                     /* data length:                 */
    INT8U   m_nDta[MAX_CHAR_IN_MESSAGE];                            	  /* data                           */
    INT8U   m_nRtr;                                                     /* rtr                          */
    INT8U   m_nfilhit;
    INT8U   SPICS;

/*
 *  nuvoton driver function 
 */   
private:

/*
 *  can operator function
 */    

    INT8U setMsg(INT32U id, INT8U ext, INT8U len, INT8U *pData);    /* set message                  */  
    INT8U clearMsg();                                               /* clear all message to zero    */
    INT8U readMsg();                                                /* read message                 */
    INT8U sendMsg();                                                /* send message                 */		
public:
		CAN();
		CAN(int id); 
		void attachInterrupt( void (*callback)(void) );
		void detachInterrupt();
		void isrInterrupt();
		
    INT8U begin(INT8U speedset);                                    /* init can                     */
    INT8U init_Mask(INT8U num, INT8U ext, INT32U ulData);           /* init Masks                   */
    INT8U init_Filt(INT8U num, INT8U ext, INT32U ulData);           /* init filters                 */
    INT8U sendMsgBuf(INT32U id, INT8U ext, INT8U len, INT8U *buf);  /* send buf                     */
    INT8U readMsgBuf(INT8U *len, INT8U *buf);                       /* read buf                     */
    INT8U checkReceive(void);                                       /* if something received        */
    INT8U checkError(void);                                         /* if something error           */
    INT32U getCanId(void);                                          /* get can id when receive      */
};

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
