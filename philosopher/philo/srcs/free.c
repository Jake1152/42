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

void	free_and_destory(t_status *status_info, int philo_idx)
{
	int		idx;

	printf("in free_and_destory\n");
	// memory_release(t_status *status_info, int philo_idx)
	// int philo_idx 정확한 표현의 변수명 필요.
	all_free(status_info);
	// status_info->print_lock가 mutex_init 되어있다는 것이 확인 되어야함
	// logic상 그런게 아니라 logic이 바뀌어도 확인 가능한 조건 필요.
	if (philo_idx > 0)
		pthread_mutex_destroy(&status_info->print_lock);
	idx = 0;
	while (idx <= philo_idx)
	{
		pthread_mutex_destroy(&status_info->forks[idx]);
		idx++;
	}
}
