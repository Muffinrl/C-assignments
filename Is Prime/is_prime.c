/*
    This program corresponds to assignment 2.12: The program is_prime.
*/

#include <stdio.h>
#include <math.h>

int isPrime(int a);

int main(void) {
    int input;

    printf("Enter a natural number: ");
    scanf("%d", &input);

    if(isPrime(input)) {
        printf("%d is prime!", input);
    }
    else {
        printf("%d is not prime!", input);
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
    for (int i = 1; i <= sqrt(a); i++) {
        if (!fmod(a, i))
            c++;
    }
    return c == 1 && a != 1;
}
