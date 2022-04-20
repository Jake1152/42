/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:05:17 by jim               #+#    #+#             */
/*   Updated: 2022/04/20 21:06:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H
# include <pthread.h>

typedef struct s_philo
{
	int				number_of_philosophers;
	int				*philo_back_number;
	double			time_to_die;
	double			time_to_eat;
	double			time_to_sleep;
	int				must_eat_cnt;
	pthread_mutex_t	*forks;
}				t_philo;

typedef enum e_pthread_flag
{
	SUCCESS,
}			t_pthread_flag;

typedef enum e_common_flag
{
	FALSE,
	TRUE,
}			t_common_flag;

#endif
