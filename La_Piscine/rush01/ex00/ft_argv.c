/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:45:42 by seonmiki          #+#    #+#             */
/*   Updated: 2023/02/19 16:38:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_argv_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (i % 2 == 0 && !(argv[i] >= '1' && argv[i] <= '4'))
			return (0);
		else if (i % 2 == 1 && argv[i] != ' ')
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

void	ft_input_in_arr(char *argv, char arr[6][6])
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	while (++x <= 4)
	{
		arr[0][x] = argv[i];
		arr[5][x] = argv[i + 8];
		i += 2;
	}
	i = 16;
	y = 0;
	while (++y <= 4)
	{
		arr[y][0] = argv[i];
		arr[y][5] = argv[i + 8];
		i += 2;
	}
}
