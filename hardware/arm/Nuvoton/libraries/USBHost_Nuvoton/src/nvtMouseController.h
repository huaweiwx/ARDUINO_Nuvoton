/*
  Copyright (c) 2012 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include "usb.h"

enum MouseButton {
	LEFT_BUTTON   = 0x01,
	MIDDLE_BUTTON = 0x02,
	RIGHT_BUTTON  = 0x04
};


void  mouse_int_cb(HID_DEV_T *hdev, uint8_t *rdata, int data_len);


/**
 * \brief MOUSEINFO definition.
 */
struct MOUSEINFO
{
	struct
	{
		uint8_t		bmLeftButton	: 1;
		uint8_t		bmRightButton	: 1;
		uint8_t		bmMiddleButton	: 1;
		uint8_t		bmDummy			: 1;
	};
	int8_t			dX;
	int8_t			dY;
};


class MouseController
{
public:
	MouseController() : dx(0), dy(0), buttons(0) 
	{
  	};

  	void  poll()  
  	{
  		if (dev == 0)
  		{
  		    dev = USBH_HidGetDeviceList();
  		    if (dev != 0)
  		    {
  		    	dev->client = (void *)this;
  		        USBH_HidStartIntReadPipe(dev, mouse_int_cb);
  		    }
  		}
  		else
  		{
  			dev = USBH_HidGetDeviceList();
  		}
  	}

  	bool getButton(MouseButton button) { return (buttons & button) == button; };
  	int getXChange();
  	int getYChange();
  	// int getWheelChange(); // Not implemented
	void Parse(uint8_t *buf, uint32_t len);

protected:
  	virtual void OnMouseMove(MOUSEINFO *mi);
  	virtual void OnLeftButtonUp(MOUSEINFO *mi);
  	virtual void OnLeftButtonDown(MOUSEINFO *mi);
  	virtual void OnMiddleButtonUp(MOUSEINFO *mi);
  	virtual void OnMiddleButtonDown(MOUSEINFO *mi);
  	virtual void OnRightButtonUp(MOUSEINFO *mi);
  	virtual void OnRightButtonDown(MOUSEINFO *mi);

private:
  	HID_DEV_T  *dev;
  	int dx, dy;
  	int buttons;

	union
	{
		MOUSEINFO	mouseInfo;
		uint8_t		bInfo[3];
	}	prevState;
};

#endif
