/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:48:51 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:46:26 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

char	*ft_strlowcase(char *str);

int main(void)
{
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char str1[] = "abcdeFGHIJKlmnopqrs";
    char str2[] = "A;B.C'D,E[F]G-H=I1J5K";

	printf("\n");
    printf("befor : %s\n", str);
    printf("after : %s\n\n", ft_strlowcase(str));
    printf("befor : %s\n", str1);
    printf("after : %s\n\n", ft_strlowcase(str1));
    printf("befor : %s\n", str2);
    printf("after : %s\n\n", ft_strlowcase(str2));
	printf("\n");
    return (0);
}*/
