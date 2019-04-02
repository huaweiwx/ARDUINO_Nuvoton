/*
   NuConsole.ino use nulink console i/o demo by huaweiwx@sina.com 2018.11.25
   

   1 menu Serial communication option selected NuConsole
   2 Remember the NuConsole_InfoBlock adress at arduino build info window while update to mcu, 
     or search the sketch map file in the sketch path
   3 run NuConsole and modify Info Block Address as NuConsole_InfoBlock address
   4 Click the [start] in NuConsole window;
   5 at Transmit Text you can keyin string and click Enter for input
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin();
}

int count = 0;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("count: ");
  Serial.println(count++);
  digitalToggle(LED_BUILTIN);
  delay(1000);
}
