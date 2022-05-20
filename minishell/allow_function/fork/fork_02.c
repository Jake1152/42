#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample()
{
	// child process because return valuee xero
	if (fork() == 0)
		printf("Hello from child!\n");
	// parent process because return value-non-xero
	else
		printf("Hello from Parent!\n");
}

int main()
{
	// make two process which run same
	// program after this instruction
	forkexample();
	return (0);
}
