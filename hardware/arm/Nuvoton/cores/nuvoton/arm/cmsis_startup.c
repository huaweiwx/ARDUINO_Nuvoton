
#include "build_defines.h"


#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef  CUSTOM_STARTUP_C
#  include CUSTOM_SYSTEM_C
#  pragma message "used custom startup file"
#else
#  if defined(UNUSED_CMSIS_STARTUP)&& (UNUSED_CMSIS_STARTUP > 0)  /* has .c or .S file auto select in project or variant path */
#     pragma message "uuused CMSIS startup file"
#  else	
	 #include "cmsis_startup.h"		
#  endif
#endif
