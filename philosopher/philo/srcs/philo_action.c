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
	if (pthread_mutex_lock(philo_info->status->print) != SUCCESS)
	{
		printf("%s %d\n", __func__, __LINE__);
		return (FALSE);
	}
	if (pthread_mutex_lock(philo_info->left_fork) != SUCCESS)
		return (FALSE);
	printf("%llums %d is taken a fork\n", \
			get_current_ms(*(philo_info->init_time)), \
			philo_info->back_number);
	if (pthread_mutex_lock(philo_info->right_fork) != SUCCESS)
	{
		pthread_mutex_unlock(philo_info->left_fork);
		return (FALSE);
	}
	if (pthread_mutex_unlock(philo_info->status->print) != SUCCESS)
	{
		printf("%s %d\n", __func__, __LINE__);
		return (FALSE);
	}
	return (TRUE);
}

int	eat(t_philo *philo_info)
{
	if (philo_info->philo_status == HUNGRY)
	{
		if (pthread_mutex_lock(philo_info->status->print) != SUCCESS)
		{
			printf("%s %d\n", __func__, __LINE__);
			return (FALSE);
		}
		printf("%llums %d eating\n", get_current_ms(*(philo_info->init_time)),
										philo_info->back_number);
		if (pthread_mutex_unlock(philo_info->status->print) != SUCCESS)
		{
			printf("%s %d\n", __func__, __LINE__);
			return (FALSE);
		}
		pthread_mutex_lock(philo_info->eat_time);
		gettimeofday(&philo_info->last_time, NULL);
		pthread_mutex_unlock(philo_info->eat_time);
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
		*/
		// time 함수 만들어서 usleep을 쪼개서 발생시킬것!
		usleep(philo_info->status->time_to_eat * 1000);
	}
	
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
	if (pthread_mutex_lock(philo_info->status->print) != SUCCESS)
	{
		printf("%s %d\n", __func__, __LINE__);
		return (FALSE);
	}
	printf("%llums %d sleep\n", get_current_ms(*(philo_info->init_time)),
									philo_info->back_number);
	usleep(philo_info->status->time_to_sleep * 1000);
	if (pthread_mutex_unlock(philo_info->status->print) != SUCCESS)
	{
		printf("%s %d\n", __func__, __LINE__);
		return (FALSE);
	}
	return (TRUE);
}

int	think(t_philo *philo_info)
{
	printf("%llums %d think\n", get_current_ms(*(philo_info->init_time)),
									philo_info->back_number);
	return (TRUE);
}
