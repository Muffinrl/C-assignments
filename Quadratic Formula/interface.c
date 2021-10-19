#include <stdio.h>

void abc (void);

int a, b, c;

extern double x1real, x2real, ximag;

static void get_parameters (void)
{
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
}

void print_solution (void)
{
	printf ("The roots of %dx^2 + %dx + %d are:\n", a, b, c);
        if (ximag < 1e-99) {
		if (x1real == x2real) {
			printf ("x = %.4f\n", x1real);
		}
		else {
			printf ("x1 = %.4f, x2 = %.4f\n", x1real, x2real);
		}
	}
	else 
	{
		printf ("x1 = %.4f+%.4fi, x2 = %.4f-%.4fi\n", x1real, ximag, x2real, ximag);
	}
}

int main (void)
{
	int runs, run;

	scanf ("%d", &runs);

	for (run = 0; run < runs; run++)
	{
		get_parameters ();
		abc ();
		print_solution ();
	}

	return 0;
}
