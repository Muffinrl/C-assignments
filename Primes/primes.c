/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 3.3
 */

#include <stdio.h>
#include <math.h>

int isPrime(int a);

int main(void) {
    int lowerBound, upperBound;
    int i;

    printf("Provide a range (lower_bound upper_bound) separated by a space: ");
    scanf("%d%d", &lowerBound, &upperBound);
    printf("Primes in range %d - %d:\n", lowerBound, upperBound);

    /* Minor error check, not really necessary for the purposes of the program, but could possibly prevent a huge loop around. */
    if(lowerBound > upperBound) {
        printf("Please enter the lower bound first!");
        return 0;
    }
    
    /* Loop through within the range, printing if isPrime() returns true. */
    for(i = lowerBound; i <= upperBound; i++) {
        if(isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

/*
    isPrime() takes an input value a of type int.
    it proceeds to go through all its divisors, adding every "succesful" division to the auxiliary variable c.
    c starts at 0, meaning that if a has 2 divisors, c will be 1, because the input value itself isn't counted as a divisor.
    Thus, the output of isPrime() will be c == 1.
    a = 1 will still return true for c == 1, so it is handled seperately.
*/
int isPrime(int a) {
    int c = 0;
    int i;
    for (i = 1; i <= sqrt(a); i++) {
        if (!fmod(a, i))
            c++;
    }
    return c == 1 && a != 1;
}

