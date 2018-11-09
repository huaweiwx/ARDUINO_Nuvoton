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

#include <stdio.h>
#include <nvtKeyboardController.h>

extern "C" {
void __keyboardControllerEmptyCallback() { }
}

void keyPressed()  __attribute__ ((weak, alias("__keyboardControllerEmptyCallback")));
void keyReleased() __attribute__ ((weak, alias("__keyboardControllerEmptyCallback")));

void KeyboardController::OnKeyDown(uint8_t _mod, uint8_t _oemKey) {
	modifiers = _mod;
	keyOem = _oemKey;
	key = OemToAscii(_mod, _oemKey);
	keyPressed();
}

void KeyboardController::OnKeyUp(uint8_t _mod, uint8_t _oemKey) {
	modifiers = _mod;
	keyOem = _oemKey;
	key = OemToAscii(_mod, _oemKey);
	keyReleased();
}


const uint8_t KeyboardController::numKeys[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' };
const uint8_t KeyboardController::symKeysUp[] = { '_', '+', '{', '}', '|', '~', ':', '"', '~', '<', '>', '?' };
const uint8_t KeyboardController::symKeysLo[] = { '-', '=', '[', ']', '\\', ' ', ';', '\'', '`', ',', '.', '/' };
const uint8_t KeyboardController::padKeys[] = { '/', '*', '-', '+', 0x13 };


void  keyboard_int_cb(HID_DEV_T *hdev, uint8_t *rdata, int data_len)
{
	KeyboardController  *k  = (KeyboardController *)hdev->client;
#if 0	
   	int  i;
   	
   	printf("INT-in pipe data %d bytes received =>\n", data_len);
   	for (i = 0; i < data_len; i++)
       	printf("0x%02x ", rdata[i]);
   	printf("\n");
#endif
   	
   	k->Parse(rdata, data_len);
}


void KeyboardController::Parse(uint8_t *buf, uint32_t len)
{
	// On error - return
	if (buf[2] == 1)
		return;

	//KBDINFO	*pki = (KBDINFO*)buf;

	for (uint32_t i = 2; i < 8; ++i)
	{
		bool down = false;
		bool up	  = false;

		for (uint8_t j=2; j<8; j++)
		{
			if (buf[i] == prevState.bInfo[j] && buf[i] != 1)
				down = true;
			if (buf[j] == prevState.bInfo[i] && prevState.bInfo[i] != 1)
				up = true;
		}

		if (!down)
		{
			HandleLockingKeys(buf[i]);
			OnKeyDown(*buf, buf[i]);
		}

		if (!up)
			OnKeyUp(prevState.bInfo[0], prevState.bInfo[i]);
	}

	for (uint32_t i = 0; i < 8; ++i)
		prevState.bInfo[i] = buf[i];
};


/**
 * \brief Handle keyboard locking keys and manage keyboard leds using USB
 * report.
 *
 * \param hid HID device pointer.
 * \param key Locking key.
 *
 * \return 0 on success, error code otherwise.
 */
uint8_t KeyboardController::HandleLockingKeys(uint8_t key)
{
	uint8_t old_keys = kbdLockingKeys.bLeds;

	switch (key)
	{
		case KEY_NUM_LOCK:
			kbdLockingKeys.kbdLeds.bmNumLock = ~kbdLockingKeys.kbdLeds.bmNumLock;
			break;
		case KEY_CAPS_LOCK:
			kbdLockingKeys.kbdLeds.bmCapsLock = ~kbdLockingKeys.kbdLeds.bmCapsLock;
			break;
		case KEY_SCROLL_LOCK:
			kbdLockingKeys.kbdLeds.bmScrollLock = ~kbdLockingKeys.kbdLeds.bmScrollLock;
			break;
	}

	if (old_keys != kbdLockingKeys.bLeds)
	{
		return HID_HidSetReport(dev, 2, 0, &kbdLockingKeys.bLeds, 1);
	}

	return 0;
}


/**
 * \brief Manage keyboard OEM to ASCII conversion.
 *
 * \param mod Keyboard modifier.
 * \param key Key value to convert.
 *
 * \return Keyboard corresponding ASCII value on success, 0 otherwise.
 */
uint8_t KeyboardController::OemToAscii(uint8_t mod, uint8_t key)
{
	uint8_t shift = (mod & 0x22);

	// [a-z]
	if (key > 0x03 && key < 0x1e)
	{
		// Upper case letters
		if ( (kbdLockingKeys.kbdLeds.bmCapsLock == 0 && (mod & 2)) ||
			 (kbdLockingKeys.kbdLeds.bmCapsLock == 1 && (mod & 2) == 0) )
			return (key - 4 + 'A');

		// Lower case letters
		else
			return (key - 4 + 'a');
	}
	// Numbers
	else if (key > 0x1d && key < 0x27)
	{
		if (shift)
			return (numKeys[key - 0x1e]);
		else
			return (key - 0x1e + '1');
	}
	// Keypad Numbers
	else if (key > 0x58 && key < 0x62)
	{
		if (kbdLockingKeys.kbdLeds.bmNumLock == 1)
			return (key - 0x59 + '1');
	}
	else if (key > 0x2c && key < 0x39)
		return ((shift) ? symKeysUp[key-0x2d] : symKeysLo[key-0x2d]);
	else if (key > 0x53 && key < 0x59)
		return padKeys[key - 0x54];
	else
	{
		switch (key)
		{
			case KEY_SPACE:		return (0x20);
			case KEY_ENTER:		return (0x13);
			case KEY_ZERO:		return ((shift) ? ')' : '0');
			case KEY_ZERO2:		return ((kbdLockingKeys.kbdLeds.bmNumLock == 1) ? '0' : 0);
			case KEY_PERIOD:	return ((kbdLockingKeys.kbdLeds.bmNumLock == 1) ? '.' : 0);
		}
	}
	return 0;
}

