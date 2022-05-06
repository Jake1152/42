/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:11:46 by jim               #+#    #+#             */
/*   Updated: 2022/05/05 20:34:35 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#inlcude <pthread.h>

int	init_mutex(t_status *status_info)
{
	;//will be removed
}

int	init_philosopher(t_status *status_info, t_philo *philo_info, \
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
	pthread_mutex_init(status_info->forks[philo_number]);
	
}

int	init_allocation(t_status *status_info, int philo_cnt)
{
	status_info->forks = (pthread_mutex_t *)malloc(\
										sizeof(pthread_mutex_t) * philo_cnt);
	if (status_info->forks == NULL)
		return (FALSE);
	status_info->philo = (t_philo *)malloc(sizeof(t_philo) * philo_cnt);
	if (status_info->philo == NULL)
	{
		free(status_info->forks);
		status_info->forks = NULL;
		return (FALSE);
	}
}

int	init_status(int argc, char *argv[], t_status *status_info)
{
	int	philo_cnt;

	philo_cnt = ft_atoi(argv[1]);
	status_info->philosopher_cnt = philo_cnt;
	status_info->time_to_die = ft_atoi(argv[2]);
	status_info->time_to_eat = ft_atoi(argv[3]);
	status_info->time_to_sleep = ft_atoi(argv[4]);
	status_info->must_eat_flag = FALSE;
	status_info->must_eat_cnt = 0;
	if (argc == 6)
	{
		status_info->must_eat_cnt = ft_atoi(argv[5]);
		status_info->must_eat_flag = TRUE;
	}
	if (status_info->philosopher_cnt < 0 || status_info->time_to_die < 0 || \
		status_info->time_to_eat < 0 || status_info->time_to_sleep < 0 || \
		status_info->must_eat_cnt < 0)
		return (FALSE);
	if (init_allocation(status_info, philo_cnt) == FALSE)
		return (FALSE);
	if (gettimeofday(&status_info->init_time, NULL) != SUCCESS)
		return (FALSE);
	if (pthread_mutex_init(status_info->print_lock) != SUCCESS)
		return (FALSE);
	return (TRUE);
}
