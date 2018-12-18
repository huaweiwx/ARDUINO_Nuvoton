int Relay = 10;
 
void setup()
{
    pinMode(Relay, OUTPUT);     
}
void loop()
{

    digitalWrite(Relay, HIGH);    
    delay(100);
    digitalWrite(Relay, LOW);      
    delay(100);
}