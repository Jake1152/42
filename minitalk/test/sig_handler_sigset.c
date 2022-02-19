#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	(*sigset(int sig, void (*disp)(int)))(int);
/*
	- sig: 시그널 핸들러로 처리하려는 시그널
	- disp: 시그널 핸들러의 함수명
	sigset 함수의 인자구조는 signal 함수와 동일하다.
	sigset함수도 첫번째 인자인 sig에 SIGKILL과 SIGSTOP 시그널을 제외한 어떤 시그널도 지정할 수 있다.
	두번쨰 인자인 disp에도  signal함수처럼 시그널 핸들러 함수의 주소나 SIG_IGN, SIG_DFL중 하나를 지정해야한다.
	리턴값은 시그널 핸들러 함수의 주소다
	sigset함수가 실패하면 SIG_ERR을 return한다.

	sigset함수가 signal함수와 다른점은 시그널 핸들러가 한번 호출된 후에 
	기본 동작으로 재설정하지 않고 시그널 핸들러를 자동으로 재지정한다는 것
	따라서 시그널 핸들러를 재지정할 필요가 없다.
*/

void	handler(int signo)
{
	printf("== Signal Handler Signal Number : %d\n\n", signo);
	psignal(signo, "Received Signal");
}

int	main(void)
{
	// sigset을 이용하여 시그널 핸들러를 지정한다.
	// 어떤부분이 시그널 핸들러가 한 번 호출된 후에 재지정하지 않아도 됨을 알 수 있을까?
	if (sigset(SIGINT, handler) == SIG_ERR)
	{
		perror("sigset");
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
