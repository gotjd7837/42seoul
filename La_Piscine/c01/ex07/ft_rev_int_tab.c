/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:09:10 by haekang           #+#    #+#             */
/*   Updated: 2023/02/16 13:53:52 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
*/
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap(&tab[i], &tab[size - i - 1]);
		i++;
	}
}
/*
int main()
{
	//----------- test case --------------------
	int tab[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int tab2[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	ft_rev_int_tab(tab, 9);
	ft_rev_int_tab(tab2, 8);


	//-------------- result --------------------
	printf("--------------- ex07 ---------------");
	printf("\n\n");

	printf( YELLOW "Sort first array " RESET);
	printf("\n\n");

	printf("expected: 9, 8, 7, 6, 5, 4, 3, 2, 1, \n");
	printf("output:   ");
	for (int i = 0; i < 9; i++)
		printf("%d, ", tab[i]);

	printf("\n\n");

	printf( YELLOW "Sort second array " RESET);
	printf("\n\n");

	printf("expected: 8, 7, 6, 5, 4, 3, 2, 1, \n");
	printf("output:   ");
	for (int i = 0; i < 8; i++)
		printf("%d, ", tab2[i]);


	printf("\n\n");
	printf("------------------------------------\n\n");
}*/
