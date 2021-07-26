#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	while (len--)
		ft_putchar_fd(fd, &s);
}
