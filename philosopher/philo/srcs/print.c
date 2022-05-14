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

int	print_status(t_philo *philo_info, t_philo_status philo_status)
{
	const char	*state_message[4] = {"is taken a fork", "is eating", \
									"is sleeping", "is thinking"};

	if (pthread_mutex_lock(&philo_info->status->print) != SUCCESS)
	{
		printf("%s %d\n", __func__, __LINE__);
		return (FALSE);
	}
	printf("%llums %d %s\n", get_current_ms(*(philo_info->init_time)), \
			philo_info->back_number, state_message[philo_status]);
	if (pthread_mutex_unlock(&philo_info->status->print) != SUCCESS)
	{
		printf("%s %d\n", __func__, __LINE__);
		return (FALSE);
	}
	return (TRUE);
}

int	print_error(char *error_statement)
{
	printf("%s\n", error_statement);
	return (TRUE);
}
