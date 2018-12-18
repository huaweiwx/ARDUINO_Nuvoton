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
 ****************************************************************************
   @file WireBase.h
   @author Trystan Jones <crenn6977@gmail.com>
   @brief Wire library, following the majority of the interface from Arduino.
          Provides a 'standard' interface to I2C (two-wire) communication for
          derived classes.

   Library created by crenn to allow a system which would provide users the
   'standardised' Arduino method for interfacing with I2C devices regardless of
   whether it is I2C hardware or emulating software.

   for EFM32/STM32/NUVOTON GENERIC by huaweiwx@sina.com 2018.10
*/

#ifndef _WIREBASE_H_
#define _WIREBASE_H_

#ifndef WIRE_BUFSIZ
#define WIRE_BUFSIZ 32
#endif

/* return codes from endTransmission() */
#define SUCCESS   0        /* transmission was successful */
#define EDATA     1        /* too much data */
#define ENACKADDR 2        /* received nack on transmit of address */
#define ENACKTRNS 3        /* received nack on transmit of data */
#define EOTHER    4        /* other error */

#define I2C_MSG_READ            0x1
#define I2C_MSG_10BIT_ADDR      0x2

typedef struct i2c_msg {
  uint16_t adr;                /**< Address */
  /**
     Bitwise OR of:
     - I2C_MSG_READ (write is default)
     - I2C_MSG_10BIT_ADDR (7-bit is default) */
  uint16_t flags;

  uint16_t length;              /**< Message length */
  uint16_t xferred;             /**< Messages transferred */
  uint8_t  *data;               /**< Data */
} i2c_msg;

#if USE_SOFTWARESTREAM >0
class WireBase : public Stream
#else
class WireBase
#endif
{
  public:
    WireBase() {}
    ~WireBase() {}

#if USE_SOFTWARESTREAM >0
    virtual int peek(){};
    virtual void flush(){};
#endif

#if USE_ITERATOR == 0
    void begin(uint8_t self_addr = 0){Init(self_addr);}
#endif
// Allow derived classes to overwrite begin function
//    virtual void begin(uint8_t self_addr= 0x00);
    void Init(uint8_t self_addr = 0)
	{
	  UNUSED(self_addr);
      tx_buf_idx = 0;
      tx_buf_overflow = false;
      rx_buf_idx = 0;
      rx_buf_len = 0;
    }

    void beginTransmission(uint8_t slave_address) {
      itc_msg.adr = slave_address;
      itc_msg.data = &tx_buf[tx_buf_idx];
      itc_msg.length = 0;
      itc_msg.flags = 0;
    }

    uint8_t endTransmission(uint8_t __attribute__ ((unused)) sendStop) {
      uint8_t retVal;
      if (tx_buf_overflow) return EDATA;

	  retVal = process();// Changed so that the return value from process is returned by this function see also the return line below
      tx_buf_idx = 0;
      tx_buf_overflow = false;
      return retVal;//SUCCESS;
    }

    inline uint8_t endTransmission(void) {
      return endTransmission(1);
    }

/*
   Request bytes from a slave device and process the request,
   storing into the receiving buffer.
*/
    uint8_t requestFrom(uint8_t address, uint16_t num_bytes) {
      if (num_bytes > WIRE_BUFSIZ) {
        num_bytes = WIRE_BUFSIZ;
      }
      itc_msg.adr = address;
      itc_msg.flags = I2C_MSG_READ;
      itc_msg.length = num_bytes;
      itc_msg.data = &rx_buf[rx_buf_idx];
      process();
      rx_buf_len += itc_msg.xferred;
      itc_msg.flags = 0;
      return rx_buf_len;
    }

/*
   Stack up bytes to be sent when transmitting
*/
    size_t write(uint8_t value) {
      if (tx_buf_idx == WIRE_BUFSIZ) {
        tx_buf_overflow = true;
        return 0;
      }
      tx_buf[tx_buf_idx++] = value;
      itc_msg.length++;
	  return 1;
    }

/*
   Stack up bytes from the array to be sent when transmitting
*/
    size_t write(uint8_t *buf, int len) {
      for (uint8_t i = 0; i < len; i++) {  
        if(write(buf[i]) ==0) return 0;
      }
      return len;
    }

    size_t write(char* buf) {
	  uint8_t len = 0;	
      uint8_t *ptr = (uint8_t*)buf;
      while (*ptr) {
        if(write(*ptr)) ptr++,len++;
		else return 0;
      }
	  return len;
    }

    inline int available() {
      return rx_buf_len - rx_buf_idx;
    }

    int read() {
      if (rx_buf_idx == rx_buf_len) {
        rx_buf_idx = 0;
        rx_buf_len = 0;
        return 0;
      } else if (rx_buf_idx == (rx_buf_len - 1)) {
        uint8_t temp = rx_buf[rx_buf_idx];
        rx_buf_idx = 0;
        rx_buf_len = 0;
        return temp;
      }
      return rx_buf[rx_buf_idx++];
    }
	
#if USE_SOFTWARESTREAM >0
	using Print::write;
#endif
  protected:

    i2c_msg itc_msg;
    uint8_t rx_buf[WIRE_BUFSIZ];      /* receive buffer */
    uint8_t rx_buf_idx;               /* first unread idx in rx_buf */
    uint8_t rx_buf_len;               /* number of bytes read */

    uint8_t tx_buf[WIRE_BUFSIZ];      /* transmit buffer */
    uint8_t tx_buf_idx;  // next idx available in tx_buf, -1 overflow
    boolean tx_buf_overflow;

// Force derived classes to define process function
    virtual uint8_t process() = 0;
};

#endif // _WIREBASE_H_
