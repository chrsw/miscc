#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

        unsigned int i = 0;
        pid_t pid = 0;
        for (i = 0; i < 3; ++i){
                pid = fork();
                printf("i = %d\n\r", i);
        }
        return 0;
}
