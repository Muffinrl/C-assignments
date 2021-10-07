/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 3.6
 */

#include <stdio.h>
#include <math.h>

extern int a, b, c;

double x1real, x2real, ximag;

static int discriminant(void) {
    return (b * b) - (4 * a * c); 
}

void abc (void) {
    int D = discriminant();

    if(D >= 0) {
        x1real = (-b + sqrt(D)) / (2.0 * a);
        x2real = (-b - sqrt(D)) / (2.0 * a);
        ximag = 0;
    }
    else {
        x1real = -b / (2.0 * a);
        x2real = x1real;
        ximag = (sqrt(-D) / (2.0 * a));
    }
}