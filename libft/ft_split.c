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

char	**ft_split(char const *s, char c)
{
	char	**word_list;
	size_t	word_cnt;

	word_cnt = 0;
	while (ft_strchr(s, c))
		word_cnt++;
	word_list = (char **)malloc(sizeof(char) * (word_cnt + 2));
	if (word_list == 0)
		return (0);
	word_cnt = &s[0]; 
	s = &s[0];
	while (s)
	{
		if (s == c)
		{
			*word_list = *ft_substr(*(word_cnt), 0, (s - word_cnt));
			if (*word_list == 0)
				return (0);
			word_list++;
			word_cnt = &(s + (sizeof(s) * 1));
		}
		s++;
	}
	word_list = 0;
	return (word_list);
}
