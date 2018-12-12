/* systicCallback test
 * huaweiwx@sina.com 2017.12.22
 */
#define led LED_BUILTIN

bool state = LOW;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  digitalWrite(led,state);
}

/* 
   compatibility with stm32 hal lib systick callback
   和stm32 hal 库 systick 回调函数兼容
 */
void HAL_SYSTICK_Callback(void)
{
  static uint32_t cnt = 0;
  cnt++;
  if (cnt >= 1000) { /*1000 ticks= 1s*/
    state = !state;
    cnt = 0;
  }
}
