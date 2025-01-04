// memmath: examples of math on objects in memory
//

#include <stdio.h>
#include <stdint.h>

uint64_t a[4] = {0};


int main(void) {

    uint64_t *ptr_start = a;
    uint64_t *ptr_end = &a[4];
    uint64_t memcount = (uint64_t)&a[3] - (uint64_t)a;

    printf("ptr_start = %p\n", ptr_start);
    printf("ptr_end = %p\n", ptr_end);
    printf("memcount = %ld\n", memcount);

    return 0;
}
