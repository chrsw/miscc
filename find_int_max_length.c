/* vim:ts=4:sw=4:et:so=10:
 *
 * find_int_max_length.c
 *      Find max integer size on host.
 *
 * Output:
 *      Length of integer data type in digits.
 *
 * Build:
 *      $ gcc -c find_int_max_length.c
 *
 */

#include <limits.h>

static int find_int_max_length(void);

static int find_int_max_length(void) {

    int n = INT_MAX;
    int i = 0;

    do { i++; } while ((n /= 10) > 0);

    return i;
}

