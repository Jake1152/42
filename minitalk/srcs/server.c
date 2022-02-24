/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:39:33 by jim               #+#    #+#             */
/*   Updated: 2022/02/23 15:15:25 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"

int	server_bit_sender(pid_t client_pid, int send_flag)
{
	// printf("client pid : %d\n", client_pid);
	/* ACK */
	if (send_flag == 1)
		return (kill(client_pid, SIGUSR1));
}

void	server_bit_receiver(siginfo_t *sig_info)
{
	static unsigned char	bit_receiver = 0;
	static unsigned char	bit_flag = 1 << 7;

	// printf("current bit flag is : %d\n", bit_flag);
	// printf("sig_info->si_signo is : %d\n", sig_info->si_signo);
	if (sig_info->si_signo == SIGUSR1)
	{
		//printf("receive USR1\n");
		bit_receiver |=  bit_flag;
	}
	//else if (sig_info->si_signo == SIGUSR2)
	//{
		//printf("receive USR2\n");
	//	;
	//}
	// printf("current bit_receiver is : %d\n", bit_receiver);
	bit_flag >>= 1;
	/* ACK send */
	if (server_bit_sender(sig_info->si_pid, 1) == -1)
		error_handler("bit_sender Error.");
	if (bit_flag == 0)
	{
		write(1, &bit_receiver, 1);
		bit_receiver = 0;
		bit_flag = 1 << 7;
	}
}
void	sa_server_handler(int signo, siginfo_t *sig_info, void *ucontext)
{
	static pid_t	pid_flag = 0;

	(void)ucontext;
	if (sig_info->si_pid != pid_flag)
	{
		printf("Client Pid %d : ", sig_info->si_pid);
		pid_flag = sig_info->si_pid;
	}
	// signal catch했을때와 보내야할때를 구분해야한다.
	// 다시 생각해보니 구분할 수 없다.
	// 지금 받는 신호가 몇번쨰인지 어떻게 알것인가?
	// pid를 이용
	server_bit_receiver(sig_info);
}

// int	main(int argc, char *argv[])
int	main()
{
	pid_t		server_pid;

	// (int)argc;
	// (char *)argv[0];
	server_pid = getpid();
	if (pid_valider(server_pid) == -1)
		error_handler("Server pid is wrong.");
	sigaction_init(&sa_server_handler);
	//sigaction_init(sa);
	printf("Server launched, pid is %d\n", server_pid); // ft_printf로 변환할것!
	while (42)
		;
	return (0);
}

/*
	TODO
	- server는 ctrl+c가 있기 전까지는 계속 떠있어야한다.
	- client로부터 PID와 메시지를 받는다.
	- 동시에 client로부터 입력 및 신뢰성있는 처리를 하는지 모른다.
		아마 이 과제에서는 그렇게까지는 안하는것 같다.
		signal 내부적으로 동시접속 및 신뢰성있게 처리해줄 수 있을 거 같다.
	Progress
	- Server run
	- Server waiting to connect from some client
	- PID, message(signal?) receive
	Curious
	- Unicode 2~4byte라는데 ASCII와 구분을 어떻게하는가?
	- write함수에서 알수 있는 방법이 있는가?
	// 인자가 몇개 있던지 정보가 중요한가?
	// 못넣게 했는데 실수로 넣으면 문제가 되니까
	// 인자를 넣어줄수 있게는 하는게 나은가?
	client로부터 받은건 어떻게 캐치할 수 있는가?
*/
/*
	## sa_server_handler(int signo, siginfo_t *sig_info, void *ucontext)
	client로부터 넘겨받은 sig에 따라 비트를 만든다(SIGUSR1,2)
	다받으면 (0000 0000) ACK로 0000 0000을 보낸다.
	sig_info에 대한 추가 이해 및 예제 필요.
	1개 글자마다 찍는다.
	- bit receiveer() 호출
		- 받은 비트 문자로 변환하여 write함수 호출
		- 받을때 소요시간 발생하므로 1비트 받을때마다 일정시간 동안 usleep
		- 이전에 받은 내용 기억해야하므로  static 필요
		- unicode일떄 처리 추가로 필요 왜냐하면 1바이트마다 출력할것이라서!
	- handler할떄마다 해야하는가?
		- 보낼때는 usleep하지 않는다?
		- 받은쪽에서 처리하고서 usleep
		- 받고 처리했다는걸 어떻게 알수 있는가
		- interrupt걸리고 sleep하면 그냥 일시정지 아닌가?
		- 보내는 쪽에서 보내고서 usleep한다.
		이유는 받는 쪽에서 언제 받았는지 받은 것을 처리하고 쉴시간이  필요한지 알기 어렵고
		알수있는지도 모르겠으며
		목적은 받는쪽에서 처리하기전에 새로운  signal이 들어와서 순서가 어긋나거나 문제되는것을 막기 위함이므로
		보내는 쪽에서 signal을 보내고서 일정시간 usleep을 한다.
*/
