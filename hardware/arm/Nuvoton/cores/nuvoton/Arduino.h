/******************************************************************************
 * @file     Arduino.h
 * @version  V2.00
 * $Date: 13/10/07 3:57p $ 
 * @brief    MINI51 Series Global Control for Arduino
 *
 * @note
 * Copyright (C) 2012 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
 
#ifndef _ARDUINO_H_
#define _ARDUINO_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "wiring.h"
#include "WInterrupts.h"
#include "wiring_digital.h"
#include "wiring_analog.h"
#include "arm/nuvoton.h"

#ifndef ARDUINO
#define ARDUINO 185
#endif

extern uint32_t SystemTickClock;
#define clockCyclesPerMicrosecond() ( SystemCoreClock / 1000000L )
#define clockCyclesToMicroseconds(a) ( ((a) * 1000L) / (SystemCoreClock / 1000L) )
#define microsecondsToClockCycles(a) ( (a) * (SystemCoreClock / 1000000L) )

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

//#include "wiring_shift.h"

void yield(void);

#ifdef __cplusplus
}

/*C++ including option*/
#include "WCharacter.h"
//#include "WString.h"
#include "WMath.h"
#include "HardwareSerial.h"
#include "HardwareTimer.h"
#include "wiring_pulse.h"
#include "arm/NuConsole.h"

#if USE_ARDUINOSTREAMING
#  include <Streaming.h>
#endif

void tone(uint8_t ucPin, unsigned int frequency, unsigned long duration = 0);
void noTone(uint8_t ucPin);

#endif //__cplusplus

static volatile uint8_t init_flag=0;	

void setup(void);
void loop(void);

#if 0  //ndef USBUSB_VID
#if defined(__M451__)
  #define USB_VID     0x0416        // nuvoton
  #define USB_PID     0x8249
#elif defined(__NUC240__)
  #define USB_VID            0x0416 // nuvoton
  #define USB_PID_NUC200     0x003E
#elif defined(__NANO100__)
  #define USB_VID            0x0416 // nuvoton
  #define USB_PID            0x8240
#endif
#endif

#include "usb/USBCore.h"
#include "usb/USBAPI.h"

#endif