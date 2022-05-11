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

#include "philo.h"

unsigned long long	get_us_time(t_timeval tv)
{
	unsigned long long	us;

	us = tv.tv_sec * (1000 * 1000);
	us += tv.tv_usec;
	return (us);
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
