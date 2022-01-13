/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:44:45 by jim               #+#    #+#             */
/*   Updated: 2022/01/12 16:53:02 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // should be removed

/*
		0. specifier or just string 
		   printf("hello \nwolrd, %s hi?, nice to meet you? \n\n Hi my name is %s I'm in %d\n\n", name1, name2, num);
		1.  just string
			write function or putchar
			putchar 써도 되는지 확인 필요
		2. specifier
			%기호가 나오면 시작
		
		- 필요한 것 
		format에는 "adgdsfgdf %d %%\n\n" 같은 것만 나오는가?
		ap는 어떻게 처리하는가?
		printf("%d %d %d", num1, num2, num3);w
		즉 arguments들을 va_ function들을 사용하여 처리하여야하는데 어떻게 하는가?
		null일때 처리 필요
		(null)
*/
int main()
{
	ft_printf("test\nsentence\n");
	ft_printf("the char is : %c, other one is : %c\n", 'a', 'b');
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		return_size;
	char	ret_c;
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

	format++;
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
		write(1, '%', 1);
		char_size++;
	}
	return (char_size);
}
