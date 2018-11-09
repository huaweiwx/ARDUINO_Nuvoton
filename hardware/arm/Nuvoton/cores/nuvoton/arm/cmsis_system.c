

#include "build_defines.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef  CUSTOM_SYSTEM_C
#  include CUSTOM_SYSTEM_C
#  pragma message "used custom CMSIS system file"
#else
#  if defined(UNUSED_CMSIS_SYSTEM)&& (UNUSED_CMSIS_SYSTEM > 0)  /* has .c or .S file auto select in project or variant path */
#     pragma message "uuused CMSIS system file"
#  else	
	#if defined(M480)
		#include "Device/Nuvoton/M480/Source/system_M480.c"

	#elif defined(M451Series)
		#include "Device/Nuvoton/M451Series/Source/system_M451Series.c"
		
	#elif defined(NUC200Series)
		#include "Device/Nuvoton/NUC200Series/Source/system_NUC200Series.c"
	
	#elif defined(NUC131)
		#include "Device/Nuvoton/NUC131/Source/system_NUC131.c"
	
	#elif defined(Nano100Series)
		#include "Device/Nuvoton/Nano100Series/Source/system_Nano100Series.c"
	
	#elif defined(Nano1X2Series)
		#include "Device/Nuvoton/Nano1X2Series/Source/system_Nano1X2Series.c"
		
	#elif defined(M051Series)
		#include "Device/Nuvoton/M051Series/Source/system_M051Series.c"

	#elif defined(M058S)
		#include "Device/Nuvoton/M058S/Source/system_M058S.c"

	#elif defined(Mini51Series)
		#include "Device/Nuvoton/Mini51Series/Source/system_Mini51Series.c"
		
	#elif defined(Mini58Series)
		#include "Device/Nuvoton/Mini58Series/Source/system_Mini58Series.c"
		
	#else
		#error "! the Series undef  or unsupport !"
	#endif

#  endif
#endif
