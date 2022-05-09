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
}

void	memory_release(t_status *status_info, int philo_idx)
{
	int		idx;

	// memory_release(t_status *status_info, int philo_idx)
	// int philo_idx 정확한 표현의 변수명 필요.
	all_free(status_info);
	// status_info->print_lock가 mutex_init 되어있다는 것이 확인 되어야함
	// logic상 그런게 아니라 logic이 바뀌어도 확인 가능한 조건 필요.
	if (philo_idx > 0)
		pthread_mutex_destroy(status_info->print_lock);
	idx = 0;
	while (idx <= philo_idx)
	{
		pthread_mutex_destroy(status_info->forks[idx]);
		idx++;
	}
}

int	init_mutex(t_status *status_info)
{
	int	philo_idx;

	if (pthread_mutex_init(&(status_info->print_lock), NULL) != SUCCESS)
		return (FALSE);
	philo_idx = 0;
	if (philo_idx < status_info->philosopher_cnt)
	{
		if (pthread_mutex_init(&(status_info->forks[philo_idx]), NULL)
			!= SUCCESS)
		{
			memory_release(status_info, philo_idx);
			return (FALSE);
		}
		philo_idx++;
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
	philo_info->left_fork = ;
	philo_info->right_fork = ;
	return (TRUE);
}

int	init_allocation(t_status *status_info, int philo_cnt)
{
	int	idx;

	status_info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_cnt);
	if (status_info->forks == NULL)
		return (FALSE);
	idx = 0;
	status_info->philo = (t_philo *)malloc(sizeof(t_philo) * philo_cnt);
	if (status_info->philo == NULL)
	{
		all_free(status_info);
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
	if (init_mutex(status_info) == FALSE ||
		init_allocation(status_info, philo_cnt) == FALSE ||
		gettimeofday(&status_info->init_time, NULL) != SUCCESS)
		return (FALSE);
	return (TRUE);
}
