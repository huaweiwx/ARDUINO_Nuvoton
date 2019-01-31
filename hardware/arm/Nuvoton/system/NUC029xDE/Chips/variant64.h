/*
  variant64.h
  
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
  {NULL, NULL, {NULL, NULL, NULL}},                                           //0
  {PB, BIT14, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB14_Msk, SYS_MFP_PB14_GPIO }},//1
  {PB, BIT13, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB13_Msk, SYS_MFP_PB13_GPIO }},//2
  {PB, BIT12, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB12_Msk, SYS_MFP_PB12_GPIO }},//3
  {PF, BIT5, {(uint32_t)&SYS->PF_MFP, SYS_MFP_PF5_Msk, SYS_MFP_PF5_GPIO }},   //4
  {PF, BIT4, {(uint32_t)&SYS->PF_MFP, SYS_MFP_PF4_Msk, SYS_MFP_PF4_GPIO }},   //5
  {PA, BIT11, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA11_Msk, SYS_MFP_PA11_GPIO }},//6
  {PA, BIT10, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA10_Msk, SYS_MFP_PA10_GPIO }},//7
  {PA, BIT9 , {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA9_Msk, SYS_MFP_PA9_GPIO }},  //8
  {PA, BIT8 , {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA8_Msk, SYS_MFP_PA8_GPIO }},  //9
  {PB, BIT4, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB4_Msk, SYS_MFP_PB4_GPIO}},    //10
  {PB, BIT5, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB5_Msk, SYS_MFP_PB5_GPIO}},    //11
  {PB, BIT6, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB6_Msk, SYS_MFP_PB6_GPIO}},    //12
  {PB, BIT7, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB7_Msk, SYS_MFP_PB7_GPIO}},    //13
  /*    		LDO_CAP          */{NULL, NULL, {NULL, NULL, NULL}},          //14
  /*            VDD              */{NULL, NULL, {NULL, NULL, NULL}},          //15
  /*    		VSS              */{NULL, NULL, {NULL, NULL, NULL}},          //16
  {PB, BIT0, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB0_Msk, SYS_MFP_PB0_GPIO }},   //17
  {PB, BIT1, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB1_Msk, SYS_MFP_PB1_GPIO }},   //18
  {PB, BIT2, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB2_Msk, SYS_MFP_PB2_GPIO }},   //19
  {PB, BIT3, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB3_Msk, SYS_MFP_PB3_GPIO }},   //20
  {PD, BIT6, {(uint32_t)&SYS->PD_MFP, SYS_MFP_PD6_Msk, SYS_MFP_PD6_GPIO }},   //21
  {PD, BIT7, {(uint32_t)&SYS->PD_MFP, SYS_MFP_PD7_Msk, SYS_MFP_PD7_GPIO }},   //22
  {PD, BIT14,{(uint32_t)&SYS->PD_MFP, SYS_MFP_PD14_Msk,SYS_MFP_PD14_GPIO}},   //23
  {PD, BIT15,{(uint32_t)&SYS->PD_MFP, SYS_MFP_PD15_Msk,SYS_MFP_PD15_GPIO}},   //24
  {PC, BIT3, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC3_Msk, SYS_MFP_PC3_GPIO }},   //25
  {PC, BIT2, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC2_Msk, SYS_MFP_PC2_GPIO }},   //26
  {PC, BIT1, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC1_Msk, SYS_MFP_PC1_GPIO }},   //27
  {PC, BIT0, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC0_Msk, SYS_MFP_PC0_GPIO }},   //28
  {PE, BIT5, {(uint32_t)&SYS->PE_MFP, SYS_MFP_PE5_Msk, SYS_MFP_PE5_GPIO }},   //39
  {PB, BIT11,{(uint32_t)&SYS->PB_MFP, SYS_MFP_PB11_Msk,SYS_MFP_PB11_GPIO}},   //30
  {PB, BIT10,{(uint32_t)&SYS->PB_MFP, SYS_MFP_PB10_Msk,SYS_MFP_PB10_GPIO}},   //31
  {PB, BIT9, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB9_Msk, SYS_MFP_PB9_GPIO}},    //32
  {PC, BIT11,{(uint32_t)&SYS->PC_MFP, SYS_MFP_PC11_Msk,SYS_MFP_PC11_GPIO}},   //33
  {PC, BIT10,{(uint32_t)&SYS->PC_MFP, SYS_MFP_PC10_Msk,SYS_MFP_PC10_GPIO}},   //34
  {PC, BIT9, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC9_Msk, SYS_MFP_PC9_GPIO}},    //35
  {PC, BIT8 ,{(uint32_t)&SYS->PC_MFP, SYS_MFP_PC8_Msk, SYS_MFP_PC8_GPIO }},   //36
  {PA, BIT15, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA15_Msk, SYS_MFP_PA15_GPIO }},//37
  {PA, BIT14, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA14_Msk, SYS_MFP_PA14_GPIO }},//38
  {PA, BIT13, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA13_Msk, SYS_MFP_PA13_GPIO }},//39
  {PA, BIT12, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA12_Msk, SYS_MFP_PA12_GPIO }},//40
#if USE_ICE == 0
  {PF, BIT7, {(uint32_t)&SYS->PE_MFP, SYS_MFP_PF7_Msk, SYS_MFP_PF7_GPIO }},   //41
  {PF, BIT6, {(uint32_t)&SYS->PE_MFP, SYS_MFP_PF6_Msk, SYS_MFP_PF6_GPIO }},   //42
#else
                                    {NULL, NULL, {NULL, NULL, NULL}},         //41
                                    {NULL, NULL, {NULL, NULL, NULL}},         //42
#endif
  /*    		AVSS              */{NULL, NULL, {NULL, NULL, NULL}},         //43
  {PA, BIT0, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA0_Msk, SYS_MFP_PA0_GPIO }},   //44
  {PA, BIT1, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA1_Msk, SYS_MFP_PA1_GPIO }},   //45
  {PA, BIT2, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA2_Msk, SYS_MFP_PA2_GPIO }},   //46
  {PA, BIT3, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA3_Msk, SYS_MFP_PA3_GPIO }},   //47
  {PA, BIT4, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA4_Msk, SYS_MFP_PA4_GPIO }},   //48
  {PA, BIT5, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA5_Msk, SYS_MFP_PA5_GPIO }},   //49
  {PA, BIT6, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA6_Msk, SYS_MFP_PA6_GPIO }},   //50
  {PA, BIT7, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA7_Msk, SYS_MFP_PA7_GPIO }},   //51
  /*          AVDD             */{NULL, NULL, {NULL, NULL, NULL}},            //52
  {PC, BIT7, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC7_Msk, SYS_MFP_PC7_GPIO }},   //53
  {PC, BIT6, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC6_Msk, SYS_MFP_PC6_GPIO }},   //54
  {PC, BIT14,{(uint32_t)&SYS->PC_MFP, SYS_MFP_PC14_Msk,SYS_MFP_PC14_GPIO}},   //55
  {PC, BIT15,{(uint32_t)&SYS->PC_MFP, SYS_MFP_PC15_Msk,SYS_MFP_PC15_GPIO}},   //56
  {PB, BIT15, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB15_Msk, SYS_MFP_PB15_GPIO }},//57
  /*    		XTAL2            */{NULL, NULL, {NULL, NULL, NULL}},          //58
  /*    		XTAL1            */{NULL, NULL, {NULL, NULL, NULL}},          //59
  /*nRST                         */{NULL, NULL, {NULL, NULL, NULL}},          //60 
  /*    		VSS              */{NULL, NULL, {NULL, NULL, NULL}},          //61
  /*            VDD              */{NULL, NULL, {NULL, NULL, NULL}},          //62
  {PF, BIT8, {(uint32_t)&SYS->PE_MFP, SYS_MFP_PF8_Msk, SYS_MFP_PF8_GPIO }},   //63
  {PB, BIT8, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB8_Msk, SYS_MFP_PB8_GPIO }},   //64
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWM,PWM23_MODULE,PWM_IRQn,2,500,{PC_4,SYS_MFP_PC4_PWM2}},  //2  
	{PWM,PWM23_MODULE,PWM_IRQn,3,500,{PC_5,SYS_MFP_PC5_PWM3}},  //3  
	{PWM,PWM45_MODULE,PWM_IRQn,5,500,{PA_4,SYS_MFP_PA4_PWM5}},  //5  
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
	{ADC,ADC_MODULE,2,{PB_2,SYS_MFP_PB2_AIN2}},		//2
	{ADC,ADC_MODULE,3,{PB_3,SYS_MFP_PB3_AIN3}},		//3
	{ADC,ADC_MODULE,4,{PB_4,SYS_MFP_PB4_AIN4}},		//4
	{ADC,ADC_MODULE,5,{PB_5,SYS_MFP_PB5_AIN5}},		//5	
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinDescription UART_Desc[]={
   {UART,UART_MODULE,UART_IRQn,{{PB_2,SYS_MFP_PB2_RXD}, {PB_3,SYS_MFP_PB3_TXD} }},	
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinDescription SPI_Desc[]={
	{
	 SPI,SPI_MODULE,SPI_IRQn,CLK_CLKSEL1_SPI_S_HCLK,
	 {{PA_7,SYS_MFP_PA7_SPICLK},{PA_6,SYS_MFP_PA6_MISO},{PA_5,SYS_MFP_PA5_MOSI}, {PA_4,SYS_MFP_PA4_SPISS}, }
	},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinDescription I2C_Desc[]={	
  {
	I2C,I2C_MODULE,I2C_IRQn,
    {{PD_4,SYS_MFP_PD4_SDA},{PD_5, SYS_MFP_PD5_SCL},}
  },
};
#endif
