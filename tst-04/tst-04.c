/*
 * tst-o4.c
 * Endianness tests
 *
 * Created: 15/06/2021
 * Author : prandeamus
 *
 */ 

#include <stdint.h>

void PokeMSBFirst(uint8_t *command, uint8_t val) {
    uint16_t addr = (command[1] << 8) | (command[2]);
    *((uint8_t*)addr) = val;
}

void PokeLSBFirst(uint8_t *command, uint8_t val) {
    uint16_t addr = (command[2] << 8) | (command[1]);
    *((uint8_t*)addr) = val;
}

void PokeNative(uint8_t *command, uint8_t val) {
    uint16_t addr = *(uint16_t*)&command[1];
    *((uint8_t*)addr) = val;
}
