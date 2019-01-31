
#if defined(CHIP100P)
  #if defined(M453VG)||defined(M453VE)
    #include "list100_3.h"
  #else
    #include "list100_1.h"
  #endif
#elif defined(CHIP64P)
  #if  defined(M453RG)||defined(M453RE)
    #include "list64_3.h"
  #elif defined(M452RG)||defined(M452RE)
    #include "list64_2.h"
  #else
    #include "list64_1.h"
  #endif
#elif defined(CHIP48P)
  #if defined(M453LG)||defined(M453LE)
    #include "list48_3.h"
  #elif defined(M452LG)||defined(M452LE)
    #include "list48_2.h"
  #else
    #include "list48_1.h"
  #endif	  
#else
  #error "! undefined ! "
#endif

 