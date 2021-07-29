#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	while (len--)
		ft_putchar_fd(s++, fd);
	ft_putchar_fd(s++, '\n');
	ft_putchar_fd(s, '\0');
}
