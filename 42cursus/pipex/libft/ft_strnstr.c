/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:25:09 by haekang           #+#    #+#             */
/*   Updated: 2023/03/29 03:20:42 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		i = 0;
		while ((needle[i] == haystack[j + i]) && needle[i] != '\0' \
			&& i + j < len)
			i++;
		if (needle[i] == '\0')
			return ((char *)(haystack + j));
		j++;
	}
	return (NULL);
}
