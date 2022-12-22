/* vim:ts=4:sw=4:et:
 * 
 * rfactorial.c	
 *      Compute the factorial (n!) of an integer.
 *      Recursive version.
 *
 * Description:
 *      The definition of the factorial function:
 *      n! = n * (n - 1) * (n - 2) * (n - 3) * ... * 3 * 2 * 1
 *      Number to factorial comes from the command line or a default
 *      value if none is passed by command line argument.
 *
 * Returns:
 *      Success.
 */

#include <stdio.h>
#include <stdlib.h>

unsigned int rfactorial(unsigned int n);

int main(int argc, char *argv[]) {

	unsigned int n = 0U; 

    if (argc == 2) {
       n = atoi(argv[1]); 
    }
    else {
	    n = 5U;
    }


	printf("%d! = ", n);

	printf("%d\n", rfactorial(n));      // Show result and exit successfully.
	return 0;
}

/*
 * rfactorial    Rcursively compute the facorial of a given non-zero integer.
 */
unsigned int rfactorial(unsigned int n) {

    if (n == 1)
        return n;
    else
        return (n * rfactorial(n-1));
}

