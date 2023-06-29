/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:55:40 by haekang           #+#    #+#             */
/*   Updated: 2023/06/29 21:21:36 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare_instr_cnt(int *best_ra_c, int *best_rb_c, int ra_c, int rb_c)
{
	int	sum_current;
	int	sum_c;
	int	current_rb;
	int	current_ra;

	if (*best_ra_c < 0)
		current_ra = *best_ra_c * -1;
	else
		current_ra = *best_ra_c;
	if (*best_rb_c < 0)
		current_rb = *best_rb_c * -1;
	else
		current_rb = *best_rb_c;
	if (ra_c < 0)
		ra_c = ra_c * -1;
	if (rb_c < 0)
		rb_c = rb_c * -1;
	sum_current = current_ra + current_rb;
	sum_c = ra_c + rb_c;
	if (sum_c < sum_current)
		return (1);
	else
		return (0);
}

static void	best_instr_cnt(t_stack *a, t_stack *b, int *best_ra_c, int *best_rb_c)
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
		if (i == 0 || compare_instr_cnt(best_ra_c, best_rb_c, ra_c, rb_c))
		{
			*best_ra_c = ra_c;
			*best_rb_c = rb_c;
		}
		node = node->next;
		i++;
	}
}

static void	second_sort_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	best_ra_c;
	int	best_rb_c;

	best_ra_c = 0;
	best_rb_c = 0;
	while (stack_b->size != 0)
	{
		best_instr_cnt(stack_a, stack_b, &best_ra_c, &best_rb_c);
		rr_a_b(stack_a, stack_b, &best_ra_c, &best_rb_c);
		r_a(stack_a, &best_ra_c);
		r_b(stack_b, &best_rb_c);
		pa(stack_a, stack_b);
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *sorted_data)
{
	first_sort_stack_b(stack_a, stack_b, sorted_data);
	hard_coding_three(stack_a);
	second_sort_stack_a(stack_a, stack_b);
}
