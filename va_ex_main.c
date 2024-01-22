/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * va_ex_main.c
 *      main() driver for variadic function argument example.
 *
 * Build:
 *      $ gcc -o va_ex_main va_ex_main.c va_ex.c
 *
 * Run:
 *      $ ./va_ex_main
 *
 */

#include <stdio.h>
#include "va_ex.h"

int main(int argc, char *argv[])
{
    int n = 10;
    int i = 0;
    (void)argc;
    (void)argv;
    
    i = va_ex(1, n);
    printf("main: i = %d\n", i);
    return 0;
}
