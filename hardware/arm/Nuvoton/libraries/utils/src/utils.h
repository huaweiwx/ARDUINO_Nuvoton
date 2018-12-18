
#ifndef _ULMYUTILS_H_
#define _ULMYUTILS_H_


#ifdef __cplusplus
extern "C" {
#endif

#define UTIL_isHexStr(x) isHex(x)

uint8_t	 bitMaskPos(uint32_t mask); 
uint8_t  isHex(char* str);
uint8_t  UTIL_toDigit(char x);
int32_t  UTIL_num(char* str);
uint32_t UTIL_hexNum(char* str);
uint32_t UTIL_getNum(char* str);

uint32_t UTIL_Str2PortPin(char* str);

#ifdef __cplusplus
}  //extern "C" {
#endif

#include "Bootloader.h"
#include "dev_table.h"
#endif
