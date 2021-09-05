/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:37:43 by jim               #+#    #+#             */
/*   Updated: 2021/07/05 18:53:14 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	un_s1 = (unsigned char)s1;
	un_s2 = (unsigned char)s2;
	while (n--)
	{
		if (*un_s1 != *un_s2)
			return (*un_s1 - *un_s2);
		if (!*un_s1)
			break ;
		un_s1++;
		un_s2++;		
	}
	if (n != 0)
		return (-1);
	return (0);
}
