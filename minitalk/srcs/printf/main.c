#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int 	a = 7;
	char	*s = "Hello world.";
	char	c = 'a';
	// long long a = 9223372036854775807LL;
	// int a = -42;
	// int a = -42;s
	// int base_num = 16;

	// printf("%%d: %d\n%%p: %p\n%%x: %x\n", a, &a, a);
	// printf("\n\n");
	// printf("%%d: %d\n%%p: %x\n%%llx: %d\n", a, &a, a);
	printf("return size : %d\n", printf("just string\n"));
	printf("ft return size : %d\n\n", ft_printf("just string\n"));
	printf("return size : %d\n", printf("c : %c\n", c));
	printf("ft return size : %d\n\n", ft_printf("c : %c\n", c));
	printf("return size : %d\n", printf("s : %s\n", s));
	printf("ft return size : %d\n\n", ft_printf("s : %s\n", s));
	printf("return size : %d\n", printf("d : %d\n", a));
	printf("ft return size : %d\n\n", ft_printf("d : %d\n", a));
	printf("return size : %d\n", printf("u : %u\n", a));
	printf("ft return size : %d\n\n", ft_printf("u : %u\n", a));
	printf("return size : %d\n", printf("x : %x\tX : %X\n", a, a));
	printf("ft return size : %d\n\n", ft_printf("x : %x\tX : %X\n", a, a));
	printf("return size : %d\n", printf("p, real: %p\n", &a));
	printf("ft return size : %d\n\n", ft_printf("p, real: %p\n", &a));
	return (0);
}
