/* vim:ts=4:sw=4:et:so=10:
 *
 * str_ptr_loop.c
 *      Loop through a list of strings using pointers.
 *
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 0;
    char *ss[] = {
        "string",
        "pointer",
        "loop",
        "in",
        "c",
        NULL
    };
    
    printf("str_ptr_loop\n"); 

    do {
        printf("%s\n", ss[i++]);
    } while (ss[i]);
    
    return 0;
}
