/*
    This program corresponds to assignment 2.12: The program is_prime.
*/

#include <stdio.h>
#include <math.h>

int isPrime(int a);

int main(void) {
    // Values for testing, correct output should be: 1 1 0 1 1
    printf("2 is prime: %d\n", isPrime(2));
    printf("3 is prime: %d\n", isPrime(3));
    printf("4 is prime: %d\n", isPrime(4));
    printf("5 is prime: %d\n", isPrime(5));
    printf("13 is prime: %d\n", isPrime(13));
    return 0;
}

/*
    isPrime() takes an input value a of type int.
    it proceeds to go through all its divisors, adding every "succesful" division to the auxiliary variable c.
    c starts at 0, meaning that if a has 2 divisors, c will be 1, because the input value itself isn't counted as a divisor.
    Thus, the output of isPrime() will be c == 1.
*/
int isPrime(int a){
    int c = 0;
    for (int i = 1; i <= sqrt(a); i++) {
        if (!fmod(a, i))
            c++;
    }
    return c == 1;
}
