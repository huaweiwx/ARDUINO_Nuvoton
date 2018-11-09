/* Copyright (C) 2011 Circuits At Home, LTD. All rights reserved.

This software may be distributed and modified under the terms of the GNU
General Public License version 2 (GPL2) as published by the Free Software
Foundation and appearing in the file GPL2.TXT included in the packaging of
this file. Please note that GPL2 Section 2[b] requires that all works based
on this software must also be made publicly available under the terms of
the GPL2 ("Copyleft").

Contact information
-------------------

Circuits At Home, LTD
Web      :  http://www.circuitsathome.com
e-mail   :  support@circuitsathome.com
*/

/* USB functions */

#include "Arduino.h"
#include "M451Series.h"
#include "Nuvoton/INCLUDE/usbh_core.h"
#include "Usb.h"
#include <stdio.h>

#define PLLCTL_SETTING      0x422e
#define PLL_CLOCK           96000000


/**
 * \brief USBHost class constructor.
 */
USBHost::USBHost()
{
	init();
}



/**
 * \brief Initialize USBHost class.
 */
void USBHost::init()
{
	volatile int  delay;  
	
	SYS_UnlockReg();
	
    /* Switch HCLK clock source to XTAL */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HXT, CLK_CLKDIV0_HCLK(1));

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCTL |= CLK_PLLCTL_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCTL = PLLCTL_SETTING;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_STATUS_PLLSTB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK->CLKSEL0 &= (~CLK_CLKSEL0_HCLKSEL_Msk);
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLKSEL_PLL;

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UARTSEL_HXT, CLK_CLKDIV0_UART(1));

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 2;              // HCLK
    CyclesPerUs     = SystemCoreClock / 1000000;  // For SYS_SysTickDelay()

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init USB Host clock                                                                                     */
    /*---------------------------------------------------------------------------------------------------------*/
    // Configure OTG function as Host-Only
    SYS->USBPHY = 0x101;

#ifdef AUTO_POWER_CONTROL

    /* Below settings is use power switch IC to enable/disable USB Host power.
       Set PC.4 is VBUS_EN function pin and PC.3 VBUS_ST function pin             */

    //SYS->GPC_MFPL &= ~(SYS_GPC_MFPL_PC4MFP_Msk | SYS_GPC_MFPL_PC3MFP_Msk);
    //SYS->GPC_MFPL |=  (SYS_GPC_MFPL_PC3MFP_USB_VBUS_ST | SYS_GPC_MFPL_PC4MFP_USB_VBUS_EN);

    /* Below settings is use power switch IC to enable/disable USB Host power.
       Set PA.2 is VBUS_EN function pin and PA.3 VBUS_ST function pin             */
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA2MFP_Msk | SYS_GPA_MFPL_PA3MFP_Msk);
    SYS->GPA_MFPL |= (SYS_GPA_MFPL_PA3MFP_USB_VBUS_ST | SYS_GPA_MFPL_PA2MFP_USB_VBUS_EN);

    CLK->APBCLK0 |= CLK_APBCLK0_OTGCKEN_Msk;   //Enable OTG_EN clock
#else
    /* Below settings is use GPIO to enable/disable USB Host power.
       Set PC.4 output high to enable USB power                               */

    SYS->GPC_MFPL &= ~SYS_GPC_MFPL_PC4MFP_Msk;
    PC->MODE = (PC->MODE & ~GPIO_MODE_MODE4_Msk) | (0x1 << GPIO_MODE_MODE4_Pos);
    PC->DOUT |= 0x10;
#endif

    // USB clock divided by 2
    CLK->CLKDIV0 = (CLK->CLKDIV0 & ~CLK_CLKDIV0_USBDIV_Msk) | (1 << CLK_CLKDIV0_USBDIV_Pos);

    // Enable USB Host
    CLK->AHBCLK |= CLK_AHBCLK_USBHCKEN_Msk;

    USBH_Open();

    // Configure OTG function as Dual Role
    SYS_UnlockReg();
    SYS->USBPHY = 0x102;
    
    for (delay = 0; delay < 0x800000; delay++)
    	__NOP();

    USBH_HidInit();
}


/**
 * \brief USB main task, responsible for enumeration and clean up stage.
 *
 * \note Must be periodically called from loop().
 */
void USBHost::Task(void)
{
	USBH_ProcessHubEvents();
}



/**
 * \brief Allocate an URB.
 *
 * \return An URB. 
 */
URB_T * USBHost::alloc_urb(void)
{
    return USBH_AllocUrb();
}


/**
 * \brief Release and free an URB.
 *
 */
void USBHost::free_urb(URB_T *urb)
{
    USBH_FreeUrb(urb);
}


/**
 * \brief Submit an URB transfer.
 *
 * \return Success or failed. 
 */
int  USBHost::submit_urb(URB_T *urb)
{
    return USBH_SubmitUrb(urb);
}


/**
 * \brief Force to abort an URB transfer.
 *
 * \return Success or failed. 
 */
int  USBHost::unlink_urb(URB_T *urb)
{
    return USBH_UnlinkUrb(urb);
}


/**
 * \brief Request to issue a Control Transfer.
 *
 * \return Success or failed. 
 */
int USBHost::snd_ctrl_msg(USB_DEV_T *dev, uint32_t pipe, uint8_t request, uint8_t requesttype,  
                            uint16_t value, uint16_t index, void *data, uint16_t size, int timeout)
{
	return USBH_SendCtrlMsg(dev, pipe, request, requesttype, value, index, data, size, timeout);
}


/**
 * \brief Request to issue a Bulk Transfer.
 *
 * \return Success or failed. 
 */
int USBHost::snd_bulk_msg(USB_DEV_T *dev, uint32_t pipe, void *data, int len, 
                            int *actual_length, int timeout)
{
	return USBH_SendBulkMsg(dev, pipe, data, len, actual_length, timeout);
}


/**
 * \brief Issue a GET_DESCRIPTOR standard command to get descritor from device.
 *
 * \return Success or failed. 
 */
int USBHost::get_descriptor(USB_DEV_T *dev, uint8_t type, uint8_t index, void *buf, int size)
{
	return USBH_GetDescriptor(dev, type, index, buf, size);
}


/**
 * \brief Issue a SET_CONFIGURATION standard command to select a device configuration.
 *
 * \return Success or failed. 
 */
int USBHost::set_configuration(USB_DEV_T *dev, int config_val)
{
	return USBH_SetConfiguration(dev, config_val);
}


/**
 * \brief Issue a SET_INTERFACE standard command to select a device interface's alternative interface.
 *
 * \return Success or failed. 
 */
int USBHost::set_interface(USB_DEV_T *dev, char interface, char alternate)
{
	return USBH_SetInterface(dev, interface, alternate);
}


/**
 * \brief Issue a CLEAR_FEATURE standard command to clear the halt state of an endpoint.
 *
 * \return Success or failed. 
 */
int USBHost::clear_halt(USB_DEV_T *dev, int pipe)
{
	return USBH_ClearHalt(dev, pipe);
}


/**
 * \brief Let USB host enter suspend mode. All connected device will be suspended also.
 *
 * \return Success or failed. 
 */
int USBHost::suspend(void)
{
	return USBH_Suspend();
}


/**
 * \brief Resume USB host from suspend mode.
 *
 * \return Success or failed. 
 */
int USBHost::resume(void)
{
	return USBH_Resume();
}


/**
 * \brief Stop USB host.
 *
 * \return Success or failed. 
 */
int USBHost::close(void)
{
	return USBH_Close();
}


/**
 * \brief Register a device driver to USB host core.
 *
 * \return Success or failed. 
 */
int USBHost::register_driver(USB_DRIVER_T *driver)
{
	return USBH_RegisterDriver(driver);
}



