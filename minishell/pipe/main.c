#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
/*
    ./pipex 
*/
int main(int argc, char **argv)
{
    int fd[2];
    int pid;
    int pid_second;

    if (pipe(fd) < 0)
        printf("Pipe Error: %s\n", strerror(errno));
    pid = fork();
    if (pid < 0)
        printf("fork Error: %s\n", strerror(errno));
    if (pid == 0) // child proces
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", "-al", NULL);
    }
    // pid_second = fork();
    // if (pid_second < 0)
    //     printf("fork Error: %s\n", strerror(errno));
    // if (pid_second == 0)
    // {
    //     dup2(fd[0], STDIN_FILENO);
    //     close(fd[0]);
    //     close(fd[1]);
    //     execlp("wc", "wc", "-l", NULL);
    // }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid, NULL, 0);
    // waitpid(pid_second, NULL, 0);
    return (0);
}