/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:37:46 by haekang           #+#    #+#             */
/*   Updated: 2023/04/07 16:50:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*arr_s;

	arr_s = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if ((unsigned char *)dst <= arr_s)
	{
		while (i < len)
		{
			*((unsigned char *)dst + i) = *(arr_s + i);
			i++;
		}
	}
	else
	{
		dst += len;
		arr_s += len;
		while (i++ < len)
			*((char *)--dst) = *(--arr_s);
	}
	return (dst);
}
