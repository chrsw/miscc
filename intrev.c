// Reverse an integer

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {

	int len = 1;
    int num = 0;
    int rev = 0;
    char digit;

	if (argc > 1)
	    num = atoi(argv[1]);
	else
        return -1;

    int copy = num;    

	while (num /= 10)
		len++;

    num = copy;
	while (digit = num % 10) {
        //printf("digit = %d len = %d  ", digit, len);
		rev += pow(10,--len) * digit; 
        //printf("rev = %d\n", rev);
        num /= 10;
    }

    printf("num = %d\nrev = %d\n", copy, rev);
	return len;
}
