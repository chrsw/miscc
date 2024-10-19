// soe.c 	Sieve of Eratosthenes - find primes up to n
// From https://www.youtube.com/watch?v=klcIklsWzrY
// 
// Build:
//  $ gcc -Wall -o soe soe.c -lm
//
// Run:
//  $ ./soe 100
// 
// TODO:
// Simplify solution
// Don't use prime status flag (bool mark)
// Print all numbers, display primes differently from non-primes
// Print using grid
//
// Example sieve with prime numbers visible and non-primes hidden:
//
//   ┌──┬──┬──┬──┬──┬──┬──┐
//   │ 0│ 1│ 2│ 3│  │ 5│  │
//   ├──┼──┼──┼──┼──┼──┼──┤
//   │ 7│  │  │  │11│  │13│
//   ├──┼──┼──┼──┼──┼──┼──┤
//   │  │  │  │17│  │19│  │
//   ├──┼──┼──┼──┼──┼──┼──┤
//   │  │  │23│  │  │23│  │
//   ├──┼──┼──┼──┼──┼──┼──┤
//   │  │29│  │  │  │  │  │
//   ├──┼──┼──┼──┼──┼──┼──┤
//   │  │  │37│  │  │  │41│
//   ├──┼──┼──┼──┼──┼──┼──┤
//   │  │43│  │  │  │  │  │
//   └──┴──┴──┴──┴──┴──┴──┘
//
////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

#define MAXN 1000

// hold numbers and prime status
struct sieve {
	int n;          // the number
	bool mark;      // prime == false
};

int main(int argc, char *argv[]) {

	int n;
	struct sieve *siv = NULL;

	// check arguments
	if (argc != 2) {
		printf("%s: argument error. use: %s n\n", argv[0], argv[0]);
		return 1;
	}
	if ((n = atoi(argv[1])) > MAXN) {
		printf("%s: argument error, max n = %d\n", argv[0], MAXN);
		return 2;
	}

	// storage for numbers and prime status
	siv = (struct sieve *)malloc((sizeof(struct sieve) * n) + 1);
	if (siv == NULL) {
		printf("%s: memory error\n", argv[0]);
		return 3;
	}

	// init memory
	for (int i = 0; i <= n; i++) {
		siv[i].n = i;
		siv[i].mark = false;
    }

	// Use the sieve to calculate primes
	for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= sqrt(i); j++)
            if (((i % j) == 0) && (siv[i].mark == false))
                siv[i].mark = true;
    }

	// unmarked numbers are primes
	for (int i = 0; i <= n; i++) {
		if (!siv[i].mark)
			printf("%d ", siv[i].n);
	}
	printf("\n");
	free(siv);

	return EXIT_SUCCESS;
}
