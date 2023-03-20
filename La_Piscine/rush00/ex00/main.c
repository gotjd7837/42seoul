/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranchoi <ranchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:03:31 by ranchoi           #+#    #+#             */
/*   Updated: 2023/02/12 21:28:49 by ranchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{	
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647)
			return (-1);
		i++;
	}
	if (str[i] == '\0')
		return (result);
	else
		return (-1);
}

int	main(int ac, char **av)
{
	int	x;
	int	y;

	if (ac == 3)
	{
		x = ft_atoi(av[1]);
		y = ft_atoi(av[2]);
		if (x < 1 || y < 1)
		{
			write(1, "wrong value :( \n", 16);
			return (-1);
		}
		rush(x, y);
	}
	else
	{
		write(1, "wrong number of arguments! :( \n", 31);
		return (-1);
	}
	return (0);
}
