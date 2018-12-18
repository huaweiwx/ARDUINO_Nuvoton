int redpin = 11;    // select LED output pin for red LED
int bluepin =10;    // select LED output pin for blue LED
int greenpin =9;    // select LED output pin for green LED
int val;

void setup()
{
    pinMode(redpin, OUTPUT);
    pinMode(bluepin, OUTPUT);
    pinMode(greenpin, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    for(val=255; val>0; val--)
    {
        analogWrite(redpin, val);
        analogWrite(bluepin, 255-val);
        analogWrite(greenpin, 128-val);
        delay(1);
    }
    for(val=0; val<255; val++)
    {
        analogWrite(redpin, val);
        analogWrite(bluepin, 255-val);
        analogWrite(greenpin, 128-val);
        delay(1);
    }
    Serial.println(val, DEC);
}
