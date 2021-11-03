/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:47:35 by jim               #+#    #+#             */
/*   Updated: 2021/11/03 12:33:35 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 42
#define FD_SIZE 256

char	*get_next_line(int fd)
{
	static char		*remain[FD_SIZE];
	char			read_str[BUFFER_SIZE + 1];
	char			*new_line_str;
	char			*joined_str;
	int				read_str_len;
	size_t			new_line_idx;
	char			*new_line_posi;			

	read_str_len = 0;
	remain[fd] = NULL;
	while (1)
	{
		read_str_len = read(fd, read_str, BUFFER_SIZE);
		printf("read str len : %d\n", read_str_len);
		if (read_str_len <= 0)
			break ;
		read_str[read_str_len] = '\0';
		remain[fd] = ft_strdup("");
		new_line_posi = ft_strchr(read_str, '\n');
		if (new_line_posi != NULL)
		{
			new_line_idx = ft_strchr(read_str, '\n') - read_str;
			new_line_str = (char *)malloc(sizeof(char) * new_line_idx + 1 + 1);
			if (!new_line_str)
				return (NULL);
			ft_strlcpy(new_line_str, read_str, new_line_idx + 1 + 1);
			if (remain[fd] != (void *)0)
			{
				joined_str = ft_strjoin(remain[fd], new_line_str);
				free(remain[fd]);
				remain[fd] = ft_strdup("");
				ft_strlcat(remain[fd], &read_str[new_line_idx + 1], (read_str_len - (new_line_idx + 1)) + 1);
				printf("remain[fd] : %s\n", remain[fd] );
			}			
			else
				joined_str = ft_strdup(new_line_str);
			free(new_line_str);
		}
		else
		{
			joined_str = ft_strjoin(remain[fd], read_str);
			free(remain[fd]);
			remain[fd] = joined_str;
		}
		return (joined_str);
	}
	if (remain[fd] && read_str_len == 0)
		return (remain[fd]);
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx++;
	}
	if (s[idx] == (char)c)
		return ((char *)&s[idx]);
	return (NULL);
}
