/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:47:20 by haekang           #+#    #+#             */
/*   Updated: 2023/06/28 20:21:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*node;

	node = pop_top_stack(stack_a);
	if (node == NULL)
		return ;
	push_bottom_stack(stack_a, node);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_top_stack(stack_b);
	if (node == NULL)
		return ;
	push_bottom_stack(stack_b, node);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
