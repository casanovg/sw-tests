// .............................................
// File: tst-03.h
// .............................................

#ifndef TST_03_H
#define TST_03_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defines
#define USE_BITWISE_MASK true  // This defines the buffer pointers return-to-start method
// If USE_BITWISE_MASK is true, BUFFER_SIZE has to a power of 2 (2, 4, 8, 16, 32, 64, ... )
#define BUFFER_SIZE 16
#define BUFFER_MASK (BUFFER_SIZE - 1)  // This is used only when USE_BITWISE_MASK is true

#define OPERATION_DELAY 250

// Globals
uint8_t buffer[BUFFER_SIZE];
uint8_t buffer_byte_count = 0;  // Bytes received in buffer
uint8_t buffer_head = 0, buffer_tail = 0;

// Prototypes
void InitBuffer(void);
void WriteBuffer(uint8_t data);
uint8_t ReadBuffer(void);
void PrintBuffer(void);
uint8_t RandomByte(uint8_t lower, uint8_t upper);
void Delay(unsigned int milli_seconds);
void ClrScr(void);

#endif  // TST_03_H
