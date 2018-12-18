int ledPin=13;
int sensorPin=A0;

double alpha=0.75;
int period=20;
double change=0.0;

void setup()
{
    Serial.begin(115200);
    pinMode(ledPin,OUTPUT);
}

void loop()
{
    static double oldValue=0;
    static double oldChange=0;
    int rawValue=analogRead(sensorPin);
    double value=alpha*oldValue+(1-alpha)*rawValue;

    change=value-oldValue;
    digitalWrite(ledPin,(change<0.0&&oldChange>0.0));

    Serial.print(rawValue);
    Serial.print(",");
    Serial.println(value);

    oldValue=value;
    oldChange=change;
    delay(period);
}