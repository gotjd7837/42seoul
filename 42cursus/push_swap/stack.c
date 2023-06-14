/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:35:19 by haekang           #+#    #+#             */
/*   Updated: 2023/06/14 15:21:21 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_stack *stack, t_node *new_node)
{
	t_node	*added_node;
	int		i;

	i = 0;
	if (stack->size == 0)
	{
		stack->top->next = new_node;
		stack->bottom->prev = new_node;
		new_node->prev = stack->top;
		new_node->next = stack->bottom;
		stack->size += 1;
	}
	else
	{
		added_node = stack->top;
		while (i++ < stack->size)
			added_node = added_node->next;
		added_node->next = new_node;
		new_node->prev = added_node;
		new_node->next = stack->bottom;
		stack->size += 1;
	}
}

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
