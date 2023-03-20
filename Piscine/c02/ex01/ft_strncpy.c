/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:35:22 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:32:14 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
 * dest에 src를 n번 복사, src의 길이를 넘어서 복사하면 n까지 널값을 넣어준다.
 * src가 널이 아니고, i가 n보다 작으면 그대로 계속 복사
 * src가 널이 되어서 반복문을 빠져나오면  dest에 i가 n까지 널을 넣어줌*/
/*#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
    char str[] = "123456789";
    char dest[] = "aaaaaaaaaa";
    char edest[] = "aaaaaaaaaa";
    char dest01[] = "aaaaaaaaaa";
    char edest01[] = "aaaaaaaaaa";
    char dest02[] = "aaaaaaaaaa";
    char edest02[] = "aaaaaaaaaa";

    char str1[] = "helloworld";
    char dest1[10] = "yolo";
    char edest1[10] = "yolo";
    char dest101[20] = "";
    char edest101[20] = ""; 
    char dest102[20];
    char edest102[20];

    char str2[] = "";
    char dest2[] = "abcde";
    char edest2[] = "abcde";
    char dest201[] = "abcde";
    char edest201[] = "abcde";


    printf("\n\nTEST1 : dest is bigger than src\n");
    printf("------------------------------------------------");
	printf("\n");
    printf("str : %s\ndest : %s\nsize : 7\n", str, dest);
    printf(" My function : ->|%s|<-\nlib function : ->|%s|<-\n",\
	ft_strncpy(dest, str, 7), strncpy(edest, str, 7));
	printf("\n\n");
    printf("str : %s\ndest : %s\nsize : 0\n", str, dest01);
    printf(" My function : ->|%s|<-\nlib function : ->|%s|<-\n",\
	ft_strncpy(dest01, str, 0), strncpy(edest01, str, 0));
	printf("\n\n");
    printf("str : %s\ndest : %s\nsize : 10\n", str, dest01);
    printf(" My function : ->|%s|<-\nlib function : ->|%s|<-\n",\
	ft_strncpy(dest01, str, 10), strncpy(edest01, str, 10));
    printf("------------------------------------------------\n");

    printf("\n\n\nTEST2 : src is bigger than dest\n");
    printf("------------------------------------------------");
    printf("\n");
    printf("str : %s\ndest : %s\nsize : 4\n", str1, dest1);
    printf(" My function : ->|%s|<-\nlib function : ->|%s|<-\n",\
	ft_strncpy(dest1, str1, 4), strncpy(edest1, str1, 4));
    printf("\n\n");
    printf("str : %s\ndest : [10]\nsize : 0\n", str1);
    printf(" My function : ->|%s|<-\nlib function : ->|%s|<-\n",\
	ft_strncpy(dest101, str1, 0), strncpy(edest101, str1, 0));
    printf("\n\n");
    printf("str : %s\ndest : [20]\nsize : 20\n", str1);
    printf(" My function : ->|%s|<-\nlib function : ->|%s|<-\n",\
	ft_strncpy(dest102, str1, 20), strncpy(edest102, str1, 20));
    printf("------------------------------------------------\n");

    printf("\n\n\nTEST3 : src is empty\n");
    printf("------------------------------------------------");
    printf("\n");
    printf("str : %s\ndest : %s\nsize : 2\n", str2, dest2);
    printf(" My function : ->|%s|<-\nlib function : ->|%s|<-\n",\
	ft_strncpy(dest2, str2, 2), strncpy(edest2, str2, 2));
    printf("\n\n");
    printf("str : %s\ndest : %s\nsize : 0\n", str2, dest201);
    printf(" My function : ->|%s|<-\nlib function : ->|%s|<-\n",\
	ft_strncpy(dest201, str2, 0), strncpy(edest201, str2, 0));
    printf("------------------------------------------------\n");
	
    printf("\n");
    return (0);
}*/
