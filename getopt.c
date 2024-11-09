// getopt:  simply use getopt()
//
// $ gcc -o getopt getopt.c

#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

    int opt = ' ';
    const char *optstring = "welp";

    // print every option passed on command line
    while ((opt = getopt(argc, argv, optstring)) > 0)
        printf("%c\n", opt);

    printf("\n");
    return 0;
}