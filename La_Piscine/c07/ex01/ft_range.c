/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 05:52:01 by haekang           #+#    #+#             */
/*   Updated: 2023/03/01 01:11:31 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			i;
	long long	len;
	int			*arr;

	if (min >= max)
		return (0);
	len = max - min;
	i = 0;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	while (i < len)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
