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

#ifndef TwoWire_h
#define TwoWire_h

// Include Nuvoton CMSIS driver
#include "Arduino.h"

#include "Stream.h"

#define BUFFER_LENGTH 32

#if defined(__M451__)
#define I2C_STA_STO_SI 		I2C_CTL_STA_STO_SI       
#define I2C_STA_STO_SI_AA 	I2C_CTL_STA_STO_SI_AA    
#define I2C_STA_SI 	        I2C_CTL_STA_SI           
#define I2C_STA_SI_AA 	        I2C_CTL_STA_SI_AA         
#define I2C_STO_SI		I2C_CTL_STO_SI            
#define I2C_STO_SI_AA   	I2C_CTL_STO_SI_AA         
#define I2C_SI 			I2C_CTL_SI                
#define I2C_SI_AA	        I2C_CTL_SI_AA             
#define I2C_STA 	        I2C_CTL_STA               
#define I2C_STO 		I2C_CTL_STO               
#define I2C_AA 			I2C_CTL_AA     
#elif defined(__NUC240__) | defined(__NUC131__)
#define I2C_STA_STO_SI 		I2C_I2CON_STA_STO_SI       
#define I2C_STA_STO_SI_AA 	I2C_I2CON_STA_STO_SI_AA    
#define I2C_STA_SI 		I2C_I2CON_STA_SI           
#define I2C_STA_SI_AA 		I2C_I2CON_STA_SI_AA         
#define I2C_STO_SI		I2C_I2CON_STO_SI            
#define I2C_STO_SI_AA   	I2C_I2CON_STO_SI_AA         
#define I2C_SI 			I2C_I2CON_SI                
#define I2C_SI_AA		I2C_I2CON_SI_AA             
#define I2C_STA 		I2C_I2CON_STA               
#define I2C_STO 		I2C_I2CON_STO               
#define I2C_AA 			I2C_I2CON_AA                
#endif

#define I2C_SI_AA               (I2C_SI | I2C_AA)           

class TwoWire : public Stream {
public:
	TwoWire(I2C_T *twi, void(*begin_cb)(void));
	void begin();
	void begin(uint8_t);
	void begin(int);
	void beginTransmission(uint8_t);
	void beginTransmission(int);
	uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);
	uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
	uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t *, size_t);
	virtual int available(void);
	virtual int read(void);
	virtual int peek(void);
	virtual void flush(void);
	void onReceive(void(*)(int));
	void onRequest(void(*)(void));

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;

	void onService(void);

private:
	// RX Buffer
	uint8_t rxBuffer[BUFFER_LENGTH];
	uint8_t rxBufferIndex;
	uint8_t rxBufferLength;

	// TX Buffer
	uint8_t txAddress;
	uint8_t txBuffer[BUFFER_LENGTH];
	uint8_t txBufferLength;

	// Service buffer
	uint8_t srvBuffer[BUFFER_LENGTH];
	uint8_t srvBufferIndex;
	uint8_t srvBufferLength;

	// Callback user functions
	void (*onRequestCallback)(void);
	void (*onReceiveCallback)(int);

	// Called before initialization
	void (*onBeginCallback)(void);

	// TWI instance
	I2C_T *i2c;

	// TWI state
	enum TwoWireStatus {
		UNINITIALIZED,
		MASTER_IDLE,
		MASTER_SEND,
		MASTER_RECV,
		SLAVE_IDLE,
		SLAVE_RECV,
		SLAVE_SEND
	};
	TwoWireStatus status;

	// TWI clock frequency
	static const uint32_t I2C_CLOCK = 100000;

	// Timeouts (
	static const uint32_t TIMEOUT = 100;	
	
	
	void I2C_SlaveTRx(uint32_t u32Status);
};

#if I2C_MAX_COUNT > 0
extern TwoWire Wire;
#endif
#if I2C_MAX_COUNT > 1
extern TwoWire Wire1;
#endif

#endif

