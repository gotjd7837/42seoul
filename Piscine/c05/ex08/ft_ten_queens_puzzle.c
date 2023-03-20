/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:05:38 by haekang           #+#    #+#             */
/*   Updated: 2023/02/26 19:17:46 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	chk_condi(char *arr, int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		if (arr[depth] == arr[i])
			return (0);
		else if (arr[depth] - arr[i] == depth - i \
			|| arr[i] - arr[depth] == depth - i)
			return (0);
		i++;
	}
	return (1);
}

void	dfs(char *arr, int depth, int *cnt)
{
	char	col;

	col = '0';
	if (depth == 10)
	{
		write(1, arr, 10);
		write(1, "\n", 1);
		*cnt += 1;
		return ;
	}
	while (col >= '0' && col <= '9')
	{
		arr[depth] = col;
		if (chk_condi(arr, depth) == 1)
			dfs(arr, depth + 1, cnt);
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	arr[10];
	int		cnt;

	cnt = 0;
	dfs(arr, 0, &cnt);
	return (cnt);
}
