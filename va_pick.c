// va_pick.c  simple example of function with variable argument lists.
//            pick letters from a string and print them.
//
//


#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int va_pick(int va_num, ...);

char *gstr = "variable length argument list test";

int va_pick(int va_num, ...)
{
    int i, pick, max_pick;
    va_list valist;
    
    if (va_num <= 0) return -1;
    /* initialize variable argument list */
    va_start(valist, va_num);

    /* get constraint info */
    max_pick = strlen(gstr);

    /* pick chars from the test string */
    for (i = 0; i < va_num; i++) {
        pick = va_arg(valist, int);
        if (pick < max_pick)
            printf("%c ", (int)gstr[pick]);
    }
    
    /* clean up variable arg list processesing data */ 
    va_end(valist);    
    return i;
}


int main(int argc, char *argv[])
{
    int i = 7;   
    printf("variable argument test example...\n");
    va_pick(i, 1, 2, 3, 5, 8, 13, 21);

    printf("\n"); 
}
