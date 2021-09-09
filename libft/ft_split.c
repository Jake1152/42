/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:37:51 by jim               #+#    #+#             */
/*   Updated: 2021/09/09 16:16:51 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_cnt(char const *s, char c)
{
	size_t	word_cnt;

	word_cnt = 0;
	while (ft_strchr(s, c))
		word_cnt++;
	return (word_cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**word_list;
	char	*begin_of_str;
	size_t	word_cnt;

	word_cnt = ft_word_cnt(s, c);
	word_list = (char **)malloc(sizeof(char) * (word_cnt + 2));
	if (word_list == 0)
		return (0);
	begin_of_str = &s[0];
	while (s)
	{
		if (s == c)
		{
			*word_list = *ft_substr(word_cnt, 0, (s - begin_of_str));
			if (*word_list == 0)
				return (0);
			word_list++;
			begin_of_str = (s + (sizeof(s) * 1));
		}
		s++;
	}
	word_list = 0;
	return (word_list);
}
