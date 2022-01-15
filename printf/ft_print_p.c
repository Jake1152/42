/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:45:00 by jim               #+#    #+#             */
/*   Updated: 2022/01/15 19:14:14 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_address(va_list ap)
{
	int		num;
	char	*base;
	int		print_size;

	print_size = 0;
	num = va_arg(ap, int);
	base = "0123456789abcdef";
	print_size += ft_putstr_fd("0x", 1);
	print_size += ft_itoa_base_unsigned(num, 16, base, 'p');
	return (print_size);
}
