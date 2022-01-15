/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:45:11 by jim               #+#    #+#             */
/*   Updated: 2022/01/15 17:50:54 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_upper(va_list ap)
{
	int		num;
	char	*base;

	num = va_arg(ap, int);
	base = "0123456789ABCDEF";
	return (ft_itoa_base(num, 16, base));
}

int	ft_print_hex_lower(va_list ap)
{
	int		num;
	char	*base;

	num = va_arg(ap, int);
	base = "0123456789abcdef";
	return (ft_itoa_base(num, 16, base));
}
