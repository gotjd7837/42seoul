/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:35:19 by haekang           #+#    #+#             */
/*   Updated: 2023/06/20 19:44:59 by haekang          ###   ########.fr       */
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

void	push_top_stack(t_stack *stack, t_node *ph_node)
{
	if (stack->size == 0)
	{
		stack->top->next = ph_node;
		stack->bottom->prev = ph_node;
		ph_node->prev = stack->top;
		ph_node->next = stack->bottom;
		stack->size += 1;
	}
	else
	{
		stack->top->next->prev = ph_node;
		ph_node->next = stack->top->next;
		stack->top->next = ph_node;
		ph_node->prev = stack->top;
		stack->size += 1;
	}
}

void	push_bottom_stack(t_stack *stack, t_node *ph_node)
{
	if (stack->size == 0)
	{
		stack->top->next = ph_node;
		stack->bottom->prev = ph_node;
		ph_node->prev = stack->top;
		ph_node->next = stack->bottom;
		stack->size += 1;
	}
	else
	{
		stack->bottom->prev->next = ph_node;
		ph_node->prev = stack->bottom->prev;
		stack->bottom->prev = ph_node;
		ph_node->next = stack->bottom;
		stack->size += 1;
	}
}

t_node	*pop_top_stack(t_stack *stack)
{
	t_node	*pop_node;

	pop_node = stack->top->next;
	if (stack->size == 0)
		return (NULL);
	else
	{
		pop_node->next->prev = stack->top;
		stack->top->next = pop_node->next;
		pop_node->prev = NULL;
		pop_node->next = NULL;
		stack->size -= 1;
		return (pop_node);
	}
}

t_node	*pop_bottom_stack(t_stack *stack)
{
	t_node	*pop_node;

	pop_node = stack->bottom->prev;
	if (stack->size == 0)
		return (NULL);
	else
	{
		pop_node->prev->next = stack->bottom;
		stack->bottom->prev = pop_node->prev;
		pop_node->prev = NULL;
		pop_node->next = NULL;
		stack->size -= 1;
		return (pop_node);
	}
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
