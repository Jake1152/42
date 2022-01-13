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
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	print_specific(va_list ap, const char *format);

/* utils */
size_t  ft_strlen(const char* str);
int     ft_toupper(int c);
int		ft_itoa_base(long long num, int base_num);
// itoa_base, dec, hex, pointer에 쓰일 예정, util에 넣는게 맞는가?
/* specifier */
/* char */
int		ft_print_char(va_list ap);
void	ft_putchar_fd(char c, int fd);
/* string */
int	ft_print_str(va_list ap);
int	ft_putstr_fd(char *s, int fd);
/* signed integer */
// itoa_base( , 10)
/* decimal or integer */
int	ft_print_decimal(va_list ap);
/* unsigned integer */
ft_print_unsigned_decimal(ap);
/* hexadecimal */
ft_print_hex_upper(ap);
ft_print_hex_lower(ap);
/* pointer */
ft_print_address(ap);

#endif