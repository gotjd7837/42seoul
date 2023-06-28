/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:51:02 by haekang           #+#    #+#             */
/*   Updated: 2023/06/28 17:15:58 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_duplicates_checker(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				print_error(0);
			j++;
		}
		i++;
	}
}

void	arr_sort_checker(int *arr, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (arr[i] < arr[i - 1])
			return ;
		i++;
	}
	print_error(0);
}

void	handle_arg_error(int *stack_data, int size)
{
	arr_sort_checker(stack_data, size);
	quick_sort_arr(stack_data, 0, size - 1);
	arr_duplicates_checker(stack_data, size);
}
