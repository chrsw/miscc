// Test ispal()
// 
// Build:
//     $ gcc -o ispal_test ispal_test.c ispal.c reverse.c -lm

#include <stdio.h>
#include <stdbool.h>

bool ispal(int n);

int main(void) {

    int n = 4321234;

    if (ispal(n))
        printf("palindrome!\n");
    else
        printf("not palindrome!\n");

    return 0;
}
