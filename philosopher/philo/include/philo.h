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

/*
• Your(s) program(s) should take the following arguments:
	number_of_philosophers
	time_to_die
	time_to_eat
	time_to_sleep
	[number_of_times_each_philosopher_must_eat]
◦ number_of_philosophers: The number of philosophers and also the number of forks.
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the sim- ulation, they die.
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
◦ number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
• Each philosopher has a number ranging from 1 to number_of_philosophers.
• Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philoso- pher number N + 1.
*/
#ifndef PHILO_H
# define PHILO_H
# include "philo_struct.h"
// philo_action
int					pickup(t_philo *philo_info);
int					putdown(t_philo *philo_info);
int					eat(t_philo *philo_info);
int					philo_sleep(t_philo *philo_info);
int					think(t_philo *philo_info);

// init
int					init_status(int argc, char *argv[], t_status *status_info);
int					init_mutex(t_status *status_info);
int					init_allocation(t_status *status_info, int philo_cnt);
int					init_philosopher(t_status *status_info, \
										t_philo *philo_info, int philo_number);
// free
void				all_free(t_status *status_info);
void				free_and_destory(t_status *status_info, int philo_idx);

// etc
unsigned long long	get_current_ms(t_timeval tv);
unsigned long long	get_diff_ms(t_timeval start_tv, t_timeval end_tv);
int					ft_atoi_nonnegative(const char *str);
void				print_notice(void);
void				print_error(char *msg);

#endif
