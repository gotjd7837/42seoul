/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:51:02 by haekang           #+#    #+#             */
/*   Updated: 2023/06/30 20:51:39 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arr_sort_checker(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] < arr[i - 1])
			return ;
		i++;
	}
	print_error(1);
}


static void	arr_duplicates_checker(int *arr, int size)
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

void	handle_arg_error(int *stack_data, int size)
{
	int	i;
	int	*sort_check_arr;

	i = 0;
	sort_check_arr = (int *)malloc(sizeof(int) * size);
	if (sort_check_arr == NULL)
		print_error(0);
	while (i < size)
	{
		sort_check_arr[i] = stack_data[i];
		i++;
	}
	quick_sort_arr(stack_data, 0, size - 1);
	arr_duplicates_checker(stack_data, size);
	arr_sort_checker(sort_check_arr, size);
	free(sort_check_arr);//다른거 릭도 잡아야함
}
//중복처리가 안되는 상황임 수정 필요
//중복처리가 5 이상은 되는데 그 이하는 안됨 하드 코딩 파트가 문제인듯 ?
//정확히는 1 2 3 4 가 안됨 ;;