/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:43:34 by haekang           #+#    #+#             */
/*   Updated: 2023/06/30 20:06:25 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pb_except_three(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (stack_a->size <= 3)
		return ;
	while (stack_a->size > 3)
		pb(stack_a, stack_b);
}

static void	a_to_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	i;
	int	size;
	int	top;

	i = 0;
	size = stack_a->size;
	while (i < size)
	{
		top = stack_a->top->next->content;
		if (top <= pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void	first_sort_stack(t_stack *a, t_stack *b, int *sorted_data)
{
	int	pivot[2];
	int	max_index_arr;

	max_index_arr = (a->size - 1);
	pivot[0] = sorted_data[max_index_arr / 3];
	pivot[1] = sorted_data[(max_index_arr * 2) / 3];
	a_to_b(a, b, pivot[0]);
	a_to_b(a, b, pivot[1]);
	pb_except_three(a, b);
}
