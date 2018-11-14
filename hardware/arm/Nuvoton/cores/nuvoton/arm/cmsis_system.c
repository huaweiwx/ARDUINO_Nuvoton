

#include "build_defines.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef  CUSTOM_SYSTEM_C
#  include CUSTOM_SYSTEM_C
#  pragma message "used custom CMSIS system file"
#else
#  if defined(UNUSED_CMSIS_SYSTEM)&& (UNUSED_CMSIS_SYSTEM > 0)  /* has .c or .S file auto select in project or variant path */
#     pragma message "uuused CMSIS system file"
#  else	
      #include "cmsis_system.h"
#  endif
#endif
