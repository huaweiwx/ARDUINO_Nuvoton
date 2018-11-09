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

#ifndef USB_H_INCLUDED
#define USB_H_INCLUDED


#include <stdint.h>
#include "Nuvoton\INCLUDE\usbh_core.h"
#include "Nuvoton\INCLUDE\usbh_hid.h"



/**
 * \class USBHost
 *
 * \brief Main USB host class.
 */
class USBHost
{

    public:
        USBHost(void);

        void    Task(void);
		URB_T * alloc_urb(void);
		void    free_urb(URB_T *);
        int     submit_urb(URB_T *urb);
		int     unlink_urb(URB_T *urb);
        int     snd_ctrl_msg(USB_DEV_T *dev, uint32_t pipe, uint8_t request, uint8_t requesttype,  uint16_t value, uint16_t index, void *data, uint16_t size, int timeout);
        int     snd_bulk_msg(USB_DEV_T *dev, uint32_t pipe, void *data, int len, int *actual_length, int timeout);
        int     get_descriptor(USB_DEV_T *dev, uint8_t type, uint8_t index, void *buf, int size);
        int     set_configuration(USB_DEV_T *dev, int config_val);
        int     set_interface(USB_DEV_T *dev, char interface, char alternate);
        int     clear_halt(USB_DEV_T *dev, int pipe);
        int     suspend(void);
        int     resume(void);
        int     close(void);

        int     register_driver(USB_DRIVER_T *new_driver);

    private:
    	void    init();
};


#endif /* USB_H_INCLUDED */
