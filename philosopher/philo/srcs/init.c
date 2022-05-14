/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:11:46 by jim               #+#    #+#             */
/*   Updated: 2022/05/11 13:47:51 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "philo.h"
#include <stdlib.h>
#include <pthread.h>
// debug
#include <stdio.h>

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
	gettimeofday(&status_info->init_time, NULL);
	if (argc == 6)
	{
		status_info->must_eat_cnt = ft_atoi_nonnegative(argv[5]);
		status_info->must_eat_flag = TRUE;
	}
	if (status_info->philosopher_cnt <= 0 || status_info->time_to_die < 0
		|| status_info->time_to_eat < 0 || status_info->time_to_sleep < 0
		|| status_info->must_eat_cnt < 0)
		return (FALSE);
	if (init_allocation(status_info, philo_cnt) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	init_mutex(t_status *status_info)
{
	int	philo_idx;
	int	ret_mutex_init;

	// mutex destory 고민 할 것!
	philo_idx = 0;
	// if (pthread_mutex_init(&(status_info->print), NULL) != SUCCESS)
	// 	free_and_destory(status_info, philo_idx);
	if (pthread_mutex_init(&(status_info->progress), NULL) != SUCCESS)
		free_and_destory(status_info, philo_idx);
	while (philo_idx < status_info->philosopher_cnt)
	{
		ret_mutex_init = pthread_mutex_init(&(status_info->forks[philo_idx]), NULL);
		// printf("forks_mutex_init : %d, philo_idx : %d\n", ret_mutex_init, philo_idx);
		if (ret_mutex_init != SUCCESS)
		{
			free_and_destory(status_info, philo_idx);
			return (FALSE);
		}
		ret_mutex_init = pthread_mutex_init(&(status_info->philo[philo_idx].mealtime), NULL);
		// printf("mealtime_mutex_init : %d, philo_idx : %d\n", ret_mutex_init, philo_idx);
		if (ret_mutex_init != SUCCESS)
		{
			free_and_destory(status_info, philo_idx);
			return (FALSE);
		}
		ret_mutex_init = pthread_mutex_init(&(status_info->philo[philo_idx].full), NULL);
		// printf("full_mutex_init : %d, philo_idx : %d\n", ret_mutex_init, philo_idx);
		if (ret_mutex_init != SUCCESS)
		{
			free_and_destory(status_info, philo_idx);
			return (FALSE);
		}
		philo_idx++;
	}
	return (TRUE);
}

int	init_philosopher(t_status *status_info, t_philo *philo_info,
					int philo_number)
{
	int	philo_cnt;
	int	philo_idx;

	philo_cnt = status_info->philosopher_cnt;
	philo_idx = philo_number - 1;
	philo_info->back_number = philo_number;
	philo_info->init_time = &status_info->init_time;
	philo_info->last_mealtime = status_info->init_time;
	philo_info->eat_cnt = 0;
	philo_info->status = status_info;
	philo_info->init_time = &status_info->init_time;
	philo_info->left_fork = &status_info->forks[philo_idx % philo_cnt];
	philo_info->right_fork = \
				&status_info->forks[(philo_idx + (philo_cnt - 1)) % philo_cnt];
	return (SUCCESS);
}

int	init_allocation(t_status *status_info, int philo_cnt)
{
	status_info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
													* philo_cnt);
	if (status_info->forks == NULL)
		return (FALSE);
	status_info->philo = (t_philo *)malloc(sizeof(t_philo) * philo_cnt);
	if (status_info->philo == NULL)
	{
		free_all(status_info);
		return (FALSE);
	}
	return (TRUE);
}
