/*
  can.cpp
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include "can_.h"

uint32_t Mask_Filter_Number = 5;
static interruptCAN callbacksCAN[CAN_MAX_COUNT]={0};
typedef struct
{
	uint32_t Mask_Flag;
	uint32_t Mask_ext;
	uint32_t MaskID;
}CAN_MaskID;

typedef struct 
{
    uint32_t Filt_Flag;
    uint32_t Filt_ext;
    uint32_t FiltID;
}CAN_FiltID;

volatile static CAN_MaskID Mask_ID[5] =
{
    {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
};

volatile static CAN_FiltID Filt_ID[5] =
{
    {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
};

/*********************************************************************************************************
** Function name:           init
** Descriptions:            init can and set speed
*********************************************************************************************************/
#define CAN_ID 0
CAN::CAN()
{
	can_device=CAN_Desc[CAN_ID].C;
  u32Idx=CAN_ID;  
  u32module=CAN_Desc[CAN_ID].module;  
  u32IrqId=CAN_Desc[CAN_ID].irq;
}

CAN::CAN(int id)
{
	can_device=CAN_Desc[id].C;
  u32Idx=id;    
  u32module=CAN_Desc[id].module;  
  u32IrqId=CAN_Desc[id].irq;
}

#ifdef __cplusplus
extern "C" {
#endif

uint8_t read_msg(CAN_T * device)
{
    uint32_t stat;
		uint32_t CompareID;	
    uint32_t res = CAN_OK;
    uint32_t m_nDlc;
    uint32_t m_nID;
    uint32_t m_nExtFlg;
    uint8_t  m_nDta[MAX_CHAR_IN_MESSAGE];
    STR_CANMSG_T rMsg;
    int i = 0;

    stat = CAN_Receive(device, 0, &rMsg);    
    if(stat == TRUE)
    {
        m_nDlc = rMsg.DLC;
        m_nID = rMsg.Id;
        m_nExtFlg = rMsg.IdType;
        for(i = 0; i<8; i++)
        {
            m_nDta[i] = rMsg.Data[i];
        }

		for(i = 0; i < Mask_Filter_Number; i++)
		{
			if(Filt_ID[i].Filt_Flag)
			{
				res = CAN_NOMSG;
				if(!(Mask_ID[i].Mask_Flag))
				{
					CompareID = Filt_ID[i].FiltID;
					
					if( (CompareID & m_nID) == CompareID )
						return CAN_OK;
				}
				else
				{
					CompareID = (Filt_ID[i].FiltID & Mask_ID[i].MaskID);
					
					if((Mask_ID[i].Mask_ext & Filt_ID[i].Filt_ext) == (Mask_ID[i].Mask_ext & m_nExtFlg))
					{
						if( (CompareID & m_nID) == CompareID )
							return CAN_OK;
					}
				}
			
			}
		}
		
        //res = CAN_OK;
    }

    return res;
}

#if(CAN_MAX_COUNT>0)
void CAN0_IRQHandler(void)
{
 		uint32_t u8IIDRstatus;

    u8IIDRstatus = CAN0->IIDR;		
    if(u8IIDRstatus == 0x00008000)     
    {
        /**************************/
        /* Status Change interrupt*/
        /**************************/
        if(CAN0->STATUS & CAN_STATUS_RXOK_Msk)
        {
            CAN0->STATUS &= ~CAN_STATUS_RXOK_Msk;   /* Clear RxOK status*/         
            if(read_msg(CAN0)==CAN_OK)   
            	callbacksCAN[0]();
        }

        if(CAN0->STATUS & CAN_STATUS_TXOK_Msk)
        {
            CAN0->STATUS &= ~CAN_STATUS_TXOK_Msk;    /* Clear TxOK status*/
        }

        /**************************/
        /* Error Status interrupt */
        /**************************/
        if(CAN0->STATUS & CAN_STATUS_BOFF_Msk)
        {
           	; //BOFF INT
        }
        else if(CAN0->STATUS & CAN_STATUS_EWARN_Msk)
        {
						; //EWARN INT
        }
        else if((CAN0->ERR & CAN_ERR_TEC_Msk) != 0)
        {
            ; //Transmit error!
        } 
        else if((CAN0->ERR & CAN_ERR_REC_Msk) != 0)
        {
            ; //Receive error!
        }       
        
    }
    else if((u8IIDRstatus >= 0x1) || (u8IIDRstatus <= 0x20))
    {
        CAN_CLR_INT_PENDING_BIT(CAN0, (u8IIDRstatus - 1)); /* Clear Interrupt Pending */       
    }
	
}
#endif

#if(CAN_MAX_COUNT>1)
void CAN1_IRQHandler(void)
{
	
}
#endif

#ifdef __cplusplus
}
#endif


void CAN::attachInterrupt(void (*callback)(void))
{
	callbacksCAN[u32Idx]=callback;
	CAN_EnableInt(can_device,CAN_CON_SIE_Msk|CAN_CON_IE_Msk );
	NVIC_EnableIRQ(u32IrqId);
}

void CAN::detachInterrupt()
{
	callbacksCAN[u32Idx]=NULL;
	CAN_DisableInt(can_device,CAN_CON_SIE_Msk|CAN_CON_IE_Msk);
	NVIC_DisableIRQ(u32IrqId);
}

INT8U CAN::begin(INT8U speedset)
{
    //uint32_t res;
    uint32_t BaudRate = 0, RealBaudRate = 0; //RealBaudRate1 = 0;

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/

    SYS_UnlockReg();

    CAN_Config(CAN_Desc[u32Idx]);

    /* Enable CAN module clock */
    CLK_EnableModuleClock(u32module);    
    
    switch (speedset)
    {
        case (CAN_5KBPS):
             BaudRate = 5000;
             break;
             
        case (CAN_10KBPS):
             BaudRate = 10000;
             break;
        
        case (CAN_20KBPS):
             BaudRate = 20000;
             break;
             
        case (CAN_31K25BPS):
             BaudRate = 31250;
             break;

        case (CAN_40KBPS):
             BaudRate = 40000;
             break;
             
        case (CAN_50KBPS):
             BaudRate = 50000;
             break;
             
        case (CAN_80KBPS):
             BaudRate = 80000;
             break;

        case (CAN_100KBPS):
             BaudRate = 100000;
             break;

        case (CAN_125KBPS):
             BaudRate = 125000;
             break;
             
        case (CAN_200KBPS):
             BaudRate = 200000;
             break;
             
        case (CAN_250KBPS):
             BaudRate = 250000;
             break;
             
        case (CAN_500KBPS):
             BaudRate = 500000;
             break;

        case (CAN_1000KBPS):
             BaudRate = 1000000;
             break;
    }    
    RealBaudRate = CAN_Open(can_device,  BaudRate, CAN_BASIC_MODE);
    if(BaudRate != RealBaudRate)
        return CAN_FAILINIT;
    else
        return CAN_OK;

}

/*********************************************************************************************************
** Function name:           init_Mask
** Descriptions:            init canid Masks
*********************************************************************************************************/
INT8U CAN::init_Mask(INT8U num, INT8U ext, INT32U ulData)
{
	if(num >= 2)
		return CAN_FAIL;
	
	if(num == 0)
	{
		Mask_ID[0].Mask_Flag = 1;
		Mask_ID[0].Mask_ext = ext;
		Mask_ID[0].MaskID = ulData;
		
		Mask_ID[1].Mask_Flag = 1;
		Mask_ID[1].Mask_ext = ext;
		Mask_ID[1].MaskID = ulData;
	}
	else if(num == 1)
	{
		Mask_ID[2].Mask_Flag = 1;
		Mask_ID[2].Mask_ext = ext;
		Mask_ID[2].MaskID = ulData;
		
		Mask_ID[3].Mask_Flag = 1;
		Mask_ID[3].Mask_ext = ext;
		Mask_ID[3].MaskID = ulData;
		
		Mask_ID[4].Mask_Flag = 1;
		Mask_ID[4].Mask_ext = ext;
		Mask_ID[4].MaskID = ulData;
	}
	
	return CAN_OK;
}

/*********************************************************************************************************
** Function name:           init_Filt
** Descriptions:            init canid filters
*********************************************************************************************************/
INT8U CAN::init_Filt(INT8U num, INT8U ext, INT32U ulData)
{
	if(num >= Mask_Filter_Number)
		return CAN_FAIL;
	
	Filt_ID[num].Filt_Flag = 1;
	Filt_ID[num].Filt_ext = ext;
	Filt_ID[num].FiltID = ulData;
	
	return CAN_OK;
}

/*********************************************************************************************************
** Function name:           setMsg
** Descriptions:            set can message, such as dlc, id, dta[] and so on
*********************************************************************************************************/
INT8U CAN::setMsg(INT32U id, INT8U ext, INT8U len, INT8U *pData)
{
	int i = 0;
    m_nExtFlg = ext;
    m_nID     = id;
    m_nDlc    = len;
    for(i = 0; i<MAX_CHAR_IN_MESSAGE; i++)
    {
        m_nDta[i] = *(pData+i);
    }

    return 0;
}

/*********************************************************************************************************
** Function name:           clearMsg
** Descriptions:            set all message to zero
*********************************************************************************************************/
INT8U CAN::clearMsg()
{
	uint32_t i;
	
    m_nID       = 0;
    m_nDlc      = 0;
    m_nExtFlg   = 0;
    m_nRtr      = 0;
    m_nfilhit   = 0;
	
    for(i = 0; i < m_nDlc; i++ )
	{
      m_nDta[i] = 0x00;
	}
	
    return 0;
}

/*********************************************************************************************************
** Function name:           sendMsg
** Descriptions:            send message
*********************************************************************************************************/
INT8U CAN::sendMsg()
{
    int i = 0;
    int32_t res;

    STR_CANMSG_T msg1;
  
    msg1.FrameType = CAN_DATA_FRAME;
    msg1.IdType   = m_nExtFlg;
    msg1.Id       = m_nID;
    msg1.DLC      = m_nDlc;
    
    for(i = 0; i<8; i++)
    {
       msg1.Data[i] = m_nDta[i];
    }

    res = CAN_Transmit(can_device, 0, &msg1);//Send CAN message

    if(res == 0)
        return  CAN_SENDMSGTIMEOUT;

    return CAN_OK;
}

/*********************************************************************************************************
** Function name:           sendMsgBuf
** Descriptions:            send buf
*********************************************************************************************************/
INT8U CAN::sendMsgBuf(INT32U id, INT8U ext, INT8U len, INT8U *buf)
{
    setMsg(id, ext, len, buf);
    sendMsg();
}

/*********************************************************************************************************
** Function name:           readMsg
** Descriptions:            read message
*********************************************************************************************************/
INT8U CAN::readMsg()
{
    uint32_t stat;
		uint32_t CompareID;	
    uint32_t res = CAN_OK;
    STR_CANMSG_T rMsg;
    int i = 0;

    stat = CAN_Receive(can_device, 0, &rMsg);    
    if(stat == TRUE)
    {
        m_nDlc = rMsg.DLC;
        m_nID = rMsg.Id;
        m_nExtFlg = rMsg.IdType;
		
        for(i = 0; i<8; i++)
        {        		
            m_nDta[i] = rMsg.Data[i];
        }

		for(i = 0; i < Mask_Filter_Number; i++)
		{
			
			if(Filt_ID[i].Filt_Flag)
			{
				res = CAN_NOMSG;
				if(!(Mask_ID[i].Mask_Flag))
				{
					CompareID = Filt_ID[i].FiltID;
					
					if( (CompareID & m_nID) == CompareID )
						return CAN_OK;
				}
				else
				{
					CompareID = (Filt_ID[i].FiltID & Mask_ID[i].MaskID);
					
					if((Mask_ID[i].Mask_ext & Filt_ID[i].Filt_ext) == (Mask_ID[i].Mask_ext & m_nExtFlg))
					{
						if( (CompareID & m_nID) == CompareID )
							return CAN_OK;
					}
				}
			
			}
		}
		
        //res = CAN_OK;
    }

    return res;

}

/*********************************************************************************************************
** Function name:           readMsgBuf
** Descriptions:            read message buf
*********************************************************************************************************/
INT8U CAN::readMsgBuf(INT8U *len, INT8U buf[])
{
	uint32_t i;
	uint8_t res;
	
    if((res=readMsg())==CAN_OK)
    {
	    *len = m_nDlc;
	    for(i = 0; i<m_nDlc; i++)
	    {
	      buf[i] = m_nDta[i];
	    }
  	}
 		return res; 	
}

/*********************************************************************************************************
** Function name:           checkReceive
** Descriptions:            check if got something
*********************************************************************************************************/
INT8U CAN::checkReceive(void)
{
    uint32_t res;
    
    res = CAN_GET_INT_STATUS(can_device);
    if(res & (1 << 4))  // check RxOk status
    {
    		if(readMsg()!=CAN_OK) 
    			return CAN_NOMSG;
    		else
        return CAN_MSGAVAIL;
    }
    else
        return CAN_NOMSG;
}

/*********************************************************************************************************
** Function name:           checkError
** Descriptions:            if something error
*********************************************************************************************************/
INT8U CAN::checkError(void)
{
   uint32_t res;
    res = CAN_GET_INT_STATUS(can_device);
    if(!(res & 0x7))  // check Last Error Code
        return CAN_OK;
    else
        return CAN_CTRLERROR;
}

/*********************************************************************************************************
** Function name:           getCanId
** Descriptions:            when receive something ,u can get the can id!!
*********************************************************************************************************/
INT32U CAN::getCanId(void)
{
    return m_nID;
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/