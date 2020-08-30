// file: library.h

#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <stdio.h>

#define FUNCTION_1 true
#define FUNCTION_2 false

class Class {
   public:
    Class();
    ~Class();
#if FUNCTION_1
    void Function_1(void);
#endif  // FUNCTION_1
#if FUNCTION_2
    void Function_2(void);
#endif  // FUNCTION_2
};

#endif  // _LIBRARY_H_
