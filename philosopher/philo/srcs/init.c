/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:11:46 by jim               #+#    #+#             */
/*   Updated: 2022/05/07 20:55:46 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "philo.h"
#include <stdlib.h>
#include <pthread.h>
//debug
#include <stdio.h>

void	all_free(t_status *status_info)
{
	free(status_info->forks);
	status_info->forks = NULL;
	free(status_info->philo);
	status_info->philo = NULL;
}

int	memory_release(t_status *status_info, int philo_idx)
{
	t_philo	philo_info;
	int		idx;

	philo_info = status_info->philo[philo_idx];
	if (status_info->forks != NULL)
	{
		free(status_info->forks);
		status_info->forks = NULL;
	}
	if (status_info->philo != NULL)
	{
		free(status_info->philo);
		status_info->philo = NULL;
	}
	// mutex init release
	idx = 0;
	while (idx < philo_idx)
	{
		if (pthread_mutex_destroy(status_info->forks[idx]) != SUCCESS)

		idx++;
	}
	return (TRUE);
}

int	init_philosopher(t_status *status_info, t_philo *philo_info, 
					int philo_number)
{
	/*
	 * mutex init
	 * start_time 이식
	 * back number할당
	 * eat_cnt 0으로 초기화
	 */
	philo_info->back_number = philo_number;
	philo_info->last_time = status_info->init_time;
	philo_info->eat_cnt = 0;
	philo_info->status = status_info;
	philo_info->philo_status = HUNGRY;
	if (pthread_mutex_init(&(status_info->forks[philo_number]), NULL)
		!= SUCCESS)
	{
		all_free(status_info);
		return (TRUE);
	}
	return (FALSE);
}

int	init_allocation(t_status *status_info, int philo_cnt)
{
	int	idx;

	status_info->forks = (pthread_mutex_t *)malloc(
										sizeof(pthread_mutex_t) * philo_cnt);
	if (status_info->forks == NULL)
		return (FALSE);
	idx = 0;
	status_info->philo = (t_philo *)malloc(sizeof(t_philo) * philo_cnt);
	if (status_info->philo == NULL)
	{
		free(status_info->forks);
		status_info->forks = NULL;
		return (FALSE);
	}
	return (TRUE);
}

int	init_status(int argc, char *argv[], t_status *status_info)
{
	int	philo_cnt;

	philo_cnt = ft_atoi_nonnegative(argv[1]);
	status_info->philosopher_cnt = philo_cnt;
	status_info->time_to_die = ft_atoi_nonnegative(argv[2]);
	status_info->time_to_eat = ft_atoi_nonnegative(argv[3]);
	status_info->time_to_sleep = ft_atoi_nonnegative(argv[4]);
	status_info->must_eat_flag = FALSE;
	status_info->progress_flag = TRUE;
	status_info->must_eat_cnt = 0;
	if (argc == 6)
	{
		status_info->must_eat_cnt = ft_atoi_nonnegative(argv[5]);
		status_info->must_eat_flag = TRUE;
	}
	if (status_info->philosopher_cnt < 0 || status_info->time_to_die < 0 ||
		status_info->time_to_eat < 0 || status_info->time_to_sleep < 0 ||
		status_info->must_eat_cnt < 0)
		return (FALSE);
	if (pthread_mutex_init(&(status_info->print_lock), NULL) != SUCCESS ||
		gettimeofday(&status_info->init_time, NULL) != SUCCESS ||
		init_allocation(status_info, philo_cnt) == FALSE)
		return (FALSE);
	return (TRUE);
}
