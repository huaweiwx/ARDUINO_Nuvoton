/* vdos_spisdcard.ino stm32 vdisk/mcu administer
    ---------------------------------------------------------------------------------------
   from the menu
   Select Startup adr: flash(WhitRamboo xxkRAM used only)
   ---------------------------------------------------------------------------------------
   cmd usage:
   type help or h or ? for Display list of commands.

   ---------------------------------------------------------------------------------------
   tested for F103xE/F407xE  by huaweiwx@sina.com 2017.10

   ---------------------------------------------------------------------------------------
*/
// include the SD library:
#include <Streaming.h>
#include <STM32SD.h>
File root;
Sd2Card card;
SdFatFs fatFs;

// set up variables using the SD utility library functions:

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin SDCARD_CS
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// MKRZero SD: SDCARD_CS

#include <cmdline.h>
char cmdline[256];
int ptr;

#include <utils.h>
#include <LED.h>

void setup() {
  Serial.begin(115200);
  Led.Init();

  //for  use SerialUSB if selected from menu
#if (MENU_USB_SERIAL || MENU_USB_IAD)
  while (!Serial.available()) {
    Led.flash(10, 990, 1);
  }
#endif

  Serial.println(F("\n****************************************"));
  Serial.println(F("*        STM32 vdos demo v1.0          *"));
  Serial.println(F("*  Type help Display list of commands  *"));
  Serial.println(F("****************************************\n"));

  ptr = 0;
  Serial.print("Initializing SD card...");
#ifdef   SD_DETECT_PIN
  while (SD.begin(SD_DETECT_PIN) != TRUE)
#else
  while (SD.begin() != TRUE)
#endif
  {
    Led.flash(10, 190,1);
    Serial.print(".");
  }
  Serial.println("initialization done.");

  root = SD.openRoot();
  root.ls(LS_R | LS_DATE | LS_SIZE);
  root.close();

  Serial.print(F(">"));
}

boolean stringComplete = false;  // whether the string is complete
void loop() {
  int nStatus;
  if (stringComplete) {
    if (cmdline[0] > ' ') {
      nStatus = CmdLineProcess(cmdline);
      if (nStatus == CMDLINE_BAD_CMD)
      {
        Serial.println(F("Bad cmd!"));
      }
      else if (nStatus == CMDLINE_TOO_MANY_ARGS)
      {
        Serial.println(F("Too many args!"));
      }
      else if (nStatus != 0)
      {
        Serial.print(F("Cmd rtn err_code"));
        Serial.println(nStatus);
      }
    }
    ptr = 0;
    stringComplete = false;
    Serial.print(F("\r\n>"));
  }
#if defined(STM32GENERIC)
  serialEvent();
#endif
  Led.flash(10, 90, 1);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    cmdline[ptr++] = inChar;
    cmdline[ptr] = '\0';
    if ((inChar == '\n') || (inChar == '\r')) {
      stringComplete = true;
    }
  }
}

//*****************************************************************************
// This function implements the "help" command.  It prints a simple list of the
// available commands with a brief description.
//*****************************************************************************
void print_port(char* str, uint16_t val) {
  Serial <<  str << " : ";
  for (uint8_t i = 15; i > 0; i--) {
    if (val & (1 << i)) break;
    Serial << "0";
  }
  Serial << _BIN(val) << "(0x" << _HEX(val) << ")\n";
}

int Cmd_help(int argc, char *argv[])
{
  if (argc == 2) { //  ?[ pin/P/A/B/C/D]
    char* pstr = argv[1];
    if (isdigit(pstr[0])) {
      uint8_t pin = atoi(argv[1]);
      Serial << stm32PinName(pin) << "(" << argv[1] << "): " << digitalRead(pin) << "\n";
      return 0;
    }
    if (pstr[0] == 'P') {
      uint8_t pin = UTIL_Str2PortPin(argv[1]);
      if (pin == 0xff) {
        Serial << "err: pinName" << argv[1] << "\n";
        return 0;
      } else {
        Serial << argv[1] << "(" << pin << ") : " << digitalRead(pin) << "\n";
        return 0;
      }
    }
    if (pstr[0] == 'A') {
      print_port((char*)"GPIOA->IDR  ", GPIOA->IDR);
#if defined(STM32F1)
      print_port((char*)"      ->CRH  ", GPIOA->CRH & 0xffff);
      print_port((char*)"      ->CRL  ", GPIOA->CRL & 0xffff);
#else
      print_port((char*)"      ->MODER", GPIOA->MODER);
#endif
      return 0;
    }
    if (pstr[0] == 'B') {
      print_port((char*)"GPIOB->IDR  ", GPIOB->IDR);
#if defined(STM32F1)
      print_port((char*)"      ->CRH  ", GPIOB->CRH & 0xffff);
      print_port((char*)"      ->CRL  ", GPIOB->CRL & 0xffff);
#else
      print_port((char*)"      ->MODER", GPIOB->MODER);
#endif
      return 0;
    }
    if (pstr[0] == 'C') {
      print_port((char*)"GPIOC->IDR  ", GPIOC->IDR);
#if defined(STM32F1)
      print_port((char*)"      ->CRH  ", GPIOC->CRH & 0xffff);
      print_port((char*)"      ->CRL  ", GPIOC->CRL & 0xffff);
#else
      print_port((char*)"      ->MODER", GPIOC->MODER);
#endif
      return 0;
    }
#ifdef GPIOD
    if (pstr[0] == 'D') {
      print_port((char*)"GPIOD->IDR  ", GPIOD->IDR);
#if defined(STM32F1)
      print_port((char*)"      ->CRH  ", GPIOD->CRH & 0xffff);
      print_port((char*)"      ->CRL  ", GPIOD->CRL & 0xffff);
#else
      print_port((char*)"      ->MODER", GPIOD->MODER);
#endif
      return 0;
    }
#endif
#ifdef GPIOE
    if (pstr[0] == 'E') {
      print_port((char*)"GPIOE->IDR  ", GPIOE->IDR);
#if defined(STM32F1)
      print_port((char*)"      ->CRH  ", GPIOE->CRH & 0xffff);
      print_port((char*)"      ->CRL  ", GPIOE->CRL & 0xffff);
#else
      print_port((char*)"      ->MODER", GPIOE->MODER);
#endif
      return 0;
    }
#endif
#ifdef GPIOF
    if (pstr[0] == 'F') {
      print_port((char*)"GPIOF->IDR  ", GPIOF->IDR);
#if defined(STM32F1)
      print_port((char*)"      ->CRH  ", GPIOF->CRH & 0xffff);
      print_port((char*)"      ->CRL  ", GPIOF->CRL & 0xffff);
#else
      print_port((char*)"      ->MODER", GPIOF->MODER);
#endif
      return 0;
    }
#endif
#ifdef GPIOG
    if (pstr[0] == 'G') {
      print_port((char*)"GPIOG->IDR  ", GPIOG->IDR);
#if defined(STM32F1)
      print_port((char*)"      ->CRH  ", GPIOG->CRH & 0xffff);
      print_port((char*)"      ->CRL  ", GPIOG->CRL & 0xffff);
#else
      print_port((char*)"      ->MODER", GPIOG->MODER);
#endif
      return 0;
    }
#endif
#ifdef GPIOH
    if (pstr[0] == 'H') {
      print_port((char*)"GPIOH->IDR  ", GPIOH->IDR);
#if defined(STM32F1)
      print_port((char*)"      ->CRH  ", GPIOH->CRH & 0xffff);
      print_port((char*)"      ->CRL  ", GPIOH->CRL & 0xffff);
#else
      print_port((char*)"      ->MODER", GPIOH->MODER);
#endif
      return 0;
    }
#endif
#ifdef GPIOH
    if (pstr[0] == 'H') {
      print_port((char*)"GPIOH->IDR  ", GPIOH->IDR);
#if defined(STM32F1)
      print_port((char*)"      ->CRH  ", GPIOH->CRH & 0xffff);
      print_port((char*)"      ->CRL  ", GPIOH->CRL & 0xffff);
#else
      print_port((char*)"      ->MODER", GPIOH->MODER);
#endif
      return 0;
    }
#endif
    Serial << argc << "  " <<  argv[1] << " ??\n";
  }

  tCmdLineEntry *pEntry;
  pEntry = &g_sCmdTable[0];
  Serial.println(F("\r\nAvailable commands:\r\n------------------\n"));
  while (pEntry->pcCmd)
  {
    Serial.print( pEntry->pcCmd);
    Serial.println(pEntry->pcHelp);
    pEntry++;
  }

  Serial << "\nPIN list:";
  for (uint8_t i = 0; i < sizeof(variant_pin_list) / sizeof(variant_pin_list[0]); i++)
    Serial << stm32PinName(i) << "("  << i  << "), ";

  uint8_t leds[] = {LEDS_LIST};
  Serial << "\nLED list:\n";
  for (uint8_t i = 0; i < sizeof(leds) / sizeof(leds[0]); i++)
    Serial << "LED" << i << "_BUILTIN(" <<  stm32PinName(leds[i]) << "), ";

#ifdef KEYS_LIST
  uint8_t keys[] = {KEYS_LIST};
  Serial << "\nKEYS list:";
  for (uint8_t i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
    Serial << "BUILTIN" << i << "(" << stm32PinName(keys[i]) << "), ";
#endif

#ifdef MOSI
  Serial << "\nSPI pins:";
  Serial << "MOSI(" <<  stm32PinName(MOSI);
  Serial << "), MISO(" <<  stm32PinName(MISO);
  Serial << "), SCK(" <<  stm32PinName(SCK);
  Serial << "), SS(" <<  stm32PinName(SS) << "),";
#endif

#ifdef SDA
  Serial << "\nI2C pins:";
  Serial << "SDA:" <<  stm32PinName(SDA);
  Serial << ",SCL:" <<  stm32PinName(SCL);
#endif

#ifdef DBGMCU
  Serial << "\nMCU_IDCODE:" << _HEX(HAL_GetDEVID());
#endif

#ifdef OB_BASE
  uint32_t UID[3];
#if defined(STM32F0)||defined(STM32F3)
  UID[0] = HAL_GetUIDw0();
  UID[1] = HAL_GetUIDw1();
  UID[2] = HAL_GetUIDw2();
#else
  HAL_GetUID(UID);
#endif
  Serial << "\nUSERID:" << _HEX(UID[0]) << " " << _HEX(UID[1]) << " " <<  _HEX(UID[2]);
#endif
  return (0);
}

int Cmd_dir(int argc, char *argv[])  //exp: dir/ls
{
  UNUSED(argc);  /*unused argc, move warnign*/
  UNUSED(argv);  /*unused argc, move warnign*/
  volatile uint32_t useradr;
  //  SD.cacheClear();
  Serial << "ls files:\n";
  root = SD.openRoot();
  root.ls(LS_R | LS_DATE | LS_SIZE);
  root.close();
 
  Serial << "\ncodes on slot:\n";
  for (int i = 0; i < (appCodeSegAddr[0] + 1); i++) {
    if (i > 0)
      useradr = FLASH_BASE + appCodeSegAddr[i] * 1024;
    else {
      useradr = USER_CODE_RAM;
    }
    Serial << i << "# addr:0x";
    if (useradr < 0x10000000) Serial << "0";
    Serial << _HEX(useradr);
    if (UTIL_checkUserCode(useradr))
      Serial << " is app.\n";
    else
      Serial << " is free.\n";
  }
  return (0);
}

void show_addr(uint32_t addr, uint8_t* data, uint8_t num = 16, uint8_t asc = 1);
void show_addr(uint32_t addr, uint8_t* data, uint8_t num, uint8_t asc) {
  Serial << ((addr < 0x10) ? "000" : ((addr < 0x100) ? "00" : ((addr < 0x1000) ? "0" : ""))) << _HEX(addr) << " :";
  for (uint8_t i = 0; i < num; i++) {
    if (data[i] < 0x10) Serial << "0";
    Serial << _HEX(data[i]) << " ";
  }
  if (asc) {
    Serial << "    ";
    for (uint8_t i = 0; i < num; i++)
      Serial.write((isprint (data[i])) ? data[i] : '.');
  }
}

int Cmd_dispmen (int argc, char *argv[]) {
  static uint32_t addr = 0;
  uint8_t data[16];
  if (argc == 2) {
    char *pstr = argv[1];
    addr = UTIL_getNum(pstr) & 0xfffffff0;
  }
  for (uint8_t i = 0; i < 16; i++) {
    volatile uint8_t *mem = (uint8_t*) (addr);
    for (uint8_t j = 0; j < 16; j++) {
      data[j] = mem[j];
    }
    show_addr(addr, data);
    Serial << "\n ";
    addr += 0x10;
  }
  return (0);
}

#if defined(STM32F4)||(FLASH_BANK1_END >  0x0801FFFFU)   //for hight density  xC/D/E
//exp: load mydemo.bin
int Cmd_load(int argc, char *argv[]) {
  volatile uint8_t* prog_ram =  (uint8_t *) USER_CODE_RAM;
  for (uint8_t i = 0; i < argc; i++)
  {
    Serial.print(argv[i]);
    Serial.print(F("  "));
  };
  Serial.println();

  //  SD.cacheClear();
  File f = SD.open(argv[1], FILE_READ);
  if (!f) {
    Serial << "file: " << argv[1] << "no found!\n";
    return 0;
  }

  uint32_t fsize = f.size();
  if ( fsize > MAX_PROG_RAM) {
    Serial << "file " << argv[1] << "too larger to fit in ram!\n";
    return 0;
  }

  uint16_t i = 0;
  uint8_t t = 1;
  char c;
  while (t) {
    if (f.available()) {
      c = f.read();
    } else {
      c =  0;
      t = 0;
    }
    prog_ram[i++] = (uint8_t) c;
  }
  f.close();

  if (UTIL_checkUserCode(USER_CODE_RAM))
  {
    Serial << "load ok! reset run it\n";
  } else {
    Serial << "file: " << argv[1] << "is unavailed!\n";
  }
  return 0;
}
#endif

//exp: typr test.txt
int Cmd_type(int argc, char *argv[])
{
  if (!(argc == 2)) return 0;
  //  SD.cacheClear();
  File f = SD.open(argv[1], FILE_READ);
  if (!f) {
    Serial << "file: " << argv[1] << "no found!\n";
    return 0;
  }
  char c;
  while (f.available()) {
    c = f.read();
    if (isprint(c) || (c == '\r') || (c == '\n')) Serial.write(c);
    else Serial.write('.');
  }
  f.close();
  return 0;
}

//exp:go 1/2/...
int Cmd_go(int argc, char *argv[])
{
  if (!(argc == 2)) return 0;
  volatile uint32_t useradr;
  Serial << "go " << argv[1] << "\n";
  int i = atoi(argv[1]);
  if (i < (appCodeSegAddr[0] + 1)) {
    if (i == 0) {
      useradr =  USER_CODE_RAM;
    } else {
      useradr = FLASH_BASE + appCodeSegAddr[i] * 1024;
    }

    if (UTIL_checkUserCode(useradr))
    {
      Serial << "check ok and goto " << _HEX(useradr) << ".....\n" << _endl;
#if (MENU_USB_SERIAL||MENU_USB_MASS_STORAGE||MENU_USB_IAD)
      USBDeviceFS.end();
#endif
      delay(1000); /*wait  serial complated */

      //    Serial1.end();  /*if open close it*/
      //    Serial2.end();  /*if open close it*/
      //    UTIL_jumpToUser(useradr);
      start_application(useradr);
    } else {
      Serial << "slot: " << argv[1] << " is unavailed!\n";
    }
  }
  return 0;
}

/*---------------------arduino func----------------------------*/
static uint8_t getpin(char* str) {
  uint8_t pin = 0xff;
  if (str[0] == 'P')    pin = UTIL_Str2PortPin(str);
  else if (UTIL_isHexStr(str)) pin = UTIL_hexNum(str);
  else if (isdigit(str[0]))  pin = atoi(str);
  return pin;
}

// This function implements the "dw" command. bit write to a pin output
// Usage: dw pin 0/1
int Cmd_digitalWrite(int argc, char *argv[])
{
  static uint8_t v;
  static uint8_t pin = 0xff;
  uint8_t tmp;

  if (argc > 1) {
    tmp = getpin(argv[1]);
    if (tmp < 0xff) pin = tmp;
  }
  if (pin == 0xff) {
    Serial << "err: pinName" << argv[1] << "\n";
    return 0;
  }

  if (argc > 2)
    v = atoi(argv[2]);

  if (v) {
    digitalWrite(pin, HIGH);   // turn on/off the LED
  } else {
    digitalWrite(pin , LOW);
  };

  return (0);
}

// This function implements the "dt" command. toggle pin H/L
// Usage: dt pin
static int Cmd_digitalToggle(int argc, char *argv[])
{
  static uint8_t pin = 0xff;
  uint8_t tmp;
  if (argc > 1) {
    tmp = getpin(argv[1]);
    if (tmp < 0xff) pin = tmp;
  }
  if (pin == 0xff) {
    Serial << "err: pinName" << argv[1] << "\n";
    return 0;
  }
  digitalToggle(pin);
  return (0);
}

// This function implements the "aw" command. analog pin output
// Usage: aw pin byte
static int Cmd_analogWrite(int argc, char *argv[])
{
  static uint16_t v;
  static uint8_t pin = 0xff;
  uint8_t tmp;

  if (argc > 1) {
    tmp = getpin(argv[1]);
    if (tmp < 0xff) pin = tmp;
  }
  if (pin == 0xff) {
    Serial << "err: pinName" << argv[1] << "\n";
    return 0;
  }

  if (argc > 2) {
    v = atoi(argv[2]);
  }

  analogWrite(pin, v);
  return (0);
}

// This function implements the "ar" command. analog pin read input
// Usage: ar pin
static int Cmd_analogRead(int argc, char *argv[])
{
  static uint8_t pin = 0xff;
  uint8_t tmp;
  if (argc > 1) {
    tmp = getpin(argv[1]);
    if (tmp < 0xff) pin = tmp;
  }
  if (pin == 0xff) {
    Serial << "error: pinName" << argv[1] << "\n";
    return 0;
  }
  Serial << stm32PinName(pin) << "(" << pin  << "):"  << analogRead(pin) << "\n";
  return (0);
}

/* ----------------This function implements the "pm" command. Set a pin input/output mode  --------------------------*/
// Usage: pm pin mode[0/1/2]
static int Cmd_pinMode(int argc, char *argv[])
{
  static uint8_t pin = 0xff;
  static uint8_t mode = 0;
  uint8_t tmp;
  if (argc > 1) {
    tmp = getpin(argv[1]);
    if (tmp < 0xff) pin = tmp;
  }
  if (pin == 0xff) {
    Serial << "err: pinName" << argv[1] << "\n";
    return 0;
  }

  if (argc > 2) {
    tmp = getpin(argv[2]);
    if (tmp) mode = tmp;
    else    mode = 0;
  }
  pinMode(pin , mode);
  Serial << stm32PinName(pin) << (mode ? " OUTPUT" : " INPUT") << "\n";
  return (0);
}

/*-------------  This function implements the "si" command. shiftIn ----------------------------*/
// Usage: si dpin cpin order
int Cmd_shiftin(int argc, char *argv[])
{
  uint8_t val;
  static uint8_t dpin = 0xff;
  static uint8_t cpin = 0xff;
  static uint8_t ord = 1;
  uint8_t pin;
  if (argc > 1) {
    pin = getpin(argv[1]);
    if (pin < 0xff) dpin = pin;
  }
  if (argc > 2) {
    pin = getpin(argv[2]);
    if (pin < 0xff) cpin = pin;
  }
  if (argc > 3) {
    pin = getpin(argv[3]);
    if (pin < 0xff) ord = pin;
  }

  if ((dpin == 0xff) || (cpin == 0xff))
    Serial.println(F(" argc err!\r\n"));
  val = shiftIn(dpin, cpin, ord);
  Serial << "\nshiftIn val=" << _HEX(val) << "\n";
  return (0);
}

/*--------------  This function implements the "so" command. shiftIn---------------------------------*/
// Usage: so val dpin cpin order
int Cmd_shiftout(int argc, char *argv[])
{
  static uint8_t val = 0;
  static uint8_t dpin = 0xff;
  static uint8_t cpin = 0xff;
  static uint8_t ord = 1;
  uint8_t tmp;
  if (argc > 1) {
    tmp = getpin(argv[1]);
    if (tmp < 0xff) val = tmp;
  }
  if (argc > 2) {
    tmp = getpin(argv[2]);
    if (tmp < 0xff) dpin = tmp;
  }
  if (argc > 3) {
    tmp = getpin(argv[3]);
    if (tmp < 0xff) cpin = tmp;
  }

  if (argc > 4) {
    tmp = getpin(argv[3]);
    if (tmp < 0xff) ord = tmp;
  }

  if ((dpin == 0xff) || (cpin == 0xff))
    Serial.println(F(" argc err!\r\n"));
  shiftOut(dpin, cpin, ord, val);

  Serial << "shiftout " << _HEX(val) << " ok\n";
  return (0);
}

/*------------- This function implements the "Cmd_pulse" command. shiftIn -------------------*/
// Usage: pulse pin state
int Cmd_pulsein(int argc, char *argv[])
{
  uint32_t val;
  static uint8_t ppin = 0xff;
  static uint8_t state = 1;
  uint8_t tmp;
  if (argc > 1) {
    tmp = getpin(argv[1]);
    if (tmp < 0xff) ppin = tmp;
  }
  if (argc > 2) {
    tmp = getpin(argv[2]);
    if (tmp < 0xff) state = tmp;
  }

  if (ppin == 0xff)
    Serial.println(F(" argc err!\r\n"));

  val = pulseIn(ppin, state);
  Serial << "\npulseIn:" << val << " microseconds\n";
  return (0);
}

/*----------- This function implements the "ee" command. shiftIn------------------------------*/
#include <exteeprom.h>
EXTEEPROM ee;
int Cmd_eeprom(int argc, char *argv[])// Usage: so val dpin cpin order
{
  static uint8_t op = 0;  //opration 0 uninit/1 init/2 read/3 write
  static uint16_t addr = 0;
  uint8_t  val[16];
  char c;
  File f;
  if (argc > 1) {
    if (op) {  // inited
      if (argv[1][0] == 'f')     //flash eeprom from file
        op = 5;
      else if (argv[1][0] == 'd') //dump eeprom to file
        op = 4;
      else  if (argv[1][0] == 'w') //write datas to addr
        op = 3;
      else if (argv[1][0] == 'r')  //view datas
        op = 2;
    }

    if (argv[1][0] == 'i')  //init device
      op = 1;
  }

  if ((argc > 2) && (op < 4))
    addr = UTIL_getNum(argv[2]);

  if (argc > 3) {
    if (op == 1)
      for (uint8_t i = 0; i < (argc - 3) ; i++)  val[i] = getpin(argv[i + 3]);
    else
      for (uint8_t i = 0; i < (argc - 3) ; i++)  val[i] = UTIL_getNum(argv[i + 3]);
  }

  switch (op) {
    case 0:
      Serial << "\nI2C eeprom un Inited!";
      break;
    case 1:
      if (argc > 4) {
        if ((val[2] < 0xff) && (val[1] < 0xff)) {
          ee.setPins(val[0], val[1]);
        } else {
          Serial << "\nI2C eeprom scl sda pin input err!";
          return 1;
          break;
        }
      } else {
        val[2] = 0x50;
      }

      if (argc > 2) ee.pdata->dev = (uint16_t)(((uint32_t)addr << 7) - 1);

      if (ee.begin(val[2])) {
        Serial << "\neeprom init err!  dev:24C " << ee.pdata->dev << "  at adr 0x" << _HEX(ee.pdata->adr);
        op = 0;
      } else {
        Serial << "\neeprom init ok!  at adr 0x" << _HEX(ee.pdata->adr) << " is AT24C";
        switch (ee.pdata->dev) {
          case AT24C01:
            Serial << "01";
            break;
          case AT24C02:
            Serial << "02";
            break;
          case AT24C04:
            Serial << "04";
            break;
          case AT24C08:
            Serial << "08";
            break;
          case AT24C16:
            Serial << "16";
            break;
          case AT24C32:
            Serial << "32";
            break;
          case AT24C64:
            Serial << "64";
            break;
          case AT24C128:
            Serial << "128";
            break;
          case AT24C256:
            Serial << "256";
            break;
          case AT24C512:
            Serial << "512";
            break;
        } //end switch(dev)
        op++;
      } //end if
      break;
    case 3:  //write
      if (argc > 3)
        ee.writeBuf(addr, val, (uint16_t)(argc - 3));
      Serial << "\nwrite " << argc - 3 << "data ok\n";

    //		break;
    case 2: //view read
      addr &= 0xfff0;
      ee.readBuf(addr, val, (uint16_t)16);
      show_addr(addr, val);
      Serial << "\n ";
      addr += 0x10;
      break;
    case 4:  //dump
      //      SD.cacheClear();
      f = SD.open(argv[2], FILE_WRITE);
      if (!f) {
        Serial << "\nfile: " << argv[2] << " open err!";
        return 0;
      }
      addr = 0;
      while (addr < (ee.pdata->dev + 1)) {
        c = ee.read(addr++);;
        f.write(c);
      }
      f.close();
      break;
    case 5:  //flash
      //      SD.cacheClear();
      f = SD.open(argv[2], FILE_READ);
      if (!f) {
        Serial << "\nfile: " << argv[2] << "no found!";
        return 0;
      }
      int fsize = f.size();
      if ( fsize > (ee.pdata->dev + 1)) {
        Serial << "\nfile " << argv[2] << "too larger to fit in eeprom!\n";
        return 0;
      }

      addr = 0;
      while (addr < fsize) {
        if (f.available()) {
          c = f.read();
          ee.write(addr++, c);
        } else {
          f.close();
          return (0);
        }
      }
      break;
  } //end switch(op)


  return (0);
}

tCmdLineEntry g_sCmdTable[] =
{
  { "help",   Cmd_help,      " : Display list of commands & get mcu info..."} ,
  { "?",      Cmd_help,   "    : alias for help"} ,

  //debug
  { "d",      Cmd_dispmen,   "    : disp memory([addr])"} ,

  //vdisk function
  { "dir",    Cmd_dir,      "  : list vdisk files"} ,
  { "ls",     Cmd_dir,      "   : alias for dir"} ,
#if defined(STM32F4)||(FLASH_BANK1_END >  0x0801FFFFU)   //for hight density  xC/D/E
  { "load",   Cmd_load,      " : chech bin file and load it if available"} ,
#endif
  { "type",   Cmd_type,      " : type a txt file(filename)"} ,

  //go flash addr
  { "go",     Cmd_go,      "   : goto n slot addr running(slot#)"},

  //arduino
  { "pm",     Cmd_pinMode, "   : Set pinMode(pin,mode" } ,
  { "dw",     Cmd_digitalWrite, "   : digitalWrite(pin,val)" } ,
  { "dt",     Cmd_digitalToggle, "   : digitalToggle(pin)"  },
  { "aw",     Cmd_analogWrite, "   : analogWrite(pin,val)"} ,
  { "ar",     Cmd_analogRead,  "   : analogRead(pin)"},
  { "si",     Cmd_shiftin,     "   : shiftIn([dpin cpin order])"} ,
  { "so",     Cmd_shiftout,    "   : shiftOut(val[ dpin cpin order])"},
  { "pulse",  Cmd_pulsein,     ": pulseIn([pin state])"} ,

  { "ee",     Cmd_eeprom,    "   : i2c eeprom read/write[adr ...."},

  {  0, 0, 0 }
};
