/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:26:38 by jim               #+#    #+#             */
/*   Updated: 2022/05/13 18:26:38 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>

void	print_status(t_philo *philo_info, t_philo_status philo_status)
{
	t_timeval	current_tv;
	const char	*state_message[] = {"has taken a fork", "is eating", \
									"is sleeping", "is thinking", "died"};

	pthread_mutex_lock(&philo_info->status->progress);
	if (philo_info->status->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&philo_info->status->progress);
		return ;
	}
	gettimeofday(&current_tv, NULL);
	printf("%llums %d %s\n", get_diff_ms_time(current_tv, \
			*(philo_info->init_time)), \
			philo_info->back_number, state_message[philo_status]);
	pthread_mutex_unlock(&philo_info->status->progress);
}

void	print_notice(void)
{
	printf
	(
		"please input appropriate value as argument,\n"
		"It will be only taked 4~5 argumentes.\n"
		"e.g)\n"
		"./philo number_of_philosophers time_to_die time_to_eat"
		"time_to_sleep number_of_times_each_philosopher_must_eat\n"
	);
}
