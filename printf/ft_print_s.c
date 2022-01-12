/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:45:03 by jim               #+#    #+#             */
/*   Updated: 2022/01/12 16:50:13 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putstr(va_list ap)
{
	char	*s;
	int		print_size;

	print_size = 0;
	s = va_arg(ap, char *);
	while (*s)
	{
		write(1, s++, 1);
		print_size++;
	}
	return (print_size);
}
