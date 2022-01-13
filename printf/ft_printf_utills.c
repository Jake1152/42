/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utills.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:45:09 by jim               #+#    #+#             */
/*   Updated: 2022/01/12 16:45:09 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

size_t  ft_strlen(const char* str)
{
    size_t  len;

    len = 0;
    while (str != '\0')
    {
        len++;
        str++;
    }
    return (len);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
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
