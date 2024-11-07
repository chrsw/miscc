// pargs.c  print each command line argument
//
// $ gcc -o pargs pargs.c
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int i;

    // argv[0] is command name
    for (i = 1; i < argc; i++)
        printf("%s\n", argv[i]);
    
    return 0;
}
