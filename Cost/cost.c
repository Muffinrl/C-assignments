/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 4.3
*/

#include <stdio.h>

#define MAX_ARR 100

/* n: amount of product-prices, m: amount of customers. */
int n, m; 

/*
    Initialisation for arrays: prices[price], totals[total].
    prices[] is to contain all the possible prices as inputted by the user.
    totals[] is to contain all the totaled amounts spent per customer.
*/
double prices[MAX_ARR], totals[MAX_ARR];

int main (void) {
    int i,j;


    scanf("%d", &n);
    
    /* Iterate over every product and store the price in prices[]. */
    for(i = 0; i < n; i++) {
        scanf("%lf", &prices[i]);
    }

    scanf("%d", &m);

    /* 
        Outer for-loop iterates over every customer i, 
        inner for-loop iterates over every purchase j and adds the total price (price[j] * a) to totals[i].
        Here, `int a` is the amount corresponding the product purchased.
    */
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            totals[i] += a * prices[j];
        }
    }

    /* 
        Finally, print the total spent by customer i for all m customers. 
    */
    for(i = 0; i < m; i++) {
        printf("%.2f\n", totals[i]);
    }

    return 0;
}