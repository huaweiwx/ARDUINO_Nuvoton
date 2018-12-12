/*
  PWM AnalogWrite arduino pin PB_5 with occupy duty 50%
  demo by huawei<huaweiwx@sina.com> 2016.9.18
 */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  analogWrite(PB_5, 0x1000 / 2); // 12bit occupy duty  50%
}

void loop() {
  digitalToggle(LED_BUILTIN);
  delay(500);
}

