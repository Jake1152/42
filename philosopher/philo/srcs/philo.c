/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:28:39 by jim               #+#    #+#             */
/*   Updated: 2022/05/16 14:38:10 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void	do_for_one_philo(t_philo *philo_info)
{
	pthread_mutex_lock(&philo_info->status->progress);
	if (philo_info->status->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&philo_info->status->progress);
		return ;
	}
	pthread_mutex_unlock(&philo_info->status->progress);
	pthread_mutex_lock(philo_info->left_fork);
	print_status(philo_info, HUNGRY);
	pthread_mutex_unlock(philo_info->left_fork);
	preciser_sleep(philo_info->status->time_to_die);
}

void	*routine(void *philo_info_ptr)
{
	t_philo	*philo_info;

	philo_info = (t_philo *)philo_info_ptr;
	// 철학자 수의 증감에 따른 적정한 usleep 시간의 변화가 필요하다.
	if (philo_info->status->philosopher_cnt == 1)
	{
		do_for_one_philo(philo_info);
		return (NULL);
	}
	if (philo_info->back_number % 2 == 0)
		usleep(50 * philo_info->status->philosopher_cnt);
	while (TRUE)
	{
		if (pickup(philo_info) == FALSE)
			return (NULL);
		if (eat(philo_info) == FALSE)
			return (NULL);
		putdown(philo_info);
		if (philo_sleep(philo_info) == FALSE)
			return (NULL);
		if (think(philo_info) == FALSE)
			return (NULL);
	}
}

int	init(int argc, char **argv, t_status *status_info)
{
	int			idx;

	if (init_status(argc, argv, status_info) == FALSE)
	{
		printf("%s %d\n", __func__, __LINE__);
		return (FALSE);
	}
	// printf("before init_mutex(status_info)\n");
	// status에서 할당한 부분 init mutex에서 에러발생시 free할 것!
	if (init_mutex(status_info) == FALSE)
	{
		printf("%s %d\n", __func__, __LINE__);
		return (FALSE);
	}
	idx = 0;
	while (idx < status_info->philosopher_cnt)
	{
		// printf("before init_philosopher\n");
		if (init_philosopher(status_info, &status_info->philo[idx], idx + 1) \
			!= SUCCESS)
		{
			printf("%s %d\n", __func__, __LINE__);
			return (FALSE);
		}
		idx++;
	}
	return (TRUE);
}

int	join(t_status *status_info)
{
	int		idx;
	void	*ret;

	idx = 0;
	ret = NULL;
	while (idx < status_info->philosopher_cnt)
	{
		if (pthread_join(status_info->philo[idx].philospher, &ret) != SUCCESS)
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

int	create(t_status *status_info)
{
	int	idx;

	idx = 0;
	while (idx < status_info->philosopher_cnt)
	{
		if (pthread_create(&status_info->philo[idx].philospher, NULL, \
			routine, (void *)&status_info->philo[idx]) != SUCCESS)
		{
			printf("%s %d\n", __func__, __LINE__);
			return (FALSE);
		}
		idx++;
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_status	status_info;

	if (argc < 5 || argc > 6)
	{
		print_notice();
		return (0);
	}
	if (init(argc, argv, &status_info) == FALSE)
		return (0);
	if (create(&status_info) == FALSE)
		return (0);
	monitoring(&status_info);
	if (join(&status_info) == FALSE)
		return (0);
	free_and_destory(&status_info, status_info.philosopher_cnt);
	while (42);
	return (0);
}
