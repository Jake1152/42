/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:38:00 by jim               #+#    #+#             */
/*   Updated: 2022/05/17 18:46:10 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

static bool	progress_lock(t_status *status_info)
{
	pthread_mutex_lock(&status_info->progress);
	if (status_info->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&status_info->progress);
		return (TRUE);
	}
	pthread_mutex_unlock(&status_info->progress);
	return (FALSE);
}

static bool	check_full(t_status *status_info)
{
	int	idx;
	int	satisfied_philosopher_cnt;

	if (progress_lock(status_info))
		return (TRUE);
	idx = 0;
	satisfied_philosopher_cnt = 0;
	while (idx < status_info->philosopher_cnt)
	{
		pthread_mutex_lock(&status_info->philo[idx].full);
		if (status_info->philo[idx].eat_cnt >= status_info->must_eat_cnt)
			satisfied_philosopher_cnt++;
		pthread_mutex_unlock(&status_info->philo[idx].full);
		idx++;
	}
	if (satisfied_philosopher_cnt >= status_info->philosopher_cnt)
	{
		pthread_mutex_lock(&status_info->progress);
		status_info->progress_flag = FALSE;
		printf("All philosophers are full.\n");
		return (TRUE);
	}
	return (FALSE);
}

static void	print_dead(t_status *status_info)
{
	t_timeval	current_tv;

	pthread_mutex_lock(&status_info->progress);
	gettimeofday(&current_tv, NULL);
	printf("%llums %d %s\n", get_diff_ms_time(current_tv, \
			*(status_info->philo->init_time)), \
			status_info->philo->back_number, "died");
	status_info->progress_flag = FALSE;
}

static bool	check_dead(t_status *status_info)
{
	int			idx;
	t_timeval	current_tv;

	if (progress_lock(status_info))
		return (TRUE);
	idx = 0;
	while (idx < status_info->philosopher_cnt)
	{
		pthread_mutex_lock(&status_info->philo[idx].mealtime);
		gettimeofday(&current_tv, NULL);
		if (get_diff_ms_time(current_tv, status_info->philo[idx].last_mealtime) \
			>= (unsigned long long)status_info->time_to_die)
		{
			pthread_mutex_unlock(&status_info->philo[idx].mealtime);
			print_dead(status_info);
			return (TRUE);
		}
		pthread_mutex_unlock(&status_info->philo[idx].mealtime);
		idx++;
	}
	return (FALSE);
}

int	monitoring(t_status *status_info)
{
	if (status_info->must_eat_flag)
	{
		while (TRUE)
		{
			if (check_full(status_info))
				break ;
			if (check_dead(status_info))
				break ;
			usleep(100);
		}
	}
	else
	{
		while (TRUE)
		{
			if (check_dead(status_info))
				break ;
			usleep(100);
		}
	}
	pthread_mutex_unlock(&status_info->progress);
	return (TRUE);
}
