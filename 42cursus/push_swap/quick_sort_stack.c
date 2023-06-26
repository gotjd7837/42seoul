/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:55:40 by haekang           #+#    #+#             */
/*   Updated: 2023/06/26 17:50:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition()
{
}

void	quick_sort_stack(t_stack *stack_a, t_stack *stack_b, int right)
{
	if (right <= 3)
	{
		hardcoding;
		return ;
	}
	int	pushed;

	pushed = partition(stack_a, stack_b, right);  // ㅇㅕ기서 나나눠눠줌줌
	quick_sort_stack(stack_a, stack_b, (pushed - 1));
	// quick_sort_stack(stack_a, stack_b, ())
	
}
-----------------------------------------------------------------------
void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= (high - 1))
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort_arr(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort_arr(arr, low, pi - 1);
		quick_sort_arr(arr, pi + 1, high);
	}
}