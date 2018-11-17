
#ifndef GPIO_DESC_USERDEF
const GPIOPinDescription GPIO_Desc[] =
{
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 0
  {P1, BIT0, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P10_Msk, SYS_MFP_P10_GPIO }},   // 1
  {P1, BIT4, {(uint32_t)&SYS->P1_MFP, SYS_MFP_P14_Msk, SYS_MFP_P14_GPIO}},    // 2
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 3
  {P3, BIT0, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P30_Msk, SYS_MFP_P30_GPIO }},   // 4
  {NULL, NULL, {NULL, NULL, NULL}},                                           // 5
  {P3, BIT1, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P31_Msk, SYS_MFP_P31_GPIO }},   // 6
  {P3, BIT4, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P34_Msk, SYS_MFP_P34_GPIO }},   // 7
  {P3, BIT5, {(uint32_t)&SYS->P3_MFP, SYS_MFP_P35_Msk, SYS_MFP_P35_GPIO }},   // 8
  {P7, BIT0, {(uint32_t)&SYS->P7_MFP, SYS_MFP_P70_Msk, SYS_MFP_P70_GPIO }},   // 9
  {P7, BIT1, {(uint32_t)&SYS->P7_MFP, SYS_MFP_P71_Msk, SYS_MFP_P71_GPIO }},   //10
  {NULL, NULL, {NULL, NULL, NULL}},                                           //11                               //15
  {NULL, NULL, {NULL, NULL, NULL}}, 										  //12	     	 	    //17
  {P2, BIT3, {(uint32_t)&SYS->P2_MFP, SYS_MFP_P23_Msk, SYS_MFP_P23_GPIO }},   //13
#if USE_ICE == 0
  {P4, BIT6, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P46_Msk, SYS_MFP_P46_GPIO }},   //14
  {P4, BIT7, {(uint32_t)&SYS->P4_MFP, SYS_MFP_P47_Msk, SYS_MFP_P47_GPIO }},   //15
#else
  {NULL, NULL, {NULL, NULL, NULL}},   //14													//30
  {NULL, NULL, {NULL, NULL, NULL}},   //15
#endif
  {P0, BIT7, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P07_Msk, SYS_MFP_P07_GPIO }},   //16
  {P0, BIT6, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P06_Msk, SYS_MFP_P06_GPIO }},   //17
  {P0, BIT5, {(uint32_t)&SYS->P0_MFP, SYS_MFP_P05_Msk, SYS_MFP_P05_GPIO }},   //18
};
#endif

#ifndef PWM_DESC_USERDEF
const PWMPinDescription PWM_Desc[]={
//	{PWMA,PWM01_MODULE,PWMA_IRQn,0,500,{P2_0,SYS_MFP_P20_PWM0}},  //0
//	{PWMA,PWM01_MODULE,PWMA_IRQn,1,500,{P2_1,SYS_MFP_P21_PWM1}},  //1  
//	{PWMA,PWM23_MODULE,PWMA_IRQn,2,500,{P2_2,SYS_MFP_P22_PWM2}},  //2  
	{PWMA,PWM23_MODULE,PWMA_IRQn,3,500,{P2_3,SYS_MFP_P23_PWM3}},  //3  
};
#endif

#ifndef ADC_DESC_USERDEF
const ADCPinDescription ADC_Desc[]={
	{ADC,ADC_MODULE,0,{P1_0,SYS_MFP_P10_AIN0}},   	//0 
//	{ADC,ADC_MODULE,1,{P1_1,SYS_MFP_P11_AIN1}},		//1
//	{ADC,ADC_MODULE,2,{P1_2,SYS_MFP_P12_AIN2}},		//2
//	{ADC,ADC_MODULE,3,{P1_3,SYS_MFP_P13_AIN3}},		//3
	{ADC,ADC_MODULE,4,{P1_4,SYS_MFP_P14_AIN4}},		//4
//	{ADC,ADC_MODULE,5,{P1_5,SYS_MFP_P15_AIN5}},		//5	
//	{ADC,ADC_MODULE,6,{P1_6,SYS_MFP_P16_AIN6}},		//6
//	{ADC,ADC_MODULE,7,{P1_7,SYS_MFP_P17_AIN7}},		//7	
};
#endif

#ifndef UART_DESC_USERDEF
const UARTPinDescription UART_Desc[]={
   {UART0,UART0_MODULE,UART0_IRQn,{{P3_0,SYS_MFP_P30_RXD}, {P3_1,SYS_MFP_P31_TXD} }},	
//   {UART0,UART0_MODULE,UART0_IRQn,{{P0_3,SYS_MFP_P03_RXD}, {P0_2,SYS_MFP_P02_TXD} }},	
};
#endif

#ifndef SPI_DESC_USERDEF
const SPIPinDescription SPI_Desc[]={
//    {
//	 SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL1_SPI0_S_HCLK,
// 	 {{P1_7,SYS_MFP_P17_SPICLK},{P1_6,SYS_MFP_P16_MISO},{P1_5,SYS_MFP_P15_MOSI}, {P1_4,SYS_MFP_P14_SPISS}, }
//	},
	{
	 SPI0,SPI0_MODULE,SPI0_IRQn,CLK_CLKSEL1_SPI0_S_HCLK,
	 {{P0_7,SYS_MFP_P07_SPICLK},{P0_6,SYS_MFP_P06_MISO},{P0_5,SYS_MFP_P05_MOSI}, {P1_4,SYS_MFP_P14_SPISS}, }
	},
};
#endif

#ifndef I2C_DESC_USERDEF
const I2CPinDescription I2C_Desc[]={	
  {
	I2C0,I2C0_MODULE,
    {{P3_4,SYS_MFP_P34_SDA0},{P3_5, SYS_MFP_P35_SCL0},}
  },
//  {
//	I2C0,I2C0_MODULE,
 //   {{P5_2,SYS_MFP_P52_SDA0},{P5_3, SYS_MFP_P53_SCL0},}
//  },
//  {
//	I2C1,I2C1_MODULE,
//    {{P4_5,SYS_MFP_P45_SDA1},{P4_4, SYS_MFP_P44_SCL1},}
//  },
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
	{P7,/*0xff, */ (uint32_t)&SYS->P7_MFP,                    0,SYS_P7_MFP_P7_TYPE_Pos},  
};
#endif
