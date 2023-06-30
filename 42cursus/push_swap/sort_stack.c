/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:55:40 by haekang           #+#    #+#             */
/*   Updated: 2023/06/30 20:16:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last_sort_stack(t_stack *stack_a)
{
	int	min_idx;

	min_idx = return_min_idx_or_val(stack_a, 0);
	if (min_idx < 0)
	{
		while (min_idx)
		{
			rra(stack_a);
			min_idx += 1;
		}
	}
	else
	{
		while (min_idx)
		{
			ra(stack_a);
			min_idx -= 1;
		}
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *sorted_data)
{
	first_sort_stack(stack_a, stack_b, sorted_data);
	hard_coding_three(stack_a);
	second_sort_stack(stack_a, stack_b);
	last_sort_stack(stack_a);
}
