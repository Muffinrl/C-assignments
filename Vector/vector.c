/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 4.6
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getMagnitude(double* v);
void swap(double **a, double **b), sortVectorsByMagnitude(double** w);

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

	/* FIXME
	 * Sort the vectors and print them.
	 */
	sortVectorsByMagnitude(w);
	for (i = 0; i < num; i++) {
		for (j = 0; j < dim; j++) {
			printf("%e ", w[i][j]);
		}
		printf("\n");
	}

	return 0;
}

double getMagnitude(double *v) {
	double sum;
	int i;
	int length = sizeof(v) / sizeof(v[0]); /* Determine the length of v */

	for(i = 0; i < length; i++) {
		sum += v[i];
	}
	printf("%.2f", sum);
	return sqrt(sum);
}

void sortVectorsByMagnitude(double** w) {
	int i, j, length = sizeof(w) / sizeof(w[0]);
	for (i = 0; i < length - 1; i++) {
		for (j = length - 1; j > i; j--) {
			if (getMagnitude(&*w[j-1]) > getMagnitude(&*w[j]))
				swap(&w[j-1], &w[j]);
		}
	}
}

void swap (double **a, double **b) {
	double *tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
