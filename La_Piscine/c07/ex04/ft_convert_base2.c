/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:32:30 by haekang           #+#    #+#             */
/*   Updated: 2023/03/01 05:49:37 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	int_len(long buf, int base_len)
{
	int	len;

	len = 1;
	while (buf / base_len != 0)
	{
		len++;
		buf /= base_len;
	}
	return (len);
}

int	base_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' \
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
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

long	ft_atoi_base(char *str, char *base)
{
	int		flag;
	long	result;
	int		baselen;

	flag = 1;
	result = 0;
	baselen = base_check(base);
	if (baselen == 0)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	while (base_index (base, *str) != -1)
		result = result * baselen + base_index(base, *str++);
	return (result * flag);
}
