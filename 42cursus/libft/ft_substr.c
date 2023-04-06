/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 06:47:31 by haekang           #+#    #+#             */
/*   Updated: 2023/03/29 10:13:58 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*arr;

	i = 0;
	if (ft_strlen(s) < len + start)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) > start)
	{
		arr = (char *)malloc(sizeof(char) * (len + 1));
		if (arr == NULL)
			return (NULL);
		while (s[start + i] && i < len)
		{
			arr[i] = s[start + i];
			i++;
		}
	}
	else
	{
		arr = (char *)malloc(sizeof(char));
		if (arr == NULL)
			return (NULL);
	}
	arr[i] = '\0';
	return (arr);
}
