/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:19 by jim               #+#    #+#             */
/*   Updated: 2022/01/25 13:33:23 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_DoublyList *stack)
{
    if (stack == NULL || stack->currentElementCount <= 1)
        return (print_error());
    stack->headerNode = stack->headerNode->pRLink;
}

void	rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
    rotate(a_stack);
    rotate(b_stack);
}
