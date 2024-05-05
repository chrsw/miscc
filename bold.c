// bold.c  display some text in bold

#include <stdio.h>

int main(void)
{
    for(int i = 1; i <= 1; i++)
        printf("normal \e[1mbold\e[m normal\n");
    return 0;
}
