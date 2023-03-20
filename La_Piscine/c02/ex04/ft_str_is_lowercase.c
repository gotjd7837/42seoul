/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:04:11 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:40:36 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			i++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>
#include<string.h>

int	ft_str_is_lowercase(char *str);

int main(void)
{
    char str[] = "aligywefbxlygsdcjhg";
    char str1[] = "";
    char str2[] = "aliugwefdlIsvluiscedf";
    char str3[] = "aef;iugaew:liaygefwef";
    char str4[] = "awefaewfuoiIawelfgliygawef";

	printf("\n\n");
    printf("str : %s\nyour function : %d\nexpect :\
	 1\n\n", str, ft_str_is_lowercase(str));
    printf("str : %s\nyour function : %d\nexpect :\
	 1\n\n", str1, ft_str_is_lowercase(str1));
    printf("str : %s\nyour function : %d\nexpect :\
	 0\n\n", str2, ft_str_is_lowercase(str2));
    printf("str : %s\nyour function : %d\nexpect :\
	 0\n\n", str3, ft_str_is_lowercase(str3));
    printf("str : %s\nyour function : %d\nexpect :\
	 0\n", str4, ft_str_is_lowercase(str4));
	printf("\n\n");

    return (0);
}*/
