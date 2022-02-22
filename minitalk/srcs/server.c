/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:39:33 by jim               #+#    #+#             */
/*   Updated: 2022/02/19 21:30:36 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"

void sa_server_handler(int signo, siginfo_t *sig_info, void *ucontext)
{
	(void)ucontext;
	sig_info->
	/*
		client로부터 넘겨받은 sig에 따라 비트를 만든다(SIGUSR1,2)
		다받으면 (0000 0000) ACK로 0000 0000을 보낸다.
		sig_info에 대한 추가 이해 및 예제 필요.
	*/
	char	*sig_char;

}

int	main(int argc, char *argv[])
{
	t_sigaction	sa;
	long long	received_sig;
	pid_t		server_pid;
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
	(int)argc;
	(char *)argv[0];
	server_pid = getpid();
	sa.sa_sigaction = &sa_server_handler;
	sa.sa_flags = SA_SIGINFO;
	// need to recode
	sigemptyset(&sa.sa_mask);
	// Interrupt도 설정해줘야하는가?
	// 전역변수는 언제 써줘야하는가?
	// error 처리 필수!!!!!!!!!!!
	// return 값에 대한 처리 필요
	// log를 남기는게 낫지만 그럴 수 없다.
	// 다른 에러라는걸 어떻게 표현할것인가?
	// error에 문구를 찍고서 exit한다.
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaciton(SIGUSR1, &sa, NULL);
	sigaciton(SIGUSR2, &sa, NULL);
	printf("Server launched, pid is %d\n", server_pid); // ft_printf로 변환할것!
	while (42)
		sleep(1);// usleep test
	return (0);
}
