#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction act_new;
struct sigaction act_old;

void sigUSR1_handler(int signo)
{
	printf("Test SIGUSR1\n");
}

void sigUSR2_handler(int signo)
{
	printf("Test SIGUSR2\n");
}

int main(void)
{
	struct sigaction	act_usr1;
	struct sigaction	act_usr2;
	struct sigaction	act_old;
	pid_t				my_pid;

	act_usr1.sa_handler = sigUSR1_handler;    // signal handler assign
	act_usr2.sa_handler = sigUSR2_handler;    // signal handler assign

	sigaction(SIGUSR1, &act_usr1, NULL);
	sigaction(SIGUSR2, &act_usr2, NULL);
	my_pid = getpid();
	printf("my_pid : %d\n", my_pid);
	while (1)
	{
		printf("jake's test\n");
		kill(my_pid, SIGUSR1);
		sleep(1);
		kill(my_pid, SIGUSR2);
		sleep(1);
	}
	return (0);
}