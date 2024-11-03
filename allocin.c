// allocin:  allocate space for input.
//           read file into memory with a pointer to each line.
//
// $ gcc -g -Wall -Wextra -Wpedantic -DMAIN -o allocin allocin.c
// $ cat allocin_test.txt | ./allocin
// -or-
// $ gcc -o app app.c allocin.c
//
// TODO: make number of lines 0 if there is no input and no memory error
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int allocin(char ***p);

char **ghap_ln;
char buf[BUFSIZ];

#ifdef MAIN
int main(int argc, char *argv[]) {

    int lines = 0;

    (void)argc;
    (void)argv;

    // read input
    lines = allocin(&ghap_ln);

    // print out the input
    for (int i = 0; i < lines; i++)
        printf("%s", ghap_ln[i]);

    free(ghap_ln);
    return 0;
}
#endif  // MAIN


/* allocin: read standard input lines into dynamically allocated arrays 
 *
 *     buf: global buffer for temporary line storage while data is being read
 *       p:  pointer to start of arrays
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
