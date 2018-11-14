/*
  NUVOTON avr_emulation.cpp
  
  Copyright (c) 2018 huaweiwx@sina.com 2018.9.1

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

#include "Arduino.h"

#if  defined(PA)
DDRemulation	DDRA(PA);
#elif defined(P0)
DDRemulation	DDRA(P0);
#endif
#if  defined(PB)
DDRemulation	DDRB(PB);
#elif defined(P1)
DDRemulation	DDRB(P1);
#endif
#if  defined(PC)
DDRemulation	DDRC(PC);
#elif defined(P2)
DDRemulation	DDRC(P2);
#endif
#if   defined(PD)
DDRemulation	DDRD(PD);
#elif defined(P3)
DDRemulation	DDRD(P3);
#endif
#if   defined(PE)
DDRemulation	DDRE(PE);
#elif defined(P4)
DDRemulation	DDRE(P4);
#endif
#if   defined(PF)
DDRemulation	DDRF(PF);
#elif defined(P5)
DDRemulation	DDRF(P5);
#endif
#if   defined(PG)
DDRemulation	DDRG(PG);
#elif defined(P6)
DDRemulation	DDRG(P6);
#endif
#if   defined(PH)
DDRemulation	DDRH(PH);
#elif defined(P7)
DDRemulation	DDRH(P7);
#endif
#if   defined(PJ)
DDRemulation	DDRJ(PJ);
#endif
#if   defined(PK)
DDRemulation	DDRK(PK);
#endif
