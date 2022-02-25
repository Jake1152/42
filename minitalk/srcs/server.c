/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:39:33 by jim               #+#    #+#             */
/*   Updated: 2022/02/25 19:23:48 by jake             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"

int	server_bit_sender(pid_t client_pid, int send_flag)
{
	/* ACK send */
	if (send_flag == 1)
		return (kill(client_pid, SIGUSR1));
}

void	server_bit_receiver(siginfo_t *sig_info)
{
	static unsigned char	bit_receiver = 0;
	static unsigned char	bit_flag = 1 << 7;
	static pid_t			pid_flag = 0;

	if (sig_info->si_signo == SIGUSR1)
		bit_receiver |=  bit_flag;
	else if (sig_info->si_signo == SIGUSR2)
		;
	bit_flag >>= 1;
	usleep(160);
	/* ACK send */
	if (server_bit_sender(sig_info->si_pid, 1) == -1)
		error_handler("bit_sender Error.\n");
	if (bit_flag == 0)
	{
		write(1, &bit_receiver, 1);
		bit_receiver = 0;
		bit_flag = 1 << 7;
	}
}

void	sa_server_handler(int signo, siginfo_t *sig_info, void *ucontext)
{
	if (sig_info->si_signo == SIGUSR1 || sig_info->si_signo == SIGUSR2)
		server_bit_receiver(sig_info);
}

int	main()
{
	pid_t		server_pid;

	server_pid = getpid();
	if (pid_valider(server_pid) == -1)
		error_handler("Server pid is wrong.\n");
	sigaction_init(&sa_server_handler);
	ft_putstr_fd("Server launched, pid is ", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putstr_fd("\n", 1);
	while (42)
		;
	return (0);
}
