/*
 * static.c:	Demonstration of building static executable 
 *
 * Build: 	$ gcc -static -o static static.c
 *
 */

#include <stdio.h>

int main(int argc, char **argv) {

        printf("Hello from a statically linked executable.\n");
        return 0;
}
