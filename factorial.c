/* vim: ts=4 sw=4 et:
 * 
 * factorial.c	
 *      Compute the factorial (n!) of an integer.
 *      Loop version.
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

int main(int argc, char *argv[]) {

	unsigned int n = 0U;         // Number to factorial
	unsigned long nfact = 0U;    // Intermediate and result

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

	nfact = (unsigned long)n;                 // Compute the factorial.
	while (--n > 1) nfact = nfact * (unsigned long)n;
	
	printf("%lu\n", nfact);                   // Show result and exit.
	return 0;
}
