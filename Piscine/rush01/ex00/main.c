/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:31:13 by seonmiki          #+#    #+#             */
/*   Updated: 2023/02/19 16:41:18 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_argv_check(char *argv);
void	ft_input_in_arr(char *argv, char arr[6][6]);
void	ft_run(int y, int x, char arr[6][6], int *check);

int	main(int argc, char **argv)
{
	char	arr[6][6];
	int		check;

	if (argc == 2)
	{
		if (ft_argv_check(argv[1]) == 1)
		{
			ft_input_in_arr(argv[1], arr);
			check = 0;
			ft_run(1, 1, arr, &check);
			if (check == 0)
				write(1, "Error\n", 6);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
