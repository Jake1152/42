#include <stdio.h>

void hello()
{
    printf("Hello, how are you?\n");
}

void hola()
{
    printf("Hola como estas?");
}

int main()
{
    void    (*fp)();

    fp = hello;
    fp();
    fp = hola;
    fp();
    return (0);
}

/*
int sum(int a, int b)
{
    return (a + b);
}

int main()
{
    int (*ptrsum)(int a, int b);

    ptrsum = sum;
    printf("sum address is %p\n", &sum);
    printf("ptrsum value is %p\n", ptrsum);
    printf("ptrsum address is %p\n", &ptrsum);
    return (0);
}

*/