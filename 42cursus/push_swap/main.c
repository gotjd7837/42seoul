/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:46:24 by haekang           #+#    #+#             */
/*   Updated: 2023/06/29 20:43:36 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_data;

	if (ac > 2)
	{
		stack_a = init_stack();
		stack_b = init_stack();
		sorted_data = arg_parsing(stack_a, ac, av);
		if (stack_a->size <= 3)
		{
			hard_coding_three(stack_a);
			return (0);
		}
		sort_stack(stack_a, stack_b, sorted_data);
		
		printf("------------- 정렬한 스택값 -------------\n\n\n");
		printf("%d\n", stack_a->top->next->content);
		printf("%d\n", stack_a->top->next->next->content);
		printf("%d\n", stack_a->top->next->next->next->content);
		printf("%d\n", stack_a->top->next->next->next->next->content);
		printf("%d\n", stack_a->top->next->next->next->next->next->content);
		printf("%d\n", stack_a->top->next->next->next->next->next->next->content);
		printf("%d\n", stack_a->top->next->next->next->next->next->next->next->content);
		printf("%d\n", stack_a->top->next->next->next->next->next->next->next->next->content);
		printf("%d\n", stack_a->top->next->next->next->next->next->next->next->next->next->content);
		printf("-------------정렬한 스택값 -------------\n");
	}
	else
		print_error(0);
	return (0);
}
