
#include "build_defines.h"


#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef  CUSTOM_STARTUP_C
#  include CUSTOM_SYSTEM_C
#  pragma message "used custom startup file"
#else
#  if defined(UNUSED_CMSIS_STARTUP)&& (UNUSED_CMSIS_STARTUP > 0)  /* has .c or .S file auto select in project or variant path */
#     pragma message "uuused CMSIS startup file"
#  else	

	#if defined(M480)
       /* use startup_m480.S */

	#elif defined(M451Series)
		#include "Device/Nuvoton/M451Series/Source/GCC/startup_M451Series.c"
		
	#elif defined(NUC200Series)
		#include "Device/Nuvoton/NUC200Series/Source/GCC/startup_NUC200Series.c"
	
	#elif defined(NUC131)
		#include "Device/Nuvoton/NUC131/Source/GCC/startup_NUC131.c"
	
	#elif defined(Nano100Series)
		#include "Device/Nuvoton/Nano100Series/Source/GCC/startup_Nano100Series.c"
	
	#elif defined(Nano1X2Series)
		#include "Device/Nuvoton/Nano1X2Series/Source/GCC/startup_Nano1X2Series.c"
		
	#elif defined(M051Series)
		#include "Device/Nuvoton/M051Series/Source/GCC/startup_M051Series.c"

	#elif defined(M058S)
		#include "Device/Nuvoton/M058S/Source/GCC/startup_M058S.c"
	
	#elif defined(Mini58Series)
		#include "Device/Nuvoton/Mini58Series/Source/GCC/startup_Mini58Series.c"
	
	#elif defined(Mini51Series)
		#include "Device/Nuvoton/Mini51Series/Source/GCC/startup_Mini51Series.c"
		
	#else
		#error "! the Series undef  or unsupport !"
	#endif

#  endif
#endif
