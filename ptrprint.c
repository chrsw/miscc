// ptrprint:  print a pointer value, nicely
// C99 only

#include <stdio.h>
#include <inttypes.h>

unsigned char g = 1;
unsigned char * ptr;

int main(int argc, char *argv[])
{
    uint32_t x = 42;
    ptr = &g;
    printf("This is a pointer value: 0x%"PRIXPTR" \n", (uintptr_t)ptr);
    return 0;
}
