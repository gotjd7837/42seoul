/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 06:43:13 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:50:05 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (len(src));
	while (src[i] != '\0' && (i + 1 < size))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len(src));
}
/*
 * strcpy와 다른점은 널을 보장한다는 점이다 
 * 복사의 마지막은 널값이 들어가야함! 복사길이는 size - 1 까지
 * unsigned형이기 때문에 이항해서 계산하고 비교 변수도 같은 자료형  (오버플로 발생 위험)
 * size가 0이면 바로 리턴
 * strlcpy는 src의 길이를 반환함
 * */
/*
#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int	size);

int main(void)
{
    char src[] = "123456789";
    char dest[] = "aaaaaaaaaa";
    char lib_dest[] = "aaaaaaaaaa";
    char dest01[] = "aaaaaaaaaa";
    char lib_dest01[] = "aaaaaaaaaa";
    char dest02[] = "aaaaaaaaaa";
    char lib_dest02[] = "aaaaaaaaaa";

    char src1[] = "helloworld";
    char dest1[10] = "yolo";
    char lib_dest1[10] = "yolo";
    char dest101[20] = "";
    char lib_dest101[20] = "";
    char dest102[20];
    char lib_dest102[20];

    char src2[] = "";
    char dest2[] = "abcde";
    char lib_dest2[] = "abcde";
    char dest201[] = "abcde";
    char lib_dest201[] = "abcde";

	printf("\n\nTEST1 : dest is bigger than src\n");
    printf("------------------------------------------------");
	printf("\n");
    printf("src : %s\ndest : %s\nsize : 7\n", src, dest);
    printf(" My function : ->|%u|<-\nlib function : ->|%lu|<-\n",\
	ft_strlcpy(dest, src, 7), strlcpy(lib_dest, src, 7));
	printf("dest: 	  ->|%s|<-\n", dest);
	printf("lib_dest: ->|%s|<-\n", lib_dest);
	printf("\n\n");
    printf("src : %s\ndest : %s\nsize : 0\n", src, dest01);
    printf(" My function : ->|%u|<-\nlib function : ->|%lu|<-\n",\
	ft_strlcpy(dest01, src, 0), strlcpy(lib_dest01, src, 0));
	printf("dest:     ->|%s|<-\n", dest01);
	printf("lib_dest: ->|%s|<-\n", lib_dest01);
	printf("\n\n");
    printf("src : %s\ndest : %s\nsize : 10\n", src, dest01);\
	ft_strlcpy(dest01, src, 10), strlcpy(lib_dest01, src, 10);
	printf("dest:     ->|%s|<-\n", dest02);
	printf("lib_dest: ->|%s|<-\n", lib_dest02);
    printf("------------------------------------------------\n");

    printf("\n\n\nTEST2 : src is bigger than dest\n");
    printf("------------------------------------------------");
    printf("\n");
    printf("src : %s\ndest : %s\nsize : 4\n", src1, dest1);
    printf(" My function : ->|%u|<-\nlib function : ->|%lu|<-\n",\
	ft_strlcpy(dest1, src1, 4), strlcpy(lib_dest1, src1, 4));
	printf("dest:     ->|%s|<-\n", dest1);
	printf("lib_dest: ->|%s|<-\n", lib_dest1);
    printf("\n\n");
    printf("src : %s\ndest : [10]\nsize : 0\n", src1);
    printf(" My function : ->|%u|<-\nlib function : ->|%lu|<-\n",\
	ft_strlcpy(dest101, src1, 0), strlcpy(lib_dest101, src1, 0));
	printf("dest:     ->|%s|<-\n", dest101);
	printf("lib_dest: ->|%s|<-\n", lib_dest101);
    printf("\n\n");
    printf("src : %s\ndest : [20]\nsize : 20\n", src1);
    printf(" My function : ->|%u|<-\nlib function : ->|%lu|<-\n",\
	ft_strlcpy(dest102, src1, 20), strlcpy(lib_dest102, src1, 20));
	printf("dest:     ->|%s|<-\n", dest102);
	printf("lib_dest: ->|%s|<-\n", lib_dest102);
    printf("------------------------------------------------\n");

    printf("\n\n\nTEST3 : src is empty\n");
    printf("------------------------------------------------");
    printf("\n");
    printf("src : %s\ndest : %s\nsize : 2\n", src2, dest2);
    printf(" My function : ->|%u|<-\nlib function : ->|%lu|<-\n",\
	ft_strlcpy(dest2, src2, 2), strlcpy(lib_dest2, src2, 2));
	printf("dest:     ->|%s|<-\n", dest2);
	printf("lib_dest: ->|%s|<-\n", lib_dest2);
    printf("\n\n");
    printf("src : %s\ndest : %s\nsize : 0\n", src2, dest201);
    printf(" My function : ->|%u|<-\nlib function : ->|%lu|<-\n",\
	ft_strlcpy(dest201, src2, 0), strlcpy(lib_dest201, src2, 0));
	printf("dest:     ->|%s|<-\n", dest201);
	printf("lib_dest: ->|%s|<-\n", lib_dest201);
    printf("------------------------------------------------\n");

    printf("\n");
    return (0);
}*/
