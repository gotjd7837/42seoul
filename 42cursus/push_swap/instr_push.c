/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:37:25 by haekang           #+#    #+#             */
/*   Updated: 2023/06/21 16:06:39 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_b->size == 0)
		return ;
	node = pop_top_stack(stack_b);
	push_top_stack(stack_a, node);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_a->size == 0)
		return ;
	node = pop_top_stack(stack_a);
	push_top_stack(stack_b, node);
}
