/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 3.4
 */

#include <stdio.h>

int gcd(int p, int q);

int main(void) {
    int a, b; /* Inputs */

    scanf("%d\n%d", &a, &b);
    printf("%d\n", gcd(a,b));
    return 0;
}

/*
    gcd() is an iterative version of the recursive euclidian algorithm for finding the GCD.
    gcd() takes two inputs p,q and stores the modulus p%q in the auxiliary variable r.
    Checking for r == 0 as a means to find the common denominator.
    As we are going down from the top posssible value,
    that being the lowest of p and q, the first case for r == 0 will be the GCD.
*/
int gcd(int p, int q) {
    int r;
    if ((r = p % q) == 0) {
        return q;
    }
    else {
        while(r != 0) {
            p = q;
            q = r;
            r = p % q;
        }
        return q;
    }
}