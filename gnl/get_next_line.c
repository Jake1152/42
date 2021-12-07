/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:47:35 by jim               #+#    #+#             */
/*   Updated: 2021/12/07 12:42:02 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 42
#define FD_SIZE 256

char	*get_next_line(int fd)
{
	static char		*static_save[FD_SIZE];
	char			read_str[BUFFER_SIZE + 1];
	char			*new_line_str;
	char			*joined_str;
	char			*tmp;
	int				read_str_len;
	size_t			new_line_size;
	char			*new_line_posi;

	read_str_len = 0;
	static_save[fd] = ft_strdup("");  // 꼭 동적 할당해야하는가?
	while (1)
	{
		// 읽음 그리고 저장, 읽고 남은건 return
		read_str_len = read(fd, read_str, BUFFER_SIZE);
		printf("read str len : %d\n", read_str_len);
		if (read_str_len <= 0 && static_save[fd] == "")
			break ;
		// static 마지막에 \0을 넣어줘야한다.
		// 다음 문자열이 들어오면 이전 \0부분을 덮어쓰고
		// 다시 맨뒤에 \0을 넣어줘야한다.
		read_str[read_str_len] = '\0';
		// static에 읽은 것을 다 저장한다.
		tmp = ft_strjoin(static_save[fd], read_str);
		free(static_save[fd]);
		static_save[fd] = tmp;
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
		new_line_posi = ft_strchr(static_save[fd], '\n');
		if (new_line_posi != NULL)
		{
			new_line_size = new_line_posi - static_save[fd];
			new_line_str = ft_alloc(new_line_size + 1);
			ft_strlcpy(new_line_str, static_save[fd], new_line_size + 1);
			// static에 첫번쨰 개행 이후에 데이터를 다시 저장해야한다.
			// 첫번째 개행 이후 데이터가 없다면?

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
	// 어떤 케이스? 마지막 케이스
	if ((ft_strncmp(remain[fd], "", 1) > 0) && read_str_len == 0)
		return (remain[fd]);
	return (NULL);
}


char	*ft_alloc(int size)
{
	char	*ret_str;

	ret_str = (char *)malloc(sizeof(char) * (size));
	if (ret_str == NULL)
		return (NULL);
	return (ret_str);
}

char	*ft_join_realloc(char *s1, char *s2)
{
	
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
