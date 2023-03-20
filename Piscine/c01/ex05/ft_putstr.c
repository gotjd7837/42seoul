/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:52:27 by haekang           #+#    #+#             */
/*   Updated: 2023/02/16 13:50:36 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*#include <stdio.h>
#include "stdio.h"
#include "unistd.h"
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
*/
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
/*
int main()
{
	//----------- test case --------------------
	char str[6] = "Hello";
	char *str2 = "Hella.fkjga;lfkgno\0";




	//-------------- result --------------------
	printf("--------------- ex05 ---------------");
	printf("\n\n");

	printf( YELLOW "Put string 1" RESET);

	printf("\n\n");

	printf("Hello <= Me\n");
	ft_putstr(str);
	printf( YELLOW " <= You");
	printf("\n\n");

	printf("Put string 2" RESET);

	printf("\n\n");

	printf("Hella.fkjga;lfkgno <= Me\n");
	ft_putstr(str2);
	printf( YELLOW " <= You" RESET );

	printf("\n\n");
	printf("------------------------------------\n\n");
}*/
