, str, 1/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:57:13 by haekang           #+#    #+#             */
/*   Updated: 2023/02/16 13:51:18 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
/*
int main()
{
	//----------- test case --------------------
	char str[] = "hell";
	char *str2 = "hel l	a.f*^$#jga;lfkgno\0";

	int res1 = ft_strlen(str);
	int res2 = ft_strlen(str2);

	//-------------- result --------------------
	printf("--------------- ex06 ---------------");
	printf("\n\n");

	printf( YELLOW "length of 'hell' " RESET);
	if (res1 == 4)
		printf( GREEN "(\xE2\x9C\x93)" RESET );
	else
		 printf( RED "(x)"  RESET );

	printf("\n\n");

	printf("expected: %d\n", 4);
	if (res1 == 4) printf("output:   " GREEN "%d\n" RESET, res1);
	if (res1 != 4) printf("output:   " RED "%d\n" RESET, res1);

	printf("\n\n");

	printf( YELLOW "length of 'hella.fkjga;lfkgno' " RESET);
	res2 == 23 ? printf( GREEN "(\xE2\x9C\x93)" RESET )
   	:  printf( RED "(x)"  RESET );

	printf("\n\n");

	printf("expected: %d\n", 23);
	if (res2 == 23) printf("output:   " GREEN "%d\n" RESET, res2);
	if (res2 != 23) printf("output:   " RED "%d\n" RESET, res2);

	printf("\n\n");
	printf("------------------------------------\n\n");
}*/
