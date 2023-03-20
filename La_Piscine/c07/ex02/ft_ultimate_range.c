/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:30:13 by haekang           #+#    #+#             */
/*   Updated: 2023/02/28 22:52:07 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	long long	len;

	i = 0;
	len = max - min;
	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * len);
	if (!(*range))
		return (-1);
	while (i < len)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (len);
}
