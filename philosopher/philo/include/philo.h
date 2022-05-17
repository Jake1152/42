/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:05:17 by jim               #+#    #+#             */
/*   Updated: 2022/05/10 20:47:24 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "philo_struct.h"

int						create(t_status *status_info);
int						join(t_status *status_info);
int						init(int argc, char **argv, t_status *status_info);
void					*routine(void *philo_info_ptr);
/* philo_action */
int						pickup(t_philo *philo_info);
void					putdown(t_philo *philo_info);
int						eat(t_philo *philo_info);
int						philo_sleep(t_philo *philo_info);
int						think(t_philo *philo_info);

/* init */
int						init_status(int argc, char *argv[], \
									t_status *status_info);
int						init_mutex(t_status *status_info);
int						init_allocation(t_status *status_info, int philo_cnt);
int						init_philosopher(t_status *status_info, \
										t_philo *philo_info, int philo_number);
int						monitoring(t_status *status_info);
/* free */
void					free_all(t_status *status_info);
int						free_and_destory(t_status *status_info, \
											int fork_idx, int full_idx, \
											int mealtime_idx);
/* etc */
void					preciser_sleep(unsigned long long wait_ms);
unsigned long long		get_diff_ms_time(t_timeval late_tv, t_timeval early_tv);
unsigned long long		get_current_ms_time(void);
unsigned long long		ft_atoi_nonnegative(const char *str);
void					print_notice(void);
void					print_status(t_philo *philo_info, \
									t_philo_status philo_status);

#endif
