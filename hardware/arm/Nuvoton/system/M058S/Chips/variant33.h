
#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 0
  {P1, BIT5, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P15_Msk, SYS_MFP_P15_GPIO }},   // 1
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 2
  {P3, BIT0, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P30_Msk, SYS_MFP_P30_GPIO }},   // 3
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 4
  {P3, BIT1, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P31_Msk, SYS_MFP_P31_GPIO }},   // 5
  {P3, BIT2, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P32_Msk, SYS_MFP_P32_GPIO }},   // 6
  {P3, BIT4, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P34_Msk, SYS_MFP_P34_GPIO }},   // 7
  {P3, BIT5, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P35_Msk, SYS_MFP_P35_GPIO }},   // 8
  {P3, BIT6, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P36_Msk, SYS_MFP_P36_GPIO }},   // 9
  {NULL, NULL, {NULL, NULL, NULL}},                                           //10                                //15
  {NULL, NULL, {NULL, NULL, NULL}},                                           //11                  //16
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //12	     	 	    //17
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //13	     	 	    //18
  {P2, BIT2, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P22_Msk, SYS_MFP_P22_GPIO }},   //14
  {P2, BIT3, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P23_Msk, SYS_MFP_P23_GPIO }},   //15
  {P2, BIT4, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P24_Msk, SYS_MFP_P24_GPIO }},   //16
  {P2, BIT5, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P25_Msk, SYS_MFP_P25_GPIO }},   //17
  {P2, BIT6, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P26_Msk, SYS_MFP_P26_GPIO }},   //18
#if USE_ICE == 0
  {P4, BIT6, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P46_Msk, SYS_MFP_P46_GPIO }},   //19
  {P4, BIT7, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P47_Msk, SYS_MFP_P47_GPIO }},   //20
#else
  {NULL, NULL, {NULL, NULL, NULL}},   //19													//30
  {NULL, NULL, {NULL, NULL, NULL}},   //20
#endif
  {P0, BIT7, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P07_Msk, SYS_MFP_P07_GPIO }},   //21
  {P0, BIT6, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P06_Msk, SYS_MFP_P06_GPIO }},   //22
  {P0, BIT5, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P05_Msk, SYS_MFP_P05_GPIO }},   //23
  {P0, BIT4, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P04_Msk, SYS_MFP_P04_GPIO }},   //24
  {P0, BIT1, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P01_Msk, SYS_MFP_P01_GPIO }},   //25
  {P0, BIT0, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P00_Msk, SYS_MFP_P00_GPIO }},   //26
  {NULL, NULL, {NULL, NULL, NULL}}, 															//41
  {NULL, NULL, {NULL, NULL, NULL}}, 															//42
  {P1, BIT0, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P10_Msk, SYS_MFP_P10_GPIO }},   //29
  {P1, BIT2, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P12_Msk, SYS_MFP_P12_GPIO}},    //30
  {P1, BIT3, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P13_Msk, SYS_MFP_P13_GPIO}},    //31
  {P1, BIT4, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P14_Msk, SYS_MFP_P14_GPIO}},    //32
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWMA,PWM23_MODULE,PWMA_IRQn,2,500,{P2_2,SYS_MFP_P22_PWM2}},  //2  
	{PWMA,PWM23_MODULE,PWMA_IRQn,3,500,{P2_3,SYS_MFP_P23_PWM3}},  //3  
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
	{ADC,ADC_MODULE,0,{P1_0,SYS_MFP_P10_AIN0}},   	//0 
	{ADC,ADC_MODULE,2,{P1_2,SYS_MFP_P12_AIN2}},		//2
	{ADC,ADC_MODULE,3,{P1_3,SYS_MFP_P13_AIN3}},		//3
	{ADC,ADC_MODULE,4,{P1_4,SYS_MFP_P14_AIN4}},		//4
	{ADC,ADC_MODULE,5,{P1_5,SYS_MFP_P15_AIN5}},		//5	
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
   {{P3_0,SYS_MFP_P30_RXD}, {P3_1,SYS_MFP_P31_TXD}},	
};
const UARTPinDescription UART_Desc[]={
   {UART0,UART0_MODULE,UART0_IRQn,UART0PinAlt},	
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = {
   {{P0_7,SYS_MFP_P07_SPICLK},{P0_6,SYS_MFP_P06_MISO},{P0_5,SYS_MFP_P05_MOSI}, {P1_4,SYS_MFP_P14_SPISS}},
};
const SPIPinDescription SPI_Desc[]={
  {SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL1_SPI0_S_HCLK,SPI0PinAlt},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
  {{P3_4,SYS_MFP_P34_SDA0},{P3_5, SYS_MFP_P35_SCL0}}
};
const I2CPinDescription I2C_Desc[]={	
  {I2C0,I2C0_MODULE,I2C0PinAlt},
};
#endif

#ifndef PORT_DESC_USERDEF
const GPIOPortDescription  PORT_Desc[]=
{
	{P0,/*0xff, */ (uint32_t)&SYS->P0_MFP,SYS_P0_MFP_P0_ALT_Pos,SYS_P0_MFP_P0_TYPE_Pos}, 
	{P1,/*0xff, */ (uint32_t)&SYS->P1_MFP,SYS_P1_MFP_P1_ALT_Pos,SYS_P1_MFP_P1_TYPE_Pos}, 
	{P2,/*0xff, */ (uint32_t)&SYS->P2_MFP,SYS_P2_MFP_P2_ALT_Pos,SYS_P2_MFP_P2_TYPE_Pos}, 
	{P3,/*0xff, */ (uint32_t)&SYS->P3_MFP,SYS_P3_MFP_P3_ALT_Pos,SYS_P3_MFP_P3_TYPE_Pos}, 
	{P4,/*0xff, */ (uint32_t)&SYS->P4_MFP,SYS_P4_MFP_P4_ALT_Pos,SYS_P4_MFP_P4_TYPE_Pos}, 
};
#endif
