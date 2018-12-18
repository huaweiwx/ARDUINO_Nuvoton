/*
 * Copyright (c) 2018 by huaweiwx <huaweiwx@sina.com>
 * NANO100_LCD_PANEL class for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */
 
#ifndef __NANO100_LCDPANEL_H
#define __NANO100_LCDPANEL_H

#include "LCD_Panel.h"
#include "LCDLIB.h"

class LCDClass {
  public:
    void Init(void){
	    LCD_Init();
    }
    
    void print(uint32_t  u32Zone, char *string){
	    LCDLIB_Printf(u32Zone, string);
    }
    
    void putChar(uint32_t u32Zone, uint32_t u32Index, uint8_t u8Ch){
	    LCDLIB_PutChar(u32Zone, u32Index, u8Ch);
    }
    
    void setSymbol(uint32_t u32Zone, uint32_t u32Index, uint32_t u32OnOff){
	    LCDLIB_SetSymbol(u32Zone, u32Index, u32OnOff);
    }
    
    void printNumber(uint32_t  u32Zone, long long value){
	    LCDLIB_PrintNumber(u32Zone,value);
    }

};

#endif  /* __NANO100_LCDPANEL_H */

