// basename_cmd_name.c  print the executable name without path
//
// Linux only?
//
// $ gcc -o basename_cmd_name basename_cmd_name
//
// $ ./basename_cmd_name
///////////////////////////////////////////////////////////////////////////


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <libgen.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *path = NULL;

    path = malloc(sizeof(argv[0]+1));

    if (path == NULL) {
        exit(1);
        fprintf(stderr, "%s: memory error\n", argv[0]);
    }

    // basename() works on copy of path
    strcpy(path, argv[0]);

    printf("argv[0]: %s\n", argv[0]);
    printf("basename(path): %s\n", basename(path));

    return EXIT_SUCCESS;
}
