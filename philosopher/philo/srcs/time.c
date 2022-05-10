/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:47:04 by jim               #+#    #+#             */
/*   Updated: 2022/05/10 20:47:08 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "philo.h"

unsigned long long	get_diff_ms(t_timeval start_tv, t_timeval end_tv)
{
	unsigned long long	ms;

	ms = (end_tv.tv_sec - start_tv.tv_sec) * 1000 \
			+ (end_tv.tv_usec - start_tv.tv_usec) / 1000;
	return (ms);
}

unsigned long long	get_current_ms(t_timeval tv)
{
	unsigned long long	ms;
	t_timeval			current_tv;

	if (gettimeofday(&current_tv, NULL) != SUCCESS)
	{
		print_error("gettimeofday fail.");
		return (0);
	}
	ms = (current_tv.tv_sec - tv.tv_sec) * 1000 \
			+ (current_tv.tv_usec - tv.tv_usec) / 1000;
	return (ms);
}
