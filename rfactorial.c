/* vim:ts=4:sw=4:et:
 * 
 * rfactorial.c	
 *      Compute the factorial (n!) of an integer.
 *      Recursive version.
 *
 * Description:
 *          The definition of the factorial function:
 *          n! = n * (n - 1) * (n - 2) * (n - 3) * ... * 3 * 2 * 1
 *          Uses a static default value for n.
 *
 * Returns:
 *          Success.
 */

#include <stdio.h>

unsigned int rfactorial(unsigned int n);

int main(void) {

	unsigned int n = 7U; 

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

