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
int					monitoring(t_status *status_info);

// free
void				free_all(t_status *status_info);
int					free_and_destory(t_status *status_info, int philo_idx);
int					error_handler(char *error_statement);

// etc
unsigned long long	get_current_ms(t_timeval tv);
unsigned long long	get_diff_ms(t_timeval start_tv, t_timeval end_tv);
int					ft_atoi_nonnegative(const char *str);
void				print_notice(void);
int					print_error(char *error_statement);
int					print_status(t_philo *philo_info, \
								t_philo_status philo_status);

#endif
