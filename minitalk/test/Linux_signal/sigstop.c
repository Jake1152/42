#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void mystop(int signo)
{
	printf("I Received Signal : %d\n", signo);
}

int main(int argc, char **argv)
{
	int i;

    i = 0;
	signal(SIGQUIT, (void *)mystop);
	while (1)
	{
		printf("%d\n", i);
		i++;
		sleep(1);
	}
	return (1);
}
