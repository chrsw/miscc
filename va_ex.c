/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * va_ex.c
 *      Minimal printf with variable argument list.
 *      Excerpt from section 7.3 with additions for Exercise 7-3.
 *
 * Build:
 *      See main() driver.
 *
 * Run:
 *      See main() driver.
 *
 */

#include <stdarg.h>
#include <stdio.h>
#include "va_ex.h"

/* va_ex:  minimal printf with variable argument list */
int va_ex(int i, ...)
{

    va_list ap;                     /* points to each unnamed arg in turn */   
    char *p;
    int ival;

    va_start(ap, i);              /* make ap point 1 1st unnamed arg */
    ival = va_arg(ap, int);
    va_end(ap);                     /* clean up when done */
    return ival;
}
