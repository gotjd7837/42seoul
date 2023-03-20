/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:38:31 by haekang           #+#    #+#             */
/*   Updated: 2023/02/16 13:09:21 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sumjo(char	*arr, int n, int depth, int input_num)
{
	int	i;

	i = 0;
	if (depth == n)
	{
		while (i < n)
		{
			write(1, arr, 1);
			i++;
			arr++;
		}
		if (*(arr - n) != '0' + (10 - n))
		{
			write(1, ", ", 2);
		}
	}
	else
	{
		while (input_num < 10)
		{
			arr[depth] = '0' + input_num;
			input_num++;
			sumjo(arr, n, depth + 1, input_num);
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	sumjo(arr, n, 0, 0);
}
/*
int	main(void)
{
	ft_print_combn(9);
}*/
