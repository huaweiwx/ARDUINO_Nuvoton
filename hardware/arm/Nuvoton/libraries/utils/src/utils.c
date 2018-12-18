/*
  utils.c utility for arduino huaweiwx@sina.com 2017.11.2
*/
#include <Arduino.h>
#include "ctype.h"  /*isdigit isxdigit*/
/*----------------------------------------------------------------------------*/
uint8_t UTIL_toDigit(char x) {
  if (x >= '0' && x <= '9') return x - '0';
  if (x >= 'a' && x <= 'f') return x - 'a' + 10;
  if (x >= 'A' && x <= 'F') return x - 'A' + 10;
  return 0;
}

int32_t UTIL_num(char * str) {
  return atol(str);
}

uint8_t isHex(char* str) {
  if (str[0] == '0')
    if ((str[1] == 'x') || (str[1] == 'X')) return 1;
  return 0;
}

uint32_t UTIL_hexNum(char* str) {
  int32_t xval = 0;

  for (uint8_t i = 2; i < 10; i++) //i=2 skip  0x or 0X
  {
    if (isxdigit(str[i])) {
      uint8_t val = UTIL_toDigit(str[i]);
      xval = xval * 16 + val;
    } else {
      break;
    }
  }
  return xval;
}

uint32_t UTIL_getNum(char* str) {
  return (isHex(str) ? UTIL_hexNum(str) : (uint32_t)UTIL_num(str));
}
