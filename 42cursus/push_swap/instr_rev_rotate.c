/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:59:36 by haekang           #+#    #+#             */
/*   Updated: 2023/06/21 16:05:54 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*node;

	node = pop_bottom_stack(stack_a);
	if (node == NULL)
		return ;
	push_top_stack(stack_a, node);
}

void	rrb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_bottom_stack(stack_b);
	if (node == NULL)
		return ;
	push_top_stack(stack_b, node);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
