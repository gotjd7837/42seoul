/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:24:31 by haekang           #+#    #+#             */
/*   Updated: 2023/03/29 10:44:08 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str_cpy(const char *s1, const char *s2, char *arr)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*arr;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (arr == NULL)
		return (NULL);
	ft_str_cpy(s1, s2, arr);
	return (arr);
}
