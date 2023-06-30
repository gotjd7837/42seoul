/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 04:15:56 by haekang           #+#    #+#             */
/*   Updated: 2023/06/30 20:05:19 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *stack, int top, int second, int third)
{
	if (top < second && second < third)
		return ;
	else if (top < third && third < second)
	{
		sa(stack);
		ra(stack);
	}
	else if (second < top && top < third)
		sa(stack);
	else if (third < second && second < top)
	{
		sa(stack);
		ra(stack);
		ra(stack);
	}
	else if (second < third && third < top)
		ra(stack);
	else if (third < top && top < second)
	{
		ra(stack);
		ra(stack);
	}
}

static void	hard_coding_three(t_stack *stack)
{
	int	top;
	int	second;
	int	third;

	if (stack->size == 3)
	{
		top = stack->top->next->content;
		second = stack->top->next->next->content;
		third = stack->top->next->next->next->content;
		sort_three(stack, top, second, third);
	}
	else if (stack->size == 2)
	{
		top = stack->top->next->content;
		second = stack->top->next->next->content;
		if (top > second)
			sa(stack);
		else
			return ;
	}
	else
		return ;
}

static void	hard_coding_fourth(t_stack *stack_a, t_stack *stack_b)
{
	int	min_idx;

	min_idx = return_min_idx_or_val(stack_a, 0);
	r_a(stack_a, &min_idx);
	pb(stack_a, stack_b);
	hard_coding_three(stack_a);
	pa(stack_a, stack_b);
}

static void	hard_coding_fifth(t_stack *stack_a, t_stack *stack_b)
{
	int	min_idx;

	min_idx = return_min_idx_or_val(stack_a, 0);
	r_a(stack_a, &min_idx);
	pb(stack_a, stack_b);
	hard_coding_fourth(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	hard_coding(t_stack *stack_a, t_stack *stack_b, int a_size)
{
	if (a_size <= 3)
		hard_coding_three(stack_a);
	else if (a_size == 4)
		hard_coding_fourth(stack_a, stack_b);
	else if (a_size == 5)
		hard_coding_fifth(stack_a, stack_b);
}
