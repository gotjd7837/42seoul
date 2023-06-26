/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:55:40 by haekang           #+#    #+#             */
/*   Updated: 2023/06/27 04:23:45 by haekang          ###   ########.fr       */
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
	hard_coding_three(stack_a); //제일 큰 수 3개 정렬 완료 ~
	//그리디 알고리즘을 사용해서 스택 b에 있는 원소를 정렬하면서 옮긴다

}
