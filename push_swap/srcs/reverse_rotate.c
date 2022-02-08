/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:14 by jim               #+#    #+#             */
/*   Updated: 2022/01/25 13:33:17 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_DoublyList *stack)
{
    if (stack == NULL || stack->currentElementCount <= 1)
        return (print_error());
    stack->tailerNode = stack->tailerNode->pLLink;
}

void	reverse_rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
    reverse_rotate(a_stack);
    reverse_rotate(b_stack);
}
