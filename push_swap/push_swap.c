/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:53 by jim               #+#    #+#             */
/*   Updated: 2022/02/04 18:27:05 by jake             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "doublylist.h"

// push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack)
int	push_swap(char *num_str)
{
	/*
		정렬하는 용도로만 사용한다.
		main에서 parsing,
		init 담당
	*/
	int		*a_stack;
	int		*b_stack;
	size_t	cmd_cnt;

	cmd_cnt = 0;
	a_stack = parse_str_to_int_list(num_str);
	// int * array return 
	if (a_stack == NULL)
	{
		print_error();
		return (0);
	}
	b_stack = create_int_list();

	return (cmd_cnt);
}

int	*parse_str_to_int_list(char *num_str)
{
	/*
		문자열을 넘겨받는다.
		넘겨받은 문자열에서 숫자가 나오면 
		숫자가 나올동안에는 atoi를 적용한다.
		이후에 공백이 나오면 다음문자
		123 45 
		"123 45"
		를 어떻게 구분할것인가?
		구분해야하는 이유는?
		atoi호출 횟수가 달라지기 때문
		그리고
		"123 45 a"
		는 또 다르다.
		error처리해야한다.

		atoi는 어쨌든 공백 스킵하고 부호 1개만 읽고 숫자를 변환해주므로
		"   -5  334 5" 같은 케이스가 있는 경우
		-5까지 읽고 끝난다.
		그런데 나는 이후도 읽어야한다.
		어디까지 읽었는지 정보를 알고 있으면 문제가 없긴하다.
	*/
	/*
		number와 ', "까지는 인정해주며 그외에는 error 호출
		정상적이라면 int list로 분리한다.
	*/
	int				sign;
	t_DoublyList	stack_a;

	sign = 1;
	while (*num_str != NULL)
	{
		while (' ')
			num_str++;
		if (*num_str == '-' || *num_str == '+')
		{
			if (*num_str == '-')
				sign = -1;
			num_str++;
		}
		while ('0' <= num_str && num_str <= '9')
			;
		if ('0' > num_str || num_str > '9') // error case
		{
			/* code */
		}
		num_str++;
	}
	return (1);
}

int	*create_int_list(void)
{
	return (1);
}

int	main(int argc, char *argv[])
{
	/*
		다른 shell에 따라 파싱안해줘도 되는 부분은 생각하지 않는다.
		zsh 기준으로하며 checker에서 Error로 처리하는 케이스들에 대해서는 ERROR하도록 한다.
		그 외에는 다 OK
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

		1. argc 갯수를 통해 error 체크
		2. argv로 넘어오는 값들 parsing
		3. 여러개가 넘어오면 arguments가 여러개이다. 이런 경우 int * array의 size를 어떻게 처리할 것인가?
		   
	*/
	int	idx;

	if (argc == 0)
		print_error();
	/*
		int *로 만들때 어떻게 할 것인지
		몇개가 될지 모른다.
		최종적으로 linked stack으로 만들 것인데 중간에 int *과정을 거쳐야하는가?
		처음부터 init()으로 stack a,b를 만든다.(linked list type)
		이후에 파싱하면서 파싱 된 애들은 바로 node로 추가한다.
		중간에 파싱 error  나면 이전에 할당한것 모두 free하고서 Error\n출력하고서 exit() 한다.
	*/
	idx = 1;
	while (idx < argc)
		parse_str_to_int_list(argv[idx]);
	/*
		- 
	*/
	return (0);
}
