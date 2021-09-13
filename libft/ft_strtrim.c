/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:37:51 by jim               #+#    #+#             */
/*   Updated: 2021/09/13 15:29:38 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_front_idx(char const *s1, char const *set)
{
	size_t	cnt;

	cnt = 0;
	while (s1[cnt])
	{
		if (ft_strchr(set, s1[cnt]) == 0)
			break ;
		cnt++;
	}
	return (cnt);
}

size_t	get_rear_idx(char const *s1, char const *set)
{
	size_t	cnt;
	size_t	s_len;

	cnt = 0;
	s_len = ft_strlen(s1);
	while (s_len > cnt)
	{
		if (ft_strchr(set, s1[s_len - cnt - 1]) == 0)
			break ;
		cnt++;
	}
	return (s_len - cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*to_be;	
	size_t	set_len;
	size_t	front_idx;
	size_t	rear_idx;
	size_t	to_be_size;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	set_len = ft_strlen(set);
	front_idx = get_front_idx(s1, set);
	rear_idx = get_rear_idx(s1, set);
	to_be_size = 0;
	if (rear_idx >= front_idx)
		to_be_size = (rear_idx - front_idx);
	if (to_be_size == 0)
		return (ft_strdup(""));
	to_be = (char *)malloc(sizeof(char) * (to_be_size + 1));
	if (!to_be)
		return (0);
	ft_strlcpy(to_be, (s1 + front_idx), to_be_size + 1);
	return (to_be);
}
