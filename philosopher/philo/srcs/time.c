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


int	get_diff_ms_time(t_timeval late_tv, t_timeval early_tv)
{
	int	ms;

	ms = (late_tv.tv_sec - early_tv.tv_sec) * 1000 \
			+ (late_tv.tv_usec - early_tv.tv_usec) / 1000;
	return (ms);
}

int	get_us_time(t_timeval tv)
{
	int us;

	us = tv.tv_sec * (1000 * 1000);
	us += tv.tv_usec;
	return (us);
}

int	get_current_ms_time(t_timeval tv)
{
	int				ms;
	t_timeval		current_tv;

	gettimeofday(&current_tv, NULL);
	ms = (current_tv.tv_sec - tv.tv_sec) * 1000 \
			+ (current_tv.tv_usec - tv.tv_usec) / 1000;
	return (ms);
}
