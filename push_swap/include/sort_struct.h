/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:16:49 by jim               #+#    #+#             */
/*   Updated: 2022/03/29 17:19:47 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STRUCT_H
# define SORT_STRUCT_H

typedef struct s_pivot_info
{
	long long	pivot;
	long long	chunk;
	/*
		pivot개수가 많은 걸 감안해야하는가?
		인덱싱을 안하면
		만약 elements count가 21억이 넘는 경우 pivot이 overflow된다.
		하지만 long long 넘어가는 것에 대해서도 마찬가지이다. 이런경우 어떻게 처리할 것인가?
		500개까지라 고려할필요는 없지만 만약에 경우를 생각해서 대용량에 대해서도 처리 가능하도록 한다면
		이부분도 고려해야한다.
		num <= top <= pivot + chunk
		pivot + chunk가 int범위를 넘는 경우는?
		(long long)으로 casting한다.
	*/
}				t_pivot_info;

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
}			t_stack_type;

typedef enum e_data_bound
{
	UPPER_BOUND,
	LOWER_BOUND,
}				t_data_bound;

#endif
