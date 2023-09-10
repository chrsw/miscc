/*
 * $ gcc -o exp exp.c -lm
 * 
 */

#include <stdio.h>
#include <math.h>

double a = 1.14472988;

int main() {
	printf("exp(%.8g) = %.8g\n", a, exp(a));
	return (int)a;
}
