// bold.c  print some characters in bold typeface

#include <stdio.h>

int main(void)
{
    for(int i = 1; i <= 1; i++)
        printf("normal \e[1mbold\e[m normal\n");
    return 0;
}
