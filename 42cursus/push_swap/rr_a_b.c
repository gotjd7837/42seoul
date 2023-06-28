/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_a_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:24:44 by haekang           #+#    #+#             */
/*   Updated: 2023/06/28 15:44:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_b(t_stack *stack_b, int *best_rb_c)
{
	int	i;

	i = 0;
	while (i < *best_rb_c)
	{
		rb(stack_b);
		write(1, "rb\n", 3);
		i++;
	}
}

void	r_a(t_stack *stack_a, int *best_ra_c)
{
	int	i;

	i = 0;
	while (i < *best_ra_c)
	{
		rb(stack_a);
		write(1, "ra\n", 3);
		i++;
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
