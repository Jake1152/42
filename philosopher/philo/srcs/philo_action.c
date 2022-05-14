/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:20:37 by jim               #+#    #+#             */
/*   Updated: 2022/05/10 20:51:25 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_struct.h"
#include <stdio.h>
#include <unistd.h>

int	pickup(t_philo *philo_info)
{
	pthread_mutex_lock(&philo_info->thread);
	if (philo_info->status->progress_flag == FALSE)
	{
		pthread_mutex_lock(&philo_info->thread);
		return (FALSE);
	}
	if (pthread_mutex_lock(philo_info->left_fork) != SUCCESS)
		return (FALSE);
	print_status(philo_info, HUNGRY);
	if (pthread_mutex_lock(philo_info->right_fork) != SUCCESS)
	{
		pthread_mutex_unlock(philo_info->left_fork);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo_info->thread);
	return (TRUE);
}

int	eat(t_philo *philo_info)
{
	pthread_mutex_lock(&philo_info->thread);
	if (philo_info->status->progress_flag == FALSE)
	{
		pthread_mutex_lock(&philo_info->thread);
		return (FALSE);
	}
	print_status(philo_info, EATING);
	gettimeofday(&philo_info->last_eat_time, NULL);
	usleep(philo_info->status->time_to_eat * 1000);
	pthread_mutex_unlock(&philo_info->thread);
	/*
		eat_time이 맞는가?
		생각해보면 죽었는지, 식사 다해서 종료해야하는지 확인할때 필요하다.
		그럴 것이라면 좀더 포괄적인 이름이 필요하다.
		스레드별로 있는 뮤텍스라서 효율성이 떨어질 일은 없는가?
		스레드와 print 뮤텍스는 개별이다.
		시간 함수에서 지체되는 부분을 줄인다.
		재밌는건 usleep을 나눠서 여러번 하는게 더 적게 걸린다.
		오차를 줄일 수 있어서라고 하는데
		cpu에 할당되는 시간이 있어서 더 걸리는 것인데
		왜 usleep을 쪼개서 자주 호출하는게 이득인가?
		구체적으로 왜 그런가?
		progress_flag에 대해 거는 mutex인데
		thread별로 거는게 맞는가?
		thread mutex로 각 동작할때마다 임계영역으로 만들고

		progress_flag가 임계구역일때
		모니터에서 progress_flag를 막고

		thread마다 lock을 거는 이유는 무엇인가?
		그 이유는 전체가 1개의 lock을 가질 필요가 없다고 생각해서이다.
		전체가 1개의 락을 가져야한다면(print lock제외)
		1명이 1개의 동작을 끝내야만 다음 동작을 하므로 지연될 수 밖에 없다.
		그런데

		시간을 확인할때만 철학자마다 가지는 lock을 쓴다.
		시간 확인은 철학자마다니까 타당
		- 시뮬레이션이 끝났다면
			다른 철학자들이 동작을 안하고 루틴에서 빠져나온다.
			빠져 나오게할려고 한다면
			그러면 모두가 flag를 확인해야한다.
			해당 flag에 대해서 확인하게하고

		철학자별로 시간을 확인하는 영역을 막는다.
		그런데 죽었을때 flag를 바꾸는 mutex는 다른 것이다
		그렇게 되면 제대로 상호배제가 되는가?

		시간에 대한 락을 개별로 처리하고
		모니터에서 시간에 대한 락을 걸고 확인하면 된다.

		임계코드를 가급적 줄여야한다.
		- 동작을 안하게할려면 복잡해진다.
		- 시뮬레이션에서 시간을 확인하고
			해당 flag값을 바꾼다
			그런데 flag에 대한 lock 개별이다.
			그러면 허점이 있지 않는가?
		- 임계영역이 커지면
	*/
	// time 함수 만들어서 usleep을 쪼개서 발생시킬것!

	return (TRUE);
}

int	putdown(t_philo *philo_info)
{
	if (pthread_mutex_unlock(philo_info->left_fork) != SUCCESS
		|| pthread_mutex_unlock(philo_info->right_fork) != SUCCESS)
	{
		printf("%s %d\n", __func__, __LINE__);
		return (FALSE);
	}
	return (TRUE);
}

int	philo_sleep(t_philo *philo_info)
{
	print_status(philo_info, SLEEPING);
	usleep(philo_info->status->time_to_sleep * 1000);
	return (TRUE);
}

int	think(t_philo *philo_info)
{
	print_status(philo_info, THINKG);
	return (TRUE);
}
