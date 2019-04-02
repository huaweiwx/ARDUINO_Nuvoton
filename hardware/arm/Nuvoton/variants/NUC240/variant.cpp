/*
 Copyright (c) 2011 Arduino. All right reserved.

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
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
#include "Arduino.h"

#pragma GCC diagnostic ignored "-Wconversion-null"

 #if defined(CHIP100P)
  #include "Chips/variant100.h"
 #elif defined(CHIP64P)
  #include "Chips/variant64.h"
 #elif defined(CHIP48P)
  #include "Chips/variant48.h"
 #endif

#if  defined(ARDUINO_NuEdu_NUC240)
const GPIOPinDescription GPIO_Desc[] =
{
  {PB, BIT0,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB0_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB0_GPIO }}, //0
  {PB, BIT1,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB1_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB1_GPIO }}, //1
  {PA, BIT12, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA12_Msk, NULL,                 SYS_ALT_MFP1_PA12_Msk,  NULL,                 SYS_GPA_MFP_PA12_GPIO}},//2
  {PA, BIT13, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA13_Msk, NULL,                 SYS_ALT_MFP1_PA13_Msk,  NULL,                 SYS_GPA_MFP_PA13_GPIO}},//3
  {PA, BIT14, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA14_Msk, NULL,                 SYS_ALT_MFP1_PA14_Msk,  NULL,                 SYS_GPA_MFP_PA14_GPIO}},//4
  {PA, BIT15, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA15_Msk, SYS_ALT_MFP_PA15_Msk, SYS_ALT_MFP1_PA15_Msk,  NULL,                 SYS_GPA_MFP_PA15_GPIO}},//5
  {PB, BIT11, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB11_Msk, SYS_ALT_MFP_PB11_Msk, NULL,                   NULL,                 SYS_GPB_MFP_PB11_GPIO}},//6
  {PE, BIT5,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE5_Msk, SYS_ALT_MFP_PE5_Msk,  NULL,                   SYS_ALT_MFP2_PE5_Msk, SYS_GPE_MFP_PE5_GPIO }}, //7
  {PE, BIT0,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE0_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE0_GPIO }}, //8
  {PE, BIT1,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE1_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE1_GPIO }}, //9

  {PC, BIT4,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC4_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC4_GPIO }}, //10
  {PB, BIT9,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB9_Msk, SYS_ALT_MFP_PB9_Msk,  NULL,                   NULL,                 SYS_GPB_MFP_PB9_GPIO }}, //11
  {PC, BIT5,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC5_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC5_GPIO }}, //12
  {PE, BIT6,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE6_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE6_GPIO }}, //13
  {PA, BIT10, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA10_Msk, SYS_ALT_MFP_PA10_Msk, NULL,                   NULL,                 SYS_GPA_MFP_PA10_GPIO}},//14
  {PA, BIT11, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA11_Msk, SYS_ALT_MFP_PA11_Msk, NULL,                   NULL,                 SYS_GPA_MFP_PA11_GPIO}},//15
  {PA, BIT0,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA0_Msk, NULL,                 SYS_ALT_MFP1_PA0_Msk,   NULL,                 SYS_GPA_MFP_PA0_GPIO }}, //16
  {PA, BIT1,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA1_Msk, NULL,                 SYS_ALT_MFP1_PA1_Msk,   NULL,                 SYS_GPA_MFP_PA1_GPIO }}, //17
  {PA, BIT2,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA2_Msk, NULL,                 SYS_ALT_MFP1_PA2_Msk,   NULL,                 SYS_GPA_MFP_PA2_GPIO }}, //18
  {PA, BIT3,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA3_Msk, NULL,                 SYS_ALT_MFP1_PA3_Msk,   NULL,                 SYS_GPA_MFP_PA3_GPIO }}, //19

  {PA, BIT4,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA4_Msk, NULL,                 SYS_ALT_MFP1_PA4_Msk,   NULL,                 SYS_GPA_MFP_PA4_GPIO }}, //20
  {PA, BIT5,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA5_Msk, NULL,                 SYS_ALT_MFP1_PA5_Msk,   NULL,                 SYS_GPA_MFP_PA5_GPIO }}, //21
  {PA, BIT6,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA6_Msk, NULL,                 SYS_ALT_MFP1_PA6_Msk,   NULL,                 SYS_GPA_MFP_PA6_GPIO }}, //22
  {PA, BIT7,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA7_Msk, SYS_ALT_MFP_PA7_Msk,  SYS_ALT_MFP1_PA7_Msk,   NULL,                 SYS_GPA_MFP_PA7_GPIO }}, //23
  {PC, BIT15, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC15_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC15_GPIO}},//24
  {PC, BIT14, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC14_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC14_GPIO}},//25
  {PE, BIT15, {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE15_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE15_GPIO}},//26
  {PE, BIT14, {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE14_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE14_GPIO}},//27
  {PD, BIT4,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD4_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD4_GPIO }}, //28
  {PD, BIT5,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD5_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD5_GPIO }}, //29

  {PD, BIT6,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD6_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD6_GPIO }}, //30
  {PD, BIT7,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD7_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD7_GPIO }}, //31
  {PA, BIT9,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA9_Msk, NULL,                 NULL,                   NULL,                 SYS_GPA_MFP_PA9_GPIO }}, //32
  {PA, BIT8,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA8_Msk, NULL,                 NULL,                   NULL,                 SYS_GPA_MFP_PA8_GPIO }}, //33
  {PB, BIT4,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB4_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB4_GPIO }}, //34
  {PB, BIT5,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB5_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB5_GPIO }}, //35
  {PD, BIT14, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD14_Msk, NULL,                NULL,                  SYS_ALT_MFP2_PD14_Msk, SYS_GPD_MFP_PD14_GPIO}}, //36
  {PD, BIT15, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD15_Msk, NULL,                NULL,                  SYS_ALT_MFP2_PD15_Msk, SYS_GPD_MFP_PD15_GPIO}}, //37
  {PE, BIT7,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE7_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE7_GPIO }}, //38
  {PE, BIT8,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE8_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE8_GPIO }}, //39

  {PD, BIT2,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD2_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD2_GPIO }}, //40
  {PD, BIT1,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD1_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD1_GPIO }}, //41
  {PD, BIT3,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD3_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD3_GPIO }}, //42
  {PD, BIT4,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD4_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD4_GPIO }}, //43
  {PC, BIT13, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC13_Msk, NULL,                 NULL,                  NULL,                 SYS_GPC_MFP_PC13_GPIO}}, //44
  {PD, BIT8,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD8_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD8_GPIO }}, //45
  {PB, BIT8,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB8_Msk, SYS_ALT_MFP_PB8_Msk,  NULL,                   NULL,                 SYS_GPB_MFP_PB8_GPIO }}, //46
  {PD, BIT9,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD9_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD9_GPIO }}, //47
  {PA, BIT15, {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA15_Msk, SYS_ALT_MFP_PA15_Msk, SYS_ALT_MFP1_PA15_Msk, NULL,                 SYS_GPA_MFP_PA15_GPIO}}, //48
  {PD, BIT10, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD10_Msk, NULL,                 NULL,                  NULL,                 SYS_GPD_MFP_PD10_GPIO}}, //49

  {PC, BIT0,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC0_Msk, SYS_ALT_MFP_PC0_Msk,  NULL,                   NULL,                 SYS_GPC_MFP_PC0_GPIO }}, //50
  {PD, BIT11, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD11_Msk, NULL,                 NULL,                  NULL,                 SYS_GPD_MFP_PD11_GPIO}}, //51
  {PC, BIT1,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC1_Msk, SYS_ALT_MFP_PC1_Msk,  NULL,                   NULL,                 SYS_GPC_MFP_PC1_GPIO }}, //52
  {PD, BIT12, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD12_Msk, NULL,                 NULL,                  NULL,                 SYS_GPD_MFP_PD12_GPIO}}, //53
  {PC, BIT2,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC2_Msk, SYS_ALT_MFP_PC2_Msk,  NULL,                   NULL,                 SYS_GPC_MFP_PC2_GPIO }}, //54
  {PD, BIT13, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD13_Msk, NULL,                 NULL,                  NULL,                 SYS_GPD_MFP_PD13_GPIO}}, //55
  {PC, BIT3,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC3_Msk, SYS_ALT_MFP_PC3_Msk,  NULL,                   NULL,                 SYS_GPC_MFP_PC3_GPIO }}, //56
  {PC, BIT12, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC12_Msk, NULL,                 NULL,                  NULL,                 SYS_GPC_MFP_PC12_GPIO}}, //57
  {PB, BIT10, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB10_Msk, SYS_ALT_MFP_PB10_Msk, NULL,                  NULL,                 SYS_GPB_MFP_PB10_GPIO}}, //58
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //59

  {PB, BIT3,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB3_Msk, SYS_ALT_MFP_PB3_Msk,  SYS_ALT_MFP1_PB3_Msk,   SYS_ALT_MFP2_PB3_Msk, SYS_GPB_MFP_PB3_GPIO }}, //60
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}},                                                                                                           //61
  {PC, BIT7,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC7_Msk, NULL,                 SYS_ALT_MFP1_PC7_Msk,   NULL,                 SYS_GPC_MFP_PC7_GPIO }}, //62
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}},                                                                                                           //63
  {PC, BIT6,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC6_Msk, NULL,                 SYS_ALT_MFP1_PC6_Msk,   NULL,                 SYS_GPC_MFP_PC6_GPIO }}, //64
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}},                                                                                                           //65
  {PB, BIT2,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB2_Msk, SYS_ALT_MFP_PB2_Msk,  NULL,                   SYS_ALT_MFP2_PB2_Msk, SYS_GPB_MFP_PB2_GPIO }}, //66
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}},                                                                                                           //67
  {PC, BIT8,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC8_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC8_GPIO }}, //68
  {PB, BIT7,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB7_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB7_GPIO }}, //69

  {PC, BIT9,  {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC9_Msk, NULL,                 NULL,                   NULL,                 SYS_GPC_MFP_PC9_GPIO }}, //70
  {PB, BIT6,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB6_Msk, NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB6_GPIO }}, //71
  {PC, BIT10, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC10_Msk, NULL,                 NULL,                  NULL,                 SYS_GPC_MFP_PC10_GPIO}}, //72
  {PF, BIT2,  {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF2_Msk, NULL,                 NULL,                   NULL,                 SYS_GPF_MFP_PF2_GPIO }}, //73
  {PC, BIT11, {(uint32_t)&SYS->GPC_MFP, SYS_GPC_MFP_PC11_Msk, NULL,                 NULL,                  NULL,                 SYS_GPC_MFP_PC11_GPIO}}, //74
  {PF, BIT3,  {(uint32_t)&SYS->GPF_MFP, SYS_GPF_MFP_PF3_Msk, NULL,                 NULL,                   NULL,                 SYS_GPF_MFP_PF3_GPIO }}, //75
  {PE, BIT2,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE2_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE2_GPIO }}, //76
  {PB, BIT14, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB14_Msk, SYS_ALT_MFP_PB14_Msk, NULL,                  NULL,                 SYS_GPB_MFP_PB14_GPIO}}, //77
  {PE, BIT3,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE3_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE3_GPIO }}, //78
  {PB, BIT15, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB15_Msk, SYS_ALT_MFP_PB15_Msk, NULL,                 SYS_ALT_MFP2_PB15_Msk, SYS_GPB_MFP_PB15_GPIO}}, //79

  {PE, BIT4,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE4_Msk, NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE4_GPIO }}, //80
  {PE, BIT13, {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE13_Msk, NULL,                 NULL,                  NULL,                 SYS_GPE_MFP_PE13_GPIO}}, //81
  {PB, BIT13, {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB13_Msk, NULL,                 NULL,                  NULL,                 SYS_GPB_MFP_PB13_GPIO}}, //82
  {PD, BIT0,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD0_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD0_GPIO }}, //83
};
#endif
