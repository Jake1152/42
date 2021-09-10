/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:38:03 by jim               #+#    #+#             */
/*   Updated: 2021/07/08 21:55:45 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digits(int n)
{
	size_t	expo;		

	expo = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			n = 2147483648;
		else
			n *= -1;
		expo++;
	}
	while (n)
	{
		expo++;
		n /= 10;
	}
	return expo
}

char	*ft_itoa(int n)
{
	size_t			digits;
	unsigned char	*to_be_s;

	digits = count_digits(n);
	to_be_s = (unsigned char *)malloc(sizeof(char) * (digits + 1));	
	if (!to_be_s)
		return (0);
	if (n < 0)
	{
		if (n == -2147483648)
			n = 2147483648;
		else
			n = -n;
		to_be_s[0] = '-';
	}
	to_be_s[digits] = '\0';
	digits--;
	while (n)
	{
		to_be_s[digits] = n % 10;
		digits--;
		n /= 10;
	}
	return (to_be_s);
}
