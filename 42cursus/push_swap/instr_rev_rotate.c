/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:59:36 by haekang           #+#    #+#             */
/*   Updated: 2023/06/28 20:22:00 by haekang          ###   ########.fr       */
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
	write(1, "rra\n", 3);
}

void	rrb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_bottom_stack(stack_b);
	if (node == NULL)
		return ;
	push_top_stack(stack_b, node);
	write(1, "rrb\n", 3);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
