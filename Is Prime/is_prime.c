/*
    This program corresponds to assignment 2.12: The program is_prime.
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    return 0;
}

/*
    isPrime() takes an input value a of type int.
    it proceeds to go through all its divisors, adding every "succesful" division to the auxiliary variable c.
    c starts at 0, meaning that if a has 2 divisors, c will be 2.
    Thus, the output of isPrime() will be c == 2.
*/
int isPrime(int a){
    int c = 0;
    for (int i = 0; i < sqrt(a); i++) {
        if (!fmod(a, i))
            c++;
    }
    return c == 2;
}
