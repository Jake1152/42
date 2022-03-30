/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_tester.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:25:16 by jim               #+#    #+#             */
/*   Updated: 2022/03/30 16:15:00 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "doublylist.h"
#include <stdio.h>

int	push_swap_cmd_tester(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	/*
		정렬하는 용도로만 사용한다.	*/
	t_DoublyListNode	*tmpNode;

	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);

	printf("\n\n== pop test\n");
	tmpNode = pop(a_stack);
	printf("tmpNode->data : %d\n", tmpNode->data);
	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);

	for (int i=1; i<=5; i++)
	{
		printf("\n\n== rotate_a %dth test\n", i);
		rotate(a_stack, A_STACK, TRUE);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
	}

	for (int i=1; i<=5; i++)
	{
		printf("\n\n== reverse_rotate_a %dth test\n", i);
		reverse_rotate(a_stack, A_STACK, TRUE);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
		printf("\n\n== swap %dth test\n", i);
		swap(a_stack, FALSE, A_STACK);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
	}

	printf("\n\n====== push_a test\n");
	push(a_stack, b_stack, B_STACK);
	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);

	while (a_stack->currentElementCount)
	{
		printf("\n\n====== push_b test\n");
		push(a_stack, b_stack, B_STACK);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
		printf("== displayDoublyList(b_stack)\n");
		displayDoublyList(b_stack);
		displayDoublyList(a_stack);
	}

	printf("\n\n====== push_a test\n");
	push(a_stack, b_stack, B_STACK);
	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);
	displayDoublyList(a_stack);

	printf("\n\n====== push_b test\n");
	push(a_stack, b_stack, B_STACK);
	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);
	displayDoublyList(a_stack);

	displayDoublyList(a_stack);
	for (int i=1; i<=3; i++)
	{
		printf("\n\n== swap %dth test\n", i);
		swap(a_stack, FALSE, A_STACK);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
		printf("\n\n====== swap_b test\n");
		swap(b_stack, FALSE, B_STACK);
		printf("== displayDoublyList(b_stack)\n");
		displayDoublyList(b_stack);
	}

	for (int i=1; i<=5; i++)
	{
		printf("\n\n== rotate_a %dth test\n", i);
		rotate(a_stack, A_STACK, TRUE);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
		printf("\n\n== swap %dth test\n", i);
		swap(a_stack, FALSE, A_STACK);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
	}

	displayDoublyList(a_stack);
	for (int i=1; i<=3; i++)
	{
		printf("\n\n== swap %dth test\n", i);
		swap(a_stack, FALSE, A_STACK);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
	}

	printf("\n=====================================================\n");
	printf("\n\n====== push_a test\n");
	push(b_stack, a_stack, A_STACK);
	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);
	printf("\n=====================================================\n");

	printf("\n=====================================================\n");
	printf("\n\n====== push_b test\n");
	for (int i=1; i<=3; i++)
	{
		printf("\n\n====== push_b %dth test\n", i);
		push(a_stack, b_stack, B_STACK);
		printf("\n== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
		printf("\n== displayDoublyList(b_stack)\n");
		displayDoublyList(b_stack);
	}

	printf("\n=====================================================\n");

	printf("\n\n== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("\n\n== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);

	for (int i=1; i<=3; i++)
	{
		printf("\n\n== swap %dth test\n", i);
		swap(a_stack, FALSE, A_STACK);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
	}

	for (int i=1; i<=3; i++)
	{
		printf("\n\n== swap_b %dth test\n", i);
		swap(b_stack, FALSE, B_STACK);
		printf("== displayDoublyList(b_stack)\n");
		displayDoublyList(b_stack);
	}

	swap_both(b_stack, b_stack);

	printf("\n\n== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("\n\n== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);

	printf("\n\n### Finally done\n");

	// size_t	cmd_cnt;
	return (0);
}
