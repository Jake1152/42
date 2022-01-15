/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:44:58 by jim               #+#    #+#             */
/*   Updated: 2022/01/15 17:49:59 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(va_list ap)
{
	int		num;
	char	*base;

	num = va_arg(ap, int);
	base = "0123456789";
	if (num == -2147483648)
		return (ft_putstr_fd("-2147483648", 1));
	return (ft_itoa_base(num, 10, base));
}
