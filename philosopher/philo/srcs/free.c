/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:42 by jim               #+#    #+#             */
/*   Updated: 2022/05/10 17:08:25 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include <stdlib.h>
#include <stdio.h>

void	free_all(t_status *status_info)
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

int	free_and_destory(t_status *status_info, int philo_cnt)
{
	int		idx;

	printf("in free_and_destory\n");
	// memory_release(t_status *status_info, int philo_cnt)
	// int philo_cnt 정확한 표현의 변수명 필요.
	free_all(status_info);
	// status_info->print_state가 mutex_init 되어있다는 것이 확인 되어야함
	// logic상 그런게 아니라 logic이 바뀌어도 확인 가능한 조건 필요.
	// if (philo_cnt > 0)
	pthread_mutex_destroy(&status_info->progress);
	idx = 0;
	while (idx < philo_cnt)
	{
		pthread_mutex_destroy(&status_info->forks[idx]);
		pthread_mutex_destroy(&status_info->philo[idx].full);
		pthread_mutex_destroy(&status_info->philo[idx].mealtime);
		idx++;
	}
	return (TRUE);
}
