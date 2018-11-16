/*
  Copyright (c) 2018 huaweiwx@sina.com 2018.7.1

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

/* as arduino avr */
#ifndef _PINNAME_LEGACY_H_
#define _PINNAME_LEGACY_H_

#if defined(P00) 
	#define PA0  P00
	#define PA1  P01
	#define PA2  P02
	#define PA3  P03
	#define PA4  P04
	#define PA5  P05
	#define PA6  P06
	#define PA7  P07
	#define PA_0 P0_0
	#define PA_1 P0_1
	#define PA_2 P0_2
	#define PA_3 P0_3
	#define PA_4 P0_4
	#define PA_5 P0_5
	#define PA_6 P0_6
	#define PA_7 P0_7
#elif defined(PA0) 
	#define P00  PA0
	#define P01  PA1
	#define P02  PA2
	#define P03  PA3
	#define P04  PA4
	#define P05  PA5
	#define P06  PA6
	#define P07  PA7
	#define P0_0 PA_0
	#define P0_1 PA_1
	#define P0_2 PA_2
	#define P0_3 PA_3
	#define P0_4 PA_4
	#define P0_5 PA_5
	#define P0_6 PA_6
	#define P0_7 PA_7
	#define P0_8 PA_8
	#define P0_9 PA_9
	#define P0_10 PA_10
	#define P0_11 PA_11
	#define P0_12 PA_12
	#define P0_13 PA_13
	#define P0_14 PA_14
	#define P0_15 PA_15
#endif

#if defined(P10) 
	#define PB0  P10
	#define PB1  P11
	#define PB2  P12
	#define PB3  P13
	#define PB4  P14
	#define PB5  P15
	#define PB6  P16
	#define PB7  P17
	#define PB_0 P1_0
	#define PB_1 P1_1
	#define PB_2 P1_2
	#define PB_3 P1_3
	#define PB_4 P1_4
	#define PB_5 P1_5
	#define PB_6 P1_6
	#define PB_7 P1_7
#elif defined(PB0) 
	#define P10  PB0
	#define P11  PB1
	#define P12  PB2
	#define P13  PB3
	#define P14  PB4
	#define P15  PB5
	#define P16  PB6
	#define P17  PB7
	#define P1_0 PB_0
	#define P1_1 PB_1
	#define P1_2 PB_2
	#define P1_3 PB_3
	#define P1_4 PB_4
	#define P1_5 PB_5
	#define P1_6 PB_6
	#define P1_7 PB_7
	#define P1_8  PB_8
	#define P1_9  PB_9
	#define P1_10 PB_10
	#define P1_11 PB_11
	#define P1_12 PB_12
	#define P1_13 PB_13
	#define P1_14 PB_14
	#define P1_15 PB_15
#endif

#if defined(P20) 
	#define PC0  P20
	#define PC1  P21
	#define PC2  P22
	#define PC3  P23
	#define PC4  P24
	#define PC5  P25
	#define PC6  P26
	#define PC7  P27
	#define PC_0 P2_0
	#define PC_1 P2_1
	#define PC_2 P2_2
	#define PC_3 P2_3
	#define PC_4 P2_4
	#define PC_5 P2_5
	#define PC_6 P2_6
	#define PC_7 P2_7
#elif defined(PC0) 
	#define P20  PC0
	#define P21  PC1
	#define P22  PC2
	#define P23  PC3
	#define P24  PC4
	#define P25  PC5
	#define P26  PC6
	#define P27  PC7
	#define P2_0 PC_0
	#define P2_1 PC_1
	#define P2_2 PC_2
	#define P2_3 PC_3
	#define P2_4 PC_4
	#define P2_5 PC_5
	#define P2_6 PC_6
	#define P2_7 PC_7
	#define P2_8  PC_8
	#define P2_9  PC_9
	#define P2_10 PC_10
	#define P2_11 PC_11
	#define P2_12 PC_12
	#define P2_13 PC_13
	#define P2_14 PC_14
	#define P2_15 PC_15
#endif

#if defined(P30) 
	#define PD0  P30
	#define PD1  P31
	#define PD2  P32
	#define PD3  P33
	#define PD4  P34
	#define PD5  P35
	#define PD6  P36
	#define PD7  P37
	#define PD_0 P3_0
	#define PD_1 P3_1
	#define PD_2 P3_2
	#define PD_3 P3_3
	#define PD_4 P3_4
	#define PD_5 P3_5
	#define PD_6 P3_6
	#define PD_7 P3_7
#elif defined(PD0) 
	#define P00  PD0
	#define P31  PD1
	#define P32  PD2
	#define P33  PD3
	#define P34  PD4
	#define P35  PD5
	#define P36  PD6
	#define P37  PD7
	#define P0_0 PD_0
	#define P3_1 PD_1
	#define P3_2 PD_2
	#define P3_3 PD_3
	#define P3_4 PD_4
	#define P3_5 PD_5
	#define P3_6 PD_6
	#define P3_7 PD_7
	#define P3_8  PD_8
	#define P3_9  PD_9
	#define P3_10 PD_10
	#define P3_11 PD_11
	#define P3_12 PD_12
	#define P3_13 PD_13
	#define P3_14 PD_14
	#define P3_15 PD_15
#endif

#if defined(P40) 
	#define PE0    P40
	#define PE1    P41
	#define PE2    P42
	#define PE3    P43
	#define PE4    P44
	#define PE5    P45
	#define PE6    P46
	#define PE7    P47
	#define PE_0   P4_0
	#define PE_1   P4_1
	#define PE_2   P4_2
	#define PE_3   P4_3
	#define PE_4   P4_4
	#define PE_5   P4_5
	#define PE_6   P4_6
	#define PE_7   P4_7
#elif defined(PE0) 
	#define P40    PE0
	#define P41    PE1
	#define P42    PE2
	#define P43    PE3
	#define P44    PE4
	#define P45    PE5
	#define P46    PE6
	#define P47    PE7
	#define P4_0   PE_0
	#define P4_1   PE_1
	#define P4_2   PE_2
	#define P4_3   PE_3
	#define P4_4   PE_4
	#define P4_5   PE_5
	#define P4_6   PE_6
	#define P4_7   PE_7
	#define P4_8   PE_8
	#define P4_9   PE_9
	#define P4_10  PE_10
	#define P4_11  PE_11
	#define P4_12  PE_12
	#define P4_13  PE_13
	#define P4_14  PE_14
	#define P4_15  PE_15
#endif

#if defined(P50) 
	#define PF0    P50
	#define PF1    P51
	#define PF2    P52
	#define PF3    P53
	#define PF4    P54
	#define PF5    P55
	#define PF6    P56
	#define PF7    P57
	#define PF_0   P5_0
	#define PF_1   P5_1
	#define PF_2   P5_2
	#define PF_3   P5_3
	#define PF_4   P5_4
	#define PF_5   P5_5
	#define PF_6   P5_6
	#define PF_7   P5_7
#elif defined(PF0) 
	#define P50    PF0
	#define P51    PF1
	#define P52    PF2
	#define P53    PF3
	#define P54    PF4
	#define P55    PF5
	#define P56    PF6
	#define P5_0   PF_0
	#define P5_1   PF_1
	#define P5_2   PF_2
	#define P5_3   PF_3
	#define P5_4   PF_4
	#define P5_5   PF_5
	#define P5_6   PF_6
	#define P5_7   PF_7
	#define P5_8   PF_8
	#define P5_9   PF_9
	#define P5_10  PF_10
	#define P5_11  PF_11
	#define P5_12  PF_12
	#define P5_13  PF_13
	#define P5_14  PF_14
	#define P5_15  PF_15
#endif 

#if defined(P60) 
	#define PG0  P60
	#define PG1  P61
	#define PG2  P62
	#define PG3  P63
	#define PG4  P64
	#define PG5  P65
	#define PG6  P66
	#define PG7  P67
	#define PG_0 P6_0
	#define PG_1 P6_1
	#define PG_2 P6_2
	#define PG_3 P6_3
	#define PG_4 P6_4
	#define PG_5 P6_5
	#define PG_6 P6_6
	#define PG_7 P6_7
#elif defined(PG0) 
	#define P60    PG0
	#define P61    PG1
	#define P62    PG2
	#define P63    PG3
	#define P64    PG4
	#define P65    PG5
	#define P66    PG6
	#define P67    PG7
	#define P6_0   PG_0
	#define P6_1   PG_1
	#define P6_2   PG_2
	#define P6_3   PG_3
	#define P6_4   PG_4
	#define P6_5   PG_5
	#define P6_6   PG_6
	#define P6_7   PG_7
	#define P6_8   PG_8
	#define P6_9   PG_9
	#define P6_10  PG_10
	#define P6_11  PG_11
	#define P6_12  PG_12
	#define P6_13  PG_13
	#define P6_14  PG_14
	#define P6_15  PG_15
#endif 

#if defined(P70) 
	#define PH0  P70
	#define PH1  P71
	#define PH2  P72
	#define PH3  P73
	#define PH4  P74
	#define PH5  P75
	#define PH6  P76
	#define PH7  P77
	#define PH_0 P7_0
	#define PH_1 P7_1
	#define PH_2 P7_2
	#define PH_3 P7_3
	#define PH_4 P7_4
	#define PH_5 P7_5
	#define PH_6 P7_6
	#define PH_7 P7_7
#elif defined(PH0) 
	#define P70    PH0
	#define P71    PH1
	#define P72    PH2
	#define P73    PH3
	#define P74    PH4
	#define P75    PH5
	#define P76    PH6
	#define P77    PH7
	#define P7_0   PH_0
	#define P7_1   PH_1
	#define P7_2   PH_2
	#define P7_3   PH_3
	#define P7_4   PH_4
	#define P7_5   PH_5
	#define P7_6   PH_6
	#define P7_7   PH_7
	#define P7_8   PH_8
	#define P7_9   PH_9
	#define P7_10  PH_10
	#define P7_11  PH_11
	#define P7_12  PH_12
	#define P7_13  PH_13
	#define P7_14  PH_14
	#define P7_15  PH_15
#endif 

#endif /*_PINNAME_LEGACY_H_*/
