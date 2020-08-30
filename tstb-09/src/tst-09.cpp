// ---------------------------------------------
// Test 09 - 2020-06-23 - Gustavo Casanova
// .............................................
// Override library #define values
// ---------------------------------------------

#include "tst-09.h"

int main(void) {
    Class object;
#if FUNCTION_1
    object.Function_1();
#endif  // FUNCTION_1
#if FUNCTION_2
    object.Function_2();
#endif  // FUNCTION_2
}