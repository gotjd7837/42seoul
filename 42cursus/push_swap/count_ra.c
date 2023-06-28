/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:18:08 by haekang           #+#    #+#             */
/*   Updated: 2023/06/28 21:27:26 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_min_idx_or_val(t_stack *stack, int sign)
{
	int		i;
	int		min;
	int		min_idx;
	t_node	*node;

	i = 0;
	node = stack->top->next;
	while (i < stack->size)
	{
		if (i == 0 || node->content < min)
		{
			min = node->content;
			min_idx = i;
		}
		i++;
		node = node->next;
	}
	if (sign == 0)
	{
		if (min_idx > (stack->size / 2))
			return ((stack->size - min_idx) * -1);
		return (min_idx);
	}
	else
		return (min);
}

static int	return_max_idx_or_val(t_stack *stack, int sign)
{
	int		i;
	int		max;
	int		max_idx;
	t_node	*node;

	i = 0;
	node = stack->top->next;
	while (i < stack->size)
	{
		if (i == 0 || node->content > max)
		{
			max = node->content;
			max_idx = i;
		}
		i++;
		node = node->next;
	}
	if (sign == 0)
	{
		if (max_idx > (stack->size / 2))
			return ((stack->size - max_idx) * -1);
		return (max_idx);
	}
	else
		return (max);
}

int	count_ra(t_stack *stack_a, int b_content)
{
	int		i;
	int		max;
	int		min;
	t_node	*node;

	i = 0;
	max = return_max_idx_or_val(stack_a, 1);
	min = return_min_idx_or_val(stack_a, 1);
	if (max < b_content || min > b_content)
		return (return_min_idx_or_val(stack_a, 0));
	if (stack_a->top->next->content > b_content && \
		stack_a->bottom->prev->content < b_content)
		return (0);
	node = stack_a->top->next;
	while (i < stack_a->size)
	{
		if (node->content > b_content && node->prev->content < b_content)
			break ;
		i++;
		node = node->next;
	}
	if (i > (stack_a->size / 2))
		return ((stack_a->size - i) * -1);
	return (i);
}
