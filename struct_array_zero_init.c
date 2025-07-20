// struct_array_zero_init: how you can initialize an array of structs to zero

#include <stdio.h>

struct tstr_zi {

    int i;
    short sh;
    char c;
};


int main(void) {

    // initialize a struct to integers
    struct tstr_zi szi = {1, 2, 3};

    // initialize all members of all structs in an array to zero
    struct tstr_zi aszi[5] = {0};

    // demonstrate the results of the initialization
    printf("szi.i = %d\n", szi.i);
    printf("szi.sh = %d\n", szi.sh);
    printf("szi.c = %d\n", szi.c);

    printf("aszi[0].i = %d\n", aszi[0].i);
    printf("aszi[0].sh = %d\n", aszi[0].sh);
    printf("aszi[0].c = %d\n", aszi[0].c);

    printf("aszi[1].i = %d\n", aszi[1].i);
    printf("aszi[2].i = %d\n", aszi[2].i);
    printf("aszi[3].i = %d\n", aszi[3].i);

    printf("aszi[4].i = %d\n", aszi[4].i);
    printf("aszi[4].sh = %d\n", aszi[4].sh);
    printf("aszi[4].c = %d\n", aszi[4].c);

    return 0;
}

