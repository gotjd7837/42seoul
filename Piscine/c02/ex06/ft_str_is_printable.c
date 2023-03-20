/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:26:21 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:43:58 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= 126)
			i++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>
#include<string.h>

int	ft_str_is_printable(char *str);

int main(void)
{
    char str[] = "awe][f;./,dsvlg1=-`73rzef.,";
    char str1[] = "";
    char str2[] = "auhwefli\ngzewubfew";
    char str3[] = "\tAEFULYZPQOWEFVWE]FLYGDS";
    char str4[] = "HFWDUSQMSDNwWEFQDYGFE\f";

	printf("\n");
    printf("str : %s\nyour function : %d\nexpect :\
	 1\n\n", str, ft_str_is_printable(str));
    printf("str : %s\nyour function : %d\nexpect :\
	 1\n\n", str1, ft_str_is_printable(str1));
    printf("str : auhwefli \\n gzewubfew\nyour function :\
	 %d\nexpect : 0\n\n", ft_str_is_printable(str2));
    printf("str : \\t AEFULYZPQOWEFVWE]FLYGDS\nyour function :\
	 %d\nexpect : 0\n\n", ft_str_is_printable(str3));
    printf("str : HFWDUSQMSDNwWEFQDYGFE\\f\nyour function :\
	 %d\nexpect : 0\n", ft_str_is_printable(str4));
	printf("\n");
    return (0);
}*/
