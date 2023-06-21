/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:08:20 by haekang           #+#    #+#             */
/*   Updated: 2023/06/21 16:00:02 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*top_node;
	t_node	*second_node;

	if (stack_a->size == 0)
		return ;
	top_node = pop_top_stack(stack_a);
	second_node = pop_top_stack(stack_a);
	push_top_stack(stack_a, top_node);
	push_top_stack(stack_a, second_node);
}

void	sb(t_stack *stack_b)
{
	t_node	*top_node;
	t_node	*second_node;

	if (stack_b->size == 0)
		return ;
	top_node = pop_top_stack(stack_b);
	second_node = pop_top_stack(stack_b);
	push_top_stack(stack_b, top_node);
	push_top_stack(stack_b, second_node);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
