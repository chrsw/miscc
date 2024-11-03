// allocin:  allocate space for input.
//           read file into memory with a pointer to each line.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int allocin(char ***p);

char **ghap_ln;
char buf[BUFSIZ];

#ifdef MAIN
int main(int argc, char *argv[]) {

    char **hap_ln;              // array of pointers
                                // that point to each line read in
    char buf[BUFSIZ];
    int lines = 0;

    (void)argc;
    hap_ln = (char **)malloc(sizeof(char *));

    /*while (fgets(buf, sizeof(buf), stdin) != NULL) {
        char **hap_new = (char **)realloc(hap_ln, 
                                          (lines+1)*sizeof(char **));
        if (hap_new == NULL) {
            fprintf(stderr, "%s: memory error\n", argv[0]);
            return -1;
        }
        
        hap_ln = hap_new;
        hap_ln[lines] = (char*)malloc(sizeof(buf)+1);
        memcpy(hap_ln[lines], buf, sizeof(buf));
        lines++;
	}*/

    // read input lines into dynamically allocated arrays
    lines = allocin(&ghap_ln);

    // print out the input
    for (int i = 0; i < lines; i++)
        printf("%s", ghap_ln[i]);

    free(hap_ln);
    free(ghap_ln);
    return 0;
}
#endif  // MAIN

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
            fprintf(stderr, "%s: memory error\n", __FUNCTION__);
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