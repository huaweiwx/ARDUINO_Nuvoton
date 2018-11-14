
#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}},                                           //0
  {PB, BIT12, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB12_Msk, SYS_MFP_PB12_GPIO }},//1
  {PF, BIT5, {(uint32_t)&SYS->PF_MFP, SYS_MFP_PF5_Msk, SYS_MFP_PF5_GPIO }},   //2
  {PF, BIT4, {(uint32_t)&SYS->PF_MFP, SYS_MFP_PF4_Msk, SYS_MFP_PF4_GPIO }},   //3
  {PA, BIT11, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA11_Msk, SYS_MFP_PA11_GPIO }},//4
  {PA, BIT10, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA10_Msk, SYS_MFP_PA10_GPIO }},//5
  {PA, BIT9 , {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA9_Msk, SYS_MFP_PA9_GPIO }},  //6
  {PA, BIT8 , {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA8_Msk, SYS_MFP_PA8_GPIO }},  //7
  {PB, BIT4, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB4_Msk, SYS_MFP_PB4_GPIO}},    //8
  {PB, BIT5, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB5_Msk, SYS_MFP_PB5_GPIO}},    //9
  /*    		LDO_CAP          */{NULL, NULL, {NULL, NULL, NULL}},          //10
  /*            VDD              */{NULL, NULL, {NULL, NULL, NULL}},          //11
  /*    		VSS              */{NULL, NULL, {NULL, NULL, NULL}},          //12
  {PB, BIT0, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB0_Msk, SYS_MFP_PB0_GPIO }},   //13
  {PB, BIT1, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB1_Msk, SYS_MFP_PB1_GPIO }},   //14
  {PB, BIT2, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB2_Msk, SYS_MFP_PB2_GPIO }},   //15
  {PB, BIT3, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB3_Msk, SYS_MFP_PB3_GPIO }},   //16
  {PD, BIT6, {(uint32_t)&SYS->PD_MFP, SYS_MFP_PD6_Msk, SYS_MFP_PD6_GPIO }},   //17
  {PD, BIT7, {(uint32_t)&SYS->PD_MFP, SYS_MFP_PD7_Msk, SYS_MFP_PD7_GPIO }},   //18
  {PD, BIT14, {(uint32_t)&SYS->PD_MFP, SYS_MFP_PD14_Msk, SYS_MFP_PD14_GPIO }},//19
  {PD, BIT15, {(uint32_t)&SYS->PD_MFP, SYS_MFP_PD15_Msk, SYS_MFP_PD15_GPIO }},//20
  {PC, BIT3, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC3_Msk, SYS_MFP_PC3_GPIO }},   //21
  {PC, BIT2, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC2_Msk, SYS_MFP_PC2_GPIO }},   //22
  {PC, BIT1, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC1_Msk, SYS_MFP_PC1_GPIO }},   //23
  {PC, BIT0, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC0_Msk, SYS_MFP_PC0_GPIO }},   //24
  {PA, BIT15, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA15_Msk, SYS_MFP_PA15_GPIO }},//25
  {PA, BIT14, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA14_Msk, SYS_MFP_PA14_GPIO }},//26
  {PA, BIT13, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA13_Msk, SYS_MFP_PA13_GPIO }},//27
  {PA, BIT12, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA12_Msk, SYS_MFP_PA12_GPIO }},//28
#if USE_ICE == 0
  {PF, BIT7, {(uint32_t)&SYS->PE_MFP, SYS_MFP_PF7_Msk, SYS_MFP_PF7_GPIO }},   //29
  {PF, BIT6, {(uint32_t)&SYS->PE_MFP, SYS_MFP_PF6_Msk, SYS_MFP_PF6_GPIO }},   //30
#else
  {NULL, NULL, {NULL, NULL, NULL}},   // 29
  {NULL, NULL, {NULL, NULL, NULL}},   // 30
#endif
  /*    		AVSS              */{NULL, NULL, {NULL, NULL, NULL}},         //31
  {PA, BIT0, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA0_Msk, SYS_MFP_PA0_GPIO }},   //32
  {PA, BIT1, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA1_Msk, SYS_MFP_PA1_GPIO }},   //33
  {PA, BIT2, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA2_Msk, SYS_MFP_PA2_GPIO }},   //34
  {PA, BIT3, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA3_Msk, SYS_MFP_PA3_GPIO }},   //35
  {PA, BIT4, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA4_Msk, SYS_MFP_PA4_GPIO }},   //36
  {PA, BIT5, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA5_Msk, SYS_MFP_PA5_GPIO }},   //37
  {PA, BIT6, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA6_Msk, SYS_MFP_PA6_GPIO }},   //38
  {PA, BIT7, {(uint32_t)&SYS->PA_MFP, SYS_MFP_PA7_Msk, SYS_MFP_PA7_GPIO }},   //39
  /*          AVDD             */{NULL, NULL, {NULL, NULL, NULL}},            //40
  {PC, BIT7, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC7_Msk, SYS_MFP_PC7_GPIO }},   //41
  {PC, BIT6, {(uint32_t)&SYS->PC_MFP, SYS_MFP_PC6_Msk, SYS_MFP_PC6_GPIO }},   //42
  {PB, BIT15, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB15_Msk, SYS_MFP_PB15_GPIO }},//43
  /*    		XTAL2            */{NULL, NULL, {NULL, NULL, NULL}},          //44
  /*    		XTAL1            */{NULL, NULL, {NULL, NULL, NULL}},          //45
  /*nRST*/{NULL, NULL, {NULL, NULL, NULL}},                                   //46 
  {PF, BIT8, {(uint32_t)&SYS->PE_MFP, SYS_MFP_PF8_Msk, SYS_MFP_PF8_GPIO }},   //47
  {PB, BIT8, {(uint32_t)&SYS->PB_MFP, SYS_MFP_PB8_Msk, SYS_MFP_PB8_GPIO }},   //48
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
	I2C,I2C_MODULE,
    {{PD_4,SYS_MFP_PD4_SDA},{PD_5, SYS_MFP_PD5_SCL},}
  },
};
#endif

#ifndef PPORT_DESC_USERDEF
const GPIOPortDescription  PORT_Desc[]=
{
	{PA,/*0xff, */ (uint32_t)&SYS->PA_MFP,SYS_PA_MFP_PA_ALT_Pos,SYS_PA_MFP_PA_TYPE_Pos},  
	{PB,/*0xff, */ (uint32_t)&SYS->PB_MFP,SYS_PB_MFP_PB_ALT_Pos,SYS_PB_MFP_PB_TYPE_Pos}, 
	{PC,/*0xff, */ (uint32_t)&SYS->PC_MFP,SYS_PC_MFP_PC_ALT_Pos,SYS_PC_MFP_PC_TYPE_Pos}, 
	{PD,/*0xff, */ (uint32_t)&SYS->PD_MFP,SYS_PD_MFP_PD_ALT_Pos,SYS_PD_MFP_PD_TYPE_Pos}, 
	{PE,/*0xff, */ (uint32_t)&SYS->PE_MFP,SYS_PE_MFP_PE_ALT_Pos,SYS_PE_MFP_PE_TYPE_Pos},  
	{P5,/*0xff, */ (uint32_t)&SYS->P5_MFP,SYS_P5_MFP_P5_ALT_Pos,SYS_P5_MFP_P5_TYPE_Pos},  
};
#endif
