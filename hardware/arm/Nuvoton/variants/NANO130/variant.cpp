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

#if defined(__M451__)
#ifdef USE_BoardToPin
const BoardToPin BoardToPinInfo[] = {
  { 21, UART_TYPE, 0}, // 0: PD6(UART_RX0)
  { 15, UART_TYPE, 0}, // 1: PD1(UART_TX0)
  { 38, PWM_TYPE, 0}, // 2: PC9(PWM0)
  { 39, PWM_TYPE, 1}, // 3: PC10(PWM1)
  { 40, PWM_TYPE, 2}, // 4: PC11(PWM2)
  { 41, PWM_TYPE, 3}, // 5: PC12(PWM3)
  { 42, PWM_TYPE, 4}, // 6: PC13(PWM4)
  { 43, PWM_TYPE, 5}, // 7: PC14(PWM5)
  { 20, PWM_TYPE, 6}, // 8: PE3(PWM6)
  { 32, PWM_TYPE, 7}, // 9: PD7(PWM7)
  { 27, GPIO_TYPE, 0}, //10: PD11
  { 25, GPIO_TYPE, 0}, //11: PF2
  { 13, GPIO_TYPE, 0}, //12: PD8
  { 12, GPIO_TYPE, 0}, //13: PC8
  { 49, I2C_TYPE, 1}, //14: PE0(I2C1_SDA)
  { 48, I2C_TYPE, 1}, //15: PC4(I2C1_SCL)
  { 97, ADC_TYPE, 0}, //16: PB9 (ADC0)
  { 98, ADC_TYPE, 1}, //17: PB10(ADC1)
  { 99, ADC_TYPE, 2}, //18: PB11(ADC2)
  {100, ADC_TYPE, 3}, //19: PB12(ADC3)
  {  1, ADC_TYPE, 4}, //20: PB13(ADC4)
  {  2, ADC_TYPE, 5}, //21: PB14(ADC5)
  {  3, ADC_TYPE, 6}, //22: PB15(ADC6)
  {  4, ADC_TYPE, 7}, //23: PB5 (ADC7)
  {  5, ADC_TYPE, 8}, //24: PB6 (ADC8)
  {  6, ADC_TYPE, 9}, //25: PB7 (ADC9)
  { 92, ADC_TYPE, 10}, //26: PB1 (ADC10)
  { 52, GPIO_TYPE, 0}, //27: PC7
  { 91, GPIO_TYPE, 0}, //28: PB0
  { -1,        0, 0}, //29: NC
  { 84, CAN_TYPE, 0}, //30: PA13(CAN_RX)
  { 83, CAN_TYPE, 0}, //31: PA12(CAN_TX)
  { 19, I2C_TYPE, 1}, //32: PD5(I2C0_SCL)
  { 18, I2C_TYPE, 1}, //33: PD4(I2C0_SDA)
  { 93, UART_TYPE, 1}, //34: PB2(UART_RX1)
  { 94, UART_TYPE, 1}, //35: PB3(UART_TX1)
  { 47, UART_TYPE, 2}, //36: PC3(UART_RX2)
  { 46, UART_TYPE, 2}, //37: PC2(UART_TX2)
  { 58, UART_TYPE, 3}, //38: PA9(UART_RX3)
  { 57, UART_TYPE, 3}, //39: PA8(UART_TX3)
  { 30, SPI_TYPE, 0}, //40: PD14(SPI1_MISO)
  { 31, SPI_TYPE, 0}, //41: PD15(SPI1_CLK)
  { 29, SPI_TYPE, 0}, //42: PD13(SPI1_MOSI)
  { 28, SPI_TYPE, 0}, //43: PD12(SPI1_SS0)
  { 78, GPIO_TYPE, 0}, //44: PE2
  //-----------------------------------------
  { 45, GPIO_TYPE, 0}, //45: PC1
  { -1,        0, 0}, //46: NC
  {  8, GPIO_TYPE, 0}, //47: PD0
  { -1,        0, 0}, //48: NC
  { 65, GPIO_TYPE, 0}, //49: PA4
  { -1,        0, 0}, //50: NC
  { 62, GPIO_TYPE, 0}, //51: PA7
  { -1,        0, 0}, //52: NC
  { 63, GPIO_TYPE, 0}, //53: PA6
  { -1,        0, 0}, //54: NC
  { 64, GPIO_TYPE, 0}, //55: PA5
  { -1,        0, 0}, //56: NC
  { 16, GPIO_TYPE, 0}, //57: PD2
  { -1,        0, 0}, //58: NC
  { 26, GPIO_TYPE, 0}, //59: PD10
  { 53, GPIO_TYPE, 0}, //60: PE4
  {  8,        0, 0}, //61: NC
  { 54, GPIO_TYPE, 0}, //62: PE5
  { 14, GPIO_TYPE, 0}, //63: PD9
  { 82, GPIO_TYPE, 0}, //64: PA0
  { 51, GPIO_TYPE, 0}, //65: PC6
  { 81, GPIO_TYPE, 0}, //66: PA1
  { 73, GPIO_TYPE, 0}, //67: PE12
  { 68, GPIO_TYPE, 0}, //68: PE1
  { 74, GPIO_TYPE, 0}, //69: PE13
  { 95, GPIO_TYPE, 0}, //70: PB4
  { 71, GPIO_TYPE, 0}, //71: PE10
  { 96, GPIO_TYPE, 0}, //72: PB8
  { 72, GPIO_TYPE, 0}, //73: PE11
  { 85, GPIO_TYPE, 0}, //74: PA14
  { 69, GPIO_TYPE, 0}, //75: PE8
  { 86, GPIO_TYPE, 0}, //76: PA15
  { 70, GPIO_TYPE, 0}, //77: PE9
  { 17, GPIO_TYPE, 0}, //78: PD3
  { 50, GPIO_TYPE, 0}, //79: PC5
  { 44, GPIO_TYPE, 0}, //80: PC0
};
#endif
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}}, //0
  {PB, BIT13, {(uint32_t)&SYS->GPB_MFPH, SYS_GPB_MFPH_PB13MFP_Msk, SYS_GPB_MFPH_PB13MFP_GPIO}}, //1
  {PB, BIT14, {(uint32_t)&SYS->GPB_MFPH, SYS_GPB_MFPH_PB14MFP_Msk, SYS_GPB_MFPH_PB14MFP_GPIO}}, //2
  {PB, BIT15, {(uint32_t)&SYS->GPB_MFPH, SYS_GPB_MFPH_PB15MFP_Msk, SYS_GPB_MFPH_PB15MFP_GPIO}}, //3
  {PB, BIT5, {(uint32_t)&SYS->GPB_MFPL, SYS_GPB_MFPL_PB5MFP_Msk, SYS_GPB_MFPL_PB5MFP_GPIO }}, //4
  {PB, BIT6, {(uint32_t)&SYS->GPB_MFPL, SYS_GPB_MFPL_PB6MFP_Msk, SYS_GPB_MFPL_PB6MFP_GPIO }}, //5
  {PB, BIT7, {(uint32_t)&SYS->GPB_MFPL, SYS_GPB_MFPL_PB7MFP_Msk, SYS_GPB_MFPL_PB7MFP_GPIO }}, //6
  {NULL, NULL, {NULL, NULL, NULL}}, //7
  {PD, BIT0, {(uint32_t)&SYS->GPD_MFPL, SYS_GPD_MFPL_PD0MFP_Msk, SYS_GPD_MFPL_PD0MFP_GPIO }}, //8
  {NULL, NULL, {NULL, NULL, NULL}}, //9
  {NULL, NULL, {NULL, NULL, NULL}}, //10
  {NULL, NULL, {NULL, NULL, NULL}}, //11
  {PC, BIT8, {(uint32_t)&SYS->GPC_MFPH, SYS_GPC_MFPH_PC8MFP_Msk, SYS_GPC_MFPH_PC8MFP_GPIO }}, //12
  {PD, BIT8, {(uint32_t)&SYS->GPD_MFPH, SYS_GPD_MFPH_PD8MFP_Msk, SYS_GPD_MFPH_PD8MFP_GPIO }}, //13
  {PD, BIT9, {(uint32_t)&SYS->GPD_MFPH, SYS_GPD_MFPH_PD9MFP_Msk, SYS_GPD_MFPH_PD9MFP_GPIO }}, //14
  {PD, BIT1, {(uint32_t)&SYS->GPD_MFPL, SYS_GPD_MFPL_PD1MFP_Msk, SYS_GPD_MFPL_PD1MFP_GPIO }}, //15
  {PD, BIT2, {(uint32_t)&SYS->GPD_MFPL, SYS_GPD_MFPL_PD2MFP_Msk, SYS_GPD_MFPL_PD2MFP_GPIO }}, //16
  {PD, BIT3, {(uint32_t)&SYS->GPD_MFPL, SYS_GPD_MFPL_PD3MFP_Msk, SYS_GPD_MFPL_PD3MFP_GPIO }}, //17
  {PD, BIT4, {(uint32_t)&SYS->GPD_MFPL, SYS_GPD_MFPL_PD4MFP_Msk, SYS_GPD_MFPL_PD4MFP_GPIO }}, //18
  {PD, BIT5, {(uint32_t)&SYS->GPD_MFPL, SYS_GPD_MFPL_PD5MFP_Msk, SYS_GPD_MFPL_PD5MFP_GPIO }}, //19
  {PE, BIT3, {(uint32_t)&SYS->GPE_MFPL, SYS_GPE_MFPL_PE3MFP_Msk, SYS_GPE_MFPL_PE3MFP_GPIO }}, //20
  {PD, BIT6, {(uint32_t)&SYS->GPD_MFPL, SYS_GPD_MFPL_PD6MFP_Msk, SYS_GPD_MFPL_PD6MFP_GPIO }}, //21
  {NULL, NULL, {NULL, NULL, NULL}}, //22
  {PF, BIT0, {(uint32_t)&SYS->GPF_MFPL, SYS_GPF_MFPL_PF0MFP_Msk, SYS_GPF_MFPL_PF0MFP_GPIO }}, //23
  {PF, BIT1, {(uint32_t)&SYS->GPF_MFPL, SYS_GPF_MFPL_PF1MFP_Msk, SYS_GPF_MFPL_PF1MFP_GPIO }}, //24
  {PF, BIT2, {(uint32_t)&SYS->GPF_MFPL, SYS_GPF_MFPL_PF2MFP_Msk, SYS_GPF_MFPL_PF2MFP_GPIO }}, //25
  {PD, BIT10, {(uint32_t)&SYS->GPD_MFPH, SYS_GPD_MFPH_PD10MFP_Msk, SYS_GPD_MFPH_PD10MFP_GPIO}}, //26
  {PD, BIT11, {(uint32_t)&SYS->GPD_MFPH, SYS_GPD_MFPH_PD11MFP_Msk, SYS_GPD_MFPH_PD11MFP_GPIO}}, //27
  {PD, BIT12, {(uint32_t)&SYS->GPD_MFPH, SYS_GPD_MFPH_PD12MFP_Msk, SYS_GPD_MFPH_PD12MFP_GPIO}}, //28
  {PD, BIT13, {(uint32_t)&SYS->GPD_MFPH, SYS_GPD_MFPH_PD13MFP_Msk, SYS_GPD_MFPH_PD13MFP_GPIO}}, //29
  {PD, BIT14, {(uint32_t)&SYS->GPD_MFPH, SYS_GPD_MFPH_PD14MFP_Msk, SYS_GPD_MFPH_PD14MFP_GPIO}}, //30
  {PD, BIT15, {(uint32_t)&SYS->GPD_MFPH, SYS_GPD_MFPH_PD15MFP_Msk, SYS_GPD_MFPH_PD15MFP_GPIO}}, //31
  {PD, BIT7, {(uint32_t)&SYS->GPD_MFPL, SYS_GPD_MFPL_PD7MFP_Msk, SYS_GPD_MFPL_PD7MFP_GPIO }}, //32
  {PF, BIT3, {(uint32_t)&SYS->GPF_MFPL, SYS_GPF_MFPL_PF3MFP_Msk, SYS_GPF_MFPL_PF3MFP_GPIO }}, //33
  {PF, BIT4, {(uint32_t)&SYS->GPF_MFPL, SYS_GPF_MFPL_PF4MFP_Msk, SYS_GPF_MFPL_PF4MFP_GPIO }}, //34
  {NULL, NULL, {NULL, NULL, NULL}}, //35
  {NULL, NULL, {NULL, NULL, NULL}}, //36
  {NULL, NULL, {NULL, NULL, NULL}}, //37
  {PC, BIT9, {(uint32_t)&SYS->GPC_MFPH, SYS_GPC_MFPH_PC9MFP_Msk, SYS_GPC_MFPH_PC9MFP_GPIO }}, //38
  {PC, BIT10, {(uint32_t)&SYS->GPC_MFPH, SYS_GPC_MFPH_PC10MFP_Msk, SYS_GPC_MFPH_PC10MFP_GPIO}}, //39
  {PC, BIT11, {(uint32_t)&SYS->GPC_MFPH, SYS_GPC_MFPH_PC11MFP_Msk, SYS_GPC_MFPH_PC11MFP_GPIO}}, //40
  {PC, BIT12, {(uint32_t)&SYS->GPC_MFPH, SYS_GPC_MFPH_PC12MFP_Msk, SYS_GPC_MFPH_PC12MFP_GPIO}}, //41
  {PC, BIT13, {(uint32_t)&SYS->GPC_MFPH, SYS_GPC_MFPH_PC13MFP_Msk, SYS_GPC_MFPH_PC13MFP_GPIO}}, //42
  {PC, BIT14, {(uint32_t)&SYS->GPC_MFPH, SYS_GPC_MFPH_PC14MFP_Msk, SYS_GPC_MFPH_PC14MFP_GPIO}}, //43
  {PC, BIT0, {(uint32_t)&SYS->GPC_MFPL, SYS_GPC_MFPL_PC0MFP_Msk, SYS_GPC_MFPL_PC0MFP_GPIO }}, //44
  {PC, BIT1, {(uint32_t)&SYS->GPC_MFPL, SYS_GPC_MFPL_PC1MFP_Msk, SYS_GPC_MFPL_PC1MFP_GPIO }}, //45
  {PC, BIT2, {(uint32_t)&SYS->GPC_MFPL, SYS_GPC_MFPL_PC2MFP_Msk, SYS_GPC_MFPL_PC2MFP_GPIO }}, //46
  {PC, BIT3, {(uint32_t)&SYS->GPC_MFPL, SYS_GPC_MFPL_PC3MFP_Msk, SYS_GPC_MFPL_PC3MFP_GPIO }}, //47
  {PC, BIT4, {(uint32_t)&SYS->GPC_MFPL, SYS_GPC_MFPL_PC4MFP_Msk, SYS_GPC_MFPL_PC4MFP_GPIO }}, //48
  {PE, BIT0, {(uint32_t)&SYS->GPE_MFPL, SYS_GPE_MFPL_PE0MFP_Msk, SYS_GPE_MFPL_PE0MFP_GPIO }}, //49
  {PC, BIT5, {(uint32_t)&SYS->GPC_MFPL, SYS_GPC_MFPL_PC5MFP_Msk, SYS_GPC_MFPL_PC5MFP_GPIO }}, //50
  {PC, BIT6, {(uint32_t)&SYS->GPC_MFPL, SYS_GPC_MFPL_PC6MFP_Msk, SYS_GPC_MFPL_PC6MFP_GPIO }}, //51
  {PC, BIT7, {(uint32_t)&SYS->GPC_MFPL, SYS_GPC_MFPL_PC7MFP_Msk, SYS_GPC_MFPL_PC7MFP_GPIO }}, //52
  {PE, BIT4, {(uint32_t)&SYS->GPE_MFPL, SYS_GPE_MFPL_PE4MFP_Msk, SYS_GPE_MFPL_PE4MFP_GPIO }}, //53
  {PE, BIT5, {(uint32_t)&SYS->GPE_MFPL, SYS_GPE_MFPL_PE5MFP_Msk, SYS_GPE_MFPL_PE5MFP_GPIO }}, //54
  {PF, BIT5, {(uint32_t)&SYS->GPF_MFPL, SYS_GPF_MFPL_PF5MFP_Msk, SYS_GPF_MFPL_PF5MFP_GPIO }}, //55
  {PF, BIT6, {(uint32_t)&SYS->GPF_MFPL, SYS_GPF_MFPL_PF6MFP_Msk, SYS_GPF_MFPL_PF6MFP_GPIO }}, //56
  {PA, BIT8, {(uint32_t)&SYS->GPA_MFPH, SYS_GPA_MFPH_PA8MFP_Msk, SYS_GPA_MFPH_PA8MFP_GPIO }}, //57
  {PA, BIT9, {(uint32_t)&SYS->GPA_MFPH, SYS_GPA_MFPH_PA9MFP_Msk, SYS_GPA_MFPH_PA9MFP_GPIO }}, //58
  {PA, BIT10, {(uint32_t)&SYS->GPA_MFPH, SYS_GPA_MFPH_PA10MFP_Msk, SYS_GPA_MFPH_PA10MFP_GPIO}}, //59
  {PA, BIT11, {(uint32_t)&SYS->GPA_MFPH, SYS_GPA_MFPH_PA11MFP_Msk, SYS_GPA_MFPH_PA11MFP_GPIO}}, //60
  {PE, BIT6, {(uint32_t)&SYS->GPE_MFPL, SYS_GPE_MFPL_PE6MFP_Msk, SYS_GPE_MFPL_PE6MFP_GPIO }}, //61
  {PA, BIT7, {(uint32_t)&SYS->GPA_MFPL, SYS_GPA_MFPL_PA7MFP_Msk, SYS_GPA_MFPL_PA7MFP_GPIO }}, //62
  {PA, BIT6, {(uint32_t)&SYS->GPA_MFPL, SYS_GPA_MFPL_PA6MFP_Msk, SYS_GPA_MFPL_PA6MFP_GPIO }}, //63
  {PA, BIT5, {(uint32_t)&SYS->GPA_MFPL, SYS_GPA_MFPL_PA5MFP_Msk, SYS_GPA_MFPL_PA5MFP_GPIO }}, //64
  {PA, BIT4, {(uint32_t)&SYS->GPA_MFPL, SYS_GPA_MFPL_PA4MFP_Msk, SYS_GPA_MFPL_PA4MFP_GPIO }}, //65
  {NULL, NULL, {NULL, NULL, NULL}}, //66
  {NULL, NULL, {NULL, NULL, NULL}}, //67
  {PE, BIT1, {(uint32_t)&SYS->GPE_MFPL, SYS_GPE_MFPL_PE1MFP_Msk, SYS_GPE_MFPL_PE1MFP_GPIO }}, //68
  {PE, BIT8, {(uint32_t)&SYS->GPE_MFPH, SYS_GPE_MFPH_PE8MFP_Msk, SYS_GPE_MFPH_PE8MFP_GPIO }}, //69
  {PE, BIT9, {(uint32_t)&SYS->GPE_MFPH, SYS_GPE_MFPH_PE9MFP_Msk, SYS_GPE_MFPH_PE9MFP_GPIO }}, //70
  {PE, BIT10, {(uint32_t)&SYS->GPE_MFPH, SYS_GPE_MFPH_PE10MFP_Msk, SYS_GPE_MFPH_PE10MFP_GPIO}}, //71
  {PE, BIT11, {(uint32_t)&SYS->GPE_MFPH, SYS_GPE_MFPH_PE11MFP_Msk, SYS_GPE_MFPH_PE11MFP_GPIO}}, //72
  {PE, BIT12, {(uint32_t)&SYS->GPE_MFPH, SYS_GPE_MFPH_PE12MFP_Msk, SYS_GPE_MFPH_PE12MFP_GPIO}}, //73
  {PE, BIT13, {(uint32_t)&SYS->GPE_MFPH, SYS_GPE_MFPH_PE13MFP_Msk, SYS_GPE_MFPH_PE13MFP_GPIO}}, //74
  {NULL, NULL, {NULL, NULL, NULL}}, //75
  {PE, BIT7, {(uint32_t)&SYS->GPE_MFPL, SYS_GPE_MFPL_PE7MFP_Msk, SYS_GPE_MFPL_PE7MFP_GPIO }}, //76
  {PC, BIT15, {(uint32_t)&SYS->GPC_MFPH, SYS_GPC_MFPH_PC15MFP_Msk, SYS_GPC_MFPH_PC15MFP_GPIO}}, //77
  {PE, BIT2, {(uint32_t)&SYS->GPE_MFPL, SYS_GPE_MFPL_PE2MFP_Msk, SYS_GPE_MFPL_PE2MFP_GPIO }}, //78
  {PA, BIT3, {(uint32_t)&SYS->GPA_MFPL, SYS_GPA_MFPL_PA3MFP_Msk, SYS_GPA_MFPL_PA3MFP_GPIO }}, //79
  {PA, BIT2, {(uint32_t)&SYS->GPA_MFPL, SYS_GPA_MFPL_PA2MFP_Msk, SYS_GPA_MFPL_PA2MFP_GPIO }}, //80
  {PA, BIT1, {(uint32_t)&SYS->GPA_MFPL, SYS_GPA_MFPL_PA1MFP_Msk, SYS_GPA_MFPL_PA1MFP_GPIO }}, //81
  {PA, BIT0, {(uint32_t)&SYS->GPA_MFPL, SYS_GPA_MFPL_PA0MFP_Msk, SYS_GPA_MFPL_PA0MFP_GPIO }}, //82
  {PA, BIT12, {(uint32_t)&SYS->GPA_MFPH, SYS_GPA_MFPH_PA12MFP_Msk, SYS_GPA_MFPH_PA12MFP_GPIO}}, //83
  {PA, BIT13, {(uint32_t)&SYS->GPA_MFPH, SYS_GPA_MFPH_PA13MFP_Msk, SYS_GPA_MFPH_PA13MFP_GPIO}}, //84
  {PA, BIT14, {(uint32_t)&SYS->GPA_MFPH, SYS_GPA_MFPH_PA14MFP_Msk, SYS_GPA_MFPH_PA14MFP_GPIO}}, //85
  {PA, BIT15, {(uint32_t)&SYS->GPA_MFPH, SYS_GPA_MFPH_PA15MFP_Msk, SYS_GPA_MFPH_PA15MFP_GPIO}}, //86
  {NULL, NULL, {NULL, NULL, NULL}}, //87
  {NULL, NULL, {NULL, NULL, NULL}}, //88
  {NULL, NULL, {NULL, NULL, NULL}}, //89
  {NULL, NULL, {NULL, NULL, NULL}}, //90
  {PB, BIT0, {(uint32_t)&SYS->GPB_MFPL, SYS_GPB_MFPL_PB0MFP_Msk, SYS_GPB_MFPL_PB0MFP_GPIO }}, //91
  {PB, BIT1, {(uint32_t)&SYS->GPB_MFPL, SYS_GPB_MFPL_PB1MFP_Msk, SYS_GPB_MFPL_PB1MFP_GPIO }}, //92
  {PB, BIT2, {(uint32_t)&SYS->GPB_MFPL, SYS_GPB_MFPL_PB2MFP_Msk, SYS_GPB_MFPL_PB2MFP_GPIO }}, //93
  {PB, BIT3, {(uint32_t)&SYS->GPB_MFPL, SYS_GPB_MFPL_PB3MFP_Msk, SYS_GPB_MFPL_PB3MFP_GPIO }}, //94
  {PB, BIT4, {(uint32_t)&SYS->GPB_MFPL, SYS_GPB_MFPL_PB4MFP_Msk, SYS_GPB_MFPL_PB4MFP_GPIO }}, //95
  {PB, BIT8, {(uint32_t)&SYS->GPB_MFPH, SYS_GPB_MFPH_PB8MFP_Msk, SYS_GPB_MFPH_PB8MFP_GPIO }}, //96
  {PB, BIT9, {(uint32_t)&SYS->GPB_MFPH, SYS_GPB_MFPH_PB9MFP_Msk, SYS_GPB_MFPH_PB9MFP_GPIO }}, //97
  {PB, BIT10, {(uint32_t)&SYS->GPB_MFPH, SYS_GPB_MFPH_PB10MFP_Msk, SYS_GPB_MFPH_PB10MFP_GPIO}}, //98
  {PB, BIT11, {(uint32_t)&SYS->GPB_MFPH, SYS_GPB_MFPH_PB11MFP_Msk, SYS_GPB_MFPH_PB11MFP_GPIO}}, //99
  {PB, BIT12, {(uint32_t)&SYS->GPB_MFPH, SYS_GPB_MFPH_PB12MFP_Msk, SYS_GPB_MFPH_PB12MFP_GPIO}}, //100
};

const PWMPinDescription PWM_Desc[] = { //SYS_GPA_MFPL_PA5MFP_PWM0_CH0
  {PWM1, PWM1_MODULE, PWM0P0_IRQn, 0, 500, {38, SYS_GPC_MFPH_PC9MFP_PWM1_CH0  }}, //0  PC9
  {PWM1, PWM1_MODULE, PWM0P0_IRQn, 1, 500, {39, SYS_GPC_MFPH_PC10MFP_PWM1_CH1 }}, //1  PC10
  {PWM1, PWM1_MODULE, PWM0P1_IRQn, 2, 500, {40, SYS_GPC_MFPH_PC11MFP_PWM1_CH2 }}, //2  PC11
  {PWM1, PWM1_MODULE, PWM0P1_IRQn, 3, 500, {41, SYS_GPC_MFPH_PC12MFP_PWM1_CH3 }}, //3  PC12
  {PWM1, PWM1_MODULE, PWM0P2_IRQn, 4, 500, {42, SYS_GPC_MFPH_PC13MFP_PWM1_CH4 }}, //4  PC13
  {PWM1, PWM1_MODULE, PWM0P2_IRQn, 5, 500, {43, SYS_GPC_MFPH_PC14MFP_PWM1_CH5 }}, //5  PC14
  {PWM0, PWM0_MODULE, PWM0P1_IRQn, 3, 500, {20, SYS_GPE_MFPL_PE3MFP_PWM0_CH3  }}, //6  PE3
  {PWM0, PWM0_MODULE, PWM0P2_IRQn, 5, 500, {32, SYS_GPD_MFPL_PD7MFP_PWM0_CH5  }}, //7  PD7
};

const ADCPinDescription ADC_Desc[] = { //SYS_GPE_MFPL_PE0MFP_ADC0_0
  {EADC, EADC_MODULE, 6, { 97, SYS_GPB_MFPH_PB9MFP_EADC_CH6  }}, //0
  {EADC, EADC_MODULE, 7, { 98, SYS_GPB_MFPH_PB10MFP_EADC_CH7 }}, //1
  {EADC, EADC_MODULE, 8, { 99, SYS_GPB_MFPH_PB11MFP_EADC_CH8 }}, //2
  {EADC, EADC_MODULE, 9, {100, SYS_GPB_MFPH_PB12MFP_EADC_CH9 }}, //3
  {EADC, EADC_MODULE, 10, {  1, SYS_GPB_MFPH_PB13MFP_EADC_CH10}}, //4
  {EADC, EADC_MODULE, 11, {  2, SYS_GPB_MFPH_PB14MFP_EADC_CH11}}, //5
  {EADC, EADC_MODULE, 12, {  3, SYS_GPB_MFPH_PB15MFP_EADC_CH12}}, //6
  {EADC, EADC_MODULE, 13, {  4, SYS_GPB_MFPL_PB5MFP_EADC_CH13 }}, //7
  {EADC, EADC_MODULE, 14, {  5, SYS_GPB_MFPL_PB6MFP_EADC_CH14 }}, //8
  {EADC, EADC_MODULE, 15, {  6, SYS_GPB_MFPL_PB7MFP_EADC_CH15 }}, //9
  {EADC, EADC_MODULE, 1, { 92, SYS_GPB_MFPL_PB1MFP_EADC_CH1  }}, //10
};


const SPIPinDescription SPI_Desc[] = {

  { SPI2, SPI2_MODULE, SPI2_IRQn, CLK_CLKSEL2_SPI2SEL_PCLK0,
    { {31, SYS_GPD_MFPH_PD15MFP_SPI2_CLK }, {29, SYS_GPD_MFPH_PD13MFP_SPI2_MOSI},
      {30, SYS_GPD_MFPH_PD14MFP_SPI2_MISO}, {28, SYS_GPD_MFPH_PD12MFP_SPI2_SS  }
    }
  },

  //   //{SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL1_SPI1_S_HCLK,
  //   //{{60,SYS_GPC_MFP_PC9_SPI1_CLK},{58,SYS_GPC_MFP_PC11_SPI1_MOSI0 },
  //    //{59,SYS_GPC_MFP_PC10_SPI1_MISO0 },{61,SYS_GPC_MFP_PC8_SPI1_SS0}}},
};

const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART0_IRQn, {{21, SYS_GPD_MFPL_PD6MFP_UART0_RXD }, { 15, SYS_GPD_MFPL_PD1MFP_UART0_TXD }}},
  {UART1, UART1_MODULE, UART1_IRQn, {{93, SYS_GPB_MFPL_PB2MFP_UART1_RXD }, { 94, SYS_GPB_MFPL_PB3MFP_UART1_TXD }}},
  {UART2, UART2_MODULE, UART2_IRQn, {{47, SYS_GPC_MFPL_PC3MFP_UART2_RXD }, { 46, SYS_GPC_MFPL_PC2MFP_UART2_TXD }}},
  {UART3, UART3_MODULE, UART3_IRQn, {{58, SYS_GPA_MFPH_PA9MFP_UART3_RXD }, { 57, SYS_GPA_MFPH_PA8MFP_UART3_TXD }}},
};

const I2CPinDescription I2C_Desc[] = {
  {I2C1, I2C1_MODULE, {{48, SYS_GPC_MFPL_PC4MFP_I2C1_SCL}, {49, SYS_GPE_MFPL_PE0MFP_I2C1_SDA }}},
  {I2C0, I2C0_MODULE, {{19, SYS_GPD_MFPL_PD5MFP_I2C0_SCL}, {18, SYS_GPD_MFPL_PD4MFP_I2C0_SDA }}},
};


const CANPinDescription CAN_Desc[] = {
  {CAN0, CAN0_MODULE, CAN0_IRQn, {{84, SYS_GPA_MFPH_PA13MFP_CAN0_RXD}, {83, SYS_GPA_MFPH_PA12MFP_CAN0_TXD}}},
};

#elif defined(__NUC240__)
#ifdef USE_BoardToPin
const BoardToPin BoardToPinInfo[] = {{ 32, UART_TYPE, 0}, // 0: PB0(UART_RX0)
  { 33, UART_TYPE, 0}, // 1: PB1(UART_TX0)
  { 65, PWM_TYPE, 0}, // 2: PA12(PWM0)
  { 64, PWM_TYPE, 1}, // 3: PA13(PWM1)
  { 63, PWM_TYPE, 2}, // 4: PA14(PWM2)
  { 62, PWM_TYPE, 3}, // 5: PA15(PWM3)
  { 48, PWM_TYPE, 4}, // 6: PB11(PWM4)
  { 47, PWM_TYPE, 5}, // 7: PE5(PWM5)
  { 55, PWM_TYPE, 6}, // 8: PE0(PWM6)
  { 54, PWM_TYPE, 7}, // 9: PE1(PWM7)
  { 41, GPIO_TYPE, 0}, //10: PC4
  { 50, GPIO_TYPE, 0}, //11: PB9
  { 40, GPIO_TYPE, 0}, //12: PC5
  { 46, GPIO_TYPE, 0}, //13: PE6

  { 10, I2C_TYPE, 1}, //14: PA10(I21_SDA)
  {  9, I2C_TYPE, 1}, //15: PA11(I21_SCL)
  { 71, ADC_TYPE, 0}, //16: PA0(ADC0)
  { 72, ADC_TYPE, 1}, //17: PA1(ADC1)
  { 73, ADC_TYPE, 2}, //18: PA2(ADC2)
  { 74, ADC_TYPE, 3}, //19: PA3(ADC3)
  { 75, ADC_TYPE, 4}, //20: PA4(ADC4)
  { 76, ADC_TYPE, 5}, //21: PA5(ADC5)
  { 77, ADC_TYPE, 6}, //22: PA6(ADC6)
  { 78, ADC_TYPE, 7}, //23: PA7(ADC7)

  { 89, GPIO_TYPE, 0}, //24: PC15
  { 90, GPIO_TYPE, 0}, //25: PC14
  {  1, GPIO_TYPE, 0}, //26: PE15
  {  2, GPIO_TYPE, 0}, //27: PE14
  { 85, GPIO_TYPE, 0}, //28: PD4
  { 86, GPIO_TYPE, 0}, //29: PD5
  { 36, CAN_TYPE, 0}, //30: PD6(CAN_RX)
  { 37, CAN_TYPE, 0}, //31: PD7(CAN_TX)

  { 11, I2C_TYPE, 0}, //32: PA9(I2C0_SCL)
  { 12, I2C_TYPE, 0}, //33: PA8(I2C0_SDA)
  { 19, UART_TYPE, 1}, //34: PB4(UART_TX1)
  { 20, UART_TYPE, 1}, //35: PB5(UART_RX1)
  { 38, UART_TYPE, 2}, //36: PD14(UART_TX2)
  { 39, UART_TYPE, 2}, //37: PD15(UART_RX2)
  { 26, GPIO_TYPE, 0}, //38: PE7
  { 27, GPIO_TYPE, 0}, //39: PE8

  { 83, SPI_TYPE, 0}, //40: PD2(SPI2_MISO)
  { 82, SPI_TYPE, 0}, //41: PD1(SPI2_CLK)
  { 84, SPI_TYPE, 0}, //42: PD3(SPI2_MOSI)
  { 81, SPI_TYPE, 0}, //43: PD4(SPI2_SS0)
  { 56, GPIO_TYPE, 0}, //44: PC13

  { 13, GPIO_TYPE, 0}, //45: PD8
  {100, GPIO_TYPE, 0}, //46: PB8
  { 14, GPIO_TYPE, 0}, //47: PD9
  { 62, GPIO_TYPE, 0}, //48: PA15
  { 15, GPIO_TYPE, 0}, //49: PD10
  { 45, GPIO_TYPE, 0}, //50: PC0
  { 16, GPIO_TYPE, 0}, //51: PD11
  { 44, GPIO_TYPE, 0}, //52: PC1
  { 17, GPIO_TYPE, 0}, //53: PD12
  { 43, GPIO_TYPE, 0}, //54: PC2
  { 18, GPIO_TYPE, 0}, //55: PD13
  { 42, GPIO_TYPE, 0}, //56: PC3
  { 57, GPIO_TYPE, 0}, //57: PC12
  { 49, GPIO_TYPE, 0}, //58: PB10
  { -1, GPIO_TYPE, 0}, //59: X
  { 35, GPIO_TYPE, 0}, //60: PB3
  { -1, GPIO_TYPE, 0}, //61: X
  { 87, GPIO_TYPE, 0}, //62: PC7
  { -1, GPIO_TYPE, 0}, //63: X
  { 88, GPIO_TYPE, 0}, //64: PC6
  {  7, GPIO_TYPE, 0}, //65: X
  { 34, GPIO_TYPE, 0}, //66: PB2
  { -1, GPIO_TYPE, 0}, //67: X
  { 61, GPIO_TYPE, 0}, //68: PC8
  { 22, GPIO_TYPE, 0}, //69: PB7
  { 60, GPIO_TYPE, 0}, //70: PC9
  { 21, GPIO_TYPE, 0}, //71: PB6
  { 59, GPIO_TYPE, 0}, //72: PC10
  { 97, GPIO_TYPE, 0}, //73: PF2
  { 58, GPIO_TYPE, 0}, //74: PC11
  { 98, GPIO_TYPE, 0}, //75: PF3
  { 53, GPIO_TYPE, 0}, //76: PE2
  {  4, GPIO_TYPE, 0}, //77: PB14
  { 52, GPIO_TYPE, 0}, //78: PE3
  { 91, GPIO_TYPE, 0}, //79: PB15
  { 51, GPIO_TYPE, 0}, //80: PE4
};
#endif
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //0
  {PE, BIT15, {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE15_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE15_GPIO}}, //1
  {PE, BIT14, {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE14_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE14_GPIO}}, //2
  {PE, BIT13, {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE13_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE13_GPIO}}, //3
  {PB, BIT14, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB14_Msk, SYS_ALT_MFP_PB14_Msk, NULL,                   NULL,                 SYS_GPB_MFP_PB14_GPIO}}, //4
  {PB, BIT13, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB13_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB13_GPIO}}, //5
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //6
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //7
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //8
  {PA, BIT11, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA11_Msk, SYS_ALT_MFP_PA11_Msk, NULL,                   NULL,                 SYS_GPA_MFP_PA11_GPIO}}, //9
  {PA, BIT10, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA10_Msk, SYS_ALT_MFP_PA10_Msk, NULL,                   NULL,                 SYS_GPA_MFP_PA10_GPIO}}, //10
  {PA, BIT9,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA9_Msk, NULL,                 NULL,                   NULL,                 SYS_GPA_MFP_PA9_GPIO }}, //11
  {PA, BIT8,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA8_Msk, NULL,                 NULL,                   NULL,                 SYS_GPA_MFP_PA8_GPIO }}, //12
  {PD, BIT8,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD8_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD8_GPIO }}, //13
  {PD, BIT9,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD9_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD9_GPIO }}, //14
  {PD, BIT10, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD10_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD10_GPIO}}, //15
  {PD, BIT11, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD11_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD11_GPIO}}, //16
  {PD, BIT12, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD12_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD12_GPIO}}, //17
  {PD, BIT13, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD13_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD13_GPIO}}, //18
  {PB, BIT4,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB4_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB4_GPIO }}, //19
  {PB, BIT5,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB5_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB5_GPIO }}, //20
  {PB, BIT6,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB6_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB6_GPIO }}, //21
  {PB, BIT7,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB7_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB7_GPIO }}, //22
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //23
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //24
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //25
  {PE, BIT7,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE7_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE7_GPIO }}, //26
  {PE, BIT8,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE8_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE8_GPIO }}, //27
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //28
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //29
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //30
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //31
  {PB, BIT0,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB0_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB0_GPIO }}, //32
  {PB, BIT1,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB1_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB1_GPIO }}, //33
  {PB, BIT2,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB2_Msk, SYS_ALT_MFP_PB2_Msk,  NULL,                   SYS_ALT_MFP2_PB2_Msk, SYS_GPB_MFP_PB2_GPIO }}, //34
  {PB, BIT3,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB3_Msk, SYS_ALT_MFP_PB3_Msk,  SYS_ALT_MFP1_PB3_Msk,   SYS_ALT_MFP2_PB3_Msk, SYS_GPB_MFP_PB3_GPIO }}, //35
  {PD, BIT6,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD6_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD6_GPIO }}, //36
  {PD, BIT7,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD7_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD7_GPIO }}, //37
  {PD, BIT14, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD14_Msk, NULL,                 NULL,                   SYS_ALT_MFP2_PD14_Msk, SYS_GPD_MFP_PD14_GPIO}}, //38
  {PD, BIT15, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD15_Msk, NULL,                 NULL,                   SYS_ALT_MFP2_PD15_Msk, SYS_GPD_MFP_PD15_GPIO}}, //39
  {PC, BIT5,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC5_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC5_GPIO }}, //40
  {PC, BIT4,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC4_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC4_GPIO }}, //41
  {PC, BIT3,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC3_Msk, SYS_ALT_MFP_PC3_Msk,  NULL,                   NULL,                 SYS_GPC_MFP_PC3_GPIO }}, //42
  {PC, BIT2,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC2_Msk, SYS_ALT_MFP_PC2_Msk,  NULL,                   NULL,                 SYS_GPC_MFP_PC2_GPIO }}, //43
  {PC, BIT1,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC1_Msk, SYS_ALT_MFP_PC1_Msk,  NULL,                   NULL,                 SYS_GPC_MFP_PC1_GPIO }}, //44
  {PC, BIT0,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC0_Msk, SYS_ALT_MFP_PC0_Msk,  NULL,                   NULL,                 SYS_GPC_MFP_PC0_GPIO }}, //45
  {PE, BIT6,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE6_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE6_GPIO }}, //46
  {PE, BIT5,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE5_Msk, SYS_ALT_MFP_PE5_Msk,  NULL,                   SYS_ALT_MFP2_PE5_Msk, SYS_GPE_MFP_PE5_GPIO }}, //47
  {PB, BIT11, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB11_Msk, SYS_ALT_MFP_PB11_Msk, NULL,                   NULL,                 SYS_GPB_MFP_PB11_GPIO}}, //48
  {PB, BIT10, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB10_Msk, SYS_ALT_MFP_PB10_Msk, NULL,                   NULL,                 SYS_GPB_MFP_PB10_GPIO}}, //49
  {PB, BIT9,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB9_Msk, SYS_ALT_MFP_PB9_Msk,  NULL,                   NULL,                 SYS_GPB_MFP_PB9_GPIO }}, //50

  {PE, BIT4,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE4_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE4_GPIO }}, //51
  {PE, BIT3,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE3_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE3_GPIO }}, //52
  {PE, BIT2,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE2_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE2_GPIO }}, //53
  {PE, BIT1,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE1_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE1_GPIO }}, //54
  {PE, BIT0,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE0_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE0_GPIO }}, //55
  {PC, BIT13, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC13_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC13_GPIO}}, //56
  {PC, BIT12, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC12_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC12_GPIO}}, //57
  {PC, BIT11, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC11_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC11_GPIO}}, //58
  {PC, BIT10, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC10_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC10_GPIO}}, //59
  {PC, BIT9,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC9_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC9_GPIO }}, //60
  {PC, BIT8,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC8_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC8_GPIO }}, //61
  {PA, BIT15, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA15_Msk, SYS_ALT_MFP_PA15_Msk, SYS_ALT_MFP1_PA15_Msk,  NULL,                 SYS_GPA_MFP_PA15_GPIO}}, //62
  {PA, BIT14, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA14_Msk, NULL,                 SYS_ALT_MFP1_PA14_Msk,  NULL,                 SYS_GPA_MFP_PA14_GPIO}}, //63
  {PA, BIT13, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA13_Msk, NULL,                 SYS_ALT_MFP1_PA13_Msk,  NULL,                 SYS_GPA_MFP_PA13_GPIO}}, //64
  {PA, BIT12, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA12_Msk, NULL,                 SYS_ALT_MFP1_PA12_Msk,  NULL,                 SYS_GPA_MFP_PA12_GPIO}}, //65
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //66
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //67
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //68
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //69
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //70
  {PA, BIT0,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA0_Msk, NULL,                 SYS_ALT_MFP1_PA0_Msk,   NULL,                 SYS_GPA_MFP_PA0_GPIO }}, //71
  {PA, BIT1,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA1_Msk, NULL,                 SYS_ALT_MFP1_PA1_Msk,   NULL,                 SYS_GPA_MFP_PA1_GPIO }}, //72
  {PA, BIT2,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA2_Msk, NULL,                 SYS_ALT_MFP1_PA2_Msk,   NULL,                 SYS_GPA_MFP_PA2_GPIO }}, //73
  {PA, BIT3,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA3_Msk, NULL,                 SYS_ALT_MFP1_PA3_Msk,   NULL,                 SYS_GPA_MFP_PA3_GPIO }}, //74
  {PA, BIT4,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA4_Msk, NULL,                 SYS_ALT_MFP1_PA4_Msk,   NULL,                 SYS_GPA_MFP_PA4_GPIO }}, //75
  {PA, BIT5,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA5_Msk, NULL,                 SYS_ALT_MFP1_PA5_Msk,   NULL,                 SYS_GPA_MFP_PA5_GPIO }}, //76
  {PA, BIT6,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA6_Msk, NULL,                 SYS_ALT_MFP1_PA6_Msk,   NULL,                 SYS_GPA_MFP_PA6_GPIO }}, //77
  {PA, BIT7,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA7_Msk, SYS_ALT_MFP_PA7_Msk,  SYS_ALT_MFP1_PA7_Msk,   NULL,                 SYS_GPA_MFP_PA7_GPIO }}, //78
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //79
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //80
  {PD, BIT0,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD0_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD0_GPIO }}, //81
  {PD, BIT1,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD1_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD1_GPIO }}, //82
  {PD, BIT2,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD2_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD2_GPIO }}, //83
  {PD, BIT3,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD3_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD3_GPIO }}, //84
  {PD, BIT4,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD4_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD4_GPIO }}, //85
  {PD, BIT5,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD5_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD5_GPIO }}, //86
  {PC, BIT7,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC7_Msk, NULL,                 SYS_ALT_MFP1_PC7_Msk,   NULL,                 SYS_GPC_MFP_PC7_GPIO }}, //87
  {PC, BIT6,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC6_Msk, NULL,                 SYS_ALT_MFP1_PC6_Msk,   NULL,                 SYS_GPC_MFP_PC6_GPIO }}, //88
  {PC, BIT15, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC15_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC15_GPIO}}, //89
  {PC, BIT14, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC14_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC14_GPIO}}, //90
  {PB, BIT15, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB15_Msk, SYS_ALT_MFP_PB15_Msk, NULL,                   SYS_ALT_MFP2_PB15_Msk, SYS_GPB_MFP_PB15_GPIO}}, //91
  {PF, BIT0,  {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF0_Msk, NULL,                 NULL,                   NULL,                 SYS_GPF_MFP_PF0_GPIO }}, //92
  {PF, BIT1,  {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF1_Msk, NULL,                 NULL,                   NULL,                 SYS_GPF_MFP_PF1_GPIO }}, //93
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL}}, //94
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL}}, //95
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL}}, //96
  {PF, BIT2,  {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF2_Msk, NULL,                 NULL,                   NULL,                 SYS_GPF_MFP_PF2_GPIO }}, //97
  {PF, BIT3,  {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF3_Msk, NULL,                 NULL,                   NULL,                 SYS_GPF_MFP_PF3_GPIO }}, //98
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL}}, //99
  {PB, BIT8,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB8_Msk, SYS_ALT_MFP_PB8_Msk,  NULL,                   NULL,                 SYS_GPB_MFP_PB8_GPIO }}, //100
};

const PWMPinDescription PWM_Desc[] = {
  {PWMA, PWM01_MODULE, PWMA_IRQn, 0, 500, {65, SYS_GPA_MFP_PA12_PWM0, NULL,                 SYS_ALT_MFP1_PA12_PWM0, NULL                 }}, //0
  {PWMA, PWM01_MODULE, PWMA_IRQn, 1, 500, {64, SYS_GPA_MFP_PA13_PWM1, NULL,                 SYS_ALT_MFP1_PA13_PWM1, NULL                 }}, //1
  {PWMA, PWM23_MODULE, PWMA_IRQn, 2, 500, {63, SYS_GPA_MFP_PA14_PWM2, NULL,                 SYS_ALT_MFP1_PA14_PWM2, NULL                 }}, //2
  {PWMA, PWM23_MODULE, PWMA_IRQn, 3, 500, {62, SYS_GPA_MFP_PA15_PWM3, SYS_ALT_MFP_PA15_PWM3, SYS_ALT_MFP1_PA15_PWM3, NULL                 }}, //3
  {PWMB, PWM45_MODULE, PWMB_IRQn, 0, 500, {48, SYS_GPB_MFP_PB11_PWM4, SYS_ALT_MFP_PB11_PWM4, NULL,                  NULL                 }}, //4
  {PWMB, PWM45_MODULE, PWMB_IRQn, 1, 500, {47, SYS_GPE_MFP_PE5_PWM5 , SYS_ALT_MFP_PE5_PWM5 , NULL,                  SYS_ALT_MFP2_PE5_PWM5}}, //5
  {PWMB, PWM67_MODULE, PWMB_IRQn, 2, 500, {55, SYS_GPE_MFP_PE0_PWM6 , NULL,                 NULL,                  NULL                 }}, //6
  {PWMB, PWM67_MODULE, PWMB_IRQn, 3, 500, {54, SYS_GPE_MFP_PE1_PWM7 , NULL,                 NULL,                  NULL                 }}, //7
};

const ADCPinDescription ADC_Desc[] = {
  {ADC, ADC_MODULE, 0, {71, SYS_GPA_MFP_PA0_ADC0, NULL,                 SYS_ALT_MFP1_PA0_ADC0, NULL                 }}, //0
  {ADC, ADC_MODULE, 1, {72, SYS_GPA_MFP_PA1_ADC1, NULL,                 SYS_ALT_MFP1_PA1_ADC1, NULL                 }}, //1
  {ADC, ADC_MODULE, 2, {73, SYS_GPA_MFP_PA2_ADC2, NULL,                 SYS_ALT_MFP1_PA2_ADC2, NULL                 }}, //2
  {ADC, ADC_MODULE, 3, {74, SYS_GPA_MFP_PA3_ADC3, NULL,                 SYS_ALT_MFP1_PA3_ADC3, NULL                 }}, //3
  {ADC, ADC_MODULE, 4, {75, SYS_GPA_MFP_PA4_ADC4, NULL,                 SYS_ALT_MFP1_PA4_ADC4, NULL                 }}, //4
  {ADC, ADC_MODULE, 5, {76, SYS_GPA_MFP_PA5_ADC5, NULL,                 SYS_ALT_MFP1_PA5_ADC5, NULL                 }}, //5
  {ADC, ADC_MODULE, 6, {77, SYS_GPA_MFP_PA6_ADC6, NULL,                 SYS_ALT_MFP1_PA6_ADC6, NULL                 }}, //6
  {ADC, ADC_MODULE, 7, {78, SYS_GPA_MFP_PA7_ADC7, SYS_ALT_MFP_PA7_ADC7, SYS_ALT_MFP1_PA7_ADC7, NULL                 }}, //7
};


const SPIPinDescription SPI_Desc[] = {

  {
    SPI2, SPI2_MODULE, SPI2_IRQn, CLK_CLKSEL1_SPI2_S_HCLK,
    {
      {82, SYS_GPD_MFP_PD1_SPI2_CLK  , NULL, NULL, NULL},
      {84, SYS_GPD_MFP_PD3_SPI2_MOSI0, NULL, NULL, NULL},
      {83, SYS_GPD_MFP_PD2_SPI2_MISO0, NULL, NULL, NULL},
      {81, SYS_GPD_MFP_PD0_SPI2_SS0  , NULL, NULL, NULL}
    }
  },

  //{SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL1_SPI1_S_HCLK,
  //{{60,SYS_GPC_MFP_PC9_SPI1_CLK},{58,SYS_GPC_MFP_PC11_SPI1_MOSI0 },
  //{59,SYS_GPC_MFP_PC10_SPI1_MISO0 },{61,SYS_GPC_MFP_PC8_SPI1_SS0}}},

};

const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART02_IRQn, {{32, SYS_GPB_MFP_PB0_UART0_RXD, NULL, NULL, NULL}, {33, SYS_GPB_MFP_PB1_UART0_TXD, NULL, NULL, NULL} }},
  {UART1, UART1_MODULE, UART1_IRQn, {{19, SYS_GPB_MFP_PB4_UART1_RXD, NULL, NULL, NULL}, {20, SYS_GPB_MFP_PB5_UART1_TXD, NULL, NULL, NULL} }},
  {UART2, UART2_MODULE, UART02_IRQn, {{38, SYS_GPD_MFP_PD14_UART2_RXD, NULL, NULL, NULL}, {39, SYS_GPD_MFP_PD15_UART2_TXD, NULL, NULL, NULL}}},
};

const I2CPinDescription I2C_Desc[] = {
  {I2C1, I2C1_MODULE, {{9, SYS_GPA_MFP_PA11_I2C1_SCL, NULL, NULL, NULL}, {10, SYS_GPA_MFP_PA10_I2C1_SDA, NULL, NULL, NULL}}},
  {I2C0, I2C0_MODULE, {{11, SYS_GPA_MFP_PA9_I2C0_SCL, NULL, NULL, NULL}, {12, SYS_GPA_MFP_PA8_I2C0_SDA, NULL, NULL, NULL}}},
};


const CANPinDescription CAN_Desc[] = {
  {CAN0, CAN0_MODULE, CAN0_IRQn, {{36, SYS_GPD_MFP_PD6_CAN0_RXD, NULL, NULL, NULL}, {37, SYS_GPD_MFP_PD7_CAN0_TXD, NULL, NULL, NULL}}},
};
#elif defined(__NANO100__)
#ifdef USE_BoardToPin
const BoardToPin BoardToPinInfo[] = {{ 73, UART_TYPE, 0}, // 0: PC10(UART_RX0)
  { 72, UART_TYPE, 0}, // 1: PC11(UART_TX0)
  { 79, PWM_TYPE, 0}, // 2: PA12(PWM0)
  { 78, PWM_TYPE, 1}, // 3: PA13(PWM1)
  { 77, PWM_TYPE, 2}, // 4: PA14(PWM2)
  { 76, PWM_TYPE, 3}, // 5: PA15(PWM3)
  { 71, PWM_TYPE, 4}, // 6: PC12(PWM4)
  { 70, PWM_TYPE, 5}, // 7: PC13(PWM5)
  {109, PWM_TYPE, 6}, // 8: PC15(PWM6)
  {110, PWM_TYPE, 7}, // 9: PC14(PWM7)
  { 48, GPIO_TYPE, 0}, //10: PD6
  { 49, GPIO_TYPE, 0}, //11: PD7
  { 50, GPIO_TYPE, 0}, //12: PD14
  { 51, GPIO_TYPE, 0}, //13: PD15
  {  9, I2C_TYPE, 0}, //14: PA10(I2C1_SDA)
  { 10, I2C_TYPE, 0}, //15: PA11(I2C1_SCL)
  { 89, GPIO_TYPE, 0}, //16: PA0(ADC0)
  { 90, GPIO_TYPE, 0}, //17: PA1(ADC1)
  { 91, GPIO_TYPE, 0}, //18: PA2(ADC2)
  { 92, GPIO_TYPE, 0}, //19: PA3(ADC3)
  { 93, GPIO_TYPE, 0}, //20: PA4(ADC4)
  { 94, GPIO_TYPE, 0}, //21: PA5(ADC5)
  { 95, GPIO_TYPE, 0}, //22: PA6(ADC6)
  { 96, GPIO_TYPE, 0}, //23: PA7(ADC7)
  {100, GPIO_TYPE, 0}, //24: PD0(ADC8)
  {101, GPIO_TYPE, 0}, //25: PD1(ADC9)
  { 13, GPIO_TYPE, 0}, //26: PD8
  { 14, GPIO_TYPE, 0}, //27: PD9
  {108, GPIO_TYPE, 0}, //28: PC6
  {107, GPIO_TYPE, 0}, //29: PC7
  { 15, GPIO_TYPE, 0}, //30: PD10
  { 16, GPIO_TYPE, 0}, //31: PD11
  { 11, I2C_TYPE, 1}, //32: PA9(I2C0_SCL)
  { 12, I2C_TYPE, 1}, //33: PA8(I2C0_SDA)
  { 44, UART_TYPE, 1}, //34: PB0(UART_RX1)
  { 45, UART_TYPE, 1}, //35: PB1(UART_TX1)
  { 36, GPIO_TYPE, 0}, //36: PE9
  { 35, GPIO_TYPE, 0}, //37: PE10
  { 34, GPIO_TYPE, 0}, //38: PE11
  { 33, GPIO_TYPE, 0}, //39: PE12
  { 66, SPI_TYPE, 0}, //40: PE3(SPI0_MISO0)
  { 67, SPI_TYPE, 0}, //41: PE2(SPI0_SCLK)
  { 65, SPI_TYPE, 0}, //42: PE4(SPI0_MOSI0)
  { 68, SPI_TYPE, 0}, //43: PE1(SPI0_SS0)
  { 17, GPIO_TYPE, 0}, //44: PD12
  {127, GPIO_TYPE, 0}, //45: PE15
  {  4, GPIO_TYPE, 0}, //46: PB12(CKO)
  {122, GPIO_TYPE, 0}, //47: PF4
  { 69, GPIO_TYPE, 0}, //48: PE0(I2S_MCLK)
  {123, GPIO_TYPE, 0}, //49: PF5
  {102, GPIO_TYPE, 0}, //50: PD2(I2S_LRCK)
  { 75, GPIO_TYPE, 0}, //51: PC8
  {103, GPIO_TYPE, 0}, //52: PD3(I2S_BCLK)
  { 74, GPIO_TYPE, 0}, //53: PC9
  {105, GPIO_TYPE, 0}, //54: PD4(I2S_DI)
  { 53, GPIO_TYPE, 0}, //55: PC4
  {106, GPIO_TYPE, 0}, //56: PD5(I2S_DO)
  { 52, GPIO_TYPE, 0}, //57: PC5
  { 76, GPIO_TYPE, 0}, //58: PA15(TMR0_CAP)
  { 55, GPIO_TYPE, 0}, //59: PC2(SC0_POR)
  { 64, GPIO_TYPE, 0}, //60: PB9(TMR0_OUT)
  { 54, GPIO_TYPE, 0}, //61: PC3(SC0_RST)
  { 63, GPIO_TYPE, 0}, //62: PB10
  { 57, GPIO_TYPE, 0}, //63: PC0(SC0_CLK)
  { 62, GPIO_TYPE, 0}, //64: PB11
  { 56, GPIO_TYPE, 0}, //65: PC1(SC0_DAT)
  { 61, GPIO_TYPE, 0}, //66: PE5
  {111, GPIO_TYPE, 0}, //67: PB15(SC0_CS)
  { 19, GPIO_TYPE, 0}, //68: PB4
  { 47, GPIO_TYPE, 0}, //69: PB3(UART1_CTS)
  { 20, GPIO_TYPE, 0}, //70: PB5
  { 46, GPIO_TYPE, 0}, //71: PB2(UART1_RTS)
  { 21, GPIO_TYPE, 0}, //72: PB6
  { 38, GPIO_TYPE, 0}, //73: PE7
  { 22, GPIO_TYPE, 0}, //74: PB7
  { 37, GPIO_TYPE, 0}, //75: PE8
  { 58, GPIO_TYPE, 0}, //76: PE6
  {  2, GPIO_TYPE, 0}, //77: PB14(EINT0)
  { 18, GPIO_TYPE, 0}, //78: PD13
  {  1, GPIO_TYPE, 0}, //79: PE13
  {  3, GPIO_TYPE, 0}, //80: PB13
};
#endif

const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}}, //0
  {PE, BIT13 , {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE13_MFP_Msk, SYS_PE_H_MFP_PE13_MFP_GPE13}}, //1
  {PB, BIT14 , {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB14_MFP_Msk, SYS_PB_H_MFP_PB14_MFP_GPB14}}, //2
  {PB, BIT13 , {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB13_MFP_Msk, SYS_PB_H_MFP_PB13_MFP_GPB13}}, //3
  {PB, BIT12 , {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB12_MFP_Msk, SYS_PB_H_MFP_PB12_MFP_GPB12}}, //4
  {NULL, NULL, {NULL, NULL, NULL}}, //5
  {NULL, NULL, {NULL, NULL, NULL}}, //6
  {NULL, NULL, {NULL, NULL, NULL}}, //7
  {NULL, NULL, {NULL, NULL, NULL}}, //8
  {PA, BIT11, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA11_MFP_Msk, SYS_PA_H_MFP_PA11_MFP_GPA11}}, //9
  {PA, BIT10, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA10_MFP_Msk, SYS_PA_H_MFP_PA10_MFP_GPA10}}, //10
  {PA, BIT9 , {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA9_MFP_Msk, SYS_PA_H_MFP_PA9_MFP_GPA9}}, //11
  {PA, BIT8 , {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA8_MFP_Msk, SYS_PA_H_MFP_PA8_MFP_GPA8}}, //12
  {PD, BIT8 , {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD8_MFP_Msk, SYS_PD_H_MFP_PD8_MFP_GPD8}}, //13
  {PD, BIT9 , {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD9_MFP_Msk, SYS_PD_H_MFP_PD9_MFP_GPD9}}, //14
  {PD, BIT10, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD10_MFP_Msk, SYS_PD_H_MFP_PD10_MFP_GPD10}}, //15
  {PD, BIT11, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD11_MFP_Msk, SYS_PD_H_MFP_PD11_MFP_GPD11}}, //16
  {PD, BIT12, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD12_MFP_Msk, SYS_PD_H_MFP_PD12_MFP_GPD12}}, //17
  {PD, BIT13, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD13_MFP_Msk, SYS_PD_H_MFP_PD13_MFP_GPD13}}, //18
  {PB, BIT4 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB4_MFP_Msk, SYS_PB_L_MFP_PB4_MFP_GPB4}}, //19
  {PB, BIT5 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB5_MFP_Msk, SYS_PB_L_MFP_PB5_MFP_GPB5}}, //20
  {PB, BIT6 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB6_MFP_Msk, SYS_PB_L_MFP_PB6_MFP_GPB6}}, //21
  {PB, BIT7 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB7_MFP_Msk, SYS_PB_L_MFP_PB7_MFP_GPB7}}, //22
  {NULL, NULL, {NULL, NULL, NULL}}, //23
  {NULL, NULL, {NULL, NULL, NULL}}, //24
  {NULL, NULL, {NULL, NULL, NULL}}, //25
  {NULL, NULL, {NULL, NULL, NULL}}, //26
  {NULL, NULL, {NULL, NULL, NULL}}, //27
  {NULL, NULL, {NULL, NULL, NULL}}, //28
  {NULL, NULL, {NULL, NULL, NULL}}, //29
  {NULL, NULL, {NULL, NULL, NULL}}, //30
  {NULL, NULL, {NULL, NULL, NULL}}, //31
  {NULL, NULL, {NULL, NULL, NULL}}, //32
  {PE, BIT12, {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE12_MFP_Msk, SYS_PE_H_MFP_PE12_MFP_GPE12}}, //33
  {PE, BIT11, {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE11_MFP_Msk, SYS_PE_H_MFP_PE11_MFP_GPE11}}, //34
  {PE, BIT10, {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE10_MFP_Msk, SYS_PE_H_MFP_PE10_MFP_GPE10}}, //35
  {PE, BIT9 , {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE9_MFP_Msk, SYS_PE_H_MFP_PE9_MFP_GPE9}}, //36
  {PE, BIT8 , {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE8_MFP_Msk, SYS_PE_H_MFP_PE8_MFP_GPE8}}, //37
  {PE, BIT7 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE7_MFP_Msk, SYS_PE_L_MFP_PE7_MFP_GPE7}}, //38
  {NULL, NULL, {NULL, NULL, NULL}}, //39
  {NULL, NULL, {NULL, NULL, NULL}}, //40
  {NULL, NULL, {NULL, NULL, NULL}}, //41
  {NULL, NULL, {NULL, NULL, NULL}}, //42
  {NULL, NULL, {NULL, NULL, NULL}}, //43
  {PB, BIT0 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB0_MFP_Msk, SYS_PB_L_MFP_PB0_MFP_GPB0}}, //44
  {PB, BIT1 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB1_MFP_Msk, SYS_PB_L_MFP_PB1_MFP_GPB1}}, //45
  {PB, BIT2 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB2_MFP_Msk, SYS_PB_L_MFP_PB2_MFP_GPB2}}, //46
  {PB, BIT3 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB3_MFP_Msk, SYS_PB_L_MFP_PB3_MFP_GPB3}}, //47
  {PD, BIT6 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD6_MFP_Msk, SYS_PD_L_MFP_PD6_MFP_GPD6}}, //48
  {PD, BIT7 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD7_MFP_Msk, SYS_PD_L_MFP_PD7_MFP_GPD7}}, //49
  {PD, BIT14, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD14_MFP_Msk, SYS_PD_H_MFP_PD14_MFP_GPD14}}, //50
  {PD, BIT15, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD15_MFP_Msk, SYS_PD_H_MFP_PD15_MFP_GPD15}}, //51
  {PC, BIT5 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC5_MFP_Msk, SYS_PC_L_MFP_PC5_MFP_GPC5}}, //52
  {PC, BIT4 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC4_MFP_Msk, SYS_PC_L_MFP_PC4_MFP_GPC4}}, //53
  {PC, BIT3 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC3_MFP_Msk, SYS_PC_L_MFP_PC3_MFP_GPC3}}, //54
  {PC, BIT2 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC2_MFP_Msk, SYS_PC_L_MFP_PC2_MFP_GPC2}}, //55
  {PC, BIT1 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC1_MFP_Msk, SYS_PC_L_MFP_PC1_MFP_GPC1}}, //56
  {PC, BIT0 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC0_MFP_Msk, SYS_PC_L_MFP_PC0_MFP_GPC0}}, //57
  {PE, BIT6 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE6_MFP_Msk, SYS_PE_L_MFP_PE6_MFP_GPE6}}, //58
  {NULL, NULL, {NULL, NULL, NULL}}, //59
  {NULL, NULL, {NULL, NULL, NULL}}, //60
  {PE, BIT5 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE5_MFP_Msk, SYS_PE_L_MFP_PE5_MFP_GPE5}}, //61
  {PB, BIT11, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB11_MFP_Msk, SYS_PB_H_MFP_PB11_MFP_GPB11}}, //62
  {PB, BIT10, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB10_MFP_Msk, SYS_PB_H_MFP_PB10_MFP_GPB10}}, //63
  {PB, BIT9 , {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB9_MFP_Msk, SYS_PB_H_MFP_PB9_MFP_GPB9}}, //64
  {PE, BIT4 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE4_MFP_Msk, SYS_PE_L_MFP_PE4_MFP_GPE4}}, //65
  {PE, BIT3 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE3_MFP_Msk, SYS_PE_L_MFP_PE3_MFP_GPE3}}, //66
  {PE, BIT2 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE2_MFP_Msk, SYS_PE_L_MFP_PE2_MFP_GPE2}}, //67
  {PE, BIT1 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE1_MFP_Msk, SYS_PE_L_MFP_PE1_MFP_GPE1}}, //68
  {PE, BIT0 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE0_MFP_Msk, SYS_PE_L_MFP_PE0_MFP_GPE0}}, //69
  {PC, BIT13, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC13_MFP_Msk, SYS_PC_H_MFP_PC13_MFP_GPC13}}, //70
  {PC, BIT12, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC12_MFP_Msk, SYS_PC_H_MFP_PC12_MFP_GPC12}}, //71
  {PC, BIT11, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC11_MFP_Msk, SYS_PC_H_MFP_PC11_MFP_GPC11}}, //72
  {PC, BIT10, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC10_MFP_Msk, SYS_PC_H_MFP_PC10_MFP_GPC10}}, //73
  {PC, BIT9 , {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC9_MFP_Msk, SYS_PC_H_MFP_PC9_MFP_GPC9}}, //74
  {PC, BIT8 , {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC8_MFP_Msk, SYS_PC_H_MFP_PC8_MFP_GPC8}}, //75
  {PA, BIT15, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA15_MFP_Msk, SYS_PA_H_MFP_PA15_MFP_GPA15}}, //76
  {PA, BIT14, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA14_MFP_Msk, SYS_PA_H_MFP_PA14_MFP_GPA14}}, //77
  {PA, BIT13, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA13_MFP_Msk, SYS_PA_H_MFP_PA13_MFP_GPA13}}, //78
  {PA, BIT12, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA12_MFP_Msk, SYS_PA_H_MFP_PA12_MFP_GPA12}}, //79
  {PF, BIT0 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF0_MFP_Msk, SYS_PF_L_MFP_PF0_MFP_GPF0}}, //80
  {PF, BIT1 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF1_MFP_Msk, SYS_PF_L_MFP_PF1_MFP_GPF1}}, //81
  {NULL, NULL, {NULL, NULL, NULL}}, //82
  {NULL, NULL, {NULL, NULL, NULL}}, //83
  {NULL, NULL, {NULL, NULL, NULL}}, //84
  {NULL, NULL, {NULL, NULL, NULL}}, //85
  {NULL, NULL, {NULL, NULL, NULL}}, //86
  {NULL, NULL, {NULL, NULL, NULL}}, //87
  {NULL, NULL, {NULL, NULL, NULL}}, //88
  {PA, BIT0 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA0_MFP_Msk, SYS_PA_L_MFP_PA0_MFP_GPA0}}, //89
  {PA, BIT1 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA1_MFP_Msk, SYS_PA_L_MFP_PA1_MFP_GPA1}}, //90
  {PA, BIT2 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA2_MFP_Msk, SYS_PA_L_MFP_PA2_MFP_GPA2}}, //91
  {PA, BIT3 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA3_MFP_Msk, SYS_PA_L_MFP_PA3_MFP_GPA3}}, //92
  {PA, BIT4 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA4_MFP_Msk, SYS_PA_L_MFP_PA4_MFP_GPA4}}, //93
  {PA, BIT5 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA5_MFP_Msk, SYS_PA_L_MFP_PA5_MFP_GPA5}}, //94
  {PA, BIT6 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA6_MFP_Msk, SYS_PA_L_MFP_PA6_MFP_GPA6}}, //95
  {PA, BIT7 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA7_MFP_Msk, SYS_PA_L_MFP_PA7_MFP_GPA7}}, //96
  {NULL, NULL, {NULL, NULL, NULL}}, //97
  {NULL, NULL, {NULL, NULL, NULL}}, //98
  {NULL, NULL, {NULL, NULL, NULL}}, //99
  {PD, BIT0 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD0_MFP_Msk, SYS_PD_L_MFP_PD0_MFP_GPD0}}, //100
  {PD, BIT1 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD1_MFP_Msk, SYS_PD_L_MFP_PD1_MFP_GPD1}}, //101
  {PD, BIT2 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD2_MFP_Msk, SYS_PD_L_MFP_PD2_MFP_GPD2}}, //102
  {PD, BIT3 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD3_MFP_Msk, SYS_PD_L_MFP_PD3_MFP_GPD3}}, //103
  {NULL, NULL, {NULL, NULL, NULL}}, //104
  {PD, BIT4 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD4_MFP_Msk, SYS_PD_L_MFP_PD4_MFP_GPD4}}, //105
  {PD, BIT5 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD5_MFP_Msk, SYS_PD_L_MFP_PD5_MFP_GPD5}}, //106
  {PC, BIT7 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC7_MFP_Msk, SYS_PC_L_MFP_PC7_MFP_GPC7}}, //107
  {PC, BIT6 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC6_MFP_Msk, SYS_PC_L_MFP_PC6_MFP_GPC6}}, //108
  {PC, BIT15, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC15_MFP_Msk, SYS_PC_H_MFP_PC15_MFP_GPC15}}, //109
  {PC, BIT14, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC14_MFP_Msk, SYS_PC_H_MFP_PC14_MFP_GPC14}}, //110
  {PB, BIT15, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB15_MFP_Msk, SYS_PB_H_MFP_PB15_MFP_GPB15}}, //111
  {NULL, NULL, {NULL, NULL, NULL}}, //112
  {NULL, NULL, {NULL, NULL, NULL}}, //113
  {NULL, NULL, {NULL, NULL, NULL}}, //114
  {NULL, NULL, {NULL, NULL, NULL}}, //115
  {NULL, NULL, {NULL, NULL, NULL}}, //116
  {NULL, NULL, {NULL, NULL, NULL}}, //117
  {NULL, NULL, {NULL, NULL, NULL}}, //118
  {NULL, NULL, {NULL, NULL, NULL}}, //119
  {NULL, NULL, {NULL, NULL, NULL}}, //120
  {NULL, NULL, {NULL, NULL, NULL}}, //121
  {PF, BIT4 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF4_MFP_Msk, SYS_PF_L_MFP_PF4_MFP_GPF4}}, //122
  {PF, BIT5 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF5_MFP_Msk, SYS_PF_L_MFP_PF5_MFP_GPF5}}, //123
  {NULL, NULL, {NULL, NULL, NULL}}, //124
  {NULL, NULL, {NULL, NULL, NULL}}, //125
  {PB, BIT8 , {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB8_MFP_Msk, SYS_PB_H_MFP_PB8_MFP_GPB8}}, //126
  {PE, BIT15, {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE15_MFP_Msk, SYS_PE_H_MFP_PE15_MFP_GPE15}}, //127
  {PE, BIT14, {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE14_MFP_Msk, SYS_PE_H_MFP_PE14_MFP_GPE14}}, //128
};

const PWMPinDescription PWM_Desc[] = {
  {PWM0, PWM0_CH01_MODULE, PWM0_IRQn, 0, 500, { 79, SYS_PA_H_MFP_PA12_MFP_PWM0_CH0}}, //0
  {PWM0, PWM0_CH01_MODULE, PWM0_IRQn, 1, 500, { 78, SYS_PA_H_MFP_PA13_MFP_PWM0_CH1}}, //1
  {PWM0, PWM0_CH23_MODULE, PWM0_IRQn, 2, 500, { 77, SYS_PA_H_MFP_PA14_MFP_PWM0_CH2}}, //2
  {PWM0, PWM0_CH23_MODULE, PWM0_IRQn, 3, 500, { 76, SYS_PA_H_MFP_PA15_MFP_PWM0_CH3}}, //3
  {PWM1, PWM1_CH01_MODULE, PWM1_IRQn, 0, 500, { 71, SYS_PC_H_MFP_PC12_MFP_PWM1_CH0}}, //4
  {PWM1, PWM1_CH01_MODULE, PWM1_IRQn, 1, 500, { 70, SYS_PC_H_MFP_PC13_MFP_PWM1_CH1}}, //5
  {PWM1, PWM1_CH23_MODULE, PWM1_IRQn, 2, 500, {109, SYS_PC_H_MFP_PC15_MFP_PWM1_CH2}}, //6
  {PWM1, PWM1_CH23_MODULE, PWM1_IRQn, 3, 500, {110, SYS_PC_H_MFP_PC14_MFP_PWM1_CH3}}, //7
};

const ADCPinDescription ADC_Desc[] = {
  {ADC, ADC_MODULE, 0, { 89, SYS_PA_L_MFP_PA0_MFP_ADC_CH0}}, //0
  {ADC, ADC_MODULE, 1, { 90, SYS_PA_L_MFP_PA1_MFP_ADC_CH1}}, //1
  {ADC, ADC_MODULE, 2, { 91, SYS_PA_L_MFP_PA2_MFP_ADC_CH2}}, //2
  {ADC, ADC_MODULE, 3, { 92, SYS_PA_L_MFP_PA3_MFP_ADC_CH3}}, //3
  {ADC, ADC_MODULE, 4, { 93, SYS_PA_L_MFP_PA4_MFP_ADC_CH4}}, //4
  {ADC, ADC_MODULE, 5, { 94, SYS_PA_L_MFP_PA5_MFP_ADC_CH5}}, //5
  {ADC, ADC_MODULE, 6, { 95, SYS_PA_L_MFP_PA6_MFP_ADC_CH6}}, //6
  {ADC, ADC_MODULE, 7, { 96, SYS_PA_L_MFP_PA7_MFP_ADC_CH7}}, //7
  {ADC, ADC_MODULE, 8, {100, SYS_PD_L_MFP_PD0_MFP_ADC_CH8}}, //8
  {ADC, ADC_MODULE, 9, {101, SYS_PD_L_MFP_PD1_MFP_ADC_CH9}}, //9
};


const SPIPinDescription SPI_Desc[] = {
  { SPI0, SPI0_MODULE, SPI0_IRQn, CLK_CLKSEL2_SPI0_S_HCLK,
    { {67, SYS_PE_L_MFP_PE2_MFP_SPI0_SCLK  }, {65, SYS_PE_L_MFP_PE4_MFP_SPI0_MOSI0 },
      {66, SYS_PE_L_MFP_PE3_MFP_SPI0_MISO0 }, {68, SYS_PE_L_MFP_PE1_MFP_SPI0_SS0}
    }
  },

  { SPI1, SPI1_MODULE, SPI1_IRQn, CLK_CLKSEL2_SPI1_S_HCLK,
    { {46, SYS_PB_L_MFP_PB2_MFP_SPI1_SCLK  }, {44, SYS_PB_L_MFP_PB0_MFP_SPI1_MOSI0 },
      {45, SYS_PB_L_MFP_PB1_MFP_SPI1_MISO0 }, {47, SYS_PB_L_MFP_PB3_MFP_SPI1_SS0}
    }
  },

  { SPI2, SPI2_MODULE, SPI2_IRQn, CLK_CLKSEL2_SPI2_S_HCLK,
    { {20, SYS_PB_L_MFP_PB5_MFP_SPI2_SCLK  }, {22, SYS_PB_L_MFP_PB7_MFP_SPI2_MOSI0 },
      {21, SYS_PB_L_MFP_PB6_MFP_SPI2_MISO0 }, {19, SYS_PB_L_MFP_PB4_MFP_SPI2_SS0}
    }
  },
};

const UARTPinDescription UART_Desc[] = {
  {UART1, UART1_MODULE, UART1_IRQn, {{73, SYS_PC_H_MFP_PC10_MFP_UART1_RX}, {72, SYS_PC_H_MFP_PC11_MFP_UART1_TX}}}, /* UART_RX0,UART_TX0 */
  {UART0, UART0_MODULE, UART0_IRQn, {{44, SYS_PB_L_MFP_PB0_MFP_UART0_RX }, {45, SYS_PB_L_MFP_PB1_MFP_UART0_TX}}}, /* UART_RX1,UART_TX1 */
};

const I2CPinDescription I2C_Desc[] = {
  {I2C1, I2C1_MODULE, {{  9, SYS_PA_H_MFP_PA11_MFP_I2C1_SCL}, { 10, SYS_PA_H_MFP_PA10_MFP_I2C1_SDA}}}, /* I2C0_SDA,I2C0_SCL */
  {I2C0, I2C0_MODULE, {{ 11, SYS_PA_H_MFP_PA9_MFP_I2C0_SCL }, { 12, SYS_PA_H_MFP_PA8_MFP_I2C0_SDA }}}, /* I2C1_SDA,I2C1_SCL */
};

#elif defined(__NUC131__)
#ifdef USE_BoardToPin
const BoardToPin BoardToPinInfo[] = {{ 17, UART_TYPE, 0}, // 0: PB0(UART_RX0)   /* 64Pins */
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
  {PB, BIT12, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB12_Msk, NULL,                 NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB12_GPIO}}, //1
  {PF, BIT5 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF5_Msk, NULL,                  NULL,   SYS_ALT_MFP3_PF5_Msk,                   NULL,                 SYS_GPF_MFP_PF5_GPIO}}, //2
  {PF, BIT4 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF4_Msk, NULL,                  NULL,   SYS_ALT_MFP3_PF4_Msk,                   NULL,                 SYS_GPF_MFP_PF4_GPIO}}, //3
  {PA, BIT11, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA11_Msk, NULL,                  NULL,  SYS_ALT_MFP3_PA11_Msk,                   NULL,                 SYS_GPA_MFP_PA11_GPIO}}, //4
  {PA, BIT10, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA10_Msk, NULL,                  NULL,  SYS_ALT_MFP3_PA10_Msk,                   NULL,                 SYS_GPA_MFP_PA10_GPIO}}, //5
  {PA, BIT9 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA9_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA9_GPIO}}, //6
  {PA, BIT8 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA8_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA8_GPIO}}, //7
  {PB, BIT4, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB4_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB4_GPIO}}, //8
  {PB, BIT5, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB5_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB5_GPIO}}, //9
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //10
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //11
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //12
  {PB, BIT0, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB0_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB0_GPIO}}, //13
  {PB, BIT1, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB1_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB1_GPIO}}, //14
  {PB, BIT2, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB2_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB2_GPIO}}, //15
  {PB, BIT3, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB3_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB3_GPIO}}, //16
  {PD, BIT6, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD6_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD6_GPIO}}, //17
  {PD, BIT7, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD7_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD7_GPIO}}, //18
  {PD, BIT14, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD14_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD14_GPIO}}, //19
  {PD, BIT15, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD15_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD15_GPIO}}, //20
  {PC, BIT3, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC3_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC3_GPIO}}, //21
  {PC, BIT2, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC2_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC2_GPIO}}, //22
  {PC, BIT1, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC1_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC1_GPIO}}, //23
  {PC, BIT0, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC0_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC0_GPIO}}, //24
  {PA, BIT15, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA15_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA15_GPIO}}, //25
  {PA, BIT14, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA14_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA14_GPIO}}, //26
  {PA, BIT13, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA13_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA13_GPIO}}, //27
  {PA, BIT12, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA12_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA12_GPIO}}, //28
  {PF, BIT7 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF7_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF7_GPIO}}, //29
  {PF, BIT6 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF6_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF6_GPIO}}, //30
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //31
  {PA, BIT0 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA0_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA0_GPIO}}, //32
  {PA, BIT1 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA1_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA1_GPIO}}, //33
  {PA, BIT2 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA2_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA2_GPIO}}, //34
  {PA, BIT3 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA3_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA3_GPIO}}, //35
  {PA, BIT4 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA4_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA4_GPIO}}, //36
  {PA, BIT5 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA5_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA5_GPIO}}, //37
  {PA, BIT6 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA6_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA6_GPIO}}, //38
  {PA, BIT7 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA7_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA7_GPIO}}, //39
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //40
  {PC, BIT7, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC7_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC7_GPIO}}, //41
  {PC, BIT6, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC6_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC6_GPIO}}, //42
  {PB, BIT15, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB15_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB15_GPIO}}, //43
  {PF, BIT0 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF0_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF0_GPIO}}, //44
  {PF, BIT1 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF1_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF1_GPIO}}, //45
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //46
  {PF, BIT8 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF8_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF8_GPIO}}, //47
  {PB, BIT8 , {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB8_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB8_GPIO}}, //48
#else  /* 64pins */
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //0
  {PB, BIT14, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB14_Msk, NULL,                 NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB14_GPIO}}, //1
  {PB, BIT13, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB13_Msk, NULL,                 NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB13_GPIO}}, //2
  {PB, BIT12, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB12_Msk, NULL,                 NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB12_GPIO}}, //3
  {PF, BIT5 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF5_Msk, NULL,                  NULL,   SYS_ALT_MFP3_PF5_Msk,                   NULL,                 SYS_GPF_MFP_PF5_GPIO}}, //4
  {PF, BIT4 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF4_Msk, NULL,                  NULL,   SYS_ALT_MFP3_PF4_Msk,                   NULL,                 SYS_GPF_MFP_PF4_GPIO}}, //5
  {PA, BIT11, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA11_Msk, NULL,                  NULL,  SYS_ALT_MFP3_PA11_Msk,                   NULL,                 SYS_GPA_MFP_PA11_GPIO}}, //6
  {PA, BIT10, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA10_Msk, NULL,                  NULL,  SYS_ALT_MFP3_PA10_Msk,                   NULL,                 SYS_GPA_MFP_PA10_GPIO}}, //7
  {PA, BIT9 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA9_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA9_GPIO}}, //8
  {PA, BIT8 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA8_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA8_GPIO}}, //9
  {PB, BIT4, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB4_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB4_GPIO}}, //10
  {PB, BIT5, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB5_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB5_GPIO}}, //11
  {PB, BIT6, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB6_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB6_GPIO}}, //12
  {PB, BIT7, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB7_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB7_GPIO}}, //13
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //14
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //15
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //16
  {PB, BIT0, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB0_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB0_GPIO}}, //17
  {PB, BIT1, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB1_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB1_GPIO}}, //18
  {PB, BIT2, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB2_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB2_GPIO}}, //19
  {PB, BIT3, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB3_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB3_GPIO}}, //20
  {PD, BIT6, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD6_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD6_GPIO}}, //21
  {PD, BIT7, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD7_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD7_GPIO}}, //22
  {PD, BIT14, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD14_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD14_GPIO}}, //23
  {PD, BIT15, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD15_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPD_MFP_PD15_GPIO}}, //24
  {PC, BIT3, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC3_Msk, NULL,                   NULL,   SYS_ALT_MFP3_PC3_Msk,                   NULL,                 SYS_GPC_MFP_PC3_GPIO}}, //25
  {PC, BIT2, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC2_Msk, NULL,                   NULL,   SYS_ALT_MFP3_PC2_Msk,                   NULL,                 SYS_GPC_MFP_PC2_GPIO}}, //26
  {PC, BIT1, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC1_Msk, NULL,                   NULL,   SYS_ALT_MFP3_PC1_Msk,                   NULL,                 SYS_GPC_MFP_PC1_GPIO}}, //27
  {PC, BIT0, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC0_Msk, NULL,                   NULL,   SYS_ALT_MFP3_PC0_Msk,                   NULL,                 SYS_GPC_MFP_PC0_GPIO}}, //28
  {PE, BIT5, {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE5_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPE_MFP_PE5_GPIO}}, //29
  {PB, BIT11, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB11_Msk, NULL,                  NULL,  SYS_ALT_MFP3_PB11_Msk,                   NULL,                 SYS_GPB_MFP_PB11_GPIO}}, //30
  {PB, BIT10, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB10_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB10_GPIO}}, //31
  {PB, BIT9, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB9_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB9_GPIO}}, //32
  {PC, BIT11, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC11_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC11_GPIO}}, //33
  {PC, BIT10, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC10_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC10_GPIO}}, //34
  {PC, BIT9, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC9_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC9_GPIO}}, //35
  {PC, BIT8, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC8_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC8_GPIO}}, //36
  {PA, BIT15, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA15_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA15_GPIO}}, //37
  {PA, BIT14, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA14_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA14_GPIO}}, //38
  {PA, BIT13, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA13_Msk, NULL,                  NULL,                   NULL,  SYS_ALT_MFP4_PA13_Msk,                 SYS_GPA_MFP_PA13_GPIO}}, //39
  {PA, BIT12, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA12_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA12_GPIO}}, //40
  {PF, BIT7 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF7_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF7_GPIO}}, //41
  {PF, BIT6 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF6_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF6_GPIO}}, //42
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //43
  {PA, BIT0 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA0_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA0_GPIO}}, //44
  {PA, BIT1 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA1_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA1_GPIO}}, //45
  {PA, BIT2 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA2_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA2_GPIO}}, //46
  {PA, BIT3 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA3_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA3_GPIO}}, //47
  {PA, BIT4 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA4_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA4_GPIO}}, //48
  {PA, BIT5 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA5_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA5_GPIO}}, //49
  {PA, BIT6 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA6_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA6_GPIO}}, //50
  {PA, BIT7 , {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA7_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPA_MFP_PA7_GPIO}}, //51
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //52
  {PC, BIT7, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC7_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC7_GPIO}}, //53
  {PC, BIT6, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC6_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC6_GPIO}}, //54
#if 0
  {PC, BIT15, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC15_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC15_GPIO}}, //55
  {PC, BIT14, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC14_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPC_MFP_PC14_GPIO}}, //56
#else
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //55
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //56
#endif
  {PB, BIT15, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB15_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB15_GPIO}}, //57
  {PF, BIT0 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF0_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF0_GPIO}}, //58
  {PF, BIT1 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF1_Msk, NULL,                   NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF1_GPIO}}, //59
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //60
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //61
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL}}, //62
  {PF, BIT8 , {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF8_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPF_MFP_PF8_GPIO}}, //63
  {PB, BIT8 , {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB8_Msk, NULL,                  NULL,                   NULL,                   NULL,                 SYS_GPB_MFP_PB8_GPIO}}, //64
#endif
};

const PWMPinDescription PWM_Desc[] = {
  {PWM1, PWM1_MODULE, PWM1_IRQn, 4, 500, { 5, SYS_GPF_MFP_PF4_PWM1_CH4,                       NULL,                        NULL, SYS_ALT_MFP3_PF4_PWM1_CH4,                      NULL}}, //0
  {PWM1, PWM1_MODULE, PWM1_IRQn, 5, 500, { 4, SYS_GPF_MFP_PF5_PWM1_CH5,                       NULL,                        NULL, SYS_ALT_MFP3_PF5_PWM1_CH5,                      NULL}}, //1
  {PWM1, PWM1_MODULE, PWM1_IRQn, 2, 500, { 7, SYS_GPA_MFP_PA10_PWM1_CH2,                      NULL,                        NULL, SYS_ALT_MFP3_PA10_PWM1_CH2,                      NULL}}, //2
  {PWM1, PWM1_MODULE, PWM1_IRQn, 3, 500, { 6, SYS_GPA_MFP_PA11_PWM1_CH3,                      NULL,                        NULL, SYS_ALT_MFP3_PA11_PWM1_CH3,                      NULL}}, //3
  {PWM0, PWM0_MODULE, PWM0_IRQn, 3, 500, {37, SYS_GPA_MFP_PA15_PWM0_CH3,                      NULL,                        NULL,                      NULL,                      NULL}}, //4
  {PWM0, PWM0_MODULE, PWM0_IRQn, 5, 500, {29, SYS_GPE_MFP_PE5_PWM0_CH5,                       NULL,                        NULL,                      NULL,                      NULL}}, //5
  {PWM0, PWM0_MODULE, PWM0_IRQn, 4, 500, {30, SYS_GPB_MFP_PB11_PWM0_CH4,                      NULL,                        NULL, SYS_ALT_MFP3_PB11_PWM0_CH4,                      NULL}}, //6
  {PWM0, PWM0_MODULE, PWM0_IRQn, 2, 500, {38, SYS_GPA_MFP_PA14_PWM0_CH2,                      NULL,                        NULL,                      NULL,                      NULL}}, //7
  {PWM0, PWM0_MODULE, PWM0_IRQn, 1, 500, {39, SYS_GPA_MFP_PA13_PWM0_CH1,                      NULL,                        NULL,                      NULL,                      NULL}}, //8
  {PWM0, PWM0_MODULE, PWM0_IRQn, 0, 500, {40, SYS_GPA_MFP_PA12_PWM0_CH0,                      NULL,                        NULL,                      NULL,                      NULL}}, //9
};


const ADCPinDescription ADC_Desc[] = {
  {ADC, ADC_MODULE, 0, {44, SYS_GPA_MFP_PA0_ADC0, NULL, NULL, NULL, NULL}}, //0
  {ADC, ADC_MODULE, 1, {45, SYS_GPA_MFP_PA1_ADC1, NULL, NULL, NULL, NULL}}, //1
  {ADC, ADC_MODULE, 2, {46, SYS_GPA_MFP_PA2_ADC2, NULL, NULL, NULL, NULL}}, //2
  {ADC, ADC_MODULE, 3, {47, SYS_GPA_MFP_PA3_ADC3, NULL, NULL, NULL, NULL}}, //3
  {ADC, ADC_MODULE, 4, {48, SYS_GPA_MFP_PA4_ADC4, NULL, NULL, NULL, NULL}}, //4
  {ADC, ADC_MODULE, 5, {49, SYS_GPA_MFP_PA5_ADC5, NULL, NULL, NULL, NULL}}, //5
};

const SPIPinDescription SPI_Desc[] = {

  {
    SPI0, SPI0_MODULE, SPI0_IRQn, CLK_CLKSEL1_SPI0_S_HCLK,
    {
      {27, SYS_GPC_MFP_PC1_SPI0_CLK  , NULL, NULL, NULL, NULL},
      {26, SYS_GPC_MFP_PC2_SPI0_MISO0, NULL, NULL, NULL, NULL},
      {25, SYS_GPC_MFP_PC3_SPI0_MOSI0, NULL, NULL, NULL, NULL},
      {28, SYS_GPC_MFP_PC0_SPI0_SS0  , NULL, NULL, NULL, NULL},
    }
  },
};

const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART02_IRQn, {{17, SYS_GPB_MFP_PB0_UART0_RXD, NULL, NULL, NULL, NULL}, {18, SYS_GPB_MFP_PB1_UART0_TXD, NULL, NULL, NULL, NULL} }},
};

const I2CPinDescription I2C_Desc[] = {
  {I2C0, I2C0_MODULE, {{9, SYS_GPA_MFP_PA8_I2C0_SDA, NULL, NULL, NULL, NULL}, {8, SYS_GPA_MFP_PA9_I2C0_SCL, NULL, NULL, NULL, NULL}}},
};

//#if defined(__M451__) | defined(__NUC240__)
//CANPinDescription CAN_Desc[]={
//{CAN0,CAN0_MODULE,CAN0_IRQn,{{36,SYS_GPD_MFP_PD6_CAN0_RXD,NULL,NULL},{37,SYS_GPD_MFP_PD7_CAN0_TXD,NULL,NULL,NULL,NULL}}},
//};
//#endif
#elif defined(__NANO1X2__)
#if defined(__IOT_EVB__)
#ifdef USE_BoardToPin
BoardToPin BoardToPinInfo[] = {{ 5, GPIO_TYPE, 0}, // 0: PC4
  { 8, UART_TYPE, 1}, // 1: PC8(UART1_TX)
  { 7, UART_TYPE, 1}, // 2: PC7(UART1_RX)
  { 6, GPIO_TYPE, 0}, // 3: PC6
  {30, UART_TYPE, 0}, // 4: PA12(UART0_TX)
  {31, UART_TYPE, 0}, // 5: PA13(UART0_RX)
  { 3, GPIO_TYPE, 0}, // 6: PB14
  { 2, GPIO_TYPE, 0}, // 7: PB13
  { 1, GPIO_TYPE, 0}, // 8: PB12
  {13, PWM_TYPE, 0}, // 9: PD9(PWM0)
  {16, GPIO_TYPE, 0}, //10: PD12
  {15, GPIO_TYPE, 0}, //11: PD11
  {10, I2C_TYPE, 0}, //12: PC11(I2C_SDA0)
  { 9, I2C_TYPE, 0}, //13: PC10(I2C_SCL0)
  {32, GPIO_TYPE, 0}, //14: PA14
  { 4, GPIO_TYPE, 0}, //15: PB15
  {14, GPIO_TYPE, 0}, //16: PD10
  {11, GPIO_TYPE, 0}, //17: PC12
  {12, GPIO_TYPE, 0}, //18: PC13
  //-------------------------------
  //{25,ADC_TYPE,0},  //19: PA4(ADC4)
  //{26,ADC_TYPE,1},  //20: PA5(ADC5)
  //-------------------------------
} ;
#endif
const PWMPinDescription PWM_Desc[] = {
  {PWM0, PWM0_CH23_MODULE, PWM0_IRQn, 3, 500, { 13, SYS_PD_H_MFP_PD9_MFP_PWM0_CH3}}, //0
};

const ADCPinDescription ADC_Desc[] = {
  {ADC, ADC_MODULE, 4, { 25, SYS_PA_L_MFP_PA4_MFP_ADC_CH4}}, //0
  {ADC, ADC_MODULE, 5, { 26, SYS_PA_L_MFP_PA5_MFP_ADC_CH5}}, //1
};

const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART0_IRQn, {{31, SYS_PA_H_MFP_PA13_MFP_UART0_RX }, {30, SYS_PA_H_MFP_PA12_MFP_UART0_TX}}}, /* UART_RX0,UART_TX0 */
  {UART1, UART1_MODULE, UART1_IRQn, {{ 7, SYS_PC_L_MFP_PC7_MFP_UART1_RX  }, { 8, SYS_PC_H_MFP_PC8_MFP_UART1_TX}}}, /* UART_RX1,UART_TX1 */
};

const I2CPinDescription I2C_Desc[] = {
  {I2C1, I2C1_MODULE, {{  9, SYS_PC_H_MFP_PC10_MFP_I2C1_SCL}, { 10, SYS_PC_H_MFP_PC11_MFP_I2C1_SDA}}}, /* I2C1_SDA,I2C1_SCL */
};
#endif

#if defined(__NANO112__)
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}}, //0
  {PB, BIT7, {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB7_MFP_Msk , SYS_PB_L_MFP_PB7_MFP_GPB7}  }, //1
  {PB, BIT8, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB8_MFP_Msk , SYS_PB_H_MFP_PB8_MFP_GPB8}  }, //2
  {PB, BIT9, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB9_MFP_Msk , SYS_PB_H_MFP_PB9_MFP_GPB9}  }, //3
  {PE, BIT8, {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE8_MFP_Msk , SYS_PE_H_MFP_PE8_MFP_GPE8}  }, //4
  {PE, BIT9, {(uint32_t)&SYS->PE_H_MFP, SYS_PE_H_MFP_PE9_MFP_Msk , SYS_PE_H_MFP_PE9_MFP_GPE9}  }, //5
  {PB, BIT10, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB10_MFP_Msk, SYS_PB_H_MFP_PB10_MFP_GPB10}}, //6
  {PB, BIT11, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB11_MFP_Msk, SYS_PB_H_MFP_PB11_MFP_GPB11}}, //7
  {PB, BIT12, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB12_MFP_Msk, SYS_PB_H_MFP_PB12_MFP_GPB12}}, //8
  {PB, BIT13, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB13_MFP_Msk, SYS_PB_H_MFP_PB13_MFP_GPB13}}, //9
  {PB, BIT14, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB14_MFP_Msk, SYS_PB_H_MFP_PB14_MFP_GPB14}}, //10
  {NULL, NULL, {NULL, NULL, NULL}}, //11
  {PB, BIT15, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB15_MFP_Msk, SYS_PB_H_MFP_PB15_MFP_GPB15}}, //12
  {PC, BIT0 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC0_MFP_Msk , SYS_PC_L_MFP_PC0_MFP_GPC0}  }, //13
  {PC, BIT1 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC1_MFP_Msk , SYS_PC_L_MFP_PC1_MFP_GPC1}  }, //14
  {PC, BIT2 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC2_MFP_Msk , SYS_PC_L_MFP_PC2_MFP_GPC2}  }, //15
  {PC, BIT3 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC3_MFP_Msk , SYS_PC_L_MFP_PC3_MFP_GPC3}  }, //16
  {PC, BIT4 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC4_MFP_Msk , SYS_PC_L_MFP_PC4_MFP_GPC4}  }, //17
  {PC, BIT5 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC5_MFP_Msk , SYS_PC_L_MFP_PC5_MFP_GPC5}  }, //18
  {PC, BIT6 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC6_MFP_Msk , SYS_PC_L_MFP_PC6_MFP_GPC6}  }, //19
  {PC, BIT7 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC7_MFP_Msk , SYS_PC_L_MFP_PC7_MFP_GPC7}  }, //20
  {PC, BIT8 , {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC8_MFP_Msk , SYS_PC_H_MFP_PC8_MFP_GPC8}  }, //21
  {PC, BIT9 , {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC9_MFP_Msk , SYS_PC_H_MFP_PC9_MFP_GPC9}  }, //22
  {NULL, NULL, {NULL, NULL, NULL}}, //23
  {NULL, NULL, {NULL, NULL, NULL}}, //24
  {NULL, NULL, {NULL, NULL, NULL}}, //25
  {PC, BIT10, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC10_MFP_Msk, SYS_PC_H_MFP_PC10_MFP_GPC10}}, //26
  {PC, BIT11, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC11_MFP_Msk, SYS_PC_H_MFP_PC11_MFP_GPC11}}, //27
  {PC, BIT12, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC12_MFP_Msk, SYS_PC_H_MFP_PC12_MFP_GPC12}}, //28
  {PC, BIT13, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC13_MFP_Msk, SYS_PC_H_MFP_PC13_MFP_GPC13}}, //29
  {PC, BIT14, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC14_MFP_Msk, SYS_PC_H_MFP_PC14_MFP_GPC14}}, //30
  {PC, BIT15, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC15_MFP_Msk, SYS_PC_H_MFP_PC15_MFP_GPC15}}, //31
  {PD, BIT0 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD0_MFP_Msk , SYS_PD_L_MFP_PD0_MFP_GPD0}  }, //32
  {PD, BIT1 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD1_MFP_Msk , SYS_PD_L_MFP_PD1_MFP_GPD1}  }, //33
  {PD, BIT2 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD2_MFP_Msk , SYS_PD_L_MFP_PD2_MFP_GPD2}  }, //34
  {PD, BIT3 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD3_MFP_Msk , SYS_PD_L_MFP_PD3_MFP_GPD3}  }, //35
  {PD, BIT4 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD4_MFP_Msk , SYS_PD_L_MFP_PD4_MFP_GPD4}  }, //36
  {PD, BIT5 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD5_MFP_Msk , SYS_PD_L_MFP_PD5_MFP_GPD5}  }, //37
  {PD, BIT6 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD6_MFP_Msk , SYS_PD_L_MFP_PD6_MFP_GPD6}  }, //38
  {PD, BIT7 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD7_MFP_Msk , SYS_PD_L_MFP_PD7_MFP_GPD7}  }, //39
  {PD, BIT8 , {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD8_MFP_Msk , SYS_PD_H_MFP_PD8_MFP_GPD8}  }, //40
  {PD, BIT9 , {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD9_MFP_Msk , SYS_PD_H_MFP_PD9_MFP_GPD9}  }, //41
  {PD, BIT10, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD10_MFP_Msk, SYS_PD_H_MFP_PD10_MFP_GPD10}}, //42
  {PD, BIT11, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD11_MFP_Msk, SYS_PD_H_MFP_PD11_MFP_GPD11}}, //43
  {PD, BIT12, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD12_MFP_Msk, SYS_PD_H_MFP_PD12_MFP_GPD12}}, //44
  {NULL, NULL, {NULL, NULL, NULL}}, //45
  {NULL, NULL, {NULL, NULL, NULL}}, //46
  {NULL, NULL, {NULL, NULL, NULL}}, //47
  {PD, BIT13, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD13_MFP_Msk, SYS_PD_H_MFP_PD13_MFP_GPD13}}, //48
  {PD, BIT14, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD14_MFP_Msk, SYS_PD_H_MFP_PD14_MFP_GPD14}}, //49
  {PD, BIT15, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD15_MFP_Msk, SYS_PD_H_MFP_PD15_MFP_GPD15}}, //50
  {NULL, NULL, {NULL, NULL, NULL}}, //51
  {NULL, NULL, {NULL, NULL, NULL}}, //52
  {NULL, NULL, {NULL, NULL, NULL}}, //53
  {PF, BIT0 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF0_MFP_Msk,  SYS_PF_L_MFP_PF0_MFP_GPF0} }, //54
  {PF, BIT1 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF1_MFP_Msk,  SYS_PF_L_MFP_PF1_MFP_GPF1} }, //55
  {NULL, NULL, {NULL, NULL, NULL}}, //56
  {NULL, NULL, {NULL, NULL, NULL}}, //57
  {NULL, NULL, {NULL, NULL, NULL}}, //58
  {PF, BIT2 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF2_MFP_Msk,  SYS_PF_L_MFP_PF2_MFP_GPF2} }, //59
  {PF, BIT3 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF3_MFP_Msk,  SYS_PF_L_MFP_PF3_MFP_GPF3} }, //60
  {NULL, NULL, {NULL, NULL, NULL}}, //61
  {PE, BIT0 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE0_MFP_Msk,  SYS_PE_L_MFP_PE0_MFP_GPE0} }, //62
  {PE, BIT1 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE1_MFP_Msk,  SYS_PE_L_MFP_PE1_MFP_GPE1} }, //63
  {PE, BIT2 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE2_MFP_Msk,  SYS_PE_L_MFP_PE2_MFP_GPE2} }, //64
  {PE, BIT3 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE3_MFP_Msk,  SYS_PE_L_MFP_PE3_MFP_GPE3} }, //65
  {PE, BIT4 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE4_MFP_Msk,  SYS_PE_L_MFP_PE4_MFP_GPE4} }, //66
  {PE, BIT5 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE5_MFP_Msk,  SYS_PE_L_MFP_PE5_MFP_GPE5} }, //67
  {PE, BIT6 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE6_MFP_Msk,  SYS_PE_L_MFP_PE6_MFP_GPE6} }, //68
  {PE, BIT7 , {(uint32_t)&SYS->PE_L_MFP, SYS_PE_L_MFP_PE7_MFP_Msk,  SYS_PE_L_MFP_PE7_MFP_GPE7} }, //69
  {NULL, NULL, {NULL, NULL, NULL}}, //70
  {NULL, NULL, {NULL, NULL, NULL}}, //71
  {PA, BIT0 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA0_MFP_Msk,  SYS_PA_L_MFP_PA0_MFP_GPA0} }, //72
  {PA, BIT1 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA1_MFP_Msk,  SYS_PA_L_MFP_PA1_MFP_GPA1} }, //73
  {PA, BIT2 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA2_MFP_Msk,  SYS_PA_L_MFP_PA2_MFP_GPA2} }, //74
  {PA, BIT3 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA3_MFP_Msk,  SYS_PA_L_MFP_PA3_MFP_GPA3} }, //75
  {PA, BIT4 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA4_MFP_Msk,  SYS_PA_L_MFP_PA4_MFP_GPA4} }, //76
  {PA, BIT5 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA5_MFP_Msk,  SYS_PA_L_MFP_PA5_MFP_GPA5} }, //77
  {PA, BIT6 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA6_MFP_Msk,  SYS_PA_L_MFP_PA6_MFP_GPA6} }, //78
  {PA, BIT7 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA7_MFP_Msk,  SYS_PA_L_MFP_PA7_MFP_GPA7} }, //79
  {NULL, NULL, {NULL, NULL, NULL}}, //80
  {NULL, NULL, {NULL, NULL, NULL}}, //81
  {PF, BIT4 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF4_MFP_Msk, SYS_PF_L_MFP_PF4_MFP_GPF4}  }, //82
  {PF, BIT5 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF5_MFP_Msk, SYS_PF_L_MFP_PF5_MFP_GPF5}  }, //83
  {PA, BIT8 , {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA8_MFP_Msk, SYS_PA_H_MFP_PA8_MFP_GPA8}  }, //84
  {PA, BIT9 , {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA9_MFP_Msk, SYS_PA_H_MFP_PA9_MFP_GPA9}  }, //85
  {PA, BIT10, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA10_MFP_Msk, SYS_PA_H_MFP_PA10_MFP_GPA10}}, //86
  {PA, BIT11, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA11_MFP_Msk, SYS_PA_H_MFP_PA11_MFP_GPA11}}, //87
  {PA, BIT12, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA12_MFP_Msk, SYS_PA_H_MFP_PA12_MFP_GPA12}}, //88
  {PA, BIT13, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA13_MFP_Msk, SYS_PA_H_MFP_PA13_MFP_GPA13}}, //89
  {PA, BIT14, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA14_MFP_Msk, SYS_PA_H_MFP_PA14_MFP_GPA14}}, //90
  {PA, BIT15, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA15_MFP_Msk, SYS_PA_H_MFP_PA15_MFP_GPA15}}, //91
  {PB, BIT0 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB0_MFP_Msk, SYS_PB_L_MFP_PB0_MFP_GPB0}  }, //92
  {PB, BIT1 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB1_MFP_Msk, SYS_PB_L_MFP_PB1_MFP_GPB1}  }, //93
  {PB, BIT2 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB2_MFP_Msk, SYS_PB_L_MFP_PB2_MFP_GPB2}  }, //94
  {PB, BIT3 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB3_MFP_Msk, SYS_PB_L_MFP_PB3_MFP_GPB3}  }, //95
  {NULL, NULL, {NULL, NULL, NULL}}, //96
  {NULL, NULL, {NULL, NULL, NULL}}, //97
  {PB, BIT4 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB4_MFP_Msk, SYS_PB_L_MFP_PB4_MFP_GPB4}  }, //98
  {PB, BIT5 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB5_MFP_Msk, SYS_PB_L_MFP_PB5_MFP_GPB5}  }, //99
  {PB, BIT6 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB6_MFP_Msk, SYS_PB_L_MFP_PB6_MFP_GPB6}  }, //100
};
#elif defined(__NANO102SC2AN__)
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}}, //0
  {PB, BIT10, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB10_MFP_Msk, SYS_PB_H_MFP_PB10_MFP_GPB10}}, //1
  {PB, BIT11, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB11_MFP_Msk, SYS_PB_H_MFP_PB11_MFP_GPB11}}, //2
  {PB, BIT12, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB12_MFP_Msk, SYS_PB_H_MFP_PB12_MFP_GPB12}}, //3
  {PB, BIT13, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB13_MFP_Msk, SYS_PB_H_MFP_PB13_MFP_GPB13}}, //4
  {PB, BIT14, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB14_MFP_Msk, SYS_PB_H_MFP_PB14_MFP_GPB14}}, //5
  {PB, BIT15, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB15_MFP_Msk, SYS_PB_H_MFP_PB15_MFP_GPB15}}, //6
  {PC, BIT0 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC0_MFP_Msk , SYS_PC_L_MFP_PC0_MFP_GPC0}  }, //7
  {PC, BIT1 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC1_MFP_Msk , SYS_PC_L_MFP_PC1_MFP_GPC1}  }, //8
  {PC, BIT2 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC2_MFP_Msk , SYS_PC_L_MFP_PC2_MFP_GPC2}  }, //9
  {PC, BIT3 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC3_MFP_Msk , SYS_PC_L_MFP_PC3_MFP_GPC3}  }, //10
  {PC, BIT4 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC4_MFP_Msk , SYS_PC_L_MFP_PC4_MFP_GPC4}  }, //11
  {PC, BIT5 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC5_MFP_Msk , SYS_PC_L_MFP_PC5_MFP_GPC5}  }, //12
  {PC, BIT6 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC6_MFP_Msk , SYS_PC_L_MFP_PC6_MFP_GPC6}  }, //13
  {PC, BIT7 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC7_MFP_Msk , SYS_PC_L_MFP_PC7_MFP_GPC7}  }, //14
  {PC, BIT8 , {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC8_MFP_Msk , SYS_PC_H_MFP_PC8_MFP_GPC8}  }, //15
  {PC, BIT9 , {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC9_MFP_Msk , SYS_PC_H_MFP_PC9_MFP_GPC9}  }, //16
  {PC, BIT14, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC14_MFP_Msk, SYS_PC_H_MFP_PC14_MFP_GPC14}}, //17
  {PC, BIT15, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC15_MFP_Msk, SYS_PC_H_MFP_PC15_MFP_GPC15}}, //18
  {PD, BIT0 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD0_MFP_Msk , SYS_PD_L_MFP_PD0_MFP_GPD0}  }, //19
  {PD, BIT1 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD1_MFP_Msk , SYS_PD_L_MFP_PD1_MFP_GPD1}  }, //20
  {PD, BIT2 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD2_MFP_Msk , SYS_PD_L_MFP_PD2_MFP_GPD2}  }, //21
  {PD, BIT3 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD3_MFP_Msk , SYS_PD_L_MFP_PD3_MFP_GPD3}  }, //22
  {PD, BIT4 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD4_MFP_Msk , SYS_PD_L_MFP_PD4_MFP_GPD4}  }, //23
  {PD, BIT5 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD5_MFP_Msk , SYS_PD_L_MFP_PD5_MFP_GPD5}  }, //24
  {PD, BIT6 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD6_MFP_Msk , SYS_PD_L_MFP_PD6_MFP_GPD6}  }, //25
  {PD, BIT7 , {(uint32_t)&SYS->PD_L_MFP, SYS_PD_L_MFP_PD7_MFP_Msk , SYS_PD_L_MFP_PD7_MFP_GPD7}  }, //26
  {PD, BIT8 , {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD8_MFP_Msk , SYS_PD_H_MFP_PD8_MFP_GPD8}  }, //27
  {PD, BIT9 , {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD9_MFP_Msk , SYS_PD_H_MFP_PD9_MFP_GPD9}  }, //28
  {PD, BIT10, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD10_MFP_Msk, SYS_PD_H_MFP_PD10_MFP_GPD10}}, //29
  {PD, BIT11, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD11_MFP_Msk, SYS_PD_H_MFP_PD11_MFP_GPD11}}, //30
  {PD, BIT12, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD12_MFP_Msk, SYS_PD_H_MFP_PD12_MFP_GPD12}}, //31
  {NULL, NULL, {NULL, NULL, NULL}}, //32
  {PD, BIT13, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD13_MFP_Msk, SYS_PD_H_MFP_PD13_MFP_GPD13}}, //33
  {PD, BIT14, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD14_MFP_Msk, SYS_PD_H_MFP_PD14_MFP_GPD14}}, //34
  {PD, BIT15, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD15_MFP_Msk, SYS_PD_H_MFP_PD15_MFP_GPD15}}, //35
  {NULL, NULL, {NULL, NULL, NULL}}, //36
  {NULL, NULL, {NULL, NULL, NULL}}, //37
  {NULL, NULL, {NULL, NULL, NULL}}, //38
  {PF, BIT0 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF0_MFP_Msk,  SYS_PF_L_MFP_PF0_MFP_GPF0} }, //39
  {PF, BIT1 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF1_MFP_Msk,  SYS_PF_L_MFP_PF1_MFP_GPF1} }, //40
  {NULL, NULL, {NULL, NULL, NULL}}, //41
  {PF, BIT2 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF2_MFP_Msk,  SYS_PF_L_MFP_PF2_MFP_GPF2} }, //42
  {PF, BIT3 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF3_MFP_Msk,  SYS_PF_L_MFP_PF3_MFP_GPF3} }, //43
  {NULL, NULL, {NULL, NULL, NULL}}, //44
  {PA, BIT0 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA0_MFP_Msk,  SYS_PA_L_MFP_PA0_MFP_GPA0} }, //45
  {PA, BIT1 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA1_MFP_Msk,  SYS_PA_L_MFP_PA1_MFP_GPA1} }, //46
  {PA, BIT2 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA2_MFP_Msk,  SYS_PA_L_MFP_PA2_MFP_GPA2} }, //47
  {PA, BIT3 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA3_MFP_Msk,  SYS_PA_L_MFP_PA3_MFP_GPA3} }, //48

  {PA, BIT4 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA4_MFP_Msk,  SYS_PA_L_MFP_PA4_MFP_GPA4} }, //49
  {PA, BIT5 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA5_MFP_Msk,  SYS_PA_L_MFP_PA5_MFP_GPA5} }, //50
  {PA, BIT6 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA6_MFP_Msk,  SYS_PA_L_MFP_PA6_MFP_GPA6} }, //51
  {NULL, NULL, {NULL, NULL, NULL}}, //52
  {NULL, NULL, {NULL, NULL, NULL}}, //53
  {PF, BIT4 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF4_MFP_Msk, SYS_PF_L_MFP_PF4_MFP_GPF4}  }, //54
  {PF, BIT5 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF5_MFP_Msk, SYS_PF_L_MFP_PF5_MFP_GPF5}  }, //55
  {PA, BIT12, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA12_MFP_Msk, SYS_PA_H_MFP_PA12_MFP_GPA12}}, //56
  {PA, BIT13, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA13_MFP_Msk, SYS_PA_H_MFP_PA13_MFP_GPA13}}, //57
  {PA, BIT14, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA14_MFP_Msk, SYS_PA_H_MFP_PA14_MFP_GPA14}}, //58
  {PA, BIT15, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA15_MFP_Msk, SYS_PA_H_MFP_PA15_MFP_GPA15}}, //59
  {PB, BIT0 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB0_MFP_Msk, SYS_PB_L_MFP_PB0_MFP_GPB0}  }, //60
  {PB, BIT1 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB1_MFP_Msk, SYS_PB_L_MFP_PB1_MFP_GPB1}  }, //61
  {PB, BIT2 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB2_MFP_Msk, SYS_PB_L_MFP_PB2_MFP_GPB2}  }, //62
  {PB, BIT3 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB3_MFP_Msk, SYS_PB_L_MFP_PB3_MFP_GPB3}  }, //63
  {PB, BIT6 , {(uint32_t)&SYS->PB_L_MFP, SYS_PB_L_MFP_PB6_MFP_Msk, SYS_PB_L_MFP_PB6_MFP_GPB6}  }, //64
};
#elif defined(__NANO102ZC2AN__)
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}}, //0
  {PB, BIT12, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB12_MFP_Msk, SYS_PB_H_MFP_PB12_MFP_GPB12}}, //1
  {PB, BIT13, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB13_MFP_Msk, SYS_PB_H_MFP_PB13_MFP_GPB13}}, //2
  {PB, BIT14, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB14_MFP_Msk, SYS_PB_H_MFP_PB14_MFP_GPB14}}, //3
  {PB, BIT15, {(uint32_t)&SYS->PB_H_MFP, SYS_PB_H_MFP_PB15_MFP_Msk, SYS_PB_H_MFP_PB15_MFP_GPB15}}, //4
  {PC, BIT4 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC4_MFP_Msk , SYS_PC_L_MFP_PC4_MFP_GPC4}  }, //5
  {PC, BIT6 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC6_MFP_Msk , SYS_PC_L_MFP_PC6_MFP_GPC6}  }, //6
  {PC, BIT7 , {(uint32_t)&SYS->PC_L_MFP, SYS_PC_L_MFP_PC7_MFP_Msk , SYS_PC_L_MFP_PC7_MFP_GPC7}  }, //7
  {PC, BIT8 , {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC8_MFP_Msk , SYS_PC_H_MFP_PC8_MFP_GPC8}  }, //8
  {PC, BIT10, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC10_MFP_Msk, SYS_PC_H_MFP_PC10_MFP_GPC10}}, //9
  {PC, BIT11, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC11_MFP_Msk, SYS_PC_H_MFP_PC11_MFP_GPC11}}, //10
  {PC, BIT12, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC12_MFP_Msk, SYS_PC_H_MFP_PC12_MFP_GPC12}}, //11
  {PC, BIT13, {(uint32_t)&SYS->PC_H_MFP, SYS_PC_H_MFP_PC13_MFP_Msk, SYS_PC_H_MFP_PC13_MFP_GPC13}}, //12
  {PD, BIT9 , {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD9_MFP_Msk , SYS_PD_H_MFP_PD9_MFP_GPD9}  }, //13
  {PD, BIT10, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD10_MFP_Msk, SYS_PD_H_MFP_PD10_MFP_GPD10}}, //14
  {PD, BIT11, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD11_MFP_Msk, SYS_PD_H_MFP_PD11_MFP_GPD11}}, //15
  {PD, BIT12, {(uint32_t)&SYS->PD_H_MFP, SYS_PD_H_MFP_PD12_MFP_Msk, SYS_PD_H_MFP_PD12_MFP_GPD12}}, //16
  {NULL, NULL, {NULL, NULL, NULL}}, //17
  {NULL, NULL, {NULL, NULL, NULL}}, //18
  {NULL, NULL, {NULL, NULL, NULL}}, //19
  {PF, BIT0 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF0_MFP_Msk,  SYS_PF_L_MFP_PF0_MFP_GPF0} }, //20
  {PF, BIT1 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF1_MFP_Msk,  SYS_PF_L_MFP_PF1_MFP_GPF1} }, //21
  {NULL, NULL, {NULL, NULL, NULL}}, //22
  {PF, BIT2 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF2_MFP_Msk,  SYS_PF_L_MFP_PF2_MFP_GPF2} }, //23
  {PF, BIT3 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF3_MFP_Msk,  SYS_PF_L_MFP_PF3_MFP_GPF3} }, //24
  {PA, BIT4 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA4_MFP_Msk,  SYS_PA_L_MFP_PA4_MFP_GPA4} }, //25
  {PA, BIT5 , {(uint32_t)&SYS->PA_L_MFP, SYS_PA_L_MFP_PA5_MFP_Msk,  SYS_PA_L_MFP_PA5_MFP_GPA5} }, //26
  {NULL, NULL, {NULL, NULL, NULL}}, //27
  {PF, BIT4 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF4_MFP_Msk, SYS_PF_L_MFP_PF4_MFP_GPF4}  }, //28
  {PF, BIT5 , {(uint32_t)&SYS->PF_L_MFP, SYS_PF_L_MFP_PF5_MFP_Msk, SYS_PF_L_MFP_PF5_MFP_GPF5}  }, //29
  {PA, BIT12, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA12_MFP_Msk, SYS_PA_H_MFP_PA12_MFP_GPA12}}, //30
  {PA, BIT13, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA13_MFP_Msk, SYS_PA_H_MFP_PA13_MFP_GPA13}}, //31
  {PA, BIT14, {(uint32_t)&SYS->PA_H_MFP, SYS_PA_H_MFP_PA14_MFP_Msk, SYS_PA_H_MFP_PA14_MFP_GPA14}}, //32
};
#endif

#endif