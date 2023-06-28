/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 04:15:56 by haekang           #+#    #+#             */
/*   Updated: 2023/06/28 19:15:48 by haekang          ###   ########.fr       */
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

void	hard_coding_three(t_stack *stack)
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
