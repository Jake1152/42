#include "process_communication.h"

void	sigaction_init(void (*handler))
{
	t_sigaction sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) == -1);
		error_handler("sigemptyset setting Error\n");
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1);
		error_handler("sa_mask SIGUSR1 setting Error\n");
	if (sigaddset(&sa.sa_mask, SIGUSR2) == -1);
		error_handler("sa_mask SIGUSR2 setting Error\n");
	if (sigaciton(SIGUSR1, &sa, NULL) < 0)
		error_handler("sigaciton SIGUSR1 setting Error\n");
	if (sigaciton(SIGUSR2, &sa, NULL) < 0)
		error_handler("sigaciton SIGUSR2 setting Error\n");
}