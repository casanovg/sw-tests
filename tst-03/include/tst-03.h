// .............................................
// File: tst-03.h
// .............................................

#ifndef TST_03_H
#define TST_03_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

// defines
#define BUFFER_SIZE 8
#define BUFFER_MASK (BUFFER_SIZE - 1)

#define MAX_COUNT 255

// Globals
uint8_t buffer[BUFFER_SIZE];
uint8_t buffer_byte_count = 0; /* Bytes received in buffer */
uint8_t buffer_head = 0, buffer_tail = 0;

// Prototypes
void InitBuffer(void);
void WriteBuffer(uint8_t data);
uint8_t ReadBuffer(void);
void PrintBuffer(void);
void Delay(unsigned int milli_seconds);
void ClrScr(void);

#endif  // TST_03_H