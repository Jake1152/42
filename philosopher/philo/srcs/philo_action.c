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

int	eat(t_philo *philo_info)
{
	if (philo_info->philo_status == HUNGRY)
	{
		printf("%llums %d eating\n", get_current_ms(*(philo_info->init_time)),
										philo_info->back_number);
		usleep(philo_info->status->time_to_eat * 1000);
	}
	return (TRUE);
}

int	philo_sleep(t_philo *philo_info)
{
	printf("%llums %d sleep\n", get_current_ms(*(philo_info->init_time)),
									philo_info->back_number);
	usleep(philo_info->status->time_to_sleep * 1000);
	return (TRUE);
}

int	think(t_philo *philo_info)
{
	printf("%llums %d think\n", get_current_ms(*(philo_info->init_time)),
									philo_info->back_number);
	return (TRUE);
}

int	pickup(t_philo *philo_info)
{
	// printf("philo number : %d\n", philo_info->back_number);
	if (pthread_mutex_lock(philo_info->left_fork) != SUCCESS)
		return (FALSE);
	if (pthread_mutex_lock(philo_info->right_fork) != SUCCESS)
	{
		pthread_mutex_unlock(philo_info->left_fork);
		return (FALSE);
	}
	printf("%llums %d is taken a fork\n", \
									get_current_ms(*(philo_info->init_time)), \
									philo_info->back_number);
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
