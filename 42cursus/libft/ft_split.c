/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:25:24 by haekang           #+#    #+#             */
/*   Updated: 2023/04/07 17:48:04 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static char *result_malloc(char *str, char c, char **result, int idx)
{
    int len = 0;

    while (str[len] && str[len] != c)
        len++;
    result[idx] = (char *)malloc(sizeof(char) * (len + 1));
    if (result[idx] == NULL)
    {
        while (--idx >= 0)
			free(result[idx]);
        free(result);
        return (NULL);
    }
    ft_strlcpy(result[idx], str, len + 1);
    return (result[idx]);
}

static char **result_double_malloc(char *str, char c)
{
    int cnt = 0;
    char **result;

    while (*str)
    {
        if (*str != c)
        {
            cnt++;
            while (*str && *str != c)
                str++;
        }
        else
            str++;
    }
    result = (char **)malloc(sizeof(char *) * (cnt + 1));
    if (!result)
        return (NULL);
    return (result);
}

char **ft_split(char const *s, char c)
{
    char *arr = (char *)s;
    char **result;
    int i = 0;

    if (!s)
        return (NULL);
    result = result_double_malloc(arr, c);
    if (result == NULL)
        return (NULL);
    while (*arr)
    {
        if (*arr != c)
        {
            if (result_malloc(arr, c, result, i++) == NULL)
                return (NULL);
            while (*arr && *arr != c)
				arr++;
		}
		else
			arr++;
	}
	result[i] = NULL;
	return (result);
}
