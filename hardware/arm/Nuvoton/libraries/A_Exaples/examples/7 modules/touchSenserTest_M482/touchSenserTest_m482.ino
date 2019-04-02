#define SENSER_GND PB_2
#define SENSER_VCC PB_3
#define SENSER_PIN PB_4
void setup() {
#ifdef    SENSER_GND
  pinMode(SENSER_GND, OUTPUT);
  digitalWrite(SENSER_GND, LOW);
#endif
#ifdef    SENSER_VCC
  pinMode(SENSER_VCC, OUTPUT);
  digitalWrite(SENSER_VCC, HIGH);
#endif

  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SENSER_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(SENSER_PIN))
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);
}
