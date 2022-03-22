/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:43:16 by jim               #+#    #+#             */
/*   Updated: 2022/03/22 20:43:17 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	double	power;

	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || \
			*str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	result = 0.0;
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
		str++;
	power = 1.0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		power *= 10.0;
		str++;
	}
	return (sign * result / power);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	printf("argv[2] to atof : %f\n", atof(argv[1]));
	printf("argv[2] to ft_atof : %f\n", ft_atof(argv[1]));
	return (0);
}
