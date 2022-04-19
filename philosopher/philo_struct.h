/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:05:17 by jim               #+#    #+#             */
/*   Updated: 2022/04/19 19:31:23 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct s_philo
{
	int				number_of_philosophers;
	int				philo_back_number;
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
