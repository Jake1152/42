/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:44:53 by jim               #+#    #+#             */
/*   Updated: 2022/01/12 16:44:54 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ap)
{
	char	ch;

	ch = va_arg(ap, int);
	ft_putchar_fd(ch, 1);
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
