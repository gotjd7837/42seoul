/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:46:24 by haekang           #+#    #+#             */
/*   Updated: 2023/06/22 19:13:41 by haekang          ###   ########.fr       */
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
	}
	else
		print_error(0);
}
