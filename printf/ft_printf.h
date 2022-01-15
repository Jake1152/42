/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:23:13 by jim               #+#    #+#             */
/*   Updated: 2022/01/15 19:15:26 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_specific(va_list ap, const char *format);
/* utils */
size_t	ft_strlen(const char *str);
int		ft_itoa_base(long long num, int base_num, char *base, char format);
int		ft_itoa_base_un(unsigned long num, int base_num, char *base, char format);
// itoa_base, dec, hex, pointer에 쓰일 예정, util에 넣는게 맞는가?
/* specifier */
/* char */
int		ft_print_char(va_list ap);
void	ft_putchar_fd(char c, int fd);
/* string */
int		ft_print_str(va_list ap);
int		ft_putstr_fd(char *s, int fd);
/* signed integer */
// itoa_base( , 10)
/* decimal or integer */
int		ft_print_decimal(va_list ap);
/* unsigned integer */
int		ft_print_unsigned_decimal(va_list ap);
/* hexadecimal */
int		ft_print_hex_upper(va_list ap);
int		ft_print_hex_lower(va_list ap);
/* pointer */
int		ft_print_address(va_list ap);

#endif
