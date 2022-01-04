#include <stdio.h>

int main()
{
    int a = 42;

    printf("%%d: %d\n%%p: %p\n%%x: %x\n", a, &a, a);
    printf("\n\n");
    printf("%%d: %d\n%%p: %x\n%%llx: %d\n", a, &a, a);
    return (0);
}