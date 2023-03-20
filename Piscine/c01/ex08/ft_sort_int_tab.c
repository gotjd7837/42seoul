/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:00:44 by haekang           #+#    #+#             */
/*   Updated: 2023/02/16 14:11:08 by haekang          ###   ########.fr       */
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - 1 - j)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
			}
			i++;
		}
		j++;
	}
}
/*
int main()
{
	//----------- test case --------------------
	int tab1[10] = {3, -233, 25, 0, 252, 255, 234, 3, -67, 89};
	int tab2[1] = {3};
	int tab3[1] = {0};
	int tab4[9] = {3, -2633, 25, 0, 252, 234, 3, -67, 89};
	int tab5[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int tab6[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8};

	ft_sort_int_tab(tab1, 10);
	ft_sort_int_tab(tab2, 1);
	ft_sort_int_tab(tab3, 1);
	ft_sort_int_tab(tab4, 9);
	ft_sort_int_tab(tab5, 10);
	ft_sort_int_tab(tab6, 10);

	//-------------- result --------------------
	printf("--------------- ex08 ---------------");
	printf("\n\n");

	printf( YELLOW "Sort array 1 " RESET);
	printf("\n\n");

	printf("expected: -233, -67, 0, 3, 3, 25, 89, 234, 252, 255, \n");
	printf("output:   ");
	for (int i = 0; i < 10; i++)
		printf("%d, ", tab1[i]);

	printf("\n\n");

	printf( YELLOW "Sort array 2 " RESET);
	printf("\n\n");

	printf("expected: 3 \n");
	printf("output:   ");
	for (int i = 0; i < 1; i++)
		printf("%d, ", tab2[i]);

	printf("\n\n");

	printf( YELLOW "Sort array 3 " RESET);
	printf("\n\n");

	printf("expected: 0 \n");
	printf("output:   ");
	for (int i = 0; i < 1; i++)
		printf("%d, ", tab3[i]);

	printf("\n\n");

	printf( YELLOW "Sort array 4 " RESET);
	printf("\n\n");

	printf("expected: -2633, -67, 0, 3, 3, 25, 89, 234, 252, \n");
	printf("output:   ");
	for (int i = 0; i < 9; i++)
		printf("%d, ", tab4[i]);


	printf("\n\n");

	printf( YELLOW "Sort array 5 " RESET);
	printf("\n\n");

	printf("expected: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 \n");
	printf("output:   ");
	for (int i = 0; i < 10; i++)
		printf("%d, ", tab5[i]);


	printf("\n\n");

	printf( YELLOW "Sort array 6 " RESET);
	printf("\n\n");

	printf("expected: 1, 2, 3, 4, 5, 6, 7, 8, 8, 9, \n");
	printf("output:   ");
	for (int i = 0; i < 10; i++)
		printf("%d, ", tab6[i]);



	printf("\n\n");
	printf("------------------------------------\n\n");
}*/
