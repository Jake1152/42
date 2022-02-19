/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:39:30 by jim               #+#    #+#             */
/*   Updated: 2022/02/19 21:40:17 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"

int	client(void)
{
	return (0);
}

int	main(int argc, char *argv[])
{
	long long	received_sig;
	int			pid;

	if (argc != 3)
		print_error();
	pid = ft_atoi(argv[1]);
	if (ft_strncmp(argv[1], "0", 1) != 0 && pid == 0)
		print_error();
	kill(pid, SIGUSR1);
	argv[2];
}
