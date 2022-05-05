/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:28:39 by jim               #+#    #+#             */
/*   Updated: 2022/05/05 16:53:53 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	eat(t_status status_info)
{

}

void	*philo_action(void *philo_info_ptr)
{
	/*
	- eat()
	- sleep()
	- think()
	*/
	t_philo	*philo_info;

	status_info = (t_status *)philo_info_ptr;
	return (NULL);
}

int	input_value_parsing(int argc, char *argv[], t_status *status_info)
{
	int	philo_cnt;

	philo_cnt = ft_atoi(argv[1]);
	status_info->philosopher_cnt = philo_cnt;
	status_info->time_to_die = ft_atoi(argv[2]);
	status_info->time_to_eat = ft_atoi(argv[3]);
	status_info->time_to_sleep = ft_atoi(argv[4]);
	status_info->must_eat_flag = FALSE;
	status_info->progress_flag = TRUE;
	if (argc == 6)
	{
		status_info->must_eat_cnt = ft_atoi(argv[5]);
		status_info->must_eat_flag = TRUE;
	}
	status_info->forks = (pthread_mutex_t *)malloc(\
										sizeof(pthread_mutex_t) * philo_cnt);
	if (status_info->forks == NULL)
		return (FALSE);
	status_info->philo = (t_philo *)malloc(sizeof(t_philo) * philo_cnt);
	if (status_info->philo == NULL)
		return (FALSE);
	if (gettimeofday(&status_info->init_time, NULL) != SUCCESS)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_status	status_info;
	int			idx;
	void		*ret;

	if (argc < 5 || argc > 6)
	{
		print_notice();
		return (0);
	}
	if (input_value_parsing(argc, argv, &status_info) == FALSE)
		return (0);
	idx = 0;
	while (idx < status_info.philosopher_cnt)
	{
		status_info.philo[idx].back_number = idx + 1;
		if (pthread_create(&(status_info.philo[idx].philosphers), NULL, \
			philo_action, (void *)&status_info) != SUCCESS)
			return (0);
		idx++;
	}
	idx = 0;
	ret = NULL;
	while (idx < status_info.philosopher_cnt)
	{
		if (pthread_join(status_info.philo[idx].philosphers, &ret) != SUCCESS)
			return (0);
		idx++;
	}
	return (0);
}
