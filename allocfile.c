// allocfile:   allocate space for file.
//              file name specified on command line
//              read file into memory with a pointer to each line.
//              line pointers are stored in array so lines can be access
//              with a simple array index.
//
// $ gcc -g -Wall -Wextra -Wpedantic -o allocfile allocfile.c
// $ ./allocfile allocin_test.txt
//
// TODO:
// Make number of lines 0 if there is no input and no memory error.
// Optionally list files to read in on the command line.
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int allocin(char ***p, FILE *fp);
FILE *efopen(char *file, const char *mode);

char **ghap_ln;                     // both modified by allocin()
char buf[BUFSIZ]; 

char *progname;
char *filename;

int main(int argc, char *argv[]) {

    int lines = 0;
    FILE *fp = NULL;

    if (argc != 2) {
        fprintf(stderr, "%s: error: no file given\n", argv[0]);
        exit(1);    
    }

    progname = argv[0]; 
    filename = argv[1];

    fp = efopen(argv[1], "r");

    // read input, allocate heap space
    lines = allocin(&ghap_ln, fp);

    // print out the standard input line-wise, in order
    for (int i = 0; i < lines; i++)
        printf("%s", ghap_ln[i]);
    // then print in reverse
    for (int i = lines-1; i >= 0; i--)
        printf("%s", ghap_ln[i]);

    free(ghap_ln);
    return 0;
}


/* allocin: read standard input lines into dynamically allocated arrays 
 *
 *     buf: global buffer for temporary line storage while data is being read
 *       p:  pointer to start of arrays
 * returns: number of lines read in or, -1 for no lines or memory error
 *
 */
int allocin(char ***p, FILE *fp) {

    char **hap_ln;              // array of pointers
                                // that point to each line read in
    int lines = 0;

    hap_ln = (char **)malloc(sizeof(int *));

    // read input lines into dynamically allocated arrays
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        char **hap_new = (char **)realloc(hap_ln, 
                                          (lines+1)*sizeof(char **));
        if (hap_new == NULL) {
            fprintf(stderr, "%s: memory error\n", __func__);
            return -1;
        }
        
        hap_ln = hap_new;
        hap_ln[lines] = (char *)malloc(sizeof(buf)+1);
        memcpy(hap_ln[lines], buf, sizeof(buf));
        lines++;
	}

    *p = hap_ln;
    return lines;
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

