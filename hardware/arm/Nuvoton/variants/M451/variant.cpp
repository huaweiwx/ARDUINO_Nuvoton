/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include "Arduino.h"

#if defined(CHIP100P)
  #if defined(M453VG)||defined(M453VE)
    #include "Chips/variant100_3.h"
  #else
    #include "Chips/variant100_1.h"
  #endif
#elif defined(CHIP64P)
  #if   defined(M453RG)||defined(M453RE)
    #include "Chips/variant64_3.h"
  #elif defined(M452RG)||defined(M452RE)
    #include "list64_2.h"
  #else
    #include "Chips/variant64_1.h"
  #endif
#elif defined(CHIP48P)
  #if   defined(M453LG)||defined(M453LE)
    #include "Chips/variant48_3.h"
  #elif defined(M452LG)||defined(M452LE)
    #include "list48_2.h"
  #else
    #include "Chips/variant48_1.h"
  #endif
#endif
