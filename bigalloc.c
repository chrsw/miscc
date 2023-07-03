/* vim:ts=4:sw=4:et:so=10:
 *
 * bigalloc.c
 *
 * Source:
 * https://jorengarenar.github.io/blog/less-known-c
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

	int i, j;	
    int m, n;
    
    unsigned int seed;

    // Allocate a huge matrix
    // (90000) for both dimensions failed to allocate
	int (*ap)[100][100] = malloc(sizeof *ap);

    if (!ap) exit(1);

    // To test this allocation, fill up the 2D array then
    // randomly select elments and show a 5x5 surrounding region.

    // Fill the matrix
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			(*ap)[i][j] = (i + j) % 100;

    // Generate 2 random numbers. 1 for row, 1 for column.
    seed = time(NULL);
    srand(seed);
   
    i = rand() % 100;
    j = rand() % 100; 

    printf("%d,%d\n", i, j);

    // Got the two random numbers, now show the surrounding 5x5 square.
    // Values out of range will be blank.
    for (m = i-2 ; m <= i+2 ; m++) {
        for (n = j-2; n <= j+2; n++) {
            if ((m >= 0) && (m <= 99) &&
                (n >= 0) && (n <= 99))
                printf("%2d ", (*ap)[m][n]);
            else
                printf("   ");
        }
        printf("\n");
    } 
    
	return 0;

}
