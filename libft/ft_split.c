/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:37:51 by jim               #+#    #+#             */
/*   Updated: 2021/09/13 21:37:34 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_cnt(char const *s, char c)
{
	size_t	word_cnt;
	size_t	idx;

	word_cnt = 0;
	idx = 0;
	while (s[idx])
	{
		if (s[idx] == c)
			idx++;
		else
		{
			word_cnt++;
			while (s[idx] && s[idx] != c)
				idx++;
		}
	}
	return (word_cnt);
}

void	ft_alloc_word(char const *s, char c, char **word_list)
{
	size_t	idx;
	size_t	word_idx;
	size_t	begin_of_word;	

	idx = 0;
	word_idx = 0;
	while (s[idx])
	{
		if (s[idx] == c)
			idx++;
		else
		{
			begin_of_word = idx;
			while (s[idx] && s[idx] != c)
				idx++;
			word_list[word_idx] = \
			ft_substr(s, begin_of_word, (idx - begin_of_word));
			word_idx++;
		}
	}
	word_list[word_idx] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**word_list;
	size_t	word_cnt;

	word_cnt = ft_word_cnt(s, c);
	if (word_cnt == 0)
		return (0);
	word_list = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (word_list == 0)
		return (0);
	ft_alloc_word(s, c, word_list);
	return (word_list);
}
