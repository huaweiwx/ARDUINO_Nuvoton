/*
 * TwoWire.h - TWI/I2C library for Arduino Due
 * Copyright (c) 2011 Cristian Maglie <c.maglie@bug.st>.
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

extern "C" {
#include <string.h>
}

#include "Wire.h"

TwoWire::TwoWire(I2C_T *_i2c, void(*_beginCb)(void)) :
	i2c(_i2c), rxBufferIndex(0), rxBufferLength(0), txAddress(0),
			txBufferLength(0), srvBufferIndex(0), srvBufferLength(0), status(
					UNINITIALIZED), onBeginCallback(_beginCb) {
	// Empty	
}

void TwoWire::begin(void) {   
                if(init_flag==0) init();
		if (onBeginCallback) onBeginCallback();			
		I2C_Open(i2c,I2C_CLOCK);		
		status = MASTER_IDLE;
                delay(1);
}

void TwoWire::begin(uint8_t address) {
		if (onBeginCallback) onBeginCallback();
		I2C_Open(i2c,I2C_CLOCK);			
		status = SLAVE_IDLE;
		
		I2C_SetSlaveAddr(i2c, 0, address, 0);   /* Slave Address */	        		
		I2C_EnableInt(i2c);				    
    I2C_SET_CONTROL_REG(i2c, I2C_SI_AA); /* I2C enter no address SLV mode */
}

void TwoWire::begin(int address) {
	begin((uint8_t) address);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop) {
	if (quantity > BUFFER_LENGTH) quantity = BUFFER_LENGTH;
	int readed = 0;
	int timeout_=TIMEOUT;
	while(timeout_--)
	{
		/* Send start */
		I2C_START(i2c);	
		I2C_WAIT_READY(i2c);
		
		/* Send control byte */
		I2C_SET_DATA(i2c, (address<<1)+1);			
		I2C_SET_CONTROL_REG(i2c, I2C_SI | I2C_AA);
		I2C_WAIT_READY(i2c);	
	
		if(I2C_GET_STATUS(i2c)!=0x40)
		{ /* Send stop */			
			I2C_SET_CONTROL_REG(i2c, I2C_STO | I2C_SI);	
			continue;	
		}
		readed = 0;		 	 
		while (readed < quantity){				
			/* Read data */
			if((readed+1)==quantity)			
				I2C_SET_CONTROL_REG(i2c, I2C_SI);
			else
				I2C_SET_CONTROL_REG(i2c, I2C_SI | I2C_AA);
			I2C_WAIT_READY(i2c);			
			rxBuffer[readed++] = I2C_GET_DATA(i2c);
		};	
		if(sendStop==true){
					/* Send stop */
			I2C_SET_CONTROL_REG(i2c, I2C_STO | I2C_SI);				
		}else
			I2C_SET_CONTROL_REG(i2c, I2C_SI);					
		
		break;
	}
			
	// set rx buffer iterator vars
	rxBufferIndex = 0;
	rxBufferLength = readed;		
		
	return readed;			
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity) {
	return requestFrom((uint8_t)address, (uint8_t) quantity, (uint8_t) true);
}

uint8_t TwoWire::requestFrom(int address, int quantity) {
	return requestFrom((uint8_t)address, (uint8_t) quantity, (uint8_t) true);
}

uint8_t TwoWire::requestFrom(int address, int quantity, int sendStop) {
	return requestFrom((uint8_t)address, (uint8_t) quantity, (uint8_t) sendStop);
}

void TwoWire::beginTransmission(uint8_t address) {
	status = MASTER_SEND;
	// save address of target and empty buffer
	txAddress = address<<1;
	txBufferLength = 0;
}

void TwoWire::beginTransmission(int address) {
	beginTransmission((uint8_t) address);
}

//
//	Originally, 'endTransmission' was an f(void) function.
//	It has been modified to take one parameter indicating
//	whether or not a STOP should be performed on the bus.
//	Calling endTransmission(false) allows a sketch to
//	perform a repeated start.
//
//	WARNING: Nothing in the library keeps track of whether
//	the bus tenure has been properly ended with a STOP. It
//	is very possible to leave the bus in a hung state if
//	no call to endTransmission(true) is made. Some I2C
//	devices will behave oddly if they do not see a STOP.
//

uint8_t TwoWire::endTransmission(uint8_t sendStop) {
	
	int sent = 0;	/* Send data */
	int timeout_=TIMEOUT;
	while(timeout_--)
	{
		/* Send start */
		I2C_START(i2c);	
		I2C_WAIT_READY(i2c);			
	
		/* Send control byte */
		I2C_SET_DATA(i2c, txAddress);
		I2C_SET_CONTROL_REG(i2c, I2C_SI);
		I2C_WAIT_READY(i2c);			
		if(I2C_GET_STATUS(i2c)!=0x18) 
		{ 
			I2C_SET_CONTROL_REG(i2c, I2C_STO | I2C_SI);
			continue;
		}
		sent = 0;
		while (sent < txBufferLength) {
			I2C_SET_DATA(i2c, txBuffer[sent++]);
			I2C_SET_CONTROL_REG(i2c, I2C_SI);
			I2C_WAIT_READY(i2c);	
			if(I2C_GET_STATUS(i2c)!=0x28) { 
				I2C_SET_CONTROL_REG(i2c, I2C_STO | I2C_SI);
				continue;
			}			
		}
		if(sendStop==true)
		{
			/* Send stop */
			I2C_SET_CONTROL_REG(i2c, I2C_STO | I2C_SI);  				
		}
		break;
	}	
	// empty buffer
	txBufferLength = 0;
	status = MASTER_IDLE;	
	return sent;	
}

//	This provides backwards compatibility with the original
//	definition, and expected behaviour, of endTransmission
//
uint8_t TwoWire::endTransmission(void)
{
	return endTransmission(true);
}

size_t TwoWire::write(uint8_t data) {	
	if (status == MASTER_SEND) {
		if (txBufferLength >= BUFFER_LENGTH)
			return 0;
		txBuffer[txBufferLength++] = data;
		return 1;
	} else {
		if (srvBufferLength >= BUFFER_LENGTH)
			return 0;
		srvBuffer[srvBufferLength++] = data;
		return 1;
	}
}

size_t TwoWire::write(const uint8_t *data, size_t quantity) {
	if (status == MASTER_SEND) {
		for (size_t i = 0; i < quantity; ++i) {
			if (txBufferLength >= BUFFER_LENGTH)
				return i;
			txBuffer[txBufferLength++] = data[i];
		}
	} else {
		for (size_t i = 0; i < quantity; ++i) {
			if (srvBufferLength >= BUFFER_LENGTH)
				return i;
			srvBuffer[srvBufferLength++] = data[i];
		}
	}
}

int TwoWire::available(void) {
	return rxBufferLength - rxBufferIndex;
}

int TwoWire::read(void) {
	if (rxBufferIndex < rxBufferLength)
		return rxBuffer[rxBufferIndex++];
	return -1;
}

int TwoWire::peek(void) {
	if (rxBufferIndex < rxBufferLength)
		return rxBuffer[rxBufferIndex];
	return -1;
}

void TwoWire::flush(void) {
	// Do nothing, use endTransmission(..) to force
	// data transfer.
}

void TwoWire::onReceive(void(*function)(int)) {
	onReceiveCallback = function;
}

void TwoWire::onRequest(void(*function)(void)) {
	onRequestCallback = function;
}

void TwoWire::I2C_SlaveTRx(uint32_t u32Status)
{
		//Serial.print("u32Status=");
		//Serial.println(u32Status,HEX);
		//Serial.print("srvBufferIndex=");
		//Serial.println(srvBufferIndex,HEX);
    if(u32Status == 0x60)                       /* Own SLA+W has been receive; ACK has been return */
    {
    	  status = SLAVE_RECV;
        srvBufferLength = 0;
        I2C_SET_CONTROL_REG(i2c, I2C_SI_AA);
    }
    else if(u32Status == 0x80 || u32Status==0x10)                 /* Previously address with own SLA address
                                                   Data has been received; ACK has been returned*/
    {
        srvBuffer[srvBufferLength] = (unsigned char) I2C_GET_DATA(i2c);
        srvBufferLength++;

        I2C_SET_CONTROL_REG(i2c, I2C_SI_AA);
    }
    else if(u32Status == 0xA8)                  /* Own SLA+R has been receive; ACK has been return */
    {				    		        
     
				// Alert calling program to generate a response ASAP
				if (onRequestCallback && status != SLAVE_SEND)
				{
					srvBufferLength = 0;
					srvBufferIndex = 0;	
					onRequestCallback();
				}			
  			status = SLAVE_SEND;  							
				if (srvBufferIndex < srvBufferLength)
				{						
						//Serial.print("==============>");
						//Serial.println((char)srvBuffer[srvBufferIndex]);
						I2C_SET_DATA(i2c, srvBuffer[srvBufferIndex++]);						
						I2C_SET_CONTROL_REG(i2c, I2C_SI_AA);						
				}
				
				if (srvBufferIndex == srvBufferLength)
						status = SLAVE_IDLE;
						
		}else if(u32Status == 0xB8)	
		{
				if (srvBufferIndex < srvBufferLength)
				{				
						//Serial.print("==============>");
						//Serial.println((char)srvBuffer[srvBufferIndex]);		
						I2C_SET_DATA(i2c, srvBuffer[srvBufferIndex++]);						
						I2C_SET_CONTROL_REG(i2c, I2C_SI_AA);						
				}
				
				if (srvBufferIndex == srvBufferLength)
						status = SLAVE_IDLE;			
		}
    else if(u32Status == 0xC0)                 /* Data byte or last data in I2CDAT has been transmitted
                                                   Not ACK has been received */
    {
        I2C_SET_CONTROL_REG(i2c, I2C_SI_AA);
    }
    else if(u32Status == 0x88)                 /* Previously addressed with own SLA address; NOT ACK has
                                                   been returned */
    {
        srvBufferLength = 0;
        I2C_SET_CONTROL_REG(i2c, I2C_SI_AA);
    }
    else if(u32Status == 0xA0)                 /* A STOP or repeated START has been received while still
                                                   addressed as Slave/Receiver*/
    {
        srvBufferIndex = 0;
        I2C_SET_CONTROL_REG(i2c, I2C_SI_AA);
 
 
 			if (status != SLAVE_IDLE)
 			{
 				for (uint8_t i = 0; i < srvBufferLength; ++i)
					rxBuffer[i] = srvBuffer[i];
				rxBufferIndex = 0;
				rxBufferLength = srvBufferLength;				             
				onReceiveCallback( rxBufferLength); // Alert calling program
				status = SLAVE_IDLE;
			}
    }
}

void TwoWire::onService(void) {
    uint32_t u32Status;

    u32Status = I2C_GET_STATUS(i2c);

    if(I2C_GET_TIMEOUT_FLAG(i2c))
    {
        /* Clear I2C0 Timeout Flag */
        I2C_ClearTimeoutFlag(i2c);
    }
    else
    {
        I2C_SlaveTRx(u32Status);
    }
}

#if I2C_MAX_COUNT > 0
static void Wire_Init(void) {
	
	IRQn_Type irq=I2C1_IRQn;
	I2C_Config(I2C_Desc[0]);	
	/* Enable IP clock */       
	CLK_EnableModuleClock(I2C_Desc[0].module);    	
   	
	/* Select IP clock source and clock divider */
	CLK_SetModuleClock(I2C_Desc[0].module,0,0);

	NVIC_DisableIRQ(irq);
	NVIC_ClearPendingIRQ(irq);
	NVIC_SetPriority(irq, 0);
	NVIC_EnableIRQ(irq);
}

TwoWire Wire = TwoWire(I2C_Desc[0].I, Wire_Init);

#ifdef __cplusplus
extern "C" void I2C1_IRQHandler(void) {
	Wire.onService();
}
#endif

#endif



#if I2C_MAX_COUNT > 1
static void Wire1_Init(void) {
	
	IRQn_Type irq=I2C0_IRQn;
	
	I2C_Config(I2C_Desc[1]);
	
	/* Enable IP clock */       
	CLK_EnableModuleClock(I2C_Desc[1].module);    	
   	
	/* Select IP clock source and clock divider */
	CLK_SetModuleClock(I2C_Desc[1].module,0,0);

	NVIC_DisableIRQ(irq);
	NVIC_ClearPendingIRQ(irq);
	NVIC_SetPriority(irq, 0);
	NVIC_EnableIRQ(irq);
}

TwoWire Wire1 = TwoWire(I2C_Desc[1].I, Wire1_Init);
#ifdef __cplusplus
extern "C" void I2C0_IRQHandler(void) {
	Wire1.onService();
}
#endif

#endif
