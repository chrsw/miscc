// pidfile.c  make a file with the pid in the name
//
// $ gcc -o pidfile pidfile.c
//
// $ ./pidfile
///////////////////////////////////////////////////////////////////////////


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <libgen.h>
#include <string.h>

int main(int argc, char *argv[])
{

    pid_t pid;
    char pids[20];
    FILE *fp = NULL;
    char *path;

    path = malloc(sizeof(argv[0]+1));
    strcpy(path, argv[0]);
    //printf("path: %s\n", path);
    printf("basename(path): %s\n", basename(path));

    pid = getpid();
    sprintf(pids, "/tmp/%s.%d", basename(path), pid);
    
    if ((fp = fopen(pids, "w+" )) != NULL) {
        fprintf(fp, "hello pidfile\n");
        printf("file created\n");
    }

    if (fp)
        fclose(fp);
    return EXIT_SUCCESS;
}
