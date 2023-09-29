/* vim:ts=4:sw=4:et:so=10:
 *      Vim modeline for consistent editor settings across files.
 *
 * comp_lit.c
 *      Example using compund literals.
 *
 */

#include <stdio.h>

struct s { 
	int a; 
	int b;
} gs;

struct d {

    int i;
    char *s;
};

void foo(int);
int bar(struct s);
void baz(struct d);

int main(int argc, char *argv[]) {

    //struct s ls;
    struct d ds = {.i = 0, .s = "initialized"};
   
    foo(1); 
    baz(ds);
    baz((struct d){.i = 1, .s = "random"});

    return 0;
}

void foo(int x) {

    int y;
    struct s fs = {.a = x, .b = x};
    
    
    y = bar(fs);
    printf("foo: y = %d\n", y);
    
    printf("foo: bar() = %d\n", bar((struct s){.b = 3, .a = 0}));


}

int bar(struct s ps) {

    if ( ps.a > 0)
        printf("bar: a = %d\tb=%d\n", ps.a, ps.b);
    else
        return ps.b;

    return ps.b - ps.a;
}

void baz(struct d db) {

    printf("baz: %s\n", db.s);
}

    

