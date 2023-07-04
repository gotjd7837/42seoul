/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:50:11 by haekang           #+#    #+#             */
/*   Updated: 2023/07/04 12:19:29 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_arr(t_stack *stack)
{
	t_node	*current_node;
	int		*arr;
	int		i;
	int		stack_size;

	i = 0;
	stack_size = stack->size;
	arr = (int *)malloc(sizeof(int) * stack_size);
	if (arr == NULL)
		return (NULL);
	current_node = stack->top->next;
	while (i < stack_size)
	{
		arr[i++] = current_node->content;
		current_node = current_node->next;
	}
	return (arr);
}

static long long	push_swap_atoi(const char *str)
{
	int			flag;
	long long	result;

	flag = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str++ - '0');
		else
			print_error(0);
	}
	return (result * flag);
}

static void	parse(t_stack *stack, char **split)
{
	t_node		*node;
	long long	arg;
	int			i;

	i = 0;
	while (split[i] != NULL)
	{
		arg = push_swap_atoi(split[i]);
		if (arg > 2147483647 || arg < -2147483648)
			print_error(0);
		node = new_node(arg);
		push_bottom_stack(stack, node);
		free(split[i]);
		i++;
	}
}

int	*arg_parsing(t_stack *stack, int ac, char *av[])
{
	int		i;
	char	**split;
	int		*stack_data;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		parse(stack, split);
		free(split);
		i++;
	}
	if (stack->size == 0)
		print_error(1);
	stack_data = stack_to_arr(stack);
	handle_arg_error(stack_data, stack->size);
	return (stack_data);
}
