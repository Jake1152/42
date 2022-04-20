/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:28:39 by jim               #+#    #+#             */
/*   Updated: 2022/04/20 21:11:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*philo_action(void *philo_info_ptr)
{
	/*
	- eat()
	- sleep()
	- think()
	*/
	t_philo	*philo_info;
	
	philo_info = (t_philo *)philo_info_ptr;
	printf("philo_info->number_of_philosophers : %d\n", philo_info->number_of_philosophers);
	return (philo_info_ptr);
}

int	input_value_parsing(int argc, char *argv[], t_philo *philo_info)
{
	int	philo_cnt;

	philo_cnt = ft_atoi(argv[1]);
	philo_info->number_of_philosophers = philo_cnt;
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_info->must_eat_cnt = ft_atoi(argv[5]);
	philo_info->forks = (pthread_mutex_t *)malloc(\
										sizeof(pthread_mutex_t) * philo_cnt);
	if (philo_info->forks == NULL)
		return (FALSE);
	philo_info->philo_back_number = (int *)malloc(sizeof(int) * philo_cnt);
	if (philo_info->philo_back_number == NULL)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_philo		philo_info;
	pthread_t	*philosphers;
	int			idx;
	void		*ret;

	if (argc < 5 || argc > 6)
	{
		print_notice();
		return (0);
	}
	if (input_value_parsing(argc, argv, &philo_info) == FALSE)
		return (0);
	philosphers = (pthread_t *)malloc(sizeof(pthread_t) * \
										philo_info.number_of_philosophers);
	if (philosphers == NULL)
		return (0);
	idx = 0;
	// 함수 1개로 뺸다음 FASLE여부 체크
	// pthread 1개씩 만들고서 join해도 되는지?
	// 아니면 일괄적으로 create하고서 join해야하는가?
	while (idx < philo_info.number_of_philosophers)
	{
		// 내가 몇번인지 알아야하지만 다른 사람은 나의 존재를 몰라야한다. 그렇다면 구조체를 어떻게 넘기는게 나은가?
		// philo_info구조체도 철학자별로 나눠야하는가?
		// 그러면 옆에 포크가 쓰는중인지 모른다.
		// 구조를 그리고서 다시 진행한다.
		ret = NULL;
		philo_info.philo_back_number[idx] = idx + 1;
		if (pthread_create(&(philosphers[idx]), NULL, philo_action, (void *)&philo_info) \
			!= SUCCESS)
			return (0);
		// ret의 역할, 구조체 멤버변수로 써야할 필요는 있는지 확인 필요!!
		if (pthread_join(philosphers[idx], ret) != SUCCESS)
			return (0);
		idx++;
	}
	return (0);
}
