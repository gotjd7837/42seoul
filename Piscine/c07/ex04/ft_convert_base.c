/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:32:26 by haekang           #+#    #+#             */
/*   Updated: 2023/03/01 05:35:57 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		base_index(char *base, char c);
int		base_check(char *base);
long	ft_atoi_base(char *str, char *base);
int		str_len(char *str);
int		int_len(long buf, int base_len);

char	*str_rev(char *str)
{
	int		i;
	int		j;
	int		size;
	char	tmp;
	int		buf;

	j = 0;
	size = str_len(str);
	buf = size - 1;
	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	while (j < (size / 2))
	{
		tmp = str[i];
		str[i] = str[buf];
		str[buf] = tmp;
		i++;
		j++;
		buf--;
	}
	return (str);
}

void	ft_itoa_base(long nb, char *base, char *cv_nbr, int dp)
{
	int	baselen;

	baselen = base_check(base);
	if (nb < 0)
	{
		cv_nbr[dp++] = '-';
		nb = -nb;
	}
	if (nb >= baselen)
	{
		ft_itoa_base(nb / baselen, base, cv_nbr, dp + 1);
		cv_nbr[dp] = base[nb % baselen];
	}
	else
	{
		cv_nbr[dp] = base[nb % baselen];
	}
}

char	*cv_nbr_malloc(int buf, int len)
{
	char	*cv_nbr;

	if (buf < 0)
	{
		cv_nbr = (char *)malloc(sizeof(char) * (len + 2));
		cv_nbr[len + 1] = '\0';
	}
	else
	{
		cv_nbr = (char *)malloc(sizeof(char) * (len + 1));
		cv_nbr[len] = '\0';
	}
	return (cv_nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*cv_nbr;
	long	buf;
	int		len;

	if (base_check(base_from) == 0 || base_check(base_to) == 0)
		return (0);
	buf = ft_atoi_base(nbr, base_from);
	len = int_len(buf, base_check(base_to));
	cv_nbr = cv_nbr_malloc(buf, len);
	if (!cv_nbr)
		return (0);
	ft_itoa_base(buf, base_to, cv_nbr, 0);
	str_rev(cv_nbr);
	return (cv_nbr);
}
