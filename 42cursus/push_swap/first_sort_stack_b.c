/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:43:34 by haekang           #+#    #+#             */
/*   Updated: 2023/06/27 16:50:37 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	i;
	int	top;

	i = 0;
	while (i < stack_a->size)
	{
		top = stack_a->top->next->content;
		if (top <= pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void	first_sort_stack_b(t_stack *stack_a, t_stack *stack_b, int *sorted_data)
{
	int	pivot[2];
	int	max_index_arr;

	max_index_arr = (stack_a->size - 1);
	pivot[0] = sorted_data[max_index_arr / 3];
	pivot[1] = sorted_data[(max_index_arr * 2) / 3];
	a_to_b(stack_a, stack_b, pivot[0]);
	a_to_b(stack_a, stack_b, pivot[1]);
	a_to_b(stack_a, stack_b, sorted_data[max_index_arr - 3]);
}
