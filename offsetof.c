/* vim:ts=4:sw=4:et:so=10:
 *      Vim modeline for consistent editor settings across files.
 *
 * offsetof.c
 *      Demonstrate the use of the offsetof() macro.
 *
 */

#include <stdio.h>
#include <stddef.h>


struct test_str {           // str def
    unsigned long a;        // str def 8    0
    unsigned long b;        // str def 8    8
    char c;                 // str def 1   16
    char d;                 // str def 1   17
    char arr_e[16];         // str def 16  18
    int x;                  // str def 4   36
    int y;                  // str def 4   40
};

int main(int argc, char *argv[]) {

    struct test_str str_test;
    
    printf("Demonstrting ofsetof()...\n");
    printf("sizeof(str_test): %zu\n", sizeof(str_test));
    printf("offsetof(struct test_str,a):     %zu\n", 
            offsetof(struct test_str, a));
    printf("offsetof(struct test_str,b):     %zu\n", 
            offsetof(struct test_str, b));
    printf("offsetof(struct test_str,c):     %zu\n", 
            offsetof(struct test_str, c));
    printf("offsetof(struct test_str,d):     %zu\n", 
            offsetof(struct test_str, d));
    printf("offsetof(struct test_str,arr_e): %zu\n", 
            offsetof(struct test_str, arr_e));
    printf("offsetof(struct test_str,x):     %zu\n", 
            offsetof(struct test_str, x));
    printf("offsetof(struct test_str,y):     %zu\n", 
            offsetof(struct test_str, y));
    



    return 0;
}
