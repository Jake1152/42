#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	(*signal(int sig, void (*disp)(int)))(int);
/*
	- sig: 시그널 핸들러로 처리하려는 시그널
	- disp: 시그널 핸들러의 함수명
	첫번째 인자 sig에는 SIGKILL과 SIGSTOP 시그널을 제외한 모든 시그널을 지정할 수 있다.
	
*/

void	handler(int signo)
{
	printf("== Signal Handler Signal Number : %d\n\n", signo);
	psignal(signo, "Received Signal");
}

int	main(void)
{
	void	(*hand)(int);

	hand = signal(SIGINT, handler);
	if (hand == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}
	printf("Wait 1st Ctrl+C... : SIGINT\n");
	pause();
	printf("After 1st Signal Handler\n");
	printf("Wait 2nd Ctrl+C... : SIGINT\n");
	pause();
	printf("After 2nd Signal Handler\n");
	return (0);
}
