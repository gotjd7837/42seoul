/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:46:24 by haekang           #+#    #+#             */
/*   Updated: 2023/06/14 21:17:14 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*init_stack(void);
t_node	*new_node(int content);
void	add_node(t_stack *stack, t_node *new_node);
void	*av_to_stack(t_stack *stack, int ac, char *av[]);

void

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac >= 2)
	{
		stack_a = init_stack();
		stack_b = init_stack();
		av_to_stack(stack_a, ac, av);
	}
	else
	{
		
	}
}
