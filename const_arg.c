#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_conv {

        unsigned char ucData1;
        unsigned char ucData2;
} tst_conv_var;

static void foo();
static void bar(const struct st_conv *);


int gi_message;
int gi_response;

int gi_new = 0;
int gi_old = 0;

int main(int argc, char *argv[]) {

        gi_message = 1;
        gi_response = 0;

        printf("gi_message addr: %p\n", &gi_message);
        foo();
        bar(&(tst_conv_var){0,8});
        return 0;
}


static void foo() {

        gi_message = 0;
}

static void bar(const struct st_conv *cv) {

        if (cv->ucData1 == 0) printf("bar(): got reset data\n");
        if (cv->ucData2 == 0) printf("bar(): got magic data\n");
        printf("bar(): &cv addr: %p\n", &cv);
        printf("bar(): cv addr: %p\n", cv);
}
