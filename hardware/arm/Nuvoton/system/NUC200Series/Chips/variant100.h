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

#ifdef USE_BoardToPin
const BoardToPin BoardToPinInfo[] = {
  { 32, UART_TYPE, 0}, // 0: PB0(UART_RX0)
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

#pragma GCC diagnostic ignored "-Wconversion-null"

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
