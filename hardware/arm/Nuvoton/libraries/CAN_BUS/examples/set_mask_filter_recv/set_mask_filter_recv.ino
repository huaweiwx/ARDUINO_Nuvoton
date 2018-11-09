// demo: CAN-BUS Shield, receive data with interrupt mode, and set mask and filter
//
// when in interrupt mode, the data coming can't be too fast, must >20ms, or else you can use check mode
// loovee, 2014-7-8

#include <CAN.h>
#include "can_.h"

CAN CAN_0;   


unsigned char Flag_Recv = 0;
unsigned char len = 0;
unsigned char buf[8];
char str[20];

void setup()
{
    Serial.begin(115200);

START_INIT:

    if(CAN_OK == CAN_0.begin(CAN_500KBPS))                   // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init ok!");
    }
    else
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(100);
        goto START_INIT;
    }


    /*
     * set mask, set both the mask to 0x3ff
     */
    CAN_0.init_Mask(0, 0, 0x3ff);                         // there are 2 mask in mcp2515, you need to set both of them
    CAN_0.init_Mask(1, 0, 0x3ff);
    
    
    /*
     * set filter, we can receive id from 0x04 ~ 0x09
     */
    CAN_0.init_Filt(0, 0, 0x04);                          // there are 6 filter in mcp2515
    CAN_0.init_Filt(1, 0, 0x05);                          // there are 6 filter in mcp2515
    
    CAN_0.init_Filt(2, 0, 0x06);                          // there are 6 filter in mcp2515
    CAN_0.init_Filt(3, 0, 0x07);                          // there are 6 filter in mcp2515
    CAN_0.init_Filt(4, 0, 0x08);                          // there are 6 filter in mcp2515
    CAN_0.init_Filt(5, 0, 0x09);                          // there are 6 filter in mcp2515

}

void loop()
{
                      
    if(CAN_MSGAVAIL == CAN_0.checkReceive()) // check if get data
    {
    
        Flag_Recv = 0;                // clear flag
        CAN_0.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        Serial.println("\r\n------------------------------------------------------------------");
        Serial.print("Get Data From id: ");
        Serial.println(CAN_0.getCanId());
        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print("0x");
            Serial.print(buf[i], HEX);
            Serial.print("\t");
        }
        Serial.println();
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/