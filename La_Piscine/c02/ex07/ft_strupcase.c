/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:37:34 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:45:15 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

char	*ft_strupcase(char *str);

int main(void)
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    char str1[] = "ABCDefghijkLMNOP";
    char str2[] = "a;b.c'd,e[f]g-h=i1j5k";

	printf("\n");
    printf("befor : %s\n", str);
    printf("after : %s\n\n", ft_strupcase(str));
    printf("befor : %s\n", str1);
    printf("after : %s\n\n", ft_strupcase(str1));
    printf("befor : %s\n", str2);
    printf("after : %s\n\n", ft_strupcase(str2));
	printf("\n");
    return (0);
}*/
