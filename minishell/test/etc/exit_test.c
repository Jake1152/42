#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	exit((char)atoi(argv[1]));
	return (0);
}
