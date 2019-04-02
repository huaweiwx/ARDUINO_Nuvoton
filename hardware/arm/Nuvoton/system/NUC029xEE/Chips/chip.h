
 #if defined(CHIP128P)
  #include "list128.h"
 #elif defined(CHIP100P)
  #include "list100.h"
 #elif defined(CHIP64P)
  #include "list64.h"
 #elif defined(CHIP48P)
  #include "list48.h"
 #elif defined(CHIP33P)
  #include "list33.h"
 #elif defined(CHIP28P)
  #include "list28.h"
 #elif defined(CHIP20P)
  #include "list20.h"
 #else
  #error "!!undef chip!!" 	 
 #endif

 