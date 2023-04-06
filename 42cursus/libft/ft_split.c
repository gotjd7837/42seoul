/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:25:24 by haekang           #+#    #+#             */
/*   Updated: 2023/04/02 04:47:56 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*result_malloc(char *str, char c, char **result, int idx)
{
	int		len;

	len = 0;
	while (str[len] && !(*(str + len) == c))
		len++;
	result[idx] = (char *)malloc(sizeof(char) * (len + 1));
	if (result[idx] == NULL)
	{
		free(result);
		return (NULL);
	}
	ft_strlcpy(result[idx], str, (len + 1));
	return (result[idx]);
}

static char	**result_double_malloc(char *str, char c)
{
	int		cnt;
	char	**result;

	cnt = 0;
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		if (*str && !(*str == c))
		{
			cnt++;
			while (*str && !(*str == c))
				str++;
		}
	}
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	*arr;
	char	**result;
	int		i;

	i = 0;
	arr = (char *)s;
	result = result_double_malloc(arr, c);
	if (result == NULL)
		return (NULL);
	while (*arr)
	{
		while (*arr && (*arr == c))
			arr++;
		if (*arr && !(*arr == c))
		{
			result[i] = result_malloc(arr, c, result, i);
			i++;
			while (*arr && !(*arr == c))
				arr++;
		}
	}
	result[i] = NULL;
	return (result);
}
