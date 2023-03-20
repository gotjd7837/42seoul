/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:58:16 by seonmiki          #+#    #+#             */
/*   Updated: 2023/02/19 16:39:30 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	lf(char arr[6][6], int y, int x)
{
	int	cnt;
	int	max;

	while (++y <= 4)
	{
		x = 1;
		cnt = 1;
		max = arr[y][1];
		if (arr[y][1] != '4')
		{
			while (++x <= 4)
			{
				if (arr[y][x] > max)
				{
					cnt++;
					max = arr[y][x];
				}
				if (arr[y][x] == '4')
					break ;
			}
		}
		if (arr[y][0] != cnt + '0')
			return (0);
	}
	return (1);
}

int	ri(char arr[6][6], int y, int x)
{
	int	cnt;
	int	max;

	while (++y <= 4)
	{
		x = 4;
		cnt = 1;
		max = arr[y][4];
		if (arr[y][4] != '4')
		{
			while (--x >= 1)
			{
				if (arr[y][x] > max)
				{
					cnt++;
					max = arr[y][x];
				}
				if (arr[y][x] == '4')
					break ;
			}
		}
		if (arr[y][5] != cnt + '0')
			return (0);
	}
	return (1);
}

int	up(char arr[6][6], int y, int x)
{
	int	cnt;
	int	max;

	while (++x <= 4)
	{
		y = 1;
		cnt = 1;
		max = arr[1][x];
		if (arr[1][x] != '4')
		{
			while (++y <= 4)
			{
				if (arr[y][x] > max)
				{
					cnt++;
					max = arr[y][x];
				}
				if (arr[y][x] == '4')
					break ;
			}
		}
		if (arr[0][x] != cnt + '0')
			return (0);
	}
	return (1);
}

int	dw(char arr[6][6], int y, int x)
{
	int	cnt;
	int	max;

	while (++x <= 4)
	{
		y = 4;
		cnt = 1;
		max = arr[4][x];
		if (arr[4][x] != '4')
		{
			while (--y >= 1)
			{
				if (arr[y][x] > max)
				{
					cnt++;
					max = arr[y][x];
				}
				if (arr[y][x] == '4')
					break ;
			}
		}
		if (arr[5][x] != cnt + '0')
			return (0);
	}
	return (1);
}
