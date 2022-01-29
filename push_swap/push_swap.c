/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:53 by jim               #+#    #+#             */
/*   Updated: 2022/01/29 18:15:19 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linkedstack.h"

int	push_swap(char *num_str)
{
	/*
		" "기준으로 split
		a stack 추가
		11개 명령어 이외에 다른 동작을 해도 되는가?
		다른 동작도 complexity
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
		', "  두개 문자는 문자열을 감싸는 것으로 치고서 넘어간다.
		그외에 숫자가 아닌 문자가 들어오면 Error 호출하고 끝난다.
		Error호출을 분리할것인가?
		아니면 발생한 곳에서 처리할 것인가?
		분리한다면 Error발생여부를 넘겨줘서 한 곳에서 처리한다.
		불편할 것 같다.
		Error처리를 분리하면 어떤 특징이 있고 장단점이 있는가?
		- 분리할려면 return값에 넘겨주거나
		  structure member변수를 쓸 수도 있다.
		  - 무언가 종속성이 더 심해질 수 있을것 같다는 생각이 든다.
		- 개별로 나누면
		  함수별 코드가 길어질 수도 있을 것 같으며 
		  Error 발생하면 종료해야하는데
		  그정보를 결국 main에서 알아야한다.
		  즉 main에서 check하거나 그 자리에서 종료 가능한가?
		  "Error\n"를 출력하고서 exit한다?
		  exit을 해도 되는가?
		  어떻게 처리하는지에 따라 달라진다.
		  exit보다는 전체 리턴값으로 분류할 수 있으면 어디서 어떻게 문제가 생겼는지 관리하기 좋을 것이라 생각든다.
		  그러면 타고타고 들어가서 결과 값을 main에서 처리할 수 있게 해야한다.
		  error code 값을 어딘가 저장해야 의미 있어진다.
		  error code값 관리에 대한 리소스도 발생한다.
		  error 구분을 잘 해주어야한다.
	*/
	/*
		number와 ', "까지는 인정해주며 그외에는 error 호출
		정상적이라면 int list로 분리한다.
	*/
	int	sign;

	sign = 1;
	while (*num_str != NULL)
	{
		while (*num_str == '\'' || *num_str == '\"' || *num_str == ' ')
			num_str++;
		if (*num_str == '-' || *num_str == '+')
		{
			if (*num_str == '-')
				sign = -1;
			num_str++;
		}
		while ('0' <= num_str && num_str <= '9')
			;
		else // error case
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
	return (0);
}
