/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:55:40 by haekang           #+#    #+#             */
/*   Updated: 2023/06/27 21:06:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_instr_cnt(int *best_ra_c, int *best_rb_c, int ra_c, int rb_c)
{
	int	sum_best;
	int	sum_c;
	int	best_rrb_c;
	int	current_rrb;

	if (*best_rb_c < 0)
	{
		best_rrb_c = *best_rb_c * -1;
		sum_best = *best_ra_c + best_rrb_c;
	}
	else
		sum_best = *best_ra_c + *best_rb_c;
	if (rb_c < 0)
	{
		current_rrb = rb_c * -1;
		sum_c = ra_c + current_rrb;
	}
	else
		sum_c = ra_c + rb_c;
	if (sum_c < sum_best)
		return (1);
	else
		return (0);
}

int	count_ra(t_stack *stack_a, int content)
{
	
}

void	best_instr_cnt(t_stack *a, t_stack *b, int *best_ra_c, int *best_rb_c)
{
	int		i;
	int		ra_c;
	int		rb_c;
	t_node	*node;

	i = 0;
	node = b->top->next;
	while (i < b->size)
	{
		ra_c = count_ra(a, node->content);
		if (i > (b->size / 2))
			rb_c = (b->size - i) * -1;
		else
			rb_c = i;
		if (i == 0 || compare_instr_cnt(best_ra_c, best_rb_c, ra_c, rb_c) == 1)
		{
			*best_ra_c = ra_c;
			*best_rb_c = rb_c;
		}
		node = node->next;
	}
}

void	second_sort_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	best_ra_c;
	int	best_rb_c;

	best_ra_c = 0;
	best_rb_c = 0;
	best_instr_cnt(stack_a, stack_b, &best_ra_c, &best_rb_c);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *sorted_data)
{
	first_sort_stack_b(stack_a, stack_b, sorted_data);
	hard_coding_three(stack_a);
	second_sort_stack_a(stack_a, stack_b);


}
