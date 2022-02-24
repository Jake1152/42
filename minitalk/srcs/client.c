/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:39:30 by jim               #+#    #+#             */
/*   Updated: 2022/02/23 11:55:35 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"
t_signal_status	g_signal_status;

void	client_bit_receiver(siginfo_t *sig_info)
{
	// signal을 이전에 보냈는지 정보도 알아야한다.
	/* ACK Received*/
	if (g_signal_status.sig_send_status == ON && \
		sig_info->si_signo == SIGUSR1)
	{
		if (client_bit_sender(sig_info) == -1)
			error_handler("client side bit_sender Error.");
		g_signal_status.sig_send_status = OFF;
	}
}

int string_sender(pid_t server_pid, char *str)
{
	unsigned int	flag;
	size_t			idx;

	idx = 0;
	while (str[idx])
	{
		printf("char : %c\n", str[idx]);
		printf("char in dec : %d\n", str[idx]);
		flag = 1 << 7;
		while (flag)
		{
			printf("str[idx] & flag : %d\n", str[idx] & flag);
			if (str[idx] & flag)
				kill(server_pid, SIGUSR1);
			else//SIGUSR2 받을때 0이라서 처리를 안하니까 안보낸다? 그래도 가독성과 명시성을 위해 적는게 나을까?
				kill(server_pid, SIGUSR2);
			g_signal_status.sig_send_status = ON;
			pause(); // ACK받기 위함, NULL에 대한 ACK도 받아야.
			// ACK를 어떻게 인지할것인가?
			// inturrupt온게 SIGUSR1이라는걸 알아야한다.
			// sa_sigaction에 할당한 함수에서 알아채서 그 다음에
			// ACK가 맞으면 다음 문자를 전송해야한다.
			// 문자를 다 보냈으면 NULL을 받고 출력해야한다.
			// 이부분에서 전역변수가 필요한가?
			// 현재까지 출력한 곳의 idx면 되는가?
			// ACK를 받기위해 pause하므로 usleep은 필요없다.
			if (g_signal_status.sig_receive_status == ON)
				g_signal_status.sig_receive_status = OFF;
			else
				error_handler("have not received ACK.");
			flag >>= 1;
		}
		idx++;
	}
}

void	sa_client_handler(siginfo_t *sig_info, void *ucontext)
{
	(void)ucontext;
	client_bit_receiver(sig_info);
}

int main(int argc, char *argv[])
{
	struct sigaction	sa;
	pid_t				server_pid;
	pid_t				client_pid;

	if (argc != 2)
		error_handler("non invalid argument.");
	server_pid = atoi(argv[1]);
	if (ft_strncmp(argv[1], "0", 1) != 0 \
			 && server_pid == 0)
		error_handler("non invalid argument.");
	if (pid_valider(server_pid) == -1)
		error_handler("Server pid is wrong.");
	client_pid = getpid();
	if (pid_valider(client_pid) == -1)
		error_handler("Client pid is wrong.");
	printf("Client pid is %d\n", client_pid); // ft_printf로 변환할것!
	sigaction_init(&sa_client_handler);
	string_sender(server_pid, argv[2]);
	return (0);
}
