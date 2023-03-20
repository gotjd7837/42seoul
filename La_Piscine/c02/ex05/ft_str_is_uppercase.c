/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:19:30 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:43:07 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			i++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>
#include<string.h>

int	ft_str_is_uppercase(char *str);

int main(void)
{
    char str[] = "DFLIUGAEWFKFSDZQSDF";
    char str1[] = "";
    char str2[] = "AWEFLLIGStDCWAEFDKUYFQW";
    char str3[] = "AEFULYZPQOWEFVWE]FLYGDS";
    char str4[] = "HFWDUSQMSDNwWEFQDYGFE";

	printf("\n");
    printf("str : %s\nyour function : %d\nexpect :\
	 1\n\n", str, ft_str_is_uppercase(str));
    printf("str : %s\nyour function : %d\nexpect :\
	 1\n\n", str1, ft_str_is_uppercase(str1));
    printf("str : %s\nyour function : %d\nexpect :\
	 0\n\n", str2, ft_str_is_uppercase(str2));
    printf("str : %s\nyour function : %d\nexpect :\
	 0\n\n", str3, ft_str_is_uppercase(str3));
    printf("str : %s\nyour function : %d\nexpect :\
	 0\n", str4, ft_str_is_uppercase(str4));
	printf("\n");
    return (0);
}*/
