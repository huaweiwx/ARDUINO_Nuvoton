int Led=13;
int SENSOR=A0;
int val;
void setup()
{
  pinMode(Led,OUTPUT);
  Serial.begin(115200);
}
void loop()
{
  val=analogRead(SENSOR);
  digitalWrite(Led,HIGH);
  delay(val);
  digitalWrite(Led,LOW);
  delay(val);
  Serial.println(val,DEC);
}
