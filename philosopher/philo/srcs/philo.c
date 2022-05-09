/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:28:39 by jim               #+#    #+#             */
/*   Updated: 2022/05/07 20:36:10 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	eat(t_philo *philo_info)
{
	if (philo_info->left_fork ==)
	printf("%d eating\n", philo_info->back_number);
}

void	philo_sleep(t_philo *philo_info)
{
	printf("%d sleep\n", philo_info->back_number);
}

void	think(t_philo *philo_info)
{
	printf("%d think\n", philo_info->back_number);
}

void	pickup(t_philo *philo_info)
{
	pthread_mutex_lock(philo_info->left_fork);
	if ()
}

void	putdown(t_philo *philo_info)
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

	philo_info = (t_philo *)philo_info_ptr;
	while (philo_info->status->progress_flag == TRUE)
	{
		pickup(philo_info);
		eat(philo_info);
		putdown(philo_info);
		philo_sleep(philo_info);
		think(philo_info);
	}
	return (NULL);
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
	if (init_status(argc, argv, &status_info) == FALSE)
		return (0);
	idx = 0;
	while (idx < status_info.philosopher_cnt)
	{
		if (init_philosopher(&status_info, &(status_info.philo[idx]), idx + 1) \
			!= SUCCESS)
			return (0);
		if (pthread_create(&(status_info.philo[idx].philosphers), NULL, \
			philo_action, (void *)&status_info.philo[idx]) != SUCCESS)
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
