/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dynarray.c
 *      Use malloc() and realloc();
 *
 * Description:
 *      Not getting something right when dynamically allocating
 *      memory for pointers inside structure members. Setting this simple
 *      app as a test case to figure out what's wrong.
 *
 * Build:
 *      $ gcc -o dynarray dynarray.c
 *
 * Run:
 *      $ ./dynarray
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple structure for the test
struct dyntest {
    int count;
    int *list;
};


void create_elm(struct dyntest *);

int main(int argc, char *argv[]) {

    // Local vars for experiments
    int *dynarray;
    int i;
    int *tmp;
    
    struct dyntest *d;

    struct dyntest *strarray[10];

    // Supress warnings
    (void)argc;
    (void)argv;
    tmp = &i;

    // Allocate some memory, don't bother checking for success
    dynarray = malloc(sizeof(int)*5);

    // Structure part of test
    d = malloc(sizeof(d));
    d->count = 0;
    d->list = malloc(sizeof(int)*10);


    // Fill the allocated memory
    for (i = 0; i < 5; i++) {
        dynarray[i] = i;
    }
    // Print the allocated memory
    for (i = 0; i < 5; i++) {
        printf("%d ", dynarray[i]);
    }
    printf("\n");

    // Now realloc for added size...
    dynarray = realloc(dynarray, sizeof(int) * 10);

    // Fill the added size
    for (i = 5; i < 10; i++) {
        dynarray[i] = i;
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", dynarray[i]);
    }
    printf("\n");
    
    //printf("tmp = %p\n", (void *)tmp);

    // Now mess with dynarray...
    tmp = dynarray;
    dynarray = &i;
    dynarray = tmp;
    dynarray = realloc(dynarray, sizeof(int)*20);

    // Now the structure part of the test
    for (i = 0; i < 10; i++) {
        d->list[i] = i;
        d->count+=2;
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", d->list[i]);
    }
    printf("\n%d\n", d->count);

    d->list = realloc(d->list, sizeof(int) * sizeof(int)*d->count);
    for (i = 0; i < d->count; i++) {
        d->list[i] = i;
    }

     for (i = 0; i < d->count; i++) {
        printf("%d ", d->list[i]);
    }
    printf("\n%d\n", d->count);

    // Now using functions
    for (i = 0; i < 10; i++)
        create_elm(strarray[i]);

    return 0;
}


void create_elm(struct dyntest *delm) {
    delm = malloc(sizeof(delm)); 
    delm->count = 0;
    delm->list = malloc(sizeof(int)*10);
}
