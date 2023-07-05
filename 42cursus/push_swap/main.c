/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:46:24 by haekang           #+#    #+#             */
/*   Updated: 2023/07/05 14:55:06 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_free(t_stack *stack)
{
	int		i;
	t_node	*node;
	t_node	*tmp;

	i = 0;
	node = stack->top->next;
	while (i < stack->size)
	{
		tmp = node->next;
		free(node);
		node = tmp;
		i++;
	}
	free(stack->top);
	free(stack->bottom);
	free(stack);
}

static void	push_swap_free(int *sorted_data, t_stack *stack_a, t_stack *stack_b)
{
	free(sorted_data);
	stack_free(stack_a);
	stack_free(stack_b);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_data;

	if (ac >= 2)
	{
		stack_a = init_stack();
		stack_b = init_stack();
		sorted_data = arg_parsing(stack_a, ac, av);
		if (stack_a->size <= 5)
		{
			hard_coding(stack_a, stack_b, stack_a->size);
			push_swap_free(sorted_data, stack_a, stack_b);
			return (0);
		}
		sort_stack(stack_a, stack_b, sorted_data);
		push_swap_free(sorted_data, stack_a, stack_b);
	}
	else
		print_error(1);
	return (0);
}
