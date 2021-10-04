/*
    This program corresponds to assignment 1.4: Geometric series.
*/

#include <stdio.h>
#include <math.h>

double calculateSum(double a, int n, double r);

int main (void) {
    double a;
    double r;
    int n;

    printf("Please provide three parameters (a,n,r) separated by a space:\n");
    scanf("%lf%d%lf", &a, &n, &r);
    printf("The geometric sum:\n%.2f", calculateSum(a,n,r));
    return 0;
}

double calculateSum(double a, int n, double r) {
    double sum;
    for (int i = 0; i <= n; i++){
        sum += a * pow(r, i);
    }
    return sum;
}