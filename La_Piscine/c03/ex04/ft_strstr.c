/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:09:56 by haekang           #+#    #+#             */
/*   Updated: 2023/02/23 04:24:05 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	j = 0;
	if (*to_find == '\0')
		return (str);
	while (*(str))
	{
		i = 0;
		while ((to_find[i] == str[i]) && to_find[i] != '\0')
			i++;
		if (to_find[i] == '\0')
			return (str);
		str++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main()
{
	char str[] = "ababac";
	char to_find[] = "abac";
	printf("%s\n", ft_strstr(str, to_find));
}
*/