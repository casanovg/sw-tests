// file: library.cpp

#include "library.h"

Class::Class() { /* Constructor */ };
Class::~Class() { /* Destructor */ };

#if FUNCTION_1
void Class::Function_1(void) {
    printf("\n\rHi, this is %s running ...\n\r", __func__);
}
#endif  // FUNCTION_1

#if FUNCTION_2
void Class::Function_2(void) {
    printf("\n\rHi, this is %s running ...\n\r", __func__);
}
#endif  // FUNCTION_2
