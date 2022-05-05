/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:05:17 by jim               #+#    #+#             */
/*   Updated: 2022/05/05 15:21:12 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo
{
	int				back_number;
	pthread_t		philosphers;
	struct timeval	last_time;
}				t_philo;

typedef struct s_status
{
	int				philosopher_cnt;
	t_philo			*philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
	pthread_mutex_t	*forks;
	pthread_mutex_t	progress_lock;
	bool			progress_flag;
	bool			must_eat_flag;
	struct timeval	init_time;
}				t_status;

typedef enum e_pthread_flag
{
	ERROR = -1,
	SUCCESS,
}			t_pthread_flag;

typedef enum e_common_flag
{
	FALSE,
	TRUE,
}			t_common_flag;

#endif
