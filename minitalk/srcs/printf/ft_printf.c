/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:44:45 by jim               #+#    #+#             */
/*   Updated: 2022/01/15 18:38:45 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		return_size;
	va_list	ap;

	return_size = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			return_size += print_specific(ap, format);
		}
		else
		{
			write(1, format, 1);
			return_size++;
		}
		format++;
	}
	va_end(ap);
	return (return_size);
}

int	print_specific(va_list ap, const char *format)
{
	int	char_size;

	char_size = 0;
	if (*format == 'c')
		char_size = ft_print_char(ap);
	else if (*format == 's')
		char_size = ft_print_str(ap);
	else if (*format == 'd' || *format == 'i')
		char_size = ft_print_decimal(ap);
	else if (*format == 'u')
		char_size = ft_print_unsigned_decimal(ap);
	else if (*format == 'p')
		char_size = ft_print_address(ap);
	else if (*format == 'x')
		char_size = ft_print_hex_lower(ap);
	else if (*format == 'X')
		char_size = ft_print_hex_upper(ap);
	else if (*format == '%')
	{
		ft_putstr_fd("%", 1);
		char_size++;
	}
	return (char_size);
}
