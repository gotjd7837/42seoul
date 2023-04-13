/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:24:31 by haekang           #+#    #+#             */
/*   Updated: 2023/04/13 17:41:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*arr;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (arr == NULL)
		return (NULL);
	arr[i + j] = '\0';
	while (--j >= 0)
		arr[i + j] = s2[j];
	while (--i >= 0)
		arr[i] = s1[i];
	return (arr);
}
