/* vim:ts=4:sw=4:et:so=10:
 *
 * ptr_str_arr_loop.c
 *      Loop through an array of strings using pointers. Simple
 *      app demonstrating how these are used.
 *
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 0;
    int j = 0;

    const char *ss[] = {
        "pointers",
        "strings",
        "arrays",
        "loops",
        "and",
        "in",
        "c"
    };

    /* get the length of list of strings at compile time. */
    const unsigned char str_cnt = (unsigned char)
                                    (sizeof(ss)/sizeof(*ss));

    do {
        printf("%s\n", ss[i++]);
    } while (i < str_cnt);

    i = 0;

    do {
        for (j = 0; j < str_cnt - i; j++) printf(" ");        
        printf("%s\n", ss[i++]);
    } while (i < str_cnt);
    
    return 0;
}
