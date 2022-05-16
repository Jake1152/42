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
#include <unistd.h>

unsigned long long	get_diff_ms_time(t_timeval late_tv, t_timeval early_tv)
{
	unsigned long long	ms;

	ms = (late_tv.tv_sec - early_tv.tv_sec) * 1000 \
			+ (late_tv.tv_usec - early_tv.tv_usec) / 1000;
	return (ms);
}

unsigned long long	get_ms_time(t_timeval tv)
{
	unsigned long long	ms;

	ms = tv.tv_sec * 1000;
	ms += tv.tv_usec / 1000;
	return (ms);
}

unsigned long long	get_current_ms_time(void)
{
	t_timeval		current_tv;

	gettimeofday(&current_tv, NULL);
	return (get_ms_time(current_tv));
}

void	preciser_sleep(unsigned long long wait_ms)
{
	unsigned long long	end_time;

	end_time = get_current_ms_time() + wait_ms;
	while (get_current_ms_time() <= end_time)
		usleep(100);
}
