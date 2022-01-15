/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:45:03 by jim               #+#    #+#             */
/*   Updated: 2022/01/15 18:56:23 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == (void *)0)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(s, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	print_size;

	print_size = 0;
	while (*s)
	{
		ft_putchar_fd(*s++, fd);
		print_size++;
	}
	return (print_size);
}
