/******************************************************************************
 * @file     usbd.c
 * @brief    NANO100 series USBD driver Sample file
 * @version  2.0.0
 * @date     10, January, 2014
 *
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

/*!<Includes */
#include <string.h>
#include "nano100Series.h"

/*--------------------------------------------------------------------------*/
/* Global variables for Control Pipe */
uint8_t g_usbd_SetupPacket[8] = {0};

static uint8_t *g_usbd_CtrlInPointer = 0;
static uint32_t g_usbd_CtrlInSize = 0;
static uint8_t *g_usbd_CtrlOutPointer = 0;
static uint32_t g_usbd_CtrlOutSize = 0;
static uint32_t g_usbd_CtrlOutSizeLimit = 0;
static uint32_t g_usbd_UsbAddr = 0;
static uint32_t g_usbd_UsbConfig = 0;
static uint32_t g_usbd_CtrlMaxPktSize = 8;
static uint32_t g_usbd_UsbAltInterface = 0;

S_USBD_INFO_T *g_usbd_sInfo;

CLASS_REQ g_usbd_pfnClassRequest = NULL;
SET_INTERFACE_REQ g_usbd_pfnSetInterface = NULL;

/**
  * @brief  USBD Initial, Enable clock and reset USB.
  * @param[in]   param               Descriptor
  * @param[in]   pfnClassReq         Class Request Callback Function
  * @param[in]   pfnSetInterface     SetInterface Request Callback Function
  * @retval None.
  */
void USBD_Open(S_USBD_INFO_T *param, CLASS_REQ pfnClassReq, SET_INTERFACE_REQ pfnSetInterface)
{
    g_usbd_sInfo = param;
    g_usbd_pfnClassRequest = pfnClassReq;
    g_usbd_pfnSetInterface = pfnSetInterface;

    /* get EP0 maximum packet size */
    g_usbd_CtrlMaxPktSize = g_usbd_sInfo->gu8DevDesc[7];

    /* Initial USB engine */
    USBD->CTRL = 0x29f;
    USBD->PDMA |= USBD_PDMA_BYTEM_Msk;
    /* Force SE0, and then clear it to connect*/
    USBD_SET_SE0();
}

/**
 * @brief       USBD Start
 *
 * @param       None
 *
 * @return      None
 *
 * @details     This function is used to start transfer
 */
void USBD_Start(void)
{
    /* Enable USB-related interrupts. */
    UBSD_ENABLE_INT(USBD_INT_BUS | USBD_INT_USB | USBD_INT_FLDET | USBD_INT_WAKEUP);
    CLK_SysTickDelay(100000);
    USBD_CLR_SE0();
}

/**
 * @brief       Get Setup Packet
 *
 * @param[in]   buf Buffer pointer to store setup packet
 *
 * @return      None
 *
 * @details     This function is used to get Setup packet.
 */
void USBD_GetSetupPacket(uint8_t *buf)
{
    USBD_MemCopy(buf, g_usbd_SetupPacket, 8);
}

/**
 * @brief       Process Setup Packet
 *
 * @param       None
 *
 * @return      None
 *
 * @details     This function is used to process Setup packet.
 */
void USBD_ProcessSetupPacket(void)
{
    // Setup packet process
    USBD_MemCopy(g_usbd_SetupPacket, (uint8_t *)USBD_BUF_BASE, 8);

    switch (g_usbd_SetupPacket[0] & 0x60) { /* request type */
    case REQ_STANDARD: { // Standard
        USBD_StandardRequest();
        break;
    }
    case REQ_CLASS: { // Class
        if (g_usbd_pfnClassRequest != NULL) {
            g_usbd_pfnClassRequest();
        }
        break;
    }
    case REQ_VENDOR: { // Vendor
        break;
    }
    default: { // reserved
        /* Setup error, stall the device */
        USBD_SetStall(0);
        break;
    }
    }
}

/**
 * @brief       Get Descriptor request
 *
 * @param       None
 *
 * @return      None
 *
 * @details     This function is used to process GetDescriptor request.
 */
void USBD_GetDescriptor(void)
{
    uint32_t u32Len;

    u32Len = 0;
    u32Len = g_usbd_SetupPacket[7];
    u32Len <<= 8;
    u32Len += g_usbd_SetupPacket[6];

    switch (g_usbd_SetupPacket[3]) {
    // Get Device Descriptor
    case DESC_DEVICE: {
        u32Len = Minimum(u32Len, LEN_DEVICE);
        USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8DevDesc, u32Len);
        USBD_PrepareCtrlOut(0,0);
        break;
    }
    // Get Configuration Descriptor
    case DESC_CONFIG: {
        uint32_t u32TotalLen;

        u32TotalLen = g_usbd_sInfo->gu8ConfigDesc[3];
        u32TotalLen = g_usbd_sInfo->gu8ConfigDesc[2] + (u32TotalLen << 8);

        u32Len = Minimum(u32Len, u32TotalLen);
        USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8ConfigDesc, u32Len);
        USBD_PrepareCtrlOut(0,0);
        break;
    }
    // Get HID Descriptor
    case DESC_HID: {
        u32Len = Minimum(u32Len, LEN_HID);
        USBD_PrepareCtrlIn((uint8_t *)&g_usbd_sInfo->gu8ConfigDesc[LEN_CONFIG+LEN_INTERFACE], u32Len);
        USBD_PrepareCtrlOut(0,0);
        break;
    }
    // Get Report Descriptor
    case DESC_HID_RPT: {
        USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8HidReportDesc, u32Len);
        USBD_PrepareCtrlOut(0,0);
        break;
    }
    // Get String Descriptor
    case DESC_STRING: {
        // Get Language
        if (g_usbd_SetupPacket[2] == 0) {
            u32Len = Minimum(u32Len, 4);
            USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8StrLangDesc, u32Len);
            USBD_PrepareCtrlOut(0,0);
        } else {
            // Get String Descriptor
            switch (g_usbd_SetupPacket[2]) {
            case 1: {
                u32Len = Minimum(u32Len, g_usbd_sInfo->gu8StrVendorDesc[0]);
                USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8StrVendorDesc, u32Len);
                USBD_PrepareCtrlOut(0,0);
                break;
            }
            case 2: {
                u32Len = Minimum(u32Len, g_usbd_sInfo->gu8StrProductDesc[0]);
                USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8StrProductDesc, u32Len);
                USBD_PrepareCtrlOut(0,0);
                break;
            }
            default:
                // Not support. Reply STALL.
                USBD_SetStall(0);
                break;
            }
        }
        break;
    }
    default:
        // Not support. Reply STALL.
        USBD_SetStall(0);
        break;
    }
}

/**
 * @brief       Process USB standard request
 *
 * @param       None
 *
 * @return      None
 *
 * @details     This function is used to process USB Standard Request.
 */
void USBD_StandardRequest(void)
{
    /* clear global variables for new request */
    g_usbd_CtrlInPointer = 0;
    g_usbd_CtrlInSize = 0;

    if (g_usbd_SetupPacket[0] & 0x80) { /* request data transfer direction */
        // Device to host
        switch (g_usbd_SetupPacket[1]) {
        case GET_CONFIGURATION: {
            // Return current configuration setting
            /* Data stage */
            M8(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0)) = g_usbd_UsbConfig;
            USBD_SET_DATA1(EP0);
            USBD_SET_PAYLOAD_LEN(EP0, 1);
            /* Status stage */
            USBD_PrepareCtrlOut(0,0);
            break;
        }
        case GET_DESCRIPTOR: {
            USBD_GetDescriptor();
            break;
        }
        case GET_INTERFACE: {
            // Return current interface setting
            /* Data stage */
            M8(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0)) = g_usbd_UsbAltInterface;
            USBD_SET_DATA1(EP0);
            USBD_SET_PAYLOAD_LEN(EP0, 1);
            /* Status stage */
            USBD_PrepareCtrlOut(0,0);
            break;
        }
        case GET_STATUS: {
            // Device
            if (g_usbd_SetupPacket[0] == 0x80) {
                if (g_usbd_sInfo->gu8ConfigDesc[7] & 0x40)
                    M8(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0)) = 1;  // Self-Powered
                else
                    M8(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0)) = 0;  // bus-Powered
            }
            // Interface
            else if (g_usbd_SetupPacket[0] == 0x81)
                M8(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0)) = 0;
            // Endpoint
            else if (g_usbd_SetupPacket[0] == 0x82) {
                uint8_t ep = g_usbd_SetupPacket[4] & 0xF;
                M8(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0)) = USBD_GetStall(ep)? 1 : 0;
            }

            M8(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0) + 1) = 0;
            /* Data stage */
            USBD_SET_DATA1(EP0);
            USBD_SET_PAYLOAD_LEN(EP0, 2);
            /* Status stage */
            USBD_PrepareCtrlOut(0,0);
            break;
        }
        default: {
            /* Setup error, stall the device */
            USBD_SetStall(0);
            break;
        }
        }
    } else {
        // Host to device
        switch (g_usbd_SetupPacket[1]) {
        case CLEAR_FEATURE: {
            if(g_usbd_SetupPacket[2] == FEATURE_ENDPOINT_HALT)
                USBD_ClearStall(g_usbd_SetupPacket[4] & 0xF);
            /* Status stage */
            USBD_SET_DATA1(EP0);
            USBD_SET_PAYLOAD_LEN(EP0, 0);
            break;
        }
        case SET_ADDRESS: {
            g_usbd_UsbAddr = g_usbd_SetupPacket[2];

            // DATA IN for end of setup
            /* Status Stage */
            USBD_SET_DATA1(EP0);
            USBD_SET_PAYLOAD_LEN(EP0, 0);
            break;
        }
        case SET_CONFIGURATION: {
            g_usbd_UsbConfig = g_usbd_SetupPacket[2];

            // DATA IN for end of setup
            /* Status stage */
            USBD_SET_DATA1(EP0);
            USBD_SET_PAYLOAD_LEN(EP0, 0);
            break;
        }
        case SET_FEATURE: {
            if(g_usbd_SetupPacket[2] == FEATURE_ENDPOINT_HALT)
                USBD_SetStall(g_usbd_SetupPacket[4] & 0xF);
            /* Status stage */
            USBD_SET_DATA1(EP0);
            USBD_SET_PAYLOAD_LEN(EP0, 0);
            break;
        }
        case SET_INTERFACE: {
            g_usbd_UsbAltInterface = g_usbd_SetupPacket[2];
            if (g_usbd_pfnSetInterface != NULL)
                g_usbd_pfnSetInterface(g_usbd_UsbAltInterface);
            /* Status stage */
            USBD_SET_DATA1(EP0);
            USBD_SET_PAYLOAD_LEN(EP0, 0);
            break;
        }
        default: {
            /* Setup error, stall the device */
            USBD_SetStall(0);
            break;
        }
        }
    }
}

/**
 * @brief       Prepare Control IN transaction
 *
 * @param[in]   pu8Buf      Control IN data pointer
 * @param[in]   u32Size     IN transfer size
 *
 * @return      None
 *
 * @details     This function is used to prepare Control IN transfer
 */
void USBD_PrepareCtrlIn(uint8_t *pu8Buf, uint32_t u32Size)
{
    if(u32Size > g_usbd_CtrlMaxPktSize) {
        // Data size > MXPLD
        g_usbd_CtrlInPointer = pu8Buf + g_usbd_CtrlMaxPktSize;
        g_usbd_CtrlInSize = u32Size - g_usbd_CtrlMaxPktSize;
        USBD_SET_DATA1(EP0);
        USBD_MemCopy((uint8_t *)USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0), pu8Buf, g_usbd_CtrlMaxPktSize);
        USBD_SET_PAYLOAD_LEN(EP0, g_usbd_CtrlMaxPktSize);
    } else {
        // Data size <= MXPLD
        g_usbd_CtrlInPointer = 0;
        g_usbd_CtrlInSize = 0;
        USBD_SET_DATA1(EP0);
        USBD_MemCopy((uint8_t *)USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0), pu8Buf, u32Size);
        USBD_SET_PAYLOAD_LEN(EP0, u32Size);
    }
}

/**
 * @brief       Start Control IN transfer
 *
 * @param       None
 *
 * @return      None
 *
 * @details     This function is used to start Control IN
 */
void USBD_CtrlIn(void)
{
    if(g_usbd_CtrlInSize) {
        // Process remained data
        if(g_usbd_CtrlInSize > g_usbd_CtrlMaxPktSize) {
            // Data size > MXPLD
            USBD_MemCopy((uint8_t *)USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0), g_usbd_CtrlInPointer, g_usbd_CtrlMaxPktSize);
            USBD_SET_PAYLOAD_LEN(EP0, g_usbd_CtrlMaxPktSize);
            g_usbd_CtrlInPointer += g_usbd_CtrlMaxPktSize;
            g_usbd_CtrlInSize -= g_usbd_CtrlMaxPktSize;
        } else {
            // Data size <= MXPLD
            USBD_MemCopy((uint8_t *)USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP0), g_usbd_CtrlInPointer, g_usbd_CtrlInSize);
            USBD_SET_PAYLOAD_LEN(EP0, g_usbd_CtrlInSize);
            g_usbd_CtrlInPointer = 0;
            g_usbd_CtrlInSize = 0;
        }
    } else {
        // In ACK for Set address
        if((g_usbd_SetupPacket[0] == 0) && (g_usbd_SetupPacket[1] == 5)) {
            if((USBD_GET_ADDR() != g_usbd_UsbAddr) && (USBD_GET_ADDR() == 0)) {
                USBD_SET_ADDR(g_usbd_UsbAddr);
            }
        }

        // No more data for IN token
        USBD_SET_PAYLOAD_LEN(EP0, 0);
    }
}

/**
 * @brief       Prepare Control OUT transaction
 *
 * @param[in]   pu8Buf      Control OUT data pointer
 * @param[in]   u32Size     OUT transfer size
 *
 * @return      None
 *
 * @details     This function is used to prepare Control OUT transfer
 */
void USBD_PrepareCtrlOut(uint8_t *pu8Buf, uint32_t u32Size)
{
    g_usbd_CtrlOutPointer = pu8Buf;
    g_usbd_CtrlOutSize = 0;
    g_usbd_CtrlOutSizeLimit = u32Size;
    USBD_SET_PAYLOAD_LEN(EP1, g_usbd_CtrlMaxPktSize);
}

/**
 * @brief       Start Control OUT transfer
 *
 * @param       None
 *
 * @return      None
 *
 * @details     This function is used to start Control OUT
 */
void USBD_CtrlOut(void)
{
    uint32_t u32Size;

    if(g_usbd_CtrlOutSize < g_usbd_CtrlOutSizeLimit) {
        u32Size = USBD_GET_PAYLOAD_LEN(EP1);
        USBD_MemCopy(g_usbd_CtrlOutPointer, (uint8_t *)USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP1), u32Size);
        g_usbd_CtrlOutPointer += u32Size;
        g_usbd_CtrlOutSize += u32Size;
    }
}

/**
 * @brief       Clear all software flags
 *
 * @param       None
 *
 * @return      None
 *
 * @details     This function is used to clear all software control flag
 */
void USBD_SwReset(void)
{
    // Reset all variables for protocol
    g_usbd_CtrlInPointer = 0;
    g_usbd_CtrlInSize = 0;
    g_usbd_CtrlOutPointer = 0;
    g_usbd_CtrlOutSize = 0;
    g_usbd_CtrlOutSizeLimit = 0;
    memset(g_usbd_SetupPacket, 0, 8);

    // Reset USB device address
    USBD_SET_ADDR(0);
}







