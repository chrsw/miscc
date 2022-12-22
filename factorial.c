/* vim: ts=4 sw=4 et:
 * 
 * factorial.c	Compute the factorial (n!) of an integer.
 *          Loop version.
 *
 *          The definition of the factorial function:
 *
 * n! = n * (n - 1) * (n - 2) * (n - 3) * ... * 3 * 2 * 1
 *
 * Number to factorial comes from the command line or a default
 * value if none is passed by command line argument.
 *
 * Returns success.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	unsigned int n = 0U;        // Some vars for factorial
	unsigned int nfact = 0U;    // computation.

    // Grab number to factorial from cmd line or use
    // default value.
    // This isn't safe, just for demonstration.
    if (argc == 2) {
       n = atoi(argv[1]); 
    }
    else {
	    n = 5U;
    }

    // Show the starting value of n.
	printf("%d! = ", n);

	nfact = n;                  // Compute the factorial.
	while (--n > 1) nfact = nfact * n;
	
	printf("%d\n", nfact);      // Show result and exit successfully.
	return 0;
}
