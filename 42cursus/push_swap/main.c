/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:46:24 by haekang           #+#    #+#             */
/*   Updated: 2023/06/12 17:42:39 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->content = content;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);

	stack->top = new_node(0);
	stack->bottom = new_node(0);

	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;

	stack->size = 0;
	return (stack);
}

int	main(int ac, char *av[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*arg_arr;

	if (ac < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	arg_arr = get_arg_arr();
}
