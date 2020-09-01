// ---------------------------------------------
// Test 02 - 2020-08-01 - Gustavo Casanova
// .............................................
// Circular buffer test
// ---------------------------------------------

#include "tst-03.h"

// Main function
int main(void) {

    printf("\r\nCircular buffer test\n\r");
    printf("====================\n\n\r");

    // printf("\n\rADC B: %d, Temperature calculation = %d\n\n\r", adc_temp, TempNTC(adc_temp, TO_CELSIUS, DT_CELSIUS));
    for (;;) {};

}

// Function Delay
void Delay(unsigned int milli_seconds) {
    clock_t goal = milli_seconds + clock();
    while (goal > clock())
        ;
}
