// ---------------------------------------------
// Test 03 - 2020-08-01 - Gustavo Casanova
// .............................................
// Circular buffer test
// ---------------------------------------------

#include "tst-03.h"

// Main function
int main(void) {

    InitBuffer();

    ClrScr();
    printf("Circular buffer test\n\r");
    printf("====================\n\n\r");

    Delay(1000);
    ClrScr();

    PrintBuffer();
    Delay(2000);

    for (uint8_t i = 1; i < MAX_COUNT + 1; i++) {
        ClrScr();
        WriteBuffer(i);
        PrintBuffer();
        Delay(250);
    };
}

// Function BufferInit
void InitBuffer(void) {
    buffer_tail = 0;
    buffer_head = 0;
    buffer_byte_count = 0;
}

// Function WriteBuffer
void WriteBuffer(uint8_t data) {
    buffer_byte_count++;
    buffer_head = ((buffer_head + 1) & BUFFER_MASK);
    buffer[buffer_head] = data;
}

// Function ReadBuffer
uint8_t ReadBuffer(void) {
    //while (!rx_byte_count) {};                     // Wait until the buffer has data
    buffer_tail = ((buffer_tail + 1) & BUFFER_MASK); // Update the buffer index
    return buffer[buffer_tail];                      // Return data from the buffer
}

// void PrintBuffer
void PrintBuffer(void) {
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        printf("| B%02d ", i);
    }
    printf("|\n\r-");
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        printf("------");
    }
    printf("\n\r");
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        if (buffer[i] < 10) {
            printf("|   %d ", buffer[i]);
        } else {
            if (buffer[i] < 100) {
                printf("|  %d ", buffer[i]);
            } else {
                printf("| %d ", buffer[i]);
            }

        }
    }
    printf("|\n\n\r");
    for (int i = 0; i < buffer_head; i++) {
        printf("      ");
    }
    printf(" head \n\r");
    for (int i = 0; i < buffer_tail; i++) {
        printf("      ");
    }
    printf(" tail \n\n\r");
    // printf("Buffer head: %d\n\r", buffer_head);
    // printf("Buffer tail: %d\n\r", buffer_tail);
    printf("Buffer count: %d\n\r", buffer_byte_count);
}

// Function Delay
void Delay(unsigned int milli_seconds) {
    clock_t goal = milli_seconds + clock();
    while (goal > clock())
        ;
}

// Function ClrScr
void ClrScr(void) {
    //printf("\e[1;1H\e[2J");
    system("clear");
}
