/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:51:35 by haekang           #+#    #+#             */
/*   Updated: 2023/04/09 17:36:40 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buf;

	buf = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			buf = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	if (buf == 0)
		return (NULL);
	return (buf);
}
