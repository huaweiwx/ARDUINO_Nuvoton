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
#include <nvtMouseController.h>

extern "C" {
void __mouseControllerEmptyCallback() { }
}

void mouseClicked()  __attribute__ ((weak, alias("__mouseControllerEmptyCallback")));
void mouseDragged()  __attribute__ ((weak, alias("__mouseControllerEmptyCallback")));
void mouseMoved()    __attribute__ ((weak, alias("__mouseControllerEmptyCallback")));
void mousePressed()  __attribute__ ((weak, alias("__mouseControllerEmptyCallback")));
void mouseReleased() __attribute__ ((weak, alias("__mouseControllerEmptyCallback")));

int MouseController::getXChange() {
	int r = dx;
	dx = 0;
	return r;
}

int MouseController::getYChange() {
	int r = dy;
	dy = 0;
	return r;
}

void MouseController::OnMouseMove(MOUSEINFO *mi) {
	dx += mi->dX;
	dy += mi->dY;
	if (buttons != 0)
		mouseDragged();
	else
		mouseMoved();
}

void MouseController::OnLeftButtonUp(MOUSEINFO *mi) {
	buttons &= ~LEFT_BUTTON;
	mouseReleased();
	mouseClicked();
}

void MouseController::OnLeftButtonDown(MOUSEINFO *mi) {
	buttons |= LEFT_BUTTON;
	mousePressed();
}

void MouseController::OnMiddleButtonUp(MOUSEINFO *mi) {
	buttons &= ~MIDDLE_BUTTON;
	mouseReleased();
	mouseClicked();
}

void MouseController::OnMiddleButtonDown(MOUSEINFO *mi) {
	buttons |= MIDDLE_BUTTON;
	mousePressed();
}

void MouseController::OnRightButtonUp(MOUSEINFO *mi) {
	buttons &= ~RIGHT_BUTTON;
	mouseReleased();
	mouseClicked();
}

void MouseController::OnRightButtonDown(MOUSEINFO *mi) {
	buttons |= RIGHT_BUTTON;
	mousePressed();
}


void  mouse_int_cb(HID_DEV_T *hdev, uint8_t *rdata, int data_len)
{
	MouseController  *m  = (MouseController *)hdev->client;
#if 0	
   	int  i;
   	
   	printf("INT-in pipe data %d bytes received =>\n", data_len);
   	for (i = 0; i < data_len; i++)
       	printf("0x%02x ", rdata[i]);
   	printf("\n");
#endif
   	
   	m->Parse(rdata, data_len);
}


void MouseController::Parse(uint8_t *buf, uint32_t len)
{
	MOUSEINFO *pmi = (MOUSEINFO*)buf;

	if (prevState.mouseInfo.bmLeftButton == 0 && pmi->bmLeftButton == 1)
		OnLeftButtonDown(pmi);

	if (prevState.mouseInfo.bmLeftButton == 1 && pmi->bmLeftButton == 0)
		OnLeftButtonUp(pmi);

	if (prevState.mouseInfo.bmRightButton == 0 && pmi->bmRightButton == 1)
		OnRightButtonDown(pmi);

	if (prevState.mouseInfo.bmRightButton == 1 && pmi->bmRightButton == 0)
		OnRightButtonUp(pmi);

	if (prevState.mouseInfo.bmMiddleButton == 0 && pmi->bmMiddleButton == 1)
		OnMiddleButtonDown(pmi);

	if (prevState.mouseInfo.bmMiddleButton == 1 && pmi->bmMiddleButton == 0)
		OnMiddleButtonUp(pmi);

	if (prevState.mouseInfo.dX != pmi->dX || prevState.mouseInfo.dY != pmi->dY)
		OnMouseMove(pmi);

	for (uint32_t i = 0; i < 3; ++i)
		prevState.bInfo[i] = buf[i];
}


