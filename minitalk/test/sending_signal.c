#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>

void	(*signal(int sig, void (*disp)(int)))(int);
/*
	- sig: 시그널 핸들러로 처리하려는 시그널
	- disp: 시그널 핸들러의 함수명
	첫번째 인자 sig에는 SIGKILL과 SIGSTOP 시그널을 제외한 모든 시그널을 지정할 수 있다.

*/

int	main(void)
{
	printf("Before SIGCONT Signal to parent.\n");
	kill(getppid(), SIGCONT);
	printf("Before SIGQUIT Signal to me.\n");
	kill(getpid(), SIGQUIT);
	printf("After SIGQUIT Signal.\n");
	return (0);
}
