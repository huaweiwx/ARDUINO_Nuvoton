/**************************************************************************//**
 * @file     LCD_Commom.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 15/06/26 2:12p $
 * @brief    Common files for Tiny board sample code.
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "Arduino.h"
#include "lcd.h"
#include "LCDLIB.h"

/*!<Enable LCD for 100/128-Pin Package */
#define MFP_LCD_TYPEA() { \
    SYS->PA_L_MFP |= 0x77770000;    /* seg 36 ~ 39 */\
    SYS->PA_H_MFP |= 0x7777;        /* seg 20 ~ 23 */\
    SYS->PB_L_MFP = 0x77777777;     /* seg 10 ~ 13, 4 ~ 7 */\
    SYS->PB_H_MFP = 0x77777777;     /* LCD V1 ~ V3, seg 30 ~ 31, 24 ~ 26 */\
    SYS->PC_L_MFP |= 0x777777;      /* LCD COM3 ~ COM0, DH1/DH2 */\
    SYS->PC_H_MFP |= 0x77000000;    /* seg 32 ~ 33 */\
    SYS->PD_L_MFP |= 0x77770000;    /* seg 2 ~ 3, 34 ~ 35 */\
    SYS->PD_H_MFP = 0x77777777;     /* seg 0 ~ 1, 14 ~ 19 */\
    SYS->PE_L_MFP |= 0x70000000;    /* seg 8 */\
    SYS->PE_H_MFP |= 0x77700007;    /* seg 9, 27 ~ 29 */\
  }

/*!<Enable LCD for 64-Pin Package */
#define MFP_LCD_TYPEB() { \
    SYS->PA_L_MFP |= 0x77777700;    /* seg 18 ~ 23 */\
    SYS->PA_H_MFP = 0x77777777;     /* seg 6 ~ 9, 24 ~ 27 */\
    SYS->PB_L_MFP = 0x77777777;     /* COM2, COM3, seg 0 ~ 5 */\
    SYS->PB_H_MFP = 0x77777777;     /* LCD V1 ~ V3, seg 10 ~ 14 */\
    SYS->PC_L_MFP |= 0x70007777;    /* LCD COM1 ~ COM0, DH1/DH2, seg 17 */\
    SYS->PC_H_MFP |= 0x77007777;    /* seg 28 ~ 31, 15 ~ 16 */\
  }


long long char_to_int(char c)
{
    if(c=='0') return 0;
    else if(c=='1') return 1;
    else if(c=='2') return 2;
    else if(c=='3') return 3;
    else if(c=='4') return 4;
    else if(c=='5') return 5;
    else if(c=='6') return 6;
    else if(c=='7') return 7;
    else if(c=='8') return 8;
    else if(c=='9') return 9;

    return -1;
}

long long local_atoi(char text[])
{
    int len = strlen(text);
    int len2, negflag=0;
    long long mul=len;
    long long i=0, j=0, mul2=1;
    long long result=0;

    if( text[0] == '-')
    {
        negflag = 1;
        len2 = len - 1;
        for(i=0; i<len2; i++)
        {
            text[i] = text[i+1];
        }
        text[i] = '\0';
        len--;
        mul = len;
    }

    for(i=0; i < len; i++)
    {
        if(mul==1) mul2 = 1;
        else if(mul>1)
            for(j=0; j<(mul-1); j++)
                mul2 *= 10;
        result += mul2*char_to_int(text[i]);
        mul--;
        mul2=1;
    }

    if(negflag==1)
        result = 0 - result;

    return result;
}

void ControlSegment(uint32_t onoff, int com, int seg)
{
    LCD_SetPixel(com, seg, onoff);
}


void textticker(char *string, uint32_t delayus)
{
    char showstring[7], tmpstring[7];
    int showidx, textidx, storeshowidx, storetextidx;
    int textlen;
    uint32_t i;

    strcpy(&showstring[0], "       ");

    textlen = strlen(string);

    showidx = 6;

    for(textidx=0; textidx<textlen; textidx++)
    {
        // clear showstring
        for(storetextidx=0; storetextidx<=6; storetextidx++) showstring[storetextidx] = ' ';

        storetextidx = textidx;
        if((6-showidx) > 0)
        {
            storetextidx -= (6-showidx);
        }
        for(storeshowidx=showidx; storeshowidx<=6; storeshowidx++)
        {
            showstring[storeshowidx] = string[storetextidx++];
        }
        if(showidx!=0)
            showidx--;
        //printf("%s \r\n", showstring);
        LCDLIB_Printf(0, &showstring[0]);
        CLK_SysTickDelay(delayus);

    }

    for(showidx=0; showidx<=6; showidx++)
    {
        strcpy(tmpstring, showstring);
        for(storeshowidx=0; storeshowidx<=6; storeshowidx++)
        {
            for(i = 0; i < 10000; i++);

            if((storeshowidx+1) <= 6)
                showstring[storeshowidx] = tmpstring[storeshowidx+1];
            else
                showstring[storeshowidx] = ' ';
        }

        LCDLIB_Printf(0, &showstring[0]);
        CLK_SysTickDelay(delayus);
    }

}

// hour: 24-hours
void showTime(uint32_t hour, uint32_t minute)
{
    long long time;
    // show time
    time = hour * 100 + minute;

    LCDLIB_PrintNumber(1, time);
    LCD_SetPixel(3,29,1);
}

void LCD_Init(void)
{
  /*---------------------------------------------------------------------------------------------------------*/
  /* Init System Clock                                                                                       */
  /*---------------------------------------------------------------------------------------------------------*/
  /* Unlock protected registers */
  SYS_UnlockReg();

  CLK->PWRCTL |= (0x1 << CLK_PWRCTL_LXT_EN_Pos); // LXT Enable
  /* Waiting for 32KHz clock ready */
  CLK_WaitClockReady( CLK_CLKSTATUS_LXT_STB_Msk);

  CLK->CLKSEL1 &= ~CLK_CLKSEL1_LCD_S_Msk;
  CLK->CLKSEL1 |= (0x0 << CLK_CLKSEL1_LCD_S_LXT);// Clock source from external 12 MHz or 32 KHz crystal clock

  /* Enable IP clock */
  CLK->APBCLK |= CLK_APBCLK_LCD_EN;

  /* Select LCD COMs, SEGs, V1 ~ V3, DH1, DH2 */
  MFP_LCD_TYPEA();

  /* Digital Input Path Disable */
  /* V1, V2 and V3 */
  PB->OFFD |= (0xE000000);
  /* DH1 and DH2 */
  PC->OFFD |= (0x30000);
  /* COM0~3 */
  PC->OFFD |= (0x3C0000);
  /* SEG0~39 */
  PA->OFFD |= (0x0FF00000);
  PB->OFFD |= (0xF1FF0000);
  PC->OFFD |= (0xC0000000);
  PD->OFFD |= (0xFFF00000);
  PE->OFFD |= (0xE1800000);

  /* Lock protected registers */
  SYS_LockReg();

  /* Do LCD Initializaton */
  LCD_Open(LCD_C_TYPE, 4, LCD_BIAS_THIRD, LCD_FREQ_DIV64, LCD_CPVOl_3V);
  LCD_EnableDisplay();

  /* Start displaying on LCD */
  LCDLIB_SetSymbol(2, 27, 1);
}


/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/



