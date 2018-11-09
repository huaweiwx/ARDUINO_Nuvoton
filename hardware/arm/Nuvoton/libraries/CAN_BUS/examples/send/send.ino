// demo: CAN-BUS, send data
#include <CAN.h>
#include "can_.h"

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

unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
void loop()
{
    // send data:  id = 0x00, standrad flame, data len = 8, stmp: data buf
    CAN_0.sendMsgBuf(0x00, 0, 8, stmp);
    delay(100);                       // send data per 100ms
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
