/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 06:09:51 by haekang           #+#    #+#             */
/*   Updated: 2023/02/24 02:08:13 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (base[i] == '+' || base[i] == '-' || (*base >= 9 && *base <= 13))
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

int	ft_atoi_base(char *str, char *base)
{
	int	flag;
	int	result;
	int	baselen;

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
