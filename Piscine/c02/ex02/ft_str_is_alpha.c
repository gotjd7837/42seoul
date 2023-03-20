/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:36:20 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:38:49 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			i++;
		else
			return (0);
	}
	return (1);
}
/*
 * 문자열에 알파벳이 포함되면 1 다른문자가 포함되면 0 아예 비어있으면 1
 * 아무것도 안들어있으면 1 리턴
 * 알파벳이 들어오면 계속 반복문 돌다가 다른 문자 들어오면 not alph 플래그를 set하고 반복문 종료
 * 플래그가 set되어 있으면 다른 문자가 들어온 것 이므로 0을 리턴, 그렇지 않은 경우는 1 리턴
*/
/*
#include <stdio.h>
#include<string.h>

int	ft_str_is_alpha(char *str);

int main(void)
{
    char str[] = "aBchWEOPghsdfEbkbjsoiE";
    char str1[] = "";
    char str2[] = "aARegAE1feSDQdvH";
    char str3[] = ";][;1=-`10976=234=-";

	printf("\n\n");
    printf("str : %s\nyour function : %d\nexpect :\
	 1\n\n", str, ft_str_is_alpha(str));
    printf("str : %s\nyour function : %d\nexpect :\
	 1\n\n", str1, ft_str_is_alpha(str1));
    printf("str : %s\nyour function : %d\nexpect :\
	 0\n\n", str2, ft_str_is_alpha(str2));
    printf("str : %s\nyour function : %d\nexpect :\
	 0\n", str3, ft_str_is_alpha(str3));
	printf("\n\n");
    return (0);
}*/
