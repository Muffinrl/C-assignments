/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 3.4
 */

#include <stdio.h>

int gcd(int p, int q);

int main(void) {
    printf("%d", gcd(15, 6));
    return 0;
}

int gcd(int p, int q) {
    int r = p % q;
    while(r != 0) {
        r = q % r;
    }
    return q;
}