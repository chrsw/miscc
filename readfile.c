// readfile:    read a file into memory using falloc()
//
// $ gcc -Wall -o readfile allocin.c readfile.c
//
//


#include <stdio.h>
#include <stdlib.h>
#include "falloc.h"

FILE *efopen(char *file, const char *mode);

char buf[BUFSIZ];
char *progname;
char *filename;
extern char **fal_gp;

int main(int argc, char *argv[]) {

    int lines = 0;
    FILE *fp = NULL;

    if (argc != 2) {
        fprintf(stderr, "%s: error: no file given\n", argv[0]);
        exit(1);    
    }

    progname = argv[0];
    filename = argv[1];

    fp = efopen(filename, "r");

    // read input, allocate heap space
    lines = falloc(fp);

    // print out the standard input line-wise, in order
    for (int i = 0; i < lines; i++)
        printf("%s", fal_gp[i]);
    // then print in reverse
    for (int i = lines-1; i >= 0; i--)
        printf("%s", fal_gp[i]);

    free(fal_gp);
    return 0;

    
    return 0;
}


/* efopen:  fopen file, die if can't */
FILE *efopen(char *file, const char *mode)
{
    FILE *fp;
    if ((fp = fopen(file, mode)) != NULL)
        return fp;
    fprintf(stderr, "%s: can't open file %s mode %s\n",
            progname, file, mode);
    exit(1);
}

