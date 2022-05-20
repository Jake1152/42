#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include "stdlib.h"
#include <unistd.h>

extern int errno;

int main()
{
	int fd1 = open("test1152.txt", O_RDONLY | O_CREAT);

	if (fd1 < 0)
	{
		perror("cl");
		exit(1);
	}
	printf("opened the fd = %d\n", fd1);
	// Using close system call
	if (close(fd1) < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("closed the fd.\n");
	return (0);
}
