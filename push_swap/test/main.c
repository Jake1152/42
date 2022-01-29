#include <stdio.h>

int main(int argc, char *argv[])
{
    int idx;

    idx = 1;
    printf("argc : %d\n", argc);
    while (idx < argc)
    {
        printf("%s\n", argv[idx]);
        idx++;
    }
    return (0);
}