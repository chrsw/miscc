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


void create_elm(struct dyntest **, int i);

int main(void) {

    int i;
    struct dyntest *d;
    struct dyntest *str_arr[10];
    //struct dyntest *str_arr_func[10];

    struct dyntest *pstr_dyntest;
    struct dyntest *pstr_dyntest_func = NULL;

    // Static structure part of test
    d = malloc(sizeof(d));
    d->count = 0;
    d->list = malloc(sizeof(int)*10);

    // The structure part of the test
    for (i = 0; i < 10; i++) {
        d->list[i] = i;
        d->count+=2;
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", d->list[i]);
    }
    printf("\ncount = %d\n", d->count);

    d->list = realloc(d->list, sizeof(int) * sizeof(int)*d->count);
    for (i = 0; i < d->count; i++) {
        d->list[i] = i;
    }
    for (i = 0; i < d->count; i++) {
        printf("%d ", d->list[i]);
    }
    printf("\ncount = %d\n", d->count);

    for (i = 0; i < 10; i++) {
        str_arr[i] = malloc(sizeof(struct dyntest));
        str_arr[i]->count = i;
    }

    for (i = 0; i < 10; i++)
        printf("str_arry[%d] count = %d\n", i, str_arr[i]->count);

    pstr_dyntest = malloc(sizeof(struct dyntest));
    pstr_dyntest->count = 1;
    pstr_dyntest->list = malloc(sizeof(int)*10);
    printf("pstr_dyntest->count = %d\n", pstr_dyntest->count);
    for (i = 0; i < 10; i++) {
        pstr_dyntest->list[i] = i;
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", pstr_dyntest->list[i]);
    }
    printf("\n\n");

    
    create_elm(&pstr_dyntest_func, 1);
    for (i = 0; i < 10; i++) {
        printf("%d ", pstr_dyntest_func->list[i]);
    }
    printf("\n\n");

    return 0;
}


void create_elm(struct dyntest **delm, int cnt) {
    int i = 0;
    *delm = malloc(sizeof(delm)*cnt); 
    struct dyntest *pdyntest = *delm;
    pdyntest->count = cnt;
    printf("created %d element\n", cnt);
    pdyntest->list = malloc(sizeof(int)*10);
    for (i = 0; i < 10; i++) {
        pdyntest->list[i] = i*2;
    }
}
