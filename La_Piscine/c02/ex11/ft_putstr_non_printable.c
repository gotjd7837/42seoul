/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 07:49:44 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:51:19 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int						i;
	unsigned char			tr_str;

	i = 0;
	while (str[i] != '\0')
	{
		tr_str = (unsigned char)str[i];
		if (tr_str < ' ' || tr_str >= 127)
		{
			write (1, "\\", 1);
			write (1, &"0123456789abcdefg"[tr_str / 16], 1);
			write (1, &"0123456789abcdefg"[tr_str % 16], 1);
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}
/*
 * 문자열 리터럴 자체를 배열의 주소로 보고 일반 배열처럼 16진수 변환해서 출력
 * 확장 아스키까지 변환해야 하므로 unsigned char 변수를 선언해서 형변환 시켜서 넣은뒤 사용
 * (출력 불가능한 문자와 확장 아스키코드 16진수 변환)*/
/*
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr_non_printable(char *str);

int main(void)
{
    char str[] = "Coucou\ntu vas bien ?";
    char str1[] = {9, 10, 11, 12, 13, 32, 80,\
	 114, 105, 110, 116, 128, 130, 234, '\0'};
    char str2[] = "What \n is \t the \f non_printable\e  ";

	printf("\n");
    printf("\ninput :       Coucou\\ntu vas bien ?\n");
    printf("your result : ");
        fflush(NULL);

    ft_putstr_non_printable(str);
    printf("\nexpect :      Coucou\\0atu vas bien ?\n");

    printf("\n\n");
    printf("input : tab={9, 10, 11, 12, 13, 32, 80,\
	 114, 105, 110, 116, 128, 130, 234}\n");
    printf("your result : ");
    fflush(NULL);
    ft_putstr_non_printable(str1);
    printf("\nexpect :      \\09\\0a\\0b\\0c\\0d\
	 Print\\80\\82\\ea\n");

    printf("\n\n");
    printf("input :       What \\n is \\t the \\f\
	 non_printable\\e  \n");
    printf("your result : ");
    fflush(NULL);

    ft_putstr_non_printable(str2);
    printf("\nexpect :      What \\0a is \\09 the\
	 \\0c non_printable\\1b \n");
    printf("\n");
    return (0);
}*/
