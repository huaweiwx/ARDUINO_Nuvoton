/******************************************************************************
   The MIT License

   Copyright (c) 2010 LeafLabs LLC.

   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without
   restriction, including without limitation the rights to use, copy,
   modify, merge, publish, distribute, sublicense, and/or sell copies
   of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 *****************************************************************************/

/**
   @file Wire.h
   @author Trystan Jones <crenn6977@gmail.com>
   @brief Wire library, uses the WireBase to create the primary interface
          while keeping low level interactions invisible to the user.

   Library for STM32GENERIC by huaweiwx@sina.com 2017.10 
*/

#ifndef _WIRESOFT_H_
#define _WIRESOFT_H_

#include "Arduino.h"
#include "WireBase.h"

#define SOFT_STANDARD  (((F_CPU /10000) * 375)/100000)  /*200 Khz*/
#define SOFT_FAST 0

#define SOFTI2C_WRITE 0
#define SOFTI2C_READ  1

/* 10 cycle */
#define I2C_DELAY(x) do{for(int i=0;i<x;i++) {asm volatile("nop");}}while(0)

#define BUFFER_LENGTH 32

class TwoWireSoft : public WireBase {
  public:
    ARDUINOPIN_TypeDef sda;
	ARDUINOPIN_TypeDef scl;
    uint8_t i2c_delay;
	
    TwoWireSoft(ARDUINOPIN_TypeDef  sda,
                ARDUINOPIN_TypeDef  scl, 
	            uint8_t i2c_delay = SOFT_STANDARD )
                : sda(sda), scl(scl), i2c_delay(i2c_delay) {}
				
    void Init(uint8_t self_addr = 0) {
      WireBase::Init(self_addr);
      pinMode(this->scl, OUTPUT_OD);
      pinMode(this->sda, OUTPUT_OD);
      sclPin(HIGH);
      sdaPin(HIGH);
    }
    void deInit(){
      if (this->scl) pinMode(this->scl, INPUT);	  
      if (this->sda) pinMode(this->sda, INPUT);
    }
	
#if USE_ITERATOR == 0  /*for stl begin/end is keywords for iteration*/
    __deprecated("This wire init func, if you use begin() as iterator must set USE_ITERATOR to 1, chandged by huaweiwx")
    void begin(uint8_t self_addr = 0){Init(self_addr);} 
     __deprecated("This wire deInit func, if you use begin() as iterator must set USE_ITERATOR to 1, chandged by huaweiwx")
   void end(){deInit();}
#endif

    ~TwoWireSoft(){
	  deInit();	
	}
	
    void sclPin(bool state) {
      I2C_DELAY(this->i2c_delay);
      digitalWrite(this->scl, state);
      //Allow for clock stretching - dangerous currently
      if (state == HIGH) {
        while (digitalRead(this->scl) == 0);
      }
    }

    void sdaPin(bool state) {
      I2C_DELAY(this->i2c_delay);
      digitalWrite(this->sda, state);
    }
	
    void i2c_start() {
      sdaPin(LOW);
      sclPin(LOW);
    }
	
    void  i2c_stop() {
      sdaPin(LOW);
      sclPin(HIGH);
      sdaPin(HIGH);
    }
    /*
       Gets an ACK condition from a slave device on the bus
    */
    bool i2c_get_ack() {
      sclPin(LOW);
      sdaPin(HIGH);
      sclPin(HIGH);
	  
      bool ret = !digitalRead(this->sda);
      sclPin(LOW);
      return ret;
    }

    /*
       Creates a ACK condition on the bus
    */
    void i2c_send_ack() {
      sdaPin(LOW);
      sclPin(HIGH);
      sclPin(LOW);
    }
	
    void i2c_send_nack() {
      sdaPin(HIGH);
      sclPin(HIGH);
      sclPin(LOW);
    }

    uint8_t i2c_shift_in() {
      uint8_t data = 0;
      sdaPin(HIGH);
      int i;
      for (i = 0; i < 8; i++) {
        sclPin(HIGH);
        data |= digitalRead(this->sda) << (7 - i);
        sclPin(LOW);
      }

      return data;
    }

    void i2c_shift_out(uint8_t val) {
      int i;
      for (i = 0; i < 8; i++) {
        sdaPin(!!(val & (1 << (7 - i)) ) );
        sclPin(HIGH);
        sclPin(LOW);
      }
    }


  protected:
    /*
       Processes the incoming I2C message defined by WireBase
    */
    uint8_t process() {
      itc_msg.xferred = 0;

      uint8_t sla_addr = (itc_msg.adr << 1);
      if (itc_msg.flags == I2C_MSG_READ) {
         sla_addr |= SOFTI2C_READ;
      }
	  
      i2c_start();
      // shift out the address we're transmitting to
      i2c_shift_out(sla_addr);
      if (!i2c_get_ack()){
        i2c_stop();// Roger Clark. 20141110 added to set clock high again, as it will be left in a low state otherwise
        return ENACKADDR;
      }
	  
      // Recieving
      if (itc_msg.flags == I2C_MSG_READ) {
        while (itc_msg.xferred < itc_msg.length) {
          itc_msg.data[itc_msg.xferred++] = i2c_shift_in();
          if (itc_msg.xferred < itc_msg.length){
            i2c_send_ack();
          }else{
            i2c_send_nack();
          }
        }
      }
      // Sending
      else {
        for (uint8_t i = 0; i < itc_msg.length; i++) {
          i2c_shift_out(itc_msg.data[i]);
          if (!i2c_get_ack()){
            i2c_stop();  // Roger Clark. 20141110 added to set clock high again, as it will be left in a low state otherwise
            return ENACKTRNS;
          }
          itc_msg.xferred++;
        }
      }
      i2c_stop();
      return SUCCESS;
    }
};

//extern TwoWireSoft WireSoft;

#endif // _WIRE_H_
