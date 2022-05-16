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

void	print_status(t_philo *philo_info, t_philo_status philo_status)
{
	t_timeval	current_tv;
	const char	*state_message[] = {"is taken a fork", "is eating", \
									"is sleeping", "is thinking", "died"};


	/* &philo_info->status->progress를 꼭해야하는가?
		정확하게 할려면 동작하는 모든 코드가 임계영역이므로 다 막아야하지만
		그렇게하면 시간이 오래걸리므로 일정부분만 확인한다.
		가급적
	*/
	/*
		이렇게 막아 놓아도 출력할때까지 막아놓아야 정확하다.
		하지만 시간이 지연되어서 데드락과 기아발생가능성이 늘어난다.
	*/
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

int	print_error(char *error_statement)
{
	printf("%s\n", error_statement);
	return (TRUE);
}

void	print_notice(void)
{
	printf("please input appropriate value as argument,\n\
It will be only taked 4~5 argumentes.\n\
e.g)\n\
./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep number_of_times_each_philosopher_must_eat\n");
}
