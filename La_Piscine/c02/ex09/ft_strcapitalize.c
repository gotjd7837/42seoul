/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:56:17 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:47:43 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 'a' - 'A';
	while (str[i + 1] != '\0')
	{
		if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
			str[i + 1] += 'a' - 'A';
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			if (str[i] < 'A' || str[i] > 'Z')
				if (str[i] < '0' || str[i] > '9')
					if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
						str[i + 1] -= 'a' - 'A';
		i++;
	}
	return (str);
}
/*
 * 문자열의 첫번째를 대문자로 바꾸어준 뒤 나머지를 전부 소문자로 바꿔줌
 * 다시 처음부터반복, a~z, A~Z, 0~9 의 문자가 아니고 다음 문자가 a~z 이면
 * 다음 문자를 대문자로 바꾸어줌 (이게 단어의 첫 문자이기 떄문)
 */
/*
#include <stdio.h>
#include <string.h>


int main(void)
{
    char str[] = "salut, coMmEnt tU vas ? 42MOts \
	quarante-deux; cinquante+Et+un";
    char str1[] = "hello 42STUdeNts, i'M ba-tman.";
    char str2[] = "hi, i'm r+i+d+d+l+e+r. N+ow/i'1l \
	give -you9a 00sama11 r1dd1e-h-a-ha--ha- ";
    char str3[] = "";


	printf("\n");
    printf("before: %s\n", str);
    printf("after : %s\n", ft_strcapitalize(str));
    printf("expect: Salut, Comment Tu Vas ? 42mots  Quarante-Deux; \
Cinquante+Et+Un\n\n");
    printf("before: %s\n", str1);
    printf("after : %s\n", ft_strcapitalize(str1));
    printf("expect: Hello 42students, I'M Ba-Tman.\n\n");
    printf("before: %s\n", str2);
    printf("after : %s\n", ft_strcapitalize(str2));
    printf("expect: Hi, I'M R+I+D+D+L+E+R. N+Ow/I'1l	Give -You9a\
 00sama11 R1dd1e-H-A-Ha--Ha- \n\n");

    printf("before: \"%s\"\n", str3);
    printf("after : \"%s\"\n", ft_strcapitalize(str3));

	printf("\n");
    return (0);
}*/
