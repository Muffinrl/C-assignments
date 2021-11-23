#include <stdio.h>
#include <string.h>


#define MAX_LEN 1025

int countOccurrences(char *str, char *toSearch);

int main(int argc, char const *argv[])
{
    char str[MAX_LEN];
    char toSearch[MAX_LEN];
    int count;
    count = 0;
    
    if (argc != 2) {
        printf("Please specify a program argument.\n");
        return 1;
    }

    while(strcmp(fgets(str, MAX_LEN, stdin), "#EOF\n") != 0) {
        count += countOccurrences(str, toSearch);
    }
    printf("%d", count);
    
    return 0;
}

int countOccurrences(char * str, char * toSearch) {
    int i, j, found, count;
    int stringLen, searchLen;

    count = 0;

    stringLen = strlen(str);      /* length of string */
    searchLen = strlen(toSearch); /* length of word to be searched */

    count = 0;

    for(i=0; i <= stringLen-searchLen; i++) {
         /* Match word with string */
        found = 1;
        for(j=0; j<searchLen; j++) {
            if(str[i + j] != toSearch[j]) {
                found = 0;
                break;
            }
        }

        if(found == 1){
            count++;
        }
    }

    return count;
}