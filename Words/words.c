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
    int i, j, count;
    char *target, *arg;
    char buf[MAX_LEN];

    count = 0;

    if(argc != 2) {
        printf("Please specify a program argument.");
        return 1;
    }
    
    
    target = calloc(strlen(argv[1]) + 1, sizeof(char));

    fgets(buf, MAX_LEN, stdin);

    /* While loop which terminates when buf = "#EOF" */
    while(strcmp(buf, "#EOF\n") != 0) {
        for (i = 0; i < MAX_LEN - strlen(arg); i++) {
            
            for(j = 0; j < strlen(arg); j++) {
                target[j] = buf[i + j];
            }
            if(strncmp(target, argv[1], strlen(arg)) == 0){
                count++;
            }
        }

        fgets(buf, MAX_LEN, stdin); /* Re-assign buf */
    }

    printf("%d\n", count);

    free(target);

    return 0;
}