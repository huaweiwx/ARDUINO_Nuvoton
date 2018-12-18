const int interruptA = 2;       // Set Interrupt 0 on pin 2

int clk = 2;     // PIN2
int DAT = 3;     // PIN3
int SW = 4;      // PIN4
int LED1 = 5;    // PIN5
int LED2 = 6;    // PIN6
int COUNT = 0;

void setup()
{
    attachInterrupt(interruptA, RoteStateChanged, FALLING);

    pinMode(clk, INPUT);
    pinMode(DAT, INPUT);
    pinMode(SW, INPUT);

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    if  (!(digitalRead(SW)))
    {
        COUNT = 0;
        Serial.println("STOP COUNT = 0");
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        delay (200);
    }
    Serial.println(COUNT);
}

//-------------------------------------------
void RoteStateChanged() //When CLK  FALLING READ DAT
{
    if  (digitalRead(DAT)) // When DAT = HIGH IS FORWARD
    {
        COUNT++;
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
    }
    else                   // When DAT = LOW IS BackRotate
    {
        COUNT--;
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, LOW);
    }
}
