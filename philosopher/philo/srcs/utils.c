/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:44:13 by jim               #+#    #+#             */
/*   Updated: 2022/04/21 16:44:13 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_nonnegative(const char *str)
{
	long long	result;

	if (*str == '\0')
		return (-1);
	while (*str == '\t' || *str == '\n' || \
	*str == '\v' || *str == '\f' || \
	*str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		return (-1);
	if (*str == '\0')
		return (-1);
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str || result > 2147483647)
		return (-1);
	return ((int)result);
}
