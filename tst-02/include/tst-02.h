// .............................................
// File: tst-02.h
// .............................................

#ifndef TST_02_H
#define TST_02_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

// ADC value range
#define ADC_MAX 1023
#define ADC_MIN 0

// ADC Buffer lenght
#define BUFF_LEN 34

// DHW setting steps
#define DHW_SETTING_STEPS 12

// Number of NTC ADC values used for calculating temperature
#define NTC_VALUES 12
#define PuntosTabla (12)

// NTC ADC temperature values
const uint16_t ntc_adc_table[NTC_VALUES] = {
    929, 869, 787, 685, 573, 461, 359, 274, 206, 154, 116, 87};

const unsigned int TablaADC[PuntosTabla] = {
    939, 892, 828, 749, 657, 560, 464, 377, 300, 237, 186, 55};
//-30,-20, -10,  0,   10,  20,  30,  40,  50,  60,  70 ºC
//  0   1    2   3     4    5    6    7    8    9   10  i

// Prototypes
int main(void);
void Delay(unsigned int milli_seconds);
int GetNtcTempTenths(uint16_t, int, int);
float GetNtcTempDegrees(uint16_t, int, int);
int TempNTC(unsigned int, int, int);
uint8_t GetHeatLevel(int16_t, uint8_t);
int DivRound(const int numerator, const int denominator);

// Temperature calculation settings
#define TO_CELSIUS (-200)     // Celsius offset value
#define DT_CELSIUS (100)      // Celsius delta T (difference between two consecutive table entries)
#define TO_KELVIN (2430)      // Kelvin offset value
#define DT_KELVIN (100)       // Kelvin delta T (difference between two consecutive table entries)
#define TO_FAHRENHEIT (-220)  // Fahrenheit offset value
#define DT_FAHRENHEIT (180)   // Fahrenheit delta T (difference between two consecutive table entries)

// Parámetros para conversión en ºCelsius
#define ToCels (-300)
#define dTCels (100)
// Parámetros para conversión en Kelvins
#define ToKelv (2430)
#define dTKelv (100)
// Parámetros para conversión en ºFahrenheit
#define ToFahr (-220)
#define dTFahr (180)

#endif  // TST_02_H