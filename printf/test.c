#include <stdio.h>
#include <unistd.h>
#include <limits.h>

static size_t   count_digits(int n, int base);
int	ft_itoa_base(long long num, int base_num);
int	ft_putstr_fd(char *s, int fd);

int main()
{
    long long a = 9223372036854775807LL;
    int base_num = 16;

    // printf("%%d: %d\n%%p: %p\n%%x: %x\n", a, &a, a);
    // printf("\n\n");
    // printf("%%d: %d\n%%p: %x\n%%llx: %d\n", a, &a, a);

    printf("o : %o\n", a, a);
    printf("x : %llx\nX : %llX\n", a, a);
    printf("d : %lld\n", a);
    printf("p : %p\n", &a);
    ft_itoa_base(a, base_num);
    return (0);
}

static size_t   count_digits(int n, int base)
{
	size_t	expo;		

	expo = 0;
	if (n < 0)
	{
		n *= -1;
		expo++;
	}
	while (n)
	{
		expo++;
		n /= base;
	}
	return (expo);
}

int	ft_itoa_base(long long num, int base_num)
{
	size_t			digits;
	char			*base;
	char			to_be_s[20];
	unsigned long	nb;

	base = "0123456789abcdef";
	if (num == 0)
		return (ft_putstr_fd("0", 1));
	digits = count_digits(num, base_num);
	if (base_num != 10 && num < 0)
		nb = ULLONG_MAX;
	if (num < 0)
	{
		num = -num;
		to_be_s[0] = '-';
	}
	to_be_s[digits] = '\0';
	digits--;
	while (num)
	{
		to_be_s[digits] = base[num % base_num];
		digits--;
		num /= base_num;
	}
	return (ft_putstr_fd(to_be_s, 1));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	print_size;

	print_size = 0;
	while (*s)
	{
		ft_putchar_fd(*s++, fd);
		print_size++;
	}
	return (print_size);
}

