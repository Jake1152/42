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

}

int	*create_int_list()
{

}
