// mal_err  Use errno set by malloc
//          This should work on most POSIX/Unix/ISO systems..
//
// $ gcc -o mal_err mal_err.c
// $ ./mal_err 100
// $ ./mal_err -1
//
////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


int gi;
int *gpi;

int main(int argc, char *argv[0]) {

    int errmal;

    if (argc == 2)
        gi = atoi(argv[1]);

    if ((gpi = malloc(gi)) == NULL) 
        perror("mal_err");
         
    if (gpi != NULL)
        free(gpi);

    return EXIT_SUCCESS;
}
