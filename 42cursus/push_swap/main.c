/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:46:24 by haekang           #+#    #+#             */
/*   Updated: 2023/06/14 15:41:22 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*init_stack(void);
t_node	*new_node(int content);
void	add_node(t_stack *stack, t_node *new_node);

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac >= 2)
	{
		stack_a = ft_atoi("123");
	}
	else
	{
		
	}
}
