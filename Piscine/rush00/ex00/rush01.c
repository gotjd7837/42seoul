/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranchoi <ranchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:08:14 by ranchoi           #+#    #+#             */
/*   Updated: 2023/02/12 12:11:09 by ranchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_rush(int x, char begin, char middle, char end)
{
	int	x_cnt;

	x_cnt = 1;
	while (x_cnt <= x)
	{
		if (x_cnt == 1)
			ft_putchar(begin);
		else if (x_cnt == x)
			ft_putchar(end);
		else
			ft_putchar(middle);
		x_cnt++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	y_cnt;

	y_cnt = 1;
	while (y_cnt <= y)
	{
		if (y_cnt == 1)
			print_rush(x, '/', '*', '\\');
		else if (y_cnt == y)
			print_rush(x, '\\', '*', '/');
		else
			print_rush(x, '*', ' ', '*');
		y_cnt++;
	}
}
