/*
  Copyright (c) 2011 Arduino.  All right reserved.

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
#include "Arduino.h"

#pragma GCC diagnostic ignored "-Wconversion-null"

#ifdef USE_BoardToPin
const BoardToPin BoardToPinInfo[] = {
  { 17, UART_TYPE, 0}, // 0: PB0(UART_RX0)   /* 64Pins */
  { 18, UART_TYPE, 0}, // 1: PB1(UART_TX0)
  {  5, PWM_TYPE, 0}, // 2: PF4 (PWM0)
  {  4, PWM_TYPE, 1}, // 3: PF5 (PWM1)
  {  7, PWM_TYPE, 2}, // 4: PA10(PWM2)
  {  6, PWM_TYPE, 3}, // 5: PA11(PWM3)
  { 37, PWM_TYPE, 4}, // 6: PA15(PWM4)
  { 29, PWM_TYPE, 5}, // 7: PE5 (PWM5)
  { 30, PWM_TYPE, 6}, // 8: PB11(PWM6)
  { 38, PWM_TYPE, 7}, // 9: PA14(PWM7)
  { 39, PWM_TYPE, 8}, //10: PA13(PWM8)
  { 40, PWM_TYPE, 9}, //11: PA12(PWM9)
  { 57, GPIO_TYPE, 0}, //12: PB15
  {  2, GPIO_TYPE, 0}, //13: PB13
  {  9, I2C_TYPE, 0}, //14: PA8(I20_SDA)
  {  8, I2C_TYPE, 0}, //15: PA9(I20_SCL)
  { 44, ADC_TYPE, 0}, //16: PA0(ADC0)
  { 45, ADC_TYPE, 1}, //17: PA1(ADC1)
  { 46, ADC_TYPE, 2}, //18: PA2(ADC2)
  { 47, ADC_TYPE, 3}, //19: PA3(ADC3)
  { 48, ADC_TYPE, 4}, //20: PA4(ADC4)
  { 49, ADC_TYPE, 5}, //21: PA5(ADC5)
  { -1,        0, 0}, //22: NC
  { -1,        0, 0}, //23: NC
  { -1,        0, 0}, //24: NC
  { -1,        0, 0}, //25: NC
  { -1,        0, 0}, //26: NC
  { -1,        0, 0}, //27: NC
  { -1,        0, 0}, //28: NC
  { -1,        0, 0}, //29: NC
  { -1,        0, 0}, //30: NC
  { -1,        0, 0}, //31: NC
  { -1,        0, 0}, //32: NC
  { -1,        0, 0}, //33: NC
  { -1,        0, 0}, //34: NC
  { -1,        0, 0}, //35: NC
  { -1,        0, 0}, //36: NC
  { -1,        0, 0}, //37: NC
  { -1,        0, 0}, //38: NC
  { -1,        0, 0}, //39: NC
  { 26, SPI_TYPE, 0}, //40: PC2(SPI1_MISO0)
  { 27, SPI_TYPE, 0}, //41: PC1(SPI1_CLK)
  { 25, SPI_TYPE, 0}, //42: PC3(SPI1_MOSI0)
  { 28, SPI_TYPE, 0}, //43: PC0(SPI1_SS0)
  { 32, GPIO_TYPE, 0}, //44: PB9(SPI1_SS0)
};
#endif
const GPIOPinDescription GPIO_Desc[] =
{
#if 0  /* 48pins */
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //0
  {PB, BIT12, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB12_Msk, NULL,       NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB12_GPIO}}, //1
  {PF, BIT5 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF5_Msk, NULL,        NULL,   SYS_ALT_MFP3_PF5_Msk,                   NULL,                 SYS_GPF_MFP_PF5_GPIO}}, //2
  {PF, BIT4 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF4_Msk, NULL,        NULL,   SYS_ALT_MFP3_PF4_Msk,                   NULL,                 SYS_GPF_MFP_PF4_GPIO}}, //3
  {PA, BIT11, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA11_Msk, NULL,        NULL,  SYS_ALT_MFP3_PA11_Msk,                   NULL,                 SYS_GPA_MFP_PA11_GPIO}}, //4
  {PA, BIT10, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA10_Msk, NULL,        NULL,  SYS_ALT_MFP3_PA10_Msk,                   NULL,                 SYS_GPA_MFP_PA10_GPIO}}, //5
  {PA, BIT9 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA9_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA9_GPIO}}, //6
  {PA, BIT8 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA8_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA8_GPIO}}, //7
  {PB, BIT4, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB4_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB4_GPIO}}, //8
  {PB, BIT5, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB5_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB5_GPIO}}, //9
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //10      
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //11      
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //12      
  {PB, BIT0, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB0_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB0_GPIO}}, //13
  {PB, BIT1, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB1_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB1_GPIO}}, //14
  {PB, BIT2, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB2_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB2_GPIO}}, //15
  {PB, BIT3, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB3_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB3_GPIO}}, //16
  {PD, BIT6, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD6_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD6_GPIO}}, //17
  {PD, BIT7, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD7_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD7_GPIO}}, //18
  {PD, BIT14, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD14_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD14_GPIO}}, //19
  {PD, BIT15, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD15_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD15_GPIO}}, //20
  {PC, BIT3, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC3_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC3_GPIO}}, //21
  {PC, BIT2, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC2_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC2_GPIO}}, //22
  {PC, BIT1, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC1_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC1_GPIO}}, //23
  {PC, BIT0, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC0_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC0_GPIO}}, //24
  {PA, BIT15, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA15_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA15_GPIO}}, //25
  {PA, BIT14, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA14_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA14_GPIO}}, //26
  {PA, BIT13, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA13_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA13_GPIO}}, //27
  {PA, BIT12, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA12_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA12_GPIO}}, //28
  {PF, BIT7 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF7_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF7_GPIO}}, //29
  {PF, BIT6 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF6_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF6_GPIO}}, //30
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //31      
  {PA, BIT0 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA0_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA0_GPIO}}, //32
  {PA, BIT1 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA1_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA1_GPIO}}, //33
  {PA, BIT2 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA2_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA2_GPIO}}, //34
  {PA, BIT3 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA3_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA3_GPIO}}, //35
  {PA, BIT4 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA4_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA4_GPIO}}, //36
  {PA, BIT5 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA5_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA5_GPIO}}, //37
  {PA, BIT6 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA6_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA6_GPIO}}, //38
  {PA, BIT7 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA7_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA7_GPIO}}, //39
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //40      
  {PC, BIT7, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC7_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC7_GPIO}}, //41
  {PC, BIT6, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC6_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC6_GPIO}}, //42
  {PB, BIT15, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB15_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB15_GPIO}}, //43
  {PF, BIT0 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF0_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF0_GPIO}}, //44
  {PF, BIT1 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF1_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF1_GPIO}}, //45
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //46      
  {PF, BIT8 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF8_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF8_GPIO}}, //47
  {PB, BIT8 , {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB8_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB8_GPIO}}, //48
#else  /* 64pins */                                                   
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //0       
  {PB, BIT14, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB14_Msk, NULL,       NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB14_GPIO}}, //1
  {PB, BIT13, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB13_Msk, NULL,       NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB13_GPIO}}, //2
  {PB, BIT12, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB12_Msk, NULL,       NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB12_GPIO}}, //3
  {PF, BIT5 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF5_Msk, NULL,        NULL,   SYS_ALT_MFP3_PF5_Msk,                   NULL,                 SYS_GPF_MFP_PF5_GPIO}}, //4
  {PF, BIT4 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF4_Msk, NULL,        NULL,   SYS_ALT_MFP3_PF4_Msk,                   NULL,                 SYS_GPF_MFP_PF4_GPIO}}, //5
  {PA, BIT11, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA11_Msk, NULL,        NULL,  SYS_ALT_MFP3_PA11_Msk,                   NULL,                 SYS_GPA_MFP_PA11_GPIO}}, //6
  {PA, BIT10, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA10_Msk, NULL,        NULL,  SYS_ALT_MFP3_PA10_Msk,                   NULL,                 SYS_GPA_MFP_PA10_GPIO}}, //7
  {PA, BIT9 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA9_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA9_GPIO}}, //8
  {PA, BIT8 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA8_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA8_GPIO}}, //9
  {PB, BIT4, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB4_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB4_GPIO}}, //10
  {PB, BIT5, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB5_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB5_GPIO}}, //11
  {PB, BIT6, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB6_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB6_GPIO}}, //12
  {PB, BIT7, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB7_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB7_GPIO}}, //13
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //14      
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //15      
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //16      
  {PB, BIT0, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB0_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB0_GPIO}}, //17
  {PB, BIT1, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB1_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB1_GPIO}}, //18
  {PB, BIT2, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB2_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB2_GPIO}}, //19
  {PB, BIT3, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB3_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB3_GPIO}}, //20
  {PD, BIT6, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD6_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD6_GPIO}}, //21
  {PD, BIT7, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD7_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD7_GPIO}}, //22
  {PD, BIT14, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD14_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD14_GPIO}}, //23
  {PD, BIT15, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD15_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD15_GPIO}}, //24
  {PC, BIT3, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC3_Msk, NULL,         NULL,   SYS_ALT_MFP3_PC3_Msk,                   NULL,                 SYS_GPC_MFP_PC3_GPIO}}, //25
  {PC, BIT2, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC2_Msk, NULL,         NULL,   SYS_ALT_MFP3_PC2_Msk,                   NULL,                 SYS_GPC_MFP_PC2_GPIO}}, //26
  {PC, BIT1, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC1_Msk, NULL,         NULL,   SYS_ALT_MFP3_PC1_Msk,                   NULL,                 SYS_GPC_MFP_PC1_GPIO}}, //27
  {PC, BIT0, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC0_Msk, NULL,         NULL,   SYS_ALT_MFP3_PC0_Msk,                   NULL,                 SYS_GPC_MFP_PC0_GPIO}}, //28
  {PE, BIT5, {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE5_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPE_MFP_PE5_GPIO}}, //29
  {PB, BIT11, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB11_Msk, NULL,        NULL,  SYS_ALT_MFP3_PB11_Msk,                   NULL,                 SYS_GPB_MFP_PB11_GPIO}}, //30
  {PB, BIT10, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB10_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB10_GPIO}}, //31
  {PB, BIT9, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB9_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB9_GPIO}}, //32
  {PC, BIT11, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC11_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC11_GPIO}}, //33
  {PC, BIT10, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC10_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC10_GPIO}}, //34
  {PC, BIT9, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC9_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC9_GPIO}}, //35
  {PC, BIT8, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC8_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC8_GPIO}}, //36
  {PA, BIT15, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA15_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA15_GPIO}}, //37
  {PA, BIT14, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA14_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA14_GPIO}}, //38
  {PA, BIT13, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA13_Msk, NULL,        NULL,                   NULL,  SYS_ALT_MFP4_PA13_Msk,                 SYS_GPA_MFP_PA13_GPIO}}, //39
  {PA, BIT12, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA12_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA12_GPIO}}, //40
  {PF, BIT7 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF7_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF7_GPIO}}, //41
  {PF, BIT6 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF6_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF6_GPIO}}, //42
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //43      
  {PA, BIT0 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA0_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA0_GPIO}}, //44
  {PA, BIT1 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA1_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA1_GPIO}}, //45
  {PA, BIT2 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA2_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA2_GPIO}}, //46
  {PA, BIT3 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA3_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA3_GPIO}}, //47
  {PA, BIT4 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA4_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA4_GPIO}}, //48
  {PA, BIT5 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA5_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA5_GPIO}}, //49
  {PA, BIT6 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA6_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA6_GPIO}}, //50
  {PA, BIT7 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA7_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA7_GPIO}}, //51
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //52      
  {PC, BIT7, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC7_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC7_GPIO}}, //53
  {PC, BIT6, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC6_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC6_GPIO}}, //54
#if 0                                                                 
  {PC, BIT15, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC15_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC15_GPIO}}, //55
  {PC, BIT14, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC14_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC14_GPIO}}, //56
#else                                                                 
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //55      
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //56      
#endif                                                                
  {PB, BIT15, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB15_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB15_GPIO}}, //57
  {PF, BIT0 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF0_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF0_GPIO}}, //58
  {PF, BIT1 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF1_Msk, NULL,         NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF1_GPIO}}, //59
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //60      
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //61      
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //62      
  {PF, BIT8 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF8_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF8_GPIO}}, //63
  {PB, BIT8 , {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB8_Msk, NULL,        NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB8_GPIO}}, //64
#endif
};

const PWMPinDescription PWM_Desc[] = {
  {PWM1, PWM1_MODULE, PWM1_IRQn, 4, 500, { 5, SYS_GPF_MFP_PF4_PWM1_CH4,       NULL,NULL, SYS_ALT_MFP3_PF4_PWM1_CH4,    NULL}}, //0
  {PWM1, PWM1_MODULE, PWM1_IRQn, 5, 500, { 4, SYS_GPF_MFP_PF5_PWM1_CH5,       NULL,NULL, SYS_ALT_MFP3_PF5_PWM1_CH5,    NULL}}, //1
  {PWM1, PWM1_MODULE, PWM1_IRQn, 2, 500, { 7, SYS_GPA_MFP_PA10_PWM1_CH2,      NULL,NULL, SYS_ALT_MFP3_PA10_PWM1_CH2,    NULL}}, //2
  {PWM1, PWM1_MODULE, PWM1_IRQn, 3, 500, { 6, SYS_GPA_MFP_PA11_PWM1_CH3,      NULL,NULL, SYS_ALT_MFP3_PA11_PWM1_CH3,    NULL}}, //3
  {PWM0, PWM0_MODULE, PWM0_IRQn, 3, 500, {37, SYS_GPA_MFP_PA15_PWM0_CH3,      NULL,NULL,                      NULL,    NULL}}, //4
  {PWM0, PWM0_MODULE, PWM0_IRQn, 5, 500, {29, SYS_GPE_MFP_PE5_PWM0_CH5,       NULL,NULL,                      NULL,    NULL}}, //5
  {PWM0, PWM0_MODULE, PWM0_IRQn, 4, 500, {30, SYS_GPB_MFP_PB11_PWM0_CH4,      NULL,NULL, SYS_ALT_MFP3_PB11_PWM0_CH4,    NULL}}, //6
  {PWM0, PWM0_MODULE, PWM0_IRQn, 2, 500, {38, SYS_GPA_MFP_PA14_PWM0_CH2,      NULL,NULL,                      NULL,    NULL}}, //7
  {PWM0, PWM0_MODULE, PWM0_IRQn, 1, 500, {39, SYS_GPA_MFP_PA13_PWM0_CH1,      NULL,NULL,                      NULL,    NULL}}, //8
  {PWM0, PWM0_MODULE, PWM0_IRQn, 0, 500, {40, SYS_GPA_MFP_PA12_PWM0_CH0,      NULL,NULL,                      NULL,    NULL}}, //9
};


const ADCPinDescription ADC_Desc[] = {
  {ADC, ADC_MODULE, 0, {44, SYS_GPA_MFP_PA0_ADC0, NULL, NULL, NULL, NULL}}, //0
  {ADC, ADC_MODULE, 1, {45, SYS_GPA_MFP_PA1_ADC1, NULL, NULL, NULL, NULL}}, //1
  {ADC, ADC_MODULE, 2, {46, SYS_GPA_MFP_PA2_ADC2, NULL, NULL, NULL, NULL}}, //2
  {ADC, ADC_MODULE, 3, {47, SYS_GPA_MFP_PA3_ADC3, NULL, NULL, NULL, NULL}}, //3
  {ADC, ADC_MODULE, 4, {48, SYS_GPA_MFP_PA4_ADC4, NULL, NULL, NULL, NULL}}, //4
  {ADC, ADC_MODULE, 5, {49, SYS_GPA_MFP_PA5_ADC5, NULL, NULL, NULL, NULL}}, //5
};

const SPIPinAlt_TypeDef SPI0PinAlt[] = {
  {{PC_1, SYS_GPC_MFP_PC1_SPI0_CLK  , NULL, NULL, NULL, NULL},
   {PC_2, SYS_GPC_MFP_PC2_SPI0_MISO0, NULL, NULL, NULL, NULL},
   {PC_3, SYS_GPC_MFP_PC3_SPI0_MOSI0, NULL, NULL, NULL, NULL},
   {PC_0, SYS_GPC_MFP_PC0_SPI0_SS0  , NULL, NULL, NULL, NULL},}
};

const SPIPinDescription SPI_Desc[] = {
  {SPI0, SPI0_MODULE, SPI0_IRQn, CLK_CLKSEL1_SPI0_S_HCLK,SPI0PinAlt},
};

const UARTPinAlt_TypeDef UART0PinAlt[] = {
  {{PB_0, SYS_GPB_MFP_PB0_UART0_RXD, NULL, NULL, NULL, NULL}, {PB_1, SYS_GPB_MFP_PB1_UART0_TXD, NULL, NULL, NULL, NULL}},
};

const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART02_IRQn, UART0PinAlt},
};

const I2CPinAlt_TypeDef I2C0PinAlt[] = {
  {{PA_8, SYS_GPA_MFP_PA8_I2C0_SDA, NULL, NULL, NULL, NULL}, {PA_9, SYS_GPA_MFP_PA9_I2C0_SCL, NULL, NULL, NULL, NULL}},
};
const I2CPinDescription I2C_Desc[] = {
  {I2C0, I2C0_MODULE, I2C0_IRQn,I2C0PinAlt},
};
