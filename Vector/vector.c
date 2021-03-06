/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 4.6
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getMagnitude(double* v, int dim);
void swap(double **a, double **b), sortVectorsByMagnitude(double** w, int dim, int num);

int main (void)
{
	int dim, num;
	int i, j;
	double **w;

	scanf ("%d %d", &dim, &num);          /* read N and M */
	w = calloc (num, sizeof (double *));  /* allocate array of M pointers */
	for (i = 0; i < num; i++) {           
		/* allocate space for N dimensional vector */
		w[i] = calloc (dim, sizeof (double));
		/* read the vector */
		for (j = 0; j < dim; j++) {
			scanf ("%le", &w[i][j]);
		}
	} 

	/*
	 * Sort the vectors and print them.
	 */
	sortVectorsByMagnitude(w, dim, num);
	for (i = 0; i < num; i++) {
		for (j = 0; j < dim; j++) {
			printf("%e ", w[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/*
	getMagnitude() takes a single vector *v and it's dimension dim.
	getMagnitude() calculates the magnitude of vector *v:
	magnitude is the sum of the squares of the elements: sum(v[i]^2).
*/

double getMagnitude(double *v, int dim) {
	double sum = 0;
	int i;

	for(i = 0; i < dim; i++) {
		sum += v[i]*v[i];
	}

	return sqrt(sum);
}

/* 
	sortVectorsByMagnitude() takes the vectors **w and array paramaters dim, num 
	and executes a bubble-sort algorithm. 
*/
void sortVectorsByMagnitude(double** w, int dim, int num) {
	int i, j;
	for (i = 0; i < num; i++) {
		for (j = num - 1; j > i; j--) {
			if (getMagnitude(w[j-1], dim) > getMagnitude(w[j], dim))
				swap(&w[j-1], &w[j]);
		}
	}
}

/*
	swap() takes two arguments: **a, **b.
	swap() assigns the initial value of **a to **b and the inital value of **b to **a.
*/

void swap (double **a, double **b) {
	double *tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
