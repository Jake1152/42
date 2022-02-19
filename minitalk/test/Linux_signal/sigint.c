#include <signal.h>
#include <unistd.h>
#include <stdio.h>

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);

void    sig_handler(int signo);

int main(int argc, char **argv)
{
    int i = 0;
    signal(SIGINT, (void *)sig_handler);
    // signal(SIGINT, SIG_IGN);
    while (1)
    {
        printf("%d\n", i);
        sleep(2);
        // if (i == 50000000000)
            // signal(SIGINT, SIG_DFL);
        i++;
    }
    return (0);
}

void    sig_handler(int signo)
{
    printf("I Recieved SIGINT(%d)\n", SIGINT);
    sleep(4);
}

