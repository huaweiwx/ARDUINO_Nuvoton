/*
  chips.h
  
  Copyright (c) 2018 huaweiwx@sina.com 2018.11.1

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

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
 #endif

 