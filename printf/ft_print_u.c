/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:45:06 by jim               #+#    #+#             */
/*   Updated: 2022/01/15 17:55:48 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(va_list ap)
{
	int		num;
	char	*base;

	num = va_arg(ap, int);
	base = "0123456789";
	return (ft_itoa_base_unsigned(num, 10, base));
}
