/*
  dtostrf - Emulation for dtostrf function from avr-libc
  Copyright (c) 2013 Arduino.  All rights reserved.
  Written by Cristian Maglie <c.maglie@bug.st>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*
  * arm gcc does not support the %f format in sprintf.
  *	modify for arm arduino by huaweiwx@sina.com 2018.1.10
 */

#include <stdio.h>

/* 
char *dtostrf (double val, signed char width, unsigned char prec, char *sout) {
  char fmt[20];
  sprintf(fmt, "%%%d.%df", width, prec); 
  sprintf(sout, fmt, val);
  return sout;
}
*/

#pragma GCC diagnostic ignored "-Wunused-value"

char *dtostrf (double val, signed char width, unsigned char prec, char *sout) {
  if ( sout == NULL )
  {
    return 0;
  }
  
  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  
  uint8_t valn=0;
  char buf[20];
  char *tp = buf;
  char *sp = sout;
  long long i;
  uint8_t cnt = 0;
  
  if(val < 0.0){
     val = -val; 
	 valn=1;
  }
  
  unsigned long long v = val;
  while (v)
  {
    v = v / 10;
	cnt++;
  }
  
  if (cnt >= width) prec = 1;
  else if((prec+cnt)>16) prec = 16-cnt;

  for (uint8_t i=0; i<prec; ++i) rounding /= 10.0;
  
  val += rounding;
  v = val;  
  while (v)
  {
    i = v % 10;
    v = v / 10;
    *tp++ = i+'0';
  }
  
  while(width-- >(cnt + prec +valn + 2)) *sp++ = ' ';
  
  if(valn) *sp++ = '-';

  if (cnt){
    *tp--;
    while(tp >= buf) *sp++ = *tp--;
  }else{
   *sp++ = '0';	  
  }
  *sp++ = '.';
  
  for(uint8_t j=0;j<prec; j++)
  {
   val =(val -(long long)val)*10.0;
   *sp++ = (uint8_t)val + '0';
  } 
  
  *sp =0;  
  return sout;
}
