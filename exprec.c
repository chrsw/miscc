// exprec.c  Exponential function, recursive version.
// Given n returns 2^n

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int exprec(int);
	// default value
	int n = 4;

	// get a new value from command line
	if (argc == 2) n = atoi(argv[1]);	

	// find the exponential
	printf("%d\n", exprec(n));	
	return EXIT_SUCCESS;
}


// exprec:  find the result of 2^n, recursively
int exprec(int n) {

	return n > 0 ? 2*exprec(n-1) : 1;
}
