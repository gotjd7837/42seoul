/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:51:24 by seonmiki          #+#    #+#             */
/*   Updated: 2023/02/19 16:40:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	lf(char arr[6][6], int y, int x);
int	ri(char arr[6][6], int y, int x);
int	up(char arr[6][6], int y, int x);
int	dw(char arr[6][6], int y, int x);

int	ft_isokay(int dy, int dx, char arr[6][6])
{
	int	y;
	int	x;

	y = dy - 1;
	while (y >= 1)
	{
		if (arr[dy][dx] == arr[y][dx])
			return (0);
		y--;
	}
	x = dx - 1;
	while (x >= 1)
	{
		if (arr[dy][dx] == arr[dy][x])
			return (0);
		x--;
	}
	return (1);
}

void	ft_print_answer(char arr[6][6])
{
	int	y;
	int	x;

	y = 1;
	while (y <= 4)
	{
		x = 1;
		while (x <= 4)
		{
			write(1, &arr[y][x], 1);
			if (x != 4)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	ft_run(int y, int x, char arr[6][6], int *check)
{
	char	ch;

	if (*check == 1)
		return ;
	if (x == 1 && y == 5)
	{
		if (lf(arr, 0, 1) && ri(arr, 0, 4) && up(arr, 1, 0) && dw(arr, 4, 0))
		{
			ft_print_answer(arr);
			*check = 1;
		}
		return ;
	}
	ch = '0';
	while (++ch <= '4')
	{
		arr[y][x] = ch;
		if (ft_isokay(y, x, arr) == 1)
		{
			if (x != 4)
				ft_run(y, x + 1, arr, check);
			else
				ft_run(y + 1, 1, arr, check);
		}
	}
}
