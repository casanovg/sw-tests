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

    // Force some writing / reads to move the tail pointer ahead, this
    // is to test that the buffer full detection works even when this
    // pointer is not at start
    // const uint8_t count = 7;
    // for (uint8_t i = 0; i < count; i++) {
    //     printf(" < FORCING TAIL > ");
    //     if (i < (count - 2)) {
    //         ReadBuffer();
    //     }
    //     WriteBuffer(70 + i);
    //     Delay(OPERATION_DELAY);
    //     ClrScr();
    //     PrintBuffer();
    // }
    // Delay(OPERATION_DELAY * 8);

    // Preload the buffer to test for buffer full condition detection
    // before starting the alternating read / write cycle
    // const uint8_t preload_max = 30;
    // for (uint8_t i = 0; i < preload_max; i++) {
    //     printf(" = PRELOADING = ");
    //     if (buffer_byte_count < BUFFER_SIZE) {
    //         uint8_t character = RandomByte(65, 122);
    //         // WriteBuffer(RandomByte(1, 255));
    //         printf(">>> %c\n\r", character);
    //         WriteBuffer(character);
    //     } else {
    //         printf("*** FULL ***\n\r");
    //     }
    //     Delay(OPERATION_DELAY);
    //     ClrScr();
    //     PrintBuffer();
    // }
    // Delay(OPERATION_DELAY * 8);

    // Main random write / read loop
    for (;;) {
        uint8_t character = '\0';
        if (RandomByte(0, 1)) {
            // On true, write buffer
            printf(" * WRITING * ");
            if (buffer_byte_count < BUFFER_SIZE) {
                character = RandomByte(65, 122);
                // WriteBuffer(RandomByte(1, 255));
                printf(">>> %c\n\r", character);
                WriteBuffer(character);
            } else {
                printf("*** FULL ***\n\r");
            }
        } else {
            // On false, read buffer
            printf(" _ READING _ ");
            if (buffer_byte_count > 0) {
                character = ReadBuffer();
                printf("<<< %c\n\r", character);
            } else {
                printf("___ EMPTY ___\n\r");
            }
        }
        Delay(OPERATION_DELAY);
        ClrScr();
        PrintBuffer();
    }
}

// Function BufferInit
void InitBuffer(void) {
    buffer_tail = 0;
    buffer_head = 0;
    buffer_byte_count = 0;
    // Fill the buffer with spaces
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 32;
    }
}

// Function WriteBuffer
void WriteBuffer(uint8_t data) {
    buffer_head = ((buffer_head + 1) & BUFFER_MASK);
    buffer[buffer_head] = data;
    buffer_byte_count++;
}

// Function ReadBuffer
uint8_t ReadBuffer(void) {
    //while (!rx_byte_count) {};                     // Wait until the buffer has data
    buffer_tail = ((buffer_tail + 1) & BUFFER_MASK);  // Update the buffer index
    uint8_t data = buffer[buffer_tail];
    buffer[buffer_tail] = 32;  //After reading replace read with an space (optional, for testing only)
    buffer_byte_count--;
    return data;  // Return tail pointer position buffer content
}

// void PrintBuffer
void PrintBuffer(void) {
    printf("Circular buffer test\n\r");
    printf("====================\n\r");
    printf("\n\r");
    // Print buffer positions
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        printf("| B%02d ", i);
    }
    printf("|\n\r-");
    // Print separator line
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        printf("------");
    }
    printf("\n\r");
    // Print buffer contents
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        printf("|  %c  ", buffer[i]);
    }
    printf("|\n\n\r");
    // Print "head" pointer position
    for (int i = 0; i < buffer_head; i++) {
        printf("      ");
    }
    printf(" head \n\r");
    // Print "tail" pointer position
    for (int i = 0; i < buffer_tail; i++) {
        printf("      ");
    }
    printf(" tail \n\n\r");
    // Print buffer byte count
    printf("Buffer count: %d", buffer_byte_count);
}

// Function RandomByte
uint8_t RandomByte(uint8_t lower, uint8_t upper) {
    uint8_t random_byte = (rand() % (upper - lower + 1)) + lower;
    return random_byte;
}

// Function Delay
void Delay(unsigned int milli_seconds) {
    clock_t goal = milli_seconds + clock();
    while (goal > clock()) {
    };
}

// Function ClrScr
void ClrScr(void) {
    //printf("\e[1;1H\e[2J"); // On serial terminal
    system("clear");  // On PlatformIO terminal
}
