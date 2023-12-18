#include <stdio.h>
int main(void) {
    int c = '`';
    printf("` = %d 0x%02X\n", c, c);
    c = '\'';
    printf("` = %d 0x%02X\n", c, c);
    return 0;
}
