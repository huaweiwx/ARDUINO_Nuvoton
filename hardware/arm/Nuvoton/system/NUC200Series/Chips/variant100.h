/*
  variant100.h
  
  Copyright (c) 2018 huaweiwx@sina.com 2018.11.1

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
#pragma GCC diagnostic ignored "-Wconversion-null"

#ifndef GPIO_DESC_USERDEF
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
  {PA, BIT9,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA9_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPA_MFP_PA9_GPIO }}, //11
  {PA, BIT8,  {(uint32_t)&SYS->GPA_MFP, SYS_GPA_MFP_PA8_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPA_MFP_PA8_GPIO }}, //12
  {PD, BIT8,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD8_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD8_GPIO }}, //13
  {PD, BIT9,  {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD9_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD9_GPIO }}, //14
  {PD, BIT10, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD10_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD10_GPIO}}, //15
  {PD, BIT11, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD11_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD11_GPIO}}, //16
  {PD, BIT12, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD12_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD12_GPIO}}, //17
  {PD, BIT13, {(uint32_t)&SYS->GPD_MFP, SYS_GPD_MFP_PD13_Msk, NULL,                 NULL,                   NULL,                 SYS_GPD_MFP_PD13_GPIO}}, //18
  {PB, BIT4,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB4_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB4_GPIO }}, //19
  {PB, BIT5,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB5_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB5_GPIO }}, //20
  {PB, BIT6,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB6_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB6_GPIO }}, //21
  {PB, BIT7,  {(uint32_t)&SYS->GPB_MFP, SYS_GPB_MFP_PB7_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPB_MFP_PB7_GPIO }}, //22
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //23
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //24
  {NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}}, //25
  {PE, BIT7,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE7_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE7_GPIO }}, //26
  {PE, BIT8,  {(uint32_t)&SYS->GPE_MFP, SYS_GPE_MFP_PE8_Msk,  NULL,                 NULL,                   NULL,                 SYS_GPE_MFP_PE8_GPIO }}, //27
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
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[] = {
  {PWMA, PWM01_MODULE, PWMA_IRQn, 0, 500, {PA_12, SYS_GPA_MFP_PA12_PWM0, NULL,                 SYS_ALT_MFP1_PA12_PWM0, NULL                 }}, //0
  {PWMA, PWM01_MODULE, PWMA_IRQn, 1, 500, {PA_13, SYS_GPA_MFP_PA13_PWM1, NULL,                 SYS_ALT_MFP1_PA13_PWM1, NULL                 }}, //1
  {PWMA, PWM23_MODULE, PWMA_IRQn, 2, 500, {PA_14, SYS_GPA_MFP_PA14_PWM2, NULL,                 SYS_ALT_MFP1_PA14_PWM2, NULL                 }}, //2
  {PWMA, PWM23_MODULE, PWMA_IRQn, 3, 500, {PA_15, SYS_GPA_MFP_PA15_PWM3, SYS_ALT_MFP_PA15_PWM3, SYS_ALT_MFP1_PA15_PWM3, NULL                 }}, //3
  {PWMB, PWM45_MODULE, PWMB_IRQn, 0, 500, {PB_11, SYS_GPB_MFP_PB11_PWM4, SYS_ALT_MFP_PB11_PWM4, NULL,                  NULL                 }}, //4
  {PWMB, PWM45_MODULE, PWMB_IRQn, 1, 500, {PE_5 , SYS_GPE_MFP_PE5_PWM5 , SYS_ALT_MFP_PE5_PWM5 , NULL,                  SYS_ALT_MFP2_PE5_PWM5}}, //5
  {PWMB, PWM67_MODULE, PWMB_IRQn, 2, 500, {PE_0 , SYS_GPE_MFP_PE0_PWM6 , NULL,                 NULL,                  NULL                 }}, //6
  {PWMB, PWM67_MODULE, PWMB_IRQn, 3, 500, {PE_1 , SYS_GPE_MFP_PE1_PWM7 , NULL,                 NULL,                  NULL                 }}, //7
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[] = {
  {ADC, ADC_MODULE, 0, {PA_0, SYS_GPA_MFP_PA0_ADC0, NULL,                 SYS_ALT_MFP1_PA0_ADC0, NULL                 }}, //0
  {ADC, ADC_MODULE, 1, {PA_1, SYS_GPA_MFP_PA1_ADC1, NULL,                 SYS_ALT_MFP1_PA1_ADC1, NULL                 }}, //1
  {ADC, ADC_MODULE, 2, {PA_2, SYS_GPA_MFP_PA2_ADC2, NULL,                 SYS_ALT_MFP1_PA2_ADC2, NULL                 }}, //2
  {ADC, ADC_MODULE, 3, {PA_3, SYS_GPA_MFP_PA3_ADC3, NULL,                 SYS_ALT_MFP1_PA3_ADC3, NULL                 }}, //3
  {ADC, ADC_MODULE, 4, {PA_4, SYS_GPA_MFP_PA4_ADC4, NULL,                 SYS_ALT_MFP1_PA4_ADC4, NULL                 }}, //4
  {ADC, ADC_MODULE, 5, {PA_5, SYS_GPA_MFP_PA5_ADC5, NULL,                 SYS_ALT_MFP1_PA5_ADC5, NULL                 }}, //5
  {ADC, ADC_MODULE, 6, {PA_6, SYS_GPA_MFP_PA6_ADC6, NULL,                 SYS_ALT_MFP1_PA6_ADC6, NULL                 }}, //6
  {ADC, ADC_MODULE, 7, {PA_7, SYS_GPA_MFP_PA7_ADC7, SYS_ALT_MFP_PA7_ADC7, SYS_ALT_MFP1_PA7_ADC7, NULL                 }}, //7
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = {
	{{60,SYS_GPC_MFP_PC9_SPI1_CLK, NULL, NULL, NULL},
     {58,SYS_GPC_MFP_PC11_SPI1_MOSI0, NULL, NULL, NULL},
	 {59,SYS_GPC_MFP_PC10_SPI1_MISO0, NULL, NULL, NULL},
	 {61,SYS_GPC_MFP_PC8_SPI1_SS0, NULL, NULL, NULL}},
};
const SPIPinAlt_TypeDef SPI1PinAlt[] = {
    {{PC_9 ,SYS_GPC_MFP_PC9_SPI1_CLK, NULL, NULL, NULL},    {PC_11,SYS_GPC_MFP_PC11_SPI1_MOSI0, NULL, NULL, NULL},
     {PC_10,SYS_GPC_MFP_PC10_SPI1_MISO0, NULL, NULL, NULL},{PC_8 ,SYS_GPC_MFP_PC8_SPI1_SS0, NULL, NULL, NULL}},
};
const SPIPinAlt_TypeDef SPI2PinAlt[] = {
     {{PD_1, SYS_GPD_MFP_PD1_SPI2_CLK  , NULL, NULL, NULL},
      {PD_3, SYS_GPD_MFP_PD3_SPI2_MOSI0, NULL, NULL, NULL},
      {PD_2, SYS_GPD_MFP_PD2_SPI2_MISO0, NULL, NULL, NULL},
      {PD_0, SYS_GPD_MFP_PD0_SPI2_SS0  , NULL, NULL, NULL}
  },
};
const SPIPinDescription SPI_Desc[] = {
  {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL1_SPI0_S_HCLK,SPI0PinAlt},
  {SPI1,SPI1_MODULE,SPI1_IRQn,CLK_CLKSEL1_SPI1_S_HCLK,SPI1PinAlt},
  {SPI2,SPI2_MODULE,SPI2_IRQn,CLK_CLKSEL1_SPI2_S_HCLK,SPI2PinAlt},
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
  {{PB_0, SYS_GPB_MFP_PB0_UART0_RXD, NULL, NULL, NULL}, {PB_1, SYS_GPB_MFP_PB1_UART0_TXD, NULL, NULL, NULL}},
};
const UARTPinAlt_TypeDef UART1PinAlt[] = {
  {{PB_4, SYS_GPB_MFP_PB4_UART1_RXD, NULL, NULL, NULL}, {PB_5, SYS_GPB_MFP_PB5_UART1_TXD, NULL, NULL, NULL}},
};
const UARTPinAlt_TypeDef UART2PinAlt[] = {
  {{PD_14, SYS_GPD_MFP_PD14_UART2_RXD, NULL, NULL, NULL},{PD_15, SYS_GPD_MFP_PD15_UART2_TXD, NULL, NULL, NULL}},
};
const UARTPinDescription UART_Desc[] = {
  {UART0, UART0_MODULE, UART02_IRQn, UART0PinAlt},
  {UART1, UART1_MODULE, UART1_IRQn, UART1PinAlt},
  {UART2, UART2_MODULE, UART02_IRQn, UART2PinAlt},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
  {{PA_9, SYS_GPA_MFP_PA9_I2C0_SCL, NULL, NULL, NULL},{PA_8, SYS_GPA_MFP_PA8_I2C0_SDA, NULL, NULL, NULL}},
};
const I2CPinAlt_TypeDef I2C1PinAlt[] = {
  {{PA_11,SYS_GPA_MFP_PA11_I2C1_SCL,NULL, NULL, NULL},{PA_10,SYS_GPA_MFP_PA10_I2C1_SDA,NULL, NULL, NULL}},
};
const I2CPinDescription I2C_Desc[] = {
  {I2C0, I2C0_MODULE,I2C0_IRQn,I2C0PinAlt},
  {I2C1, I2C1_MODULE,I2C1_IRQn,I2C1PinAlt},
};
#endif

#ifndef CAN_DESC_USERDEF
const CANPinDescription CAN_Desc[] = {
  {CAN0, CAN0_MODULE, CAN0_IRQn, {{PD_6, SYS_GPD_MFP_PD6_CAN0_RXD, NULL, NULL, NULL}, {PD_7, SYS_GPD_MFP_PD7_CAN0_TXD, NULL, NULL, NULL}}},
};
#endif
