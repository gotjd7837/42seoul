/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_a_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:24:44 by haekang           #+#    #+#             */
/*   Updated: 2023/06/29 17:01:29 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_b(t_stack *stack_b, int *best_rb_c)
{
	while (*best_rb_c == 0)
	{
		if (*best_rb_c < 0)
		{
			rrb(stack_b);
			*best_rb_c += 1;
		}
		else
		{
			rb(stack_b);
			*best_rb_c -= 1;
		}
	}
}

void	r_a(t_stack *stack_a, int *best_ra_c)
{
	while (*best_ra_c == 0)
	{
		if (*best_ra_c < 0)
		{
			rra(stack_a);
			*best_ra_c += 1;
		}
		else
		{
			ra(stack_a);
			*best_ra_c -= 1;
		}
	}
}

// void	rr_a_b(t_stack *stack_a, t_stack *stack_b, int *ra_c, int *rb_c);
// {
// 	int	rr_c;

// 	if (*ra_c == *rb_c)
// 		rr_c = *ra_c;
// 	else if (*ra_c < *rb_c)
// 	{
// 		rr_c = *ra_c;
// 	}
// 	else if (*rb_c < *rb_c)
// 	{
// 		rr_c = *rb_c;
// 	}
// }
