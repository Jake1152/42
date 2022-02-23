#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	handler(int signo, siginfo_t *sf, ucontext_t *uc)
{
	(void)uc;
	if (sf->si_signo == SIGUSR1)
		printf("I received SIGUSR1\n");
	else if (sf->si_signo == SIGUSR2)
		printf("I received SIGUSR2\n");
	printf("## si code : %d\n", sf->si_code);
	printf("## si pid : %d\n", sf->si_pid);
}

int main()
{
	struct sigaction    act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = (void (*)(int ,siginfo_t *,void *))handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, (struct sigaction *)NULL) < 0)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &act, (struct sigaction *)NULL) < 0)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	while (42)
		pause();
	return (0);
}
