/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:44:54 by haekang           #+#    #+#             */
/*   Updated: 2023/03/31 20:38:26 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	idx_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

static size_t	idx_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || *s1 == '\0')
	{
		result = ft_strdup(s1);
		return (result);
	}
	start = idx_start(s1, set);
	end = idx_end(s1, set);
	if (start == ft_strlen(s1))
	{
		result = ft_strdup("");
		return (result);
	}
	result = ft_substr(s1, start, (end - start + 1));
	return (result);
}
