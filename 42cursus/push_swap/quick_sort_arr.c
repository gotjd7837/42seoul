/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:49:58 by haekang           #+#    #+#             */
/*   Updated: 2023/06/27 19:51:44 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_sort_arr(int *arr, int L, int R)
{
	int	left;
	int	right;
	int	pivot;

	left = L;
	right = R;
	pivot = arr[(L + R) / 2];
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	if (L < right)
		quick_sort_arr(arr, L, right);
	if (left < R)
		quick_sort_arr(arr, left, R);
}
