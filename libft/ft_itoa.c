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

char	*ft_itoa(int n)
{
	size_t			digits;
	unsigned char	*to_be_s;
	unsigned char	*tmp_s;
	int				tmp;
	int				sign;

	digits = 0;
	sign = 1;
	tmp = n;
	if (n == 0)
		digits += 1;
	else if (n < 0)
	{
		digits += 1;
		sign = -1;
		tmp *= sign;	
	}	
	while (tmp)
	{
		tmp /= 10;
		digits += 1;
	}
	to_be_s = (unsigned char *)malloc(sizeof(char) * (digits + 1));
	if (!to_be_s)
		return (0);
	while (digits)
	{
		
		digits--;
	}

	return (to_be_s);
}

/* 1152 => "1152" */
/* 
array 이용
재귀?
길이는 어떻게 10의 몇 제곱인지
pointer 이용

음수, 0 처리 
자릿수 문제
25줄 
동적할당을 한번에 하지말고 그때 그떄 한다?

-1152 -> "-1152"

*/