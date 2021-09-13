/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:37:51 by jim               #+#    #+#             */
/*   Updated: 2021/09/13 17:18:19 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_cnt(char const *s, char c)
{
	size_t	word_cnt;

	word_cnt = 0;
	while (s)
	{
		if (ft_strchr(s, c) != 0)
			word_cnt++;
		s++;
	}
		
	return (word_cnt);
}

void	ft_alloc_str(char *word_list, char const *s, char *begin_of_str)
{
	word_list = ft_substr(s, begin_of_str, (s - begin_of_str));
	if (*word_list == 0)
		return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**word_list;
	char	*begin_of_str;
	size_t	word_cnt;

	word_cnt = ft_word_cnt(s, c);
	if (word_cnt == 0)
		return (0);
	word_list = (char **)malloc(sizeof(char) * (word_cnt + 2));
	if (word_list == 0)
		return (0);
	begin_of_str = &s[0];
	while (s)
	{
		if (*s == c)
		{
			ft_alloc_str(*word_list, s, begin_of_str);
			word_list++;
			begin_of_str = (s + (sizeof(s) * 1));
		}
		s++;
	}
	ft_alloc_str(*word_list, s, begin_of_str);
	word_list = 0;
	return (word_list);
}
