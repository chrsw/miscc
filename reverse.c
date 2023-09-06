// Reverse an integer

#include <stdlib.h>
#include <math.h>

int reverse(int num) {

    int len = 1;
    int rev = 0;
    char digit;

    int copy = num;    

    while (num /= 10)
	len++;

    num = copy;
    while (digit = num % 10) {
	rev += pow(10,--len) * digit; 
        num /= 10;
    }

    return rev;
}
