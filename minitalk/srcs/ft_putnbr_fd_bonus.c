/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:36:24 by jim               #+#    #+#             */
/*   Updated: 2022/02/26 19:06:03 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication_bonus.h"

static void	ft_loop(int n, int fd)
{
	char	ch[11];
	int		index;

	index = 0;
	while (n >= 10)
	{
		ch[index] = n % 10;
		n /= 10;
		index++;
	}
	ft_putchar_fd(n + '0', fd);
	while (index > 0)
	{
		ft_putchar_fd(ch[index - 1] + '0', fd);
		index--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	ft_loop(n, fd);
}
