/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:55:40 by haekang           #+#    #+#             */
/*   Updated: 2023/06/27 03:37:38 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_coding_three(t_stack *stack)
{
	int	top;
	int	second;
	int	third;

	top = stack->top->next->content;
	second = stack->top->next->next->content;
	third = stack->top->next->next->next->content;
	1 2 3
	1 3 2
	2 1 3
	3 2 1
	2 3 1
	3 1 2
}

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

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *sorted_data)
{
	int	pivot[2];
	int	max_index_arr;

	max_index_arr = (stack_a->size - 1);
	pivot[0] = sorted_data[max_index_arr / 3];
	pivot[1] = sorted_data[(max_index_arr * 2) / 3];
	a_to_b(stack_a, stack_b, pivot[0]);
	a_to_b(stack_a, stack_b, pivot[1]);
	a_to_b(stack_a, stack_b, sorted_data[max_index_arr - 3]); // 제일 큰 수 3개가 스택 a에 남게될것임 정렬안된채로
	hard_coding_three(stack_a);

}
