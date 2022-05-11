#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void	*t_function(void *data)
{
	pid_t		pid;
	pthread_t	tid;
	char		*thread_name;
	int			i;

	pid = getpid();
	tid = pthread_self();
	thread_name = (char *)data;
	i = 0;
	while (i < 3)
	{
		printf("[%s] pid: %u, tid: %x --- %d\n",
				thread_name, (unsigned int)pid, (unsigned int)tid, i);
		i++;
		sleep(1);
	}
}

int	main()
{
	pthread_t	p_thread[2];
	int			thr_id;
	int			*status;
	char		p1[] = "thread_1";
	char		p2[] = "thread_2";
	char		pM[] = "thread_m";

	sleep(1);
	// 1번 thread 생성
	// t_function의 매개변수 p1으로 넘김
	thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)p1);
	// pthread_create()으로 성공적으로 thread가 생성되면 0을 return
	if (thr_id < 0)
	{
		perror("thread create error : \n");
		exit(EXIT_SUCCESS);
	}
	// 2번 thread 생성
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)p2);
	t_function((void *)pM);
	pthread_join(p_thread[0], &status);
	pthread_join(p_thread[1], &status);
	printf("when will be end?\n");
	return (0);
}
