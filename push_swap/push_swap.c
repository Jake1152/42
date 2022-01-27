/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:53 by jim               #+#    #+#             */
/*   Updated: 2022/01/27 21:48:14 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "doublylist.h"

int	push_swap(char *num_str)
{
	/*
		" "기준으로 split
		a stack 추가
		12개 명령어 이외에 다른 동작을 해도 되는가?
		다른 동작도 complexity
	*/
	int	*a_stack;
	int	*b_stack;
	int	cmd_cnt;

	cmd_cnt = 0;
	a_stack = parse_str_to_int_list(num_str);
	b_stack = create_int_list();

	return (cmd_cnt);
}

int	*parse_str_to_int_list(char *num_str)
{
	return (1);
}

int	*create_int_list(void)
{
	return (1);
}

int	main(int argc, char *argv[])
{
	/*
		argc로 error처리
		argv에서 넘어오는 값도 int type array여야한다.
		atoi가 안되면 error 
		2 'z' 3 6 5 8
		인자가 1개일때
		정렬이 
		zsh \"\" 문자
		bash 기준으로 한다.
		그런데 defence가 될것인가? 그게 당연한가?
		모르겠다.
		zsh기준이 나을 것이라 생각
	*/
	return (0);
}
