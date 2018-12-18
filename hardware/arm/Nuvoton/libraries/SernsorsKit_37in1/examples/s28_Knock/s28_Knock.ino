int Led=13;
int Knock=10;
int val;
void setup()
{
    pinMode(Led,OUTPUT);
    pinMode(Knock,INPUT);
}
void loop()
{
    val=digitalRead(Knock);
    if(val==HIGH)
        digitalWrite(Led,HIGH);

    else
        digitalWrite(Led,LOW);
}