int Led=13; //define LED Interfac
int buttonpin=3; //define the key switch sensor interface
int val; //define numeric variables val
void setup()
{  
  pinMode(Led,OUTPUT); //define LED as output interace
  pinMode(buttonpin,INPUT); //define the key switch sensor output interface
}
void loop()
{
  val=digitalRead(buttonpin); //digital interface will be assigned a value of 3 to read val
  if(val==HIGH)
    digitalWrite(Led, HIGH);
  else
    digitalWrite(Led, LOW);
}
