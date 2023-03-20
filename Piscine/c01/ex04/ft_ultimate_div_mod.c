/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:02:59 by haekang           #+#    #+#             */
/*   Updated: 2023/02/16 13:49:52 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
*/
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = (*a / *b);
	*b = (*a % *b);
	*a = tmp;
}
/*
int main()
{
	//----------- test case --------------------
	int a = 85;
	int b = 10;

	int *pa = &a;
	int *pb = &b;

	ft_ultimate_div_mod(pa, pb);

	//-------------- result --------------------
	printf("--------------- ex04 ---------------");
	printf("\n\n");

	printf( YELLOW "Divide and modulo a by b " RESET);
	if (a == 8 && b == 5)
		printf( GREEN "(\xE2\x9C\x93)" RESET );
	else
		 printf( RED "(\xE2\x9C\x93)"  RESET );

	printf("\n\n");

	printf("a: %d\n", 85);
	printf("b: %d\n\n", 10);
	printf("expected:\n");
	printf("	- a: 8\n");
	printf("	- b: 5\n");
	printf("output:\n");
	if (a == 8) printf("	- a: " GREEN "%d\n" RESET, a);
	if (a != 8) printf("	- a: " RED "%d\n" RESET, a);
	if (b == 5) printf("	- b: " GREEN "%d\n" RESET, b);
	if (b != 5) printf("	- b: " RED "%d\n" RESET, b);

	printf("\n\n");
	printf("------------------------------------\n\n");
}*/
