/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:16:49 by jim               #+#    #+#             */
/*   Updated: 2022/03/31 11:27:30 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STRUCT_H
# define SORT_STRUCT_H

typedef struct s_pivot_info
{
	long long	pivot;
	long long	chunk;
}				t_pivot_info;

typedef struct s_min_max_info
{
	int	min;
	int	max;
}				t_min_max_info;

typedef struct s_max_data_info
{
	int	bound;
	int	data;
	int	idx;
}				t_max_data_info;

typedef enum e_stack_type
{
	A_STACK=1,
	B_STACK,
	BOTH_STACK,
}			t_stack_type;

typedef enum e_data_bound
{
	UPPER_BOUND,
	LOWER_BOUND,
}				t_data_bound;

#endif
