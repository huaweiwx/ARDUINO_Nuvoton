
#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 0
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 1
  {P1, BIT5, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P15_Msk, SYS_MFP_P15_GPIO }},   // 2
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 3
  {P3, BIT0, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P30_Msk, SYS_MFP_P30_GPIO }},   // 4
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 5
  {P5, BIT4, {(uint32_t)&SYS->P5_MFP, SYS_MFP_P54_Msk, SYS_MFP_P54_GPIO }},   // 6
  {P3, BIT1, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P31_Msk, SYS_MFP_P31_GPIO }},   // 7
  {P3, BIT2, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P32_Msk, SYS_MFP_P32_GPIO }},   // 8
  {P3, BIT4, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P34_Msk, SYS_MFP_P34_GPIO }},   // 9
  {P3, BIT5, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P35_Msk, SYS_MFP_P35_GPIO }},   //10
  {NULL, NULL, {NULL, NULL, NULL}},                                           //11
  {NULL, NULL, {NULL, NULL, NULL}},                                           //12
  {NULL, NULL, {NULL, NULL, NULL}}, 									      //13
  {P3, BIT6, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P36_Msk, SYS_MFP_P36_GPIO }},   //14
  {P5, BIT1, {(uint32_t)&SYS->P5_MFP, SYS_MFP_P51_Msk, SYS_MFP_P51_GPIO }},   //15
  {P5, BIT0, {(uint32_t)&SYS->P5_MFP, SYS_MFP_P50_Msk, SYS_MFP_P50_GPIO }},   //16
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //17
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //18
  {P5, BIT5, {(uint32_t)&SYS->P5_MFP, SYS_MFP_P55_Msk, SYS_MFP_P55_GPIO }},   //19
  {P5, BIT2, {(uint32_t)&SYS->P5_MFP, SYS_MFP_P52_Msk, SYS_MFP_P52_GPIO }},   //20
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //21
  {P2, BIT2, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P22_Msk, SYS_MFP_P22_GPIO }},   //22
  {P2, BIT3, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P23_Msk, SYS_MFP_P23_GPIO }},   //23
  {P2, BIT4, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P24_Msk, SYS_MFP_P24_GPIO }},   //24
  {P2, BIT5, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P25_Msk, SYS_MFP_P25_GPIO }},   //25
  {P2, BIT6, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P26_Msk, SYS_MFP_P26_GPIO }},   //26
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //27
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //28
#if USE_ICE == 0
  {P4, BIT6, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P46_Msk, SYS_MFP_P46_GPIO }},   //29
  {P4, BIT7, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P47_Msk, SYS_MFP_P47_GPIO }},   //30
#else
  {NULL, NULL, {NULL, NULL, NULL}},   //29
  {NULL, NULL, {NULL, NULL, NULL}},   //30
#endif
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //31
  {P0, BIT7, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P07_Msk, SYS_MFP_P07_GPIO }},   //32
  {P0, BIT6, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P06_Msk, SYS_MFP_P06_GPIO }},   //33
  {P0, BIT5, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P05_Msk, SYS_MFP_P05_GPIO }},   //34
  {P0, BIT4, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P04_Msk, SYS_MFP_P04_GPIO }},   //35
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //36
  {P0, BIT1, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P01_Msk, SYS_MFP_P01_GPIO }},   //37
  {P0, BIT0, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P00_Msk, SYS_MFP_P00_GPIO }},   //38
  {NULL, NULL, {NULL, NULL, NULL}}, 						  				  //39
  {NULL, NULL, {NULL, NULL, NULL}}, 						  				  //40
  {P5, BIT3, {(uint32_t)&SYS->P5_MFP, SYS_MFP_P53_Msk, SYS_MFP_P53_GPIO }},   //41
  {NULL, NULL, {NULL, NULL, NULL}}, 						  				  //42
  {NULL, NULL, {NULL, NULL, NULL}}, 						  				  //43
  {P1, BIT0, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P10_Msk, SYS_MFP_P10_GPIO }},   //44
  {P1, BIT2, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P12_Msk, SYS_MFP_P12_GPIO}},    //45
  {P1, BIT3, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P13_Msk, SYS_MFP_P13_GPIO}},    //46
  {P1, BIT4, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P14_Msk, SYS_MFP_P14_GPIO}},    //47
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
	{PWM,PWM01_MODULE,PWM_IRQn,0,500,{P2_2,SYS_MFP_P22_PWM0}},  //3  
	{PWM,PWM01_MODULE,PWM_IRQn,1,500,{P2_3,SYS_MFP_P23_PWM1}},  //3  
	{PWM,PWM23_MODULE,PWM_IRQn,2,500,{P2_4,SYS_MFP_P24_PWM2}},  //4 	
	{PWM,PWM23_MODULE,PWM_IRQn,3,500,{P2_5,SYS_MFP_P25_PWM3}},  //4 	
	{PWM,PWM45_MODULE,PWM_IRQn,4,500,{P2_6,SYS_MFP_P26_PWM4}},  //4 	
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
	{ADC,ADC_MODULE,0,{P5_3,SYS_MFP_P53_AIN0}},   	//0 
	{ADC,ADC_MODULE,1,{P1_0,SYS_MFP_P10_AIN1}},   	//1 
	{ADC,ADC_MODULE,2,{P1_2,SYS_MFP_P12_AIN2}},		//2
	{ADC,ADC_MODULE,3,{P1_3,SYS_MFP_P13_AIN3}},		//3
	{ADC,ADC_MODULE,4,{P1_4,SYS_MFP_P14_AIN4}},		//4
	{ADC,ADC_MODULE,5,{P1_5,SYS_MFP_P15_AIN5}},		//5	
	{ADC,ADC_MODULE,6,{P3_0,SYS_MFP_P30_AIN6}},   	//6 
	{ADC,ADC_MODULE,7,{P3_1,SYS_MFP_P31_AIN7}},   	//7 
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinAlt_TypeDef UART0PinAlt[] = {
   {{P0_1,SYS_MFP_P01_RXD}, {P0_0,SYS_MFP_P00_TXD}},	//Loc 0
   {{P1_2,SYS_MFP_P12_RXD}, {P1_3,SYS_MFP_P13_TXD}},	//Loc 1
};
const UARTPinDescription UART_Desc[]={
   {UART,UART_MODULE,UART_IRQn,UART0PinAlt},	
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinAlt_TypeDef SPI0PinAlt[] = { 
	  {{P0_7,SYS_MFP_P07_SPICLK},{P0_6,SYS_MFP_P06_MISO},{P0_5,SYS_MFP_P05_MOSI}, {P0_4,SYS_MFP_P04_SPISS}},
};
const SPIPinDescription SPI_Desc[]={
  {SPI,SPI_MODULE,SPI_IRQn,CLK_CLKSEL1_SPI_S_HCLK, SPI0PinAlt},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinAlt_TypeDef I2C0PinAlt[] = {
 {{P3_4,SYS_MFP_P34_SDA},{P3_5, SYS_MFP_P35_SCL}},
};
const I2CPinDescription I2C_Desc[]={	
 {I2C,I2C_MODULE,I2C0PinAlt},
};
#endif

#ifndef PORT_DESC_USERDEF
const GPIOPortDescription PORT_Desc[]={
	{P0,0b11111111,(uint32_t)&SYS->P0_MFP,SYS_P0_MFP_P0_MFP_Pos,SYS_P0_MFP_P0_MFP_Msk,}, 
	{P1,0b00111111,(uint32_t)&SYS->P1_MFP,SYS_P1_MFP_P1_MFP_Pos,SYS_P1_MFP_P1_MFP_Msk,}, 
	{P2,0b01111100,(uint32_t)&SYS->P2_MFP,SYS_P2_MFP_P2_MFP_Pos,SYS_P2_MFP_P2_MFP_Msk,}, 
	{P3,0b01111111,(uint32_t)&SYS->P3_MFP,SYS_P3_MFP_P3_MFP_Pos,SYS_P3_MFP_P3_MFP_Msk,}, 
	{P4,0b11000000,(uint32_t)&SYS->P4_MFP,SYS_P4_MFP_P4_MFP_Pos,SYS_P4_MFP_P4_MFP_Msk,}, 
	{P5,0b00111111,(uint32_t)&SYS->P5_MFP,SYS_P5_MFP_P5_MFP_Pos,SYS_P5_MFP_P5_MFP_Msk,}, 
};
#endif
