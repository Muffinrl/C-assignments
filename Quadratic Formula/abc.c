#include <stdio.h>
#include <math.h>

double x1real, x2real, ximag;

extern int a, b, c;

int discriminant(void) {
    return ((pow(b,2)) - (4 * a * c)); /* unnecessary parentheses B) */
}

void abc (void) {
    if(discriminant() >= 0) {
        x1real = (-b + sqrt(discriminant()))/(2 * a);
        x2real = (-b - sqrt(discriminant()))/(2 * a);
        ximag = 0;
    }
    else {
        x1real = -b/(2*a);
        x2real = x1real;
        ximag = (sqrt(-1 * discriminant()));
    }
}

