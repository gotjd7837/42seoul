/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:32:11 by haekang           #+#    #+#             */
/*   Updated: 2023/02/16 13:44:36 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
*/
void	ft_swap(int	*a, int	*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
int main()
{
	// test case
	int a = 5;
	int b = 9;
	ft_swap(&a, &b);

	// print result
	printf("--------------- ex02 ---------------");
	printf("\n\n");

	printf( YELLOW "Swap a and b " RESET);
	if (a == 9 && b == 5)
		printf( GREEN "(\xE2\x9C\x93)" RESET );
	else
		 printf( RED "(\xE2\x9C\x93)"  RESET );

	printf("\n\n");

	printf("a: %d\n", 5);
	printf("b: %d\n\n", 9);
	printf("expected:\n");
	printf("	- a: 9\n");
	printf("	- b: 5\n");
	printf("output:\n");
	if (a == 9) printf("	- a: " GREEN "%d\n" RESET, a);
	if (a != 9) printf("	- a: " RED "%d\n" RESET, a);
	if (b == 5) printf("	- b: " GREEN "%d\n" RESET, b);
	if (b != 5) printf("	- b: " RED "%d\n" RESET, b);

	printf("\n\n");
	printf("------------------------------------\n\n");
}*/
