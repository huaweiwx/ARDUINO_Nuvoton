/*
  Copyright (c) 2011-2012 Arduino.  All right reserved.

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
#include "Arduino.h"

#if defined(__M451__)||defined(M480)   

typedef void (*interruptCB)(void);
#define GNUM 16
static interruptCB callbacksGPA[GNUM];
static interruptCB callbacksGPB[GNUM];
static interruptCB callbacksGPC[GNUM];
static interruptCB callbacksGPD[GNUM];
static interruptCB callbacksGPE[GNUM];
static interruptCB callbacksGPF[GNUM];

/* Configure GPIO interrupt sources */
static void __initialize() {
	int i;
	for (i=0; i<GNUM; i++) {
		callbacksGPA[i] = NULL;
		callbacksGPB[i] = NULL;
		callbacksGPC[i] = NULL;
		callbacksGPD[i] = NULL;
		callbacksGPE[i] = NULL;
		callbacksGPF[i] = NULL;
	}
	NVIC_EnableIRQ(GPA_IRQn);
	NVIC_EnableIRQ(GPB_IRQn);
	NVIC_EnableIRQ(GPC_IRQn);
	NVIC_EnableIRQ(GPD_IRQn);
	NVIC_EnableIRQ(GPE_IRQn);
	NVIC_EnableIRQ(GPF_IRQn);	
}

void attachInterrupt(uint32_t pin, void (*callback)(void), uint32_t mode)
{
	static int enabled = 0;
	
#ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
#else
  if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
 #endif
  		
	if (!enabled) {
		__initialize();
		enabled = 1;
	}
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	
	for (t = mask; t>1; t>>=1, pos++);
	// Set callback function
	
	if (pio == PA )
		callbacksGPA[pos] = callback;
	else if (pio == PB )
		callbacksGPB[pos] = callback;
	else if (pio == PC )
		callbacksGPC[pos] = callback;
	else if (pio == PD )
		callbacksGPD[pos] = callback;
	else if (pio == PE )
		callbacksGPE[pos] = callback;
	else if (pio == PF )
		callbacksGPF[pos] = callback;		
	// Enable interrupt
	if(mode==FALLING)
		GPIO_EnableInt(pio,pos,GPIO_INT_FALLING);
	else if(mode==RISING)		
		GPIO_EnableInt(pio,pos,GPIO_INT_RISING);	
	else if(mode==CHANGE)
		GPIO_EnableInt(pio,pos,GPIO_INT_BOTH_EDGE);		
}

void detachInterrupt(uint32_t pin)
{

	#ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
	#else
  if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
  #endif
  	
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	for (t = mask; t>1; t>>=1, pos++);	

	// Disable interrupt
	GPIO_DisableInt(pio,pos);
	
	if (pio == PA )
		callbacksGPA[pos] = NULL;
	else if (pio == PB )
		callbacksGPB[pos] = NULL;
	else if (pio == PC )
		callbacksGPC[pos] = NULL;
	else if (pio == PD )
		callbacksGPD[pos] = NULL;
	else if (pio == PE )
		callbacksGPE[pos] = NULL;
	else if (pio == PF )
		callbacksGPF[pos] = NULL;			
}

#ifdef __cplusplus
extern "C" {
#endif

void GPA_IRQHandler(void)
{
		uint32_t i;		
	  for (i=0; i<GNUM; i++) {
	  	if(PA->INTSRC & (1<<i))
	  	{ 
	  		if (callbacksGPA[i]) callbacksGPA[i]();	  		
	  		PA->INTSRC = (1<<i);
	  	}
	  }  
}
void GPB_IRQHandler(void)
{
		uint32_t i;		
	  for (i=0; i<GNUM; i++) {
	  	if(PB->INTSRC & (1<<i))
	  	{ 
	  		if (callbacksGPB[i]) callbacksGPB[i]();	  		
	  		PB->INTSRC = (1<<i);
	  	}
	  }  
}

void GPC_IRQHandler(void)
{
		uint32_t i;		
	  for (i=0; i<GNUM; i++) {
	  	if(PC->INTSRC & (1<<i))
	  	{ 
	  		if (callbacksGPC[i]) callbacksGPC[i]();	  		
	  		PC->INTSRC = (1<<i);
	  	}
	  }  
}

void GPD_IRQHandler(void)
{
		uint32_t i;		
	  for (i=0; i<GNUM; i++) {
	  	if(PD->INTSRC & (1<<i))
	  	{ 
	  		if (callbacksGPD[i]) callbacksGPD[i]();	  		
	  		PD->INTSRC = (1<<i);
	  	}
	  }  
}

void GPE_IRQHandler(void)
{
		uint32_t i;		
	  for (i=0; i<GNUM; i++) {
	  	if(PE->INTSRC & (1<<i))
	  	{ 
	  		if (callbacksGPE[i]) callbacksGPE[i]();	  		
	  		PE->INTSRC = (1<<i);
	  	}
	  }  
}

void GPF_IRQHandler(void)
{
		uint32_t i;		
	  for (i=0; i<GNUM; i++) {
	  	if(PF->INTSRC & (1<<i))
	  	{ 
	  		if (callbacksGPF[i]) callbacksGPF[i]();	  		
	  		PF->INTSRC = (1<<i);
	  	}
	  }  
}

#ifdef __cplusplus
}
#endif

#elif defined(__NUC240__)

typedef void (*interruptCB)(void);

static interruptCB callbacksPA[8];
static interruptCB callbacksPB[8];
static interruptCB callbacksPC[8];
static interruptCB callbacksPD[8];
static interruptCB callbacksPE[8];
static interruptCB callbacksPF[8];


/* Configure PIO interrupt sources */
static void __initialize() {
	int i;
	for (i=0; i<8; i++) {
		callbacksPA[i] = NULL;
		callbacksPB[i] = NULL;
		callbacksPC[i] = NULL;
		callbacksPD[i] = NULL;
		callbacksPE[i] = NULL;
		callbacksPF[i] = NULL;
	}
	NVIC_EnableIRQ(GPAB_IRQn);
	NVIC_EnableIRQ(GPCDEF_IRQn);
}

void attachInterrupt(uint32_t pin, void (*callback)(void), uint32_t mode)
{
	static int enabled = 0;
	
#ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
#else
  if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
 #endif
  		
	if (!enabled) {
		__initialize();
		enabled = 1;
	}
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	
	for (t = mask; t>1; t>>=1, pos++);
	// Set callback function
	
	if (pio == PA )
		callbacksPA[pos] = callback;
	else if (pio == PB )
		callbacksPB[pos] = callback;
	else if (pio == PC )
		callbacksPC[pos] = callback;
	else if (pio == PD )
		callbacksPD[pos] = callback;
	else if (pio == PE )
		callbacksPE[pos] = callback;
	else if (pio == PF )
		callbacksPF[pos] = callback;		
	// Enable interrupt
	if(mode==FALLING)
		GPIO_EnableInt(pio,pos,GPIO_INT_FALLING);
	else if(mode==RISING)		
		GPIO_EnableInt(pio,pos,GPIO_INT_RISING);	
	else if(mode==CHANGE)
		GPIO_EnableInt(pio,pos,GPIO_INT_BOTH_EDGE);		
	else if(mode==LOW)
		GPIO_EnableInt(pio,pos,GPIO_INT_LOW);		
	else if(mode==HIGH)
		GPIO_EnableInt(pio,pos,GPIO_INT_HIGH);		
}

void detachInterrupt(uint32_t pin)
{

	#ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
	#else
  if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
  #endif
  	
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	for (t = mask; t>1; t>>=1, pos++);	

	// Disable interrupt
	GPIO_DisableInt(pio,pos);
	
	if (pio == PA )
		callbacksPA[pos] = NULL;
	else if (pio == PB )
		callbacksPB[pos] = NULL;
	else if (pio == PC )
		callbacksPC[pos] = NULL;
	else if (pio == PD )
		callbacksPD[pos] = NULL;
	else if (pio == PE )
		callbacksPE[pos] = NULL;
	else if (pio == PF )
		callbacksPF[pos] = NULL;		
}

#ifdef __cplusplus
extern "C" {
#endif

void GPAB_IRQHandler(void)
{
		uint32_t i;		
	  for (i=0; i<8; i++) {
	  	if(PA->ISRC & (1<<i))
	  	{ 
	  		if (callbacksPA[i]) callbacksPA[i]();	  		
	  		PA->ISRC = (1<<i);
	  	}
	  	if(PB->ISRC & (1<<i))
	  	{
	  		if (callbacksPB[i]) callbacksPB[i]();
	  		PB->ISRC = (1<<i);
	  	}
	  }  
}
void GPCDEF_IRQHandler(void)
{
		uint32_t i;	
	  for (i=0; i<8; i++) {
	  	if(PC->ISRC & (1<<i))
	  	{
	  		if (callbacksPC[i]) callbacksPC[i]();	  		
				PC->ISRC = (1<<i);	  			
	  	}
	  	if(PD->ISRC & (1<<i)) 
	  	{
	  		if (callbacksPD[i]) callbacksPD[i]();
	  		PD->ISRC = (1<<i);	
	  	}
	  	if(PE->ISRC & (1<<i)) 
	  	{
	  		if (callbacksPE[i]) callbacksPE[i]();	  			
	  		PE->ISRC = (1<<i);	
	  	}
	  	if(PF->ISRC & (1<<i)) 
	  	{
	  		if (callbacksPF[i]) callbacksPF[i]();	  			
	  		PF->ISRC = (1<<i);	
	  	}	  	
	  }     
}

#ifdef __cplusplus
}
#endif

#elif defined(__NANO100__)

#define GP_NUM 16
typedef void (*interruptCB)(void);

static interruptCB callbacksPA[GP_NUM];
static interruptCB callbacksPB[GP_NUM];
static interruptCB callbacksPC[GP_NUM];
static interruptCB callbacksPD[GP_NUM];
static interruptCB callbacksPE[GP_NUM];
static interruptCB callbacksPF[GP_NUM];


/* Configure PIO interrupt sources */
static void __initialize() {
	int i;
	for (i=0; i<GP_NUM; i++) {
		callbacksPA[i] = NULL;
		callbacksPB[i] = NULL;
		callbacksPC[i] = NULL;
		callbacksPD[i] = NULL;
		callbacksPE[i] = NULL;		
	}
	NVIC_EnableIRQ(GPABC_IRQn);
	NVIC_EnableIRQ(GPDEF_IRQn);
}

static int enabled = 0;
void attachInterrupt(uint32_t pin, void (*callback)(void), uint32_t mode)
{		
#ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
#else
  if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
#endif
  		
	if (!enabled) {
		__initialize();
		enabled = 1;
	}
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	
	for (t = mask; t>1; t>>=1, pos++);
	// Set callback function
	
	if (pio == PA )
		callbacksPA[pos] = callback;
	else if (pio == PB )
		callbacksPB[pos] = callback;
	else if (pio == PC )
		callbacksPC[pos] = callback;
	else if (pio == PD )
		callbacksPD[pos] = callback;
	else if (pio == PE )
		callbacksPE[pos] = callback;
	else if (pio == PF )
		callbacksPF[pos] = callback;		
	// Enable interrupt
	if(mode==FALLING)
		GPIO_EnableInt(pio,pos,GPIO_INT_FALLING);
	else if(mode==RISING)		
		GPIO_EnableInt(pio,pos,GPIO_INT_RISING);	
	else if(mode==CHANGE)
		GPIO_EnableInt(pio,pos,GPIO_INT_BOTH_EDGE);		
}

void detachInterrupt(uint32_t pin)
{

  #ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
  #else
    if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
  #endif
  	
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	for (t = mask; t>1; t>>=1, pos++);	

	// Disable interrupt
	GPIO_DisableInt(pio,pos);
	
	if (pio == PA )
		callbacksPA[pos] = NULL;
	else if (pio == PB )
		callbacksPB[pos] = NULL;
	else if (pio == PC )
		callbacksPC[pos] = NULL;
	else if (pio == PD )
		callbacksPD[pos] = NULL;
	else if (pio == PE )
		callbacksPE[pos] = NULL;
	else if (pio == PF )
		callbacksPF[pos] = NULL;		
}

#ifdef __cplusplus
extern "C" {
#endif

void GPABC_IRQHandler(void)
{
		uint32_t i;				
	  for (i=0; i<GP_NUM; i++) {
	  	if(PA->ISR & (1<<i))
	  	{ 
	  		if (callbacksPA[i]) callbacksPA[i]();	  		
	  		PA->ISR = (1<<i);
	  	}
	  	if(PB->ISR & (1<<i))
	  	{
	  		if (callbacksPB[i]) callbacksPB[i]();
	  		PB->ISR = (1<<i);
	  	}
	  	if(PC->ISR & (1<<i))
	  	{
	  		if (callbacksPC[i]) callbacksPC[i]();
	  		PC->ISR = (1<<i);
	  	}	  	
	  }  
}
void GPDEF_IRQHandler(void)
{
		uint32_t i;	
	  for (i=0; i<GP_NUM; i++) {
	  	if(PD->ISR & (1<<i))
	  	{
	  		if (callbacksPD[i]) callbacksPD[i]();	  		
				PD->ISR = (1<<i);	  			
	  	}
	  	if(PE->ISR & (1<<i)) 
	  	{
	  		if (callbacksPE[i]) callbacksPE[i]();
	  		PE->ISR = (1<<i);	
	  	}
	  	if(PF->ISR & (1<<i)) 
	  	{
	  		if (callbacksPF[i]) callbacksPF[i]();	  			
	  		PF->ISR = (1<<i);	
	  	}
	  }     
}

#ifdef __cplusplus
}
#endif

#elif defined(__NANO1X2__)

#define GP_NUM 16
typedef void (*interruptCB)(void);

static interruptCB callbacksPA[GP_NUM];
static interruptCB callbacksPB[GP_NUM];
static interruptCB callbacksPC[GP_NUM];
static interruptCB callbacksPD[GP_NUM];
static interruptCB callbacksPE[GP_NUM];
static interruptCB callbacksPF[GP_NUM];


/* Configure PIO interrupt sources */
static void __initialize() {
	int i;
	for (i=0; i<GP_NUM; i++) {
		callbacksPA[i] = NULL;
		callbacksPB[i] = NULL;
		callbacksPC[i] = NULL;
		callbacksPD[i] = NULL;
		callbacksPE[i] = NULL;		
	}
	NVIC_EnableIRQ(GPABC_IRQn);
	NVIC_EnableIRQ(GPDEF_IRQn);
}

static int enabled = 0;
void attachInterrupt(uint32_t pin, void (*callback)(void), uint32_t mode)
{		
#ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
#else
  if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
#endif
  		
	if (!enabled) {
		__initialize();
		enabled = 1;
	}
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	
	for (t = mask; t>1; t>>=1, pos++);
	// Set callback function
	
	if (pio == PA )
		callbacksPA[pos] = callback;
	else if (pio == PB )
		callbacksPB[pos] = callback;
	else if (pio == PC )
		callbacksPC[pos] = callback;
	else if (pio == PD )
		callbacksPD[pos] = callback;
	else if (pio == PE )
		callbacksPE[pos] = callback;
	else if (pio == PF )
		callbacksPF[pos] = callback;		
	// Enable interrupt
	if(mode==FALLING)
		GPIO_EnableInt(pio,pos,GPIO_INT_FALLING);
	else if(mode==RISING)		
		GPIO_EnableInt(pio,pos,GPIO_INT_RISING);	
	else if(mode==CHANGE)
		GPIO_EnableInt(pio,pos,GPIO_INT_BOTH_EDGE);		
}

void detachInterrupt(uint32_t pin)
{

	#ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
	#else
  if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
  #endif
  	
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	for (t = mask; t>1; t>>=1, pos++);	

	// Disable interrupt
	GPIO_DisableInt(pio,pos);
	
	if (pio == PA )
		callbacksPA[pos] = NULL;
	else if (pio == PB )
		callbacksPB[pos] = NULL;
	else if (pio == PC )
		callbacksPC[pos] = NULL;
	else if (pio == PD )
		callbacksPD[pos] = NULL;
	else if (pio == PE )
		callbacksPE[pos] = NULL;
	else if (pio == PF )
		callbacksPF[pos] = NULL;		
}

#ifdef __cplusplus
extern "C" {
#endif

void GPABC_IRQHandler(void)
{
		uint32_t i;				
	  for (i=0; i<GP_NUM; i++) {
	  	if(PA->ISRC & (1<<i))
	  	{ 
	  		if (callbacksPA[i]) callbacksPA[i]();	  		
	  		PA->ISRC = (1<<i);
	  	}
	  	if(PB->ISRC & (1<<i))
	  	{
	  		if (callbacksPB[i]) callbacksPB[i]();
	  		PB->ISRC = (1<<i);
	  	}
	  	if(PC->ISRC & (1<<i))
	  	{
	  		if (callbacksPC[i]) callbacksPC[i]();
	  		PC->ISRC = (1<<i);
	  	}	  	
	  }  
}
void GPDEF_IRQHandler(void)
{
		uint32_t i;	
	  for (i=0; i<GP_NUM; i++) {
	  	if(PD->ISRC & (1<<i))
	  	{
	  		if (callbacksPD[i]) callbacksPD[i]();	  		
				PD->ISRC = (1<<i);	  			
	  	}
	  	if(PE->ISRC & (1<<i)) 
	  	{
	  		if (callbacksPE[i]) callbacksPE[i]();
	  		PE->ISRC = (1<<i);	
	  	}
	  	if(PF->ISRC & (1<<i)) 
	  	{
	  		if (callbacksPF[i]) callbacksPF[i]();	  			
	  		PF->ISRC = (1<<i);	
	  	}
	  }     
}

#ifdef __cplusplus
}
#endif

#elif(__NUC131__)
typedef void (*interruptCB)(void);

static interruptCB callbacksPA[8];
static interruptCB callbacksPB[8];
static interruptCB callbacksPC[8];
static interruptCB callbacksPD[8];
static interruptCB callbacksPE[8];
static interruptCB callbacksPF[8];


/* Configure PIO interrupt sources */
static void __initialize() {
	int i;
	for (i=0; i<8; i++) {
		callbacksPA[i] = NULL;
		callbacksPB[i] = NULL;
		callbacksPC[i] = NULL;
		callbacksPD[i] = NULL;
		callbacksPE[i] = NULL;
		callbacksPF[i] = NULL;
	}
	NVIC_EnableIRQ(GPAB_IRQn);
	NVIC_EnableIRQ(GPCDEF_IRQn);
}

void attachInterrupt(uint32_t pin, void (*callback)(void), uint32_t mode)
{
	static int enabled = 0;
	
#ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
#else
  if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
 #endif
  		
	if (!enabled) {
		__initialize();
		enabled = 1;
	}
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	
	for (t = mask; t>1; t>>=1, pos++);
	// Set callback function
	
	if (pio == PA )
		callbacksPA[pos] = callback;
	else if (pio == PB )
		callbacksPB[pos] = callback;
	else if (pio == PC )
		callbacksPC[pos] = callback;
	else if (pio == PD )
		callbacksPD[pos] = callback;
	else if (pio == PE )
		callbacksPE[pos] = callback;
	else if (pio == PF )
		callbacksPF[pos] = callback;		
	// Enable interrupt
	if(mode==FALLING)
		GPIO_EnableInt(pio,pos,GPIO_INT_FALLING);
	else if(mode==RISING)		
		GPIO_EnableInt(pio,pos,GPIO_INT_RISING);	
	else if(mode==CHANGE)
		GPIO_EnableInt(pio,pos,GPIO_INT_BOTH_EDGE);		
}

void detachInterrupt(uint32_t pin)
{

	#ifdef USE_BoardToPin	
	if(pin > BoardToPin_MAX_COUNT) return;
	pin=BoardToPinInfo[pin].pin;
	#else
  if(pin>NUM_DIGITAL_PINS || GPIO_Desc[pin].P==NULL) return;
  #endif
  	
	// Retrieve pin information
	GPIO_T *pio = GPIO_Desc[pin].P;
	uint32_t mask = GPIO_Desc[pin].bit;
	uint32_t pos = 0;
	uint32_t t;
	for (t = mask; t>1; t>>=1, pos++);	

	// Disable interrupt
	GPIO_DisableInt(pio,pos);
	
	if (pio == PA )
		callbacksPA[pos] = NULL;
	else if (pio == PB )
		callbacksPB[pos] = NULL;
	else if (pio == PC )
		callbacksPC[pos] = NULL;
	else if (pio == PD )
		callbacksPD[pos] = NULL;
	else if (pio == PE )
		callbacksPE[pos] = NULL;
	else if (pio == PF )
		callbacksPF[pos] = NULL;		
}

#ifdef __cplusplus
extern "C" {
#endif

void GPAB_IRQHandler(void)
{
		uint32_t i;		
	  for (i=0; i<8; i++) {
	  	if(PA->ISRC & (1<<i))
	  	{ 
	  		if (callbacksPA[i]) callbacksPA[i]();	  		
	  		PA->ISRC = (1<<i);
	  	}
	  	if(PB->ISRC & (1<<i))
	  	{
	  		if (callbacksPB[i]) callbacksPB[i]();
	  		PB->ISRC = (1<<i);
	  	}
	  }  
}
void GPCDEF_IRQHandler(void)
{
		uint32_t i;	
	  for (i=0; i<8; i++) {
	  	if(PC->ISRC & (1<<i))
	  	{
	  		if (callbacksPC[i]) callbacksPC[i]();	  		
				PC->ISRC = (1<<i);	  			
	  	}
	  	if(PD->ISRC & (1<<i)) 
	  	{
	  		if (callbacksPD[i]) callbacksPD[i]();
	  		PD->ISRC = (1<<i);	
	  	}
	  	if(PE->ISRC & (1<<i)) 
	  	{
	  		if (callbacksPE[i]) callbacksPE[i]();	  			
	  		PE->ISRC = (1<<i);	
	  	}
	  	if(PF->ISRC & (1<<i)) 
	  	{
	  		if (callbacksPF[i]) callbacksPF[i]();	  			
	  		PF->ISRC = (1<<i);	
	  	}	  	
	  }     
}

#ifdef __cplusplus
}
#endif
#endif