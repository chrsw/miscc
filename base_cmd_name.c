// base_cmd_name.c  print the executable name with and without full path
//
// Uses:
//  basename()
//  malloc()
//  realpath()
//  printing to stderr
//
// $ gcc -o base_cmd_name base_cmd_name
// $ ./base_cmd_name
// 
///////////////////////////////////////////////////////////////////////////


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <linux/limits.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    char *path = NULL;
    char *fullpath = NULL;

    path = malloc(sizeof(argv[0]+1));
    fullpath = malloc(PATH_MAX+1);

    if (path == NULL || fullpath == NULL) {
        exit(1);
        fprintf(stderr, "%s: memory error\n", argv[0]);
    }

    // basename() works on copy of path
    strcpy(path, argv[0]);
    realpath(path, fullpath);
    if (fullpath == NULL) {
        exit(1);
        fprintf(stderr, "%s: realpath error\n", argv[0]);
    }

    printf("argv[0]: %s\n", argv[0]);
    printf("basename(path): %s\n", basename(path));
    printf("realpath(path): %s\n", fullpath);

    return EXIT_SUCCESS;
}
