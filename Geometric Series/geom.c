/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 1.4
 */

#include <stdio.h>
#include <math.h>

double calculateSum(double a, int n, double r);
double sum;

int main (void) {
    double a, r;
    int n;

    /*printf("Please provide three parameters (a,n,r) separated by a space:\n"); */
    scanf("%lf%d%lf", &a, &n, &r);
    printf("%.2f\n", calculateSum(a,n,r));
    return 0;
}

/* 
    calculateSum() takes 3 inputs a,n,r and calculates the sum of the geometric sequence: a(r^n).
    It does so by storing the intermediate values of the for-loop in the auxiliary variable "sum".
*/
double calculateSum(double a, int n, double r) {
    int i;
    for (i = 0; i <= n; i++){
        sum += a * pow(r, i);
    }
    return sum;
}