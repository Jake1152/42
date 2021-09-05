/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:37:51 by jim               #+#    #+#             */
/*   Updated: 2021/07/08 21:40:23 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	*to_be;	
	size_t			set_len;

	set_len = ft_strlen(set);
	while (s1)
	{
		if ((*s1 == set[0]) && !(ft_strncmp(s1, set, set_len)))
			s1 += sizeof(char) * set_len;
		else
			*to_be++ = *s1++;
	}
	return (to_be);
}

/*
trim
다듬기
set이 있는 부분은 시킵
그 이외에 문자들만으로 이루어진 문자열을 반환
strnstr을 이용
strncmp

hello world
o
*/
