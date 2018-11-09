int LedPinA = 5;
int LedPinB = 4;
int mercurySwitchPinA = 12;
int mercurySwitchPinB = 11;
int mercurySwitchStateA = 0;
int mercurySwitchStateB = 0;
int brightness   = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(LedPinA, OUTPUT);
    pinMode(LedPinB, OUTPUT);
    pinMode(mercurySwitchPinA, INPUT);
    pinMode(mercurySwitchPinB, INPUT);
}

void loop()
{
    Serial.print("mercurySwitchPinA =");
    Serial.print(mercurySwitchStateA);
    Serial.print(" mercurySwitchPinB =");
    Serial.println(mercurySwitchStateB);
    mercurySwitchStateA = digitalRead(mercurySwitchPinA);
    if (mercurySwitchStateA == LOW && brightness != 255)
    {
        brightness ++;
    }

    mercurySwitchStateB = digitalRead(mercurySwitchPinB);
    if (mercurySwitchStateB == LOW && brightness != 0)
    {
        brightness --;
    }
    analogWrite(LedPinA, brightness);  //  A few dark
    analogWrite(LedPinB, 255 - brightness);  // B few light
    delay(25);
}
