/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 1.3
 */

#include <stdio.h>

/* 
    Defining constant values for conversion:
    DIFF (difference) means the value is added to the input to convert the temperature.
    FACTOR means the input is multiplied by the value to convert the temperature.
*/
#define TEMP_DIFF_KELVIN 273.15
#define TEMP_FACTOR_FAHRENHEIT 1.8
#define TEMP_DIFF_FAHRENHEIT 32

double convertTempK(double temp);
double convertTempF(double temp);

int main(void) {
    double in_temp; /* "Input Temperature" */

    printf("Please provide a temperature to be converted in Celsius:\n");
    scanf("%lf", &in_temp);
    printf("%s\t%s\t%s\n%.2f\t%.2f\t%.2f\n", "C", "K", "F", in_temp, convertTempK(in_temp), convertTempF(in_temp)); // Formatting breaks with anything input > 9999. But the assignment specifies tabs.
    return 0;
}

/* convertTempK() converts a given temperature in Celsius to Kelvin. */
double convertTempK (double temp) {
    return temp + TEMP_DIFF_KELVIN;
}

/* convertTempF() converts a given temperature in Celsius to Fahrenheit. */
double convertTempF (double temp) {
    return TEMP_FACTOR_FAHRENHEIT * temp + TEMP_DIFF_FAHRENHEIT;
}