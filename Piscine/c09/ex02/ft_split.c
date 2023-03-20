/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:48:44 by haekang           #+#    #+#             */
/*   Updated: 2023/03/02 05:49:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	charset_ck(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	**arr_cnt_malloc(char *str, char *charset)
{
	char	**arr;
	int		cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && (charset_ck(*str, charset) == 1))
			str++;
		if (*str && (charset_ck(*str, charset) == 0))
		{
			cnt++;
			while (*str && (charset_ck(*str, charset) == 0))
				str++;
		}
	}
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	return (arr);
}

char	*arr_malloc(char *str, char *charset)
{
	char	*arr;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[len] && (charset_ck(str[len], charset) == 0))
		len++;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;

	i = 0;
	arr = arr_cnt_malloc(str, charset);
	while (*str)
	{
		while (*str && (charset_ck(*str, charset) == 1))
			str++;
		if (*str && (charset_ck(*str, charset) == 0))
		{
			arr[i++] = arr_malloc(str, charset);
			while (*str && (charset_ck(*str, charset) == 0))
				str++;
		}
	}
	arr[i] = 0;
	return (arr);
}
