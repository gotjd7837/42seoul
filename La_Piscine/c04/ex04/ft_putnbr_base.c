/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:24:32 by haekang           #+#    #+#             */
/*   Updated: 2023/02/24 02:08:15 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1 || i == 0)
		return (0);
	return (i);
}

void	ft_putnbr(int nb, char *base)
{
	long long	nbr;
	int			baselen;

	nbr = (long long)nb;
	baselen = base_check(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= baselen)
	{
		ft_putnbr(nbr / baselen, base);
		write (1, &base[nbr % baselen], 1);
	}
	else
	{
		write (1, &base[nbr % baselen], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (base_check(base) != 0)
		ft_putnbr(nbr, base);
}
