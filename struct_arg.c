/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * struct_arg.c
 *      Short example of passing a structure.
 *
 * Build:
 *      $ gcc struct_arg.c
 *
 * Run:
 *      ./a.out
 *      $ echo $? 
 *
 */

#include <stdio.h>

struct point {int a; int b; int c;};

int foo(struct point);

int main(void) {

	int x = 0;

	x = foo((struct point){.a = 1, .b = 2, .c = 3});
	
	return x;
}


// foo:  take a structure and return a field
int foo(struct point p) {

	return p.a;
}
