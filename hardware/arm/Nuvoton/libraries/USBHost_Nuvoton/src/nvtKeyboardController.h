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

#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "usb.h"

enum KeyboardModifiers {
	LeftCtrl = 1,
	LeftShift = 2,
	Alt = 4,
	LeftCmd = 8,
	RightCtrl = 16,
	RightShift = 32,
	AltGr = 64,
	RightCmd = 128
};


/**
 * \brief KBDINFO definition.
 */
struct KBDINFO
{
	struct
	{
		uint8_t		bmLeftCtrl		: 1;
		uint8_t		bmLeftShift		: 1;
		uint8_t		bmLeftAlt		: 1;
		uint8_t		bmLeftGUI		: 1;
		uint8_t		bmRightCtrl		: 1;
		uint8_t		bmRightShift	: 1;
		uint8_t		bmRightAlt		: 1;
		uint8_t		bmRightGUI		: 1;
	};
	uint8_t			bReserved;
	uint8_t			Keys[6];
};


/**
 * \brief KBDLEDS definition.
 */
struct KBDLEDS
{
	uint8_t		bmNumLock		: 1;
	uint8_t		bmCapsLock		: 1;
	uint8_t		bmScrollLock	: 1;
	uint8_t		bmCompose		: 1;
	uint8_t		bmKana			: 1;
	uint8_t		bmReserved		: 3;
};


#define KEY_SPACE					0x2c
#define KEY_ZERO					0x27
#define KEY_ZERO2					0x62
#define KEY_ENTER					0x28
#define KEY_PERIOD					0x63

#define KEY_CAPS_LOCK				0x39
#define KEY_SCROLL_LOCK				0x47
#define KEY_NUM_LOCK				0x53


void  keyboard_int_cb(HID_DEV_T *hdev, uint8_t *rdata, int data_len);


class KeyboardController
{
	static const uint8_t numKeys[];
	static const uint8_t symKeysUp[];
	static const uint8_t symKeysLo[];
	static const uint8_t padKeys[];

public:
    KeyboardController() : dev(0), key(0), keyOem(0), modifiers(0) 
    {
    	kbdLockingKeys.bLeds = 0; 
    };
  
  	void  poll()  
  	{
  		if (dev == 0)
  		{
  		    dev = USBH_HidGetDeviceList();
  		    if (dev != 0)
  		    {
  		    	dev->client = (void *)this;
  		        USBH_HidStartIntReadPipe(dev, keyboard_int_cb);
  		    }
  		}
  		else
  		{
  			dev = USBH_HidGetDeviceList();
  		}
  	}

  	uint8_t getKey()       { return key; };
  	uint8_t getModifiers() { return modifiers; };
  	uint8_t getOemKey()    { return keyOem; };
    void Parse(uint8_t *buf, uint32_t len);

protected:
  	void OnKeyDown(uint8_t mod, uint8_t key);
  	void OnKeyUp(uint8_t mod, uint8_t key);
	uint8_t OemToAscii(uint8_t mod, uint8_t key);
    uint8_t HandleLockingKeys(uint8_t key);

private:
  	HID_DEV_T  *dev;
  	uint8_t key, keyOem, modifiers;

	union
	{
		KBDINFO		kbdInfo;
		uint8_t		bInfo[sizeof(KBDINFO)];
	}	prevState;

	union
	{
		KBDLEDS		kbdLeds;
		uint8_t		bLeds;
	}	kbdLockingKeys;
};


#endif
