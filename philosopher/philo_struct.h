/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:05:17 by jim               #+#    #+#             */
/*   Updated: 2022/04/18 18:22:04 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct s_philo
{
	int		number_of_philosophers;
	double	time_to_die;
	double	time_to_eat;
	double	time_to_sleep;
	int		time_to_must_eat;
}				t_philo;

typedef enum e_pthread_flag
{
	SUCCESS,
}			t_pthread_flag;

#endif
