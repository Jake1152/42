/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:28:39 by jim               #+#    #+#             */
/*   Updated: 2022/04/18 20:27:46 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void	philo_eat()
{
	;
}

void	philo_action(void *philospher_number)
{

	;
}

int	input_value_parsing(int argc, char *argv[], t_philo *philo_info)
{
	philo_info->number_of_philosophers = ft_atoi(argv[1]);
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_info->time_to_must_eat = ft_atoi(argv[5]);
}

int	main(int argc, char *argv[])
{
	t_philo		philo_info;
	pthread_t	philospher;

	if (argc < 5 || argc > 6)
	{
		printf("./philo number_of_philosophers time_to_die time_to_eat \
				time_to_sleep number_of_times_each_philosopher_must_eat\n");
		return (0);
	}
	input_value_parsing(argc, argv, &philo_info);
	return (0);
}
