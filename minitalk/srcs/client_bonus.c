/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:39:30 by jim               #+#    #+#             */
/*   Updated: 2022/03/01 16:29:53 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication_bonus.h"

static t_signal_status	g_signal_status;

void	client_bit_receiver(siginfo_t *sig_info)
{
	if (pid_valider(sig_info->si_pid) == -1)
		error_handler("client pid is wrong.\n");
	if (g_signal_status.sig_send_status == ON && \
		sig_info->si_signo == SIGUSR1)
	{
		g_signal_status.sig_receive_status = ON;
		g_signal_status.sig_send_status = OFF;
	}
}

void	string_sender(pid_t server_pid, char *str)
{
	unsigned int	flag;
	size_t			idx;

	idx = 0;
	while (str[idx])
	{
		flag = 1 << 7;
		while (flag)
		{
			if (str[idx] & flag)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			g_signal_status.sig_send_status = ON;
			pause();
			if (g_signal_status.sig_receive_status == ON)
				g_signal_status.sig_receive_status = OFF;
			else
				error_handler("have not received ACK.\n");
			flag >>= 1;
			usleep(50);
		}
		idx++;
	}
}

void	sa_client_handler(int signo, siginfo_t *sig_info, void *ucontext)
{
	(void)signo;
	(void)ucontext;
	if (sig_info->si_signo == SIGUSR1)
		client_bit_receiver(sig_info);
}

int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	pid_t		client_pid;

	if (argc != 3)
		error_handler("non invalid argument.\n");
	server_pid = atoi(argv[1]);
	if (ft_strncmp(argv[1], "0", 1) != 0 \
			 && server_pid == 0)
		error_handler("non invalid argument.\n");
	if (pid_valider(server_pid) == -1)
		error_handler("Server pid is wrong.\n");
	client_pid = getpid();
	if (pid_valider(client_pid) == -1)
		error_handler("Client pid is wrong.\n");
	sigaction_init(&sa_client_handler);
	string_sender(server_pid, argv[2]);
	exit(0);
	return (0);
}
