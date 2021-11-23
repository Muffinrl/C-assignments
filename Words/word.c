/*
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 4.8
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1025

int main (int argc, char *argv[]) {
	int i, l, count;
	char c;
	char *arg;
	char *buf;

    /* Checking for program argument */
	if (argc != 2) {
		printf("Please specify a program argument.\n");
		return 1;
	}

	l = strlen(argv[1]);
	arg = calloc(l, sizeof(char));
	buf = calloc(l, sizeof(char));
	memcpy(arg, argv[1], l * sizeof(char));

	i = 0;
	count = 0;

    /* Manually compare strings 
     * Loops through indices of buf[] and arg[] and compares them.     
     */
	while((c = getchar()) != EOF) {
		if (c == arg[i]) {
			buf[i] = c;
			++i;
			if (i == l) {
				++count;
				for (i = 1; i < l - 1; ++i) {
					if (buf[i] == arg[i-1]) {
						buf[i-1] = buf[i];
					}	
					else {
						break;
					}
				}
			}
		} else {
			i = 0;
		}
	}

	if (strcmp("EOF", argv[1]) == 0) count--;

	free(arg);
	free(buf);

	printf("%i\n", count);


    return 0;
}