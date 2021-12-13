/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:32:31 by jim               #+#    #+#             */
/*   Updated: 2021/12/13 14:29:00 by jake             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_SIZE 256
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>

// it must be removed
#include <stdio.h>

/* orign */
char	*get_next_line(int fd);
char	*get_next_line_from_save(char **save, int newline_idx);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
/* util */
size_t	ft_strlen(char *s);
char	*ft_strjoin(char **s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
int		ft_strchr(char *s, int c);

#endif
