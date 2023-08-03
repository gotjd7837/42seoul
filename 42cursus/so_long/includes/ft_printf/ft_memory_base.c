/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:49:34 by haekang           #+#    #+#             */
/*   Updated: 2023/04/27 20:51:55 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base_check(char *base)
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

static void	ft_putnbr(unsigned long nb, char *base, int *len)
{
	unsigned long	nbr;
	unsigned int	baselen;

	nbr = (unsigned long)nb;
	baselen = base_check(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= baselen)
	{
		ft_putnbr(nbr / baselen, base, len);
		write (1, &base[nbr % baselen], 1);
		(*len)++;
	}
	else
	{
		write (1, &base[nbr % baselen], 1);
		(*len)++;
	}
}

int	ft_memory_base(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	if (base_check(base) != 0)
		ft_putnbr(nbr, base, &len);
	return (len);
}
