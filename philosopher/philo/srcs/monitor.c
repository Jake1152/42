/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:38:00 by jim               #+#    #+#             */
/*   Updated: 2022/05/14 18:38:09 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

static bool	check_full(t_status *status_info)
{
	int	idx;
	int	satisfied_philosopher_cnt;

	pthread_mutex_lock(&status_info->progress);
	if (status_info->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&status_info->progress);
		return (TRUE);
	}
	pthread_mutex_unlock(&status_info->progress);
	idx = 0;
	satisfied_philosopher_cnt = 0;
	while (idx < status_info->philosopher_cnt)
	{
		// printf("idx : %d\n", idx);
		pthread_mutex_lock(&status_info->philo[idx].full);
		if (status_info->philo[idx].eat_cnt >= status_info->must_eat_cnt)
			satisfied_philosopher_cnt++;
		pthread_mutex_unlock(&status_info->philo[idx].full);
		idx++;
	}
	if (satisfied_philosopher_cnt == status_info->philosopher_cnt)
	{
		pthread_mutex_lock(&status_info->progress);
		status_info->progress_flag = FALSE;
		printf("All philosophers are full.\n");
		pthread_mutex_unlock(&status_info->progress);
	}
	return (FALSE);
}

static bool	check_dead(t_status *status_info)
{
	int			idx;
	t_timeval	current_tv;

	pthread_mutex_lock(&status_info->progress);
	if (status_info->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&status_info->progress);
		return (TRUE);
	}
	pthread_mutex_unlock(&status_info->progress);
	idx = 0;
	while (idx < status_info->philosopher_cnt)
	{
		pthread_mutex_lock(&status_info->philo[idx].mealtime);
		/*
			마지막 식사시간과 현재시간의 차이를 ms로 바꾼뒤
			time_to_die 값 이상이면 죽어야한다.
		*/
		gettimeofday(&current_tv, NULL);
		if (get_diff_ms_time(current_tv, status_info->philo[idx].last_mealtime) >= status_info->time_to_die) // 시간 계산필요.
		{
			pthread_mutex_unlock(&status_info->philo[idx].mealtime);
			// 먼저 출력하기 떄문에 문제 발생가능
			// 결국 이렇게되면 print mutex가 다시 필요해진다.
			print_status(&status_info->philo[idx], DEAD);
			pthread_mutex_lock(&status_info->progress);
			status_info->progress_flag = FALSE;
			pthread_mutex_unlock(&status_info->progress);
			// printf("******************************************\n" );
			return (TRUE);
		}
		// 	;
		pthread_mutex_unlock(&status_info->philo[idx].mealtime);
		idx++;
	}
	return (FALSE);
}

int	monitoring(t_status *status_info)
{
	/*
		- 밥 다 먹었는지?
		- 식사시간 넘은 철학자가 있는지?
		- 깔끔하고 보다 효율적?이기 위해서는 모니터 스레드를 2개 써야한다.
	*/
	if (status_info->must_eat_flag)
	{
		while (TRUE)
		{
			if (check_full(status_info))
				break ;
			if (check_dead(status_info))
				break ;
			usleep(1000);
		}
	}
	else
	{
		while (TRUE)
		{
			if (check_dead(status_info))
				break ;
			usleep(1000);
		}
	}
	return (TRUE);
}
