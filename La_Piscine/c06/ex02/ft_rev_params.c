/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 04:58:01 by haekang           #+#    #+#             */
/*   Updated: 2023/02/26 06:36:10 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	(void)ac;
	i = 0;
	while (av[i])
		i++;
	i -= 1;
	while (i > 0)
	{
		j = 0;
		while (av[i][j])
		{
			write (1, &av[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i--;
	}
}
