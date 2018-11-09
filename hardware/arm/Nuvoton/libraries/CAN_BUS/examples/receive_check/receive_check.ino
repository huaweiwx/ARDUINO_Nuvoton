// demo: CAN-BUS , receive data with check mode
// send data coming to fast, such as less than 10ms, you can use this way
// loovee, 2014-6-13


//#include <SPI.h>
#include <CAN.h>
#include "can_.h"


unsigned char Flag_Recv = 0;
unsigned char len = 0;
unsigned char buf[8];
char str[20];


CAN CAN_0;                 

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
}


void loop()
{
    if(CAN_MSGAVAIL == CAN_0.checkReceive())            // check if data coming
    {
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
