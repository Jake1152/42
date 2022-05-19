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
#include <unistd.h>
#include <pthread.h>

int	pickup(t_philo *philo_info)
{
	pthread_mutex_lock(&philo_info->status->progress);
	if (philo_info->status->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&philo_info->status->progress);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo_info->status->progress);
	pthread_mutex_lock(philo_info->left_fork);
	print_status(philo_info, HUNGRY);
	pthread_mutex_lock(philo_info->right_fork);
	return (TRUE);
}

int	eat(t_philo *philo_info)
{
	pthread_mutex_lock(&philo_info->status->progress);
	if (philo_info->status->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&philo_info->status->progress);
		putdown(philo_info);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo_info->status->progress);
	pthread_mutex_lock(&philo_info->mealtime);
	gettimeofday(&philo_info->last_mealtime, NULL);
	print_status(philo_info, EATING);
	pthread_mutex_unlock(&philo_info->mealtime);
	pthread_mutex_lock(&philo_info->full);
	philo_info->eat_cnt++;
	pthread_mutex_unlock(&philo_info->full);
	preciser_sleep(philo_info->status->time_to_eat);
	return (TRUE);
}

void	putdown(t_philo *philo_info)
{
	pthread_mutex_unlock(philo_info->left_fork);
	pthread_mutex_unlock(philo_info->right_fork);
}

int	philo_sleep(t_philo *philo_info)
{
	pthread_mutex_lock(&philo_info->status->progress);
	if (philo_info->status->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&philo_info->status->progress);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo_info->status->progress);
	print_status(philo_info, SLEEPING);
	preciser_sleep(philo_info->status->time_to_sleep);
	return (TRUE);
}

int	think(t_philo *philo_info)
{
	pthread_mutex_lock(&philo_info->status->progress);
	if (philo_info->status->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&philo_info->status->progress);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo_info->status->progress);
	print_status(philo_info, THINKING);
	return (TRUE);
}
