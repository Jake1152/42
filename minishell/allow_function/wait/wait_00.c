#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// pid_t   wait(int *wstatus);
// pit_t   waitpid(pit_t pid, int *wstatus, int options);
// int waitid(pt)


int main()
{
    int pid, childpid;
    int status;

    pid = fork();
    printf("pid : %d\n", pid);
    if (pid != 0)
    {
        childpid = wait(&status);
        printf("child [pid: %d] terminal note : %x\n", childpid, status);
    }
    else
    {
        puts("자식 프로세스 출력");
        exit(5);
    }
    return (0);
}
