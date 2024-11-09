// allocin:  allocate space for input.
//           read standard input into memory with a pointer to each line.
//           line pointers are stored in array so lines can be access
//           with a simple array index.
//
// $ gcc -g -Wall -Wextra -Wpedantic -DALLOCIN_MAIN -o allocin allocin.c
// $ cat allocin_test.txt | ./allocin
// -or-
// $ gcc -o app app.c allocin.c
//
// TODO:
// Make number of lines 0 if there is no input and no memory error.
// Optionally list files to read in on the command line.
// 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allocin.h"


char **ghap_ln;                     // both modified by allocin()
char buf[BUFSIZ]; 
char *progname;                     // program name for error messages

#ifdef ALLOCIN_MAIN
int main(int argc, char *argv[]) {

    int lines = 0;

    progname = argv[0];
    (void)argc;

    // read input, allocate heap space
    lines = allocin(&ghap_ln);

    // print out the standard input line-wise, in order
    for (int i = 0; i < lines; i++)
        printf("%s", ghap_ln[i]);
    // then print in reverse
    for (int i = lines-1; i >= 0; i--)
        printf("%s", ghap_ln[i]);

    // allocated heap data no longer neaded
    free(ghap_ln);
    return 0;
}
#endif  // ALLOCIN_MAIN


/* allocin: read standard input lines into dynamically allocated arrays 
 *
 *     buf: global buffer for temporary line storage while data is being read
 *       p: pointer to start of arrays
 * returns: number of lines read in or, -1 for no lines or memory error
 *
 */
int allocin(char ***p) {

    char **hap_ln;              // array of pointers
                                // that point to each line read in
    int lines = 0;

    hap_ln = (char **)malloc(sizeof(int *));

    // read input lines into dynamically allocated arrays
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        char **hap_new = (char **)realloc(hap_ln, 
                                          (lines+1)*sizeof(char **));
        if (hap_new == NULL) {
            fprintf(stderr, "%s: %s: memory error\n", progname, __func__);
            return -1;
        }
        hap_ln = hap_new;
        hap_ln[lines] = (char *)malloc(sizeof(buf)+1);
        memcpy(hap_ln[lines], buf, sizeof(buf));
        lines++;
	}

    // set the pointer function argument to the allocated heap data
    *p = hap_ln;
    return lines;
}
