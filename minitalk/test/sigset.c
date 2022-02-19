#include <signal.h>

/*
sigemptyset
sigfillset
sigaddset
sigdelset
sigsmember


int sigemptyset(sigset_t *set);
- set: 비우려는 시그널 집합의 주소

int sigfillset(sigset_t *set);
- 설정하려는 시그널 집합의 주소

int sigaddset(sigset_t *set, int signo);
- set: 시그널을 추가하려는 시그널 집합의 주소
- signo: 시그널 집합에 추갛로 설정하려는 시그널

typedef struct
{
    unsigned int __sigbits[4];
} sigset_t;



*/
