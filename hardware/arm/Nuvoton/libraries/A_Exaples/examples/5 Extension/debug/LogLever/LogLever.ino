/*
  LogLevel.ino
  
  fault:
    _Error_Handler(char* , uint32_t);
    assert_param(int condition);  /*USE_ASSERT be set only*/
    errorLedBlink(int); 
          
  debug:
    debug(const char *format, ...);
    debug_if(int condition, const char *format, ...);
    
  log: (if LogLever > 0)
     PRINT_FATAL(...)
     PRINT_ERROR(...)
     PRINT_WARNING(...)
     PRINT_INFO(...)
     PRINT_DEBUG(...)
     PRINT_TRACE(...)
*/

// the setup function runs once when you press reset or power the board
static int val = 0;
void setup() {
  Serial.begin(115200);
  while (!Serial) { /*if used usb serial,wait for it ready*/
  };
  delay(1000); /*wait for serial ready*/

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}
extern "C" void _Error_Handler(char* file, uint32_t line);
void test (int n) {
//only LogLever > 0	
  assert_param( n < 20);
  if ((n % 10) == 0) {
    PRINT_TRACE("val= %d\n", n);
  } else if ((n % 2) == 0) {
    PRINT_DEBUG("val= %d\n", n);
  } else {
    PRINT_INFO("val= %d\n", n);
  }
  
//for any LogLever value  
  if (n >20) {
    PRINT_INFO("\nval= %d must <= 30 \n", n);
    _Error_Handler(__FILENAME__, __LINE__);
   }
}

// the loop function runs over and over again forever
void loop() {
  val++;
  debug_if(val < 2, "val = %d\n", val);
  test(val);
  digitalToggle(LED_BUILTIN);
  delay(1000);
}
