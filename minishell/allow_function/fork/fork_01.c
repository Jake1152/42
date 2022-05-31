#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	// make two process which run same
	// program after this instruction
	fork();
	printf("=== First fork === %d\n", getpid());
	fork();
	printf("=== Second fork === %d\n", getpid());
	fork();
	printf("=== Third fork === %d\n", getpid());
	printf("hola!, pid : %d\n", getpid());

	sleep(1);
	return (0);
}
