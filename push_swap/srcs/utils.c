/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:10:59 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 12:43:48 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr(char *s)
{
	size_t	str_len;

	str_len = ft_strlen(s);
	write(1, s, str_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

int	ft_atoi(const char *str,int	*atoi_flag)
{
	int			sign;
	long long	result;

	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result = result * sign;
	if (*str || result > 2147483647 || result < -2147483648)
	{
		*atoi_flag = -1;
		return (0);
	}
	return ((int)result);
}
