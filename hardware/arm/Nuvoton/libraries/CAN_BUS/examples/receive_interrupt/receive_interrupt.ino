// demo: CAN-BUS, receive data with interrupt mode
// when in interrupt mode, the data coming can't be too fast, must >20ms, or else you can use check mode
// loovee, 2014-6-13

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

     CAN_0.attachInterrupt(CAN0_ISR); // start interrupt
}

void CAN0_ISR(void)
{
        Flag_Recv = 1;
}

void loop()
{
    if(Flag_Recv)                   // check if get data
    {
    
        Flag_Recv = 0;                // clear flag
        CAN_0.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i]);Serial.print("\t");
        }
        Serial.println();
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/