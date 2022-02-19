#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int signo){
    psignal(signo, "Signal Receved!:");
    sleep(1);
    printf("After Sleep\n");
}
int main(void){
    struct sigaction act;

    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT); //block SIGQUIT
    act.sa_flags = 0;
    act.sa_handler = handler;
    if(sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0){
        perror("sigaction");
        exit(1);
    }
    fprintf(stderr, "Input SIGINT: ");
    pause();
    fprintf(stderr, "After Signal Handler\n");
    return 0;
} 

/*
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);

static int exit_flag = 0;

static void hdl(int sig)
{
    exit_flag =1;
}

int main(int argc, char *argv[])
{
    struct sigaction act;

    memset(&act, '\0', sizeof(act));
    act.sa_handler = &hdl;
    if (sigaction(SIGTERM, &act, NULL) < 0)
    {
        perror("sigaction");
        return 1;
    }
    while (!exit_flag)
        ;
    return (0);
}
*/