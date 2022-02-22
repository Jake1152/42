#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char            *str;
    unsigned int    flag;
    pid_t           server_pid;
    size_t          idx;

    str = "Hello world";
    idx = 0;
    
    if (argc != 2)
    {
        printf("non invalid argument.\n");
        exit(EXIT_FAILURE);
    }
    server_pid = atoi(argv[1]);
    while (str[idx])
    {
        printf("char : %c\n", str[idx]);
        printf("char in dec : %d\n", str[idx]);
        flag = 1 << 7;
        while (flag)
        {
            printf("str[idx] & flag : %d\n", str[idx] & flag);
            if (str[idx] & flag)
                kill(pid)
            flag >>= 1;
        }
        printf("char : %du\n", flag);
        idx++;
    }
    return (0);
}
