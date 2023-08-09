/* vim:ts=4:sw=4:et:so=10:
 *      Vim modeline for consistent editor settings across files.
 *
 * ret_str_arr.c
 *      Example of how a function can return array wrapped in a structure.
 *
 * Description:
 *      This code is a demonstration for a potentially useful C feature, not a
 *      real world solution to an actual problem.
 *
 * Build:
 *      $ gcc -o ret-str-arr ret_str_arr.c
 *
 * Run
 *      $ ./ret-str-arr
 *
 */

#include <stdio.h>
#include <string.h>

#define STR_ARR_SIZE 10

struct str_incl_array {
    char ca[STR_ARR_SIZE];
} g_str_array;

struct str_incl_array ret_str_arr(const char *s);

/* call a function that returns a structure around array and display */
int main(int argc, char *argv[]) {

    struct str_incl_array a_str_array;
    a_str_array = ret_str_arr("hello");
    a_str_array.ca[0] = 'H';
    printf("array in structure: %s\n", a_str_array.ca);
    return 0;
}

/* example_fn:  return array encapsulated in a structure */
struct str_incl_array ret_str_arr(const char *s) {

    strncpy(g_str_array.ca, s, STR_ARR_SIZE);
    return g_str_array;
}
