#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	int     fd;
	int     dup_fd;
	int     read_len;
	char    *buf;

	fd = open("./a.txt", O_RDWR, 0644);
	printf("fd : %d\n", fd);
	// dup_fd = dup2(fd, fd);
	printf("before dup\n");
	read_len = 1;
	while (read_len > 0)
	{
		read_len = read(fd, buf, 5);
		printf("read_len : %d\n", read_len);
		printf("read str : %s\n", buf);
	}
	printf("%s\n", strerror(errno));
	dup_fd = dup(fd);
	printf("dup fd : %d\n", dup_fd);
	printf("fd : %d\n", fd);
	dup2(fd, dup_fd);
	printf("dup fd : %d\n", dup_fd);
	printf("fd : %d\n", fd);
	printf("STDIN_FILENO : %d\n", STDIN_FILENO);
	// while (read(dup_fd, buf, 5) > 0)
	
	// {
	//     read_len = read(dup_fd, buf, 5);
	//     printf("read_len : %d\n", read_len);
	//     printf("%s\n", buf);
	// }
	// printf("%s\n", strerror(errno));
	return (0);
}