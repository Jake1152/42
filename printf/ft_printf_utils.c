/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:45:09 by jim               #+#    #+#             */
/*   Updated: 2022/01/15 19:15:19 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

static size_t	count_digits(long long n, int base)
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

int	ft_itoa_base(long long num, int base_num, char *base)
{
	size_t			digits;
	char			to_be_s[20];

	if (num == 0)
		return (ft_putstr_fd("0", 1));
	if (base_num != 10 && num < 0)
		num = (unsigned int)num;
	digits = count_digits(num, base_num);
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

int	ft_itoa_base_unsigned(unsigned int num, int base_num, char *base)
{
	size_t			digits;
	char			to_be_s[20];

	if (num == 0)
		return (ft_putstr_fd("0", 1));
	digits = count_digits(num, base_num);
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
