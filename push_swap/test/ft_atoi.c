/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:37:45 by jim               #+#    #+#             */
/*   Updated: 2022/03/31 11:34:37 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	return ((int)result * sign);
}

int	main(int argc, char *argv[])
{
	int	idx;

	idx = 1;
	while (argc > idx)
	{
		printf("argv str is %s\n", argv[idx]);
		printf("argv atoi is %d\n", atoi(argv[idx]));
		printf("argv ft_atoi is %d\n", ft_atoi(argv[idx]));
		idx++;
	}
}
