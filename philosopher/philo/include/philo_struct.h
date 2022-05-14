/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:05:17 by jim               #+#    #+#             */
/*   Updated: 2022/05/10 17:57:55 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct timeval	t_timeval;

typedef enum e_philo_status
{
	HUNGRY,
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
}			t_philo_status;

typedef struct s_status
{
	int				philosopher_cnt;
	struct s_philo	*philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
	pthread_mutex_t	*forks;
	// pthread_mutex_t	print;
	bool			progress_flag;
	pthread_mutex_t	progress;
	bool			must_eat_flag;
	t_timeval		init_time;
}				t_status;

typedef struct s_philo
{
	int				back_number;
	pthread_t		philospher;
	t_timeval		*init_time;
	t_timeval		last_mealtime;
	int				eat_cnt;
	t_status		*status;
	pthread_mutex_t	mealtime;
	pthread_mutex_t	full;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

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
