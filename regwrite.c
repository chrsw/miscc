// regwrite:  example of writing to an address
//            probably don't run this on a hosted platform

#include <stdio.h>

int i;
int *p = &i;

int main () {

        printf("p = %p \n", p);
        printf("p = %d \n", *p);
        // (*((volatile unsigned int *)(0x80005C00 + 0x44))) = 0x400;
        (*((volatile unsigned int *)(0x60104c))) = 0x400;
        printf("p = %d \n", *p);
 return 0;
}
//p = 0x60104c 
