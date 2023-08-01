/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:38:50 by haekang           #+#    #+#             */
/*   Updated: 2023/08/01 19:06:35 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

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
