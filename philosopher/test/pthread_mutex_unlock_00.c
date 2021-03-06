#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

pthread_mutex_t    mutex;
int	fork[4];
void	*routine(void *thread_number)
{
	int		i;
	int		cnt;

	pthread_mutex_lock(&mutex);
	printf("thread(%d): mutex lock\n", *(int *)thread_number);
	i = 0;
	while (i < 5)
	{
		usleep(1000 * 1000);
		i++;
		printf("thread(%d) : %d초 대기\n", *(int *)thread_number, i);
	}
	printf("thread end\n");
	pthread_mutex_unlock(&mutex);
	printf("thread(%d) : mutex unlock\n", *(int *)thread_number);
	return (thread_number);
}

int		main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	int			number1;
	int			number2;
	void		*ret;

	number1 = 1;
	number2 = 2;
	printf("pthread create\n");
	pthread_create(&thread1, NULL, routine, (void *)&number1);
	pthread_create(&thread2, NULL, routine, (void *)&number2);

	printf("mutex init\n");
	pthread_mutex_init(&mutex, NULL);

	printf("waiting for threads\n");
	pthread_join(thread1, &ret);
	pthread_join(thread2, &ret);

	printf("Mutex destory\n");
	pthread_mutex_destroy(&mutex);

	printf("main end\n");
	return (0);
}
