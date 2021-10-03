/* 
    This program corresponds to assignment 1.3: Temperature scales.
    "temp" is assumed to be a shortened version of "temperature". Not to be confused with "tmp" and "temporary".
*/

#include <stdio.h>

/* 
    Defining constant values for conversion:
    DIFF means the value is added to the input to convert the temperature.
    FACTOR means the input is multiplied by the value to convert the temperature.
*/
#define TEMP_DIFF_KELVIN 273.15
#define TEMP_FACTOR_FAHRENHEIT 1.8
#define TEMP_DIFF_FAHRENHEIT 32

double convertTempK(double temp);
double convertTempF(double temp);

int main(void) {
    double in_temp; // "Input Temperature"

    printf("Please provide a temperature to be converted in Celsius:\n");
    scanf("%lf", &in_temp);
    printf("%s%12s%12s\n%.2f%12.2f%12.2f\n", "C", "K", "F", in_temp, convertTempK(in_temp), convertTempF(in_temp)); // No idea how to format this neatly. In its current state it looks most neat when the input is between 3 and 8 digits.
    return 0;
}

// convertTempK() converts a given temperature in Celsius to Kelvin.
double convertTempK (double temp) {
    return temp + TEMP_DIFF_KELVIN;
}

// convertTempF() converts a given temperature in Celsius to Fahrenheit.
double convertTempF (double temp) {
    return TEMP_FACTOR_FAHRENHEIT * temp + TEMP_DIFF_FAHRENHEIT;
}