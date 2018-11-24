/*
  Bi_LED.ino  Bicolor/bidirectional LED demo
  双色无极性发光二极管控制示例

  应用程序接口函数 (API)：
  void Init(void)          : 库初始化(library initialization)
  uint8_t read(void)       : 读取状态(read status)
  void write(uint8_t val)  ：写数据(write Data) 1 A ON /2 B ON / 0 or 3 all OFF
  void toggle(void)        ：翻转(toggle)
  void on(uint8_t val = 1) ：写(write) 1
  void off(void)           ：写(write) 0
  operator uint8_t ()      : 读(read)
  operator = (T value)     : 写(write)

  双色二极管串联570欧保护电阻，通过MCU两个脚控制(Bicolor LED series 570om protective resistor, controlled by MCU two feet)
*/
#include "BiLED.h"

/*Nuvoton M482 use PB_4/PB_5 demo*/
#define BILEDPIN0 PB_4
#define BILEDPIN1 PB_5

BILEDClass myLED(BILEDPIN0, BILEDPIN1);

void setup() {
  myLED.Init();
  myLED = 1;
}

void loop() {
  myLED.toggle();
  delay(500);
}
