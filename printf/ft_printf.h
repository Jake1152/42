/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:23:13 by jim               #+#    #+#             */
/*   Updated: 2022/01/12 16:50:36 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_specific(va_list ap, char *format);

/* specifier */
/* char */
int	ft_putchar(va_list ap);
/* string */
int	ft_putstr(va_list ap);
/* string */
int	ft_putstr(va_list ap);
#endif