#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// void    handler()
// {
//     ;
// }

int kill(pid_t pid, int sig);

int main(int argc, char *argv[])
{
    int pid;
    int sig_num;

    if (argc != 3)
    {
        printf("usage %ss [pid] [signum]\n", argv[0]);
        return 1;
    }
    /* 실행인자로 pid번호와
        전송할 signal 번호를 받아들여서
        이를 해당 pid로 보낸다. */
    pid = atoi(argv[1]);
    sig_num = atoi(argv[2]);
    kill(pid, SIGUSR1));
    if (!kill(pid, SIGUSR1))
    {
        perror("SIgnal Send error");
        return 1;
    }
    return (0);
}