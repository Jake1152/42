/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:10:59 by jim               #+#    #+#             */
/*   Updated: 2022/02/25 18:08:18 by jake             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	str_len;

	if (s == NULL)
	{
		ft_putstr_fd("There are no string.\n", 2);
		return ;
	}
	str_len = ft_strlen(s);
	write(fd, s, str_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	while (*str == '\t' || *str == '\n' || \
	*str == '\v' || *str == '\f' || \
	*str == '\r' || *str == ' ')
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
	if (*str)
		return (0);
	return ((int)result * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	while (i++ < n)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
		{
			if (c1 < c2)
				return (-1);
			else
				return (1);
		}
		if (!c1)
			break ;
	}
	return (0);
}

