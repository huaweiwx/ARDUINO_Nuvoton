/*
  stm32flash - Open Source ST STM32 flash program for *nix
  Copyright (C) 2010 Geoffrey McRae <geoff@spacevs.com>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  
  for arduino modify by huaweiwx@sina.com 2017.10
*/


#ifndef _DEVTABLE_H_
#define _DEVTABLE_H_

// #define USE_STM32NAME 

typedef enum {
	F_NO_ME = 1 << 0,	/* Mass-Erase not supported */
	F_OBLL  = 1 << 1,	/* OBL_LAUNCH required */
} flags_t;

typedef struct stm32_dev	stm32_dev_t;

struct stm32_dev {
	uint16_t	id;
#ifdef USE_STM32NAME
	const char	*name;
#endif	
	uint32_t	ram_start, ram_end;
	uint32_t	fl_start, fl_end;
	uint16_t	fl_pps; // pages per sector
	uint32_t	*fl_ps;  // page size
	uint32_t	opt_start, opt_end;
	uint32_t	mem_start, mem_end;
	uint32_t	flags;
};


typedef struct chipInfo chipInfo_t;

struct chipInfo {
	uint32_t	ramEnd;
	uint32_t	flashEnd;
	uint16_t	flashPPS; // pages per sector
	uint32_t	*flashPS;  // page size
	uint32_t	optStart, optEnd;
	uint32_t	sysMemStart, sysMemEnd;
	uint32_t	flags;
};

extern const chipInfo_t *pChipInfo;

//extern const stm32_dev_t devices;

#ifdef __cplusplus
extern "C" {
#endif

stm32_dev_t* UTIL_getStmDev(uint16_t id);


#ifdef __cplusplus
} //exter "C" {
#endif



#if defined(STM32F030C6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444
  
#elif defined(STM32F030C8)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F030CC)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F030F4)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F030K6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F030R8)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F030RC)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F070C6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445
 
#elif defined(STM32F070CB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F070F6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F070RB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F031C4)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F031C6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F031E6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F031F4)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F031F6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F031G4)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F031G6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F031K4)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F031K6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F051C4)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F051C6)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F051C8)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F051K4)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F051K6)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F051K8)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F051R4)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F051R6)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F051R8)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F051T8)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx 
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F071C8)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx   
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F071CB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx   
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F071RB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx   
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F071V8)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx   
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F071VB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx   
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F091CB)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F091CC)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F091RB)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F091RC)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F091VB)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F091VC)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F042C4)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F042C6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F042F4)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F042F6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F042G4)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F042G6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F042K4)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F042K6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F042T6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F072C8)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F072CB)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F072R8)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F072RB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F072V8)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F072VB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F038C6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F038E6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F038F6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F038G6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F038K6)
  #define CHIP_ID 0x444 //STM32F03xx4/6
  #define CHIP_INFO CHIP_ID444

#elif defined(STM32F048C6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F048G6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F048T6)
  #define CHIP_ID 0x445 //STM32F04xxx/F070x6
  #define CHIP_INFO CHIP_ID445

#elif defined(STM32F058C8)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F058R8)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F058T8)
  #define CHIP_ID 0x440 //STM32F030x8/F05xxx
  #define CHIP_INFO CHIP_ID440

#elif defined(STM32F078CB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F078RB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F078VB)
  #define CHIP_ID 0x448 //STM32F070xB/F071xx/F72xx
  #define CHIP_INFO CHIP_ID448

#elif defined(STM32F098CC)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F098RC)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F098VC)
  #define CHIP_ID 0x442 //STM32F030xC/F09xxx  
  #define CHIP_INFO CHIP_ID442

#elif defined(STM32F100C4)
  #define CHIP_ID 0x412  //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F100C6)
  #define CHIP_ID 0x412  //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F100C8)
  #define CHIP_ID 0x420 //STM32F10xxx Medium-density VL
  #define CHIP_INFO CHIP_ID420

#elif defined(STM32F100CB)
  #define CHIP_ID 0x420 //STM32F10xxx Medium-density VL
  #define CHIP_INFO CHIP_ID420

#elif defined(STM32F100R4)
  #define CHIP_ID 0x412  //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F100R6)
  #define CHIP_ID 0x412  //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F100R8)
  #define CHIP_ID 0x420 //STM32F10xxx Medium-density VL
  #define CHIP_INFO CHIP_ID420

#elif defined(STM32F100RB)
  #define CHIP_ID 0x420 //STM32F10xxx Medium-density VL
  #define CHIP_INFO CHIP_ID420

#elif defined(STM32F100RC)
  #define CHIP_ID 0x428 //STM32F10xxx High-density VL
  #define CHIP_INFO CHIP_ID428

#elif defined(STM32F100RD)
  #define CHIP_ID 0x428 //STM32F10xxx High-density VL
  #define CHIP_INFO CHIP_ID428

#elif defined(STM32F100RE)
  #define CHIP_ID 0x428 //STM32F10xxx High-density VL
  #define CHIP_INFO CHIP_ID428

#elif defined(STM32F100V8)
  #define CHIP_ID 0x420 //STM32F10xxx Medium-density VL
  #define CHIP_INFO CHIP_ID420

#elif defined(STM32F100VB)
  #define CHIP_ID 0x420 //STM32F10xxx Medium-density VL
  #define CHIP_INFO CHIP_ID420

#elif defined(STM32F100VC)
  #define CHIP_ID 0x428 //STM32F10xxx High-density VL
  #define CHIP_INFO CHIP_ID428

#elif defined(STM32F100VD)
  #define CHIP_ID 0x428 //STM32F10xxx High-density VL
  #define CHIP_INFO CHIP_ID428

#elif defined(STM32F100VE)
  #define CHIP_ID 0x428 //STM32F10xxx High-density VL
  #define CHIP_INFO CHIP_ID428

#elif defined(STM32F100ZC)
  #define CHIP_ID 0x428 //STM32F10xxx High-density VL
  #define CHIP_INFO CHIP_ID428

#elif defined(STM32F100ZD)
  #define CHIP_ID 0x428 //STM32F10xxx High-density VL
  #define CHIP_INFO CHIP_ID428

#elif defined(STM32F100ZE)
  #define CHIP_ID 0x428 //STM32F10xxx High-density VL
  #define CHIP_INFO CHIP_ID428

#elif defined(STM32F101C4)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F101C6)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F101C8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F101CB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F101R4)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F101R6)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F101R8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F101RB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F101RC)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101RD)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101RE)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101RF)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101RG)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101T4)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F101T6)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F101T8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F101TB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F101V8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F101VB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F101VC)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101VD)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101VE)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101VF)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101VG)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101ZC)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101ZD)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101ZE)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101ZF)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F101ZG)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F102C4)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F102C6)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F102C8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F102CB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F102R4)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F102R6)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F102R8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F102RB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F103C4)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F103C6)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F103C8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F103CB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F103R4)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F103R6)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F103R8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F103RB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F103RC)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F103RD)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F103RE)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F103RF)
  #define CHIP_ID 0x430 //STM32F10xxx XL-density
  #define CHIP_INFO CHIP_ID430

#elif defined(STM32F103RG)
  #define CHIP_ID 0x430 //STM32F10xxx XL-density
  #define CHIP_INFO CHIP_ID430

#elif defined(STM32F103T4)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F103T6)
  #define CHIP_ID 0x412 //STM32F10xxx Low-density
  #define CHIP_INFO CHIP_ID412

#elif defined(STM32F103T8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F103TB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F103V8)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F103VB)
  #define CHIP_ID 0x410 //STM32F10xxx Medium-density" 
  #define CHIP_INFO CHIP_ID410

#elif defined(STM32F103VC)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F103VD)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F103VE)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F103VF)
  #define CHIP_ID 0x430 //STM32F10xxx XL-density
  #define CHIP_INFO CHIP_ID430

#elif defined(STM32F103VG)
  #define CHIP_ID 0x430 //STM32F10xxx XL-density
  #define CHIP_INFO CHIP_ID430

#elif defined(STM32F103ZC)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F103ZD)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F103ZE)
  #define CHIP_ID 0x414 //STM32F10xxx High-density
  #define CHIP_INFO CHIP_ID414

#elif defined(STM32F103ZF)
  #define CHIP_ID 0x430 //STM32F10xxx XL-density
  #define CHIP_INFO CHIP_ID430

#elif defined(STM32F103ZG)
  #define CHIP_ID 0x430 //STM32F10xxx XL-density
  #define CHIP_INFO CHIP_ID430

#elif defined(STM32F105R8)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F105RB)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F105RC)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F105V8)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F105VB)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F105VC)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F107RB)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F107RC)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F107VB)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F107VC)
  #define CHIP_ID 0x418 //STM32F105xx/F107xx
  #define CHIP_INFO CHIP_ID418

#elif defined(STM32F205RB)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205RC)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205RE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205RF)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205RG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205VB)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205VC)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205VE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205VF)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205VG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205ZC)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205ZE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205ZF)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F205ZG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F215RE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F215RG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F215VE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F215VG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F215ZE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F215ZG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207IC)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207IE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207IF)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207IG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207VC)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207VE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207VF)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207VG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207ZC)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207ZE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207ZF)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F207ZG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F217IE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F217IG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F217VE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F217VG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F217ZE)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F217ZG)
  #define CHIP_ID 0x411  //STM32F2xxxx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F301C6)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F301C8)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F301K6)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F301K8)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F301R6)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F301R8)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F302C6)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F302C8)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID411

#elif defined(STM32F302CB)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F302CC)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422
 
#elif defined(STM32F302K6)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID439

#elif defined(STM32F302K8)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID439

#elif defined(STM32F302R6)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID439

#elif defined(STM32F302R8)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID439

#elif defined(STM32F302RB)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F302RC)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F302RD)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F302RE)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F302VB)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F302VC)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F302VD)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F302VE)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F302ZD)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F302ZE)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F303C6)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F303C8)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F303CB)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F303CC)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F303K6)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F303K8)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F303R6)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F303R8)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F303RB)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F303RC)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F303RD)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F303RE)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F303VB)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F303VC)
  #define CHIP_ID 0x422 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID422

#elif defined(STM32F303VD)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F303VE)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F303ZD)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F303ZE)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F334C4)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F334C6)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F334C8)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F334K4)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F334K6)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F334K8)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F334R6)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F334R8)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F373C8)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F373CB)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F373CC)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F373R8)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F373RB)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F373RC)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F373V8)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F373VB)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F373VC)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F318C8)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID439

#elif defined(STM32F318K8)
  #define CHIP_ID 0x439 //STM32F301xx/F302x4(6/8)/F318xx
  #define CHIP_INFO CHIP_ID439

#elif defined(STM32F328C8)
  #define CHIP_ID 0x438 //STM32F303x4(6/8)/F334xx/F328xx
  #define CHIP_INFO CHIP_ID438

#elif defined(STM32F358CC)
  #define CHIP_ID 0x458 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID458

#elif defined(STM32F358RC)
  #define CHIP_ID 0x458 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID458

#elif defined(STM32F358VC)
  #define CHIP_ID 0x458 //STM32F302xB(C)/F303xB(C)/F358xx
  #define CHIP_INFO CHIP_ID458

#elif defined(STM32F378CC)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F378RC)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F378VC)
  #define CHIP_ID 0x432 //STM32F373xx/F378xx
  #define CHIP_INFO CHIP_ID432

#elif defined(STM32F398VE)
  #define CHIP_ID 0x446 //STM32F302xD(E)/F303xD(E)/F398xx
  #define CHIP_INFO CHIP_ID446

#elif defined(STM32F401CB)
  #define CHIP_ID 0x423 //STM32F401xB(C)
  #define CHIP_INFO CHIP_ID423

#elif defined(STM32F401CC)
  #define CHIP_ID 0x423 //STM32F401xB(C)
  #define CHIP_INFO CHIP_ID423

#elif defined(STM32F401CD)
  #define CHIP_ID 0x433 //STM32F401xD(E)
  #define CHIP_INFO CHIP_ID433

#elif defined(STM32F401CE)
  #define CHIP_ID 0x433 //STM32F401xD(E)
  #define CHIP_INFO CHIP_ID433

#elif defined(STM32F401RB)
  #define CHIP_ID 0x423 //STM32F401xB(C)
  #define CHIP_INFO CHIP_ID423

#elif defined(STM32F401RC)
  #define CHIP_ID 0x423 //STM32F401xB(C)
  #define CHIP_INFO CHIP_ID423

#elif defined(STM32F401RD)
  #define CHIP_ID 0x433 //STM32F401xD(E)
  #define CHIP_INFO CHIP_ID433

#elif defined(STM32F401RE)
  #define CHIP_ID 0x433 //STM32F401xD(E)
  #define CHIP_INFO CHIP_ID433

#elif defined(STM32F401VB)
  #define CHIP_ID 0x423 //STM32F401xB(C)
  #define CHIP_INFO CHIP_ID423

#elif defined(STM32F401VC)
  #define CHIP_ID 0x423 //STM32F401xB(C)
  #define CHIP_INFO CHIP_ID423

#elif defined(STM32F401VD)
  #define CHIP_ID 0x433 //STM32F401xD(E)
  #define CHIP_INFO CHIP_ID433

#elif defined(STM32F401VE)
  #define CHIP_ID 0x433 //STM32F401xD(E)
  #define CHIP_INFO CHIP_ID433

#elif defined(STM32F405OE)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F405OG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F405RG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F405VG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F405ZG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F415OG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F415RG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F415VG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F415ZG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F407IE)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F407IG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F407VE)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F407VG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F407ZE)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F407ZG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F417IE)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F417IG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F417VE)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F417VG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F417ZE)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F417ZG)
  #define CHIP_ID 0x413 //STM32F40xxx/41xxx
  #define CHIP_INFO CHIP_ID413

#elif defined(STM32F410C8)
  #define CHIP_ID 0x458 //STM32F410xx
  #define CHIP_INFO CHIP_ID458

#elif defined(STM32F410CB)
  #define CHIP_ID 0x458 //STM32F410xx
  #define CHIP_INFO CHIP_ID458

#elif defined(STM32F410R8)
  #define CHIP_ID 0x458 //STM32F410xx
  #define CHIP_INFO CHIP_ID458

#elif defined(STM32F410RB)
  #define CHIP_ID 0x458 //STM32F410xx
  #define CHIP_INFO CHIP_ID458

#elif defined(STM32F410T8)
  #define CHIP_ID 0x458 //STM32F410xx
  #define CHIP_INFO CHIP_ID458

#elif defined(STM32F410TB)
  #define CHIP_ID 0x458 //STM32F410xx
  #define CHIP_INFO CHIP_ID458

#elif defined(STM32F411CC)
  #define CHIP_ID 0x431 //STM32F411xx
  #define CHIP_INFO CHIP_ID431

#elif defined(STM32F411CE)
  #define CHIP_ID 0x431 //STM32F411xx
  #define CHIP_INFO CHIP_ID431

#elif defined(STM32F411RC)
  #define CHIP_ID 0x431 //STM32F411xx
  #define CHIP_INFO CHIP_ID431

#elif defined(STM32F411RE)
  #define CHIP_ID 0x431 //STM32F411xx
  #define CHIP_INFO CHIP_ID431

#elif defined(STM32F411VC)
  #define CHIP_ID 0x431 //STM32F411xx
  #define CHIP_INFO CHIP_ID431

#elif defined(STM32F411VE)
  #define CHIP_ID 0x431 //STM32F411xx
  #define CHIP_INFO CHIP_ID431

#elif defined(STM32F412CE)
  #define CHIP_ID 0x441  //STM32F412xx
  #define CHIP_INFO CHIP_ID441

#elif defined(STM32F412CG)
  #define CHIP_ID 0x441  //STM32F412xx
  #define CHIP_INFO CHIP_ID441

#elif defined(STM32F412RE)
  #define CHIP_ID 0x441  //STM32F412xx
  #define CHIP_INFO CHIP_ID441

#elif defined(STM32F412RG)
  #define CHIP_ID 0x441  //STM32F412xx
  #define CHIP_INFO CHIP_ID441

#elif defined(STM32F412VE)
  #define CHIP_ID 0x441  //STM32F412xx
  #define CHIP_INFO CHIP_ID441

#elif defined(STM32F412VG)
  #define CHIP_ID 0x441  //STM32F412xx
  #define CHIP_INFO CHIP_ID441

#elif defined(STM32F412ZE)
  #define CHIP_ID 0x441  //STM32F412xx
  #define CHIP_INFO CHIP_ID441

#elif defined(STM32F412ZG)
  #define CHIP_ID 0x441  //STM32F412xx
  #define CHIP_INFO CHIP_ID441

#elif defined(STM32F413CG)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F413CH)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F413MG)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F413MH)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F413RG)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F413RH)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F413VG)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F413VH)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F413ZG)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F413ZH)
  #define CHIP_ID 0x463 //STM32F413xx
  #define CHIP_INFO CHIP_ID463

#elif defined(STM32F423CH)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F423MH)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F423RH)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F423VH)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F423ZH)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F427AG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F427AI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F427IG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F427II)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F427VG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F427VI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F427ZG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F427ZI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F437AI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F437IG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F437II)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F437VG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F437VI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F437ZG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F437ZI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429AG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429AI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429BE)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429BG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429BI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429IE)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429IG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429II)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429NE)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429NG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429NI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429VE)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429VG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429VI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429ZE)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429ZG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F429ZI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439AI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439BG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439BI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439IG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439II)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439NG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439NI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439VG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439VI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439ZG)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F439ZI)
  #define CHIP_ID 0x419 //STM32F42xxx/43xxx
  #define CHIP_INFO CHIP_ID419

#elif defined(STM32F446MC)
  #define CHIP_ID 0x421 //STM32F446xx
  #define CHIP_INFO CHIP_ID421

#elif defined(STM32F446ME)
  #define CHIP_ID 0x421 //STM32F446xx
  #define CHIP_INFO CHIP_ID421

#elif defined(STM32F446RC)
  #define CHIP_ID 0x421 //STM32F446xx
  #define CHIP_INFO CHIP_ID421

#elif defined(STM32F446RE)
  #define CHIP_ID 0x421 //STM32F446xx
  #define CHIP_INFO CHIP_ID421

#elif defined(STM32F446VC)
  #define CHIP_ID 0x421 //STM32F446xx
  #define CHIP_INFO CHIP_ID421

#elif defined(STM32F446VE)
  #define CHIP_ID 0x421 //STM32F446xx
  #define CHIP_INFO CHIP_ID421

#elif defined(STM32F446ZC)
  #define CHIP_ID 0x421 //STM32F446xx
  #define CHIP_INFO CHIP_ID421

#elif defined(STM32F446ZE)
  #define CHIP_ID 0x421 //STM32F446xx
  #define CHIP_INFO CHIP_ID421

#elif defined(STM32F469AE)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469AG)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469AI)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469BE)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469BG)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469BI)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469IE)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469IG)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469II)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469NE)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469NG)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469NI)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469VE)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469VG)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469VI)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469ZE)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469ZG)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F469ZI)
  #define CHIP_ID 0x434 //STM32F469xx
  #define CHIP_INFO CHIP_ID434

#elif defined(STM32F479AG)

#elif defined(STM32F479AI)

#elif defined(STM32F479BG)

#elif defined(STM32F479BI)

#elif defined(STM32F479IG)

#elif defined(STM32F479II)

#elif defined(STM32F479NG)

#elif defined(STM32F479NI)

#elif defined(STM32F479VG)

#elif defined(STM32F479VI)

#elif defined(STM32F479ZG)

#elif defined(STM32F479ZI)

#elif defined(STM32F722IC)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F722IE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F722RC)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F722RE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F722VC)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F722VE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F722ZC)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F722ZE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F732IE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F732RE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F732VE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F732ZE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F723IC)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F723IE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F723VC)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F723VE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F723ZC)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F723ZE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F733IE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F733VE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F733ZE)
  #define CHIP_ID 0x452 //STM32F72xxx/73xxx
  #define CHIP_INFO CHIP_ID452

#elif defined(STM32F745IE)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F745IG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F745VE)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F745VG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F745ZE)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F745ZG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F765BG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F765BI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F765IG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F765II)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F765NG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F765NI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F765VG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F765VI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F765ZG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F765ZI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F746BE)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F746BG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F746IE)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F746IG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F746NE)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F746NG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F746VE)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F746VG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F746ZE)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F746ZG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F756BG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F756IG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F756NG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F756VG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F756ZG)
  #define CHIP_ID 0x449 //STM32F74xxx/75xxx
  #define CHIP_INFO CHIP_ID449

#elif defined(STM32F767BG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F767BI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F767IG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F767II)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F767NG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F767NI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F767VG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F767VI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F767ZG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F767ZI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F777BI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F777II)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F777NI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F777VI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F777ZI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F768AI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F778AI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F769AG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F769AI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F769BG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F769BI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F769IG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F769II)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F769NG)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F769NI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F779AI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F779BI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F779II)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451

#elif defined(STM32F779NI)
  #define CHIP_ID 0x451 //STM32F76xxx/77xxx
  #define CHIP_INFO CHIP_ID451
  
#elif defined(STM32H743ZI)

#elif defined(STM32L011D3)

#elif defined(STM32L011D4)

#elif defined(STM32L011E3)

#elif defined(STM32L011E4)

#elif defined(STM32L011F3)

#elif defined(STM32L011F4)

#elif defined(STM32L011G3)

#elif defined(STM32L011G4)

#elif defined(STM32L011K3)

#elif defined(STM32L011K4)

#elif defined(STM32L021D4)

#elif defined(STM32L021F4)

#elif defined(STM32L021G4)

#elif defined(STM32L021K4)

#elif defined(STM32L031C4)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L031C6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L031E4)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L031E6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L031F4)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L031F6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L031G4)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L031G6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L031K4)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L031K6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L041C4)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L041C6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L041E6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L041F6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L041G6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L041K6)
  #define CHIP_ID 0x425 //STM32L031xx/041xx
  #define CHIP_INFO CHIP_ID425

#elif defined(STM32L051C6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx"
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L051C8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx"
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L051K6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx"
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L051K8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx"
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L051R6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx"
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L051R8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx"
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L051T6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx"
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L051T8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx"
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L071CB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071CZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071C8)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071KB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071KZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071K8)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071RB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071RZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071VB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071VZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L071V8)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L081CZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L081KZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L052C6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L052C8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L052K6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L052K8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L052R6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L052R8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L052T6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L052T8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L062K8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L072CB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L072CZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L072KB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L072KZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L072RB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L072RZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L072VB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L072VZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L072V8)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L082CZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L082KB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L082KZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L053C6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L053C8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L053R6)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L053R8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L063C8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L063R8)
  #define CHIP_ID 0x417 //STM32L05xxx/06xxx
  #define CHIP_INFO CHIP_ID417

#elif defined(STM32L073CB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L073CZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L073RB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L073RZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L073VB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L073VZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L073V8)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L083CB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L083CZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L083RB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L083RZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L083VB)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L083VZ)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L083V8)
  #define CHIP_ID 0x447 //STM32L07xxx/08xxx
  #define CHIP_INFO CHIP_ID447

#elif defined(STM32L100C6)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L100R8)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L100RB)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L100RC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L151C6)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L151C8)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L151CB)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L151CC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L151QC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L151QD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L151QE)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L151R6)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L151R8)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L151RB)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L151RC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L151RD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L151RE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L151UC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L151V8)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L151VB)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L151VC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L151VD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L151VE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L151ZC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L151ZD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L151ZE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L152C6)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L152C8)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L152CB)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L152CC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L152QC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L152QD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L152QE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L152R6)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L152R8)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L152RB)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L152RC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L152RD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L152RE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L152V8)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L152VB)
  #define CHIP_ID 0x416 //STM32L1xxx6(8/B)
  #define CHIP_INFO CHIP_ID416

#elif defined(STM32L152VC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L152VD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L152VE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L152ZC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L152ZD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L152ZE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L162QD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L162RC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L162RD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L162RE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L162VC)
  #define CHIP_ID 0x427 //STM32L1xxxC
  #define CHIP_INFO CHIP_ID427

#elif defined(STM32L162VD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L162VE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L162ZD)
  #define CHIP_ID 0x436 //STM32L1xxxD
  #define CHIP_INFO CHIP_ID436

#elif defined(STM32L162ZE)
  #define CHIP_ID 0x437 //STM32L1xxxE
  #define CHIP_INFO CHIP_ID437

#elif defined(STM32L431CB)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L431CC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L431KB)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L431KC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L431RB)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L431RC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L431VC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L451CC)

#elif defined(STM32L451CE)

#elif defined(STM32L451RC)

#elif defined(STM32L451RE)

#elif defined(STM32L451VC)

#elif defined(STM32L451VE)

#elif defined(STM32L471QE)
  #define CHIP_ID 0x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L471QG)
  #define CHIP_ID 0x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L471RE)
  #define CHIP_ID 0x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L471RG)
  #define CHIP_ID 0x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L471VE)
  #define CHIP_ID 0x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L471VG)
  #define CHIP_ID 0x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L471ZE)
  #define CHIP_ID 0x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L471ZG)
  #define CHIP_ID 0x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L432KB)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L432KC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L442KC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L452CC)
 
#elif defined(STM32L452CE)
 
#elif defined(STM32L452RC)
 
#elif defined(STM32L452RE)
 
#elif defined(STM32L452VC)
 
#elif defined(STM32L452VE)
 
#elif defined(STM32L462CE)

#elif defined(STM32L462RE)
 
#elif defined(STM32L462VE)
 
#elif defined(STM32L433CB)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L433CC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L433RB)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L433RC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L433VC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L443CC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L443RC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L443VC)
  #define CHIP_ID 0x435 //STM32L43xxx/44xxx
  #define CHIP_INFO CHIP_ID435

#elif defined(STM32L475RC)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L475RE)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L475RG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L475VC)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L475VE)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L475VG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L485JC)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L485JE)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476JE)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476JG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476ME)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476MG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476QE)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476QG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476RC)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476RE)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476RG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476VC)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476VE)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476VG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476ZE)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L476ZG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L486JG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L486QG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L486RG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L486VG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L486ZG)
  #define CHIP_ID 00x415 //STM32L47xxx/48xxx
  #define CHIP_INFO CHIP_ID415

#elif defined(STM32L496AE)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L496AG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L496QE)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L496QG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L496RE)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L496RG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L496VE)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L496VG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L496ZE)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L496ZG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L4A6AG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L4A6QG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L4A6RG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L4A6VG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461

#elif defined(STM32L4A6ZG)
  #define CHIP_ID 0x461 //STM32L496xx/4A6xx" 
  #define CHIP_INFO CHIP_ID461
  
#elif defined(STM32L4R5ZI)
  #define CHIP_ID 0x470 //STM32L4R5xx" 
  #define CHIP_INFO CHIP_ID470

#else 
#warning   UNKNOWN CHIP PLEASE FIXED ME
#endif


#endif

