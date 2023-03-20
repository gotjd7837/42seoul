/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:47:33 by haekang           #+#    #+#             */
/*   Updated: 2023/03/01 01:36:13 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join_malloc(char **strs, char *sep, int size)
{
	int		i;
	int		length;
	char	*tmp;

	i = 0;
	length = 0;
	if (size == 0)
	{
		tmp = (char *)malloc(sizeof(char) * 1);
		tmp[0] = '\0';
		return (tmp);
	}
	while (i < size)
	{
		length += str_len(strs[i]);
		i++;
	}
	length += str_len(sep) * (size - 1);
	tmp = (char *)malloc(sizeof(char) * (length + 1));
	return (tmp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tmp;
	int		i;
	int		j;
	int		index;

	index = 0;
	i = 0;
	tmp = join_malloc(strs, sep, size);
	if (!tmp)
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			tmp[index++] = strs[i][j++];
		j = 0;
		while (sep[j] && (i != size - 1))
			tmp[index++] = sep[j++];
		i++;
	}
	tmp[index] = '\0';
	return (tmp);
}
