/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:47:35 by jim               #+#    #+#             */
/*   Updated: 2021/11/03 23:13:58 by jim              ###   ########seoul.kr  */
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
	remain[fd] = ft_strdup("");
	while (1)
	{
		read_str_len = read(fd, read_str, BUFFER_SIZE);
		printf("read str len : %d\n", read_str_len);
		if (read_str_len <= 0)
			break ;
		read_str[read_str_len] = '\0';
		// ft_alloc(read_str_len, remain);
		/*
			문제점
			1. BUFFER_SIZE 안에 읽은 개행이 많은 경우의 처리가 없다.
			2. 동작을 좀더 세분화하여 논리를 짜야한다.
				- 현재는 설계할때 동작 세분화가 덜 되어서 깔끔하게 코드짜기 어렵다.
				- 초기화 동작
				- 개행 붙여주는 과정
				- free

		*/
		new_line_posi = ft_strchr(read_str, '\n');
		if (new_line_posi != NULL)
		{
			new_line_idx = new_line_posi - read_str;
			new_line_str = (char *)malloc(sizeof(char) * (new_line_idx + 1 + 1));
			if (!new_line_str)
				return (NULL);
			ft_strlcpy(new_line_str, read_str, new_line_idx + 1 + 1);
			new_line_str[new_line_idx + 1] = '\n';
			printf("A string untill newline : %s\n", new_line_str);
			
			if (ft_strncmp(remain[fd], "", 1) > 0)
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
			return (joined_str);
		}
		else
		{
			joined_str = ft_strjoin(remain[fd], read_str);
			printf("no newline joined_str : %s\n", joined_str);
			free(remain[fd]);
			remain[fd] = ft_strdup(joined_str);
			printf("no newline remain[fd] : %s\n", remain[fd]);
		}
	}
	if ((ft_strncmp(remain[fd], "", 1) > 0) && read_str_len == 0)
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	while (i++ < n)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
		{
			if (c1 < c2)
				return (-1);
			else
				return (1);
		}
		if (!c1)
			break ;
	}
	return (0);
}
