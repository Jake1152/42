#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample()
{
	int x = 1;
	// child process because return valuee xero
	if (fork() == 0)
		printf("Child has x = %d\n", ++x);
	// parent process because return value-non-xero
	else
		printf("Parent has x = %d\n", --x);
}

int main()
{
	forkexample();
	return (0);
}
