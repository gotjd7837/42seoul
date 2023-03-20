/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:26:34 by haekang           #+#    #+#             */
/*   Updated: 2023/02/16 13:08:36 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	str[5];

	str[0] = '0';
	str[3] = ',';
	str[4] = ' ';
	while (str[0] <= '7')
	{
		str[1] = str[0] + 1;
		while (str[1] <= '8')
		{
			str[2] = str[1] + 1;
			if (str[0] == '7')
			{
				write(1, str, 3);
				return ;
			}
			while (str[2] <= '9')
			{
				write(1, str, 5);
				str[2]++;
			}
			str[1]++;
		}
		str[0]++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
}*/
